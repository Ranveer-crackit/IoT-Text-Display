#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "thingProperties.h"
#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

// OLED display dimensions
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

// Define I2C pins for ESP32
#define OLED_SDA 21
#define OLED_SCL 22

// Create an SSD1306 display object connected to I2C
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// Variable to track the last displayed text
String lastDisplayText = "";

void setup() {
  // Initialize Serial Monitor
  Serial.begin(115200);

  // Initialize I2C communication
  Wire.begin(OLED_SDA, OLED_SCL);

  // Initialize the OLED display
  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    for (;;);
  }
  display.clearDisplay();
  display.setTextSize(2);
  display.setTextColor(SSD1306_WHITE);

  // Initialize Arduino IoT Cloud
  initProperties();
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);

  // Synchronize with Arduino Cloud
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update(); // Maintain connection to Arduino Cloud

  // Update display only if the text has changed
  if (displayText != lastDisplayText) {
    display.clearDisplay();
    display.setCursor(0, 0);
    display.print(displayText);
    display.display();

    lastDisplayText = displayText; // Update the last displayed text
  }
}

// Callback function triggered when displayText changes
void onDisplayTextChange() {
  Serial.print("Received from Cloud: ");
  Serial.println(displayText);
}
