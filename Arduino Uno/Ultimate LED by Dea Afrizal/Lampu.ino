#define ledRed 2
#define ledGreen 4
#define button 6

void setup() {
  Serial.begin(9600);

  pinMode(button, INPUT);
  digitalWrite(button, HIGH);

  pinMode(ledRed, OUTPUT);
  pinMode(ledGreen, OUTPUT);
}

void ultimate(int option) {
  if (option == 6){
    digitalWrite(ledRed, HIGH);
    delay(100);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    delay(100);
    digitalWrite(ledGreen, LOW);
  }
  else{
    digitalWrite(ledRed, HIGH);
    delay(500);
    digitalWrite(ledRed, LOW);
    digitalWrite(ledGreen, HIGH);
    delay(500);
    digitalWrite(ledGreen, LOW);
  }
}

void loop() {
  int isbt = digitalRead(button);

  if(isbt == 0){
    Serial.println("speed button pressed");
    Serial.println(button);
    ultimate(6);
  }
  else{
    ultimate(0);
  }
}
