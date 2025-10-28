# Arduino Keypad Mesafe Ölçümü

Bu proje, **HC-SR04 mesafe sensörü** ve **4x3 keypad** kullanarak mesafe ölçümü yapar.  
Keypad’den tuşa basıldığında mesafe sensöründen alınan veri, belirlenen aralıkta ise yeşil LED, değilse kırmızı LED yanar.

## Kullanılan Malzemeler
- Arduino Uno
- HC-SR04 Mesafe Sensörü
- 4x3 Keypad
- 2 LED (yeşil ve kırmızı)
- 2 x 330 Ohm direnç

## Çalışma Prensibi
1. Keypad’den sayı girilir.  
2. Mesafe sensöründen veri alınır.  
3. Girilen tuş ve ölçülen mesafe aralıkları kontrol edilir.  
4. Aralıkta ise yeşil LED, değilse kırmızı LED yanar.  
