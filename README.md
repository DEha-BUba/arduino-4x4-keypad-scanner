# Arduino 4x4 Keypad Scanner (S1–S16 Mapping)

Bu proje, 4x4 matrix keypad kullanarak her tuşa özel **S1–S16 indeksleme sistemi** ile çalışan bir Arduino keypad sürücüsüdür.

---

## 📌 Özellikler

- 4x4 matrix keypad desteği
- Row/Column scanning (klasik tarama algoritması)
- S1–S16 özel tuş numaralandırma sistemi
- Serial Monitor üzerinden tuş çıktısı
- Basit debounce (50ms)
- Extra library kullanmadan manuel keypad driver

---

## 🔌 Bağlantılar

| Keypad Pin | Arduino Pin |
|------------|-------------|
| R1         | D9          |
| R2         | D8          |
| R3         | D7          |
| R4         | D6          |
| C1         | D5          |
| C2         | D4          |
| C3         | D10         |
| C4         | D2          |

---

## 🧠 Çalışma Mantığı

Keypad matrix yapısı şu prensiple çalışır:

- Satırlar sırayla LOW yapılır
- Sütunlar INPUT_PULLUP olarak okunur
- Bir tuşa basıldığında ilgili satır-sütun kesişimi LOW olur
- Bu koordinat S1–S16 tablosuna çevrilir

---

## 📤 Örnek Serial Çıktı

S1 basıldı
S6 basıldı
S12 basıldı
S16 basıldı

---

## ⚙️ Kullanım

1. Kodu Arduino IDE’ye yükle
2. Serial Monitor aç (9600 baud)
3. Tuşlara bas ve çıktıyı izle

---

## 🧩 Kod Yapısı

- `rowPins[]` → Satır pinleri
- `colPins[]` → Sütun pinleri
- `tusNumarasi[4][4]` → S1–S16 mapping tablosu
- `loop()` → keypad scanning algoritması

---

## 🚀 Geliştirme Fikirleri

- LCD 16x2 I2C ekran entegrasyonu
- Şifreli kapı kilidi sistemi
- ESP32 ile web tabanlı keypad kontrolü
- Interrupt tabanlı input sistemi
- Keypad library yerine optimize driver
- Sesli geri bildirim (buzzer)

---

## 🧠 Notlar

- Bu proje tamamen manuel keypad driver mantığıyla yazılmıştır
- Arduino’nun standart `Keypad.h` kütüphanesi kullanılmamıştır
- Mapping sistemi özelleştirilebilir

---

## 📜 Lisans

MIT License
