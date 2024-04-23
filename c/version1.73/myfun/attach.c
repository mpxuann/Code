#include"myfun.h"
#include<math.h>

Point TriAttach(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	Point ans;
	ans = TriAttachPoints(pt, t, r, Outlines, cnt);
	if(ans.x || ans.y){
		pt->attached = 1; 
		return ans;
	}
	ans = TriAttachLines(pt, t, r, Outlines, cnt);
	if(ans.x || ans.y){
		pt->attached = 1; 
		return ans;
	}
	InitPoint(&ans);
	return ans;
}

Point RecAttach(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	Point ans;
	ans = RecAttachPoints(pr, t, r, Outlines, cnt);
	if(ans.x || ans.y){
		pr->attached = 1; 
		return ans;
	}
	ans = RecAttachLines(pr, t, r, Outlines, cnt);
	if(ans.x || ans.y){
		pr->attached = 1; 
		return ans;
	}
	InitPoint(&ans);
	return ans;
}

Point Distance(Point A, Point B, Point FileA, Point FileB){//return a vector moving towards, by two lines
	Point ans;
	InitPoint(&ans);
	if(!isParallel(A, B, FileA, FileB) || !isClose(A, B, FileA, FileB)){
		return ans;
	}
	Point p1 = PointMinus(A, FileA);
	Point p2 = PointMinus(A, FileB);
	double s = crossProduct(p1, p2);
	if(s < 0) s = -s;
	double a = (FileA.x - FileB.x) * (FileA.x - FileB.x) 
		+ (FileA.y - FileB.y) * (FileA.y - FileB.y);
	double h = s / a;
	ans.x = h * (FileA.y - FileB.y);
	if(ans.x < 0) ans.x = -ans.x;
	ans.y = h * (FileA.x - FileB.x);
	if(ans.y < 0) ans.y = -ans.y;
	
	
	if(FileA.x == FileB.x){
		if(A.x > FileA.x){
			ans.x = -ans.x;
		}
		return ans;
	}
	if(FileA.y == FileB.y){
		if(A.y > FileA.y){
			ans.y = -ans.y;
		}
		return ans;
	}
	double k = (A.y - B.y) / (A.x - B.x);
	a = k * (A.x - FileA.x) + FileA.y;
	if(k > 0){
		if(A.y > a){
			ans.y = -ans.y;
		}
		if(A.y < a){
			ans.x = -ans.x;
		}
	}else if(k < 0){
		if(A.y > a){
			ans.x = -ans.x;
			ans.y = -ans.y;
		}
	}
	return ans;
}

int isParallel(Point A, Point B, Point FileA, Point FileB){
	double a1 = (A.y - B.y) * (FileA.x - FileB.x) ;
	double a2 = (FileA.y - FileB.y) * (A.x - B.x) ;
	if(a1 - a2 > -EPSILON && a1 - a2 < EPSILON){
		return 1;
	}
	return 0;
}

int isClose(Point A, Point B, Point FileA, Point FileB){
	Point p1, p2;
	p1 = PointMinus(A, FileA);
	p2 = PointMinus(A, FileB);
	if(pointProduct(p1, p2) < 0) return 1;
	p1 = PointMinus(B, FileA);
	p2 = PointMinus(B, FileB);
	if(pointProduct(p1, p2) < 0) return 1;
	p1 = PointMinus(A, FileA);
	p2 = PointMinus(B, FileA);
	if(pointProduct(p1, p2) < 0) return 1;
	p1 = PointMinus(A, FileB);
	p2 = PointMinus(B, FileB);
	if(pointProduct(p1, p2) < 0) return 1;
	return 0;
}

Point TriAttachOneLine(Triangle* pt, Point p1, Point p2){
	Point ans;
	double sqrCurEpsilon = 0;
	for(int i = 0; i < 3; i++){
		ans = Distance(pt->A[i%3], pt->A[(i+1)%3], p1, p2);
		sqrCurEpsilon = ans.x * ans.x + ans.y * ans.y;
		if((ans.x || ans.y) && sqrCurEpsilon < 0.1){
			ans.x = -ans.x;
			ans.y = -ans.y;
			return ans;
		}
	}
	InitPoint(&ans);
	return ans;
}

