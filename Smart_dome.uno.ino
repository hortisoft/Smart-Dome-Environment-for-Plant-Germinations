//only code for check dht22's 

// #include <DHT.h>

// #define DHTPIN1 32
// #define DHTPIN2 33
// #define DHTTYPE DHT22

// DHT dht1(DHTPIN1, DHTTYPE);
// DHT dht2(DHTPIN2, DHTTYPE);

// void setup() {
//   Serial.begin(115200);
//   dht1.begin();
//   dht2.begin();
// }

// void loop() {
//   float h1 = dht1.readHumidity();
//   float t1 = dht1.readTemperature();
//   float h2 = dht2.readHumidity();
//   float t2 = dht2.readTemperature();

//   if (isnan(h1) || isnan(t1)) {
//     Serial.println("DHT1 failed!");
//   } else {
//     Serial.print("DHT1 -> Temp: "); Serial.print(t1);
//     Serial.print("°C  Hum: "); Serial.println(h1);
//   }

//   if (isnan(h2) || isnan(t2)) {
//     Serial.println("DHT2 failed!");
//   } else {
//     Serial.print("DHT2 -> Temp: "); Serial.print(t2);
//     Serial.print("°C  Hum: "); Serial.println(h2);
//   }

//   Serial.println("----------------------");
//   delay(2000);
// }



//code of oled check new oled is work on SH110X
// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SH110X.h>

// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_RESET    -1
// #define SCREEN_ADDRESS 0x3C

// Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// void setup() {
//   Serial.begin(115200);
//   Wire.begin(21, 22);

//   if(!display.begin(SCREEN_ADDRESS, true)) {
//     Serial.println(F("SH1106 allocation failed"));
//     for(;;);
//   }

//   display.clearDisplay();
//   display.setTextSize(2);
//   display.setTextColor(SH110X_WHITE);
//   display.setCursor(0, 10);
//   display.println("Hello");
//   display.setCursor(0, 35);
//   display.println("SH1106!");
//   display.display();
// }

// void loop() {}



// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SH110X.h>
// #include <DHT.h>

// // ---------------- OLED ----------------
// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_RESET -1
// Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// // ---------------- DHT ----------------
// #define DHTPIN1 32   // First sensor
// #define DHTPIN2 33   // Second sensor
// #define DHTTYPE DHT22

// DHT dht1(DHTPIN1, DHTTYPE);
// DHT dht2(DHTPIN2, DHTTYPE);

// // ---------------- Relay ----------------
// #define RELAY_PIN 26   // Fan relay
// float TEMP_THRESHOLD = 30.0;   // °C
// float HUM_THRESHOLD  = 75.0;   // %

// bool relayState = false;

// void setup() {
//   Serial.begin(115200);

//   // OLED
//   if (!display.begin(0x3C, true)) {
//     Serial.println(F("SH1106 not found..."));
//     for (;;);
//   }
//   display.clearDisplay();
//   display.setTextColor(SH110X_WHITE);

//   // DHT
//   dht1.begin();
//   dht2.begin();

//   // Relay
//   pinMode(RELAY_PIN, OUTPUT);
//   digitalWrite(RELAY_PIN, HIGH); // relay OFF initially
// }

// void loop() {
//   // -------- Read sensors --------
//   float t1 = dht1.readTemperature();
//   float h1 = dht1.readHumidity();
//   float t2 = dht2.readTemperature();
//   float h2 = dht2.readHumidity();

//   if (isnan(t1) || isnan(h1) || isnan(t2) || isnan(h2)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   // -------- Control relay --------
//   if (t1 > TEMP_THRESHOLD || h1 > HUM_THRESHOLD) {
//     digitalWrite(RELAY_PIN, LOW);  // ON
//     relayState = true;
//   } else {
//     digitalWrite(RELAY_PIN, HIGH); // OFF
//     relayState = false;
//   }

//   // -------- Serial Debug --------
//   Serial.println("----------------------");
//   Serial.printf("DHT1 -> Temp: %.2f °C  Hum: %.2f %%\n", t1, h1);
//   Serial.printf("DHT2 -> Temp: %.2f °C  Hum: %.2f %%\n", t2, h2);
//   Serial.printf("Relay State: %s\n", relayState ? "ON" : "OFF");

//   // -------- OLED UI --------
//   display.clearDisplay();

//   display.setTextSize(1);
//   display.setCursor(0, 0);
//   display.print("DHT1: ");
//   display.setTextSize(2);
//   display.setCursor(0, 10);
//   display.printf("%.1fC", t1);
//   display.setCursor(64, 10);
//   display.printf("%.0f%%", h1);

