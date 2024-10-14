#include "iGraphics.h"
#include "genjam.h"
#define screenlength 740
#define screenwidth 380
#include <string.h>
#include <ctype.h>
#include <cstdlib> // For atof function
#include <cmath>
#include "calculator.h"
#include <time.h>
#include <windows.h>
#include <mmsystem.h>
#pragma comment(lib, "Winmm.lib");
char meme[100];
char answer_store[100];
int whicheval = 0;
char ab;
double xy;
double a1, a2, b1, b2, c1, c2;
double a, b, c;
int markey = 0;
int onclicked = 0, equ_equalcount = 0;
// For pow, sin, cos, tan functions
char result[100];
int settheme = 1;
int equals_clicked = 0;
char input_buffer[100];
int input_idx = 0;
char display_store[1000];
int i = 0;
char *res;
double result_input;
char result_display[100];
int themeclicked = 0;
int setmode = 0;
int modeclicked = 0;
int error = 0;
double answer;
int mode = 0;
char simul_equ_display[100];
int s = 0;
char quad_equ_display[100];
char quad_display[100];
char simul_display[100];
int equ_error = 1;
int t = 0;
int normal_error = 0;
char showmode[10];
int errorcount=0;
/*
	function iDraw() is called again and again by the system.

	*/

int row1 = 25, row2 = 95, row3 = 165, row4 = 235, row5 = 305;
int column1 = 60, column2 = 120, column3 = 180, column4 = 240, column5 = 300, column6 = 360, column7 = 420, column8 = 480, column9 = 540, column10 = 600;
void iDraw()
{

	// place your drawing codes here
	iClear();
	if (setmode == 0)
	{
		strcpy(showmode, "normal");
		if (settheme == 1)
		{
			// 1st row;
			iSetColor(255, 255, 255);
			iFilledCircle(50, 85, 25, 100);
			iSetColor(0, 0, 0);
			iText(45, 80, "0", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(120, 85, 25, 100);
			iSetColor(0, 0, 0);
			iText(120, 80, ".", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(190, 85, 25, 100);
			iSetColor(0, 0, 0);
			iText(180, 80, "%", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(260, 85, 25, 100);
			iSetColor(0, 0, 0);
			iText(246, 80, "Ans", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 85, 25, 100);
			iSetColor(0, 0, 0);
			iText(325, 80, "=", GLUT_BITMAP_HELVETICA_18);

			// 2nd row

			iSetColor(255, 255, 255);
			iFilledCircle(50, 145, 25, 100);
			iSetColor(0, 0, 0);
			iText(45, 140, "1", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			;
			iFilledCircle(120, 145, 25, 100);
			iSetColor(0, 0, 0);
			iText(115, 140, "2", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(190, 145, 25, 100);
			iSetColor(0, 0, 0);
			iText(185, 140, "3", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(260, 145, 25, 100);
			iSetColor(0, 0, 0);
			iText(255, 140, "+", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 145, 25, 100);
			iSetColor(0, 0, 0);
			iText(325, 140, "-", GLUT_BITMAP_HELVETICA_18);
			// 3rd row

			iSetColor(255, 255, 255);
			iFilledCircle(50, 205, 25, 100);
			iSetColor(0, 0, 0);
			iText(45, 200, "4", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(120, 205, 25, 100);
			iSetColor(0, 0, 0);
			iText(115, 200, "5", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(190, 205, 25, 100);
			iSetColor(0, 0, 0);
			iText(185, 200, "6", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(260, 205, 25, 100);
			iSetColor(0, 0, 0);
			iText(255, 200, "X", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 205, 25, 100);
			iSetColor(0, 0, 0);
			iText(325, 200, "/", GLUT_BITMAP_HELVETICA_18);

			// 4th row

			iSetColor(255, 255, 255);
			iFilledCircle(50, 265, 25, 100);
			iSetColor(0, 0, 0);
			iText(45, 260, "7", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(120, 265, 25, 100);
			iSetColor(0, 0, 0);
			iText(115, 260, "8", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(190, 265, 25, 100);
			iSetColor(0, 0, 0);
			iText(185, 260, "9", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(260, 265, 25, 100);
			iSetColor(0, 0, 255);
			iText(245, 260, "DEL", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 265, 25, 100);
			iSetColor(255, 0, 0);
			iText(320, 260, "AC", GLUT_BITMAP_HELVETICA_18);

			// 5th row
			iSetColor(255, 255, 255);
			iFilledCircle(50, 325, 25, 100);
			iSetColor(0, 0, 0);
			iText(37, 320, "sin", GLUT_BITMAP_8_BY_13);

			iSetColor(255, 255, 255);
			iFilledCircle(120, 325, 25, 100);
			iSetColor(0, 0, 0);
			iText(107, 320, "cos", GLUT_BITMAP_8_BY_13);

			iSetColor(255, 255, 255);
			iFilledCircle(190, 325, 25, 100);
			iSetColor(0, 0, 0);
			iText(178, 320, "tan", GLUT_BITMAP_8_BY_13);

			iSetColor(255, 255, 255);
			iFilledCircle(260, 325, 25, 100);
			iSetColor(0, 0, 0);
			iText(260, 320, "!", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 325, 25, 100);
			iSetColor(0, 0, 0);
			iText(320, 320, "ln", GLUT_BITMAP_8_BY_13);

			// 6th row
			iSetColor(255, 255, 255);
			iFilledCircle(50, 385, 25, 100);
			iSetColor(0, 0, 0);
			iText(37, 380, "x^2", GLUT_BITMAP_8_BY_13);

			iSetColor(255, 255, 255);
			iFilledCircle(120, 385, 25, 100);
			iSetColor(0, 0, 0);
			iText(107, 380, "x^3", GLUT_BITMAP_8_BY_13);

			iSetColor(255, 255, 255);
			iFilledCircle(190, 385, 25, 100);
			iSetColor(0, 0, 0);
			iText(178, 380, "x^n", GLUT_BITMAP_8_BY_13);

			iSetColor(255, 255, 255);
			iFilledCircle(260, 385, 25, 100);
			iSetColor(0, 0, 0);
			iText(245, 380, "x^-1", GLUT_BITMAP_8_BY_13);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 385, 25, 100);
			iSetColor(0, 0, 0);
			iText(320, 380, "log", GLUT_BITMAP_HELVETICA_12);

			// 7th row
			iSetColor(255, 255, 255);
			iFilledCircle(50, 445, 25, 100);
			iSetColor(0, 0, 0);
			iText(35, 440, "Mode", GLUT_BITMAP_HELVETICA_12);

			iSetColor(255, 255, 255);
			iFilledCircle(120, 445, 25, 100);
			iSetColor(0, 0, 0);
			iText(100, 440, "Theme", GLUT_BITMAP_HELVETICA_12);

			iSetColor(255, 255, 255);
			iFilledCircle(190, 445, 25, 100);
			iSetColor(0, 0, 0);
			iText(185, 440, "e^", GLUT_BITMAP_HELVETICA_18);

			iSetColor(255, 255, 255);
			iFilledCircle(260, 445, 25, 100);
			iSetColor(0, 0, 0);
			iText(250, 440, "sqrt", GLUT_BITMAP_HELVETICA_12);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 445, 25, 100);
			iSetColor(0, 0, 0);
			iText(315, 440, "cubrt", GLUT_BITMAP_HELVETICA_12);

			// last row

			iSetColor(255, 255, 255);
			iFilledCircle(50, 505, 25, 100);
			iSetColor(0, 0, 0);
			iText(35, 500, "Arcsin", GLUT_BITMAP_HELVETICA_12);
			iSetColor(255, 255, 255);
			iFilledCircle(120, 505, 25, 100);
			iSetColor(0, 0, 0);
			iText(100, 500, "Arccos", GLUT_BITMAP_HELVETICA_12);
			iSetColor(255, 255, 255);
			iFilledCircle(190, 505, 25, 100);
			iSetColor(0, 0, 0);
			iText(175, 500, "Arctan", GLUT_BITMAP_HELVETICA_12);
			iSetColor(255, 255, 255);
			iFilledCircle(260, 505, 25, 100);
			iSetColor(0, 0, 0);
			iText(240, 500, "S<=>D", GLUT_BITMAP_HELVETICA_12);

			iSetColor(255, 255, 255);
			iFilledCircle(330, 505, 25, 100);
			iSetColor(0, 0, 0);
			iText(318, 500, "On", GLUT_BITMAP_HELVETICA_18);

 
				


			// display
			if (onclicked == 1)
			{
				iSetColor(52, 219, 235);
				iFilledRectangle(10, 560, 360, 160);
			}
			else
			{
				iSetColor(0, 0, 0);
				iFilledRectangle(10, 560, 360, 180);
			}
			iSetColor(0,0,0);
	iText(20, 630, meme, GLUT_BITMAP_HELVETICA_12);
	
			iSetColor(0, 0, 0);
			iText(20, 680, display_store, GLUT_BITMAP_HELVETICA_18);

			iSetColor(0, 0, 0);
			iText(300, 700, showmode, GLUT_BITMAP_8_BY_13);
		}

		else if (settheme == 3)
		{
			iSetColor(80, 220, 100);
			iFilledCircle(50, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 85, 25, 100);
			iText(45, 80, "0", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(120, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 85, 25, 100);
			iText(120, 80, ".", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(190, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 85, 25, 100);
			iText(180, 80, "%", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(260, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 85, 25, 100);
			iText(246, 80, "Ans", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(330, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 85, 25, 100);
			iText(325, 80, "=", GLUT_BITMAP_HELVETICA_18);

			// 2nd row

			iSetColor(80, 220, 100);
			iFilledCircle(50, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 145, 25, 100);
			iText(45, 140, "1", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			;
			iFilledCircle(120, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 145, 25, 100);
			iText(115, 140, "2", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(190, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 145, 25, 100);
			iText(185, 140, "3", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(260, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 145, 25, 100);
			iText(255, 140, "+", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(330, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 145, 25, 100);
			iText(325, 140, "-", GLUT_BITMAP_HELVETICA_18);
			// 3rd row

			iSetColor(80, 220, 100);
			iFilledCircle(50, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 205, 25, 100);
			iText(45, 200, "4", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(120, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 205, 25, 100);
			iText(115, 200, "5", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(190, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 205, 25, 100);
			iText(185, 200, "6", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(260, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 205, 25, 100);
			iText(255, 200, "X", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(330, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 205, 25, 100);
			iText(325, 200, "/", GLUT_BITMAP_HELVETICA_18);

			// 4th row

			iSetColor(80, 220, 100);
			iFilledCircle(50, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 265, 25, 100);
			iText(45, 260, "7", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(120, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 265, 25, 100);
			iText(115, 260, "8", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(190, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 265, 25, 100);
			iText(185, 260, "9", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(260, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 265, 25, 100);
			iText(245, 260, "DEL", GLUT_BITMAP_HELVETICA_18);

			iSetColor(80, 220, 100);
			iFilledCircle(330, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 265, 25, 100);
			iText(320, 260, "AC", GLUT_BITMAP_HELVETICA_18);

			// 5th row
			iSetColor(21, 71, 52);
			iFilledCircle(50, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 325, 25, 100);
			iText(37, 320, "sin", GLUT_BITMAP_8_BY_13);

			iSetColor(21, 71, 52);
			iFilledCircle(120, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 325, 25, 100);
			iText(107, 320, "cos", GLUT_BITMAP_8_BY_13);

			iSetColor(21, 71, 52);
			iFilledCircle(190, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 325, 25, 100);
			iText(178, 320, "tan", GLUT_BITMAP_8_BY_13);

			iSetColor(21, 71, 52);
			iFilledCircle(260, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 325, 25, 100);
			iText(260, 320, "!", GLUT_BITMAP_HELVETICA_18);

			iSetColor(21, 71, 52);
			iFilledCircle(330, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 325, 25, 100);
			iText(320, 320, "ln", GLUT_BITMAP_8_BY_13);

			// 6th row
			iSetColor(21, 71, 52);
			iFilledCircle(50, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 385, 25, 100);
			iText(37, 380, "x^2", GLUT_BITMAP_8_BY_13);

			iSetColor(21, 71, 52);
			iFilledCircle(120, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 385, 25, 100);
			iText(107, 380, "x^3", GLUT_BITMAP_8_BY_13);

			iSetColor(21, 71, 52);
			iFilledCircle(190, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 385, 25, 100);
			iText(178, 380, "x^n", GLUT_BITMAP_8_BY_13);

			iSetColor(21, 71, 52);
			iFilledCircle(260, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 385, 25, 100);
			iText(245, 380, "x^-1", GLUT_BITMAP_8_BY_13);

			iSetColor(21, 71, 52);
			iFilledCircle(330, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 385, 25, 100);
			iText(320, 380, "log", GLUT_BITMAP_HELVETICA_18);

			// 7th row
			iSetColor(21, 71, 52);
			iFilledCircle(50, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 445, 25, 100);
			iText(35, 440, "Mode", GLUT_BITMAP_HELVETICA_12);

			iSetColor(21, 71, 52);
			iFilledCircle(120, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 445, 25, 100);
			iText(100, 440, "Theme", GLUT_BITMAP_HELVETICA_12);

			iSetColor(21, 71, 52);
			iFilledCircle(190, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 445, 25, 100);
			iText(185, 440, "e^", GLUT_BITMAP_HELVETICA_18);

			iSetColor(21, 71, 52);
			iFilledCircle(260, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 445, 25, 100);
			iText(250, 440, "sqrt", GLUT_BITMAP_HELVETICA_12);

			iSetColor(21, 71, 52);
			iFilledCircle(330, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 445, 25, 100);
			iText(315, 440, "cubrt", GLUT_BITMAP_HELVETICA_12);

			// last row

			iSetColor(21, 71, 52);
			iFilledCircle(50, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 505, 25, 100);
			iSetColor(255, 255, 255);
			iText(35, 500, "Arcsin", GLUT_BITMAP_HELVETICA_12);
			iSetColor(21, 71, 52);
			iFilledCircle(120, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 505, 25, 100);
			iSetColor(255, 255, 255);

			iText(100, 500, "Arccos", GLUT_BITMAP_HELVETICA_12);
			iSetColor(21, 71, 52);
			iFilledCircle(190, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 505, 25, 100);
			iSetColor(255, 255, 255);
			iText(175, 500, "Arctan", GLUT_BITMAP_HELVETICA_12);

			iSetColor(21, 71, 52);
			iFilledCircle(260, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 505, 25, 100);

			iSetColor(255, 255, 255);
			iText(240, 500, "S<=>D", GLUT_BITMAP_HELVETICA_12);

			iSetColor(21, 71, 52);
			iFilledCircle(330, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 505, 25, 100);
			iText(318, 500, "On", GLUT_BITMAP_HELVETICA_18);

			// display
			if (onclicked == 1)
			{
				iSetColor(199, 0, 57);
				iFilledRectangle(10, 560, 360, 160);
			}
			else
			{
				iSetColor(0, 0, 0);
				iFilledRectangle(10, 560, 360, 160);
			}
			iSetColor(255, 255, 255);
			iText(20, 680, display_store, GLUT_BITMAP_HELVETICA_18);
			iSetColor(255, 255, 255);
			iText(300, 700, showmode, GLUT_BITMAP_TIMES_ROMAN_10);
			
		iSetColor(0, 0, 0);		
	iText(20, 630, meme, GLUT_BITMAP_HELVETICA_18);

		}

		else if (settheme = 2)
		{
			iSetColor(30, 30, 30);
			iFilledCircle(50, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 85, 25, 100);
			iText(45, 80, "0", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(120, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 85, 25, 100);
			iText(120, 80, ".", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(190, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 85, 25, 100);
			iText(180, 80, "%", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(260, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 85, 25, 100);
			iText(246, 80, "Ans", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 85, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 85, 25, 100);
			iText(325, 80, "=", GLUT_BITMAP_HELVETICA_18);

			// 2nd row

			iSetColor(30, 30, 30);
			iFilledCircle(50, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 145, 25, 100);
			iText(45, 140, "1", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			;
			iFilledCircle(120, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 145, 25, 100);
			iText(115, 140, "2", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(190, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 145, 25, 100);
			iText(185, 140, "3", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(260, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 145, 25, 100);
			iText(255, 140, "+", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 145, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 145, 25, 100);
			iText(325, 140, "-", GLUT_BITMAP_HELVETICA_18);
			// 3rd row

			iSetColor(30, 30, 30);
			iFilledCircle(50, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 205, 25, 100);
			iText(45, 200, "4", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(120, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 205, 25, 100);
			iText(115, 200, "5", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(190, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 205, 25, 100);
			iText(185, 200, "6", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(260, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 205, 25, 100);
			iText(255, 200, "X", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 205, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 205, 25, 100);
			iText(325, 200, "/", GLUT_BITMAP_HELVETICA_18);

			// 4th row

			iSetColor(30, 30, 30);
			iFilledCircle(50, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 265, 25, 100);
			iText(45, 260, "7", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(120, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 265, 25, 100);
			iText(115, 260, "8", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(190, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 265, 25, 100);
			iText(185, 260, "9", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(260, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 265, 25, 100);
			iText(245, 260, "DEL", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 265, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 265, 25, 100);
			iText(320, 260, "AC", GLUT_BITMAP_HELVETICA_18);

			// 5th row
			iSetColor(30, 30, 30);
			iFilledCircle(50, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 325, 25, 100);
			iText(37, 320, "sin", GLUT_BITMAP_8_BY_13);

			iSetColor(30, 30, 30);
			iFilledCircle(120, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 325, 25, 100);
			iText(107, 320, "cos", GLUT_BITMAP_8_BY_13);

			iSetColor(30, 30, 30);
			iFilledCircle(190, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 325, 25, 100);
			iText(178, 320, "tan", GLUT_BITMAP_8_BY_13);

			iSetColor(30, 30, 30);
			iFilledCircle(260, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 325, 25, 100);
			iText(260, 320, "!", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 325, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 325, 25, 100);
			iText(320, 320, "ln", GLUT_BITMAP_8_BY_13);

			// 6th row
			iSetColor(30, 30, 30);
			iFilledCircle(50, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 385, 25, 100);
			iText(37, 380, "x^2", GLUT_BITMAP_8_BY_13);

			iSetColor(30, 30, 30);
			iFilledCircle(120, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 385, 25, 100);
			iText(107, 380, "x^3", GLUT_BITMAP_8_BY_13);

			iSetColor(30, 30, 30);
			iFilledCircle(190, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 385, 25, 100);
			iText(178, 380, "x^n", GLUT_BITMAP_8_BY_13);

			iSetColor(30, 30, 30);
			iFilledCircle(260, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 385, 25, 100);
			iText(245, 380, "x^-1", GLUT_BITMAP_8_BY_13);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 385, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 385, 25, 100);
			iText(320, 380, "log", GLUT_BITMAP_HELVETICA_18);

			// 7th row
			iSetColor(30, 30, 30);
			iFilledCircle(50, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 445, 25, 100);
			iText(35, 440, "Mode", GLUT_BITMAP_HELVETICA_12);

			iSetColor(30, 30, 30);
			iFilledCircle(120, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 445, 25, 100);
			iText(100, 440, "Theme", GLUT_BITMAP_HELVETICA_12);

			iSetColor(30, 30, 30);
			iFilledCircle(190, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 445, 25, 100);
			iText(185, 440, "e^", GLUT_BITMAP_HELVETICA_18);

			iSetColor(30, 30, 30);
			iFilledCircle(260, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 445, 25, 100);
			iText(250, 440, "sqrt", GLUT_BITMAP_HELVETICA_12);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 445, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 445, 25, 100);
			iText(315, 440, "cubrt", GLUT_BITMAP_HELVETICA_12);

			// last row

			iSetColor(30, 30, 30);
			iFilledCircle(50, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(50, 505, 25, 100);
			iSetColor(255, 255, 255);
			iText(35, 500, "Arcsin", GLUT_BITMAP_HELVETICA_12);
			iSetColor(30, 30, 30);
			iFilledCircle(120, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(120, 505, 25, 100);
			iSetColor(255, 255, 255);
			iText(100, 500, "Arccos", GLUT_BITMAP_HELVETICA_12);
			iSetColor(30, 30, 30);
			iFilledCircle(190, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(190, 505, 25, 100);
			iSetColor(255, 255, 255);
			iText(175, 500, "Arctan", GLUT_BITMAP_HELVETICA_12);
			iSetColor(30, 30, 30);
			iFilledCircle(260, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(260, 505, 25, 100);
			iSetColor(255, 255, 255);
			iText(240, 500, "S<=>D", GLUT_BITMAP_HELVETICA_12);

			iSetColor(30, 30, 30);
			iFilledCircle(330, 505, 25, 100);
			iSetColor(255, 255, 255);
			iCircle(330, 505, 25, 100);
			iText(318, 505, "On", GLUT_BITMAP_HELVETICA_18);

			// display
			if (onclicked == 1)
			{
				iSetColor(65, 25, 0);
				iFilledRectangle(10, 560, 360, 160);
			}
			else
			{
				iSetColor(0, 0, 0);
				iFilledRectangle(10, 560, 360, 160);
			}
			iSetColor(255, 255, 255);
			iText(20, 680, display_store, GLUT_BITMAP_HELVETICA_18);
			iSetColor(0, 0, 0);
			iText(300, 720, showmode, GLUT_BITMAP_TIMES_ROMAN_10);
			iSetColor(255, 255, 255);		
	iText(20, 630, meme, GLUT_BITMAP_HELVETICA_18);

		}
	}

	else if (setmode == 1)
	{
		strcpy(showmode, "simul");
		iSetColor(30, 30, 30);
		iFilledCircle(50, 145, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 145, 25, 100);
		iText(45, 140, "1", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(50, 85, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 85, 25, 100);
		iText(45, 80, "0", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(120, 145, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 145, 25, 100);
		iText(115, 140, "2", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(190, 145, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 145, 25, 100);
		iText(185, 140, "3", GLUT_BITMAP_HELVETICA_18);

		iSetColor(80, 220, 100);
		iFilledCircle(50, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 205, 25, 100);
		iText(45, 200, "4", GLUT_BITMAP_HELVETICA_18);

		iSetColor(80, 220, 100);
		iFilledCircle(120, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 205, 25, 100);
		iText(115, 200, "5", GLUT_BITMAP_HELVETICA_18);

		iSetColor(80, 220, 100);
		iFilledCircle(190, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 205, 25, 100);
		iText(185, 200, "6", GLUT_BITMAP_HELVETICA_18);
		iSetColor(30, 30, 30);
		iFilledCircle(50, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 265, 25, 100);
		iText(45, 260, "7", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(120, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 265, 25, 100);
		iText(115, 260, "8", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(190, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 265, 25, 100);
		iText(185, 260, "9", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(260, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(260, 265, 25, 100);
		iText(245, 260, "DEL", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(330, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(330, 265, 25, 100);
		iText(320, 260, "AC", GLUT_BITMAP_HELVETICA_18);
		iSetColor(30, 30, 30);
		iFilledCircle(120, 85, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 85, 25, 100);
		iText(120, 80, ".", GLUT_BITMAP_HELVETICA_18);

		iSetColor(52, 219, 235);
		iFilledRectangle(10, 530, 360, 100);
		iSetColor(0, 0, 0);

		iText(20, 580, simul_equ_display, GLUT_BITMAP_HELVETICA_18);
		iSetColor(52, 219, 235);
		iFilledRectangle(10, 640, 360, 90);
		iSetColor(0, 0, 0);
		iText(20, 680, simul_display, GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(190, 85, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 85, 25, 100);
		iText(190, 80, "=", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(260, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(260, 205, 25, 100);
		iText(255, 200, "-", GLUT_BITMAP_8_BY_13);
		iSetColor(255, 255, 255);
		iText(300, 700, showmode, GLUT_BITMAP_HELVETICA_18);
	}

	else if (setmode == 2)
	{
		strcpy(showmode, "quad");
		iSetColor(30, 30, 30);
		iFilledCircle(50, 145, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 145, 25, 100);
		iText(45, 140, "1", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(50, 85, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 85, 25, 100);
		iText(45, 80, "0", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(120, 145, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 145, 25, 100);
		iText(115, 140, "2", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(190, 145, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 145, 25, 100);
		iText(185, 140, "3", GLUT_BITMAP_HELVETICA_18);

		iSetColor(80, 220, 100);
		iFilledCircle(50, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 205, 25, 100);
		iText(45, 200, "4", GLUT_BITMAP_HELVETICA_18);

		iSetColor(80, 220, 100);
		iFilledCircle(120, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 205, 25, 100);
		iText(115, 200, "5", GLUT_BITMAP_HELVETICA_18);

		iSetColor(80, 220, 100);
		iFilledCircle(190, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 205, 25, 100);
		iText(185, 200, "6", GLUT_BITMAP_HELVETICA_18);
		iSetColor(30, 30, 30);
		iFilledCircle(50, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(50, 265, 25, 100);
		iText(45, 260, "7", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(120, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 265, 25, 100);
		iText(115, 260, "8", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(190, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 265, 25, 100);
		iText(185, 260, "9", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(260, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(260, 265, 25, 100);
		iText(245, 260, "DEL", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(330, 265, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(330, 265, 25, 100);
		iText(320, 260, "AC", GLUT_BITMAP_HELVETICA_18);
		iSetColor(30, 30, 30);
		iFilledCircle(120, 85, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(120, 85, 25, 100);
		iText(120, 80, ".", GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(260, 205, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(260, 205, 25, 100);
		iText(260, 205, "-", GLUT_BITMAP_8_BY_13);

		iSetColor(52, 219, 235);
		iFilledRectangle(10, 460, 360, 80);
		iSetColor(0, 0, 0);
		iText(20, 510, quad_equ_display, GLUT_BITMAP_HELVETICA_18);

		iSetColor(52, 219, 235);
		iFilledRectangle(10, 570, 360, 90);
		iSetColor(0, 0, 0);
		iText(20, 610, quad_display, GLUT_BITMAP_HELVETICA_18);

		iSetColor(30, 30, 30);
		iFilledCircle(190, 85, 25, 100);
		iSetColor(255, 255, 255);
		iCircle(190, 85, 25, 100);
		iText(190, 80, "=", GLUT_BITMAP_HELVETICA_18);

		iSetColor(255, 255, 255);
		iText(300, 630, showmode, GLUT_BITMAP_HELVETICA_18);
	}
}
void iMouseMove(int mx, int my)
{
	printf("x = %d, y= %d\n", mx, my);
	// place your codes here
}

/*
	function iMouse() is called when the user presses/releases the mouse.
	(mx, my) is the position where the mouse pointer is.
	*/

void iMouse(int button, int state, int mx, int my)
{
	PlaySound("clicksound.wav", NULL, SND_ASYNC);

	// row 1

	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
	{	
		if (setmode == 0)
		{
			// row 1;
			if (my > column1 && my < (column1 + 50))
			{
				if ((mx > row1 && mx < (row1 + 50)))
				{
					display_store[i] = '0';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '0';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row2 && mx < (row2 + 50)))
				{
					display_store[i] = '.';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '.';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row3 && mx < (row3 + 50)))
				{
					display_store[i] = '%';
					display_store[i + 1] = '\0';
					i++;
					input_buffer[input_idx] = '%';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
					// input buffer dite hobe
				}

				if ((mx > row4 && mx < (row4 + 50)))
				{
					strcpy(answer_store, display_store);
					for (int ijk = 0; ijk < strlen(display_store); ijk++)
					{
						display_store[ijk] = 0;
					}
					i = 0;
					display_store[i] = 'A';
					display_store[i + 1] = 'n';
					display_store[i + 2] = 's';
					display_store[i + 3] = 0;
					i = 3;
					strcpy(input_buffer, answer_store);
					input_idx = strlen(answer_store);
					for (int ijk = 0; ijk < strlen(answer_store); ijk++)
					{
						answer_store[ijk] = 0;
					}
				}

				if ((mx > row5 && mx < (row5 + 50)))
				{

					whicheval = genjam(input_buffer);

					if (whicheval == 1)
					{
						char ab[2];
						ab[0] = genjamtype(input_buffer);
						ab[1] = '\0';
						double xy = genjamvalue(input_buffer);
						double answer = genjameval(xy, ab[0]);
						sprintf(result_display, "%g", answer);
						if(errorcheck(result_display) != 0) {
						strcpy(display_store, result_display);
						}
						else {
							errorcount=1;
							strcpy(display_store, "Oops! Error!");
							strcpy(meme, "'There are no accidents - Master OOgway'");
							printf("%d", errorcount);
						}
						result_input = 0;
					}
					else
					{
						res = convert(input_buffer);
						result_input = evaluate(res);
						answer = result_input;

						if ((result_input - int(result_input)) == 0)
						{

							sprintf(result_display, "%d", int(result_input));
						if(errorcheck(result_display) != 0) {
						strcpy(display_store, result_display);
						}
						else {
							errorcount=1;
							strcpy(display_store, "Oops! Error!");
							strcpy(meme, "'There are no accidents - Master OOgway'");
							printf("%d", errorcount);
							
						}
							
							result_input = 0;
						}

						else
						{

							sprintf(result_display, "%g", result_input);
							if(errorcheck(result_display) != 0) {
						strcpy(display_store, result_display);
						}
						else {
							errorcount=1;
							strcpy(display_store, "Oops! Error!");
							strcpy(meme, "'There are no accidents - Master OOgway'");
							printf("%d", errorcount);
						}
							
							result_input = 0;
						}
					}
					printf("%g", answer);
				}
			}
			if (my > column2 && my < (column2 + 50))
			{
				if ((mx > row1 && mx < (row1 + 50)))
				{
					if (themeclicked == 1)
					{
						settheme = 1;
						themeclicked = 0;
					}
					else if (modeclicked == 1)
					{
						setmode = 1;
						modeclicked = 0;
						reset_equ(display_store);
						strcpy(simul_display, "Enter a1:");
					}

					else
					{
						display_store[i] = '1';
						display_store[i + 1] = 0;
						i++;
						input_buffer[input_idx] = '1';
						input_buffer[input_idx + 1] = '\0';
						input_idx++;
					}
				}

				if ((mx > row2 && mx < (row2 + 50)))
				{
					if (themeclicked == 1)
					{
						settheme = 2;
						themeclicked = 0;
					}
					else if (modeclicked == 1)
					{
						setmode = 2;
						modeclicked = 0;
						strcpy(quad_display, "Enter a:");
					}
					else
					{
						display_store[i] = '2';
						display_store[i + 1] = 0;
						i++;
						input_buffer[input_idx] = '2';
						input_buffer[input_idx + 1] = '\0';
						input_idx++;
					}
				}

				if ((mx > row3 && mx < (row3 + 50)))
				{
					if (themeclicked == 1)
					{
						settheme = 3;
						themeclicked = 0;
					}
					else
					{
						display_store[i] = '3';
						display_store[i + 1] = 0;
						i++;
						input_buffer[input_idx] = '3';
						input_buffer[input_idx + 1] = '\0';
						input_idx++;
					}
				}

				if ((mx > row4 && mx < (row4 + 50)))
				{
					display_store[i] = '+';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '+';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row5 && mx < (row5 + 50)))
				{
					display_store[i] = '-';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '-';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}
			}

			if (my > column3 && my < (column3 + 50))
			{
				if ((mx > row1 && mx < (row1 + 50)))
				{
					display_store[i] = '4';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '4';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row2 && mx < (row2 + 50)))
				{
					display_store[i] = '5';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '5';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row3 && mx < (row3 + 50)))
				{
					display_store[i] = '6';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '6';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row4 && mx < (row4 + 50)))
				{
					display_store[i] = 'X';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '*';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row5 && mx < (row5 + 50)))
				{
					display_store[i] = '/';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '/';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}
			}

			if (my > column4 && my < (column4 + 50))
			{
				if ((mx > row1 && mx < (row1 + 50)))
				{
					display_store[i] = '7';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '7';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row2 && mx < (row2 + 50)))
				{
					display_store[i] = '8';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '8';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row3 && mx < (row3 + 50)))
				{
					display_store[i] = '9';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '9';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row4 && mx < (row4 + 50)))
				{
					display_store[i - 1] = 0;
					i--;
					input_buffer[input_idx] = 0;
					input_idx--;
				}

				if ((mx > row5 && mx < (row5 + 50)))
				{
					reset(display_store, input_buffer);
					i = 0;
					input_idx = 0;
				}
			}

			if (my > column5 && my < (column5 + 50))
			{
				if ((mx > row1 && mx < (row1 + 50)))
				{
					display_store[i] = 's';
					display_store[i + 1] = 'i';
					display_store[i + 2] = 'n';
					display_store[i + 3] = 0;
					i++;
					input_buffer[input_idx] = 's';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row2 && mx < (row2 + 50)))
				{
					display_store[i] = 'c';
					display_store[i + 1] = 'o';
					display_store[i + 2] = 's';
					display_store[i + 3] = 0;
					i++;
					input_buffer[input_idx] = 'c';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row3 && mx < (row3 + 50)))
				{
					display_store[i] = 't';
					display_store[i + 1] = 'a';
					display_store[i + 2] = 'n';
					display_store[i + 3] = 0;
					i++;
					input_buffer[input_idx] = 't';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row4 && mx < (row4 + 50)))
				{
					display_store[i] = '!';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '!';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
					// edit
				}

				if ((mx > row5 && mx < (row5 + 50)))
				{
					display_store[i] = 'l';
					display_store[i + 1] = 'n';
					display_store[i + 2] = 0;
					i++;
					input_buffer[input_idx] = 't';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}
			}

			if (my > column6 && my < (column6 + 50))
			{
				if ((mx > row1 && mx < (row1 + 50)))
				{
					display_store[i] = '^';
					display_store[i + 1] = '2';
					display_store[i + 2] = 0;
					i = i + 2;
					input_buffer[input_idx] = 'a';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row2 && mx < (row2 + 50)))
				{
					display_store[i] = '^';
					display_store[i + 1] = '3';
					display_store[i + 2] = 0;
					i = i + 2;
					input_buffer[input_idx] = 'b';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row3 && mx < (row3 + 50)))
				{
					display_store[i] = '^';
					display_store[i + 1] = 0;
					i++;
					input_buffer[input_idx] = '^';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row4 && mx < (row4 + 50)))
				{
					display_store[i] = '^';
					display_store[i + 1] = '-';
					display_store[i + 2] = '1';
					display_store[i + 3] = 0;
					input_buffer[input_idx] = 'd';
					input_idx++;
					i = i + 3;
					input_buffer[input_idx++] = '\0';
				}

				if ((mx > row5 && mx < (row5 + 50)))
				{
					display_store[i] = 'l';
					display_store[i + 1] = 'o';
					display_store[i + 2] = 'g';
					display_store[i + 3] = 0;

					i += 3;
					input_buffer[input_idx] = 'l';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}
			}

			if (my > column7 && my < (column7 + 50))
			{
				if ((mx > row1 && mx < (row1 + 50))) // mode
				{
					strcpy(display_store, "1.Linear Equation 2.Quadratic 3.Normal");
					modeclicked = 1;
				}

				if ((mx > row2 && mx < (row2 + 50))) // theme
				{
					strcpy(display_store, "1.Light  2.Dark  3.Independence");
					themeclicked = 1;
				}

				if ((mx > row3 && mx < (row3 + 50)))
				{
					display_store[i] = 'e';
					display_store[i + 1] = '^';
					display_store[i + 2] = 0;
					i = i + 2;
					input_buffer[input_idx] = 'e';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row4 && mx < (row4 + 50)))
				{
					display_store[i] = 'r';
					display_store[i + 1] = 't';
					display_store[i + 2] = 0;
					i = i + 2;
					input_buffer[input_idx] = 'R';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}

				if ((mx > row5 && mx < (row5 + 50)))
				{
					display_store[i] = 'c';
					display_store[i + 1] = 'b';
					display_store[i + 2] = 'r';
					display_store[i + 3] = 't';
					display_store[i + 4] = 0;
					i = i + 4;
					input_buffer[input_idx] = 'r';
					input_buffer[input_idx + 1] = '\0';
					input_idx++;
				}
			}
		}
		if (my > column8 && my < (column8 + 50))
		{
			if ((mx > row1 && mx < (row1 + 50)))
			{
				display_store[i] = 'a';
				display_store[i + 1] = 'r';
				display_store[i + 2] = 'c';
				display_store[i + 3] = 's';
				display_store[i + 4] = 'i';
				display_store[i + 5] = 'n';
				display_store[i + 6] = '\0';

				i = i + 6;
				input_buffer[input_idx] = 'S';
				input_buffer[input_idx + 1] = '\0';
				input_idx++;
			}

			if ((mx > row2 && mx < (row2 + 50)))
			{
				display_store[i] = 'a';
				display_store[i + 1] = 'r';
				display_store[i + 2] = 'c';
				display_store[i + 3] = 'c';
				display_store[i + 4] = 'o';
				display_store[i + 5] = 's';
				display_store[i + 6] = '\0';

				i = i + 6;
				input_buffer[input_idx] = 'C';
				input_buffer[input_idx + 1] = '\0';
				input_idx++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				display_store[i] = 'a';
				display_store[i + 1] = 'r';
				display_store[i + 2] = 'c';
				display_store[i + 3] = 't';
				display_store[i + 4] = 'a';
				display_store[i + 5] = 'n';
				display_store[i + 6] = '\0';

				i = i + 6;
				input_buffer[input_idx] = 'T';
				input_buffer[input_idx + 1] = '\0';
				input_idx++;
			}

			if ((mx > row4 && mx < (row4 + 50)))
			{
				convertStoD(answer, display_store);
			}
			if ((mx > row5 && mx < (row5 + 50)))
			{
				reset(display_store, input_buffer);
				i = 0;
				input_idx = 0;
				onclicked = 1;
				reset_equ(meme);
			}
		}
	}
	else if (setmode == 1) // simultaneous equation solver
	{
		if (my > column1 && my < (column1 + 50))
		{
			if ((mx > row2 && mx < (row2 + 50)))
			{
				simul_equ_display[s] = '.';
				simul_equ_display[s + 1] = 0;
				s++;
			}
			if ((mx > row1 && mx < (row1 + 50)))
			{
				simul_equ_display[s] = '0';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				equ_equalcount++;

				if (equ_equalcount == 1)
				{

					sscanf(simul_equ_display, "%lf", &a1);
					reset_equ(simul_equ_display);
					s = 0;
					printf("%lf\n", a1);
					printf("%s", simul_equ_display);
					strcpy(simul_display, "Enter b1:");
				}
				if (equ_equalcount == 2)
				{

					sscanf(simul_equ_display, "%lf", &b1);
					reset_equ(simul_equ_display);
					s = 0;
					reset_equ(simul_display);
					strcpy(simul_display, "Enter c1:");
				}
				if (equ_equalcount == 3)
				{

					sscanf(simul_equ_display, "%lf", &c1);
					reset_equ(simul_equ_display);
					s = 0;
					reset_equ(simul_display);
					strcpy(simul_display, "Enter a2:");
				}
				if (equ_equalcount == 4)
				{

					sscanf(simul_equ_display, "%lf", &a2);
					reset_equ(simul_equ_display);
					s = 0;
					reset_equ(simul_display);
					strcpy(simul_display, "Enter b2:");
				}
				if (equ_equalcount == 5)
				{

					sscanf(simul_equ_display, "%lf", &b2);
					reset_equ(simul_equ_display);
					s = 0;
					reset_equ(simul_display);
					strcpy(simul_display, "Enter c2:");
				}
				if (equ_equalcount == 6)
				{

					sscanf(simul_equ_display, "%lf", &c2);
					reset_equ(simul_equ_display);
					s = 0;
					reset_equ(simul_display);
				}

				if (equ_equalcount == 7)
				{
					reset_equ(simul_display);
					solveEquations(a1, b1, c1, a2, b2, c2, simul_equ_display);
				}
			}
		}

		if (my > column2 && my < (column2 + 50))
		{
			if ((mx > row1 && mx < (row1 + 50)))
			{

				simul_equ_display[s] = '1';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row2 && mx < (row2 + 50)))
			{

				simul_equ_display[s] = '2';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				simul_equ_display[s] = '3';
				simul_equ_display[s + 1] = 0;
				s++;
			}
		}
		if (my > column3 && my < (column3 + 50))
		{
			if ((mx > row1 && mx < (row1 + 50)))
			{
				simul_equ_display[s] = '4';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row2 && mx < (row2 + 50)))
			{
				simul_equ_display[s] = '5';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				simul_equ_display[s] = '6';
				simul_equ_display[s + 1] = 0;
				s++;
			}
			if ((mx > row4 && mx < (row4 + 50)))
			{
				simul_equ_display[s] = '-';
				simul_equ_display[s + 1] = 0;
				s++;
			}
			if ((mx > row5 && mx < (row5 + 50)))
			{
				reset_equ(display_store);
				reset_equ(simul_display);
				reset_equ(simul_equ_display);
				setmode = 3;
				settheme = 1;
				equ_equalcount = 0;
				s = 0;
				i = 0;
				t = 0;
			}
		}
		if (my > column4 && my < (column4 + 50))
		{
			if ((mx > row1 && mx < (row1 + 50)))
			{
				simul_equ_display[s] = '7';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row2 && mx < (row2 + 50)))
			{
				simul_equ_display[s] = '8';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				simul_equ_display[s] = '9';
				simul_equ_display[s + 1] = 0;
				s++;
			}

			if ((mx > row4 && mx < (row4 + 50)))
			{
				simul_equ_display[s - 1] = 0;
				s--;
			}

			if ((mx > row5 && mx < (row5 + 50))) // ON
			{
				for (int ijk = 0; ijk < strlen(simul_equ_display); ijk++)
				{
					simul_equ_display[ijk] = 0;
				}
				s = 0;
				equ_equalcount = 0;
				strcpy(simul_display, "Enter a1:");
			}
		}
	}
	else if (setmode == 2) // quadratic
	{
		if (my > column1 && my < (column1 + 50))
		{
			if ((mx > row2 && mx < (row2 + 50)))
			{
				quad_equ_display[t] = '.';
				quad_equ_display[t + 1] = 0;
				t++;
			}
			if ((mx > row1 && mx < (row1 + 50)))
			{
				quad_equ_display[t] = '0';
				quad_equ_display[t + 1] = 0;
				t++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{ // main code
				equ_equalcount++;

				if (equ_equalcount == 1)
				{

					sscanf(quad_equ_display, "%lf", &a);

					reset_equ(quad_equ_display);
					t = 0;
					strcpy(quad_display, "Enter b:");
				}
				if (equ_equalcount == 2)
				{

					sscanf(quad_equ_display, "%lf", &b);

					reset_equ(quad_equ_display);
					t = 0;
					strcpy(quad_display, "Enter c:");
				}
				if (equ_equalcount == 3)
				{

					sscanf(quad_equ_display, "%lf", &c);
					reset_equ(quad_display);
					reset_equ(quad_equ_display);
					t = 0;
				}

				if (equ_equalcount == 4)
				{
					reset_equ(quad_display);
					solvequad(a, b, c, quad_equ_display);
				}
			}
		}

		if (my > column2 && my < (column2 + 50))
		{
			if ((mx > row1 && mx < (row1 + 50)))
			{

				quad_equ_display[t] = '1';
				quad_equ_display[t + 1] = 0;
				t++;
			}

			if ((mx > row2 && mx < (row2 + 50)))
			{

				quad_equ_display[t] = '2';
				quad_equ_display[t + 1] = 0;
				t++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				quad_equ_display[t] = '3';
				quad_equ_display[t + 1] = 0;
				t++;
			}
		}
		if (my > column3 && my < (column3 + 50))
		{
			if ((mx > row1 && mx < (row1 + 50)))
			{
				quad_equ_display[t] = '4';
				quad_equ_display[t + 1] = 0;
				t++;
			}

			if ((mx > row2 && mx < (row2 + 50)))
			{
				quad_equ_display[t] = '5';
				quad_equ_display[t + 1] = 0;
				t++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				quad_equ_display[t] = '6';
				quad_equ_display[t + 1] = 0;
				t++;
			}
			if ((mx > row4 && mx < (row4 + 50)))
			{
				quad_equ_display[t] = '-';
				quad_equ_display[t + 1] = 0;
				t++;
			}
		}
		if (my > column4 && my < (column4 + 50))
		{
			if ((mx > row1 && mx < (row1 + 50)))
			{
				quad_equ_display[t] = '7';
				quad_equ_display[t + 1] = 0;
				t++;
				;
			}

			if ((mx > row2 && mx < (row2 + 50)))
			{
				quad_equ_display[t] = '8';
				quad_equ_display[t + 1] = 0;
				t++;
			}

			if ((mx > row3 && mx < (row3 + 50)))
			{
				quad_equ_display[t] = '9';
				quad_equ_display[t + 1] = 0;
				t++;
			}

			if ((mx > row4 && mx < (row4 + 50)))
			{
				quad_equ_display[t - 1] = 0;
				t--;
			}

			if ((mx > row5 && mx < (row5 + 50)))
			{
				reset_equ(quad_equ_display);
				t = 0;
				equ_equalcount = 0;
				strcpy(quad_display, "Enter a:");
			}
		}
	}
}

/*
	function iKeyboard() is called whenever the user hits a key in keyboard.
	key- holds the ASCII value of the key pressed.
	*/
void iKeyboard(unsigned char key)
{

	// place your codes for other keys here
}

/*
	function iSpecialKeyboard() is called whenver user hits special keys like-
	function keys, home, end, pg up, pg down, arraows etc. you have to use
	appropriate constants to detect them. A list is:
	GLUT_KEY_F1, GLUT_KEY_F2, GLUT_KEY_F3, GLUT_KEY_F4, GLUT_KEY_F5, GLUT_KEY_F6,
	GLUT_KEY_F7, GLUT_KEY_F8, GLUT_KEY_F9, GLUT_KEY_F10, GLUT_KEY_F11, GLUT_KEY_F12,
	GLUT_KEY_LEFT, GLUT_KEY_UP, GLUT_KEY_RIGHT, GLUT_KEY_DOWN, GLUT_KEY_PAGE UP,
	GLUT_KEY_PAGE DOWN, GLUT_KEY_HOME, GLUT_KEY_END, GLUT_KEY_INSERT
	*/
void iSpecialKeyboard(unsigned char key)
{

	if (key == GLUT_KEY_END)
	{
		exit(0);
	}
	// place your codes for other keys here
}

int main()
{
	// place your own initialization codes here.
	iInitialize(screenwidth, screenlength, "Scientific Calculator");
	//iFilledCircle(10, 10, 5, 5);
	return 0;
}
