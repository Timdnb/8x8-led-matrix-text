#include "characters.h"

#define COL_1 5
#define COL_2 4
#define COL_3 3
#define COL_4 2
#define COL_5 6
#define COL_6 7
#define COL_7 8
#define COL_8 9

#define ROW_1 10
#define ROW_2 11
#define ROW_3 12
#define ROW_4 13
#define ROW_5 A5
#define ROW_6 A4
#define ROW_7 A3
#define ROW_8 A2

long t = 0;
int interval = 500;

const char string[] = "Write your text here";

const byte rows[] = {
    ROW_1, ROW_2, ROW_3, ROW_4, ROW_5, ROW_6, ROW_7, ROW_8
};

const byte cols[] = {
    COL_1, COL_2, COL_3, COL_4, COL_5, COL_6, COL_7, COL_8
};

void led(int row, int column){
  for (int i = 0; i < 8; i++){
      digitalWrite(cols[i], HIGH);}
      
  for (int i = 0; i < 8; i++){
      digitalWrite(rows[i], LOW);}
    
  digitalWrite(rows[row], HIGH);
  digitalWrite(cols[column], LOW);
  }

void setup() {
    // Set all used pins to OUTPUT
    for (byte i = 2; i <= 13; i++)
        pinMode(i, OUTPUT);
    pinMode(A2, OUTPUT);
    pinMode(A3, OUTPUT);
    pinMode(A4, OUTPUT);
    pinMode(A5, OUTPUT);

    Serial.begin(9600);
}

void loop() {
  
  for (int i = 0; i < strlen(string); i++)
  {  
      char letter = string[i];

      unsigned int ascii_index = (unsigned int)letter;

      // If the character is a space, turn off all leds
      if (ascii_index == 32){
        for (int i = 0; i < 8; i++){
          digitalWrite(cols[i], HIGH);}
      
        for (int i = 0; i < 8; i++){
          digitalWrite(rows[i], LOW);}
        }

      // While loop to keep this letter for a certain time
      while (millis()-t < interval){
        for (int j = 0; j < 8; j++)
        {
            for (int k = 7; k >= 0; k--)
            {
                byte value = (byte)(font8x8_basic[ascii_index][j] >> k) & 1 ? 1 : 0;
                if (value == 1){
                  led(j,k);
                }
            }
        }
    }
    t += interval;
  }

}
