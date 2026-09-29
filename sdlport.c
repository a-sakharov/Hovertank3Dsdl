
WORD _AX;
BYTE _AH;
BYTE _AL;

WORD _BX;
BYTE _BH;
BYTE _BL;

WORD _CX;
WORD _DX;
WORD _ES;
WORD _DS;

//DWORD sbOldIntHand;

void EGAplane(WORD plane) { }


void SetScreen(WORD crtc, WORD pel) { }


void XorBar(WORD xl, WORD yl, WORD wide, WORD height) { }


void XPlot(WORD x, WORD y, WORD color) { }


void DrawChar(WORD xcoord, WORD ycoord, WORD charnum) { }


void DrawPic(WORD xcoord, WORD ycoord, WORD picnum) { }


void Bar(WORD xl, WORD yl, WORD wide, WORD height, WORD fill) { }


void CopyEGA(WORD wide, WORD height, WORD source, WORD dest) { }


void DrawPchar(WORD charnum) { }


void ScaleLine(WORD pixels, DWORD scaleptr, DWORD picptr, WORD screen) { }


void DrawSpriteT(WORD wide, WORD height, WORD source, WORD dest, WORD plsize) { }

void geninterrupt(int intr) { }

void setvect(unsigned intr,  void (*isr)()) { }
