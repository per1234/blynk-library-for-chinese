/*************************************************************
  项目说明：控制app端LED颜色
  App项目设置:创建LED组件，设置管脚为V1
 *************************************************************/
#define BLYNK_PRINT Serial

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
char auth[] = "2a365b624c0f4ea891256d4a66d428f7";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码

WidgetLED led1(V1);

BlynkTimer timer;
bool ledStatus = false;

#define BLYNK_GREEN     "#23C48E"//定义颜色
#define BLYNK_BLUE      "#04C0F8"
#define BLYNK_YELLOW    "#ED9D00"
#define BLYNK_RED       "#D3435C"
#define BLYNK_DARK_BLUE "#5F7CD8"


void blinkLedWidget()
{
  if (ledStatus) {
    led1.setColor(BLYNK_RED);//设置为红色
    Serial.println("LED on V1: red");
    ledStatus = false;
  } else {
    led1.setColor(BLYNK_GREEN);//设置为绿色
    Serial.println("LED on V1: green");
    ledStatus = true;
  }
}

void setup()
{

  Serial.begin(9600);
  //Blynk.begin(auth, ssid, pass);//官方服务器
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);//自建服务器域名模式
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 158), 8080);//自建服务器ip模式

  led1.on();//点亮LED
  timer.setInterval(1000L, blinkLedWidget);//每隔一秒运行blinkLedWidget函数
}

void loop()
{
  Blynk.run();
  timer.run();
}

