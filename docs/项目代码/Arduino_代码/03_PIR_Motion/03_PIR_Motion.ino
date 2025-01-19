/*
 * 名称   : PIR_Motion
 * 功能   : 读取人体红外传感器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
byte sensorPin = A0; //定义引脚A0
void setup()
{
  pinMode(sensorPin,INPUT); //设置引脚为输入
  Serial.begin(9600); //设置波特率
}
void loop(){
  byte state = digitalRead(sensorPin); //读取到A0的数值赋值给state
  if(state == 1) //当state==1时，串口监视器输出对应字符，并自动换行
  Serial.println("Somebody is in this area!");
  else if(state == 0) //当state==0时，串口监视器输出对应字符，并自动换行
  Serial.println("No one!");
  delay(500); //延迟0.5S
}
