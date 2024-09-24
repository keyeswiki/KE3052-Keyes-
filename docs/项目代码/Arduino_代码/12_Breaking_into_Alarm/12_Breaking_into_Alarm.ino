/*
 * 名称   : Breaking_into_Alarm
 * 功能   : 人体红外传感器控制蜂鸣器鸣叫
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
int pir = A0;     
int buzzer = A1;

void setup() {
  pinMode(pir,INPUT);
  pinMode(buzzer,OUTPUT);
}

void loop() { 
  int value = digitalRead(pir);
  if(value == 1){
    digitalWrite(buzzer,HIGH);
  }
  else{
    digitalWrite(buzzer,LOW);
  }
}