Point TriAttachLines(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt){ 
	Point ans;
	int i, j;
	for(i = 1; i < cnt; i++){
		ans = TriAttachOneLine(pt, Outlines[i-1], Outlines[i]);
		if(ans.x || ans.y){
//					pt->attached = 1; 

			return ans;
		}
	}
	ans = TriAttachOneLine(pt, Outlines[cnt-1], Outlines[0]);
	if(ans.x || ans.y){
//				pt->attached = 1; 

		return ans;
	}
	
	for(i = 0; i < 5; i++){
		if(!((t+i)->attached)) continue;
		for(j = 0; j < 3; j++){
			ans = TriAttachOneLine(pt, t[i].A[j%3], t[i].A[(j+1)%3]);
			if(ans.x || ans.y){
//						pt->attached = 1; 

				return ans;
			}
		}
	}
	
	for(i = 0; i < 2; i++){
		if(!((r+i)->attached)) continue;
		for(j = 0; j < 4; j++){
			ans = TriAttachOneLine(pt, r[i].A[j%4], r[i].A[(j+1)%3]);
			if(ans.x || ans.y){
//						pt->attached = 1; 

				return ans;
			}
		}
	}
	
	InitPoint(&ans);
	return ans;
}

Point RecAttachOneLine(Rectangle* pr, Point p1, Point p2){
	Point ans;
	double sqrCurEpsilon;
	for(int i = 0; i < 4; i++){
		ans = Distance(pr->A[i%4], pr->A[(i+1)%4], p1, p2);
		sqrCurEpsilon = ans.x * ans.x + ans.y * ans.y;
		if((ans.x || ans.y) && sqrCurEpsilon < 0.1){
			ans.x = -ans.x;
			ans.y = -ans.y;
			return ans;
		}
	}
	InitPoint(&ans);
	return ans;
}

Point RecAttachLines(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	Point ans;
	int i, j;
	for(i = 1; i < cnt; i++){
		ans = RecAttachOneLine(pr, Outlines[i-1], Outlines[i]);
		if(ans.x || ans.y){
//			pr->attached = 1;
			return ans;
		}
	}
	ans = RecAttachOneLine(pr, Outlines[cnt-1], Outlines[0]);
	if(ans.x || ans.y){
//		pr->attached = 1;
		return ans;
	}
	
	for(i = 0; i < 5; i++){
		if(!((t+i)->attached)) continue;
		for(j = 0; j < 3; j++){
			ans = RecAttachOneLine(pr, t[i].A[j%3], t[i].A[(j+1)%3]);
			if(ans.x || ans.y){
//				pr->attached = 1;
				return ans;
			}
		}
	}
	
	for(i = 0; i < 2; i++){
		if(!((r+i)->attached)) continue;
		for(j = 0; j < 4; j++){
			ans = RecAttachOneLine(pr, r[i].A[j%4], r[i].A[(j+1)%3]);
			if(ans.x || ans.y){
//				pr->attached = 1;
				return ans;
			}
		}
	}
	
	InitPoint(&ans);
	return ans;
}

Point TriAttachOnePoint(Triangle* pt, Point point){//attach to one point
	Point ans;
	double sqrDistance;
	for(int i = 0; i < 3; i++){
		ans = PointMinus(pt->A[i], point);
		sqrDistance = ans.x * ans.x + ans.y * ans.y;
		if(sqrDistance < 0.1){
			return ans;
		}
	}
	InitPoint(&ans);
	return ans;
}

