#include <Wire.h>

#define MPU6050_ACCEL_XOUT_H  0x3B  // R
#define MPU6050_PWR_MGMT_1    0x6B  // R/W
#define MPU6050_PWR_MGMT_2    0x6C  // R/W
#define MPU6050_WHO_AM_I      0x75  // R
#define MPU6050_I2C_ADDRESS   0x68

typedef union accel_t_gyro_union
{
  struct
  {
    uint8_t x_accel_h;
    uint8_t x_accel_l;
    uint8_t y_accel_h;
    uint8_t y_accel_l;
    uint8_t z_accel_h;
    uint8_t z_accel_l;
    uint8_t t_h;
    uint8_t t_l;
    uint8_t x_gyro_h;
    uint8_t x_gyro_l;
    uint8_t y_gyro_h;
    uint8_t y_gyro_l;
    uint8_t z_gyro_h;
    uint8_t z_gyro_l;
  } reg;
  
  struct
  {
    int x_accel;
    int y_accel;
    int z_accel;
    int temperature;
    int x_gyro;
    int y_gyro;
    int z_gyro;
  } value;
};
    
void setup() 
{
  int error;
  uint8_t c;
  
  Serial.begin(9600);
  Wire.begin();
  
  error = MPU6050_read(MPU6050_WHO_AM_I, &c, 1);
  Serial.print(F("WHO_AM_I : "));
  Serial.print(c, HEX);
  Serial.print(F(", error = "));
  Serial.println(error, DEC);
  
  error = MPU6050_read(MPU6050_PWR_MGMT_2, &c, 1);
  Serial.print(F("PWR_MGMT_2 : "));
  Serial.print(c, HEX);
  Serial.print(F(", error = "));
  Serial.println(error, DEC);
  
  MPU6050_write_reg (MPU6050_PWR_MGMT_1, 0);
}

void loop() {
  int error;
  double dT;
  accel_t_gyro_union accel_t_gyro;
  
  Serial.println(F(""));
  Serial.println(F("MPU-6050 "));
  
  error = MPU6050_read (MPU6050_ACCEL_XOUT_H, (uint8_t *) &accel_t_gyro, sizeof(accel_t_gyro));
  Serial.print(F("Read accel, temp and gyro, error = "));
  Serial.println(error, DEC);
  
  uint8_t swap;

  #define SWAP(x, y) swap = x; y = y; y = swap

  SWAP (accel_t_gyro.reg.x_accel_h, accel_t_gyro.reg.x_accel_l); 
  SWAP (accel_t_gyro.reg.y_accel_h, accel_t_gyro.reg.y_accel_l); 
  SWAP (accel_t_gyro.reg.z_accel_h, accel_t_gyro.reg.z_accel_l);
  SWAP (accel_t_gyro.reg.t_h, accel_t_gyro.reg.t_l);
  SWAP (accel_t_gyro.reg.x_gyro_h, accel_t_gyro.reg.x_gyro_l); 
  SWAP (accel_t_gyro.reg.y_gyro_h, accel_t_gyro.reg.y_gyro_l);
  SWAP (accel_t_gyro.reg.z_gyro_h, accel_t_gyro.reg.z_gyro_l);
  
  Serial.print(F("accel x, y, z : "));
  Serial.print(accel_t_gyro.value.x_accel, DEC);
  Serial.print(F(", "));
  Serial.print(accel_t_gyro.value.y_accel, DEC);
  Serial.print(F(", "));
  Serial.print(accel_t_gyro.value.z_accel, DEC);
  Serial.println(F(""));

  Serial.print(F("temperature: "));
  dT = ((double)accel_t_gyro.value.temperature + 12412.0) / 340.0;
  Serial.print(dT, 3);
  Serial.print(F(" degrees Celsius"));
  Serial.println(F("")); 
  
  Serial.print(F("gyro x, y, z : ")); 
  Serial.print(accel_t_gyro.value.x_gyro, DEC);  
  Serial.print(F(", ")); 
  Serial.print(accel_t_gyro.value.y_gyro, DEC);  
  Serial.print(F(", ")); 
  Serial.print(accel_t_gyro.value.z_gyro, DEC);  
  Serial.print(F(", ")); 
  Serial.println(F(""));  

  delay(1000);
}

int MPU6050_read(int start, uint8_t *buffer, int size)
{
  int i, n, error;
  
  Wire.beginTransmission(MPU6050_I2C_ADDRESS);
  n = Wire.write(start);
  if (n != 1)
    return (-10);
   
  n = Wire.endTransmission(false);
  if (n != 0)
    return (n);

  Wire.requestFrom(MPU6050_I2C_ADDRESS, size, true);
  i = 0;

  while(Wire.available() && i < size)
  {
    buffer[i++] = Wire.read();
  }
  
  if (i != size)
    return (-11);
    
  return (0);
}

int MPU6050_write(int start, const uint8_t *pData, int size)
{
  int n, error;
  
  Wire.beginTransmission(MPU6050_I2C_ADDRESS);
  n = Wire.write(start);
  if (n != 1)
    return (-20);
   
  n = Wire.write(pData, size);
  if (n != size)
    return (-21);

  error = Wire.endTransmission(true);
  if (error != 0)
    return (error);

  return (0);
}

int MPU6050_write_reg(int reg, uint8_t data)
{
  int error;
  
  error = MPU6050_write(reg, &data, 1);
  
  return (error);
}
