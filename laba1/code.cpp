// дополнительных библиотек не используем

int buttonState = 0;

int lastButtonState = 0;

int buttonPushCounter = 0;

int counts = millis();

void setup()
{
  pinMode(2, INPUT);
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(11, OUTPUT);
}

void loop()
{
   Serial.print("Elapsed time: ");
  buttonState = digitalRead(2);
    if (buttonState != lastButtonState) {
    if (buttonState == HIGH) {
      buttonPushCounter += 1;
    }
    delay(5);
  }
  lastButtonState = buttonState;
  if (buttonPushCounter % 2 == 0) {
    if ((millis()-counts)< 200) {
    	digitalWrite(13, HIGH);
    }
    if ( 200 <= (millis()-counts)&& (millis()-counts) <= 500) {
    	digitalWrite(11, HIGH);
    	digitalWrite(13, LOW);
    }
    if (millis()-counts > 500) {
      digitalWrite(11, LOW);
      counts = millis();
    }
    counts++;
  } else {
    counts = millis();
    digitalWrite(13, LOW);
    digitalWrite(11, LOW);
  }
}