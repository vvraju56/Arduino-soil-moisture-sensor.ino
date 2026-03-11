#define MOISTURE_SENSOR_PIN A0
#define FLOW_SENSOR_PIN 2
#define MOTOR_PIN 3

#define MOISTURE_THRESHOLD 30

volatile int pulseCount = 0;
float flowRate = 0.0;
unsigned long oldTime = 0;

void setup() {
  Serial.begin(9600);
  pinMode(MOISTURE_SENSOR_PIN, INPUT);
  pinMode(MOTOR_PIN, OUTPUT);
  pinMode(FLOW_SENSOR_PIN, INPUT_PULLUP);
  
  attachInterrupt(digitalPinToInterrupt(FLOW_SENSOR_PIN), pulseCounter, FALLING);
  
  Serial.println("Smart Irrigation System Initialized");
}

void loop() {
  unsigned long currentTime = millis();
  
  int moistureLevel = analogRead(MOISTURE_SENSOR_PIN);
  moistureLevel = map(moistureLevel, 0, 1023, 100, 0);
  
  if (currentTime - oldTime >= 1000) {
    flowRate = pulseCount * 2.25;
    pulseCount = 0;
    oldTime = currentTime;
  }
  
  bool motorStatus = moistureLevel < MOISTURE_THRESHOLD;
  digitalWrite(MOTOR_PIN, motorStatus ? HIGH : LOW);
  
  Serial.print("Moisture:");
  Serial.print(moistureLevel);
  Serial.print(", FlowRate:");
  Serial.print(flowRate);
  Serial.print(", Motor:");
  Serial.println(motorStatus ? "ON" : "OFF");
  
  delay(1000);
}

void pulseCounter() {
  pulseCount++;
}
