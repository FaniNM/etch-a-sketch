
const int VRxPin= A0; //VRx pin connected to arduino pin A0
const int VRyPin= A1; //VRy pin connected to arduino in A1
const int SwButtonPin= 8; //SW pin connected to arduino pin D8
const int R = 2;
int pressed= 0; //this variable will determine whether joystick has been pressed down (selected)
int x= 0;//this variable will hold the X-coordinate value
int y= 0; //this variable will hold the Y-coordinate value
int reset = 0; // this variable will hold the reset value
String string_x;
String string_y;

unsigned long targetTime = 0;
const unsigned long interval = 1000;


void setup() {
  pinMode(SwButtonPin, INPUT);//sets the SW switch as input
  pinMode(VRxPin, INPUT);
  pinMode(VRyPin, INPUT);
  pinMode(R, INPUT);
  Serial.begin(115200);//sets the baud rate
}


void loop() {

  
  if (millis() >= targetTime) {

    targetTime = millis() + interval;

    reset = digitalRead(R);

    if (reset == LOW) { //If button is pressed, reset
      pressed= digitalRead(SwButtonPin);//reads whether joystick has been pressed down (selected) or not
      x= analogRead(VRxPin);//reads the X-coordinate value
      y= analogRead(VRyPin);//reads the Y-coordinate value
      string_x = String(x);
      string_y =String(y);
      Serial.println(string_x + "," + string_y);
    } 
    
    else {
        Serial.println(String("rst"));
        x = 0;
        y = 0;
      }
    }

}


