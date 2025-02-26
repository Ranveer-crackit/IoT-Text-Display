# IoT-Enabled Text Display on OLED using Arduino IoT Cloud  

## 📌 Introduction  
This project demonstrates how to display dynamic text on an OLED screen using an IoT-enabled microcontroller (ESP8266/ESP32) and the **Arduino IoT Cloud** platform. The user can send messages remotely via the cloud, and they will appear on the OLED display in real-time.  

## ✨ Features  
- Real-time text display via Arduino IoT Cloud  
- Wireless communication using ESP8266/ESP32  
- Dynamic message updates from a remote interface  
- Low power consumption and compact setup  

## 🛠️ Components Required  
- **ESP8266** or **ESP32** microcontroller  
- **0.96" OLED Display** (SSD1306)  
- **Jumper Wires**  
- **Breadboard** (optional)  
- **Micro USB Cable** (for programming and power)  

## ⚙️ Circuit Diagram  
> Connect your OLED display to the ESP8266/ESP32 as follows:  

| OLED Pin  | ESP8266 Pin | ESP32 Pin |
|-----------|------------|------------|
| VCC       | 3.3V       | 3.3V       |
| GND       | GND        | GND        |
| SCL       | D1 (GPIO5) | GPIO22     |
| SDA       | D2 (GPIO4) | GPIO21     |

## 🔧 Software Requirements  
- **Arduino IDE** (latest version)  
- **Arduino IoT Cloud Account**  
- Required Libraries:  
  - `ArduinoIoTCloud`  
  - `Adafruit_GFX`  
  - `Adafruit_SSD1306`  
  - `Wire.h`  

## 🚀 Setup Instructions  

### 1️⃣ Create an Arduino IoT Cloud Account  
- Sign up at **[Arduino IoT Cloud](https://cloud.arduino.cc/)**  
- Create a new **Thing** and add a **String Variable** (e.g., `messageText`)  

### 2️⃣ Install Required Libraries in Arduino IDE  
- Open **Arduino IDE**  
- Go to **Sketch** → **Include Library** → **Manage Libraries**  
- Install **ArduinoIoTCloud**, **Adafruit_GFX**, and **Adafruit_SSD1306**  

### 3️⃣ Upload the Code to ESP8266/ESP32  
- Connect your board via USB  
- Select the correct **board** and **port** in Arduino IDE  
- Modify WiFi credentials (`SSID` & `Password`) in the code  
- Upload the sketch  

## 🎮 How to Use  
1. Open **Arduino IoT Cloud Dashboard**.  
2. Enter a message in the **text input field**.  
3. Click **Send** – The OLED screen updates instantly!  

## 🛠️ Troubleshooting  
- **OLED not displaying text?**  
  - Check wiring connections.  
  - Ensure the correct **I2C address** (`0x3C` for SSD1306).  
- **WiFi not connecting?**  
  - Verify **SSID** and **Password** in the code.  
  - Restart the ESP8266/ESP32.  
- **Cloud data not updating?**  
  - Check the **Arduino IoT Cloud dashboard** for errors.  
  - Ensure your device is online.  

## 🔮 Future Improvements  
- Add support for multiple fonts and animations.  
- Integrate voice commands using Google Assistant.  
- Expand to support MQTT for more IoT flexibility.  
