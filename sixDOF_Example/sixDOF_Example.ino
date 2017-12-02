#include <FreeSixIMU.h>
#include <FIMU_ADXL345.h>
#include <FIMU_ITG3200.h>

#include <RFduinoBLE.h>
#include <Wire.h>

float angles[3]; // yaw pitch roll

// Set the FreeSixIMU object
FreeSixIMU sixDOF = FreeSixIMU();

void setup() { 
  Serial.begin(9600);
  Wire.begin();
  
  //delay(5);
  sixDOF.init(); //begin the IMU
//  RFduinoBLE.advertisementData = "temp";

  // start the BLE stack
//  RFduinoBLE.begin();
  Serial.println("Starting..");
}

void loop() { 
//  RFduino_ULPDelay( SECONDS(1) );
  sixDOF.getEuler(angles);
  
  Serial.print(angles[0]);
  Serial.print(" | ");  
  Serial.print(angles[1]);
  Serial.print(" | ");
  Serial.println(angles[2]);
//  RFduinoBLE.sendFloat(angles[0]);
//  delay(100); 
}

