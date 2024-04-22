#include <Wire.h> 
#include <MPU6050.h> 
#include <Servo.h> 

// Servos
Servo Servo_pitch1; 
Servo Servo_pitch2; 
Servo Servo_roll1; 
Servo Servo_roll2; 

// MPU
MPU6050 mpu; 

  
// Timers 
unsigned long timer = 0; 
float timeStep = 0.01; 

// Pitch, Roll and Yaw values 

float pitch = 0; 
float roll = 0; 
float yaw = 0; 

  

void setup()  
{ 
  Serial.begin(115200); 

  //Servos pins
  Servo_pitch1.attach(8); 
  Servo_pitch2.attach(9); 
  Servo_roll1.attach(10); 
  Servo_roll2.attach(11); 

  // Initialize MPU6050 

  while(!mpu.begin(MPU6050_SCALE_2000DPS, MPU6050_RANGE_2G)) 

  { 
    Serial.println("Could not find a valid MPU6050 sensor, check wiring!"); 
    delay(500); 
  } 

  // Calibrate gyroscope. The calibration must be at rest. 
  mpu.calibrateGyro(); 

  // Set threshold sensivty. Default 3. 
  mpu.setThreshold(3); 

  // Servos Initialisation
  Servo_pitch1.write(0); 
  Servo_pitch2.write(0); 
  Servo_roll1.write(0); 
  Servo_roll2.write(0); 
} 

  

void loop() 
{ 

  timer = millis(); 

  // Read normalized values 
  Vector norm = mpu.readNormalizeGyro(); 

  // Calculate Pitch and Roll
  pitch = pitch + norm.YAxis * timeStep; 
  roll = roll + norm.XAxis * timeStep; 

  // Output raw 
  Serial.print(" Pitch = "); 
  Serial.print(pitch); 
  Serial.print(" Roll = "); 
  Serial.print(roll);   
  Serial.print(" Yaw = "); 
  Serial.println(yaw); 

  // Servos commands
  Servo_pitch1.write(int(pitch)/2); 
  Servo_pitch2.write(int(pitch)/2); 
  Servo_roll1.write(int(roll)/2); 
  Servo_roll2.write(int(roll)/2); 

  // Wait to full timeStep period 
  delay((timeStep*1000) - (millis() - timer)); 

} 
