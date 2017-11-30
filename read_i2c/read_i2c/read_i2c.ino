#include "Wire.h"

#define gyroDat 0x1B
#define gyroDev 0x69
#define gyroPwr 0x2D
byte    gyroTemp_B[2];
byte    gyroMNO_B[6];
float   gyroTemp_f;
float   gyroMNO_f[3];
int     gyroTemp_i;
int     gyroMNO_i[3];

#define accelDat 0x32
#define accelDev 0x53
#define accelPwr 0x2D
byte    accelXYZ_B[6];
float   accelXYZ_f[3];
int     accelXYZ_i[3];

void setup () {
  Serial.begin(9600);
  Wire.begin();
  Wire.beginTransmission (accelDev);
  Wire.write (accelPwr);
  Wire.write (0);
  Wire.endTransmission();
  Wire.begin();
  Wire.beginTransmission (accelDev);
  Wire.write (accelPwr);
  Wire.write (16);
  Wire.endTransmission();
  Wire.begin();
  Wire.beginTransmission (accelDev);
  Wire.write (accelPwr);
  Wire.write (8);
  Wire.endTransmission();
}

void loop () {
  Wire.beginTransmission (accelDev);
  Wire.write (accelDat);
  Wire.endTransmission();
  Wire.beginTransmission(accelDev);
  Wire.requestFrom(accelDev, 6);
  for (int ii=0; ii < 6; ii++) {
    accelXYZ_B[ii] = Wire.read();
  }
  Wire.endTransmission();
  
  Wire.beginTransmission (gyroDev);
  Wire.write (gyroDat);
  Wire.endTransmission();
  Wire.beginTransmission(gyroDev);
  Wire.requestFrom(gyroDev, 8);
  for (int ii=0; ii < 8; ii++) {
    if (ii<2) {
      gyroTemp_B[ii] = Wire.read();
    }
    else {
      gyroMNO_B[ii] = Wire.read();
    }
  }
  Wire.endTransmission();
    
  accelXYZ_i[0] = (((int)accelXYZ_B[1]) << 8) | accelXYZ_B[0];   
  accelXYZ_i[1] = (((int)accelXYZ_B[3])<< 8) | accelXYZ_B[2];
  accelXYZ_i[2] = (((int)accelXYZ_B[5]) << 8) | accelXYZ_B[4];
    
  gyroTemp_i = (((int)accelXYZ_B[1]) << 8) | accelXYZ_B[0];   
  
  gyroMNO_i[0] = (((int)accelXYZ_B[3])<< 8) | accelXYZ_B[2];
  gyroMNO_i[1] = (((int)accelXYZ_B[5]) << 8) | accelXYZ_B[4];
  gyroMNO_i[2] = (((int)accelXYZ_B[7]) << 8) | accelXYZ_B[6];
  
  accelXYZ_f[0] = -1*accelXYZ_i[0]*9.80665/256;
  accelXYZ_f[1] = -1*accelXYZ_i[1]*9.80665/256;
  accelXYZ_f[2] = accelXYZ_i[2]*9.80665/256;
  
  gyroTemp_f = (gyroTemp_i+13200.0)/280;
  
  gyroMNO_f[0] = gyroMNO_i[0]/14.375;
  gyroMNO_f[1] = gyroMNO_i[1]/14.375;
  gyroMNO_f[2] = gyroMNO_i[2]/14.375;
  
  Serial.print("X: ");
  Serial.print(accelXYZ_f[0]);
  Serial.print("  Y: ");
  Serial.print(accelXYZ_f[1]);
  Serial.print("  Z: ");
  Serial.print(accelXYZ_f[2]);
  Serial.print("  T: ");
  Serial.print(gyroTemp_f);
  Serial.print("  M: ");
  Serial.print(gyroMNO_f[1]);
  Serial.print("  N: ");
  Serial.print(gyroMNO_f[2]);
  Serial.print("  O: ");
  Serial.print(gyroMNO_f[0]);
  Serial.println();
  delay(0);
}
