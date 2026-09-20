LINK DEL PROGETTO
https://randomnerdtutorials.com/esp32-esp8266-dht-temperature-and-humidity-oled-display/

# DHT Sensor & OLED Display Monitor

Questo progetto legge i dati di temperatura e umidità da un sensore DHT11 o DHT22 e li visualizza in tempo reale su un display OLED I2C da 0.96 pollici (SSD1306). 

## Hardware Necessario
* ESP8266 (es. NodeMCU) o ESP32
* Sensore di temperatura e umidità DHT22 o DHT11
* Display OLED 0.96" I2C SSD1306
* Resistenza da 10k Ohm (necessaria solo se il sensore non è montato su una breakout board con pull-up integrato)
* Breadboard e cavetti

## Cablaggio

**Configurazione per ESP8266:**
* **OLED SDA:** GPIO 4 (D2)
* **OLED SCL:** GPIO 5 (D1)
* **DHT22 Data:** GPIO 14 (D5)

**Configurazione per ESP32:**
* **OLED SDA:** GPIO 21
* **OLED SCL:** GPIO 22
* **DHT22 Data:** GPIO 14

## Librerie Utilizzate
Il progetto si appoggia alle seguenti librerie di Adafruit:
* Adafruit SSD1306
* Adafruit GFX Library
* DHT sensor library
* Adafruit Unified Sensor