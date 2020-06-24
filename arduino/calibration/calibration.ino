#include "HX711.h"

// HX711 接線設定
const int DT_PIN = 12;
const int SCK_PIN = 14;
const int sample_weight = 138;  //基準物品的真實重量(公克)

HX711 scale;

void setup() {
  Serial.begin(9600);
  scale.begin(DT_PIN, SCK_PIN);
  scale.set_scale();  // 開始取得比例參數
  scale.tare();
  Serial.println("nothing...");
  Serial.println(scale.get_units(10));
  Serial.println("put something on it."); //提示放上基準物品
  
}

void loop() {
  float current_weight=scale.get_units(10);  // 取得10次數值的平均
  float scale_factor=(current_weight/sample_weight);
  Serial.print("scale number:");
  Serial.println(scale_factor,2);  // 顯示比例參數，記起來，以便用在正式的程式中
  
}
