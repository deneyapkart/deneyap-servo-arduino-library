# deneyap-servo-arduino-library
Includes specific functions to drive servo motors by ESP32, ESP32-S2, ESP32-C3 and ESP32-S3 based development boards.

### SDK
List fo Functions

```c++
void attach(int pin, int channel, int freq, int resolution);
void write(int value);
void writeMicroseconds(int value);
int read();
int readMicroseconds();
```

## :bookmark_tabs:License Information
Please review the [LICENSE](https://github.com/deneyapkart/deneyap-servo-arduino-library/blob/master/LICENSE) file for license information.