Point TriAttachPoints(Triangle* pt, Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	Point ans;
	int i, j;
	for(i = 0; i < cnt; i++){
		ans = TriAttachOnePoint(pt, Outlines[i]);
		if(ans.x || ans.y){
			return ans;
		}
	}

	for(i = 0; i < 5; i++){
		if(!((t+i)->attached)) continue;
		/****/
		for(j = 0; j < 3; j++){
			ans = TriAttachOnePoint(pt, t[i].A[j]);
			if(ans.x || ans.y){
				return ans;
			}
		}
		/****/
	}	
	
	
	for(i = 0; i < 2; i++){
		if(!((r+i)->attached)) continue;
		for(j = 0; j < 4; j++){
			ans = TriAttachOnePoint(pt, r[i].A[j]);
			if(ans.x || ans.y){
				return ans;				
			}
		}
	}
	InitPoint(&ans);
	return ans;
}

Point RecAttachOnePoint(Rectangle* pr, Point point){
	Point ans;
	double sqrDistance;
	for(int i = 0; i < 4; i++){
		ans = PointMinus(pr->A[i], point);
		sqrDistance = ans.x * ans.x + ans.y * ans.y;
		if(sqrDistance < 0.1){
			return ans;
		}
	}
	InitPoint(&ans);
	return ans;
}

Point RecAttachPoints(Rectangle* pr, Triangle* t, Rectangle* r, Point* Outlines, int cnt){
	Point ans;
	int i, j;
	for(i = 0; i < cnt; i++){
		ans = RecAttachOnePoint(pr, Outlines[i]);
		if(ans.x || ans.y){
//			pr->attached = 1;
			return ans;
		}
	}
	for(i = 0; i < 5; i++){
		if(!((t+i)->attached)) continue;
		for(j = 0; j < 3; j++){
			ans = RecAttachOnePoint(pr, t[i].A[j]);
			if(ans.x || ans.y){
//				pr->attached = 1;
				return ans;
			}
		}
	}
	for(i = 0; i < 2; i++){
		if(!((r+i)->attached)) continue;
		for(j = 0; j < 4; j++){
			ans = RecAttachOnePoint(pr, r[i].A[j]);
			if(ans.x || ans.y){
//				pr->attached = 1;
				return ans;
			}				
		}
	}
	InitPoint(&ans);
	return ans;
}




//Point TriAttachTri(char* name, int id, char mem, Triangle* t){
//	Point Delta;
//	int count = 0;
//	Point temp;
//	Point Deltas[3];
//	InitPoint(&Delta);
//	InitPoint(&Deltas[1]);
//	InitPoint(&Deltas[2]);
//	InitPoint(&Deltas[3]);
//	
//	Triangle modeTri;
//	InitTri(&modeTri);
//	GetTriPosition(name, id, mem, &modeTri);
//	count = GetTriToTriDelta(Deltas, t, &modeTri);
////	if(count == 0){
////		InitPoint(&Delta);
////	}
//	if(count == 1){
//		Delta = Deltas[1];
//	}
//	
//	return Delta;
//}

//int GetTriToTriDelta(Point* Delta, Triangle* t, Triangle* modeTri){
//	Point temp;
//	int count = 0;
//	double sqrDis;
//	double sqrEPSILON = EPSILON * EPSILON;
//	temp = Distance((*t).A[0], (*t).A[1], (*modeTri).A[0], (*modeTri).A[1]);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).A[1], (*t).A[2], (*modeTri).A[0], (*modeTri).A[1]);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).A[2], (*t).A[0], (*modeTri).A[0], (*modeTri).A[1]);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).A, (*t).B, (*modeTri).A, (*modeTri).C);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).A, (*t).C, (*modeTri).A, (*modeTri).C);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).B, (*t).C, (*modeTri).A, (*modeTri).C);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).A, (*t).B, (*modeTri).C, (*modeTri).B);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).A, (*t).C, (*modeTri).C, (*modeTri).B);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	temp = Distance((*t).C, (*t).B, (*modeTri).C, (*modeTri).B);
//	sqrDis = (temp.x) * (temp.x) + (temp.y) * (temp.y);
//	if(sqrDis < sqrEPSILON){
//		Delta[count] = temp;
//		count++;
//	}
//	return count;
//}
