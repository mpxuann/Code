#include<stdio.h>
#include<stdlib.h>



#include"graphics.h"
#include"imgui.h"
#include"extgraph.h"
#include"myfun.h"

extern Point LimitPoint;
extern double LimitLen;
extern int Win;
extern int Mode;
extern int ShowModeButtons;
extern int CurrentTime, SetTime;
extern int Stop;
extern int Mode;
//char chosen[30] = "选择模式：养生"; 


void drawTriangle(Triangle triangle, double fill){
	
//	MovePen(triangle.A.x - 1, triangle.A.y - 1);
//	MovePen(MousePoint.x - delta.x, MousePoint.y - delta.y);
//	MovePen(MousePoint.x, MousePoint.y);
	MovePen(triangle.A[0].x, triangle.A[0].y);

	StartFilledRegion(fill); 
	{
		DrawLine(triangle.ab[0].x, triangle.ab[0].y);
		DrawLine(triangle.ab[1].x, triangle.ab[1].y);
		DrawLine(triangle.ab[2].x, triangle.ab[2].y);
//		DrawLine(1, 0);
//		DrawLine(0, 1);
//		DrawLine(-1, -1);
	}
	EndFilledRegion();
}

void RotateTri(Triangle* tri, int n, int memory){
	double x, y;
	x = (*(tri+memory)).ab[0].x;
	y = (*(tri+memory)).ab[0].y;
	switch(n){
		case 0:
			(*(tri+memory)).ab[0].x = (x - y) * ROTATE;
			(*(tri+memory)).ab[0].y = (x + y) * ROTATE;
			break;
		case 1:
			(*(tri+memory)).ab[0].x = (x + y) * ROTATE;
			(*(tri+memory)).ab[0].y = (y - x) * ROTATE;	
			break;		
	}
	x = (*(tri+memory)).ab[2].x;
	y = (*(tri+memory)).ab[2].y;
	switch(n){
		case 0:
			(*(tri+memory)).ab[2].x = (x - y) * ROTATE;
			(*(tri+memory)).ab[2].y = (x + y) * ROTATE;
			break;
		case 1:
			(*(tri+memory)).ab[2].x = (x + y) * ROTATE;
			(*(tri+memory)).ab[2].y = (y - x) * ROTATE;	
			break;		
	}
	UpdateTri(tri+memory);
}

void MoveTri(Triangle* t, Point MousePoint, Point Delta){
	(*t).A[0] = PointMinus(&MousePoint, &Delta);
	UpdateTriABC(t);
}


void drawRec(Rectangle rectangle, double fill){
	MovePen(rectangle.A[0].x, rectangle.A[0].y);
	StartFilledRegion(fill); 
	{
		DrawLine(rectangle.ab[0].x, rectangle.ab[0].y);
		DrawLine(rectangle.ab[3].x, rectangle.ab[3].y);
		DrawLine(rectangle.ab[4].x, rectangle.ab[4].y);
		DrawLine(-rectangle.ab[2].x, -rectangle.ab[2].y);
	}
	EndFilledRegion();
}

void MoveRec(Rectangle* r, Point MousePoint, Point Delta){
	(*r).A[0] = PointMinus(&MousePoint, &Delta);
	UpdateRecABCD(r);
}

void RotateRec(Rectangle* rec, int n, int memory){
	double x, y;
	x = (*(rec+memory-5)).ab[0].x;
	y = (*(rec+memory-5)).ab[0].y;
	switch(n){
		case 0:
			(*(rec+memory-5)).ab[0].x = (x - y) * ROTATE;
			(*(rec+memory-5)).ab[0].y = (x + y) * ROTATE;
			break;
		case 1:
			(*(rec+memory-5)).ab[0].x = (x + y) * ROTATE;
			(*(rec+memory-5)).ab[0].y = (y - x) * ROTATE;	
			break;		
	}
	x = (*(rec+memory-5)).ab[1].x;
	y = (*(rec+memory-5)).ab[1].y;
	switch(n){
		case 0:
			(*(rec+memory-5)).ab[1].x = (x - y) * ROTATE;
			(*(rec+memory-5)).ab[1].y = (x + y) * ROTATE;
			break;
		case 1:
			(*(rec+memory-5)).ab[1].x = (x + y) * ROTATE;
			(*(rec+memory-5)).ab[1].y = (y - x) * ROTATE;	
			break;		
	}
	x = (*(rec+memory-5)).ab[2].x;
	y = (*(rec+memory-5)).ab[2].y;
	switch(n){
		case 0:
			(*(rec+memory-5)).ab[2].x = (x - y) * ROTATE;
			(*(rec+memory-5)).ab[2].y = (x + y) * ROTATE;
			break;
		case 1:
			(*(rec+memory-5)).ab[2].x = (x + y) * ROTATE;
			(*(rec+memory-5)).ab[2].y = (y - x) * ROTATE;	
			break;		
	}
	UpdateRec(rec+memory-5);
}

