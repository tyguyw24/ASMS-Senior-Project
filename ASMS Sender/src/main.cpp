
/*
#include <esp_now.h>
#include <WiFi.h>

#define BUTTON_PIN 5  // Button connected to GPIO 5 (pulled to GND when pressed)

// REPLACE WITH YOUR RECEIVER'S MAC ADDRESS
uint8_t receiverAddress[] = {0x78, 0x42, 0x1C, 0xA2, 0x97, 0x40};

// Define a data structure to send
typedef struct struct_message {
  int id;
  char message[32];
} struct_message;

struct_message outgoingData;

void OnDataSent(const uint8_t *mac_addr, esp_now_send_status_t status) {
  Serial.print("Send Status: ");
  Serial.println(status == ESP_NOW_SEND_SUCCESS ? "Success" : "Fail");
}

void setup() {
  Serial.begin(115200);

  pinMode(BUTTON_PIN, INPUT_PULLUP);

  // Initialize WiFi in STA mode
  WiFi.mode(WIFI_STA);

  // Initialize ESP-NOW
  if (esp_now_init() != ESP_OK) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  // Register callback for send status
  esp_now_register_send_cb(OnDataSent);

  // Add peer (receiver)
  esp_now_peer_info_t peerInfo = {};
  memcpy(peerInfo.peer_addr, receiverAddress, 6);
  peerInfo.channel = 0;
  peerInfo.encrypt = false;

  if (esp_now_add_peer(&peerInfo) != ESP_OK) {
    Serial.println("Failed to add peer");
    return;
  }

  Serial.println("Sender ready!");
}

void loop() {
  // When button is pressed (active LOW)
  if (digitalRead(BUTTON_PIN) == LOW) {
    outgoingData.id = 1;
    strcpy(outgoingData.message, "Button Pressed!");

    esp_err_t result = esp_now_send(receiverAddress, (uint8_t *)&outgoingData, sizeof(outgoingData));

    if (result == ESP_OK) {
      Serial.println("Message sent successfully");
    } else {
      Serial.println("Error sending message");
    }

    delay(500); // debounce delay
  }
}
*/



#include <WiFi.h>

void setup() {
  Serial.begin(115200);
  delay(1000);

  Serial.println("\n===== ESP32 Hardware Test =====");
  Serial.println("Checking basic functions...");

  // Blink test
  pinMode(2, OUTPUT);

  // Print MAC address
  Serial.print("WiFi MAC Address: ");
  Serial.println(WiFi.macAddress());
}

void loop() {
  // Blink onboard LED
  digitalWrite(2, HIGH);
  delay(500);
  digitalWrite(2, LOW);
  delay(500);

  // Keep printing heartbeat to Serial
  Serial.println("ESP32 is alive!");
  delay(1000);
}
