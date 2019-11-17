int switchPin = 2;              // switch is connected to pin 2
int ledPin1 = 3;
int ledPin2 = 5;
int ledPin3 = 7;
int ledPin4 = 8;

int val;                        // variable for reading the pin status
int val2;                       // variable for reading the delayed status
int buttonState;                // variable to hold the button state
int Mode = 0;              // What mode is the light in?
boolean modeChanged = false;
const int NUM_MODES = 2;


void setup() {
    pinMode(switchPin, INPUT);    // Set the switch pin as input
    pinMode(ledPin1, OUTPUT);
    pinMode(ledPin2, OUTPUT);
    pinMode(ledPin3, OUTPUT);
    pinMode(ledPin4, OUTPUT);
    buttonState = digitalRead(switchPin);   // read the initial state
}


void loop(){
    val = digitalRead(switchPin);      // read input value and store it in val
    delay(10);                         // 10 milliseconds is a good amount of time
    val2 = digitalRead(switchPin);     // read the input again to check for bounces
    if (val == val2) {                 // make sure we got 2 consistant readings!
        if (val != buttonState) {          // the button state has changed!
            if (val == LOW) {                // check if the button is pressed
                Mode++;
                if (Mode >= NUM_MODES) {
                    Mode = 0;
                }
                modeChanged = true;
            }
        }
        buttonState = val;                 // save the new state in our variable
    }

    if (modeChanged) {
        modeChanged = false;

        // Now do whatever the lightMode indicates
        switch(Mode) {
        case 0:
            digitalWrite(ledPin1, LOW);
            digitalWrite(ledPin2, LOW);
            digitalWrite(ledPin3, LOW);
            digitalWrite(ledPin4, LOW);
            break;

        case 1:
            digitalWrite(ledPin1, HIGH);
            digitalWrite(ledPin2, HIGH);
            digitalWrite(ledPin3, HIGH);
            digitalWrite(ledPin4, HIGH);
            break;
/*
 * could make different light on/off combinations just be sure to alter NUM_MODES as well
        case 2:
            digitalWrite(led1Pin, LOW);
            digitalWrite(led2pin, HIGH);

        case 3:
            digitalWrite(led1Pin, HIGH);
            digitalWrite(led2pin, HIGH); */
        }
    }
}
