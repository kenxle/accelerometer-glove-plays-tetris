/*
  ADXL3xx

  Reads an Analog Devices ADXL3xx accelerometer and communicates the
  acceleration to the computer. The pins used are designed to be easily
  compatible with the breakout boards from SparkFun, available from:
  http://www.sparkfun.com/commerce/categories.php?c=80

  The circuit:
  - analog 0: accelerometer self test
  - analog 1: z-axis
  - analog 2: y-axis
  - analog 3: x-axis
  - analog 4: ground
  - analog 5: vcc

  created 2 Jul 2008
  by David A. Mellis
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ADXL3xx
*/

#include <Wire.h>

// these constants describe the pins. They won't change:
//const int groundpin = 18;             // analog input pin 4 -- ground
//const int powerpin = 19;              // analog input pin 5 -- voltage
//const int xpin = A3;                  // x-axis of the accelerometer
//const int ypin = A2;                  // y-axis
//const int zpin = A1;                  // z-axis (only on 3-axis models)

//const int xpin = A3;                  // x-axis of the accelerometer
//const int ypin = A4;                  // y-axis
//const int zpin = A5;                 // x-axis of the accelerometer
const int sDa = A4;                  // I2C data
const int sCl = A5;                  // I2C clock
//const int apin = A6;    
const int xpin = 0;                  // x-axis of the accelerometer
const int ypin = 1;                  // y-axis
const int zpin = 2;                  // z-axis (only on 3-axis models)
               

//const int winlen = 20;
const int winlen = 30; //adafruit
double xRaw[winlen];
double yRaw[winlen];
double zRaw[winlen];
//double aRaw[winlen];
double xProc[winlen];
double yProc[winlen];
double zProc[winlen];
//double aProc[winlen];

int loc = 0; // use this to loop through the array

void setup() {
  // initialize the serial communications:
  Wire.begin();
  Serial.begin(9600);
  for (int i=0; i<winlen; i++){
    xRaw[i] = 0;
    yRaw[i] = 0;
    zRaw[i] = 0;
//    aRaw[i] = 0;
    xProc[i] = 0;
    yProc[i] = 0;
    zProc[i] = 0;
//    aProc[i] = 0;
  }
  pinMode(xpin, INPUT);
  pinMode(ypin, INPUT);
  pinMode(zpin, INPUT);
//  pinMode(apin, INPUT);
  // Provide ground and power by using the analog inputs as normal digital pins.
  // This makes it possible to directly connect the breakout board to the
  // Arduino. If you use the normal 5V and GND pins on the Arduino,
  // you can remove these lines.
//  pinMode(groundpin, OUTPUT);
//  pinMode(powerpin, OUTPUT);
//  digitalWrite(groundpin, LOW);
//  digitalWrite(powerpin, HIGH);
}

void loop() {
//
  xRaw[loc] = analogRead(xpin);
  yRaw[loc] = analogRead(ypin);
  zRaw[loc] = analogRead(zpin);
//  aRaw[loc] = analogRead(apin);

  
//  xRaw[loc] = digitalRead(xpin);
//  yRaw[loc] = digitalRead(ypin);
//  zRaw[loc] = digitalRead(zpin);
//  aRaw[loc] = digitalRead(apin);

  // sparkfun acc LSM303
//  demean(xRaw, xProc);
//  demean(yRaw, yProc);
//  demean(zRaw, zProc);
//  demean(aRaw, aProc);
//  normalize(xProc);
//  normalize(yProc);
//  normalize(zProc);
//  normalize(aProc);
//  expSmooth(xProc, 0.3);
//  expSmooth(yProc, 0.3);
//  expSmooth(zProc, 0.3);
//  expSmooth(aProc, 0.3);
  
//  meanSmooth(xProc, 3);
//  meanSmooth(yProc, 3);
//  meanSmooth(zProc, 3);
//  meanSmooth(aProc, 3);
//  threshholdFilter(xProc, 1.5);
//  threshholdFilter(yProc, 1.5);
//  threshholdFilter(zProc, 1.5);
//  threshholdFilter(aProc, 1.5);
  
  //adafruit accelerometer  
  demean(xRaw, xProc);
  demean(yRaw, yProc);
  demean(zRaw, zProc);
  expSmooth(xProc, 0.4);
  expSmooth(yProc, 0.4);
  expSmooth(zProc, 0.4);
  expSmooth(xProc, 0.2);
  expSmooth(yProc, 0.2);
  expSmooth(zProc, 0.2);
  
  expSmooth(xProc, 0.4);
  expSmooth(yProc, 0.4);
  expSmooth(zProc, 0.4);
  expSmooth(xProc, 0.4);
  expSmooth(yProc, 0.4);
  expSmooth(zProc, 0.4);
//  meanSmooth(xProc, 15);
//  meanSmooth(yProc, 15);
//  meanSmooth(zProc, 15);
//  meanSmooth(xProc, 4);
//  meanSmooth(yProc, 4);
//  meanSmooth(zProc, 4);
  
  threshholdFilter(xProc, 3);
  threshholdFilter(yProc, 3);
  threshholdFilter(zProc, 3);
  
  
  // print the sensor values:
  Serial.print(xProc[loc]);
  // print a tab between values:
  Serial.print("\t");
  
//  Serial.print(xRaw[loc]);

  Serial.print(yProc[loc]);
  // print a tab between values:
  Serial.print("\t");
  Serial.print(zProc[loc]);
  
  Serial.print("\t");
//  Serial.print(aProc[loc]);
  //
//    Serial.print(xRaw[loc]);
//  // print a tab between values:
//  Serial.print("\t");
//  
////  Serial.print(xRaw[loc]);
//
//  Serial.print(yRaw[loc]);
//  // print a tab between values:
//  Serial.print("\t");
//  Serial.print(zRaw[loc]);

  Serial.println();

  if(loc == winlen-1){
    loc = 0;
  }else{
    loc++;
  }
  // delay before next reading:
//  delay(10);
}

