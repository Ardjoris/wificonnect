


//connecting to a mqtt broker
WiFiClient arduinoClient;
PubSubClient client(arduinoClient);

void MQQTConnect()  {
  client.setServer(mqtt_broker, mqtt_port);     //misschen dit bij setup zetten?
  client.setCallback(callback);                 //misschen dit bij setup zetten? ligt of hij de callback ook opvraagt dan iedere loop
  //client.setCallback(callback2);

    String client_id = "esp8266-client-";
    client_id = String(WiFi.macAddress());
   while (!client.connected()) {
    Serial.printf("The client %s connects to the public mqtt broker\n", client_id.c_str());
    Serial.println("Not connected to MQTT");
    //Blink the led
    int i = 1, som = 0;
    while (i <= 10) { //zolang i kleiner dan x is
      som += i;      // som = som + i
      digitalWrite(LED_BUILTIN, LOW);
      delay (150);
      digitalWrite(LED_BUILTIN, HIGH);
      delay (50);
      ++i;
    }
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      Serial.println("connected to MQTT");
     digitalWrite(LED_BUILTIN, LOW);
      // publish and subscribe
      client.publish(topic, "Sender connected");
     // client.publish(topic2, "Sender connected");

      client.subscribe(topic);
    //  client.subscribe(topic2);
    }   else {
      Serial.print("failed with state ");
      Serial.println(client.state());
    }
  }
}
