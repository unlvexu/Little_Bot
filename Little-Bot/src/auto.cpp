#include "auto.h"

void trackPos(int left, int right,int strafe,sPos& position){
  float L = (left - position.leftLast)*lspintoin;
  float R = (right - position.rightLast)*rspintoin;
  float S = (strafe - position.strafeLast)*sspintoin; // calculate distance traveled since last loop

  position.leftLast = left;
  position.rightLast  = right;
  position.strafeLast = strafe; // update previous valule variables

  float h; // hypotenuse of triangled formed by center of bot intial, final and circle radius positions
  float i; // half the angle change since the last loop
  float h2; // hypotenuse calculated by the strafe wheel
  float a = (L-R)/(lDist+rDist); //angle change since last loop

  if(a != 0){
    float radius = R/a; // radius of robot turning circle
    float radius2 = S/a; // radius of robot from back wheel
    i = a/2;
    float sini = sin(i);
    h = ((radius + rDist)*sini)*2;
    h2 = ((radius2 + sDist)*sini)*2;
  }
  else{
    h = R;
    i = 0;
    h2 = S;
  }
  float p = i+position.a; // corrected robot end angle
  float cosp = cos(p);
  float sinp = sin(p);

  position.y += h*cosp;
  position.y += h*(-sinp); // update global y coordinate

  position.x += h*sinp;
  position.x += h*cosp; // update global x coordinate

  position.a += a; //update global robot angle

}

void resetPos(sPos& position){
  position.x = 0;
  position.y = 0;
  position.a = 0;
}

void setPos(sPos& position, float y, float x){
  position.x = x;
  position.y = y;
}

void setPos(sPos& position, float y, float x, float a){
  position.x = x;
  position.y = y;
  position.a = a;
}

void trackVelocity(sPos position, sVel& velocity){
  unsigned long curtime = pros::millis();
  long passed = curtime - velocity.firstChecked; //time since last check
  if(passed > 40){
    velocity.a = ((position.a - velocity.firstPosA)*1000)/passed;
  }
}