//   display.setTextSize(1);
//   display.setCursor(0, 34);
//   display.print("DHT2: ");
//   display.setTextSize(2);
//   display.setCursor(0, 44);
//   display.printf("%.1fC", t2);
//   display.setCursor(64, 44);
//   display.printf("%.0f%%", h2);

//   // Relay Status
//   display.setTextSize(1);
//   display.setCursor(100, 0);
//   display.print(relayState ? "FAN ON" : "FAN OFF");

//   display.display();

//   delay(2000);
// }


// // Active working code properly

// #include <Wire.h>
// #include <Adafruit_GFX.h>
// #include <Adafruit_SH110X.h>
// #include <DHT.h>

// // ---------------- OLED ----------------
// #define SCREEN_WIDTH 128
// #define SCREEN_HEIGHT 64
// #define OLED_RESET -1
// Adafruit_SH1106G display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

// // ---------------- DHT ----------------
// #define DHTPIN1 32   // First sensor
// #define DHTPIN2 33   // Second sensor
// #define DHTTYPE DHT22

// DHT dht1(DHTPIN1, DHTTYPE);
// DHT dht2(DHTPIN2, DHTTYPE);

// // ---------------- Relay ----------------
// #define RELAY_PIN 26   // Fan relay
// float TEMP_THRESHOLD = 30.0;   // °C
// float HUM_THRESHOLD  = 80.0;   // %
// bool relayState = false;

// void setup() {
//   Serial.begin(115200);

//   // OLED
//   if (!display.begin(0x3C, true)) {
//     Serial.println(F("SH1106 not found..."));
//     for (;;);
//   }
//   display.clearDisplay();
//   display.setTextColor(SH110X_WHITE);

//   // DHT
//   dht1.begin();
//   dht2.begin();

//   // Relay
//   pinMode(RELAY_PIN, OUTPUT);
//   digitalWrite(RELAY_PIN, HIGH); // relay OFF initially
// }

// void loop() {
//   // -------- Read sensors --------
//   float t1 = dht1.readTemperature();
//   float h1 = dht1.readHumidity();
//   float t2 = dht2.readTemperature();
//   float h2 = dht2.readHumidity();

//   if (isnan(t1) || isnan(h1) || isnan(t2) || isnan(h2)) {
//     Serial.println("Failed to read from DHT sensor!");
//     return;
//   }

//   // -------- Control relay --------
//   if (t1 > TEMP_THRESHOLD || h1 > HUM_THRESHOLD) {
//     digitalWrite(RELAY_PIN, LOW);  // ON
//     relayState = true;
//   } else {
//     digitalWrite(RELAY_PIN, HIGH); // OFF
//     relayState = false;
//   }

//   // -------- Serial Debug --------
//   Serial.println("----------------------");
//   Serial.printf("DHT1 -> Temp: %.2f °C  Hum: %.2f %%\n", t1, h1);
//   Serial.printf("DHT2 -> Temp: %.2f °C  Hum: %.2f %%\n", t2, h2);
//   Serial.printf("Relay State: %s\n", relayState ? "ON" : "OFF");

//   // -------- OLED UI --------
//   display.clearDisplay();

//   // Sensor 1
//   display.setTextSize(1);
//   display.setCursor(0, 0);
//   display.print("DHT1");

//   display.setTextSize(2);
//   display.setCursor(30, 0);
//   display.printf("%.1fC", t1);

//   display.setTextSize(2);
//   display.setCursor(90, 0);
//   display.printf("%.0f%%", h1);

//   // Divider line
//   display.drawLine(0, 22, 128, 22, SH110X_WHITE);

//   // Sensor 2
//   display.setTextSize(1);
//   display.setCursor(0, 26);
//   display.print("DHT2");

//   display.setTextSize(2);
//   display.setCursor(30, 26);
//   display.printf("%.1fC", t2);

//   display.setTextSize(2);
//   display.setCursor(90, 26);
//   display.printf("%.0f%%", h2);

//   // Fan Status (big bottom text)
//   display.setTextSize(2);
//   display.setCursor(10, 52);
//   if (relayState) {
//     display.print("FAN: ON");
//   } else {
//     display.print("FAN: OFF");
//   }

//   display.display();

//   delay(2000);
// }




// // Smart Dome — 2x DHT22, 3x Relay control (humidifier + 2 fans), SH1106 (U8g2)
// // Pins used (as you set):
// // DHT1 -> GPIO23
// // DHT2 -> GPIO25
// // Relay1 (fan inside) -> GPIO18
// // Relay2 (humidifier) -> GPIO19
// // Relay3 (fan exhaust) -> GPIO32
// // I2C OLED -> SDA:21, SCL:22

