/*************************************************************
  项目说明：定时器
  App项目设置:创建Timer组件，设置管脚为V5
  该项目将在指定的时间触发IO口高低电平的变化。
  Timer组件可以控制ADC和GPIO口。
*************************************************************/
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "2a365b624c0f4ea891256d4a66d428f7";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码
BLYNK_WRITE(V5)
{
  // You'll get HIGH/1 at startTime and LOW/0 at stopTime.
  //你可以在app端设置开始时间和结束时间，
  //并在两个时间发出电平变化的触发。
  //该方法可以定时每天触发，
  //直到你移除该组件或者停止该项目为止。
  Serial.print("Got a value: ");
  Serial.println(param.asStr());
}

void setup()
{
  Serial.begin(9600);
  // Blynk.begin(auth, ssid, pass);//官方服务器
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);//自建服务器域名模式
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 158), 8080);//自建服务器ip模式
}

void loop()
{
  Blynk.run();
}

