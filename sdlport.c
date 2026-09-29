
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

DWORD fontcolor;
DWORD px;
DWORD py;
DWORD pdrawmode;
DWORD fontseg;

DWORD screenseg;
DWORD otherseg;
DWORD screenofs;
DWORD screenorigin;
DWORD planemask;
DWORD planecount;
DWORD linewidth;

char keydown[128];
int NBKscan;
int NBKascii;

unsigned sndptr;

unsigned SndPriority;

WORD SndPtr;
void* soundseg;
unsigned int8hook;
unsigned timerspeed;
unsigned inttime;
long timecount;
int dontplay;
int soundmode;

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

void CallTimer() { }

void geninterrupt(int intr) { }

void setvect(unsigned intr, intr_fn isr) { }

intr_fn getvect(int intr_num) { }

void outportb(WORD portid, BYTE value) { }

WORD bioskey(WORD cmd) { }

DWORD farcoreleft(void) { }

void farfree(void *block) { }
void *farmalloc(DWORD size) { }
void movedata(unsigned sourceseg, unsigned sourceoff, unsigned destseg, unsigned destoff, size_t count) { }
long filelength(int handle) { }

void textbackground(int color) { }
void textcolor(int color) { }
void hardresume(int code) { }
void harderr(int (*handler)()) { }
unsigned coreleft(void) { }
void clrscr(void) { }

int VideoID() { }

void StartupKbd() { }
void StartupSound() { }
void ShutdownSound() { }
void ShutdownKbd() { }

int NoBiosKey(int parm) { }

void WaitVBL(int number) { }

void PlaySound(int playnum) { }
void InitRndT(int randomize) { }
void InitRnd(int randomize) { }
void sound(unsigned freq) { }
void nosound() { }
unsigned char inportb(int port) { }
int Rnd (int max) { }
int RndT (void) { }
unsigned ylookup[256];
void far * far _fmemcpy(void far *dest, const void far *source, size_t count) {}
void far * far _fmemset(void far *buf, int ch, size_t count) {}
char *ltoa(long num, char *str, int radix) { }
char *itoa(int num, char *str, int radix) { }
int stricmp(const char *str1, const char *str2) { }