// Setup Data
#define setupBLDC 0
#define setupServo 0

// Mode
#define passiveMode false
#define autoMode true

long data;
long speedBLDC = setupBLDC;
long angleServo = setupServo;
bool controlMode = passiveMode;


void sendData(long _speedBLDC, long _angleServo, bool _controlMode){
  data = _speedBLDC + (_angleServo * 100) + (_controlMode * 10000);
}

