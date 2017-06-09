// a 0 indicates the LED is off, 1 is on
#include <FrequencyTimer2.h>

#define SPACE { \
     {0, 0, 0, 0, 0, 0, 0, 0},  \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 0, 0, 0, 0, 0} \
 }
 
#define A { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 1, 0, 1, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 1, 1, 1, 1, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0} \
 }
 
#define S  { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 1, 1, 1, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 0, 1, 1, 1, 1, 0}, \
     {0, 0, 0, 0, 0, 0, 1, 0}, \
     {0, 0, 0, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 1, 1, 1, 0, 0} \
 }
 
#define P { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 1, 1, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 1, 0, 0}, \
     {0, 0, 1, 0, 0, 1, 0, 0}, \
     {0, 0, 1, 1, 1, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0} \
 }
 
#define I { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 1, 1, 1, 1, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 1, 1, 1, 1, 1, 0} \
 }

#define D { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 1, 1, 1, 0, 0, 0, 0}, \
     {0, 1, 0, 0, 1, 0, 0, 0}, \
     {0, 1, 0, 0, 0, 1, 0, 0}, \
     {0, 1, 0, 0, 0, 1, 0, 0}, \
     {0, 1, 0, 0, 0, 1, 0, 0}, \
     {0, 1, 0, 0, 1, 0, 0, 0}, \
     {0, 1, 1, 1, 0, 0, 0, 0} \
 }
 
#define N { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 1, 0, 0, 1, 0}, \
     {0, 0, 1, 0, 1, 0, 1, 0}, \
     {0, 0, 1, 0, 0, 1, 1, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 0, 0, 0, 1, 0} \
 }
 
#define T { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 1, 1, 1, 1, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0}, \
     {0, 0, 0, 0, 1, 0, 0, 0} \
 }
 
#define F { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 1, 1, 1, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 1, 1, 1, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 0, 0, 0} \
 }
 
#define R { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 1, 1, 1, 1, 0, 0, 0}, \
     {0, 1, 0, 0, 0, 1, 0, 0}, \
     {0, 1, 0, 0, 0, 1, 0, 0}, \
     {0, 1, 1, 1, 1, 0, 0, 0}, \
     {0, 1, 0, 1, 0, 0, 0, 0}, \
     {0, 1, 0, 0, 1, 0, 0, 0}, \
     {0, 1, 0, 0, 0, 1, 0, 0} \
 }

#define M { \
     {0, 0, 0, 0, 0, 0, 0, 0}, \
     {0, 1, 0, 0, 0, 0, 0, 1}, \
     {0, 1, 1, 0, 0, 0, 1, 1}, \
     {0, 1, 0, 1, 0, 1, 0, 1}, \
     {0, 1, 0, 0, 1, 0, 0, 1}, \
     {0, 1, 0, 0, 0, 0, 0, 1}, \
     {0, 1, 0, 0, 0, 0, 0, 1}, \
     {0, 1, 0, 0, 0, 1, 0, 1} \
 }
 
 #define O { \
     {0, 0, 0, 1, 1, 0, 0, 0}, \
     {0, 0, 1, 0, 0, 1, 0, 0}, \
     {0, 1, 0, 0, 0, 0, 1, 0}, \
     {0, 1, 0, 0, 0, 0, 1, 0}, \
     {0, 1, 0, 0, 0, 0, 1, 0}, \
     {0, 1, 0, 0, 0, 0, 1, 0}, \
     {0, 0, 1, 0, 0, 1, 0, 0}, \
     {0, 0, 0, 1, 1, 0, 0, 0} \
 }
 
byte col = 0;
byte leds[8][8];

//const int rowPins[] = {  9,8, 7, 6, 5, 4, 3, 2};
//const int columnPins[]    = { 19,18,17,16,15,12,11,10};
const int rowPins[]    = { 14, 15, 16, 17, 18, 19, 11, 12};
const int columnPins[] = {  3, 4, 5, 6, 7, 8, 9, 10};

const int numPatterns = 27;
byte patterns[numPatterns][8][8] = {
  P, A, S, S, I, O, N, SPACE, A, N, S, SPACE, T, R, A, N, S, F, O, R, M, A, T, I, O, N, SPACE, 
};

int pattern = 0;

void setup() {
   for (int i = 0; i < 8; i++) {
    pinMode(rowPins[i], OUTPUT);        // make all the LED pins outputs
    pinMode(columnPins[i], OUTPUT);
   }
 
  // set up cols and rows
   for (int i = 1; i <= 8; i++) {
     digitalWrite(columnPins[i - 1], LOW);
   }
 
  for (int i = 1; i <= 8; i++) {
     digitalWrite(rowPins[i - 1], LOW);
   }  
    
  clearLeds();
 
   FrequencyTimer2::disable();
   // Set refresh rate (interrupt timeout period)
   FrequencyTimer2::setPeriod(2000);
   // Set interrupt routine to be called
   FrequencyTimer2::setOnOverflow(display);
 
  setPattern(pattern);  
}

void loop() {
     pattern = ++pattern % numPatterns;
     slidePattern(pattern, 600);
}


void clearLeds() {
   // Clear display array
   for (int i = 0; i < 8; i++) {
     for (int j = 0; j < 8; j++) {
       leds[i][j] = 0;
     }
   }
 }
      
void setPattern(int pattern) {
   for (int i = 0; i < 8; i++) {
     for (int j = 0; j < 8; j++) {
       leds[i][j] = patterns[pattern][i][j];
     }
   }
 }
 
void slidePattern(int pattern, int del) {
   for (int l = 0; l < 8; l++) {
     for (int i = 0; i < 7; i++) {
       for (int j = 0; j < 8; j++) {
         leds[j][i] = leds[j][i+1];
       }
     }
     for (int j = 0; j < 8; j++) {
       leds[j][7] = patterns[pattern][j][0 + l];
     }
     delay(del);
   }
 }
 
// Interrupt routine
 void display() {
   digitalWrite(rowPins[col], LOW);  // Turn whole previous column off
   col++;
   if (col == 8) {
     col = 0;
   }
   for (int row = 0; row < 8; row++) {
     if (leds[col][7 - row] == 1) {
       digitalWrite(columnPins[row], LOW);  // Turn on this led
     }
     else {
       digitalWrite(columnPins[row], HIGH); // Turn off this led
     }
   }
   digitalWrite(rowPins[col], HIGH); // Turn whole column on at once (for equal lighting times)
 }
