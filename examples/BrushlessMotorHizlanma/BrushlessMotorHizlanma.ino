/*
*   Brushless Modor Hız Kontrol örneği, 
*   D9 pinine bağlanan Brushless Motorun 0-255 hız değerinde ESC hız kontrolcüsü ile hızlanma ve yavaşlama örneğidir. 
*/
#include <Deneyap_Servo.h>  // Deneyap Servo kütüphanesi eklenmesi

ESC esc;  // ESC için class tanımlanması

void setup() {
  Serial.begin(115200);
  esc.attach(D9);  // ESC nin D9 pinine bağlanması   /*attach(pin, channel=0, freq=50, resolution=12) olarak belirlenmiştir.
                   // Kullandığınız motora göre değiştirebilirsiniz */
  delay(3000);
  Serial.println("ESC Kalibrasyonu aktif");
  esc.write(255);  // ESC hız kontrolcüsü yardımıyla bruhless motorun arm edilmesi için ilk olarak maximum,
                   // daha sonra minimum değer gönderilerek kalibre edilir.
  Serial.println("ESC dutycyle max");
  delay(2000);
  esc.write(0);
  Serial.println("ESC dutycyle min");
  delay(6500);
  Serial.println("ESC Kalibre Edildi");
}

void loop() {
  for (int pos = 0; pos <= 255; pos += 1) {  // 0'dan 255'e 1 adım ile hızlanması
    esc.write(pos);
    Serial.println(pos);
    delay(200);
  }
  for (int pos = 255; pos >= 0; pos -= 1) {  // 255'den 0'a 1 adım ile yavaşlaması
    esc.write(pos);
    Serial.println(pos);
    delay(200);
  }
}