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







// code with history log
// Smart Dome — UNO R4 (with runtime counters & history display)
// Shows two pages:
//   Page 1: Live status (as before)
//   Page 2: Status History (how many times each relay turned ON)
//
// DHT-IN  -> D2  (inside)
// DHT-OUT -> D3  (outside)
// Fan-In  -> D4  (intake, periodic)
// Humid   -> D5  (humidifier)
// Fan-Ex  -> D6  (exhaust)
// OLED SH1106 0x3C -> SDA/SCL
// Relays active LOW

#include <Wire.h>
#include <U8g2lib.h>
#include <DHT.h>

#define DHTTYPE DHT22

// ---- Pins ----
#define PIN_DHT_IN   2
#define PIN_DHT_OUT  3
int PIN_FAN_IN  = 4;   // intake (periodic)
int PIN_HUM     = 5;   // humidifier
int PIN_FAN_EX  = 6;   // exhaust
// ---------------

// Relay polarity
bool FAN_IN_ACTIVE_LOW = true;
bool HUM_ACTIVE_LOW    = true;
bool FAN_EX_ACTIVE_LOW = true;

// ---------- Thresholds & timings ----------
const float HUMID_EXHAUST_ON      = 87.0; // exhaust ON when > 87%
const float HUMID_EXHAUST_OFF     = 79.0; // exhaust OFF when <= 79%
const float HUMID_HUMID_ON        = 72.0; // humidifier ON when < 72%
const float HUMID_HUMID_OFF       = 80.0; // humidifier OFF when >= 80%
const uint8_t EXHAUST_OFF_CONFIRM_SAMPLES = 2;
const uint8_t HUMID_OFF_CONFIRM_SAMPLES   = 2;
const unsigned long INTAKE_INTERVAL_MS = 2UL * 3600UL * 1000UL; // 2 hours
const unsigned long INTAKE_DURATION_MS = 30UL * 1000UL;         // 30 seconds
const unsigned long DISPLAY_TOGGLE_INTERVAL_MS = 10000UL;       // 10 seconds toggle OLED pages
// -----------------------------------------

DHT dhtIn(PIN_DHT_IN, DHTTYPE);
DHT dhtOut(PIN_DHT_OUT, DHTTYPE);

// SH1106 Full-buffer OLED (matches your visible working setup)
U8G2_SH1106_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, /* reset=*/ U8X8_PIN_NONE);

// State trackers
bool exhaustOn = false;
bool humidOn   = false;
bool intakeOn  = false;

uint8_t exhaustOffConfirmCount = 0;
uint8_t humidOffConfirmCount   = 0;

// Counters (how many times each device turned ON)
unsigned long humidOnCount = 0;
unsigned long exhaustOnCount = 0;
unsigned long intakeOnCount = 0;

unsigned long nextIntakeAt = 0;
unsigned long intakeStartedAt = 0;
unsigned long lastDisplayToggle = 0;
bool showHistoryPage = false;

void rwrite(int pin, bool activeLow, bool on){
  if (activeLow) digitalWrite(pin, on ? LOW : HIGH);
  else           digitalWrite(pin, on ? HIGH : LOW);
}

bool readDHTStable(DHT &s, float &t, float &h, int tries=3, int dly=800){
  for (int i=0; i<tries; ++i) {
    h = s.readHumidity();
    t = s.readTemperature();
    if (!isnan(h) && !isnan(t) && h >= 0.5 && h <= 100.0 && t > -40 && t < 80) return true;
    delay(dly);
  }
  return false;
}

void drawLivePage(bool okIn,float Tin,float Hin,bool okOut,float Tout,float Hout){
  char line[64];
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);

  if (okIn)  snprintf(line,sizeof(line),"In  T:%.1fC H:%.1f%%", Tin, Hin);
  else       snprintf(line,sizeof(line),"In  SENSOR ERR");
  u8g2.drawStr(0, 12, line);

  if (okOut) snprintf(line,sizeof(line),"Out T:%.1fC H:%.1f%%", Tout, Hout);
  else       snprintf(line,sizeof(line),"Out SENSOR ERR");
  u8g2.drawStr(0, 26, line);

  snprintf(line,sizeof(line),"Exh>%.0f Off<=%.0f Hum<%.0f Off>=%.0f",
           HUMID_EXHAUST_ON, HUMID_EXHAUST_OFF,
           HUMID_HUMID_ON, HUMID_HUMID_OFF);
  u8g2.drawStr(0, 40, line);

  snprintf(line,sizeof(line),"Hum:%s Exh:%s Intk:%s",
           humidOn ? "ON " : "OFF",
           exhaustOn ? "ON " : "OFF",
           intakeOn ? "ON " : "OFF");
  u8g2.drawStr(0, 56, line);

  u8g2.sendBuffer();
}

void drawHistoryPage(){
  char line[64];
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 12, "Status History:");

  snprintf(line,sizeof(line),"Humidifier ON: %lu", humidOnCount);
  u8g2.drawStr(0, 28, line);

  snprintf(line,sizeof(line),"Exhaust ON: %lu", exhaustOnCount);
  u8g2.drawStr(0, 42, line);

  snprintf(line,sizeof(line),"Intake ON: %lu", intakeOnCount);
  u8g2.drawStr(0, 56, line);

  u8g2.sendBuffer();
}