// #include <Wire.h>
// #include <U8g2lib.h>
// #include <DHT.h>

// // -------- CONFIG ----------
// #define DHTTYPE DHT22

// #define DHT1_PIN    23
// #define DHT2_PIN    25

// #define RELAY_FAN_IN_PIN   18   // 1n1 -> 18 (fan inside)
// #define RELAY_HUM_PIN      19   // 1n2 -> 19 (humidifier)
// #define RELAY_FAN_EX_PIN   32   // 1n3 -> 32 (exhaust fan)

// #define HUMID_TARGET 80.0    // target RH %
// #define HUMID_MARGIN 2.0     // hysteresis margin (turn OFF at target+margin)

// #define TEMP_HIGH 30.0       // temp high threshold to turn fans ON
// #define TEMP_LOW  28.0       // temp low threshold to turn fans OFF

// // Set true if your relay module is active LOW (typical hobby modules)
// const bool RELAY_ACTIVE_LOW = true;

// // -------- Objects ----------
// DHT dht1(DHT1_PIN, DHTTYPE);
// DHT dht2(DHT2_PIN, DHTTYPE);

// // U8g2 constructor for SH1106 I2C (hardware I2C, no reset pin)
// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// // State trackers
// bool humidifierOn = false;
// bool fanInOn = false;
// bool fanExOn = false;

// void relayWrite(int pin, bool on) {
//   if (RELAY_ACTIVE_LOW) digitalWrite(pin, on ? LOW : HIGH);
//   else digitalWrite(pin, on ? HIGH : LOW);
// }

// void setup() {
//   Serial.begin(115200);

//   // init DHTs
//   dht1.begin();
//   dht2.begin();

//   // init relays
//   pinMode(RELAY_FAN_IN_PIN, OUTPUT);
//   pinMode(RELAY_HUM_PIN, OUTPUT);
//   pinMode(RELAY_FAN_EX_PIN, OUTPUT);

//   // default OFF
//   relayWrite(RELAY_FAN_IN_PIN, false);
//   relayWrite(RELAY_HUM_PIN, false);
//   relayWrite(RELAY_FAN_EX_PIN, false);

//   // init display
//   u8g2.begin();
//   u8g2.setFont(u8g2_font_ncenB08_tr); // readable font
//   u8g2.clearBuffer();
//   u8g2.drawStr(0, 12, "Smart Dome Starting");
//   u8g2.sendBuffer();
//   delay(1200);
// }

// void loop() {
//   // Read sensors (DHT22: allow 2s between reads)
//   float h1 = dht1.readHumidity();
//   float t1 = dht1.readTemperature();
//   float h2 = dht2.readHumidity();
//   float t2 = dht2.readTemperature();

//   // If reading failed, skip loop iteration (or handle as you prefer)
//   if (isnan(h1) || isnan(t1) || isnan(h2) || isnan(t2)) {
//     Serial.println("DHT read fail");
//     delay(2000);
//     return;
//   }

//   // Averages
//   float humAvg = (h1 + h2) / 2.0;
//   float tempAvg = (t1 + t2) / 2.0;

//   // HUMIDIFIER control (maintain HUMID_TARGET with hysteresis)
//   if (!humidifierOn && humAvg < HUMID_TARGET) {
//     humidifierOn = true;
//     relayWrite(RELAY_HUM_PIN, true);
//     Serial.println("Humidifier ON");
//   } else if (humidifierOn && humAvg > (HUMID_TARGET + HUMID_MARGIN)) {
//     humidifierOn = false;
//     relayWrite(RELAY_HUM_PIN, false);
//     Serial.println("Humidifier OFF");
//   }

//   // FAN control (based on temperature) — both fans follow temp hysteresis
//   if (!fanInOn && tempAvg > TEMP_HIGH) {
//     fanInOn = true;
//     relayWrite(RELAY_FAN_IN_PIN, true);
//   } else if (fanInOn && tempAvg < TEMP_LOW) {
//     fanInOn = false;
//     relayWrite(RELAY_FAN_IN_PIN, false);
//   }

//   if (!fanExOn && tempAvg > TEMP_HIGH) {
//     fanExOn = true;
//     relayWrite(RELAY_FAN_EX_PIN, true);
//   } else if (fanExOn && tempAvg < TEMP_LOW) {
//     fanExOn = false;
//     relayWrite(RELAY_FAN_EX_PIN, false);
//   }

