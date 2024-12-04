/*
*************************************************************************************************
@file         Deneyap_Servo.cpp
@mainpage     Deneyap Servo Arduino library source file
@maintainer   RFtek Electronics <techsupport@rftek.com.tr>
@version      v1.0.0
@date         October 20, 2022
@brief        Includes functions to drive servo motor for Deneyap Development Boards
*************************************************************************************************
*/

#include "Deneyap_Servo.h"

/**
 * @brief   attaches the given pin, channel, freq, resolution
 * @param   @pin : servo pin
 *          @channel : channel of pwm
 *          @freq : frequency of pwm
 *          @resolution : range is 1-14 bits (1-20 bits for ESP32)
 * @retval  None
**/

void Servo::attach(int pin, int channel, int freq, int resolution) {
  _channel = channel;
  if(channel > 15) channel = 15;
  ledcSetup(_channel, freq, resolution);
  ledcAttachPin(pin, channel);
  ledcWrite(_channel, FIRSTDUTY);
}

/**
 * @brief   writes servo value 0-SERVOMAX as degree
 * @param   @value: servo value 0-SERVOMAX as degree
 * @retval  None
**/

void Servo::write(int value) {
  if(value < SERVOMIN) value = SERVOMIN;
  if(value > SERVOMAX) value = SERVOMAX;
  int servoValue = (value - SERVOMIN) * (DUTYCYLEMAX - DUTYCYLEMIN) / (SERVOMAX - SERVOMIN) + DUTYCYLEMIN; // mapping to SERVOMIN-SERVOMAX values from DUTYCYLEMIN-DUTYCYLEMAX values
  ledcWrite(_channel, servoValue); // _channel select servoValue(duty) to be set for selected channel
  //delay(DELAYMS);
}

void Servo::writeMicroseconds(int value) {
  if (value < 0) value = 0;
  if (value > 3000) value = 3000;
  value = map(value, 0, 3000, SERVOMIN, SERVOMAX);
  this->write(value);
}

void ESC::attach(int pin, int channel, int freq, int resolution) {
  _channel = channel;
  if(channel > 15) channel = 15;
  ledcSetup(_channel, freq, resolution);
  ledcAttachPin(pin, channel);
  ledcWrite(_channel, FIRSTDUTY);
}

int Servo::read() {
  int dutyCycle = ledcRead(_channel);
  int newDutyCycle = map(dutyCycle, DUTYCYLEMIN, DUTYCYLEMAX, SERVOMIN, SERVOMAX) + 1;
  if(newDutyCycle % 45 == 0) newDutyCycle--;
  return map(newDutyCycle, SERVOMIN, SERVOMAX, 0, 180);
}

int Servo::readMicroseconds() { 
  this->read();
}
void ESC::write(int value) {
  if(value < ESCMIN) value = ESCMIN;
  if(value > ESCMAX) value = ESCMAX;
  int escValue = (value - ESCMIN) * (ESCDUTYCYLEMAX - ESCDUTYCYLEMIN) / (ESCMAX - ESCMIN) + ESCDUTYCYLEMIN; // mapping to SERVOMIN-SERVOMAX values from DUTYCYLEMIN-DUTYCYLEMAX values
  ledcWrite(_channel, escValue); // _channel select servoValue(duty) to be set for selected channel
  //delay(DELAYMS);
}

/*void Servo360::attach(int pin, int channel, int freq, int resolution) {
  _360channel = channel;
  if(channel > 15) channel = 15;
  ledcSetup(_360channel, freq, resolution);
  ledcAttachPin(pin, channel);
  ledcWrite(_360channel, FIRSTDUTY);
}

void Servo360::write(int value) {
	if (value < SERVO360MIN) value = SERVO360MIN;
	else if (value > SERVO360MAX) value = SERVO360MAX;
	int servoValue = (value - SERVO360MIN) * (DUTYCYLEMAX - DUTYCYLEMIN) / (SERVO360MAX - SERVO360MIN) + DUTYCYLEMIN; // mapping to SERVOMIN-SERVOMAX values from DUTYCYLEMIN-DUTYCYLEMAX values
	ledcWrite(_channel, servoValue); // _channel select servoValue(duty) to be set for selected channel
	//delay(DELAYMS);
}

void Servo360::writeMicroseconds(int value) {
	if (value < 0) value = 0;
	else if (value > 3000) value = 3000;
	value = map(value, 0, 3000, SERVO360MIN, SERVO360MAX);
	this->write(value);
}

int Servo360::read() {
	int dutyCycle = ledcRead(_360channel);
	int newDutyCycle = map(dutyCycle, DUTYCYLEMIN, DUTYCYLEMAX, SERVO360MIN, SERVO360MAX) + 1;
	if (newDutyCycle % 45 == 0) newDutyCycle--;
	return map(newDutyCycle, SERVO360MIN, SERVO360MAX, 0, 180);
}

int Servo360::readMicroseconds() {
	this->read();
}*/
