/* Final Exam :Embedded System Design
 *  Harith Aslam Bin Ahmad Naziri (1715531)
 *  CAR CRASH GAME USING 16x2 LCD display 
 *  Components used:
  1. Arduino Uno
  2. LCD 16x2
  3. Potentiometer
  4. Buzzer (didn't function well when servo.attach)
  5. Jumper Wire
  6. RGB LED 
*/

#include <Servo.h> // Servo Library
#include <LiquidCrystal.h> // LiquidCrystal display Library

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Register Select (12), Enable(11), DB4(5), DB5(4), DB6(3), DB7(2)
Servo myServo;
// Steering wheel potentiometer
const int POTPIN = A1;

// Piezo speaker
const int BUZZER = 10;

// Servo
int val_servo;

//RGB LED
const int blue = 6;//set blue to pin 3
const int red = 7;//set red to pin 5
const int green = 8;//set green to pin 6

const int RANDSEEDPIN = 0; // an analog pin that isn't connected to anything

const int MAXSTEPDURATION = 300; // Start slowly, each step is 1 millisec shorter.
const int MINSTEPDURATION = 150; // This is as fast as it gets

const int NGLYPHS = 6;
// the glyphs will be defined starting from 1 (not 0),
// to enable lcd.print() of null-terminated strings
byte glyphs[NGLYPHS][8] = {
  // 1: car up
  { B00000,
    B01110,
    B11111,
    B01010,
    B00000,
    B00000,
    B00000,
    B00000
  }
  // 2: car down
  , {
    B00000,
    B00000,
    B00000,
    B00000,
    B01110,
    B11111,
    B01010,
    B00000
  }
  // 3: truck up
  , {
    B00000,
    B11110,
    B11111,
    B01010,
    B00000,
    B00000,
    B00000,
    B00000
  }
  // 4: truck down
  , {
    B00000,
    B00000,
    B00000,
    B00000,
    B11110,
    B11111,
    B01010,
    B00000
  }
  // 5: crash up
  , {
    B10101,
    B01110,
    B01110,
    B10101,
    B00000,
    B00000,
    B00000,
    B00000
  }
  // 6: crash down
  , {
    B00000,
    B00000,
    B00000,
    B10101,
    B01110,
    B01110,
    B10101,
    B00000
  }
};

const int CARPOSITIONS = 4;

// Each position is mapped to a column of 2 glyphs
// where car or crash was drawn as 2 glyphs
const char BLANK = 32;
char car2glyphs[CARPOSITIONS][2] = {
  {1, BLANK}, {2, BLANK}, {BLANK, 1}, {BLANK, 2}
};
char truck2glyphs[CARPOSITIONS][2] = {
  {3, BLANK}, {4, BLANK}, {BLANK, 3}, {BLANK, 4}
};
char crash2glyphs[CARPOSITIONS][2] = {
  {5, BLANK}, {6, BLANK}, {BLANK, 5}, {BLANK, 6}
};

const int ROADLEN = 15; // LCD width (not counting the car)
int road[ROADLEN]; // positions of other cars
char line_buff[2 + ROADLEN]; // aux string for drawRoad()
int road_index;
int car_pos;
// Off-the-grid position means empty column, so MAXROADPOS
// determines the probability of a car in a column
// e.g. 3*CARPOSITIONS gives p=1/3
const int MAXROADPOS = 3 * CARPOSITIONS;
int step_duration;

int crash; // true if crashed
unsigned int crashtime; // millis() when crashed
const int CRASHSOUNDDURATION = 250;

const char *INTRO1 = "Trucks ahead,";
const char *INTRO2 = "Drive carefully";
const int INTRODELAY = 2000;

