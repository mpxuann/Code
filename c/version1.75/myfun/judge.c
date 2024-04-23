#include<math.h>
#include"myfun.h"

extern int HintTime, Mode;

//const double eps = 1e-6;
//const double PI = acos(-1);
////三态函数，判断两个double在eps精度下的大小关系
//int dcmp(double x)
//{
//    if(fabs(x)<eps) return 0;
//    else
//        return x<0?-1:1;
//}
////判断点Q是否在P1和P2的线段上
//bool OnSegment(Point P1,Point P2,Point Q)
//{
//    //前一个判断点Q在P1P2直线上 后一个判断在P1P2范围上
//    return dcmp((P1-Q)^(P2-Q))==0&&dcmp((P1-Q)*(P2-Q))<=0;
//}
////判断点P在多边形内-射线法
//bool InPolygon(Point P)
//{
//    bool flag = false; //相当于计数
//    Point P1,P2; //多边形一条边的两个顶点
//    for(int i=1,j=n;i<=n;j=i++)
//    {
//        //polygon[]是给出多边形的顶点
//        P1 = polygon[i];
//        P2 = polygon[j];
//        if(OnSegment(P1,P2,P)) return true; //点在多边形一条边上
//        //前一个判断min(P1.y,P2.y)<P.y<=max(P1.y,P2.y)
//        //这个判断代码我觉得写的很精妙 我网上看的 应该是大神模版
//        //后一个判断被测点 在 射线与边交点 的左边
//        if( (dcmp(P1.y-P.y)>0 != dcmp(P2.y-P.y)>0) && dcmp(P.x - (P.y-P1.y)*(P1.x-P2.x)/(P1.y-P2.y)-P1.x)<0)
//            flag = !flag;
//    }
//    return flag;
//}

int JudgeOnePoint(Point* p, Point* Outlines, int cnt, Triangle* t, Rectangle* r){
	if(!notOutsideOutlines(p, Outlines, cnt)) return 1;
	int i;
	for(i = 0; i < 5; i++){
		if(isInsideTri(p, t+i)) return 1;
	}
	for(i = 0; i < 2; i++){
		if(isInsideRec(p, r+i)) return 1;
	}
	return 0;
}

int JudgePoints(Point* Outlines, int cnt, Triangle* t, Rectangle* r){
	Point p = {6.01, 3.01};
	while(p.y < 7){
		p.x = 6.01;
		while(p.x < 10){
			if(!JudgeOnePoint(&p, Outlines, cnt, t, r)) return 0;
			p.x += 0.01;
		}
		p.y += 0.01;
	}
	return 1;
}


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
			if(isInsideTri((pt->A)+j, (t+i))) return 0;
		}
	}
	for(i = 0; i < 2; i++){
		for(j = 0; j < 3; j++){
			if(isInsideRec((pt->A)+j, (r+i))) return 0;
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
			if(isInsideTri((pr->A)+j, (t+i))) return 0;
		}
	}
	for(i = 0; i < 2; i++){
		for(j = 0; j < 4; j++){
			if(isInsideRec((pr->A)+j, (r+i))) return 0;
		}
	}
	return 1;
}

int isOnLine(Point* p, Point* p1, Point* p2){
//	if(p->x == p1->x && p->y == p1->y || p->x == p2->x && p->y == p2->y) return 1;
	Point a = PointMinus(p, p1);
	Point b = PointMinus(p, p2);
	if(a.x * b.x > 0 || a.y * b.y > 0) return 0;
	if(a.x * b.y == a.y * b.x) return 1;
	return 0;
}

int isOnEdge(Point* p, Point* Outlines, int cnt){
	for(int i = 0, j = cnt - 1; i < cnt; j = i++){
		if(isOnLine(p, Outlines+i, Outlines+j)) return 1;
	}
	return 0;
}

