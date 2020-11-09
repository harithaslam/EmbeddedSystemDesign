const int  buttonPin1   = 10;    // the pin that the pushbutton is attached to
const int  buttonPin2   = 11;
const int  buttonPin3   = 12;
const int  buttonPin4   = A4;
const int  buttonPin5   = A5;

int buttonPushCounter1 = 0;   // counter for the number of button presses
int buttonPushCounter2 = 0;
int buttonPushCounter3 = 0;
int buttonPushCounter4 = 0;
int buttonPushCounter5 = 0;

int up_buttonState1 = 0;         // current state of the up button
int up_lastButtonState1 = 0;     // previous state of the up button

int up_buttonState2 = 0;         // current state of the up button
int up_lastButtonState2 = 0;     // previous state of the up button

int up_buttonState3 = 0;         // current state of the up button
int up_lastButtonState3 = 0;     // previous state of the up button

int up_buttonState4 = 0;         // current state of the up button
int up_lastButtonState4 = 0;     // previous state of the up button

int up_buttonState5 = 0;         // current state of the up button
int up_lastButtonState5 = 0;     // previous state of the up button

bool b1Press = false;
bool b2Press = false;
bool b3Press = false;
bool b4Press = false;
bool b5Press = false;

void setup() {
  Serial.begin(9600);
  pinMode( buttonPin1 , INPUT_PULLUP);
  pinMode( buttonPin2 , INPUT_PULLUP);
  pinMode( buttonPin3 , INPUT_PULLUP);
  pinMode( buttonPin4 , INPUT_PULLUP);
  pinMode( buttonPin5 , INPUT_PULLUP);

  Serial.print(buttonPushCounter1);
}

void loop() {
  // put your main code here, to run repeatedly:
  button1();
  button2();
  button3();
  button4();
  button5();

  if (b1Press) {
    b1Press = false;
  }

  if (b2Press) {
    b2Press = false;
  }

  if (b3Press) {
    b3Press = false;
  }

  if (b4Press) {
    b4Press = false;
  }

  if (b5Press) {
    b5Press = false;
  }
}

void button1()
{
  up_buttonState1 = digitalRead(buttonPin1);

  // compare the buttonState to its previous state

  if (up_buttonState1 != up_lastButtonState1) {

    // if the state has changed, increment the counter

    if (up_buttonState1 == LOW) {

      b1Press = true;

      // if the current state is HIGH then the button went from off to on:

      buttonPushCounter1++;
      Serial.print("number of button1 pushes: ");
      Serial.println(buttonPushCounter1);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState1 = up_buttonState1;
}

void button2()
{
  up_buttonState2 = digitalRead(buttonPin2);

  // compare the buttonState to its previous state

  if (up_buttonState2 != up_lastButtonState2) {

    // if the state has changed, increment the counter

    if (up_buttonState2 == LOW) {

      b2Press = true;

      // if the current state is HIGH then the button went from off to on:

      buttonPushCounter2++;
      Serial.print("number of button2 pushes: ");
      Serial.println(buttonPushCounter2);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState2 = up_buttonState2;
}

void button3()
{
  up_buttonState3 = digitalRead(buttonPin3);

  // compare the buttonState to its previous state

  if (up_buttonState3 != up_lastButtonState3) {

    // if the state has changed, increment the counter

    if (up_buttonState3 == LOW) {

      b3Press = true;

      // if the current state is HIGH then the button went from off to on:

      buttonPushCounter3++;
      Serial.print("number of button3 pushes: ");
      Serial.println(buttonPushCounter3);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState3 = up_buttonState3;
}

void button4()
{
  up_buttonState4 = digitalRead(buttonPin4);

  // compare the buttonState to its previous state

  if (up_buttonState4 != up_lastButtonState4) {

    // if the state has changed, increment the counter

    if (up_buttonState4 == LOW) {

      b4Press = true;

      // if the current state is HIGH then the button went from off to on:

      buttonPushCounter4++;
      Serial.print("number of button4 pushes: ");
      Serial.println(buttonPushCounter4);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState4 = up_buttonState4;
}

void button5()
{
  up_buttonState5 = digitalRead(buttonPin5);

  // compare the buttonState to its previous state

  if (up_buttonState5 != up_lastButtonState5) {

    // if the state has changed, increment the counter

    if (up_buttonState5 == LOW) {

      b5Press = true;

      // if the current state is HIGH then the button went from off to on:

      buttonPushCounter5++;
      Serial.print("number of button5 pushes: ");
      Serial.println(buttonPushCounter5);
    }
    // Delay a little bit to avoid bouncing
    delay(50);
  }
  // save the current state as the last state, for next time through the loop
  up_lastButtonState5 = up_buttonState5;
}
