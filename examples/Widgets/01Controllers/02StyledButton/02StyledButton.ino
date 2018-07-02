/*************************************************************
  项目说明：用按钮控制GPIO2的LED
  App项目设置:
  创建StyledButton组件，输出管脚设置为GPIO2,模式设为switch
  APP端组件设置说明：
  - 设置StyledButton名称，如客厅灯，台灯
  - OUTPUT管脚：可以设置为数字管脚，模拟管脚或者虚拟管脚
  - MODE：PUSH-轻触开关，按下有效，松开无效；SWITCH：切换开关，按下有效，再按一次无效
  - ON/OFF STATES：开关样式，可以设置开和关的文本、文本颜色、背景色、文字大小。
  - EDGES:圆角设置，可预：圆角、方角、胶囊型
  - LOCK SIZE：是否锁定尺寸
  *************************************************************/
#define BLYNK_PRINT Serial // 开启串口监视
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "c3102448027d494ca48b27d0a732f245";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);//官方服务器
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);//自建服务器域名模式
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 158), 8080);//自建服务器ip模式
}

void loop()
{
  Blynk.run();
}