//   // Update display (real-time)
//   char buf[64];
//   u8g2.clearBuffer();

//   // Line 1: DHT1
//   snprintf(buf, sizeof(buf), "D1 T:%.1fC H:%.1f%%", t1, h1);
//   u8g2.drawStr(0, 12, buf);

//   // Line 2: DHT2
//   snprintf(buf, sizeof(buf), "D2 T:%.1fC H:%.1f%%", t2, h2);
//   u8g2.drawStr(0, 26, buf);

//   // Line 3: Avg humidity & temp
//   snprintf(buf, sizeof(buf), "Avg H:%.1f%%  T:%.1fC", humAvg, tempAvg);
//   u8g2.drawStr(0, 40, buf);

//   // Line 4: statuses
//   snprintf(buf, sizeof(buf), "Hum:%s  F1:%s  F2:%s",
//            humidifierOn ? "ON " : "OFF",
//            fanInOn ? "ON " : "OFF",
//            fanExOn ? "ON " : "OFF");
//   u8g2.drawStr(0, 56, buf);

//   u8g2.sendBuffer();

//   // Debug serial
//   Serial.printf("D1 T:%.1f H:%.1f | D2 T:%.1f H:%.1f | AvgH:%.1f AvgT:%.1f\n",
//                 t1, h1, t2, h2, humAvg, tempAvg);
//   Serial.printf("States - Hum:%d Fan1:%d Fan2:%d\n", humidifierOn, fanInOn, fanExOn);

//   delay(2000); // DHT22 minimum interval
// }










// // Improved Smart Dome sketch - robust DHT handling
// #include <Wire.h>
// #include <U8g2lib.h>
// #include <DHT.h>

// #define DHTTYPE DHT22
// #define DHT1_PIN 23
// #define DHT2_PIN 25

// #define RELAY_FAN_IN_PIN 18
// #define RELAY_HUM_PIN    19
// #define RELAY_FAN_EX_PIN 32

// const bool RELAY_ACTIVE_LOW = true;
// const float HUMID_TARGET = 80.0;
// const float HUMID_MARGIN = 2.0;
// const float TEMP_HIGH = 30.0;
// const float TEMP_LOW  = 28.0;

// DHT dht1(DHT1_PIN, DHTTYPE);
// DHT dht2(DHT2_PIN, DHTTYPE);
// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// bool humidifierOn = false, fanInOn = false, fanExOn = false;

// void relayWrite(int pin, bool on) {
//   if (RELAY_ACTIVE_LOW) digitalWrite(pin, on ? LOW : HIGH);
//   else digitalWrite(pin, on ? HIGH : LOW);
// }

// // Read a DHT with retries. Returns true if valid read, false otherwise.
// // On success, fills tempC and hum (percent).
// bool readDHTWithRetries(DHT &sensor, float &tempC, float &hum, int tries=3) {
//   for (int attempt=0; attempt<tries; ++attempt) {
//     hum = sensor.readHumidity();
//     tempC = sensor.readTemperature();
//     // treat NaN or zeros as invalid
//     if (!isnan(hum) && !isnan(tempC) && !(hum == 0.0 && tempC == 0.0) ) {
//       // Optionally also require humidity to be in reasonable range 0.5..100
//       if (hum >= 0.5 && hum <= 100.0 && tempC > -40 && tempC < 80) return true;
//     }
//     // Wait before next attempt - DHT22 requires spacing; 1000ms is safe
//     delay(1000);
//   }
//   return false;
// }

// void setup() {
//   Serial.begin(115200);
//   dht1.begin();
//   dht2.begin();
//   pinMode(RELAY_FAN_IN_PIN, OUTPUT);
//   pinMode(RELAY_HUM_PIN, OUTPUT);
//   pinMode(RELAY_FAN_EX_PIN, OUTPUT);
//   relayWrite(RELAY_FAN_IN_PIN, false);
//   relayWrite(RELAY_HUM_PIN, false);
//   relayWrite(RELAY_FAN_EX_PIN, false);

//   u8g2.begin();
//   u8g2.setFont(u8g2_font_ncenB08_tr);
//   u8g2.clearBuffer();
//   u8g2.drawStr(0,12,"Smart Dome Boot");
//   u8g2.sendBuffer();
//   delay(1000);
// }

// void loop() {
//   float t1, h1, t2, h2;
//   bool ok1 = readDHTWithRetries(dht1, t1, h1, 3);
//   bool ok2 = readDHTWithRetries(dht2, t2, h2, 3);

