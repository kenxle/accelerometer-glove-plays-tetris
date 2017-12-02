#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#include <Wire.h>

//float angles[3]; // yaw pitch roll
float angles[6]; // yaw pitch roll

// Set the FreeSixIMU object
FreeSixIMU sixDOF = FreeSixIMU();

const int winlen = 30; //sparkfun
double xRaw[winlen];
double yRaw[winlen];
double zRaw[winlen];
double aRaw[winlen];
double bRaw[winlen];
double cRaw[winlen];

double xProc[winlen];
double yProc[winlen];
double zProc[winlen];
double aProc[winlen];
double bProc[winlen];
double cProc[winlen];

int loc = 0; // use this to loop through the array


void setup() { 
  Serial.begin(9600);
  Wire.begin();
  for (int i=0; i<winlen; i++){
    xRaw[i] = 0;
    yRaw[i] = 0;
    zRaw[i] = 0;

    xProc[i] = 0;
    yProc[i] = 0;
    zProc[i] = 0;
  }
//  delay(5);
  sixDOF.init(); //begin the IMU
//  delay(5);
}

void loop() { 
  
  
  sixDOF.getValues(angles);
  sixDOF.getEuler(&angles[3]);
//  getRawValues

  xRaw[loc] = angles[0];
  yRaw[loc] = angles[1];
  zRaw[loc] = angles[2];
  aRaw[loc] = angles[3];
  bRaw[loc] = angles[4];
  cRaw[loc] = angles[5];
  
  demean(xRaw, xProc);
  demean(yRaw, yProc);
  demean(zRaw, zProc);
  demean(aRaw, aProc);
  demean(bRaw, bProc);
  demean(cRaw, cProc);
  expSmooth(xProc, 0.4);
  expSmooth(yProc, 0.4);
  expSmooth(zProc, 0.4);
  expSmooth(aProc, 0.4);
  expSmooth(bProc, 0.4);
  expSmooth(cProc, 0.4);
  
//  expSmooth(xProc, 0.4);
//  expSmooth(yProc, 0.4);
//  expSmooth(zProc, 0.4);

  Serial.print(xProc[loc]);
  Serial.print(" | ");  
  Serial.print(yProc[loc]);
  Serial.print(" | ");
  Serial.print(zProc[loc]);
  Serial.print(" | ");
  Serial.print(aProc[loc]);
  Serial.print(" | ");
  Serial.print(bProc[loc]);
  Serial.print(" | ");
  Serial.println(cProc[loc]);
  ///
//  Serial.print(xRaw[loc]);
//  Serial.print(" | ");  
//  Serial.print(yRaw[loc]);
//  Serial.print(" | ");
//  Serial.println(zRaw[loc]);
  
  if(loc == winlen-1){
    loc = 0;
  }else{
    loc++;
  }
//  delay(100); 
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
