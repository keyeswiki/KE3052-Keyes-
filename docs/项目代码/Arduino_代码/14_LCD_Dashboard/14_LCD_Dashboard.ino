/*
 * 名称   : LCD_Dashboard
 * 功能   : LCD显示温湿度值, 光照强度值和电位器值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
#include "lcd128_32_io.h" //导入lcd128_32_io库文件
lcd Lcd(A4,A5);

#include<dht11.h> //导入dht11库文件
dht11 DHT;
#define DHT11_PIN A0  //定义XHT11温湿度传感器的引脚为A0

int pot = A1; //定义旋转电位器的引脚为A1
int pho = A2; //定义光敏传感器的引脚为A2

void setup() {
  Serial.begin(9600);
  Lcd.Init(); //初始化
  Lcd.Clear();  //清屏
}

void loop() { 
  read_dht11_data();     //调用dht11读取函数    

    //湿度显示程序
  int humidity = DHT.humidity;      
  Lcd.Cursor(0, 0);                         //设置第0行，第0列开始显示
  Lcd.Display("humidity:");                 //显示“humidity:”
  Lcd.Cursor(0, 10);                        //设置第0行，第10列开始显示
  Lcd.Display_Num(humidity);                //实时显示数字，下方代码的都是同样的步骤
    
    //温度显示程序
  int temperature = DHT.temperature;
  Lcd.Cursor(1, 0);
  Lcd.Display("temperature:");
  Lcd.Cursor(1, 13);
  Lcd.Display_Num(temperature);
    
    //光亮度值显示程序
  int val1 = analogRead(pho);
  Lcd.Cursor(2, 0);
  Lcd.Display("Luminance:");
  Lcd.Cursor(2, 11);
  Lcd.Display_Num(val1);
    
    //旋转电位器值显示
  int val2 = analogRead(pot);
 
  Lcd.Cursor(3, 0);
  Lcd.Display("Analog:");
  Lcd.Cursor(3, 8);
  Lcd.Display_Num(val2);
  delay(100);

}

void read_dht11_data(){
    int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk) {
    case DHTLIB_OK:
      break;
    case DHTLIB_ERROR_CHECKSUM: //校检和错误返回
      break;
    case DHTLIB_ERROR_TIMEOUT: //超时错误返回
      break;
    default:
      break;
  }
}