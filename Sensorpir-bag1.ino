// Pin yang digunakan
const int pirPin = 2;    // Pin sensor PIR
const int ledPin = 13;   // Pin LED
const int buzzerPin = 8; // Pin buzzer

// Variable
int pirState = LOW;      // Status sensor PIR
int lastPirState = LOW;  // Status sensor PIR sebelumnya

void setup() {
  pinMode(pirPin, INPUT);     // Set sensor PIR sebagai input
  pinMode(ledPin, OUTPUT);    // Set LED sebagai output
  pinMode(buzzerPin, OUTPUT); // Set buzzer sebagai output

  Serial.begin(9600);         // Inisialisasi Serial Monitor
}

void loop() {
  // Membaca status sensor PIR
  pirState = digitalRead(pirPin);

  // Jika sensor PIR terdeteksi gerakan
  if (pirState == HIGH && lastPirState == LOW) {
    // LED berkedip dan buzzer mengikuti pola LED
    for (int i = 0; i < 5; i++) {
      digitalWrite(ledPin, HIGH);
      digitalWrite(buzzerPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      digitalWrite(buzzerPin, LOW);
      delay(200);
    }
    Serial.println("Gerakan Terdeteksi!");
  }
  // Jika sensor PIR tidak ada gerakan
  else if (pirState == LOW && lastPirState == HIGH) {
    // LED mati dan buzzer mati
    digitalWrite(ledPin, LOW);
    digitalWrite(buzzerPin, LOW);
    Serial.println("Tidak Ada Gerakan");
  }

  // Menyimpan status sensor PIR sebelumnya
  lastPirState = pirState;
}
