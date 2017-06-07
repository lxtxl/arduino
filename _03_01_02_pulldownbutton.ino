#define LED 3
#define BUTTON 8

void setup() {  
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonStatus = digitalRead(BUTTON);
  if(buttonStatus == HIGH){
    digitalWrite(LED, HIGH);
    delay(500);
    digitalWrite(LED, LOW);
  }
  Serial.print("buttonStatus:");
  Serial.print(buttonStatus);
  Serial.println();
  delay(100);
}
