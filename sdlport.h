#pragma once

#define huge
#define near
#define far
#define _seg
#define interrupt

#include <stdint.h>
#include <stdlib.h>
#include <math.h>



// DOS COMPAT

typedef uint8_t BYTE;
typedef uint16_t WORD;
typedef uint32_t DWORD;
typedef void* memptr;

#define O_BINARY 0

#define stdprn stderr


extern WORD _AX;
extern BYTE _AH;
extern BYTE _AL;

extern WORD _BX;
extern BYTE _BH;
extern BYTE _BL;

extern WORD _CX;
extern WORD _DX;
extern WORD _ES;
extern WORD _DS;

extern DWORD fontcolor;
extern DWORD px;
extern DWORD py;
extern DWORD pdrawmode;
extern unsigned screenofs;

extern DWORD screenseg;
extern DWORD otherseg;
extern DWORD screenofs;
extern DWORD screenorigin;
extern DWORD planemask;
extern DWORD planecount;
extern DWORD linewidth;

extern unsigned SndPriority;


extern WORD SndPtr;
extern void* soundseg;
extern unsigned int8hook;
extern unsigned inttime;
extern long timecount;
extern int dontplay;

extern char keydown[128];
extern int NBKscan;
extern int NBKascii;


#define FP_OFF(x) (WORD)x
#define FP_SEG(x) (WORD)x
#define MK_FP(x, y) 0

void geninterrupt(int intr);

typedef void (*intr_fn)();

//typedef unsigned boolean;

void setvect(unsigned intr, intr_fn isr);
intr_fn getvect(int intr_num); 

WORD bioskey(WORD cmd);
DWORD farcoreleft(void);
void farfree(void *block);
void *farmalloc(DWORD size);
void outportb(WORD portid, BYTE value);
void movedata(unsigned sourceseg, unsigned sourceoff, unsigned destseg, unsigned destoff, size_t count);
long filelength(int handle);


void textbackground(int color);
void textcolor(int color);
void hardresume(int code);
void harderr(int (*handler)());
unsigned coreleft(void);
void clrscr(void);

// ---------------------- IDASME.asm ----------------------

//====================
//
// EGAplane
// Sets read/write mode 0 and selects the given plane (0-3)
// for reading and writing
//
//====================
void EGAplane(WORD plane);

//==============
//
// SetScreen
//
//==============
void SetScreen(WORD crtc, WORD pel);

//=============
//
// XorBar
//
// xcoord in bytes, ycoord in pixels
//
//=============
void XorBar(WORD xl, WORD yl, WORD wide, WORD height);

//=============
//
// XPlot
//
// Xdraws one point
//
//=============
void XPlot(WORD x, WORD y, WORD color);

//=============
//
// DrawChar (int xcoord, int ycoord, int charnum)
//
// xcoord in bytes, ycoord in pixels
//
// Source is grsegs[STARTTILE8+charnum]
//
//=============
void DrawChar(WORD xcoord, WORD ycoord, WORD charnum);

//============
//
// DrawPic (int xcoord, int ycoord, int picnum)
//
// xcoord in bytes, ycoord in pixels
//
//============
void DrawPic(WORD xcoord, WORD ycoord, WORD picnum);

//============
//
// Bar (int xl,yl,width,height)
//
// xcoord in bytes, ycoord in pixels
//
//============
void Bar(WORD xl, WORD yl, WORD wide, WORD height, WORD fill);

//============
//
// CopyEGA
//
// Must be in latch mode
//
//============
void CopyEGA(WORD wide, WORD height, WORD source, WORD dest);

//==================
//
// DrawPchar
// Draws a proportional character at px,py, and increments px
//
//==================
void DrawPchar(WORD charnum);

//==================================================
//
// void scaleline (int scale, unsigned picseg, unsigned maskseg,
//                 unsigned screen, unsigned width)
//
//==================================================
void ScaleLine(WORD pixels, DWORD scaleptr, DWORD picptr, WORD screen);

//============
//
// DrawSprite
//
// Source is a (void _seg *) to the sprite
//
// Must be in write mode 0
//
//============
void DrawSpriteT(WORD wide, WORD height, WORD source, WORD dest, WORD plsize);

// ---------------------- IDASM.asm ----------------------

//========
//
// CallTimer
//
// Call the bios int8 to turn off drive motors
//
//========
void CallTimer();

//========
//
// StartupSound
//
// Sets up the new INT 8 ISR and various internal pointers.
// Assumes that the calling program has pointer soundseg to something
// meaningful...
//
//========
void StartupSound();

//========
//
// StartupKbd
//
// Sets up the new INT 8 ISR and various internal pointers.
// Assumes that the calling program has pointer soundseg to something
// meaningful...
//
//========
void StartupKbd();

//========
//
// ShutdownSound
//
//========
void ShutdownSound();

//========
//
// ShutdownKbd
//
//========
void ShutdownKbd();

//========
//
// WaitVBL (int number)
//
//========
void WaitVBL(int number);

//===========
//
// PlaySoundSPK (soundnum)
//
// If the sound's priority is >= the current priority, SoundPtr, SndPriority,
// and the timer speed are changed
//
// Hacked for sound blaster support!
//
//===========
void PlaySound(int playnum);

//=================================================
//
// InitRndT (boolean randomize)
// Init table based RND generator
// if randomize is false, the counter is set to 0
//
//=================================================
//void InitRndT(boolean randomize);

//=================================================
//
// InitRnd (boolean randomize)
// if randomize is false, the counter is set to 0
//
//=================================================
//void InitRnd(boolean randomize);