//   // Debug: which sensors valid
//   Serial.printf("D1 ok:%d  D2 ok:%d\n", ok1?1:0, ok2?1:0);

//   // Compute average only from valid sensors
//   float humAvg = NAN;
//   float tempAvg = NAN;
//   int validCount = 0;
//   if (ok1) { humAvg = h1; tempAvg = t1; validCount = 1; }
//   if (ok2) {
//     if (validCount == 0) { humAvg = h2; tempAvg = t2; validCount = 1; }
//     else { humAvg = (humAvg + h2) / 2.0; tempAvg = (tempAvg + t2) / 2.0; validCount = 2; }
//   }

//   // Display readings & status
//   char buf[64];
//   u8g2.clearBuffer();
//   if (ok1) {
//     snprintf(buf, sizeof(buf), "D1 T:%.1fC H:%.1f%%", t1, h1);
//   } else {
//     snprintf(buf, sizeof(buf), "D1: ERR");
//   }
//   u8g2.drawStr(0,12,buf);

//   if (ok2) {
//     snprintf(buf, sizeof(buf), "D2 T:%.1fC H:%.1f%%", t2, h2);
//   } else {
//     snprintf(buf, sizeof(buf), "D2: ERR");
//   }
//   u8g2.drawStr(0,26,buf);

//   if (validCount>0) {
//     snprintf(buf, sizeof(buf), "Avg H:%.1f%%  T:%.1fC", humAvg, tempAvg);
//   } else {
//     snprintf(buf, sizeof(buf), "Avg H: --  T: --");
//   }
//   u8g2.drawStr(0,40,buf);

//   snprintf(buf, sizeof(buf), "Hum:%s F1:%s F2:%s",
//            humidifierOn?"ON":"OFF",
//            fanInOn?"ON":"OFF",
//            fanExOn?"ON":"OFF");
//   u8g2.drawStr(0,56,buf);
//   u8g2.sendBuffer();

//   // Control logic only if we have a valid humidity reading
//   if (validCount > 0) {
//     if (!humidifierOn && humAvg < HUMID_TARGET) {
//       humidifierOn = true;
//       relayWrite(RELAY_HUM_PIN, true);
//       Serial.println("Humidifier ON");
//     } else if (humidifierOn && humAvg > (HUMID_TARGET + HUMID_MARGIN)) {
//       humidifierOn = false;
//       relayWrite(RELAY_HUM_PIN, false);
//       Serial.println("Humidifier OFF");
//     }

//     // Fans based on tempAvg
//     if (tempAvg>=-40 && tempAvg<100) {
//       if (!fanInOn && tempAvg > TEMP_HIGH) {
//         fanInOn = true;
//         relayWrite(RELAY_FAN_IN_PIN, true);
//       } else if (fanInOn && tempAvg < TEMP_LOW) {
//         fanInOn = false;
//         relayWrite(RELAY_FAN_IN_PIN, false);
//       }

//       if (!fanExOn && tempAvg > TEMP_HIGH) {
//         fanExOn = true;
//         relayWrite(RELAY_FAN_EX_PIN, true);
//       } else if (fanExOn && tempAvg < TEMP_LOW) {
//         fanExOn = false;
//         relayWrite(RELAY_FAN_EX_PIN, false);
//       }
//     }
//   } else {
//     // No valid humidity — do not toggle humidifier automatically (safety)
//     Serial.println("No valid humidity readings — skipping control");
//   }

//   // Serial debug summary
//   Serial.printf("D1: T=%.1f H=%.1f ok=%d | D2: T=%.1f H=%.1f ok=%d | AvgH:%.1f\n",
//                 ok1? t1:0.0, ok1? h1:0.0, ok1?1:0,
//                 ok2? t2:0.0, ok2? h2:0.0, ok2?1:0,
//                 validCount>0?humAvg:0.0);
//   delay(2000);
// }













// // Smart Dome final sketch
// // DHT1 -> GPIO23
// // DHT2 -> GPIO25
// // Relay Fan-In -> GPIO18
// // Relay Humid -> GPIO19
// // Relay Fan-Ex -> GPIO32
// // OLED (SH1106) -> I2C SDA=21, SCL=22 (address 0x3C)
// // Libraries: Adafruit DHT, U8g2

// #include <Wire.h>
// #include <U8g2lib.h>
// #include <DHT.h>

// #define DHTTYPE DHT22
// #define DHT1_PIN 23
// #define DHT2_PIN 25

