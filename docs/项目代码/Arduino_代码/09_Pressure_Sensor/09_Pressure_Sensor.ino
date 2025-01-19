/*
 * 名称   : Pressure_Sensor
 * 功能   : 读取压力传感器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
int pin = A0;

void setup(){
  Serial.begin(9600);
  pinMode(pin,INPUT);
}

void loop() {
  Serial.println(analogRead(pin));
  delay(100);
}
