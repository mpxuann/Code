#include<stdio.h>
#include<stdlib.h>



#include"graphics.h"
#include"imgui.h"
#include"extgraph.h"
#include"myfun.h"

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
	(*t).A[0] = PointMinus(MousePoint, Delta);
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
	(*r).A[0] = PointMinus(MousePoint, Delta);
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









