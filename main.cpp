
#include <ESP8266WiFi.h>

// WiFi
#ifndef STASSID
#define STASSID "credentials"
#define STAPSK "credentials"
#endif

const char *ssid = STASSID;
const char *password = STAPSK;

WiFiClient arduinoClient;

// Set your Static IP address, Gateway, and Subnet)
IPAddress local_IP(192, 168, 2, 12);
IPAddress gateway(192, 168, 2, 254);
IPAddress subnet(255, 255, 255, 0);

void setup()
{

    // logs aanzetten
    Serial.begin(115200);

    // Configures static IP address
    if (!WiFi.config(local_IP, gateway, subnet))
    {
        Serial.println("STA Failed to configure");
    }

    // Connect to Wi-Fi network with SSID and password
    Serial.print("Connecting to ");
    Serial.println(ssid);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED)
    {
        delay(500);
        Serial.println("Connecting to WiFi..");
    }

    // Print local IP address
    Serial.println("");
    Serial.println("WiFi connected.");
    Serial.println("IP address: ");
    Serial.println(WiFi.localIP());

    void loop()
    {
        Serial.println("WiFi connected.");
        delay(1000);
    }
