int pir = D1; // PIR sensor is at D1
int mag = D3; // magnet sensor is at D3;

int buzzer = D5; // buzzer is at D5

int green = D0; // green LED is at D0
int red = D4; // red LED is at D4

void setup()
{
  pinMode(pir, INPUT); // PIR is waiting for input
  pinMode(mag, INPUT); // magnet is waiting for input

  pinMode(buzzer, OUTPUT);  // buzzer is producing output

  pinMode(green, OUTPUT); // green LED is producing output
  pinMode(red, OUTPUT); // red LED is producing output
}

void loop() {
  // set the green LED to be in the same state as the PIR sensor (when sensor detects motion it is HIGH, HIGH for LED means on)
  digitalWrite(green, digitalRead(pir));

  // set the red LED to be in the same state as the magnet sensor (when sensor parts are pulled apart the signal is HIGH, HIGH for LED means on)
  digitalWrite(red, digitalRead(mag));

  // if the input from the magnet sensor is LOW (i.e., the parts are together), set the buzzer to LOW (off)
  if (digitalRead(mag) == LOW) {
    digitalWrite(buzzer, LOW);
  }

  // if the input from the magnet sensor is HIGH (i.e., the parts are apart), set the buzzer to HIGH (on)
  if (digitalRead(mag) == HIGH) {
    Particle.publish("door-open"); // publish an empty event called "door-open"

    delay(5000); // ring the sound for 5 seconds
    digitalWrite(buzzer, HIGH);
  }
}
