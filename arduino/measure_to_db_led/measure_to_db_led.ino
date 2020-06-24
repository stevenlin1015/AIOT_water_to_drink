//Wi-Fi
#include "ESP8266WiFi.h"
#include "ESP8266WiFiMulti.h"
ESP8266WiFiMulti WiFiMulti;
#define wifi_id ""
#define wifi_pass ""

#include "HX711.h"

// 接線設定
const int DT_PIN = 12;
const int SCK_PIN = 14;

const int scale_factor = 621; //比例參數，從校正程式中取得

HX711 scale;

//LED with weight
int led = 13;
float weight_old = 10000000;
float weight_new = 0;

void setup() {
  //configure LED light
  pinMode(led, OUTPUT);
  
  Serial.begin(9600);
  Serial.println("Initializing the scale");

  scale.begin(DT_PIN, SCK_PIN);

  Serial.println("Before setting up the scale:"); 
  
  Serial.println(scale.get_units(5), 0);  //未設定比例參數前的數值

  scale.set_scale(scale_factor);       // 設定比例參數
  scale.tare();               // 歸零

  Serial.println("After setting up the scale:"); 

  Serial.println(scale.get_units(5), 0);  //設定比例參數後的數值

  Serial.println("You can put something on it!");  //在這個訊息之前都不要放東西在電子稱上

  WiFiMulti.addAP(wifi_id, wifi_pass);

  while(WiFiMulti.run() != WL_CONNECTED){
      Serial.println("wait...");
      delay(500);
    }
  
}

void loop() {
    Serial.println("============In new loop:================="); 
  
    scale.power_down();             // 進入睡眠模式
    delay(10000);                    //1000 = 1 sec. 
    scale.power_up();               // 結束睡眠模式


    const uint16_t port = ; //資料庫的PORT
    const char * host = ""; //server的IP
    Serial.print("連線至[");
    Serial.print(host);
    Serial.println("]");

    WiFiClient client; //建立客戶端
    //檢查是否與WiFi連線
    if(!client.connect(host, port)) {
      Serial.println("connect failed");
      Serial.println("wait 1 sec...");
      delay(1000);
      return;
    }

    //連線至伺服器端後，傳送資料至getData.php
    float w = scale.get_units(10);
    Serial.println("weight = " + String(w));
    String url ="/hw2/AddData.php?weight=" + String(w);


    client.print(String("GET ") + url + " HTTP/1.1\r\n" +
    "Host: " + host + "\r\n" +
    "Connection: close\r\n\r\n");
    delay(1000);

    Serial.println("connect closed");
    client.stop();

    //process led light with weight
    weight_new = w;

    Serial.println("old weight = " + String(weight_old));
    Serial.println("new weight = " + String(weight_new));
    
    if ((weight_old - weight_new) > 10) {
      //led off
      digitalWrite(led, LOW);
      Serial.println("LED is turned off!");
    } else {
      //led on
      digitalWrite(led, HIGH);
      Serial.println("LED is turned on!");
    }
    weight_old = weight_new;

    
    delay(1000); //延時1秒
    
}
