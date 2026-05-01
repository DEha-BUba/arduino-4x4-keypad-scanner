// S1'den S16'ya özel tuş takımı kodu
// Bağlantılar: R1,R2,R3,R4 = D9,D8,D7,D6
//              C1,C2,C3,C4 = D5,D4,D10,D2  (C3 D10'da)

const int rowPins[4] = {9, 8, 7, 6};   // R1,R2,R3,R4
const int colPins[4] = {5, 4, 10, 2};  // C1,C2,C3,C4

// S1'den S16'ya özel isimler
char tusIsimleri[4][4] = {
  {'1', '2', '3', '4'},   // bu satır sembolik, asıl eşleşme aşağıda
  {'5', '6', '7', '8'},
  {'9', '0', 'A', 'B'},
  {'C', 'D', 'E', 'F'}
};

// Gerçek eşleşme: [satır][sütun] -> S_Numarası
int tusNumarasi[4][4] = {
  {13, 14, 15, 16},   // S13, S14, S15, S16
  {9,  10, 11, 12},   // S9, S10, S11, S12
  {5,  6,  7,  8},    // S5, S6, S7, S8
  {1,  2,  3,  4}     // S1, S2, S3, S4
};

void setup() {
  Serial.begin(9600);
  
  for(int i = 0; i < 4; i++) {
    pinMode(rowPins[i], OUTPUT);
    digitalWrite(rowPins[i], HIGH);
  }
  
  for(int i = 0; i < 4; i++) {
    pinMode(colPins[i], INPUT_PULLUP);
  }
  
  Serial.println("Tuş takımı hazır. S1'den S16'ya basabilirsiniz:");
}

void loop() {
  for(int satir = 0; satir < 4; satir++) {
    for(int i = 0; i < 4; i++) {
      digitalWrite(rowPins[i], HIGH);
    }
    digitalWrite(rowPins[satir], LOW);
    
    for(int sutun = 0; sutun < 4; sutun++) {
      if(digitalRead(colPins[sutun]) == LOW) {
        delay(50);
        if(digitalRead(colPins[sutun]) == LOW) {
          int tusNo = tusNumarasi[satir][sutun];
          Serial.print("S");
          Serial.print(tusNo);
          Serial.println(" basıldı");
          
          while(digitalRead(colPins[sutun]) == LOW);
          delay(50);
        }
      }
    }
  }
  delay(10);
}
