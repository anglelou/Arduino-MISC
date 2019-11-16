
// Button Switch for Light

// Turns on and off a light emitting diode (LED) connected to digit pin
// When button is pressed

int pinButton = 8;
int LED = 9;
int stateLED = LOW;
int stateButton;
int previous = LOW;
long time = 0;
long debounce = 200;

void setup() {
  // put your setup code here, to run once:

  pinMode (pinButton, INPUT);
  pinMode (LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  
  stateButton = digitalRead (pinButton);
  
  if(stateButton == HIGH && previous == LOW && millis() - time > debounce) 
  {
    if(stateLED == HIGH){
      stateLED = LOW;
    }
    else{
      stateLED = HIGH;
    }
    time = millis();
  }

  digitalWrite(LED, stateLED);
  previous == stateButton;
}
