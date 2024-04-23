#include<stdio.h>


#include"graphics.h"
#include"imgui.h"
#include"extgraph.h"
#include"myfun.h"

Point PointAdd(Point p1, Point p2){
	Point ans;
	ans.x = p1.x + p2.x;
	ans.y = p1.y + p2.y;
	return ans;
}

Point PointMinus(Point p1, Point p2){
	Point ans;
	ans.x = p1.x - p2.x;
	ans.y = p1.y - p2.y;
	return ans;
}


double crossProduct(Point p1, Point p2){
	return p1.x * p2.y - p1.y * p2.x;
}

double pointProduct(Point p1, Point p2){
	return (p1.x * p2.x + p1.y * p2.y);
}
