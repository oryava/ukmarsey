#ifndef PUBLIC_H
#define PUBLIC_H

// provided by interpreter.cpp
void interpreter();
void init_stored_parameters();
float get_float_param(int param_index);
bool get_bool_param(int param_index);

//
// provided by systick.cpp
//
void setupSystick();
void print_bat();
float get_BatteryVolts();
int readFunctionSwitch();

//
// provided by wall_sensors.cpp
//
//void wall_sensors_setup();
//void print_wall_sensors();
//void updateWallSensor();  // usually called from sysTick interrupt

// provided by sensors_control.cpp
void sensors_control_setup();
void print_sensors_control(char mode);
void update_sensors_control();
extern char emitter_on;

// provided by distance-moved.cpp
void setupEncoders();
void print_encoder_setup();
void zero_encoders();
void print_encoders();
extern volatile int32_t encoderLeftCount;
extern volatile int32_t encoderRightCount;

// provided by motor_control.cpp
void setMotorVolts(float left, float right);
void setRightMotorVolts(float volts);
void setLeftMotorVolts(float volts);
void setLeftMotorPWM(int pwm);
void setRightMotorPWM(int pwm);
void motorSetup();

// internal use
#define MEASURE_TIMING 0

typedef unsigned time_measure_t;
#if MEASURE_TIMING
#define TIME_START(START_VARIABLE) START_VARIABLE = micros();
#define TIME_END(START_VARIABLE, END_VARIABLE) END_VARIABLE = micros() - START_VARIABLE;
#define TIME_DEFINE_VARIABLE(VARIABLE) time_measure_t VARIABLE;
#else
#define TIME_START(START_VARIABLE)
#define TIME_END(START_VARIABLE, END_VARIABLE)
#define TIME_DEFINE_VARIABLE(VARIABLE) 
#endif

// Other constants
const int floating_decimal_places = 3;


#endif
