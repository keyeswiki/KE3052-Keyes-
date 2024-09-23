/*
 * 名称   : Doorbell
 * 功能   : 按键控制蜂鸣器鸣叫
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
int button = A0;  //定义引脚A0接按键
int buzz = A1;    //定义引脚A1接蜂鸣器
void setup() {
  pinMode(button, INPUT);  //将button设置为输入
  pinMode(buzz,OUTPUT);     //将buzz设置为输出 
}

void loop() {
  //设置int类型变量val；‘digitalRead’函数读取A0的数值，并赋值给 val
  int val = digitalRead(button);
  if (val == LOW)  {
    digitalWrite(buzz,HIGH);
  } 
  else {
    digitalWrite(buzz,LOW);
  }
}
