#include <ESP8266WiFi.h>
//#include <PubSubClient.h>


// Fill in Sidd and Password from modem
const char* ssid     = "sidd";
const char* password = "passwrd";


// Set your Static IP address, Gateway, and Subnet)
IPAddress local_IP(192, 168, 2, 11);
IPAddress gateway(192, 168, 2, 254);
IPAddress subnet(255, 255, 255, 0);


void ipAdressFixed() {
    //(un) quote for (un)fixed IP adress
    if (!WiFi.config(local_IP, gateway, subnet))
    {
        Serial.println("STA Failed to configure");
    }
}

// // MQTT Broker
// const char* mqtt_broker = "192.168.2.3";
// const char* topic = "esp001";
// //const char* topic2= "CTime";
// const char* topicback = "feedback";
// const char* mqtt_username = "arduino11";
// const char* mqtt_password = "wachtw";
// const int mqtt_port = 1883;
