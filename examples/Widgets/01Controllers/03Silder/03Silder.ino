/**************************************************************
  项目说明：用slider控制GPIO2的LED亮度
   APP端组件设置说明：
  - 设置slider名称,如调光台灯
  - OUTPUT管脚:可以设置为数字管脚,模拟管脚或者虚拟管脚,最小值设为0,最大值设为1023
  - SEND ON RELEASE:松开发送
  - SHOW VALUE:显示数值
*************************************************************/
#define BLYNK_PRINT Serial // 开启串口监视
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "2a365b624c0f4ea891256d4a66d428f7";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  // Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 163), 8080);
}

void loop()
{
  Blynk.run();
}