// #define RELAY_FAN_IN_PIN   18
// #define RELAY_HUM_PIN      19
// #define RELAY_FAN_EX_PIN   32

// // Control targets
// const float HUMID_TARGET = 80.0;   // desired humidity %
// const float HUMID_MARGIN = 2.0;    // hysteresis margin
// const float TEMP_HIGH = 30.0;      // fans ON threshold (°C)
// const float TEMP_LOW  = 28.0;      // fans OFF threshold (°C)

// // Set to true if relay IN is active LOW (typical hobby modules)
// const bool RELAY_ACTIVE_LOW = true;

// // DHT objects
// DHT dht1(DHT1_PIN, DHTTYPE);
// DHT dht2(DHT2_PIN, DHTTYPE);

// // U8g2 constructor for SH1106 I2C (hardware I2C)
// U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// // state trackers
// bool humidifierOn = false;
// bool fanInOn = false;
// bool fanExOn = false;

// void relayWrite(uint8_t pin, bool on) {
//   if (RELAY_ACTIVE_LOW) digitalWrite(pin, on ? LOW : HIGH);
//   else digitalWrite(pin, on ? HIGH : LOW);
// }

// // read with retries; returns true if valid
// bool readDHTWithRetries(DHT &sensor, float &tempC, float &hum, int tries = 3, int delayMs = 1000) {
//   for (int i = 0; i < tries; ++i) {
//     hum = sensor.readHumidity();
//     tempC = sensor.readTemperature();
//     if (!isnan(hum) && !isnan(tempC)) {
//       // basic sanity check (humidity 0.5..100, temp reasonable)
//       if (hum >= 0.5 && hum <= 100.0 && tempC > -40 && tempC < 80) return true;
//     }
//     delay(delayMs);
//   }
//   return false;
// }

// void setup() {
//   Serial.begin(115200);
//   dht1.begin();
//   dht2.begin();

//   pinMode(RELAY_FAN_IN_PIN, OUTPUT);
//   pinMode(RELAY_HUM_PIN, OUTPUT);
//   pinMode(RELAY_FAN_EX_PIN, OUTPUT);

//   // default OFF
//   relayWrite(RELAY_FAN_IN_PIN, false);
//   relayWrite(RELAY_HUM_PIN, false);
//   relayWrite(RELAY_FAN_EX_PIN, false);

//   // init display
//   u8g2.begin();
//   u8g2.setFont(u8g2_font_ncenB08_tr);
//   u8g2.clearBuffer();
//   u8g2.drawStr(0, 12, "Smart Dome Ready");
//   u8g2.sendBuffer();
//   delay(800);
// }

// void loop() {
//   float t1=0, h1=0, t2=0, h2=0;
//   bool ok1 = readDHTWithRetries(dht1, t1, h1, 3, 1000);
//   bool ok2 = readDHTWithRetries(dht2, t2, h2, 3, 1000);

//   // compute averages only using valid sensors
//   int vcount = 0;
//   float humSum = 0, tempSum = 0;
//   if (ok1) { humSum += h1; tempSum += t1; vcount++; }
//   if (ok2) { humSum += h2; tempSum += t2; vcount++; }
//   float humAvg = NAN, tempAvg = NAN;
//   if (vcount > 0) {
//     humAvg = humSum / vcount;
//     tempAvg = tempSum / vcount;
//   }

//   // control humidifier (only when we have a valid humidity reading)
//   if (vcount > 0) {
//     if (!humidifierOn && humAvg < HUMID_TARGET) {
//       humidifierOn = true;
//       relayWrite(RELAY_HUM_PIN, true);
//       Serial.println("Humidifier ON");
//     } else if (humidifierOn && humAvg > (HUMID_TARGET + HUMID_MARGIN)) {
//       humidifierOn = false;
//       relayWrite(RELAY_HUM_PIN, false);
//       Serial.println("Humidifier OFF");
//     }

//     // fan control: both fans follow tempAvg hysteresis
//     if (!fanInOn && tempAvg > TEMP_HIGH) { fanInOn = true; relayWrite(RELAY_FAN_IN_PIN, true); }
//     else if (fanInOn && tempAvg < TEMP_LOW) { fanInOn = false; relayWrite(RELAY_FAN_IN_PIN, false); }

//     if (!fanExOn && tempAvg > TEMP_HIGH) { fanExOn = true; relayWrite(RELAY_FAN_EX_PIN, true); }
//     else if (fanExOn && tempAvg < TEMP_LOW) { fanExOn = false; relayWrite(RELAY_FAN_EX_PIN, false); }
//   } else {
//     // no valid humidity -> keep actuators as-is and do not toggle humidifier for safety
//     Serial.println("No valid humidity reading - skipping humidifier control");
//   }

