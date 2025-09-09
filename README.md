**Smart Health Monitoring and Alerting System**
# 📌 Overview -

This project implements an IoT-enabled health monitoring system that continuously tracks vital health parameters and generates real-time alerts in case of abnormalities.
The system combines sensors, microcontrollers, and cloud connectivity to provide reliable monitoring, making it suitable for patients, elderly care, and remote health tracking.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🎯 Features -

- **Heart Rate Monitoring** (Pulse Sensor): Measures BPM and detects irregular heartbeat patterns.
- **Body Temperature Measurement** (DHT22): Tracks body temperature for fever or abnormal changes.
- **SpO₂** (Oxygen Level Monitoring - MAX30100/30102): Ensures oxygen saturation levels are within safe ranges.
- **IoT Integration** (ESP32): Sends live health data to a cloud server/mobile dashboard.
- **Alert System** (Buzzer/LED + SMS/Email): Notifies caregivers in case of abnormal readings.
- **Data Logging**: Stores historical health records for trend analysis.
- **Scalable**: Can be extended with more sensors like ECG or BP modules.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 🛠️ Hardware Components

- ESP32
- Pulse Sensor (Heartbeat)
- DHT22 Temperature Sensor
- MAX30100 / MAX30102 SpO₂ Sensor
- OLED Display (128x64 I²C)
- Buzzer + LED (for local alerts)
- Jumper wires, breadboard, power supply

---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

# 💻 Software Requirements

- Arduino IDE
- Required Libraries:
    -Wire.h
    -Wifi.h
    -DHT.h
    -LiquidCrystal_I2C.h

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
  
# 🚀 Getting Started
- Connect all sensors to ESP8266/ESP32 as per pin mapping.
- Install Arduino IDE and required libraries.
- Upload the provided sketch to the microcontroller.
- Configure WiFi credentials and cloud dashboard (e.g., Blynk, Thingspeak, or MQTT).
- Power the system via USB or 5V adapter.
- Monitor readings on display and cloud dashboard.

----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------

👨‍💻 Author
**ARYAN BADOLA**
GitHub: ARYxN04