void setup(){
  Serial.begin(115200);
  pinMode(PIN_FAN_IN, OUTPUT);
  pinMode(PIN_HUM,    OUTPUT);
  pinMode(PIN_FAN_EX, OUTPUT);

  rwrite(PIN_FAN_IN, FAN_IN_ACTIVE_LOW, false);
  rwrite(PIN_HUM,    HUM_ACTIVE_LOW,    false);
  rwrite(PIN_FAN_EX, FAN_EX_ACTIVE_LOW, false);

  pinMode(PIN_DHT_IN,  INPUT_PULLUP);
  pinMode(PIN_DHT_OUT, INPUT_PULLUP);
  dhtIn.begin();
  dhtOut.begin();

  u8g2.begin();
  u8g2.clearBuffer();
  u8g2.setFont(u8g2_font_ncenB08_tr);
  u8g2.drawStr(0, 12, "Smart Dome Ready");
  u8g2.sendBuffer();
  delay(800);

  nextIntakeAt = millis() + INTAKE_INTERVAL_MS;
  lastDisplayToggle = millis();
}

void loop(){
  float Tin=0, Hin=0, Tout=0, Hout=0;
  bool okIn  = readDHTStable(dhtIn,  Tin,  Hin);
  bool okOut = readDHTStable(dhtOut, Tout, Hout);
  unsigned long now = millis();

  // ---------- Intake periodic ----------
  if (!intakeOn && now >= nextIntakeAt) {
    intakeOn = true;
    intakeStartedAt = now;
    rwrite(PIN_FAN_IN, FAN_IN_ACTIVE_LOW, true);
    rwrite(PIN_FAN_EX, FAN_EX_ACTIVE_LOW, true);
    intakeOnCount++;
    Serial.println("Periodic Intake START - fans ON");
  }
  if (intakeOn && now - intakeStartedAt >= INTAKE_DURATION_MS) {
    intakeOn = false;
    rwrite(PIN_FAN_IN, FAN_IN_ACTIVE_LOW, false);
    Serial.println("Periodic Intake STOP - intake OFF");
    nextIntakeAt = now + INTAKE_INTERVAL_MS;
  }

  // ---------- Humidifier ----------
  if (okIn) {
    if (!humidOn && Hin < HUMID_HUMID_ON) {
      humidOn = true;
      humidOffConfirmCount = 0;
      humidOnCount++;
      rwrite(PIN_HUM, HUM_ACTIVE_LOW, true);
      Serial.println("Humidifier ON (RH < 72%)");
    } else if (humidOn && Hin >= HUMID_HUMID_OFF) {
      if (++humidOffConfirmCount >= HUMID_OFF_CONFIRM_SAMPLES) {
        humidOn = false;
        humidOffConfirmCount = 0;
        rwrite(PIN_HUM, HUM_ACTIVE_LOW, false);
        Serial.println("Humidifier OFF (RH >= 80%)");
      }
    } else {
      if (Hin < HUMID_HUMID_OFF) humidOffConfirmCount = 0;
    }
  }

  // ---------- Exhaust ----------
  if (!intakeOn && okIn) {
    if (!exhaustOn && Hin > HUMID_EXHAUST_ON) {
      exhaustOn = true;
      exhaustOffConfirmCount = 0;
      exhaustOnCount++;
      rwrite(PIN_FAN_EX, FAN_EX_ACTIVE_LOW, true);
      Serial.println("Exhaust ON (RH > 87%)");
    } else if (exhaustOn && Hin <= HUMID_EXHAUST_OFF) {
      if (++exhaustOffConfirmCount >= EXHAUST_OFF_CONFIRM_SAMPLES) {
        exhaustOn = false;
        exhaustOffConfirmCount = 0;
        rwrite(PIN_FAN_EX, FAN_EX_ACTIVE_LOW, false);
        Serial.println("Exhaust OFF (RH <= 79%)");
      }
    } else {
      if (Hin > HUMID_EXHAUST_OFF) exhaustOffConfirmCount = 0;
    }
  }

  // ---------- OLED display toggle ----------
  if (now - lastDisplayToggle >= DISPLAY_TOGGLE_INTERVAL_MS) {
    showHistoryPage = !showHistoryPage;
    lastDisplayToggle = now;
  }

  if (showHistoryPage) drawHistoryPage();
  else drawLivePage(okIn, Tin, Hin, okOut, Tout, Hout);

  // ---------- Serial Debug ----------
  Serial.print("IN H:"); Serial.print(okIn?Hin:-1,1);
  Serial.print(" T:");    Serial.print(okIn?Tin:-1,1);
  Serial.print(" | OUT H:"); Serial.print(okOut?Hout:-1,1);
  Serial.print(" T:");      Serial.print(okOut?Tout:-1,1);
  Serial.print(" | Hum:");  Serial.print(humidOn?"ON":"OFF");
  Serial.print(" | Exh:");  Serial.print(exhaustOn?"ON":"OFF");
  Serial.print(" | Intk:"); Serial.print(intakeOn?"ON":"OFF");
  Serial.print(" | Counts => Hum:"); Serial.print(humidOnCount);
  Serial.print(" Exh:"); Serial.print(exhaustOnCount);
  Serial.print(" Intk:"); Serial.println(intakeOnCount);

  delay(2000);
}













