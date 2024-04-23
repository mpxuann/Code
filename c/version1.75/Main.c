#include"myfun.h"

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
Point LimitPoint = {6, 3};
double LimitLen = 4;
Triangle t[5];
Rectangle r[2];
int move[7] = {0};
int pointed[7] = {0};
//int attached[7] = {0};
int findThePointed = 0;
int i = 0;
int memory = 0;
int Event;
//int shapeColored = 0;
FILE* fp;
//Triangle shownTri;
Triangle tempTri;
Rectangle tempRec;
Point Outlines[30];
int cnt;
int Win;
int Mode = 1;
int ShowModeButtons = 0; 
Point tempPoint1 = {8, 5};
Point tempPoint2 = {8, 10};
Point deltaTemp = {7.5, 3.5};
double h;
char chosen[30] = "模式：养生";
int Stop = 2;
int CurrentTime, SetTime;
int HintTime = 0; 



void display(void);
void myMouseEvent(int mx, int my, int button, int event);
void DisplayButton(void);
void StartTris(void);
void RecordDelta(Point* MousePoint, Triangle* t, Rectangle* r);
void StartRecs(void);
void StartMode(void);
void DrawPattern(void);

void display(){
	DisplayClear();
	DisplayButton();
	DrawMenu();
	if(ShowModeButtons) DisplayModeButtons();
//	DrawLimitLines();
	cnt = GetOutlines("outline.txt", Mode, Outlines);
	StartMode();
//	DisplayState(Stop);
	DrawTimer();
	ShowModeState();
//	MovePen(1, deltaTemp.y);
//	DrawLine(10, 0);
//	MovePen(deltaTemp.x, 1);
//	DrawLine(0, 10);
	if(!Stop || Win) DrawPattern();
//	if(Win == 1) DrawPattern();
	if(CurrentTime == 0) Win = -1;
	if(Win != -1 && Event == BUTTON_UP && JudgePoints(Outlines, cnt, t, r)) Win = 1;
	if(Win){
		Stop = 1;
		h = GetFontHeight() * 2;
		SetPenColor("Black");
		if(Win == -1)drawBox(3, 1, 10, h, 1, "Time's up!", 'L', "White");
		if(Win == 1)drawBox(3, 1, 10, h, 1, "You win!", 'L', "White");
//		MovePen(3, 3);
//		DrawLine(1, 0);
	}
}

void DrawPattern(){
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
		if(isInsideTri(&MousePoint, (t + i))){
			*(pointed+i) = 1;
			findThePointed = 1;
		}
	}
	for(i = 0; i < 2 && !findThePointed; i++){
		if(isInsideRec(&MousePoint, (r + i))){
			*(pointed+i+5) = 1;
			findThePointed = 1;
		}
	}
	for(i = 1; i >= 0; i--){//set pen color and draw
		if(*(pointed+i+5)){
			SetPenColor((*(r+i)).pointedColor);
		}else{
			SetPenColor((*(r+i)).unpointedColor);
		}
		drawRec(*(r + i), 1);
	}
	for(i = 4; i >= 0; i--){
		if(*(pointed+i)){
			SetPenColor((*(t+i)).pointedColor);
		}else{
			SetPenColor((*(t+i)).unpointedColor);
		}
		drawTriangle(*(t + i), 1);				
	}
}

void RecordDelta(Point* MousePoint, Triangle* t, Rectangle* r){
	for(i = 0; i < 5; i++){
		if(isInsideTri(MousePoint, (t+i))){
			memory = i;
			*(move+i) = 1;
			(t+i)->attached = 0;
//			shownTri = *(t+i);
			Delta = PointMinus(MousePoint, &((t+i)->A[0]));
			return;
		}
	}
	for(i = 0; i < 2; i++){
		if(isInsideRec(MousePoint, (r+i))){
			memory = i + 5;
			*(move+i+5) = 1;
			(r+i)->attached = 0;
			Delta = PointMinus(MousePoint, &((r+i)->A[0]));
			return;
		}
	}
}

void myTimer(int timerID){
	switch(timerID){
		case LimitTimer:
			if(CurrentTime > 0 && !Win && !Stop) CurrentTime--; 
	}
	display();
}

