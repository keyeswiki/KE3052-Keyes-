/*
 * 名称   : 128x32_LCD
 * 功能   : 128x32 LCD显示
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : http://www.keyes-robot.com/
*/
#include "lcd128_32_io.h"  //添加lcd128_32_io库文件
lcd lcd(A4, A5); //定义Lcd类实例和引脚

void setup() {
  lcd.Init();  //初始化
  lcd.Clear();  //清屏
}

void loop() {
  lcd.Cursor(0, 7); //设置第一行，第八列开始显示，下同
  lcd.Display("KEYES"); //显示“KEYES”，下同
  lcd.Cursor(1, 0);
  lcd.Display("ABCDEFGHIJKLMNOPQR");
  lcd.Cursor(2, 0);
  lcd.Display("123456789+-*/<>=$@");
  lcd.Cursor(3, 0);
  lcd.Display("%^&(){}:;'|?,.~\\[]");
}
