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
  
byte Matrix3[] = {
  B00000000,
  B01111110,
  B01000010,
  B01011010,
  B01011010,
  B01000010,
  B01111110,
  B00000000};

byte Matrix4[] = {
  B11111111,
  B10000001,
  B10111101,
  B10100101,
  B10100101,
  B10111101,
  B10000001,
  B11111111};
 
//const int columnPins[] = {  9,8, 7, 6, 5, 4, 3, 2};
//const int rowPins[]    = { 10,11,12,15,16,17,18,19};
const int columnPins[] = {  14, 15, 16, 17, 18, 19, 11, 12};
const int rowPins[]    = { 3, 4, 5, 6, 7, 8, 9,10};

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
  show(Matrix3, 1600);           // show image1 for 2000 ms
  show(Matrix4, 1600);       // show image2 for 2000 ms  

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
      digitalWrite(columnPins[row], HIGH);          // connect row to +5 volts
      for(int column = 0; column < 8; column++)
      {
        boolean pixel = bitRead(image[row],column);
        if(pixel == 1)
        {
          digitalWrite(rowPins[column], LOW);  // connect column to Gnd
        }
        delayMicroseconds(300);                   // a small delay for each LED
        digitalWrite(rowPins[column], HIGH);   // disconnect column from Gnd
      }
      digitalWrite(columnPins[row], LOW);            // disconnect LEDs
    }
  }
}
      
    
