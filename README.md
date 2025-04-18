# Smart Indoor Energy Optimization System
---


## 📌 Project Overview

The Smart Indoor Energy Optimization system aims to reduce unnecessary energy usage in indoor environments by intelligently controlling lighting, temperature, and electrical appliances using sensors, actuators, and an ESP32 microcontroller integrated with ThingsBoard via MQTT.

<br>

## 🎯 Objectives

- Monitor indoor environmental parameters (temperature, humidity, motion, etc.)
- Control appliances (lights, fans, HVAC, etc) via relays based on real-time data and schedules
- Enable user control and automation via ThingsBoard dashboard
- Optimize energy usage using scheduling and automation logic

<br>

## 🧱 System Architecture

### 📡 Hardware Components

- **ESP32** – Central microcontroller for communication and control
- **Sensors**
  - DHT22 – Temperature and humidity sensor
  - PIR – Motion detection sensor
  - LDR – Ambient light sensor *(optional)*
- **Actuators**
  - 8-Channel Relay Module – Controls appliances if you needed more you use more.
- **Power Supply**
  - 5V/3.3V regulated power supply for ESP32 and sensors

<br>

### ☁️ Communication

- **Protocol**: MQTT
- **Cloud Platform**: ThingsBoard
- **Connectivity**: Wi-Fi

<br>

## 📊 Dashboard UI (ThingsBoard)

- **Telemetry Widgets**: Temperature, Humidity, Gas Levels
- **Control Widgets**: Switches for all relays
- **Automation Toggles**: Enable/disable motion and schedule control
- **Status Indicators**: Relay state, last update time

<br>

## 📘 Future Improvements

- Add real-time energy consumption sensors (e.g., INA219)
- Machine learning-based adaptive automation
- Mobile app integration
- Solar-powered system extension

<br>

## 🧾 Documentation & Resources

- **Firmware**: ESP32 C++ using Arduino framework
- **Cloud**: ThingsBoard Community Edition
- **Communication**: MQTT over Wi-Fi
- **Libraries Used**: IRremoteESP8266, PubSubClient, DHT, NTPClient, etc.

<br>

## 📞 Contact Information

For any queries or support, feel free to reach out:

- 📧 **Email**: [hemant0hack@gmail.com](mailto:hemant0hack@gmail.com)
- 💼 **LinkedIn**: [linkedin.com/in/hemant0hack](https://www.linkedin.com/in/hemant0hack)
- 📱 **WhatsApp**: <a href="https://wa.me/918445952688?text=Hi%2C%20I%20am%20interested%20in%20this%20project%20can%20you%20provide%20me%20more%20details." target="_blank">+91844XXXX688</a>
- 📸 **Instagram**: <a href="https://www.instagram.com/_hemant0hack_" target="_blank">@_ hemant0hack _</a>