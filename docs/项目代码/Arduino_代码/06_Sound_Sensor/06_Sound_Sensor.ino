/*
 * 名称   : Sound sensor
 * 功能   : 读取声音传感器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
int sensorPin = A0 ;  //定义模拟口A0
int value = 0;    //设置value为0

void setup() {
  Serial.begin(9600); //设置波特率
} 

void loop() {
  value = analogRead(sensorPin);  //将value设置为读取到的A0的数值
  Serial.println(value, DEC);  //显示value数值，并自动换行
  delay(200);  //延迟0.2S
}
