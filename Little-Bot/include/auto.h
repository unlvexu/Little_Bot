#pragma once
#include "main.h"

const float lDist = 7; // left encoder position
const float rDist = 7; // right encoder position
const float sDist = 7; // strafe encoder Position

const float wheeldiaL = 2.75; // left encoder wheel diameter
const float wheeldiaR = 2.75; // right encoder wheel diameter
const float wheeldiaS = 2.75; // strafe encoder wheel diameter

const int ticks = 360; //ticks per encoder revolution, keep at 360

const float lspintoin = (wheeldiaL*pi/ticks); // inches per revolution reft
const float rspintoin = (wheeldiaR*pi/ticks); // inches per revolution right
const float sspintoin = (wheeldiaS*pi/ticks); // inches per revolution strafe

pros::ADIEncoder lEnc (1,2,false); // define left encoder  
pros::ADIEncoder rEnc (3,4,false); // define right encoder
pros::ADIEncoder sEnc (5,6,false); // define strafe encoder
// should 3-wire ports be placed in initialize.cpp?

typedef struct _pos
{
	float a;
	float y;
	float x;
	int leftLast;
	int rightLast;
	int strafeLast;
} sPos; // typedef struct containing robot location and previous encoder values

typedef struct _vel
{
	float a;
	float y;
	float x;
	unsigned long firstChecked;
	float firstPosA;
	float firstPosY;
	float firstPosX;
} sVel; //typedef struct containing robot velocity

// functions
void trackPos(int left, int right,int strafe);
void resetPos(sPos& position);
void setPos(sPos& position, float y, float x);
void setPos(sPos& position, float y, float x, float a);
void trackVelocity();
void odomTask();
