#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

#define SCREEN_WIDTH 128 // Larghezza display OLED in pixel
#define SCREEN_HEIGHT 64 // Altezza display OLED in pixel

// Inizializzazione display SSD1306 connesso via I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Pin digitale connesso al sensore DHT
#define DHTPIN 14 

// Decommenta il sensore che stai utilizzando:
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22     // DHT 22 (AM2302)
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  dht.begin();

  // Indirizzo I2C 0x3C per display 128x64
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { 
    Serial.println(F("Allocazione SSD1306 fallita"));
    for(;;);
  }
  
  delay(2000);
  display.clearDisplay();
  display.setTextColor(WHITE);
}

void loop() {
  delay(5000);

  // Lettura temperatura e umidità
  float t = dht.readTemperature();
  float h = dht.readHumidity();

  // Controllo se le letture sono andate a buon fine
  if (isnan(h) || isnan(t)) {
    Serial.println("Impossibile leggere dal sensore DHT!");
  }

  display.clearDisplay();

  // Stampa la temperatura
  display.setTextSize(1);
  display.setCursor(0,0);
  display.print("Temperatura: ");
  display.setTextSize(2);
  display.setCursor(0,10);
  display.print(t);
  display.print(" ");
  display.setTextSize(1);
  display.cp437(true);
  display.write(167); // Simbolo del grado
  display.setTextSize(2);
  display.print("C");

  // Stampa l'umidità
  display.setTextSize(1);
  display.setCursor(0, 35);
  display.print("Umidita': ");
  display.setTextSize(2);
  display.setCursor(0, 45);
  display.print(h);
  display.print(" %"); 

  // Aggiorna fisicamente lo schermo
  display.display(); 
}