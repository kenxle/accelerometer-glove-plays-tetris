#include <Wire.h>
const int I2C_address = 0b1101010;
long a_X, a_Y, a_Z;
float g_X, g_Y, g_Z;

long gyro_X, gyro_Y, gyro_Z;
float rot_X, rot_Y, rot_Z;

void setup() {
  Serial.begin(9600);
  Wire.begin();
  setupFIS();

}

void loop() {
  recordAccelRegisters();
  recordGyroRegisters();
  printData();
//  delay(800);

}

void setupFIS(){
  Wire.beginTransmission(I2C_address);
  Wire.write(0x02);
  Wire.write(0b00000000);
  Wire.endTransmission(true);

  Wire.beginTransmission(I2C_address);
  Wire.write(0x08);
  Wire.write(0b10000011);
  Wire.endTransmission(true);

  Wire.beginTransmission(I2C_address);
  Wire.write(0x04);
  Wire.write(0b00000000);
  Wire.endTransmission(true);

  Wire.beginTransmission(I2C_address);
  Wire.write(0x03);
  Wire.write(0b00000000);
  Wire.endTransmission(true);

  Wire.beginTransmission(I2C_address);
  Wire.write(0x05);
  Wire.write(0b00000000);
  Wire.endTransmission(true);

  Wire.beginTransmission(I2C_address);
  Wire.write(0x06);
  Wire.write(0b00000000);
  Wire.endTransmission(true);

  Wire.beginTransmission(I2C_address);
  Wire.write(0x07);
  Wire.write(0b00000000);
  Wire.endTransmission(true);
}

void recordAccelRegisters(){
  Wire.beginTransmission(I2C_address);
  Wire.write(0x19);
  Wire.endTransmission(false);
  Wire.requestFrom(I2C_address,6,true);
  //while(Wire.available()<6);
  a_X = Wire.read()<<8|Wire.read();
  a_Y = Wire.read()<<8|Wire.read();
  a_Z = Wire.read()<<8|Wire.read();
  processAccelData();
}

void processAccelData(){
  g_X = a_X/16384.0;
  g_Y = a_Y/16384.0;
  g_Z= a_Z/16384.0;
}

void recordGyroRegisters(){
  Wire.beginTransmission(I2C_address);
  Wire.write(0x1F);
  Wire.endTransmission(false);
  Wire.requestFrom(I2C_address,6,true);
  //while(Wire.available()<6);
  gyro_X = Wire.read()<<8|Wire.read();
  gyro_Y = Wire.read()<<8|Wire.read();
  gyro_Z = Wire.read()<<8|Wire.read();
  processGyroData();
}

void processGyroData(){
  rot_X = gyro_X/1024.0;
  rot_Y = gyro_Y/1024.0;
  rot_Z= gyro_Z/1024.0;
}

void printData(){
  Serial.print("Gyro(deg)");
  Serial.print(" X=");
  Serial.print(rot_X);
  Serial.print(" Y=");
  Serial.print(rot_Y);
  Serial.print(" Z=");
  Serial.print(rot_Z);

  Serial.print("   Accel(g)");
  Serial.print(" X=");
  Serial.print(g_X);
  Serial.print(" Y=");
  Serial.print(g_Y);
  Serial.print(" Z=");
  Serial.println(g_Z);
} 
