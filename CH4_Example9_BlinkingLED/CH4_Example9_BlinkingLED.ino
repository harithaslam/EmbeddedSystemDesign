unsigned long pasttime1 = 0;
unsigned long currenttime1 = 0;
unsigned long pasttime2 = 0;
unsigned long currenttime2 = 0;
unsigned long pasttime3 = 0;
unsigned long currenttime3 = 0;
unsigned long pasttime4 = 0;
unsigned long currenttime4 = 0;
unsigned long pasttime5 = 0;
unsigned long currenttime5 = 0;
unsigned long pasttime6 = 0;
unsigned long currenttime6 = 0;
unsigned long pasttime7 = 0;
unsigned long currenttime7 = 0;
unsigned long pasttime8 = 0;
unsigned long currenttime8 = 0;

bool flag1 = 0;
bool flag2 = 0;
bool flag3 = 0;
bool flag4 = 0;
bool flag5 = 0;
bool flag6 = 0;
bool flag7 = 0;
bool flag8 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(0, OUTPUT);   //equivalent to PD0
  pinMode(1, OUTPUT);   //equivalent to PD1
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  currenttime1 = millis(); //Returns the number of milliseconds passed
  currenttime2 = millis();
  currenttime3 = millis();
  currenttime4 = millis();
  currenttime5 = millis();
  currenttime6 = millis();
  currenttime7 = millis();
  currenttime8 = millis();

  if (flag1 == 0) {
    digitalWrite(0, HIGH);
    if ((currenttime1 - pasttime1) > 781) {
      flag1 = 1;
      pasttime1 = currenttime1;
    }
  }
  else {
    digitalWrite(0, LOW);
    if ((currenttime1 - pasttime1) > 515) {
      flag1 = 0;
      pasttime1 = currenttime1;
    }
  }

  if (flag2 == 0) {
    digitalWrite(1, HIGH);
    if ((currenttime2 - pasttime2) > 2014) {
      flag2 = 1;
      pasttime2 = currenttime2;
    }
  }
  else  {
    digitalWrite(1, LOW);
    if ((currenttime2 - pasttime2) > 1348) {
      flag2 = 0;
      pasttime2 = currenttime2;
    }
  }

  if (flag3 == 0) {
    digitalWrite(2, HIGH);
    if ((currenttime3 - pasttime3) > 343) {
      flag3 = 1;
      pasttime3 = currenttime3;
    }
  }
  else {
    digitalWrite(2, LOW);
    if ((currenttime3 - pasttime3) > 573) {
      flag3 = 0;
      pasttime3 = currenttime3;
    }
  }

  if (flag4 == 0) {
    digitalWrite(3, HIGH);
    if ((currenttime4 - pasttime4) > 678) {
      flag4 = 1;
      pasttime4 = currenttime4;
    }
  }
  else {
    digitalWrite(3, LOW);
    if ((currenttime4 - pasttime4) > 1839) {
      flag4 = 0;
      pasttime4 = currenttime4;
    }
  }

  if (flag5 == 0) {
    digitalWrite(4, HIGH);
    if ((currenttime5 - pasttime5) > 342) {
      flag5 = 1;
      pasttime5 = currenttime5;
    }
  }
  else {
    digitalWrite(4, LOW);
    if ((currenttime5 - pasttime5) > 534) {
      flag5 = 0;
      pasttime5 = currenttime5;
    }
  }

  if (flag6 == 0) {
    digitalWrite(5, HIGH);
    if ((currenttime6 - pasttime6) > 1478) {
      flag6 = 1;
      pasttime6 = currenttime6;
    }
  }
  else {
    digitalWrite(5, LOW);
    if ((currenttime6 - pasttime6) > 326) {
      flag6 = 0;
      pasttime6 = currenttime6;
    }
  }

  if (flag7 == 0) {
    digitalWrite(6, HIGH);
    if ((currenttime7 - pasttime7) > 1859) {
      flag7 = 1;
      pasttime7 = currenttime7;
    }
  }
  else {
    digitalWrite(6, LOW);
    if ((currenttime7 - pasttime7) > 351) {
      flag7 = 0;
      pasttime7 = currenttime7;
    }
  }

  if (flag8 == 0) {
    digitalWrite(7, HIGH);
    if ((currenttime8 - pasttime8) > 777) {
      flag8 = 1;
      pasttime8 = currenttime8;
    }
  }
  else {
    digitalWrite(7, LOW);
    if ((currenttime8 - pasttime8) > 888) {
      flag8 = 0;
      pasttime8 = currenttime8;
    }
  }
}
