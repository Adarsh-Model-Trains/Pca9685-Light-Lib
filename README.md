# Pca9685-Light-Lib

---

# <a href="https://github.com/adarshkumarsingh83/Pca9685-Servo-Lib/archive/production.zip"> Library download link </a>

## About the Lib 
```
Pca9685-Light-Lib is for supporing multiple Pca9685 boards together 
in chain without complexcity of the programming 

max we can connect 64 Pca9685 together in chain which will give extra 1024 pins for operations 
this api support a simple interface where we can controll 1-1024 pins by its sequence number 
respected to their sequence in the chain 

pin number will start from 1 to (number of board X 16 pin per board)

NOTE: Order of Pca9685 board address wise must be in sequence otherwise it will not work in expected manner 

```

## Pca9685 board addressing configuration 
![img](/image/pca9685-soldering-address-chart.png)


## Connection details 

![img](/image/connection-dettails.JPG)

```
sda and scl from arduino to 1st pca9685 
external power supply +5v and gnd to the breadboard 
from breadboard external power supply +5v and gnd to the first pca9685  in chain to vcc and gnd 
and +5v and gnd to the 1st pca9685 sidew power inputs 
and one gnd from the external power supply to the arduino gnd pin for common gnd setup 

connect the other pca9684 in the chain with 1st soder which has address 41 
connect the other pca9684 in the chain with 2nd soder which has address 42 
connect the other pca9684 in the chain with 2nd soder which has address 43 
and so on till 64 pca9684 can be max connected in chain 

# For Led Connection with pca9685
connect the jumper from yellow which is pwm pin to the breadboard 
then connect the resisot to that and followed by led long leg 
then connect the short leg of the led tot he common gnd in the breadboard 

repeate this for the other pca9685 in chain 


```

## steps for using lib

## include the header file
```
#include "Pca9685.h"
#include "Pca9685Board.h"
```

## define the object for the Pca9685Board
```
Pca9685Board pca9685Board;

```

## define the number of the board we are using in chain
```
#define NO_OF_BOARDS 8
```

## initialize the object with in setup method
* pca9685Board.initPca9685Boards(NO_OF_BOARDS)
* 
```
void setup() {
  
   .....

  pca9685Board.initPca9685Boards(NO_OF_BOARDS);

  .......

}
```

## for debug messages a initialize Serial in setup
```
void setup() {
  
  Serial.begin(xxxx); // xxx can be any valid supported number 

  .........
}

```

## use lib method for switch on 
* pca9685Board.switchOn(pinNo);
* switchOn light will take pin number for switch on operation.
```
void loop() {
  
  .......

   pca9685Board.switchOn(pinNo);
  ..........
}
```

## use lib method for closing swtich 
* pca9685Board.switchOff(pinNo);
* swtichOff light will take pin number for switch off operation 
```
void loop() {
  
  .......

	pca9685Board.switchOff(pinNo);
  ..........
}
```

## use lib method for displaying state of pins 
```
void loop() {
  
  .......

	pca9685Board.displayPinState();
  ..........
}
```

### Complete Example
```
#include "Pca9685.h"
#include "Pca9685Board.h"

#define NO_OF_BOARDS 3

int MAX_PINS = 0;

Pca9685Board pca9685Board;
void setup() {
  Serial.begin(9600);
  pca9685Board.initPca9685Boards(NO_OF_BOARDS);
  MAX_PINS = NO_OF_BOARDS * 16;
}

void loop() {
  delay(1000);

  int pinNo = random(0, MAX_PINS);
  Serial.print("MAX PIN ");
  Serial.println(MAX_PINS);
  Serial.print("PIN NO ");
  Serial.println(pinNo);
  pca9685Board.switchOn(pinNo);
  pca9685Board.displayPinState();
  delay(1000);
  pca9685Board.switchOff(pinNo);
  pca9685Board.displayPinState();
  delay(1000);
}

```
