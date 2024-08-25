#define LED1 15

void setup() {
  Serial.begin(115200);  // Initialize serial communication
  Serial2.begin(115200);
  
  pinMode(LED1, OUTPUT);
}

void loop() {
  if (Serial.available() > 0) 
  {
    String data = Serial.readString();
    Serial2.print(data);
  }
  if (Serial2.available()) 
  {
    String receivedData = Serial2.readString();  // Receive data via UART
    Serial.println(receivedData);
    receivedData.trim();
    if (receivedData.equals("LED_ON"))
    {
      digitalWrite(LED1, HIGH);
    }
    if (receivedData.equals("LED_OFF"))
    {
      digitalWrite(LED1, LOW);
    }
    else 
    {
      Serial2.print("NO-INPUT");
    }
  }
}


