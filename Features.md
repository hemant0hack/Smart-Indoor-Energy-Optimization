## 🧠 Features and Functional Logic

### 1. **Motion-Based Automation**
- PIR sensor on GPIO 34
- Turns ON/OFF lighting based on motion
- Relay 6 (index 5) turns OFF after 10 minutes of no motion
- Motion automation toggle via IR or ThingsBoard RPC

### 2. **Environmental Monitoring**
- DHT22 reads temperature and humidity
- Data sent to ThingsBoard telemetry every few seconds

### 3. **IR Remote Control**
- Control all relays via IR remote
- Changes reflected on dashboard (sync with ThingsBoard)

### 4. **ThingsBoard Control**
- Full manual control of relays via dashboard (RPC)
- Real-time sync with ESP32 hardware

### 5. **Scheduled Automation**
- Relay 3 (index 2) and Relay 4 (index 3)
  - ON at 7:00 PM
  - OFF at 6:00 AM
- Time-based control logic handled via NTP or ThingsBoard scheduler

---

