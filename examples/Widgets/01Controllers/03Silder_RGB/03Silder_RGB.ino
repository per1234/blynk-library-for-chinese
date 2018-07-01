/**************************************************************
  项目说明：RGB彩灯控制
  温馨提示：该项目需要下载以下第三方库
  https://github.com/adafruit/Adafruit_NeoPixel
  APP设置：
  创建Slider组件，管脚V1，数值范围0~255，名称设置为红色
  创建Slider组件，管脚V2，数值范围0~255，名称设置为蓝色
  创建Slider组件，管脚V3，数值范围0~255，名称设置为绿色

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
//（灯数，管脚，型号）
BLYNK_WRITE(V1)
{ //红色
  R = param.asInt();
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, R, G, B);
  }
  strip.show();
}

BLYNK_WRITE(V2)
{ //蓝色
  G = param.asInt();
  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, R, G, B);
  }
  strip.show();
}

BLYNK_WRITE(V3)
{ //绿色
  B = param.asInt();
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
  // Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);
  //Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 163), 8080);
  strip.begin();
  strip.show();
}

void loop()
{
  Blynk.run();
}

