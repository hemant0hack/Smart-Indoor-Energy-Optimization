#include <WiFi.h>
#include <PubSubClient.h>
#include <DHT.h>

// Define pins
#define PIR_PIN 34           // Changed to avoid conflict with DHT22
#define LIGHT_SENSOR_PIN 12
#define RELAY_PIN 15
#define DHT_PIN 25               // DHT22 data pin
#define DHT_TYPE DHT22

// WiFi credentials
const char* ssid = "Wokwi-GUEST";
const char* password = "";

// ThingsBoard MQTT settings
const char* mqtt_server = "demo.thingsboard.io";
const int mqtt_port = 1883;
const char* access_token = "0hb1p1bdzs3qc3mqi9nk";

WiFiClient espClient;
PubSubClient client(espClient);
DHT dht(DHT_PIN, DHT_TYPE);

void setup() {
  Serial.begin(115200);

  // Setup pins
  pinMode(PIR_PIN, INPUT);
  pinMode(LIGHT_SENSOR_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Initial relay state

  dht.begin(); // Initialize DHT sensor

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Connect to MQTT
  client.setServer(mqtt_server, mqtt_port);
  connectToMQTT();
}

void connectToMQTT() {
  while (!client.connected()) {
    Serial.println("Connecting to ThingsBoard...");
    if (client.connect("ESP32Client", access_token, NULL)) {
      Serial.println("Connected to ThingsBoard");
    } else {
      Serial.print("Failed to connect, rc=");
      Serial.println(client.state());
      delay(2000);
    }
  }
}

void sendTelemetry(bool relayStatus, float temp, float hum) {
  // Prepare JSON payload
  String payload = "{";
  payload += "\"relay_status\":\"" + String(relayStatus ? "ON" : "OFF") + "\",";
  payload += "\"temperature\":" + String(temp, 2) + ",";
  payload += "\"humidity\":" + String(hum, 2);
  payload += "}";

  if (client.publish("v1/devices/me/telemetry", payload.c_str())) {
    Serial.println("Telemetry sent: " + payload);
  } else {
    Serial.println("Failed to send telemetry");
  }
}

void loop() {
  if (!client.connected()) {
    connectToMQTT();
  }
  client.loop();

  // Sensor readings
  int pirState = digitalRead(PIR_PIN);
  int lightIntensity = analogRead(LIGHT_SENSOR_PIN);
  float temperature = dht.readTemperature();
  float humidity = dht.readHumidity();

  // Relay control
  bool relayOn = (lightIntensity == 0 && pirState == HIGH);
  digitalWrite(RELAY_PIN, relayOn ? HIGH : LOW);

  // Send telemetry
  sendTelemetry(relayOn, temperature, humidity);

  // Debug output
  Serial.print("Motion: "); Serial.print(pirState);
  Serial.print(" | Light: "); Serial.print(lightIntensity);
  Serial.print(" | Temp: "); Serial.print(temperature);
  Serial.print(" °C | Humidity: "); Serial.print(humidity);
  Serial.println(" %");

  delay(1000); // Delay between readings
}
