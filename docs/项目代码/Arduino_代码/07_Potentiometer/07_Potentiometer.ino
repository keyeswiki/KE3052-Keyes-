/*
 * 名称   : Potentiometer
 * 功能   : 读取旋转电位器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
int sensorPin = A0 ;  //定义引脚A0
int value = 0;      //设置value为0

void setup() {
  Serial.begin(9600); //设置波特率
} 

void loop() {
  value = analogRead(sensorPin);   //将value设置为读取到的A0的数值
  Serial.println(value);    //显示value数值，并自动换行
  delay(100);  //延迟0.1S
}
