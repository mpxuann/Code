#include<math.h>
#include"myfun.h"

int Judge(Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	int i;
	for(i = 0; i < 5; i++){
		if(!JudgeTri(t+i, t, r, Outlines, cnt)) return 0;
	}
	for(i = 0; i < 2; i++){
		if(!JudgeRec(r+i, t, r, Outlines, cnt)) return 0;
	}
	return 1;
}

int JudgeTri(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	int i, j;
	for(i = 0; i < 3; i++){
		if(!(pointInPolygon((pt->A)+i, Outlines, cnt) /*|| isOnEdge((pt->A)+i, Outlines, cnt)*/)) return 0;
	}
	for(i = 0; i < 5; i++){
		for(j = 0; j < 3; j++){
			if(isInsideTri(pt->A[j], *(t+i))) return 0;
		}
	}
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			if(isInsideRec(pt->A[j], *(r+i))) return 0;
		}
	}
	return 1;
}

int JudgeRec(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	int i, j;
	for(i = 0; i < 4; i++){
		if(!(pointInPolygon((pr->A)+i, Outlines, cnt) /*|| isOnEdge((pr->A)+i, Outlines, cnt)*/)) return 0;
	}
	for(i = 0; i < 5; i++){
		for(j = 0; j < 4; j++){
			if(isInsideTri(pr->A[j], *(t+i))) return 0;
		}
	}
	for(i = 0; i < 2; i++){
		for(j = 0; j < 4; j++){
			if(isInsideRec(pr->A[j], *(r+i))) return 0;
		}
	}
	return 1;
}

//int notOutsideOutlines(Point* p, Point* Outlines, int cnt){
//	if(isOnEdge(p, Outlines, cnt)) return 1;
//	int counter = 0;
//	for(int i = 1; i < cnt; i++){
//		if(isCrossed(p, Outlines+i-1, Outlines+i)) counter++;
//	}
//	if(isCrossed(p, Outlines+cnt-1, Outlines)) counter++;
//	if(counter%2) return 1;
//	return 0;
//}

//int isCrossed(Point* p, Point* p1, Point* p2){//prerequest not on line
//	if((p->y - p1->y) * (p->y - p2->y) >= 0) return 0;
//	double temp = (p1->y - p2->y) * p->x + (p2->x - p1->x) * p->y + p1->x * p2->y - p2->x * p1->y;
//	if(temp > 0) return 1;
//	return 0;
//}

int isOnLine(Point* p, Point* p1, Point* p2){
	if(p->x == p1->x && p->y == p1->y || p->x == p2->x && p->y == p2->y) return 1;
	Point a = PointMinus(*p, *p1);
	Point b = PointMinus(*p, *p2);
	if(a.x * b.x >= 0 || a.y * b.y >= 0) return 0;
	if(a.x * b.y == a.y * b.x) return 1;
	return 0;
}

int isOnEdge(Point* p, Point* Outlines, int cnt){
	for(int i = 1; i < cnt; i++){
		if(isOnLine(p, Outlines+i-1, Outlines+i)) return 1;
	}
	if(isOnLine(p, Outlines+cnt-1, Outlines)) return 1;
	return 0;
}

char isInsideTri(Point MousePoint, Triangle tri){
	for(int k = 1; k < 3; k++){
		if(DistancePointToLine(&MousePoint, &(tri.A[k-1]), &(tri.A[k])) < 0.001) return 0;	
	}
	if(DistancePointToLine(&MousePoint, &(tri.A[2]), &(tri.A[0])) < 0.001) return 0;
	Point p1, p2, p3;
	p1 = PointMinus(tri.A[0], MousePoint);
	p2 = PointMinus(tri.A[1], MousePoint);
	p3 = PointMinus(tri.A[2], MousePoint);
	double t1, t2, t3;
	t1 = crossProduct(p1, p2);
	t2 = crossProduct(p2, p3);
	t3 = crossProduct(p3, p1);
	if(t1 > 0 && t2 > 0 && t3 > 0 || t1 < 0 && t2 < 0 && t3 < 0){
		return 1;
	}
	return 0;
}

char isInsideRec(Point MousePoint, Rectangle rec){
	for(int k = 1; k < 4; k++){
		if(DistancePointToLine(&MousePoint, &(rec.A[k-1]), &(rec.A[k])) < 0.001) return 0;	
	}
	if(DistancePointToLine(&MousePoint, &(rec.A[2]), &(rec.A[0])) < 0.001) return 0;
	Point p1, p2, p3, p4;
	p1 = PointMinus(rec.A[0], MousePoint);
	p2 = PointMinus(rec.A[1], MousePoint);
	p3 = PointMinus(rec.A[2], MousePoint);
	p4 = PointMinus(rec.A[3], MousePoint);
	double t1, t2, t3, t4;
	t1 = crossProduct(p1, p2);
	t2 = crossProduct(p2, p3);
	t3 = crossProduct(p3, p4);
	t4 = crossProduct(p4, p1);
	if(t1 > 0 && t2 > 0 && t3 > 0 && t4 > 0 || t1 < 0 && t2 < 0 && t3 < 0 && t4 < 0){
		return 1;
	}
	return 0;
}

int pointInPolygon(Point* p, Point* Outlines, int cnt) {
	for(int k = 1; k < cnt; k++){
		if(DistancePointToLine(p, Outlines+k-1, Outlines+k) < 0.01) return 1;	
	}
	if(DistancePointToLine(p, Outlines+cnt-1, Outlines) < 0.01) return 1;
	
	int   i, j = cnt - 1;
	int  oddNodes = 0;

	for(i = 0; i < cnt; i++) {
	    if((Outlines[i].y < p->y && Outlines[j].y >= p->y 
			|| Outlines[j].y < p->y && Outlines[i].y >= p->y) 
			&& (Outlines[i].x <= p->x || Outlines[j].x <= p->x)){
	    	oddNodes ^= (Outlines[i].x + (p->y - Outlines[i].y) 
				/ (Outlines[j].y - Outlines[i].y) 
				* (Outlines[j].x - Outlines[i].x)) < p->x;
		}
	    j = i;
	}
	
	
	
	return oddNodes;
}

double DistancePointToLine(Point* p, Point* p1, Point* p2){
	Point a = PointMinus(*p, *p1);
	Point b = PointMinus(*p, *p2);
	double s = crossProduct(a, b);
	if(s < 0) s = -s;
	double l = (p1->x - p2->x) * (p1->x - p2->x) 
		+ (p1->y - p2->y) * (p1->y - p2->y);
	double h = s / sqrt(l);
	return h;
}

