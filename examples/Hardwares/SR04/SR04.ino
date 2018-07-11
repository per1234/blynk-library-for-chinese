/*************************************************************
  项目说明：超声波测距
  App项目设置:
  创建Value display组件，设置管脚为V5
  *************************************************************/
#define BLYNK_PRINT Serial // 开启串口监视
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Ultrasonic.h>
char auth[] = "c3102448027d494ca48b27d0a732f245";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码

Ultrasonic ultrasonic(4, 5, 3000); // (Trig 管脚,Echo 管脚,超时值)
//超时值=最远探测距离（cm）*58;
//如：希望最远检测距离为50cm,则超时值为50*58=2900

BlynkTimer timer;

void SR04()//输出管脚设置为虚拟管脚V5
{
  // 发送数据的频率不要超过每秒10次。
  Blynk.virtualWrite(V5, ultrasonic.Ranging(CM));// CM or INC
}
void setup() {
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);//官方服务器
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);//自建服务器域名模式
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 158), 8080);//自建服务器ip模式
  timer.setInterval(1000L, SR04);//每隔1000毫秒执行一次SR04函数
}

void loop()
{
  Blynk.run();
  timer.run(); //初始化定时器
}
