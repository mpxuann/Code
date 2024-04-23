#include"myfun.h"

void InitPoint(Point* point){
	(*point).x = (*point).y = 0;
}

void InitTri(Triangle* triangle){
	for(int i = 0; i < 3; i++){
		InitPoint(&((*triangle).A[i]));
	}
	for(int i = 0; i < 3; i++){
		InitPoint(&((*triangle).ab[i]));
	}
	triangle->attached = 0;
}

void InitRec(Rectangle* rectangle){
	for(int i = 0; i < 4; i++){
		InitPoint(&((*rectangle).A[i]));
	}
	for(int i = 0; i < 5; i++){
		InitPoint(&((*rectangle).ab[i]));
	}
	rectangle->attached = 0;
}

void UpdateRecABCD(Rectangle* rectangle){
	for(int i = 0; i < 3; i++){
		(*rectangle).A[i+1].x = (*rectangle).ab[i].x + (*rectangle).A[0].x;
		(*rectangle).A[i+1].y = (*rectangle).ab[i].y + (*rectangle).A[0].y;
	}
}

void UpdateRecDelta(Rectangle* rectangle){
	(*rectangle).ab[3].x = (*rectangle).A[2].x - (*rectangle).A[1].x;
	(*rectangle).ab[3].y = (*rectangle).A[2].y - (*rectangle).A[1].y;
	(*rectangle).ab[4].x = (*rectangle).A[3].x - (*rectangle).A[2].x;
	(*rectangle).ab[4].y = (*rectangle).A[3].y - (*rectangle).A[2].y;
}

void UpdateRec(Rectangle* rectangle){
	UpdateRecABCD(rectangle);
	UpdateRecDelta(rectangle);
}

void UpdateTriDelta(Triangle* triangle){
	(*triangle).ab[0].x = (*triangle).A[1].x - (*triangle).A[0].x;
	(*triangle).ab[0].y = (*triangle).A[1].y - (*triangle).A[0].y;
	(*triangle).ab[1].x = (*triangle).A[2].x - (*triangle).A[1].x;
	(*triangle).ab[1].y = (*triangle).A[2].y - (*triangle).A[1].y;
	(*triangle).ab[2].x = (*triangle).A[0].x - (*triangle).A[2].x;
	(*triangle).ab[2].y = (*triangle).A[0].y - (*triangle).A[2].y;
}

void UpdateTriABC(Triangle* triangle){
//	triangle.A.x = triangle.B.x - triangle.A.x;
//	triangle.A.y = triangle.B.y - triangle.A.y;
	(*triangle).A[1].x = (*triangle).ab[0].x + (*triangle).A[0].x;
	(*triangle).A[1].y = (*triangle).ab[0].y + (*triangle).A[0].y;
	(*triangle).A[2].x = (*triangle).A[0].x - (*triangle).ab[2].x;
	(*triangle).A[2].y = (*triangle).A[0].y - (*triangle).ab[2].y;
}

void UpdateTri(Triangle* tri){
	UpdateTriABC(tri);
	UpdateTriDelta(tri);
}