//   // Update OLED
//   char line[64];
//   u8g2.clearBuffer();

//   if (ok1) {
//     snprintf(line, sizeof(line), "D1 T:%.1fC H:%.1f%%", t1, h1);
//   } else {
//     snprintf(line, sizeof(line), "D1: ERR");
//   }
//   u8g2.drawStr(0, 12, line);

//   if (ok2) {
//     snprintf(line, sizeof(line), "D2 T:%.1fC H:%.1f%%", t2, h2);
//   } else {
//     snprintf(line, sizeof(line), "D2: ERR");
//   }
//   u8g2.drawStr(0, 26, line);

//   if (vcount>0) {
//     snprintf(line, sizeof(line), "Avg H:%.1f%%  T:%.1fC", humAvg, tempAvg);
//   } else {
//     snprintf(line, sizeof(line), "Avg H: --   T: --");
//   }
//   u8g2.drawStr(0, 40, line);

//   snprintf(line, sizeof(line), "Hum:%s F1:%s F2:%s",
//            humidifierOn ? "ON " : "OFF",
//            fanInOn ? "ON " : "OFF",
//            fanExOn ? "ON " : "OFF");
//   u8g2.drawStr(0, 56, line);

//   u8g2.sendBuffer();

//   // Serial debug
//   Serial.printf("OK1:%d OK2:%d  D1 T:%.1f H:%.1f  D2 T:%.1f H:%.1f  AvgH:%.1f\n",
//                 ok1?1:0, ok2?1:0, ok1?t1:0.0, ok1?h1:0.0, ok2?t2:0.0, ok2?h2:0.0, vcount?humAvg:0.0);

//   delay(2000); // DHT22 sampling interval
// }































#include <Wire.h>
#include <U8g2lib.h>
#include <DHT.h>

// ——— CONFIGURATION ——-
#define DHTTYPE DHT22
#define DHT1_PIN    23
#define DHT2_PIN    25

// Relay pins (adjust to which relays you wired to 1n4 etc)
#define RELAY_HUM_PIN     19    // humidifier relay
#define RELAY_EXHAUST_PIN 18    // exhaust fan relay
#define RELAY_INTAKE_PIN  32    // intake fan relay (1n4 replaced)

const bool RELAY_ACTIVE_LOW = true;  // typical hobby relays

// Humidity thresholds
const float HUMIDIFIER_ON_THRESHOLD = 72.0;
const float HUMIDIFIER_OFF_THRESHOLD = 80.0;

const float EXHAUST_ON_THRESHOLD = 87.0;
const float EXHAUST_OFF_THRESHOLD = 79.0;

// Intake fan timing
const unsigned long INTAKE_INTERVAL = 2UL * 60UL * 60UL * 1000UL;  // every 2 hours in milliseconds
const unsigned long INTAKE_RUN_DURATION = 30UL * 1000UL;           // run 30 seconds

// Display
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE);

// DHT sensors
DHT dht1(DHT1_PIN, DHTTYPE);
DHT dht2(DHT2_PIN, DHTTYPE);

// State flags
bool humidifierOn = false;
bool exhaustOn = false;
bool intakeOn = false;

// Timing
unsigned long lastIntakeMillis = 0;
unsigned long intakeStartMillis = 0;

void relayWrite(uint8_t pin, bool on) {
  if (RELAY_ACTIVE_LOW) {
    digitalWrite(pin, on ? LOW : HIGH);
  } else {
    digitalWrite(pin, on ? HIGH : LOW);
  }
}

// Read DHT with simple retry
bool readDHT(DHT &sensor, float &humidity, float &temp) {
  humidity = sensor.readHumidity();
  temp = sensor.readTemperature();
  if (isnan(humidity) || isnan(temp)) {
    return false;
  }
  return true;
}

void setup() {
  Serial.begin(115200);
  dht1.begin();
  dht2.begin();

  pinMode(RELAY_HUM_PIN, OUTPUT);
  pinMode(RELAY_EXHAUST_PIN, OUTPUT);
  pinMode(RELAY_INTAKE_PIN, OUTPUT);

  // Turn all relays off initially
  relayWrite(RELAY_HUM_PIN, false);
  relayWrite(RELAY_EXHAUST_PIN, false);
  relayWrite(RELAY_INTAKE_PIN, false);

  u8g2.begin();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.clearBuffer();
  u8g2.drawStr(0, 12, "Dome Controller Start");
  u8g2.sendBuffer();

  lastIntakeMillis = millis();
}

