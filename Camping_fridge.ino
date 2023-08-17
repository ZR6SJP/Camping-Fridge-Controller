
// Load libraries
#include "BluetoothSerial.h"
#include <DallasTemperature.h>
#include <OneWire.h>

// Check if Bluetooth configs are enabled
#if !defined(CONFIG_BT_ENABLED) || !defined(CONFIG_BLUEDROID_ENABLED)
#error Bluetooth is not enabled! Please run `make menuconfig` to and enable it
#endif

// Bluetooth Serial object
BluetoothSerial SerialBT;



// GPIO where the DS18B20 is connected to
const int TempPin =  2;

OneWire onewire (TempPin);

DallasTemperature sensors(&onewire);

// Handle received and sent messages
String message = "";
char incomingChar;
String temperatureString = "";


void setup() {
  pinMode(TempPin, OUTPUT);
  Serial.begin(115200);
  sensors.begin();
  // Bluetooth device name
  SerialBT.begin("ESP32");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  unsigned long currentMillis = millis();
        sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
  SerialBT.print(temperature);
  SerialBT.println("ºC");

  
  // Read received messages (LED control command)
  if (SerialBT.available()){
    char incomingChar = SerialBT.read();
    if (incomingChar != '\n'){
      message += String(incomingChar);
    }
    else{
      message = "";
    }
    Serial.write(incomingChar);  
  }
  // Check received message and control output accordingly
  
  delay(5000);
}
