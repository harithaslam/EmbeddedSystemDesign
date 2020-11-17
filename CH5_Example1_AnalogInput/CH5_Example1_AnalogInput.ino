void setup() {
  Serial.begin(9600);
  pinMode(A3,INPUT);
}

void loop() {
  int value = analogRead(A3);
  Serial.println(value);
}
