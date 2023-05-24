# deneyap-servo-arduino-library
Includes specific functions to drive servo motors by ESP32, ESP32-S2, ESP32-C3 and ESP32-S3 based development boards.

### SDK
List fo Functions

```c++
void attach(int pin, int channel, int freq, int resolution);
void write(int value);
```

### Example
This is an example.

```c++
#include <Deneyap_Servo.h>

Servo myservo;

void setup() {  
  myservo.attach(D9);
}

void loop() {
  myservo.write(60);
}
```
## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-servo-arduino-library/blob/master/LICENSE) file for license information.
