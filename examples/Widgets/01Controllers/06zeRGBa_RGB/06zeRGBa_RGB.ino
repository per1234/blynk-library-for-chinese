/**************************************************************
  项目说明：斑马取色控制RGB彩灯
  温馨提示：该项目需要下载以下第三方库
  https://github.com/adafruit/Adafruit_NeoPixel
  APP设置：
  创建zeRGBa组件，管脚V1，输出模式设为Merge（合并）
  创建Button组件，管脚V0，模式设置为PUSH。
 *************************************************************/
#define BLYNK_PRINT Serial // 开启串口监视
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Adafruit_NeoPixel.h>
char auth[] = "2a365b624c0f4ea891256d4a66d428f7";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码
#define PIN 12
int R, G, B;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(4, PIN, NEO_GRB + NEO_KHZ800);
BLYNK_WRITE(V0)
{ //开关
  int state = param.asInt();
  if (state)
    strip.show();
  else
    strip.clear();
}
BLYNK_WRITE(V1)
{ //斑马取色
  R = param[0].asInt();
  G = param[1].asInt();
  B = param[2].asInt();
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, R, G, B);
  }
  strip.show();
}
void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 163), 8080);
  strip.begin();
  strip.show();
}
void loop()
{
  Blynk.run();
}

