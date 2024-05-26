#include <BluetoothSerial.h>
#include <ESP32Servo.h>

#define SERVO_PIN 2
#define DEFAULT_ANGLE 90 // Posisi awal servo
#define LEFT_ANGLE 140 // Posisi saat servo bergerak ke kiri
#define RIGHT_ANGLE 40 // Posisi saat servo bergerak ke kanan

Servo servo;
BluetoothSerial SerialBT;

void setup() {
  Serial.begin(9600);
  SerialBT.begin("ESP32_Servo"); // Nama Bluetooth yang akan muncul
  servo.attach(SERVO_PIN);
  servo.write(DEFAULT_ANGLE); // Posisi awal servo
  Serial.println("Bluetooth started! Pair with ESP32_Servo");
}

void loop() {
  if (SerialBT.available()) {
    char value = SerialBT.read();
    Serial.print("Received: ");
    Serial.println(value);
    
    switch (value) {
      case 'L':
        servo.write(LEFT_ANGLE);
        break;
      case 'R':
        servo.write(RIGHT_ANGLE);
        break;
      case 'S':
        servo.write(DEFAULT_ANGLE);
        break;
      default:
        Serial.println("Invalid command");
        break;
    }
    delay(10); // Delay untuk menghindari flicker pada servo
  }
}
