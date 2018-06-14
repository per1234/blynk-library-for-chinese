/*************************************************************
  项目说明：发送数据给app
  App项目设置:
  创建value display组件，输入管脚设置为V5
 *************************************************************/
#define BLYNK_PRINT Serial // 开启串口监视
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "2a365b624c0f4ea891256d4a66d428f7";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码
BlynkTimer timer;

void myTimerEvent()
{
  // 发送数据的频率不要超过每秒10次。
  Blynk.virtualWrite(V5, millis() / 1000);
}

void setup()
{
  Serial.begin(9600);
  // Blynk.begin(auth, ssid, pass);//官方服务器
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);//自建服务器域名模式
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 158), 8080);//自建服务器ip模式
  timer.setInterval(1000L, myTimerEvent);//每隔1000毫秒执行一次myTimerEvent函数
}

void loop()
{
  Blynk.run();
  timer.run(); //初始化定时器
}

