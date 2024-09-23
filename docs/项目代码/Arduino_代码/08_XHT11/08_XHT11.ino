/*
 * 名称   : XHT11
 * 功能   : 读取温湿度传感器的温度和湿度
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
#include <dht11.h>  //导入库文件
dht11 DHT;
#define DHT11_PIN A0 //定义DHT11引脚为A0

void setup() {
  Serial.begin(9600);
}
void loop() {
  int chk;
  chk = DHT.read(DHT11_PIN);  // 读取数据
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
  // 显示数据
  Serial.print("humidity:");
  Serial.print(DHT.humidity);
  Serial.print("   temperature:");
  Serial.println(DHT.temperature);
  delay(200);
}
