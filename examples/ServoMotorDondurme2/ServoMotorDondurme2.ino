/*
*   ServoMotorDondurme2 örneği,
*   D9 pinine bağlanan servo motor 0-3000 ms aralığında 250 ms'lik adımlarla önce saat yönüne sonra saat yönünün tersine dönmektedir.
*     0 ms   0 derecedir.
*  1500 ms  90 derecedir.
*  3000 ms 180 derecedir.
*/
#include <Deneyap_Servo.h>  // Deneyap Servo kütüphanesi eklenmesi

Servo myservo;  // Servo sınıfında nesne tanımlanması

void setup() {
  myservo.attach(D9);  // Servo motorun D9 pinine bağlanması   /*attach(pin, channel=0, freq=50, resolution=12) olarak belirlenmiştir. Kullandığınız motora göre değiştirebilirsiniz */
}

void loop() {
  for (int pos = 0; pos <= 3000; pos += 250) {        // 0'dan 3000'e 250 aralıklarla artarak
    myservo.writeMicroseconds(pos);                   // servo motorun saat yönünde 250 ms aralıklarla dönmesi
    delay(1000);
  }
  for (int pos = 3000; pos >= 0; pos -= 250) {    // 3000'dan 0'a 250 aralıklarla azalarak
    myservo.writeMicroseconds(pos);               // servo motorun saat yönünün tersine 250 ms aralıklarla dönmesi
    delay(1000);
  }
}
