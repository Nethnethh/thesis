// Adafruit_TCS34725_test 
#include <Adafruit_TCS34725.h> // Include Library
Adafruit_TCS34725 tcs = Adafruit_TCS34725(TCS34725_INTEGRATIONTIME_50MS, TCS34725_GAIN_4X); // Initialize with settings
void setup() {
  Serial.begin(9600);
  tcs.begin(); // Start sensor
  // Configure gain/time if needed: tcs.setGain(TCS34725_GAIN_1X);
}

void loop() {
  uint16_t r, g, b, c; // Raw values
  tcs.getRawData(&r, &g, &b, &c); // Read RGBc
  Serial.print("R: "); Serial.print(r); Serial.print(" G: "); 
  Serial.print(g); Serial.print(" B: "); Serial.print(b); 
  Serial.print(" C: "); Serial.println(c);
  // Add color filtering logic here (e.g., if (r > g && r > b) { Serial.println("Red"); })
  delay(1000);
}


// Analog pH sensor_test 

const int pHSensorPin = A0; 
void setup() {
  Serial.begin(9600);  // Initialize serial communication
} 
void loop() {
  int sensorValue = analogRead(pHSensorPin);
  float pHValue = map(sensorValue, 0, 1023, 0, 14);  
  Serial.print("pH Value: ");
  Serial.println(pHValue); 
  delay(1000);  
}

// MG-138 sensor 

const int MQ_PIN = A0; 
void setup() {
  Serial.begin(9600); 
  pinMode(MQ_PIN, INPUT);
}
void loop() {
  int sensorValue = analogRead(MQ_PIN); 
  Serial.print("Analog Value: ");
  Serial.println(sensorValue);
  delay(1000); // Wait for a second
}

// BME680_sensor 

#include <Wire.h>
#include <Adafruit_BME680.h>

#define SDA_PIN D2
#define SCL_PIN D1

Adafruit_BME680 bme;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Wire.begin(SDA_PIN, SCL_PIN);

  if (!bme.begin(0x77)) {  // ← changed 0x76 to 0x77
    Serial.println("BME680 not found! Check wiring.");
    while (1);
  }

  bme.setTemperatureOversampling(BME680_OS_8X);
  bme.setHumidityOversampling(BME680_OS_2X);
  bme.setPressureOversampling(BME680_OS_4X);
  bme.setGasHeater(320, 150);

  Serial.println("BME680 ready!");
}

void loop() {
  if (bme.performReading()) {
    Serial.print("Temp: ");     Serial.print(bme.temperature);    Serial.println(" C");
    Serial.print("Humidity: "); Serial.print(bme.humidity);       Serial.println(" %");
    Serial.print("Pressure: "); Serial.print(bme.pressure / 100); Serial.println(" hPa");
    Serial.print("Gas VOC: ");  Serial.print(bme.gas_resistance); Serial.println(" ohms");
    Serial.println("---");
  } else {
    Serial.println("Reading failed!");
  }
  delay(2000);
}


 




