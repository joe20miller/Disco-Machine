#define RED_LED 11
#define GREEN_LED 10
#define BLUE_LED 9
#define PUSH_BUTTON 2
int MIN_SPEED;

void LED_COLOUR_FADE(int MIN_SPEED) {
  int x = 0;
  int y = 255;
  int a = 0;
  int b = 255;
  int e = 0;
  int f = 255;

  int POTENTIOMETER_VALUE = analogRead(A0);
  int INPUT_SPEED = map(POTENTIOMETER_VALUE, 0, 1023, 1, MIN_SPEED);
  Serial.println(INPUT_SPEED);

  while (x < 255, y > 0) {
    if (a == 255) {
      break;
    }
    analogWrite(BLUE_LED, x);
    analogWrite(RED_LED, y);
    x += 5;
    y -= 5;
    int POTENTIOMETER_VALUE = analogRead(A0);
    int INPUT_SPEED = map(POTENTIOMETER_VALUE, 0, 1023, 1, MIN_SPEED);
    Serial.println(INPUT_SPEED);
    delay(INPUT_SPEED);
    if (y == 0) {//BLUE HIGH, RED LOW
      while (e < 255, f > 0) {
        if (a == 255) {
          break;
        }
        analogWrite(GREEN_LED, e);
        analogWrite(BLUE_LED, f);
        e += 5;
        f -= 5;
        int POTENTIOMETER_VALUE = analogRead(A0);
        int INPUT_SPEED = map(POTENTIOMETER_VALUE, 0, 1023, 1, MIN_SPEED);
        Serial.println(INPUT_SPEED);
        delay(INPUT_SPEED);
        if (f == 0) {//GREEN HIGH, BLUE LOW
          while (a < 255, b > 0) {
            analogWrite(RED_LED, a);
            analogWrite(GREEN_LED, b);
            a += 5;
            b -= 5;
            int POTENTIOMETER_VALUE = analogRead(A0);
            int INPUT_SPEED = map(POTENTIOMETER_VALUE, 0, 1023, 1, MIN_SPEED);
            Serial.println(INPUT_SPEED);
            delay(INPUT_SPEED);
            if (a == 255) {//GREEN LOW, RED HIGH
              digitalWrite(RED_LED, LOW);
              digitalWrite(BLUE_LED, LOW);
              digitalWrite(GREEN_LED, LOW);
              break;
            }
          }
        }
      }
    }
  }
}

void setup() {
  Serial.begin(9600);
  pinMode(RED_LED, OUTPUT);
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(A0, INPUT); //Potentiometer
  pinMode(PUSH_BUTTON, INPUT);
}

void loop() {

  int RAVE_MODE = digitalRead(PUSH_BUTTON);
  if (RAVE_MODE == HIGH) {
    Serial.println("RAVE! RAVE! RAVE!");
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(50);
    digitalWrite(RED_LED, HIGH);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(50);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(50);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, HIGH);
    digitalWrite(GREEN_LED, LOW);
    delay(50);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, LOW);
    delay(50);
    digitalWrite(RED_LED, LOW);
    digitalWrite(BLUE_LED, LOW);
    digitalWrite(GREEN_LED, HIGH);
    delay(50);
  }
  else LED_COLOUR_FADE(20);
}
