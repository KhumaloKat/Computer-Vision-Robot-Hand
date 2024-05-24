#include <cvzone.h>
#include <Servo.h>

Servo servoThumb;
Servo servoIndex;
Servo servoMiddle;
Servo servoRing;
Servo servoPinky;

minVal = 35
maxVal = 135

SerialData serialData(5,1);
int valsRec[5];


void setup() {
 serialData.begin();
 servoThumb.attach(9);
 servoIndex.attach(10);
 servoMiddle.attach(11);
 servoRing.attach(12);
 servoPinky.attach(13);


}

void loop() {

  serialData.Get(valsRec);
  if (valsRec[0]== 0) {servoThumb.write(maxVal);}else{servoThumb.write(minVal);}
  if (valsRec[1]== 0) {servoIndex.write(maxVal);}else{servoThumb.write(minVal);}
  if (valsRec[2]== 0) {servoMiddle.write(maxVal);}else{servoThumb.write(minVal);}
  if (valsRec[3]== 0) {servoRing.write(maxVal);}else{servoThumb.write(minVal);}
  if (valsRec[4]== 0) {servoPinky.write(maxVal);}else{servoThumb.write(minVal);}

  

}
