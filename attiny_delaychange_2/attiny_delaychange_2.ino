/*
  Shift Register Example
  Turning on the outputs of a 74HC595 using an array.
  Modified for ATTiny85

Hardware:
* 74HC595 shift register
* ATTiny85
* LEDs attached to each of the outputs of the shift register


d


*/
  int pinState;
int latchPin = 2;
//Pin connected to SH_CP (11) of 74HC595
int clockPin = 3;
int myDataPin;
int dataPin = 0;
int myClockPin;
int state = 255; 
byte data;
float degree;

class breather { // object definiton
public:
  int maxI, minI;
  int pin;
  int intensity;
  int meter;
  int brighter; // are we incrementing or decrementing 

  breather (int p, int m) { // constructor called when object created
    maxI = 255;
    minI = 0;
    intensity = 0;
    brighter = true;
    this->pin = p;      // 'this' refers to this particular instantiation
    this->meter = m;    // of the object
  }
    void setMaxMin (int M, int m) {  // if you set different ranges they fall out of sync nicely
    maxI = M;
    minI = m;
  }
  
   void breathe() {
    if (brighter)
     intensity = intensity + degree;
    else
       intensity = intensity - degree;

    if (intensity > maxI) {
         for (int j = 0; j < 8; j++ ) {
    //degree = map(analogRead(2), 0, 1023, 40,.01);
    //delaySpeed = map(analogRead(2), 0, 1023, 10, 150);
    //load the light sequence you want from array
   
    data =0;
    //random(255); //chaseArray[j];
    //ground latchPin and hold low for as long as you are transmitting
    
    digitalWrite(latchPin, 0);
    
    //move 'em out
    shiftOut(dataPin, clockPin, data);
    //return the latch pin high to signal chip that it
   
    //no longer needs to listen for information
    digitalWrite(latchPin, 1);
  
 
  
    
  }
      
     for(int b = 0; b > degree; b++){
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);

      state = 0;
      data = 0;
      delay(1);
     } 
     state = 255;
     // check upper bound
      intensity > maxI;
      brighter = !brighter; // change direction
    } 

    if (intensity < minI) {
     for(int z = 0; z < 1000; z++){
      //delay(1);
     } // check lower bound
      intensity < minI;
      brighter = !brighter; // change direction
    }
  
  
    analogWrite(pin, intensity);
    
    //delay(meter); 
  }
};
  
  breather *red = new breather(1, 1);
  
  
//Pin connected to ST_CP (12) of 74HC595
//int latchPin = 2;
//Pin connected to SH_CP (11) of 74HC595
//int clockPin = 3;
////Pin connected to DS (14) of 74HC595
//int dataPin = 0;
int delaySpeed;
//holders for information you're going to pass to shifting function
//byte data;
byte chaseArray[8];

void setup() {
  digitalWrite(1,INPUT);
  red->setMaxMin(255, 0);
  //set pins to output because they are addressed in the main loop
  pinMode(latchPin, OUTPUT);
  //  Serial.begin(9600);

  chaseArray[0] = 1;   //00000001
  chaseArray[1] = 2;   //00000010
  chaseArray[2] = 4;   //00000100
  chaseArray[3] = 8;   //00001000
  chaseArray[4] = 16;  //00010000
  chaseArray[5] = 32;  //00100000
  chaseArray[6] = 64;  //01000000
  chaseArray[7] = 128; //10000000

  //function that blinks all the LEDs
  //gets passed the number of blinks and the pause time

}

void loop() {
     
    
    
    


  for (int j = 0; j < 8; j++ ) {
    degree = map(analogRead(2), 0, 1023, 40,.01);
    delaySpeed = map(analogRead(2), 0, 1023, 10, 150);
    //load the light sequence you want from array
   
    data =random(state);
    //random(255); //chaseArray[j];
    //ground latchPin and hold low for as long as you are transmitting
    
    digitalWrite(latchPin, 0);
    
    //move 'em out
    shiftOut(dataPin, clockPin, data);
    //return the latch pin high to signal chip that it
   
    //no longer needs to listen for information
    digitalWrite(latchPin, 1);
  
    delay(delaySpeed);
    red->breathe();
    
  }
}



// the heart of the program
void shiftOut(int myDataPin, int myClockPin, byte myDataOut) {
  // This shifts 8 bits out MSB first,
  //on the rising edge of the clock,
  //clock idles low

  //internal function setup
  int i = 0;
  int pinState;
  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, OUTPUT);

  //clear everything out just in case to
  //prepare shift register for bit shifting
  digitalWrite(myDataPin, 0);
  digitalWrite(myClockPin, 0);

  //for each bit in the byte myDataOut
  //NOTICE THAT WE ARE COUNTING DOWN in our for loop
  //This means that 000001 or "1" will go through such
  //that it will be pin Q0 that lights.
  for (i = 7; i >= 0; i--)  {
    digitalWrite(myClockPin, 0);

    //if the value passed to myDataOut and a bitmask result
    // true then... so if we are at i=6 and our value is
    // %11010100 it would the code compares it to %01000000
    // and proceeds to set pinState to 1.
    if ( myDataOut & (1 << i) ) {
      pinState = 1;
    }
    else {
      pinState = 0;
    }

    //Sets the pin to HIGH or LOW depending on pinState
    digitalWrite(myDataPin, pinState);
    //register shifts bits on upstroke of clock pin
    digitalWrite(myClockPin, 1);
    //zero the data pin after shift to prevent bleed through
    digitalWrite(myDataPin, 0);
  }

  //stop shifting
  digitalWrite(myClockPin, 0);
}


//blinks the whole register based on the number of times you want to
//blink "n" and the pause between them "d"
//starts with a moment of darkness to make sure the first blink
//has its full visual effect.

