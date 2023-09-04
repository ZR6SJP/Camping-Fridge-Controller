
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
const int TempPin =  4;
const int Analog_channel_pin=15;
float ADC_VALUE = 0;
float voltage_value = 0;
float voltage_value_BT = 0; 

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
  SerialBT.begin("ESP32_dad_2");
  Serial.println("The device started, now you can pair it with bluetooth!");
}

void loop() {
  unsigned long currentMillis = millis();
        sensors.requestTemperatures();
  float temperature = sensors.getTempCByIndex(0);
 
  SerialBT.print(temperature);
  SerialBT.println("ºC");
  ADC_VALUE = analogRead(Analog_channel_pin);
  voltage_value = (ADC_VALUE/4096 * 26.5);
  voltage_value_BT = voltage_value + 0.8;
  SerialBT.print(voltage_value_BT);
  Serial.println(voltage_value);
  SerialBT.println("v");

  
  
  delay(3000);
}
