/*************************************************************
  项目说明：被动发送数据给app
  App项目设置:
  创建value display组件，设置管脚为V5，
  READING RATE (读取频率)设置为任何值，如1秒。

  温馨提示：
  该例子与PushData的区别：PushData是每隔一定时间主动发送数据给app，
  这个间隔时间是程序里写好的；
  而PushDdataOnRequest是不会主动发送数据给app的，
  只有当app询问的时候才会发送数据，而这个询问的频率是由app端设置的。
 *************************************************************/
#define BLYNK_PRINT Serial // 开启串口监视
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "2a365b624c0f4ea891256d4a66d428f7";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码
#define PIN_UPTIME V5


//当app有请求时，开发板才会调用次函数发送数据
BLYNK_READ(PIN_UPTIME)
{
  //该命令会将开发板已经运行的时间发给V5
  Blynk.virtualWrite(PIN_UPTIME, millis() / 1000);
}

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