void myMouseEvent(int mx, int my, int button, int event){
	uiGetMouse(mx, my, button, event);
	MousePoint.x = ScaleXInches(mx);
	MousePoint.y = GetWindowHeight() - ScaleXInches(my);
	Event = event;
	switch(event){
		case BUTTON_DOWN :
			if(!Stop) RecordDelta(&MousePoint, t, r);
//			Win = 0;
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
//			if(JudgePoints(Outlines, cnt, t, r)) Win = 1;
//			if(JudgeOnePoint(&deltaTemp, Outlines, cnt, t, r)) Win = 1;
//			if(JudgeOnePoint(&MousePoint, Outlines, cnt, t, r)) Win = 1;
//			if(Judge(t, r, Outlines, cnt)) Win = 1;
//			if(JudgeTri(t+4, t, r, Outlines, cnt)) Win = 1;
//			if(notOutsideOutlines(((t+1)->A)+1, Outlines, cnt)) Win = 1;
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
//			if(JudgeOnePoint(&MousePoint, Outlines, cnt, t, r)) Win = 1;
//			if(pointInPolygon(&MousePoint, Outlines, cnt)) Win = 1;
//			if(notOutsideOutlines(&MousePoint, Outlines, cnt)) Win = 1;
//			if(isCrossed(&MousePoint, Outlines+3, Outlines+2)) Win = 1;
//			if(isCrossed(&deltaTemp, Outlines, Outlines+6)) Win = 1;
//			if(notOutsideOutlines(&deltaTemp, Outlines, cnt)) Win = 1;
//			if(isOnLine(&MousePoint, Outlines, Outlines+1)) Win = 1;
//			if(isOnLine(&deltaTemp, Outlines+2, Outlines+1)) Win = 1;
//			else Win = 0;
			break;
	}
	
	display();
} 

void DisplayButton(){
	if(button(GenUIID(0), 10.8, GetWindowHeight() - 4.5, 1, 0.5, "逆时针")) {
		if(!Stop) Rotate(t, r, 0, memory);
	}
	if(button(GenUIID(0), 10.8, GetWindowHeight() - 5, 1, 0.5, "顺时针")) {
		if(!Stop) Rotate(t, r, 1, memory);
	}
	{
		char * menuListFile[] = {chosen,  
			"养生",  // 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
			"简单",           
			"困难"};// 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
		int selection;
	//	SetPenSize(1);
		selection = menuList(GenUIID(0), 1, GetWindowHeight() - 0.3, 1, 1, 0.3, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
	
		switch(selection){
			case 1:{
				SetTime = 200;
				chosen[0] =  '\0';
				strcat(chosen, "模式：养生");
				Stop = 2;
				break;
			} 
			case 2:{
				SetTime = 100;
				chosen[0] =  '\0';
				strcat(chosen, "模式：简单"); 
				Stop = 2;
				break;
			}
			case 3:{
				SetTime = 10;
				chosen[0] =  '\0';
				strcat(chosen, "模式：困难"); 
				Stop = 2;
				break;
			}
		}
	}
	{
		char * menuListFile[] = {"文件",  
			"选择题目",  // 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
			"打开上次",           
			"保存当前"};// 快捷键必须采用[Ctrl-X]格式，放在字符串的结尾
		int selection;
	//	SetPenSize(1);
		selection = menuList(GenUIID(0), 0, GetWindowHeight() - 0.3, 1, 1, 0.3, menuListFile, sizeof(menuListFile)/sizeof(menuListFile[0]));
	
		switch(selection){
			case 1:{
				ShowModeButtons = 1;
				break;
			} 
			case 2:{
				ReadSavedData("save.txt", t, r, &CurrentTime, &Mode);
				Stop = 1;
//				CurrentTime = SetTime;
				break;
			}
			case 3:{
				SaveCurrentData("save.txt", t, r, CurrentTime, Mode);
				break;
			}
		}
	}
//	if(selection){
//		StartTris(); 
//		StartRecs();
//		CurrentTime = SetTime;
//		Win = 0;
//	}
//	if(Win){
		if(button(GenUIID(0), 12, GetWindowHeight() - 3.5, 2, 0.5, "开始")) {
			StartTris(); 
			StartRecs();
			CurrentTime = SetTime;
			Win = 0;
			Stop = 0;
		}
//	}
	if(button(GenUIID(0), 12, GetWindowHeight() - 3.8, 1, 0.3, "暂停")) {
		if(CurrentTime > 0 && Stop != 2)Stop = 1;
	}
	if(button(GenUIID(0), 13, GetWindowHeight() - 3.8, 1, 0.3, "继续")) {
		if(CurrentTime > 0 && Stop != 2)Stop = 0;
	}
	if(button(GenUIID(0), 12, GetWindowHeight() - 4.5, 2, 0.5, "提示")) {
		Hint();
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
	CurrentTime = -1;
	SetTime = 200; 

	SetWindowTitle("myPro001");
	InitGraphics();
	InitGUI();
	registerMouseEvent(myMouseEvent);
	registerTimerEvent(myTimer);
	startTimer(LimitTimer, 1000);
}
