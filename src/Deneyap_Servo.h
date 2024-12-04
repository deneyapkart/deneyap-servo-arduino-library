/*
*****************************************************************************
@file         Deneyap_Servo.h
@mainpage     Deneyap Servo Arduino library header file
@version      v1.0.0
@date         October 20, 2022
@brief        This file contains all function prototypes and macros
              for servo motor Arduino library for Deneyap Development Boards
*****************************************************************************
*/
#ifndef _DENEYAPSERVO_H
#define _DENEYAPSERVO_H

#include <Arduino.h>

#define DELAYMS 2000

#define PWMFREQ 50
#define PWMCHANNEL 0
#define PWMRESOLUTION 12
#define FIRSTDUTY 0

#define SERVOMIN 0
#define SERVOMAX 180
#define DUTYCYLEMIN 100
#define DUTYCYLEMAX 500

#define SERVO360MIN 0
#define SERVO360MAX 360

#define ESCDUTYCYLEMIN 205
#define ESCDUTYCYLEMAX 409
#define ESCMIN 0
#define ESCMAX 255

class Servo {
public:
  void attach(int pin, int channel = PWMCHANNEL, int freq = PWMFREQ, int resolution = PWMRESOLUTION);
  void write(int value);
  void writeMicroseconds(int value);
  int read();
  int readMicroseconds();
private:
  int _channel;
};

class ESC {
public:
  void attach(int pin, int channel = PWMCHANNEL, int freq = PWMFREQ, int resolution = PWMRESOLUTION);
  void write(int value);
private:
  int _channel;
};

/*class Servo360 {
public:
    void attach(int pin, int channel = PWMCHANNEL360, int freq = PWMFREQ360, int resolution = PWMRESOLUTION);
    void write(int value);
    void writeMicroseconds(int value);
    int read();
    int readMicroseconds();
private:
    int _360channel;
};*/
#endif /* _DENEYAPSERVO_H_ */
