/*
 * 名称   : Button
 * 功能   : 读取按键值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
int button = A0;  //定义引脚A0
void setup() {
  pinMode(button, INPUT);  //将button设置为输入
  Serial.begin(9600);  
}
void loop() {
  //设置int类型变量val；‘digitalRead’函数读取A0口的数值，并赋值给 val
  int val = digitalRead(button);
  delay(200);      //打印速度太快了，使用延时放慢打印速度
  if (val == LOW)  {
    Serial.println("Key Down!");
  } else {
    Serial.println("Wait for the key to be pressed!");
  }
}
