/*
 * 名称   : Buzzer
 * 功能   : 蜂鸣器鸣叫
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
int buzzPin = A0; //定义引脚口A0  
void setup(){
  pinMode(buzzPin, OUTPUT); //将buzzPin设置为输出 
}

void loop()
{
  digitalWrite(buzzPin, HIGH); //有源蜂鸣器响起
  delay(2000); //延迟2S
  digitalWrite(buzzPin, LOW); //有源蜂鸣器关闭
  delay(2000); //延迟2S
}
