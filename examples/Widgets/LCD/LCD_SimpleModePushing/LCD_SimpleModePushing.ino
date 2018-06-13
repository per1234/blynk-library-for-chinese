/*************************************************************
项目说明：LCD简单模式
App项目设置:创建LCD组件，设置为simple模式，
输入0号设置为V0；输入1号设置为V1；
message设置
第一行："/pin0/ seconds"
第二行："/pin1/ millis"

 *************************************************************/
#define BLYNK_PRINT Serial


#include <SPI.h>
#include <Ethernet.h>
#include <BlynkSimpleEthernet.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "YourAuthToken";

BlynkTimer timer;

void sendSeconds() {
  Blynk.virtualWrite(V0, millis() / 1000);
}

void sendMillis() {
  Blynk.virtualWrite(V1, millis());
}

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth);

  // Setup a function to be called every second
  timer.setInterval(1000L, sendSeconds);
  // Setup a function to be called every second
  timer.setInterval(1000L, sendMillis);
}

void loop()
{
  Blynk.run();
  timer.run();
}