void addToArray(double val){
  // instead of trying to move things around inside the array, 
  // keep a pointer that knows what next value to overwrite
}

// starts with the raw array and puts the data into the processed array
void demean(double arr[], double processed[]){ 
  double sum = 0;
  for (int i=0; i<winlen; i++){
    sum += arr[i];
  }
  double mean = sum/winlen;
  for (int i=0; i<winlen; i++){
    processed[i] = arr[i] - mean;
  }
}

void normalize(double arr[]){
  double amax = 0;
  for (int i = 0; i<winlen; i++){
    if (abs(arr[i]) > amax) 
      amax = abs(arr[i]);
  }
  if(amax >1){
  for (int i = 0; i<winlen; i++){
    arr[i] = arr[i]/amax;
  }
  }
}

// processes the existing array
void expSmooth(double arr[], double sf){
  // we want to start at the oldest value, which is loc+1
  int cur;
  if(loc == winlen-1){
    cur = 0;
  }else{
    cur = loc+1;
  }
  int next1 = cur; //just initialize
  int back1 = cur;
  for (int i=0; i<winlen; i++){
    //
    if(cur == winlen-1) next1 = 0;
    else next1 = cur+1;
    if(cur == 0) back1 = winlen-1;
    else back1 = cur-1;
     
    if(i == 0){} // s.0 = x.0
    else{
      // s.t = ax.t + (1-a)s.t-1 //https://en.wikipedia.org/wiki/Exponential_smoothing
      arr[cur] = sf * arr[cur] + (1-sf) * arr[back1];
    }
    cur = next1;
  }
}

// 
void meanSmooth(double arr[], int lookback){
  
  // we want to start at the oldest value+lookback, so we can back-average
  int cur = loc + lookback;
  if(cur > winlen-1){
    cur = (cur - winlen);
  }else{
    cur = loc+1;
  }
  double sum = 0;
  for (int i=0; i<lookback; i++){
    int ind = cur-i < 0 ? (cur-i) + winlen : cur-i;
    sum += arr[ind];
  }
  arr[cur] = sum/lookback;


  int next1 = cur; //just initialize
  int back1 = cur;
  for (int i=0; i<winlen-lookback-1; i++){
    //work out the circular indices
    if(cur == 0) back1 = winlen-1;
    else back1 = cur-1;
    if(cur == winlen-1) next1 = 0;
    else next1 = cur+1;
    int drop = cur-(lookback-1) < 0 ? cur-(lookback-1) + winlen : cur-(lookback-1);
    // add the next, drop the last
    arr[cur] = arr[back1] + (arr[cur]/lookback) - (arr[drop]/lookback);
   
    cur = next1;
  }
}

void threshholdFilter(double arr[], double f){
  for (int i=0; i<winlen; i++){
    if(abs(arr[i]) < f){
      arr[i] = 0;
    }
  }
}

