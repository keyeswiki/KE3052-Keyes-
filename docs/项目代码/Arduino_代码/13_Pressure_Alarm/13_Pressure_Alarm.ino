/*
 * 名称   : Pressure_Alarm
 * 功能   : 压力传感器控制蜂鸣器鸣叫
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
int pressure = A0; 
int buzzer = A1;

void setup() {
 pinMode(pressure,INPUT);
 pinMode(buzzer,OUTPUT);
}

void loop() {
  int temp = analogRead(pressure);
  int value = map(temp,1023,0,0,1023); //因为没有按压传感器时值是1023，所以我们使用map函数来讲他得到的值倒转一下，这样没有按压是得到的值就是0
  if(value > 600){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
 }
}