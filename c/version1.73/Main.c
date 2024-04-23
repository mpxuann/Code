#include<stdio.h>
#include"graphics.h"
#include"imgui.h"
#include"extgraph.h"
#include"myfun.h"
#include"extgraph.h" 

struct{
	Point A;
	double ab_x, ca_y;
	char* pointedColor;
	char* unpointedColor;
}initPositions[5] = {
	{{1, 1.1}, 1, 1, "Light Gray", "Red"},
	{{2.2, 1.1}, 1, 1, "Light Gray", "Green"},
	{{3.4, 2.1}, 2, 2, "Light Gray", "Blue"},
	{{1, 3.2}, 2, 2, "Light Gray", "Yellow"},
	{{3.2, 3.9}, 2*ROTATE, 2*ROTATE, "Light Gray", "Orange"},
};
struct{
	Point A;
	double ab_x;
	Point ac, ad;
	char* pointedColor;
	char* unpointedColor;
}initRecPositions[2] = {
	{{1, 5}, 1, {1, -1}, {0, -1}, "Light Gray", "Magenta"},
	{{2.2, 5}, 1, {2, -1}, {1, -1}, "Light Gray", "Cyan"}
};

Point MousePoint, Delta;
Point AttachDelta;
Triangle t[5];
Rectangle r[2];
int move[7] = {0};
int pointed[7] = {0};
//int attached[7] = {0};
int findThePointed = 0;
int i = 0;
int memory = 0;
//int shapeColored = 0;
FILE* fp;
//Triangle shownTri;
Triangle tempTri;
Rectangle tempRec;
Point Outlines[30];
int cnt;
int Win = 0;
int Mode = 0;
Point tempPoint1 = {8, 5};
Point tempPoint2 = {8, 10};
Point deltaTemp;
double h;

void display(void);
void myMouseEvent(int mx, int my, int button, int event);
void DisplayButton(void);
void StartTris(void);
void RecordDelta(Point MousePoint, Triangle* t, Rectangle* r);
void StartRecs(void);
void StartMode(void);



void display(){
	DisplayClear();
	DisplayButton();
	cnt = GetOutlines("outline.txt", Mode, Outlines);
	StartMode();
	if(Win){
		h = GetFontHeight() * 2;
		drawBox(3, 1, 10, h, 1, "You win!", 'L', "Light Gray");
//		MovePen(3, 3);
//		DrawLine(1, 0);
	}
	//Initialize
	findThePointed = 0;
	for(i = 0; i < 7; i++){
		*(pointed+i) = 0;
	}
	for(i = 0; i < 7 && !findThePointed; i++){//find the pointed one
		if(*(move+i)){
//			*(pointed+i) = 1;
			findThePointed = 1;
		}
	}
	for(i = 0; i < 5 && !findThePointed; i++){
		if(isInsideTri(MousePoint, *(t + i))){
			*(pointed+i) = 1;
			findThePointed = 1;
		}
	}
	for(i = 0; i < 2 && !findThePointed; i++){
		if(isInsideRec(MousePoint, *(r + i))){
			*(pointed+i+5) = 1;
			findThePointed = 1;
		}
	}
	for(i = 1; i >= 0; i--){//set pen color and draw
		if(*(pointed+i+5)){
			SetPenColor((*(r+i)).pointedColor);
//			SetPenColor("Red");
		}else{
			SetPenColor((*(r+i)).unpointedColor);
//			SetPenColor("Blue");
		}
		drawRec(*(r + i), 1);
	}
	for(i = 4; i >= 0; i--){
		if(*(pointed+i)){
			SetPenColor((*(t+i)).pointedColor);
//			SetPenColor("Red");
		}else{
			SetPenColor((*(t+i)).unpointedColor);
//			SetPenColor("Blue");
		}
//		if(*(move+i)){
//			drawTriangle(shownTri, 1);
//		}else{
		drawTriangle(*(t + i), 1);				
//		}
	}
		
}

void RecordDelta(Point MousePoint, Triangle* t, Rectangle* r){
	for(i = 0; i < 5; i++){
		if(isInsideTri(MousePoint, *(t+i))){
			memory = i;
			*(move+i) = 1;
			(t+i)->attached = 0;
//			shownTri = *(t+i);
			Delta = PointMinus(MousePoint, (*(t+i)).A[0]);
			return;
		}
	}
	for(i = 0; i < 2; i++){
		if(isInsideRec(MousePoint, *(r+i))){
			memory = i + 5;
			*(move+i+5) = 1;
			(r+i)->attached = 0;
			Delta = PointMinus(MousePoint, (*(r+i)).A[0]);
			return;
		}
	}
}

