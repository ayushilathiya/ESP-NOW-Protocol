#include <ESP8266WiFi.h>
#include <espnow.h>

#define btn1 D1
#define btn2 D3

bool btn1State = false;
bool btn2State = false;

// REPLACE WITH RECEIVER MAC Address
uint8_t broadcastAddress[] = {0xC9, 0xC8, 0xA2, 0x09, 0x07, 0x01};


typedef struct myStruct {
  bool a;
  bool b;
} myStruct;

myStruct structObj;

void OnDataSent(uint8_t *mac_addr, uint8_t sendStatus) {
  if (sendStatus == 0){
    Serial.println("Delivery success");
  }
  else{
    Serial.println("Delivery fail");
  }
}
 
void setup() {

  Serial.begin(115200);
  
  pinMode(btn1, INPUT_PULLUP);
  pinMode(btn2, INPUT_PULLUP);

  WiFi.mode(WIFI_STA);

  if (esp_now_init() != 0) {
    Serial.println("Error initializing ESP-NOW");
    return;
  }

  esp_now_set_self_role(ESP_NOW_ROLE_CONTROLLER);
  esp_now_register_send_cb(OnDataSent); 
  
  esp_now_add_peer(broadcastAddress, ESP_NOW_ROLE_SLAVE, 1, NULL, 0);
}
 
void loop() {
    delay(1000);

    structObj.a = btn1State; 
    structObj.b = btn2State; 

    esp_now_send(broadcastAddress, (uint8_t *) &structObj, sizeof(structObj));
 
   if (digitalRead(btn1) == LOW) {
    btn1State = !btn1State;
    delay(50);
    while (digitalRead(btn1) == LOW);
  }

    if (digitalRead(btn2) == LOW) {
    btn2State = !btn2State;
    delay(50); 
    while (digitalRead(btn2) == LOW);
  }
}