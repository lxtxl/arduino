// a 0 indicates the LED is off, 1 is on

byte Matrix1[] = {
  B00000000,
  B01101100,
  B11111110,
  B11111110,
  B11111110,
  B01111100,
  B00111000,
  B00010000};

byte Matrix2[] = {
  B11111111,
  B10010011,
  B00000001,
  B00000001,
  B00000001,
  B10000011,
  B11000111,
  B11101111};
  
 
//const int columnPins[] = {  9,8, 7, 6, 5, 4, 3, 2};
//const int rowPins[]    = { 10,11,12,15,16,17,18,19};
const int rowPins[]    = { 14, 15, 16, 17, 18, 19, 11, 12};
const int columnPins[] = {  3, 4, 5, 6, 7, 8, 9, 10};

void setup() {
  for (int i = 0; i < 8; i++)
  {
    pinMode(rowPins[i], OUTPUT);        // make all the LED pins outputs
    pinMode(columnPins[i], OUTPUT);
    digitalWrite(columnPins[i], HIGH);  // disconnect column pins from Ground
  }
}

void loop() {
  int pulseDelay = 800 ;          // milliseconds to wait between images

  show(Matrix1, 1600);           // show image1 for 2000 ms
  show(Matrix2, 1600);       // show image2 for 2000 ms
  
  delay(pulseDelay);              // show nothing between images
}

// routine to show a frame of an image stored in the array pointed to 
// by the image parameter.
// the frame is repeated for the given duration in milliseconds
void show( byte * image, unsigned long duration)
{
 unsigned long start = millis();            // begin timing the animation
 while (start + duration > millis())        // loop until duration period has passed
  {
    for(int row = 0; row < 8; row++)
    {
      digitalWrite(rowPins[row], HIGH);          // connect row to +5 volts
      for(int column = 0; column < 8; column++)
      {
        boolean pixel = bitRead(image[row],column);
        if(pixel == 1)
        {
          digitalWrite(columnPins[column], LOW);  // connect column to Gnd
        }
        delayMicroseconds(300);                   // a small delay for each LED
        digitalWrite(columnPins[column], HIGH);   // disconnect column from Gnd
      }
      digitalWrite(rowPins[row], LOW);            // disconnect LEDs
    }
  }
}
      
    
