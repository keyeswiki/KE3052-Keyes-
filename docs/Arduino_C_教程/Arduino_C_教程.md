# Arduino C 教程

## 开发环境设置

<span style="color: rgb(255, 76, 65);">**这一部分很重要，一定要先读取这一部分内容再到项目课程。**</span>

<br>
<br>

Arduino IDE下载、驱动安装及安装库文件的相关链接：[https://www.keyesrobot.cn/projects/Arduino/en/latest/](https://www.keyesrobot.cn/projects/Arduino/en/latest/)

<span style="color: rgb(255, 76, 65);">注意：</span><span style="background:#ff0;color:#000">本教程使用的是Arduino IDE版本：2.3.2 。</span>

## 项目课程

### 第1课 蜂鸣器模块

![](media/51deebe17e93ab0bfaa42693745ccf08.png)

**1. 项目介绍：**

有源蜂鸣器模块上的有源蜂鸣器元件可以发出声音，有源蜂鸣器元件内部自带震荡电路，使用时，我们只需要给蜂鸣器元件足够的电压，蜂鸣器就会自动响起。

**2. 规格参数：**

工作电压：DC 3.3 ~ 5V 

工作电流：22.5mA

最大功率：0.12W

频率：2300HZ

控制信号：数字信号

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 12.3mm

接口：2.54mm间距，3pin防反接口

**3. 原理图：**

![](media/cc6328c0c70481efdfd5dd663cdac4ce.png)

从原理图我们可以得知，蜂鸣器的1脚通过串联一个电阻R2连接到电压正极；蜂鸣器的2脚连接到NPN三极管Q1的C极，集电极；Q1的B极，也就是基极通过串联一个电阻R1连接到S信号端；发射集接到GND。

当三极管Q1导通时，蜂鸣器的2脚连通GND，有源蜂鸣器便会工作。那么如何让三极管Q1导通呢？**NPN三极管的导通条件是基极（B）电压比发射极（E）电压高 0.3V 以上，**只需要基极（B）被上拉至高电平即可。虽然三极管Q1的基极（B）有一个下拉电阻R3导致其不导通，但是R3电阻的阻值大，使其为弱下拉电阻。三极管Q1的基极（B）还连接了一个阻值小的强上拉电阻R1，只要我们用单片机IO口给S信号端输入高电平，强上拉电阻R1会将三极管Q1的基极（B）强上拉为高电平，三极管Q1就会导通，有源蜂鸣器就会工作。

**4. 连接图：**

![](media/e107de92cef0a731a5227ca55229ec0f.png)

**5. 实验代码：**

```c
/*
 * 名称   : Buzzer
 * 功能   : 蜂鸣器鸣叫
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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

```

**6. 测试结果：**

有源蜂鸣器只需要有个高电平电压蜂鸣器就响起。烧录好代码，连接好线，上电后，有源蜂鸣器响2S，静音2S，循环交替。

### 第2课 按键模块

![](media/1a90cb6e20f8bdab71de591c68c14a26.png)

**1. 项目介绍：**

本传感器兼容各种单片机控制板，如arduino系列单片机。它的连接端口兼容arduino传感器扩展板。传感器输入一个按键信号，可以输出一个数字电压信号。当我们按下按键时传感器信号端输出低电平信号，释放按键时传感器信号端保持高电平。传感器自带2个4.8mm的定位孔，方便你将传感器固定在其他设备。

**2. 规格参数：**

工作电压：3.3-5V（DC）

工作电流：10MA

输出信号：数字信号

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 12.3mm

接口：2.54mm间距，3pin防反接口

**3. 电路图：**

![](media/74495c5a3c13b0f91e026320e26436c4.png)

按键模块上的按键没有按下时，VCC经过R1给到S端的电压是高电平，当按键按下后，S端与GND导通电压被拉低了，所以是低电平，R1的作用是避免VCC和GND直接短路。

**4. 连接图：**

![](media/aefc3b1e926f0e8d94840d202771abdc.png)

**5. 实验代码：**

```c
/*
 * 名称   : Button
 * 功能   : 读取按键值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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

```

**6. 实验结果：**

按照上图接好线，烧录好代码； 打开arduino IDE的串口监视器并设置波特率为9600，没有按下按键时串口打印“Wait for the key to be pressed!” ；按下按键后打印“Key Down!”如下图：

![](media/4216475053234bde6f965f33a05779b1.png)

### 第3课 人体红外热释传感器

![](media/e33ebccbc7750ff556d99b6c378e12fc.png)

**1. 项目介绍：**

Keyes 人体红外热释传感器，它主要由一个RE200B-P传感器元件组成。它是一款基于热释电效应的人体热释运动传感器，能检测到人体或动物身上发出的红外线，配合菲涅尔透镜能使传感器探测范围更远更广。

实验中，通过读取模块上S端高低电平，判断附近是否有人在运动；并且在串口监视器上显示测试结果。

**2. 规格参数：**

工作电压: DC 3.3V~5V 

工作电流: 3.6mA

最大功率: 0.018W

静态电流: <50 uA

输出信号: 数字信号

触发方式: L不可重复触发/H重复触发

视野角度：Y = 90°，X = 110°（视野角度为理论数值）

最大检测距离: ≤5米

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 7.4mm

接口：2.54mm间距为，3pin防反接口

**3. 电路图：**

![Img](./media/img-20240923100437.png)

这个模块的原理图可能较前面的模块稍复杂，我们一部分一部分来看。先看电压转换部分，作用是将5V输入电压转换为3.3V输入电压。因为我们模块上用到的热释电红外传感器的工作电压是3.3V，不能直接用5V电压供电使用。有了这个电压转换部分，3.3V输入电压和5V输入电压都适用于此热释电红外传感器。

当红外热释传感器没有检测到红外信号时，红外热释传感器的1脚输出低电平，此时模块上的LED两端有电压差，有电流流过，LED被点亮，MOS管Q1导通（Q1是NPN MOS管，型号为2N7002。由于红外热释传感器的1脚输出低电平，所以Q1的源极Vs=0，而Q1的栅极Vg=3.3V，于是Q1的栅极G和Q1的源极S之间的电压 Vgs = 3.3V 大于Q1的阈值电压 2.5V，Q1导通。），信号端S检测到低电平。

当红外热释传感器检测到红外信号时，红外热释传感器的1脚输出高电平，此时模块上的LED熄灭，MOS管Q1不导通，则信号端S检测到被10K上拉电阻R5拉高的高电平。

**4. 接线图：**

![](media/6afca595b592db50554cd3350d44e4f7.png)

**5. 实验代码：**

```c
/*
 * 名称   : PIR_Motion
 * 功能   : 读取人体红外传感器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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

```

**6. 实验结果：**

烧录好测试代码，按照接线图连接好线，利用USB线上电后，打开串口监视器，设置波特率为9600。检测到人体运动时串口监视器中显示"Somebody is in this area!"；没有检测到人体运动时串口监视器中显示"No one!"。

![](media/6ff1a16c26fd6d061d8d430700e251a1.png)

### 第4课 倾斜开关模块

![](media/47304ef0be69753ce7edd2b3b3377b49.png)

**1. 项目介绍：**

Keyes 倾斜传感器，主要由一个倾斜开关组成，其内部带有一颗滚珠，用来监测倾斜情况。倾斜开关可以依据模块是否倾斜而输出不同的电平信号。当开关高于水平位置倾斜时开关导通，低于水平位置时开关断开。倾斜模块可用于倾斜检测、报警器制作或者其他检测。

**2. 规格参数：**

工作电压: DC 3.3V~5V 

工作电流: 4.2mA

最大功率: 0.03WW

输出信号: 数字信号

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 8mm

接口：2.54mm间距，3pin防反接口

**3. 原理图：**

![](media/0261aa6e00c1752e439461c9f0e8c210.png)

Keyes 倾斜开关模块的原理非常简单，主要是利用滚珠在开关内随不同倾斜角度的变化使滚珠开关P1的引脚1和2导通或者不导通，当滚珠开关P1的引脚1和2导通时，由于1脚接GND，所以信号端S被拉低为低电平，此时红色LED和R2组成的电路形成回路，电流经过红色LED，点亮红色LED；当滚珠开关P1的引脚1和2不导通时，滚珠开关P1的引脚2被4.7K的上拉电阻R1拉高使得信号端S为高电平，电流不经过红色LED，红色LED熄灭。

**4. 接线图：**

![](media/cd897a9d6bbad8020133fe32af45946f.png)

**5. 实验代码：**

```c
/*
 * 名称   : Tilt Switch
 * 功能   : 读取倾斜开关模块的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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

```

**6. 实验结果：**

按照接线图接好线，上传代码，打开串口监视器，设置波特率为9600，水平放置倾斜开关模块，模块上LED灯亮，串口打印“Normal！”，模块向右倾斜LED灯灭，串口打印“Tilt warning！”

![](media/b6ba2257794428b425c1a1e38c58af15.png)

### 第5课 光敏传感器

![](media/43852f78b7743c2c0365c7141b1cacee.png)

**1. 项目介绍：**

Keyes 光敏电阻传感器，这是一个常用的光敏电阻传感器，它主要由一个光敏电阻元件组成。光敏电阻元件的阻值随着光照强度的变化而变化，此传感器就是利用光敏电阻元件这一特性，设计电路将阻值变化转换为电压变化。光敏电阻传感器可以模拟人对环境光线的强度的判断，方便做出与人友好互动的应用。

**2. 规格参数：**

工作电压: DC 3.3V~5V 

工作电流: 0.2mA

最大功率: 0.001W

输出信号: 模拟信号

工作温度：-10°C ~ +50°C

尺寸：32 x 23.8 x 7.4 mm

接口：2.54 mm间距，3pin防反接口

**3. 原理图：**

![](media/baae5294d38c9b71f3061f09301a7da3.png)

当没有光照射时，电阻大小为0.2 MΩ，光敏电阻的信号端（2脚）检测的电压接近0。随着光照强度增大，光线传感器的电阻值越来越小，所以信号端能检测到的电压越来越大。

**4. 连接图：**

![](media/4a64e6465912093873c37ff65b1d6fba.png)

**5. 实验代码：**

```c
/*
 * 名称   : Photoresistor
 * 功能   : 读取光敏传感器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
int sensorPin =A0 ;  //定义引脚A0
int value = 0;    //设置value为0

void setup() {
  Serial.begin(9600); //设置波特率9600
} 

void loop() {
  value = analogRead(sensorPin);  //将value设置为读取到的A0的数值
  Serial.println(value, DEC);  //显示value数值，并自动换行
  delay(500);  //延迟0.5S
}
```

**6. 实验结果：**

按照接线图接好线，上传代码，打开串口监视器，设置波特率为9600，便可以看到代表当前光线强弱的模拟值，如下图。

![](media/9e1d20538ba7f61d1e05e2ede5785394.png)

### 第6课 声音传感器

![](media/12cc26052d7cb93b9544d8fed5a015eb.png)

**1. 项目介绍：**

Keyes 声音传感器可以用于测试当前环境中的声音对应的模拟值，传感器上的S端是模拟输出，是麦克风的电压信号实时输出，可以通过电位器可调节信号增益。声音越大，模拟值越大，并在串口监视器上显示测试结果。

**2. 规格参数：**

工作电压: DC 3.3V~5V 

工作电流: 15mA

最大功率: 0.075W

输出信号: 模拟信号

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 10.3mm

接口：2.54mm间距，3pin防反接口

**3. 原理图：**

![](media/71a2e4411640a5c34e4173acf893b2a6.png)

Keyes 声音传感器主要由一个高感度麦克风元件和LM386音频功率放大器芯片组成，高感度麦克风元件用于检测外界的声音。声波使麦克风内的驻极体薄膜振动，导致电容的变化，而产生与之对应变化的微小电压。利用LM386音频功率放大器芯片设计对高感度麦克风检测到的声音进行放大的电路，最大倍数为200倍。使用时我们可以通过旋转传感器上电位器，调节声音的放大倍数。顺时针调节电位器到尽头，放大倍数最大。
**4. 连接图：**

![](media/3b1393eefd6b328465c78b125972ce6e.png)

**5. 实验代码：**

```c
/*
 * 名称   : Sound sensor
 * 功能   : 读取声音传感器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
int sensorPin = A0 ;  //定义模拟口A0
int value = 0;    //设置value为0

void setup() {
  Serial.begin(9600); //设置波特率
} 

void loop() {
  value = analogRead(sensorPin);  //将value设置为读取到的A0的数值
  Serial.println(value, DEC);  //显示value数值，并自动换行
  delay(200);  //延迟0.2S
}
```

**6. 实验结果：**

按照连接图接好线，上传代码，打开串口监视器，设置波特率为9600，便可以看到声音的模拟值了，声音越大模拟值越大。如下图：

![](media/12cd2f8441edb9f4c9d94d7d2cefd481.png)

![](media/dc4858f790dced2508df628b7b26a721.png)

### 第7课 旋转电位器模块

![](media/64deff371131b942371d6916d56ff09c.png)

**1. 项目介绍：**

Keyes 旋转电位器，它一个模拟传感器。模块上电后，我们只需选择模块上电位器就可以调节模拟输出数值。

**2. 规格参数：**

工作电压: DC 3.3V~5V 

工作电流: 0.55mA

工作功率: 0.00275W

输出信号: 模拟信号

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 28.4mm

接口：2.54mm间距，3pin防反接口

**3. 原理图：**

![](media/9f9e301d7d315c442a43958db97aaa9a.png)

旋转电位器其实就是一个可以改变电阻值的电阻元件，我们这个电位器是10K的，也就是说我们可以通过旋转便可以得到0-10K的任意阻值，根据欧姆定律U=I\*R，所以我们通过改变R的阻值进行控制电压的大小。而我们的Arduino主控板会将读取到的0-5V的电压分成1024份，所以就得到了模拟值。

**4. 连接图：**

![](media/6404fda2df365fcc0506f380af9a47a6.png)

**5. 实验代码：**

```c
/*
 * 名称   : Potentiometer
 * 功能   : 读取旋转电位器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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
```

**6. 实验结果：**

按照连接图连接好线，上传代码，打开串口监视器，设置波特率为9600，我们便能看见旋转电位器的模拟值了，扭动旋转电位器值发生变化。如下图：

![](media/258a31b4d62381b63bf6bb6bbbb9d1e8.png)

### 第8课 温湿度传感器

![](media/f11d9320a04fd1ff003c34ffc975b1fe.png)

**1. 项目介绍：**

Keyes XHT11温湿度传感器。XHT11作为一款低价的入门级温湿度传感器，它主要由一个电阻式感湿元件和一个NTC测温元件组成。XHT11为4针单排引脚封装，采用单线制串行接口，只需加适当的上拉电阻，信号传输距离可达20米以上，Keyes XHT11温湿度传感器具有超快响应、抗干扰能力强、性价比极高等优点。

**2. 规格参数：**

工作电压: DC 3.3V~5V 

工作电流: 2.1mA

最大功率: 0.015W

温度范围: -25 ~ +60°C (± 2℃)

湿度范围: 5 ~ 95%RH（25C°左右精度为±5%RH）

输出信号: 数字双向单总线

工作温度: -25°C ~ +60°C

尺寸：32mm x 23.8mm x 9.7mm

接口：2.54mm间距，3pin防反接口

**3. 原理图：**

![](media/ac2d483d7421e0871fce88f05e38c27a.png)

HT11温湿度传感器，包括一个电阻式感湿元件和一个NTC测温元件，XHT11为4针单排引脚封装，如上图，采用单线制串行接口，只需加适当的上拉电阻，信号传输距离可达20米以上，使其成为各类应用甚至最为苛刻的应用场合的最佳选择。

单片机与 XHT11之间的通讯和同步,采用单总线数据格式,一次通讯时间4ms左右,数据分小数部分和整数部分,具体格式在下面说明,当前小数部分用于以后扩展,现读出为零，操作流程：一次完整的数据传输为40bit，高位先出。

**数据格式：** 8bit湿度整数数据+8bit湿度小数数据+8bi温度整数数据+8bit温度小数数据+8bit校验和。

**8位校验和：** 8bit湿度整数数据+8bit湿度小数数据+8bi温度整数数据+8bit温度小数数据"相加所得结果的末8位。

该传感器具有品质卓越、超快响应、抗干扰能力强、性价比极高等优点。

**4. 连接图：**

![](media/a50ed24c2e65b97c87e51b06e2ec8520.png)

**5. 实验代码：**

```c
/*
 * 名称   : XHT11
 * 功能   : 读取温湿度传感器的温度和湿度
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
#include <dht11.h>  //导入库文件
dht11 DHT;
#define DHT11_PIN A0 //定义DHT11引脚为A0

void setup() {
  Serial.begin(9600);
}
void loop() {
  int chk;
  chk = DHT.read(DHT11_PIN);  // 读取数据
  switch (chk) {
    case DHTLIB_OK:
      break;
    case DHTLIB_ERROR_CHECKSUM: //校检和错误返回
      break;
    case DHTLIB_ERROR_TIMEOUT: //超时错误返回
      break;
    default:
      break;
  }
  // 显示数据
  Serial.print("humidity:");
  Serial.print(DHT.humidity);
  Serial.print("   temperature:");
  Serial.println(DHT.temperature);
  delay(200);
}
```

**6. 实验结果：**

按照连接图接好线，上传代码，打开串口监视器，设置波特率为9600，便可以看到当前环境温度值和湿度值，如下图。

![](media/52b52da9015ddd0e272a2b89261b927e.png)

### 第9课 薄膜压力传感器

![](media/55dc59310d7c729bf5d66af7e443b2ca.png)

**1. 项目介绍：**

Keyes 薄膜压力传感器是基于新型纳米压敏材料辅以舒适杨式模量的超薄薄膜衬底一次性贴片而成，兼具防水和压敏双重功能。当传感器感知到外界压力时，传感器电阻值发生变化，我们采用电路将传感器感知压力变化的压力信号转换成相应变化强度的电信号输出。这样我们就可以通过检测电信号变化就可以得到压力变化情况。

通过采集模块上S端模拟信号，判断压力大小。模拟值越小，压力越大；并在串口监视器上显示测试结果。

**2. 规格参数：**

工作电压: DC 3.3V~5V

工作电流: 0.5mA

最大功率: 0.0025W

量程: 0~10KG

响应点: 150g

重复性: ＜±9.7%（60%负载）

一致性: ±10%

耐久性: ＞100万次

初始电阻: 大于10MΩ(无负载)

响应时间: ＜1ms

恢复时间: ＜15ms

输出信号: 模拟信号

工作温度：-10°C ~ +50°C

尺寸：32mm x 23.8mm x 7.4mm

接口：2.54mm间距，3pin防反接口

**3. 原理图：**

![Img](./media/img-20240920175918.png)

当传感器感知到外界压力时，传感器的电阻值发生变化。Keyes 薄膜压力传感器使用LM321运算放大器芯片将传感器感知到的压力变化的压力信号转换成相应变化强度的电信号输出，这样就可以通过检测电压信号变化得知压力变化情况。

**4. 连接图：**

![](media/051b335131b196649ac9cf69ad785182.png)

**5. 实验代码：**

```c
/*
 * 名称   : Pressure_Sensor
 * 功能   : 读取压力传感器的值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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
```

**6. 实验结果：**

按照接线图接好线，上传代码，打开串口监视器，设置波特率为9600，便能看见压力传感器的模拟值了，按压感应区便能改变模拟值，如下图：

![](media/87839823410080ee16775a1e64e3c8bf.png)

**7. 特别注意：**

前面的值是属于压力的模拟值并非压力值，要想得到压力值方法如下：

1. 该传感器模块利用1个传感器元件串联1个510KΩ电阻。传感器一端接5V电源，一端连接510KΩ电阻，电阻连接GND。测试时，传感器连接电阻的一端为信号端，接模拟口。

2. 通过上述描述，我们得到电阻和模拟值的计算公式：

3. R =（1023-A0）\* 510 / A0  单位为KΩ

4. 根据上述公式，我们得到传感器元件电阻值，观察以下压力-阻值关系图，我们可以大概得到压力值，我们没有详细公式计算出具体的压力数值。

![](media/9a791bcaedaa65a95cafa03ab1034f05.png)

5. 从图片上可以观察到，到压力值大于5000g时，压力值变化，电阻值几乎不变化，因此，我们建议测试时，最大压力值为5000g。

6. 由于传感器元件感应区是凹进去的，测试时，需要将测试物体放在圆片中间的感应区域内才可以测试出结果；如果把传感器直接放在平面上，将测试物体放在传感器感应区，是测试不出结果的。因此，我们需要在传感器感应区内垫一个小物体，再将测试物体放在传感器感应区的小物体上，才能测试出结果。

### 第10课 LCD 128\*32 DOT模块

![](media/a3fc1ac20c4429413f304a0b33b679f4.png)

**1. 项目介绍：**

128\*32的液晶屏模块，它的驱动芯片为ST7567A，像素为128\*32。模块使用IIC通信方式，它不仅可以显示英文文字，还可以显示中文文字，数字和图案。

为了方便设置，我们还提供一个测试代码，代码中，我们设置显示屏显示各种英文文字、常用符号和一个图案等。同时，代码中包含所有英文字母和常用符号的库，可以直接调用。

特别注意，模块的接口为蓝色的4pin自锁接口，接口间距为2.54mm，使用时，我们需要利用特定的接线连接。

**2. 规格参数：**

分辨率：128\*32

工作电压：5V

电流：100MA

最大功率：0.5W

工作温度：0摄氏度 到 40摄氏度

尺寸：47.6MM \*23.8MM

通信方式：IIC通信

亮度、对比度可通过程序指令控制

接口：4PIN接口，间距为2.54mm

**3. 原理图：**

![](media/87c0ce8afc5d6a8c9baea3f76e75a12f.png)

该模块使用IIC通讯原理，底层函数我们已经封装在库里面，我们直接调用库函数就可以，如果感兴趣的话也可以去了解该模块的底层驱动。

**4. 连接图：**

![](media/debeabde1e140d1884eb6244a610afa2.png)

**5. 实验代码：**

```c
/*
 * 名称   : 128x32_LCD
 * 功能   : 128x32 LCD显示
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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
```

**6. 实验结果：**

按照连接图接好线，上传代码，便能看见LCD上显示我们设置好的字符了。如下图：128X32LCD模块显示屏第一行显示“KEYES”、第二行显示“ABCDEFGHIJKLMNOPQR”、第三行显示“123456789+-\*/\<\>=$@”、第四行显示“%^&(){}:;'|?,.~\\\[\]”，如下图所示：

![](media/d1f543358fa84e0845b84cdae3a1a69f.png)

### 第11课 门铃

**1. 项目介绍：**

扩展对传感器的使用思维，将它们结合起来做出更有意思的东西。这节课我们要做的是门铃，也就是将按键和蜂鸣器结合起来。当按下按键时，蜂鸣器便发出声音。

**2. 连接图：**

![](media/dd82a69eb41f7ae9e96d63757920b5fe.png)

**3. 实验代码：**

```c
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
```

**4. 实验结果：**

按照接线图接好线，上传代码完成后，按下按键蜂鸣器便会响起。

**5. 扩展：**

上面我们的门铃是按下就一直响，想办法将它变成按下按键后门铃“滴~滴~滴~”的响呢?

### 第12课 闯入报警器

**1. 项目介绍：**

在生活中，相信大家已经对走到楼梯口灯就会自动亮起来已经习以为常了，这节课就是使用人体红外热释传感器与蜂鸣器做一个有人闯入就会报警的设备。

**2. 连接图：**

![](media/6364a743b4bc50ad796447e3f093620e.png)

**3. 实验代码：**

```c
/*
 * 名称   : Burglar_Alarm
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
```

**4. 实验结果：**

按照连接图接好线，上传代码，当传感器前方有人移动时蜂鸣器便会发出滴滴滴的警报声

### 第13课 压力报警器

**1. 项目介绍：**

这一课我们学习薄膜压力传感器与蜂鸣器的搭配，当压力过了一定值时蜂鸣器便发声报警。

**2. 连接图：**

![](media/26a4e721d30db2ad39c4ef10bf0c7e4f.png)

**3. 实验代码：**

```c
/*
 * 名称   : Pressure_Alarm
 * 功能   : 压力传感器控制蜂鸣器鸣叫
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
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
```

**4. 实验结果：**

按照连接图接好线，上传代码，当按压薄膜压力传感器的感应区的力度大于模拟值的600时蜂鸣器便会发声报警。

### 第14课 LCD仪表盘

**1. 项目介绍：**

我们有很多个传感器需要看数值，而又不能一直拿着电脑看，这时候LCD模块就起作用了，可以利用它来显示各种数据。

**2. 连接图：**

![](media/79759ed26473b38d5063f75363334710.png)

**3. 实验代码：**

```c
/*
 * 名称   : LCD_Dashboard
 * 功能   : LCD显示温湿度值, 光照强度值和电位器值
 * 编译IDE：ARDUINO 2.3.2
 * 作者   : https://www.keyestudio.com/
*/
#include "lcd128_32_io.h" //导入lcd128_32_io库文件
lcd Lcd(A4,A5);

#include<dht11.h> //导入dht11库文件
dht11 DHT;
#define DHT11_PIN A0  //定义XHT11温湿度传感器的引脚为A0

int pot = A1; //定义旋转电位器的引脚为A1
int pho = A2; //定义光敏传感器的引脚为A2

void setup() {
  Serial.begin(9600);
  Lcd.Init(); //初始化
  Lcd.Clear();  //清屏
}

void loop() { 
  read_dht11_data();     //调用dht11读取函数    

    //湿度显示程序
  int humidity = DHT.humidity;      
  Lcd.Cursor(0, 0);                         //设置第0行，第0列开始显示
  Lcd.Display("humidity:");                 //显示“humidity:”
  Lcd.Cursor(0, 10);                        //设置第0行，第10列开始显示
  Lcd.Display_Num(humidity);                //实时显示数字，下方代码的都是同样的步骤
    
    //温度显示程序
  int temperature = DHT.temperature;
  Lcd.Cursor(1, 0);
  Lcd.Display("temperature:");
  Lcd.Cursor(1, 13);
  Lcd.Display_Num(temperature);
    
    //光亮度值显示程序
  int val1 = analogRead(pho);
  Lcd.Cursor(2, 0);
  Lcd.Display("Luminance:");
  Lcd.Cursor(2, 11);
  Lcd.Display_Num(val1);
    
    //旋转电位器值显示
  int val2 = analogRead(pot);
 
  Lcd.Cursor(3, 0);
  Lcd.Display("Analog:");
  Lcd.Cursor(3, 8);
  Lcd.Display_Num(val2);
  delay(100);

}

void read_dht11_data(){
    int chk;
  chk = DHT.read(DHT11_PIN);    // READ DATA
  switch (chk) {
    case DHTLIB_OK:
      break;
    case DHTLIB_ERROR_CHECKSUM: //校检和错误返回
      break;
    case DHTLIB_ERROR_TIMEOUT: //超时错误返回
      break;
    default:
      break;
  }
}
```

**4. 实验结果：**

按照连接图接好线，上传代码，便能看见LCD上显示我们需要的传感器值了。如下图：128X32LCD模块显示屏第一行显示湿度、第二行显示温度、第三行显示光亮度、第四行显示电位器的模拟值，如下图所示：

![](media/689318e48d9c7635338e4f1f042ae5de.png)
