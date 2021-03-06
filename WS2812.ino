#include <Adafruit_NeoPixel.h>

#define PIN 6 //lampu Kiri
#define PIN1 5 //Lampu Kanan

int TBKiri     = A0;
int TBHazard    = A1;
int TBStop    = A2;
int TBKanan    = A3;
int TBAnimasi  = A4;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(30, PIN, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel strip1 = Adafruit_NeoPixel(30, PIN1, NEO_GRB + NEO_KHZ800);
char hold0 = 0;
char hold1 = 0;
char hold2 = 0;
char hold3 = 0;
char hold4 = 0;
char data0, data1, data2, data3,data4;
void setup() {
  pinMode(TBKiri, INPUT_PULLUP);
  pinMode(TBKanan, INPUT_PULLUP);
  pinMode(TBStop, INPUT_PULLUP);
  pinMode(TBHazard, INPUT_PULLUP);
  pinMode(TBAnimasi, INPUT_PULLUP);
  strip.begin();
  strip.show(); // Initialize all pixels to 'off'
  strip1.begin();
  strip1.show(); // Initialize all pixels to 'off'
}

void loop() {
key();
}

void key(){
  data0 = digitalRead(A0);
  data1 = digitalRead(A1);
  data2 = digitalRead(A2);
  data3 = digitalRead(A3);
  data4 = digitalRead(A4);
  if ( data0 == 0){
    if(hold0 == 0){
    hold0 = 0;  
    Senkiri();
  } 
  }
  else{
    hold0 = 0;
  }

   if ( data1 == 0){
    if(hold1 == 0){
    hold1 = 0;  
    Hazard();
  } 
  }
  else{
    hold1 = 0;
  }

   if ( data2 == 0){
    if(hold2 == 0){
    hold2 = 0;  
    Stop();
  } 
  }
  else{
    hold2 = 0;
  }

    if ( data3 == 0){
    if(hold3 == 0){
    hold3 = 0;  
    Senkanan();
  } 
  }
  else{
    hold3 = 0;
  }
   if ( data4 == 0){
    if(hold4 == 0){
    hold4 = 0;  
    Animasi(5);
  } 
  }
  else{
    hold4 = 0;
  }
}
void Senkiri(){
  kiri(strip.Color(255, 255, 0), 10); // Red
  kiri(strip.Color(0, 0, 0), 10); // Red
}
void kiri(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++){
      strip.setPixelColor(i, c);
      strip.show();
       delay(wait);   
  }
}

void Senkanan(){
  kanan(strip1.Color(255, 255, 0), 10); // Red
  kanan(strip1.Color(0, 0, 0), 10); // Red
}
void kanan(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip1.numPixels(); i++){
      strip1.setPixelColor(i, c);
      strip1.show();
       delay(wait);   
  }
}

void Hazard(){
  tengah(strip.Color(255, 255, 0), 10); // Red
  tengah(strip.Color(0, 0, 0), 10); // Red
}
void tengah(uint32_t c, uint8_t wait) {
  for(uint16_t i=0; i<strip.numPixels(); i++){
      strip1.setPixelColor(i, c);
      strip1.show();
      strip.setPixelColor(i, c);
      strip.show();
       delay(10);   
  }
}

void Stop(){
  berhenti(strip.Color(255, 0, 0), 1); // Red
  berhenti(strip.Color(0, 0, 0), 1); // Red
  berhenti(strip.Color(0, 0, 255), 1); // Red
  berhenti(strip.Color(0, 0, 0), 1); // Red
}
void berhenti(uint32_t c, uint8_t wait) {
      for(int i=0;i<=71;i++){
      strip1.setPixelColor(i, c);
      strip1.show();
      strip.setPixelColor(i, c);
      strip.show();
       delay(wait);   
}
}

void Animasi(uint8_t wait) {
  uint16_t i, j;

  for(j=0; j<256*5; j++) { // 5 cycles of all colors on wheel
    for(i=0; i< strip.numPixels(); i++) {
      strip.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
      strip1.setPixelColor(i, Wheel(((i * 256 / strip.numPixels()) + j) & 255));
    }
    strip.show();
    strip1.show();
    delay(wait);
  }
}

uint32_t Wheel(byte WheelPos) {
  if(WheelPos < 85) {
   return strip.Color(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if(WheelPos < 170) {
   WheelPos -= 85;
   return strip.Color(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170;
   return strip.Color(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
