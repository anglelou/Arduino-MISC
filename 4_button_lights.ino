int pinButton1 = 2;
int pinButton2 = 3;
int pinButton3 = 4;
int pinButton4 = 5;

int LED1 = 10;
int LED2 = 11;
int LED3 = 12;
int LED4 = 13;

int stateLED1 = LOW;
int stateButton1;
int stateLED2 = LOW;
int stateButton2;
int stateLED3 = LOW;
int stateButton3;
int stateLED4 = LOW;
int stateButton4;
int previous = LOW;

long time = 0;
long debounce = 200;

void setup() {
pinMode(pinButton1, INPUT);
pinMode(LED1, OUTPUT);
pinMode(pinButton2, INPUT);
pinMode(LED2, OUTPUT);
pinMode(pinButton3, INPUT);
pinMode(LED3, OUTPUT);
pinMode(pinButton4, INPUT);
pinMode(LED4, OUTPUT);
}

void loop() {

stateButton1 = digitalRead(pinButton1);
if(stateButton1 == HIGH && previous == LOW && millis() - time > debounce) {
if (stateLED1 == HIGH) {
stateLED1 = LOW;
} else {
stateLED1 = HIGH;
}
time = millis();
}
digitalWrite(LED1, stateLED1);
previous == stateButton1;

stateButton2 = digitalRead(pinButton2);
if(stateButton2 == HIGH && previous ==LOW && millis() - time > debounce) {
if (stateLED2 == HIGH) {
stateLED2 = LOW;
} else {
stateLED2 = HIGH;
}
time = millis();
}
digitalWrite(LED2, stateLED2);
previous == stateButton2;

stateButton3 = digitalRead(pinButton3);
if(stateButton3 == HIGH && previous == LOW && millis() - time > debounce){
if (stateLED3 == HIGH) {
stateLED3 = LOW;
} else {
stateLED3 = HIGH;
}
time = millis();
}
digitalWrite(LED3, stateLED3);
previous == stateButton3;

stateButton4 = digitalRead(pinButton4);
if(stateButton4 == HIGH && previous == LOW && millis() - time > debounce) {
if (stateLED4 == HIGH) {
stateLED4 = LOW;
} else {
stateLED4 = HIGH;
}
time = millis();
}
digitalWrite(LED4, stateLED4);
previous == stateButton4;
}
