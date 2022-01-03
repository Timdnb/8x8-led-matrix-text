# 8x8 led matrix text
Arduino program to show text on a 8x8 led matrix. 
## Setting up the matrix
If you know the type of matrix you have, you can probably find the datasheet of the matrix containing the information of which pins connect to which rows and columns of leds. If this is not the case, just manually put a voltage on every pin and see what lights up. From here construct your own layout. Then connect the pins and change the rows and columns in the program to the pins that you used. 

## Running the program
In `8x8_text.ino` you can write any text (using U+0000 - U+007F). This will then show on the led matrix letter by letter. The file `characters.h` contains all the unicode characters used to display the text. If you want the characters to display quicker or slower, change the interval value (it is in milliseconds).