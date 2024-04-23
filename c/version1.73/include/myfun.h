
#ifndef _myfun_h
#define _myfun_h


#define ROTATE 0.7071067812
#define EPSILON 1
#include<stdio.h>
#include<stdlib.h>
typedef struct{
	double x, y;
} Point;

typedef struct{
	Point A[3];
	Point ab[3];//ab, bc, ca;
//	char pointedColor[80];
//	char unpointedColor[80];
//	Point s_A, s_B, s_C;
//	Point s_ab, s_bc, s_ca;
	char* pointedColor;
	char* unpointedColor;
	int attached;
} Triangle;

typedef struct{
	Point A[4];
	Point ab[5];//ab, ac, ad, bc, cd;
//	char pointedColor[80];
//	char unpointedColor[80];
//	Point s_A, s_B, s_C, s_D;
//	Point s_ab, s_ac, s_ad, s_bc, s_cd;
	char* pointedColor;
	char* unpointedColor; 
	int attached;
}Rectangle;


/**********   draw.c           ************/

char* intTOstring(int n);

void drawTriangle(Triangle, double);

void drawRec(Rectangle rectangle, double);

void RotateTri(Triangle* tri, int n, int);//0counter

void RotateRec(Rectangle* rec, int n, int);//0counter

void Rotate(Triangle* t, Rectangle* r, int n, int memory);

void MoveTri(Triangle* t, Point MousePoint, Point Delta);

void MoveRec(Rectangle* r, Point MousePoint, Point Delta);

void DrawOutline(Point* p, int cnt);


/*************  init.c       *************************/
void InitPoint(Point* point);

void InitTri(Triangle* triangle);

void InitRec(Rectangle* rectangle);

void UpdateTriABC(Triangle*);

void UpdateTriDelta(Triangle*);

void UpdateRecABCD(Rectangle* rectangle);

void UpdateRecDelta(Rectangle* rectangle);

void UpdateTri(Triangle* tri);

void UpdateRec(Rectangle* rectangle);



/***********  pointcalculation.c          ******************/
Point PointAdd(Point p1, Point p2);

Point PointMinus(Point p1, Point p2);

double crossProduct(Point p1, Point p2);

double pointProduct(Point p1, Point p2);

/************ inside.c       **********************/





/********     file.c            ************/

long Locate(char* name, int id, char mem);

void ModeFill(FILE* fp, int id, char mem);

void GetTriPosition(char* name, int id, char mem, Triangle* t);

void GetRecPosition(char* name, int id, char mem, Rectangle* r);


/**********   judge.c        *********************/
int Judge(Triangle* t, Rectangle* r, Point* Outlines, int cnt);

int JudgeTri(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

int JudgeRec(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

//int notOutsideOutlines(Point* p, Point* Outlines, int cnt);

//int isCrossed(Point* p, Point* p1, Point* p2);

int isOnLine(Point* p, Point* p1, Point* p2);

int isOnEdge(Point* p, Point* Outlines, int cnt);

char isInsideTri(Point MousePoint, Triangle tri);

char isInsideRec(Point MousePoint, Rectangle rec);

int pointInPolygon(Point* p, Point* Outlines, int cnt);

double DistancePointToLine(Point* p, Point* p1, Point* p2);

/**********   attach.c           ***************/

Point TriAttach(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

Point RecAttach(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

int isParallel(Point A, Point B, Point FileA, Point FileB);

Point Distance(Point A, Point B, Point FileA, Point FileB);

int GetTriToTriDelta(Point* Delta, Triangle* t, Triangle* modeTri);

Point TriAttachTri(char* name, int id, char mem, Triangle* t);

int isClose(Point A, Point B, Point FileA, Point FileB);

Point TriAttachOneLine(Triangle* pt, Point p1, Point p2);

Point TriAttachLines(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

Point RecAttachOneLine(Rectangle* pr, Point p1, Point p2);

Point TriAttachLines(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

Point RecAttachLines(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

Point TriAttachOnePoint(Triangle* pt, Point point);

Point TriAttachPoints(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt);

Point RecAttachOnePoint(Rectangle* pr, Point point);

Point RecAttachPoints(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt);
/***********   outlinefile.c *************/

int GetOutlines(char* name, int id, Point *p);

void GetPointPosition(char* name, long locate, int num, Point* p);

long LocateId(char* name, int id);

#endif
