#include <SoftwareSerial.h>
#include <ArduinoJson.h>
// UNO Pin 5 -> Pin D5 NodeNCU, UNO Pin 6 -> Pin D6 NodeMCU
SoftwareSerial NodeSerial(5, 6);

void setup() {
  //Serial ของ UNO -> NodeMCU
  NodeSerial.begin(9600);
}

void loop() {
  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject & root = jsonBuffer.createObject();
  //ส่งแบบ String
  root["data1"] = "Hello World!";
  //ส่งแบบ Integer
  root["data2"] = 123;
  //ส่งแบบ Float
  root["data3"] = 3.141526;
  if (NodeSerial.available() > 0)
  {
    root.printTo(NodeSerial);
  }
}
