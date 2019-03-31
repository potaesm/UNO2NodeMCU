#include <SoftwareSerial.h>
#include <ArduinoJson.h>
// UNO Pin 5 -> Pin D5 NodeNCU, UNO Pin 6 -> Pin D6 NodeMCU
SoftwareSerial UNOSerial(D6, D5);

void setup() {
  //Serial อันนี้เป็นของ NodeMCU -> PC
  Serial.begin(9600);
  //Serial อันนี้เป็นของ UNO -> NodeMCU ตรงนี้ Baudrate ต่ำ ๆ ช่วยลดความผิดพลาดในการรับข้อมูล (ต้องตรงกันทั้งตัวรับ-ส่ง-PC)
  UNOSerial.begin(9600);
  while (!Serial) continue;

}

void loop() {

  StaticJsonBuffer<1000> jsonBuffer;
  JsonObject & root = jsonBuffer.parseObject(UNOSerial);
  if (root == JsonObject::invalid()) {
    return;
  }
  //ตรงนี้ไว้แสดง JSON, เป็นข้อมูลทั้งหมดที่ได้รับมาจากตัวส่ง
  /*root.prettyPrintTo(Serial);
    Serial.println("");*/
  //แสดง Data1
  Serial.print("Data 1 : ");
  String Data1 = root["data1"];
  Serial.println(Data1);
  Serial.print("Data 2 : ");
  //แสดง Data2
  String Data2 = root["data2"];
  Serial.println(Data2);
  Serial.print("Data 3 : ");
  //แสดง Data3
  String Data3 = root["data3"];
  Serial.println(Data3);
  Serial.println("----------------------------------------------");

}
