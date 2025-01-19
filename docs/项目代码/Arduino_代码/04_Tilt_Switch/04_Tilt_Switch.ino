/*
 * 名称   : Tilt Switch
 * 功能   : 读取倾斜开关模块的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
int inputPin = A0; //定义引脚A0
void setup() 
{
  Serial.begin(9600);
  pinMode(inputPin, INPUT); //将inputPin设置为输入 
}
void loop(){
  int val = digitalRead(inputPin);
//设置数字变量val，读取到A0的数值，并赋值给 val 
  if (val == LOW) {  
    Serial.println("Normal!");
  }
  else {
    Serial.println("Tilt warning!");
  }
  delay(500);
}
