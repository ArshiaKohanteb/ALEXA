#include <Arduino.h>
#include <Adafruit_ESP8266.h>
#include <fauxmoESP.h>

// -----------------------------------------------------------------------------
// Wifi Credentials
// -----------------------------------------------------------------------------

#define WIFI_SSID "xx"
#define WIFI_PASS "xx"

#define SERIAL_BAUDRATE 115200

fauxmoESP fauxmo;

// -----------------------------------------------------------------------------
// Wifi
// -----------------------------------------------------------------------------


void wifiSetup() {
  // Set WIFI module to STA mode
  WiFi.mode(WIFI_STA);

  // Connect
  Serial.printf("[WIFI] Connecting to %s ", WIFI_SSID);
  WiFi.begin(WIFI_SSID, WIFI_PASS);

  // Wait
  while (WiFi.status() != WL_CONNECTED) {
      Serial.print(".");
      delay(100);
  }
  Serial.println();

  // Connected!
  Serial.printf("[WIFI] STATION Mode, SSID: %s, IP address: %s\n", WiFi.SSID().c_str(), WiFi.localIP().toString().c_str());
}

// -----------------------------------------------------------------------------
// Initilize Pins
// -----------------------------------------------------------------------------

#define RELAY_PIN1 13
#define RELAY_PIN2 2
#define RELAY_PIN3 14
#define RELAY_PIN4 15

void setup() {
  //initialize relay pins
  pinMode(RELAY_PIN1, OUTPUT);
  digitalWrite(RELAY_PIN1, LOW);
  pinMode(RELAY_PIN2, OUTPUT);
  digitalWrite(RELAY_PIN2, LOW);
  pinMode(RELAY_PIN3, OUTPUT);
  digitalWrite(RELAY_PIN3, LOW);
  pinMode(RELAY_PIN4, OUTPUT);
  digitalWrite(RELAY_PIN4, LOW);
  
    // Init serial port and clean garbage
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println();
    Serial.println();
    Serial.println("FauxMo demo sketch");
    Serial.println("After connection, ask Alexa/Echo to 'turn pixels on' or 'off' or 'turn relay on' or 'off'");

  // Wifi
  wifiSetup();

// -----------------------------------------------------------------------------
// Alexa Device Names
// -----------------------------------------------------------------------------

  // Fauxmo
  fauxmo.addDevice("TV");
  fauxmo.addDevice("GregsNetflix");
  fauxmo.addDevice("Sleep");
  fauxmo.addDevice("Office");
//  fauxmo.onMessage(callback);
}

// -----------------------------------------------------------------------------
// Alexa Operation Calls
// -----------------------------------------------------------------------------

void callback(uint8_t device_id, const char * device_name, bool state) {
  Serial.printf("[MAIN] %s state: %s\n", device_name, state ? "ON" : "OFF");
  
  if ( (strcmp(device_name, "TV") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(RELAY_PIN1, HIGH);
    } else {
      digitalWrite(RELAY_PIN1, HIGH);
    }
  }
  
  if ( (strcmp(device_name, "GregsNetflix") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(RELAY_PIN2, HIGH);
    } else {
      digitalWrite(RELAY_PIN2, LOW);
    }
  }
  
  if ( (strcmp(device_name, "Sleep") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(RELAY_PIN3, HIGH);
    } else {
      digitalWrite(RELAY_PIN3, LOW);
    }
  }

  if ( (strcmp(device_name, "Office") == 0) ) {
    // adjust the relay immediately!
    if (state) {
      digitalWrite(RELAY_PIN4, HIGH);
    } else {
      digitalWrite(RELAY_PIN4, LOW);
    }
  }
}

void loop() {
  fauxmo.handle();
  delay(500);
  digitalWrite(RELAY_PIN1, LOW);
  digitalWrite(RELAY_PIN2, LOW);
  digitalWrite(RELAY_PIN3, LOW);
  digitalWrite(RELAY_PIN4, LOW);
}
