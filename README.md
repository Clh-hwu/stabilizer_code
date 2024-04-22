# Stabilizer Robot Control Code

This code is designed to control a stabilizer robot using an Arduino board, MPU6050 sensor for motion detection, and servo motors for stabilization. Below is a breakdown of the code structure and its functionality:

### Libraries
- `Wire.h`: Library for I2C communication.
- `MPU6050.h`: Library for interfacing with the MPU6050 sensor.
- `Servo.h`: Library for controlling servo motors.

### Servo Motors Initialization
- Four servo motors are initialized for controlling pitch and roll stabilization:
  - `Servo_pitch1`, `Servo_pitch2`: For controlling pitch stabilization.
  - `Servo_roll1`, `Servo_roll2`: For controlling roll stabilization.

### MPU6050 Initialization
- The MPU6050 sensor is initialized for reading gyroscope data.
- The gyroscope is calibrated, and sensitivity thresholds are set.

### Timers
- `timer`: Stores the current time for timing purposes.
- `timeStep`: Time step for calculations, set to 0.01 seconds.

### Pitch, Roll, and Yaw Values
- Float variables (`pitch`, `roll`, `yaw`) store the current orientation angles of the robot.

### `setup()` Function
- Initializes serial communication.
- Attaches servo motors to their respective pins.
- Initializes the MPU6050 sensor.
- Calibrates the gyroscope and sets sensitivity thresholds.
- Sets initial positions for servo motors.

### `loop()` Function
- Continuously loops to read sensor data and control servo motors.
- Reads gyroscope data to calculate pitch and roll angles.
- Prints the pitch, roll, and yaw values to the serial monitor.
- Adjusts servo motor positions based on pitch and roll angles for stabilization.
- Delays for the remaining time step to ensure consistent loop execution.

This code provides a basic framework for stabilizing a robot using gyroscopic data from the MPU6050 sensor and servo motors. Further enhancements can be made to incorporate additional sensors, implement advanced control algorithms, or optimize servo motor control for specific stabilization requirements.