void myMouseEvent(int mx, int my, int button, int event){
	uiGetMouse(mx, my, button, event);
	MousePoint.x = ScaleXInches(mx);
	MousePoint.y = GetWindowHeight() - ScaleXInches(my);
	switch(event){
		case BUTTON_DOWN :
			RecordDelta(MousePoint, t, r);
			Win = 0;
			break;
		case BUTTON_UP:
			for(i = 0; i < 5; i++){
				if(*(move+i)){
					
					AttachDelta = TriAttach(t+i, t, r, Outlines, cnt);
//					AttachDelta = TriAttachOnePoint(t+i, Outlines[3]);
//					AttachDelta = TriAttachPoints(t+i, t, r, Outlines, cnt);
//					AttachDelta = TriAttachLines(t+i, t, r, Outlines, cnt);
//					AttachDelta = TriAttachOneLine(t+i, tempPoint1, tempPoint2);
//					AttachDelta = TriAttachOneLine(t+i, Outlines[1], Outlines[2]);
					MoveTri(t+i, (*(t+i)).A[0], AttachDelta);
				}
			}
			for(i = 0; i < 2; i++){
				if(*(move+i+5)){
					AttachDelta = RecAttach(r+i, t, r, Outlines, cnt);
//					AttachDelta = RecAttachOnePoint(r+i, Outlines[3]);
//					AttachDelta = RecAttachPoints(r+i, t, r, Outlines, cnt);
					MoveRec(r+i, (*(r+i)).A[0], AttachDelta);
				}
			}
			if(Judge(t, r, Outlines, cnt)) Win = 1;
//			if(JudgeTri(t+4, t, r, Outlines, cnt)) Win = 1;
//			if(notOutsideOutlines(((t+1)->A)+1, Outlines, cnt)) Win = 1;
//			if(pointInPolygon(&MousePoint, Outlines, cnt)) Win = 1;
//			if(isOnEdge(((r+1)->A), Outlines, cnt)) Win = 1; 
			for(i = 0; i < 7; i++)
				*(move+i) = 0;
			break;
		case MOUSEMOVE:
			for(i = 0; i < 5; i++){
				if(*(move+i)){
					MoveTri((t+i), MousePoint, Delta);
				}
			}
			for(i = 0; i < 2; i++){
				if(*(move+i+5)){
					MoveRec((r+i), MousePoint, Delta);
				}
			}
			break;
	}
	
	display();
} 

void DisplayButton(){
	if(button(GenUIID(0), 0, GetWindowHeight() - 1, 2, 0.5, "ÄæÊ±Õë")) {
		Rotate(t, r, 0, memory);
	}
	if(button(GenUIID(0), 0, GetWindowHeight() - 0.5, 2, 0.5, "Ë³Ê±Õë")) {
		Rotate(t, r, 1, memory);
	}
	if(button(GenUIID(0), 12, GetWindowHeight() - 0.5, 2, 0.5, "Mode1")) {
		Mode = 1;
		Win = 0; 
	}
	if(button(GenUIID(0), 12, GetWindowHeight() - 1, 2, 0.5, "Mode2")) {
		Mode = 2;
		Win = 0;
	}
}

void StartTris(){
	for(i = 0; i < 5; i++){
		InitTri(t + i);
		(*(t + i)).A[0] = initPositions[i].A;
		(*(t + i)).ab[0].x = initPositions[i].ab_x;
		(*(t + i)).ab[2].y = initPositions[i].ca_y;
		UpdateTri(t + i);
		(*(t+i)).pointedColor = initPositions[i].pointedColor;	
		(*(t+i)).unpointedColor = initPositions[i].unpointedColor;		
	}

}

void StartRecs(){
	for(i = 0; i < 2; i++){
		InitRec(r+i);
		(*(r+i)).A[0] = initRecPositions[i].A;
		(*(r+i)).ab[0].x = initRecPositions[i].ab_x;
		(*(r+i)).ab[1] = initRecPositions[i].ac;
		(*(r+i)).ab[2] = initRecPositions[i].ad;
		UpdateRec(r+i);
		(*(r+i)).pointedColor = initRecPositions[i].pointedColor;
		(*(r+i)).unpointedColor = initRecPositions[i].unpointedColor;
	}
}

void StartMode(){
//	SetPenColor("Black");
//	for(i = 0; i < 5; i++){
//		GetTriPosition("data.txt", 1, 'A'+i, &tempTri);
//		drawTriangle(tempTri, 1);		
//	}
//	for(i = 0; i < 2; i++){
//		GetRecPosition("data.txt", 1, 'F'+i, &tempRec);
//		drawRec(tempRec, 1);
//	}
//	GetTriPosition("data.txt", 1, 'A', &tempTri);
//	drawTriangle(tempTri, 1);
	DrawOutline(Outlines, cnt);
//	MovePen(tempPoint1.x, tempPoint1.y);
//	deltaTemp = PointMinus(tempPoint2, tempPoint1);
//	DrawLine(deltaTemp.x, deltaTemp.y);
}

void Main()
{
//	DefineColor("PRed", .8, 0, 0);
//	DefineColor("PGreen", 0, .8, 0);
//	DefineColor("PBlue", 0, 0, .8);
//	DefineColor("PYellow", .5, .5, 0);
//	DefineColor("POrange", .8, .32, 0);
//	DefineColor("PMagenta", .8, 0, .8);
//	DefineColor("PCyan", 0, .8, .8);
	InitPoint(&Delta);
	MousePoint.x = 1;
	MousePoint.y = 1;
	StartTris();
	StartRecs();


	SetWindowTitle("myPro001");
	InitGraphics();
	InitGUI();
	registerMouseEvent(myMouseEvent);
}