char isInsideTri(Point* MousePoint, Triangle* tri){
	for(int k = 1; k < 3; k++){
		if(PointCloseLine(MousePoint, &(tri->A[k-1]), &(tri->A[k])) && DistancePointToLine(MousePoint, &(tri->A[k-1]), &(tri->A[k])) < 0.01) return 1;	
	}
	if(PointCloseLine(MousePoint, &(tri->A[2]), &(tri->A[0])) && DistancePointToLine(MousePoint, &(tri->A[2]), &(tri->A[0])) < 0.01) return 1;
	Point p1, p2, p3;
	p1 = PointMinus(&(tri->A[0]), MousePoint);
	p2 = PointMinus(&(tri->A[1]), MousePoint);
	p3 = PointMinus(&(tri->A[2]), MousePoint);
	double t1, t2, t3;
	t1 = crossProduct(&p1, &p2);
	t2 = crossProduct(&p2, &p3);
	t3 = crossProduct(&p3, &p1);
	if(t1 >= 0 && t2 >= 0 && t3 >= 0 || t1 <= 0 && t2 <= 0 && t3 <= 0){
		return 1;
	}
	return 0;
}

char isInsideRec(Point* MousePoint, Rectangle* rec){
	for(int k = 1; k < 4; k++){
		if(PointCloseLine(MousePoint, &(rec->A[k-1]), &(rec->A[k])) && DistancePointToLine(MousePoint, &(rec->A[k-1]), &(rec->A[k])) < 0.01) return 1;	
	}
	if(PointCloseLine(MousePoint, &(rec->A[3]), &(rec->A[0])) && DistancePointToLine(MousePoint, &(rec->A[3]), &(rec->A[0])) < 0.01) return 1;
	Point p1, p2, p3, p4;
	p1 = PointMinus(&(rec->A[0]), MousePoint);
	p2 = PointMinus(&(rec->A[1]), MousePoint);
	p3 = PointMinus(&(rec->A[2]), MousePoint);
	p4 = PointMinus(&(rec->A[3]), MousePoint);
	double t1, t2, t3, t4;
	t1 = crossProduct(&p1, &p2);
	t2 = crossProduct(&p2, &p3);
	t3 = crossProduct(&p3, &p4);
	t4 = crossProduct(&p4, &p1);
	if(t1 >= 0 && t2 >= 0 && t3 >= 0 && t4 >= 0 || t1 <= 0 && t2 <= 0 && t3 <= 0 && t4 <= 0){
		return 1;
	}
	return 0;
}

int pointInPolygon(Point* p, Point* Outlines, int cnt) {
//	for(int k = 1; k < cnt; k++){
//		if(DistancePointToLine(p, Outlines+k-1, Outlines+k) < 0.01) return 1;	
//	}
//	if(DistancePointToLine(p, Outlines+cnt-1, Outlines) < 0.01) return 1;
//	
	int   i, j = cnt;
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
	Point a = PointMinus(p, p1);
	Point b = PointMinus(p, p2);
	double s = crossProduct(&a, &b);
	if(s < 0) s = -s;
	double l = (p1->x - p2->x) * (p1->x - p2->x) 
		+ (p1->y - p2->y) * (p1->y - p2->y);
	double h = s / sqrt(l);
	return h;
}

int notOutsideOutlines(Point* p, Point* Outlines, int cnt){
	if(isOnEdge(p, Outlines, cnt)) return 1;
	int counter = 0;
	for(int i = 1; i < cnt; i++){
		if(isCrossed(p, Outlines+i-1, Outlines+i)) counter++;
	}
	if(isCrossed(p, Outlines+cnt-1, Outlines)) counter++;
	return counter%2;
}

int isCrossed(Point* p, Point* p1, Point* p2){//prerequest not on line
	if((p->y - p1->y) * (p->y - p2->y) > 0) return 0;
	double ymax, ymin;
	if(p1->y < p2->y){
		ymax = p2->y;
		ymin = p1->y;
	}else{
		ymax = p1->y;
		ymin = p2->y;
	}
	if(p->y == ymin) return 0;
	double crosspointx = (p->y - p1->y) * (p1->x - p2->x) / (p1->y - p2->y) + p1->x;
	if(p->x < crosspointx) return 1;
	return 0;
}

void Hint(){
	SetPenColor("Light Gray");
	HintTime++;
	if(HintTime > 7) HintTime -= 7;
	if(HintTime <= 5){
		Triangle tri;
		GetTriPosition("answer.txt", Mode, 'A'+HintTime-1, &tri);
		drawTriangle(tri, 1);
	}else{
		Rectangle rec;
		GetRecPosition("answer.txt", Mode, 'A'+HintTime-1, &rec);
		drawRec(rec, 1);
	}
}

