#include <Settings.h>

// connect wifi
void WIFIConnect()
{

    //onboadled aansturing
pinMode(LED_BUILTIN, OUTPUT);    // Initialize the LED_BUILTIN pin as an output                                   
digitalWrite(LED_BUILTIN, HIGH); // Ensure LED is off

ipAdressFixed();

    if (WiFi.status() != WL_CONNECTED)
    { // als wifi niet geconnect
        // Connect to Wi-Fi network with SSID and password
        WiFi.begin(ssid, password);
        while (WiFi.status() != WL_CONNECTED)
        {
            // blink the LED fast while connecting.
            digitalWrite(LED_BUILTIN, HIGH);
            delay(250);
            digitalWrite(LED_BUILTIN, LOW);
            delay(250);
            Serial.print("Connecting to ");
            Serial.println(ssid);
        }
        // Print local IP address
        Serial.println("");
        Serial.println("WiFi connected.");
        Serial.println("IP address: ");
        Serial.println(WiFi.localIP());
    }
}