void Rotate(Triangle* t, Rectangle* r, int n, int memory){
	if(memory < 5){
		RotateTri(t, n, memory);
	}else{
		RotateRec(r, n, memory);
	}
}


void DrawOutline(Point* p, int cnt){
	SetPenColor("Black");
	MovePen(p->x, p->y);
//	StartFilledRegion(1);
	for(int i = 1; i < cnt; i++){
		DrawLine((*(p+i)).x - (*(p+i-1)).x, (*(p+i)).y - (*(p+i-1)).y);
	}
	DrawLine((*(p)).x - (*(p+cnt-1)).x, (*(p)).y - (*(p+cnt-1)).y);
//	EndFilledRegion();
//	FILE* fp;
//	if((fp = fopen(name, "r")) == NULL) exit(0);
//	rewind(fp);
//	fscanf(fp, "no.%d {%lf,%lf,%lf,%lf,%lf,%lf}", 
//		&id, &(t.A.x), &(t.A.y), &(t.ab.x), &(t.ab.y), &(t.ca.x), &(t.ca.y));
////	fscanf(fp, "%lf %lf", &(t.A.x), &(t.A.y));
//	if(fclose(fp)) exit(0);
//	UpdateTri(&t);
//	SetPenColor("Black");
//	drawTriangle(t, 1);
////	OpenConsole();
////	printf("%lf", t.A.y);
////	system("pause");
////	CloseConsole();
}


void DrawLimitLines(){
	SetPenColor("Black");
	MovePen(LimitPoint.x, LimitPoint.y);
	DrawLine(LimitLen, 0);
	DrawLine(0, LimitLen);
	DrawLine(-LimitLen, 0);
	DrawLine(0, -LimitLen);
} 

void DrawTimer(){
	char str[40];
	sprintf(str, "%d", CurrentTime);
	if(CurrentTime >= 0 /*&& !Win*/) drawBox(6.5, GetWindowHeight() - 1, 3, 1, 1, str, 'M', "White");
	char* str1 = "暂停中";
	SetPenColor("White");
	if(Stop == 1 && !Win) drawBox(6.5, GetWindowHeight() - 1.5, 3, 0.5, 1, str1, 'M', "Red");
}

void DrawMenu(){
//	char * menuListFile[] = {chosen,  
//		"养生",  // 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
//		"简单",           
//		"困难"};// 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
//	int selection;
//
//	selection = menuList(GenUIID(0), 12, GetWindowHeight() - 4, 2, 2, 0.5, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
//
//	switch(selection){
//		case 1:{
//			SetTime = -1; 
//			chosen[0] =  '\0';
//			strcat(chosen, "选择模式：养生"); 
//			break;
//		} 
//		case 2:{
//			SetTime = 100;
//			chosen[0] =  '\0';
//			strcat(chosen, "选择模式：简单"); 
//			break;
//		}
//		case 3:{
//			SetTime = 10;
//			chosen[0] =  '\0';
//			strcat(chosen, "选择模式：困难"); 
//			break;
//		}
//	}
}

void DisplayModeButtons(){
	if(button(GenUIID(0), 12, GetWindowHeight() - 0.5, 2, 0.5, "Mode1")) {
		Mode = 1;
//		Win = 0;
		ShowModeButtons = 0;
		if(Stop != 2)Stop = 1;
		CurrentTime = SetTime;
	}
	if(button(GenUIID(0), 12, GetWindowHeight() - 1, 2, 0.5, "Mode2")) {
		Mode = 2;
//		Win = 0;
		ShowModeButtons = 0;
		if(Stop != 2)Stop = 1;
		CurrentTime = SetTime;
	}
	if(button(GenUIID(0), 12, GetWindowHeight() - 1.5, 2, 0.5, "ModeTest")) {
		Mode = 3;
//		Win = 0;
		ShowModeButtons = 0;
		if(Stop != 2)Stop = 1;
		CurrentTime = SetTime;
	}
}

void ShowModeState(){
	char strMode[40];
	sprintf(strMode, "%s%d", "当前题目：", Mode);
	SetPenColor("White");
	drawBox(6.5, GetWindowHeight() - 2, 3, 0.5, 1, strMode, 'M', "Black");
	SetPenColor("Black");
}


