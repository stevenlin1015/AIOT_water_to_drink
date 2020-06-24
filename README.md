----
## 關於本專案

2020 AIoT 物聯網課程期末小專題



----
## 使用方式

>註 : 需要預載[xampp](https://www.apachefriends.org/zh_tw/download.html)

<h3>html內容</h3>


  1. 下載本專案 `git clone https://github.com/stevenlin1015/AIOT_water_to_drink.git`

  2. 將html資料夾內的final資料夾放到‵`C://xampp//htdocs//`下。

  3. 開啟xampp，在瀏覽器輸入`localhost/final/highchart.html`，即可預覽飲水網頁。


<h3>arduino內容</h3>


  1. 下載本專案 `git clone https://github.com/stevenlin1015/AIOT_water_to_drink.git`

  2. 將wemos D1 R1開發版與HX711電子量秤、一顆LED燈配置完整，接上PC。

  3. 打開arduino資料夾，先做HX711電子量秤的校正。這裡使用`calibration/calibration.ino`燒錄至wemos D1 R1開發版。在校正過程中，請同時開啟arduino console(監控視窗)，照指示做初始校正。
  >註 : 原始校正方式請參考[傑森創工](https://blog.jmaker.com.tw/hx711_set/)

  4. 打開arduino資料夾，打開`measure_to_db_led/measure_to_db_led.ino`，將校正數值覆蓋於**scale_factor**這個變數。
  >註 : 原始安裝方式請參考[傑森創工](https://blog.jmaker.com.tw/hx711_set/)

  5. 把`measure_to_db_led.ino`燒錄至wemos D1 R1開發版，進行量測。
  >註 : 原始安裝方式請參考[傑森創工](https://blog.jmaker.com.tw/hx711_set/)
  