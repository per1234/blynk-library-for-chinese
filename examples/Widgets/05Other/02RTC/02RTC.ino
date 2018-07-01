/*************************************************************
  项目说明：RTC
  App项目设置:创建RTC组件，
  创建Value Display组件，管脚设为V1,
创建Value Display组件，管脚设为V2,
温馨提示：
本项目需要额外库
 https://github.com/PaulStoffregen/Time
 本项目基于
 https://github.com/PaulStoffregen/Time/blob/master/examples/TimeSerial/TimeSerial.ino

 *************************************************************/
 #define BLYNK_PRINT Serial

 #include <ESP8266WiFi.h>
 #include <BlynkSimpleEsp8266.h>
 #include <TimeLib.h>
 #include <WidgetRTC.h>

char auth[] = "2a365b624c0f4ea891256d4a66d428f7";//授权码
char ssid[] = "ssid";//wifi名称
char pass[] = "psssword";//wifi密码
BlynkTimer timer;

WidgetRTC rtc;//创建rtc组件

void clockDisplay()//显示时间
{
 //你可以使用hour(), minute(), ...
//更多细节，请参考Time库 中的例子
String currentTime = String(hour()) + ":" + minute() + ":" + second();
String currentDate = String(day()) + " " + month() + " " + year();
Serial.print("Current time: ");
Serial.print(currentTime);
Serial.print(" ");
Serial.print(currentDate);
Serial.println();
  Blynk.virtualWrite(V1, currentTime);//向App发送时间
  Blynk.virtualWrite(V2, currentDate);//向App发送日期
}

BLYNK_CONNECTED() {
  rtc.begin();//连上后同步时间
}

void setup()
{
  
  Serial.begin(9600);

  //Blynk.begin(auth, ssid, pass);//官方服务器
  //Blynk.begin(auth, ssid, pass, "blynk-cloud.com", 8080);//自建服务器域名模式
  Blynk.begin(auth, ssid, pass, IPAddress(192, 168, 1, 158), 8080);//自建服务器ip模式

  // 也可以使用其他Time 库中的函数，比如：
  //   timeStatus(), setSyncInterval(interval)...
  // 更多资料，请参考: http://www.pjrc.com/teensy/td_libs_Time.html

  setSyncInterval(10 * 60); // 设置同步间隔时间，10分钟。
  timer.setInterval(10000L, clockDisplay);//每隔10s，运行clockDisplay，显示时间
}

void loop()
{
  Blynk.run();
  timer.run();
}