void setup()
{
  crash = crashtime = road_index = 0;
  step_duration = MAXSTEPDURATION;
  line_buff[1 + ROADLEN] = '\0'; // null terminate it
  randomSeed(analogRead(RANDSEEDPIN));
  for (int i = 0; i < NGLYPHS; i++) {
    lcd.createChar(i + 1, glyphs[i]);
  }
  for (int i = 0; i < ROADLEN; i++) {
    road[i] = -1;
  }
  pinMode(blue, OUTPUT);//set blue as an output
  pinMode(red, OUTPUT);//set red as an output
  pinMode(green, OUTPUT);//set green as an output
  myServo.attach(9);
  myServo.write(180);
  pinMode(BUZZER, OUTPUT);
  analogWrite(BUZZER, 0); // to be on the safe side
  lcd.begin(16, 2);
  getSteeringWheel();
  drawRoad();
  lcd.setCursor(1, 0);
  lcd.print(INTRO1);
  lcd.setCursor(1, 1);
  lcd.print(INTRO2);
  delay(INTRODELAY);

}

void loop() {
  unsigned long now = millis() - INTRODELAY;

  val_servo = map(now, 0, 50000, 180, 0);//here I consider 50second is very hard 
                                         //which makes the toy car is at final line (the player is on top of the level)
                                         //servo value is mapped by the time of the game played
  if (!crash) {
    getSteeringWheel();
    crash = (car_pos == road[road_index]);
    myServo.write(val_servo); //toy car moved slowly till 50secs
  }
  if (crash) {
    if (!crashtime) {
      crashtime = now;
      drawRoad();
      // Game over text
      // (keep first 2 "crash" columns intact)
      lcd.setCursor(2, 0);
      lcd.print("Crashed after");
      lcd.setCursor(2, 1);
      lcd.print(now / 1000);
      lcd.print(" seconds.");
    }
    while ((now - crashtime) < CRASHSOUNDDURATION) {
      analogWrite(BUZZER, random(255)); // white noise
      
      digitalWrite(blue, HIGH); //color sequence for cycling through blue, red, green. One at a time.
      delay(1000);
      digitalWrite(blue, LOW);
      delay(1000);
      digitalWrite(red, HIGH);
      delay(1000);
      digitalWrite(red, LOW);
      delay(1000);
      digitalWrite(green, HIGH);
      delay(1000);
      digitalWrite(green, LOW);
      delay(1000);

      digitalWrite(blue, HIGH);//color sequence for purple
      digitalWrite(red, HIGH);
      digitalWrite(green, LOW);
      delay(1000);
      digitalWrite(blue, HIGH);//color sequence for turquoise
      digitalWrite(green, HIGH);
      digitalWrite(red, LOW);
      delay(1000);
    }
    
    while ((now - crashtime) > CRASHSOUNDDURATION) {
      analogWrite(BUZZER, 0); // dramatic post-crush silence :)
    }
    delay(10); // Wait a bit between writes
  }
  else {

    int prev_pos = road[(road_index - 1) % ROADLEN];
    int this_pos = random(MAXROADPOS);
    while (abs(this_pos - prev_pos) < 2) { // don't jam the road
      this_pos = random(MAXROADPOS);
    }
    road[road_index] = this_pos;
    road_index = (road_index + 1) % ROADLEN;
    drawRoad();
    delay(step_duration);
    if (step_duration > MINSTEPDURATION) {
      step_duration--; // go faster
    }
  }
}
void getSteeringWheel() {
  car_pos = map(analogRead(POTPIN), 0, 1024, 0, CARPOSITIONS);
}

void drawRoad() {
  for (int i = 0; i < 2; i++) {
    if (crash) {
      line_buff[0] = crash2glyphs[car_pos][i];
    }
    else {
      line_buff[0] = car2glyphs[car_pos][i];
    }
    for (int j = 0; j < ROADLEN; j++) {
      int pos = road[(j + road_index) % ROADLEN];
      line_buff[j + 1] = pos >= 0 && pos < CARPOSITIONS ? truck2glyphs[pos][i] : BLANK;
    }
    lcd.setCursor(0, i);
    lcd.print(line_buff);
  }
}