void loop() {
  float h1, t1, h2, t2;
  bool ok1 = readDHT(dht1, h1, t1);
  bool ok2 = readDHT(dht2, h2, t2);

  float humAvg = NAN;
  float tempAvg = NAN;
  int validCount = 0;

  if (ok1) {
    humAvg = h1;
    tempAvg = t1;
    validCount = 1;
  }
  if (ok2) {
    if (validCount == 0) {
      humAvg = h2;
      tempAvg = t2;
      validCount = 1;
    } else {
      humAvg = (humAvg + h2) / 2.0;
      tempAvg = (tempAvg + t2) / 2.0;
      validCount = 2;
    }
  }

  unsigned long now = millis();

  // ------- Intake Fan logic (time-based) -------
  if (!intakeOn && (now - lastIntakeMillis >= INTAKE_INTERVAL)) {
    // start a new intake cycle
    intakeOn = true;
    intakeStartMillis = now;
    lastIntakeMillis = now;
    Serial.println("Intake ON start");
    relayWrite(RELAY_INTAKE_PIN, true);
    // Optionally also turn on exhaust while intake is on:
    exhaustOn = true;
    relayWrite(RELAY_EXHAUST_PIN, true);
  }
  if (intakeOn && (now - intakeStartMillis >= INTAKE_RUN_DURATION)) {
    // stop intake cycle
    intakeOn = false;
    relayWrite(RELAY_INTAKE_PIN, false);
    Serial.println("Intake OFF");
    // Exhaust returns to humidity-based logic below
  }

  // ------- Humidifier control (only if valid humidity) -------
  if (validCount > 0) {
    if (!humidifierOn && (humAvg < HUMIDIFIER_ON_THRESHOLD)) {
      humidifierOn = true;
      relayWrite(RELAY_HUM_PIN, true);
      Serial.println("Humidifier turned ON");
    } else if (humidifierOn && (humAvg >= HUMIDIFIER_OFF_THRESHOLD)) {
      humidifierOn = false;
      relayWrite(RELAY_HUM_PIN, false);
      Serial.println("Humidifier OFF");
    }
  }

  // ------- Exhaust Fan control (based on humidity, unless intake override) -------
  if (!intakeOn) {
    // only enforce humidity control when intake is NOT currently forcing exhaust
    if (!exhaustOn && (validCount > 0) && (humAvg > EXHAUST_ON_THRESHOLD)) {
      exhaustOn = true;
      relayWrite(RELAY_EXHAUST_PIN, true);
      Serial.println("Exhaust turned ON (humid)");
    } else if (exhaustOn && (validCount > 0) && (humAvg <= EXHAUST_OFF_THRESHOLD)) {
      exhaustOn = false;
      relayWrite(RELAY_EXHAUST_PIN, false);
      Serial.println("Exhaust OFF (humid)");
    }
  }

  // ------- Display logic -------
  u8g2.clearBuffer();
  char buf[64];
  if (ok1) {
    snprintf(buf, sizeof(buf), "D1: T:%.1fC H:%.1f%%", t1, h1);
  } else {
    snprintf(buf, sizeof(buf), "D1: ERR");
  }
  u8g2.drawStr(0, 12, buf);

  if (ok2) {
    snprintf(buf, sizeof(buf), "D2: T:%.1fC H:%.1f%%", t2, h2);
  } else {
    snprintf(buf, sizeof(buf), "D2: ERR");
  }
  u8g2.drawStr(0, 26, buf);

  if (validCount > 0) {
    snprintf(buf, sizeof(buf), "Avg H:%.1f%% T:%.1fC", humAvg, tempAvg);
  } else {
    snprintf(buf, sizeof(buf), "Avg H: -- T: --");
  }
  u8g2.drawStr(0, 40, buf);

  snprintf(buf, sizeof(buf), "Hum:%s Ex:%s In:%s",
           humidifierOn ? "ON " : "OFF",
           exhaustOn ? "ON " : "OFF",
           intakeOn ? "ON " : "OFF");
  u8g2.drawStr(0, 56, buf);

  u8g2.sendBuffer();

  // Debug Serial
  Serial.printf("HumAvg: %.1f  ValidSensors: %d  States Hum:%d Ex:%d In:%d\n",
                validCount > 0 ? humAvg : 0.0,
                validCount,
                humidifierOn ? 1 : 0,
                exhaustOn ? 1 : 0,
                intakeOn ? 1 : 0);

  delay(2000);
}














