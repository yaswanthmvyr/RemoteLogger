// Generic libraries
#include <Arduino.h>
#include <WiFi.h>

// ESP32 specific libraries
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

// WiFi wrapper
#include <WebSerialLite.h>

// Uncomment the below line to get logs
#define PRINT_LOG

#define UART_RX_PIN 16  // UART2 RX pin
#define UART_TX_PIN 17  // UART2 TX pin
#define UART_BAUD_RATE 460800
#define LOG_BAUD_RATE 460800

// Server instance
AsyncWebServer server(80);

// WiFi hotspot credentials
const char *ssid = "furina";        // Your WiFi SSID
const char *password = "fontaine";  // Your WiFi Password

/**
 * \brief Message callback of WebSerial
 */
void web_rx_cb(uint8_t *data, size_t len) {
  String received_data = "";
  for (int i = 0; i < len; i++) {
    received_data += char(data[i]);
  }
  Serial2.println(received_data);
#ifdef PRINT_LOG
  Serial.println("WebServer: ");
  Serial.println(received_data);
#endif
}

void WiFi_init(void) {
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  delay(1000);
  Serial.println("Waiting for connection...");
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
  }

  // Print IP Address for desktop connect
  Serial.print("Connected. IP Address: ");
  Serial.println(WiFi.localIP());
  Serial.print("MAC Address: ");
  Serial.println(WiFi.macAddress());

  // WebSerial is accessible at "<IP Address>/webserial" in browser
  WebSerial.begin(&server);

  // Attach Message Callback
  WebSerial.onMessage(web_rx_cb);

  server.begin();
}

void setup() {
  // Serial init
  Serial.begin(LOG_BAUD_RATE);

  // WiFi init
  WiFi_init();

  // Uart init
  Serial2.begin(UART_BAUD_RATE, SERIAL_8N1, UART_RX_PIN, UART_TX_PIN);
}

void loop() {
  // Check if data is available on UART2
  if (Serial2.available()) {
    // Read multiple bytes from UART2 buffer
    size_t bytesAvailable = Serial2.available();
    char buffer[bytesAvailable + 1]; // Buffer to store incoming data
    Serial2.readBytes(buffer, bytesAvailable);
    buffer[bytesAvailable] = '\0'; // Null terminate the buffer

    // Print the entire buffer at once
    WebSerial.println(buffer);
#ifdef PRINT_LOG
    Serial.println("MCU: ");
    Serial.println(buffer);
#endif
  }
}
