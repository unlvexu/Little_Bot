
typedef struct _pos
{
	float a;
	float y;
	float x;
	int leftLst;
	int rightLst;
	int backLst;
} sPos; // Position of the robot

// functions
void trackPos(int left, int right,int strafe,sPos& position);
void resetPos(sPos& position);
void setPos(sPos& position, float y, float x);
void setPos(sPos& position, float y, float x, float a);
