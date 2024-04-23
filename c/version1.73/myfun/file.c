#include<stdio.h>
#include<string.h>
#include"myfun.h"

void Fill(char* name, int id, char mem){
	FILE* fp;
	long locate;
	Triangle t;
	locate = Locate(name, id, mem);
	if((fp = fopen(name, "r")) == NULL) exit(0);
	fp->_ptr += locate;
//	if((fgetc(fp)) == '{'){
//		fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%lf", 
//			&(t.A.x), &(t.A.y), &(t.ab.x), &(t.ab.y), &(t.ca.x), &(t.ca.y));		
//	}
	
	if(fclose(fp)) exit(0);
	UpdateTri(&t);
}

void GetTriPosition(char* name, int id, char mem, Triangle* t){
  	FILE* fp;
	long locate = Locate(name, id, mem);
	InitTri(t);
	if((fp = fopen(name, "r")) == NULL) exit(0);
	fseek(fp, locate, SEEK_SET);
	if((fgetc(fp)) == '{'){
		fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%lf", 
			&((*t).A[0].x), &((*t).A[0].y), &((*t).ab[0].x), &((*t).ab[0].y), &((*t).ab[2].x), &((*t).ab[2].y));		
	}
	if(fclose(fp)) exit(0);
	UpdateTri(t);
}

void GetRecPosition(char* name, int id, char mem, Rectangle* r){
  	FILE* fp;
	long locate = Locate(name, id, mem);
	InitRec(r);
	if((fp = fopen(name, "r")) == NULL) exit(0);
	fseek(fp, locate, SEEK_SET);
	if((fgetc(fp)) == '{'){
		fscanf(fp, "%lf,%lf,%lf,%lf,%lf,%lf,%lf,%lf", 
			&((*r).A[0].x), &((*r).A[0].y), 
			&((*r).ab[0].x), &((*r).ab[0].y), 
			&((*r).ab[1].x), &((*r).ab[1].y), 
			&((*r).ab[2].x), &((*r).ab[2].y));		
	}
	if(fclose(fp)) exit(0);
	UpdateRec(r);
}

long Locate(char* name, int id, char mem){//if not found return -1.
	FILE* fp;
	if((fp = fopen(name, "r")) == NULL) exit(0);
	rewind(fp);
	int currentId = -1;
	long cp = -1;
	char ch;
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '.'){
			fscanf(fp, "%d", &currentId);
			if(id == currentId){
				cp = ftell(fp);
				break;
			}
		}
	}
	if(cp == -1){
		if(fclose(fp)) exit(0);
		return cp;
	}
	cp = -1;
	while((ch = fgetc(fp)) != 'n'){
		if(ch == mem){
			cp = ftell(fp);
			break;
		}
	}
	
	if(fclose(fp)) exit(0);
	return cp;
}

void Insert(char* name, long locate, char* str){//insert after the locate
	FILE* fp;
	FILE* tempfp;
	char ch;
	
	fp = fopen(name, "a+");
	tempfp = fopen("temp.txt", "w");
	for(long i = 0; i < locate; i++){
		ch = fgetc(fp);
		fputc(ch, tempfp);
	}
	int k = strlen(str);
	for(int i = 0; i < k; i++){
		fputc(*(str+i), tempfp);
	}
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch!=EOF)fputc(ch, tempfp);
	}
	fclose(fp);
	fclose(tempfp);
	char del[80] = "del ";
	strcat(del, name);
	char re[80] = "rename ";
	strcat(re, "temp.txt ");
	strcat(re, name);
	system(del);
	system(re);
}

int GetOutlines(char* name, int id, Point *p){//return cnt
	long locate = LocateId(name, id);
	int cnt = 0;
	FILE* fp;
	if((fp = fopen(name, "r")) == NULL) exit(0);
	fseek(fp, locate, SEEK_SET);
	while(fgetc(fp) != 't'){
	}
	fscanf(fp, "%d", &cnt);
	if(fclose(fp)) exit(0);
	for(int i = 0; i < cnt; i++){
		GetPointPosition(name, locate, i+1, p+i);
	}
	return cnt;
}

void GetPointPosition(char* name, long locate, int num, Point* p){
	FILE* fp;
	if((fp = fopen(name, "r")) == NULL) exit(0);
	fseek(fp, locate, SEEK_SET);
	while(fgetc(fp) != '{'){
		fgetc(fp);
	}
	int k = num * 2 - 2;
	double trash;
	for(int i = 0; i < k; i++){
		fscanf(fp, "%lf", &trash);
	}
	fscanf(fp, "%lf %lf", &(*p).x, &(*p).y);
//	while((ch = fgetc(fp)) != 'n'){
//		if(ch == mem){
//			cp = ftell(fp);
//			break;
//		}
//	}
	
	if(fclose(fp)) exit(0);
}

long LocateId(char* name, int id){
	FILE* fp;
	if((fp = fopen(name, "r")) == NULL) exit(0);
	rewind(fp);
	int currentId = -1;
	long cp = -1;
	char ch;
	while(!feof(fp)){
		ch = fgetc(fp);
		if(ch == '.'){
			fscanf(fp, "%d", &currentId);
			if(id == currentId){
				cp = ftell(fp);
				break;
			}
		}
	}
	if(fclose(fp)) exit(0);
	return cp;
}

void OutlineFromData(char* data, char* outline, int id){
	FILE* fpData;
	FILE* fpOutline;
	Triangle t[5];
	Rectangle r[2];
	for(int i = 0; i < 5; i++){
		GetTriPosition(data, id, 'A'+i, t+i);
	}
	for(int i = 0; i < 2; i++){
		GetRecPosition(data, id, 'F'+i, r+i);
	}
	if((fpData = fopen(data, "r")) == NULL) exit(0);
	if((fpOutline = fopen(outline, "r")) == NULL) exit(0);
	
	if(fclose(fpOutline)) exit(0);
	if(fclose(fpData)) exit(0);
}





