#pragma once

#define huge
#define near
#define far
#define _seg
#define interrupt

#include <stdint.h>

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

//extern DWORD sbOldIntHand;

void geninterrupt(int intr);

void setvect(unsigned intr,  void (*isr)());

// ---------------------- IDASME.//todo:replaceasm port ----------------------

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
