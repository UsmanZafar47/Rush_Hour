//============================================================================
// Name        : .cpp
// Author      : FAST CS Department
// Version     :
// Copyright   : (c) Reserved
// Description : Basic 2D game of Rush Hour...
//============================================================================

#ifndef RushHour_CPP_
#define RushHour_CPP_
#include "util.h"
#include <iostream>
#include <sstream>
#include<string>
#include<ctime>
#include<cstdlib>
#include<cmath> // for basic math functions such as cos, sin, sqrt
using namespace std;

void grid();
// seed the random numbers generator by current time (see the documentation of srand for further help)...

/* Function sets canvas size (drawing area) in pixels...
 *  that is what dimensions (x and y) your game will have
 *  Note that the bottom-left coordinate has value (0,0) and top-right coordinate has value (width-1,height-1)
 * */
void SetCanvasSize(int width, int height) {
	glMatrixMode (GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, width, 0, height, -1, 1); // set the screen size to given width and height.
	glMatrixMode (GL_MODELVIEW);
	glLoadIdentity();
}
int menu;

int xI = 0, yI = 780;

void drawCar(){

	
 	DrawRoundRect(xI,yI,30,25,colors[RED],6);	
	DrawCircle(xI, yI, 5, colors[BLACK]);
	DrawCircle(xI+30, yI, 5, colors[BLACK]);
	DrawCircle(xI, yI+25, 5, colors[BLACK]);
	DrawCircle(xI+30, yI+25, 5, colors[BLACK]);
	glutPostRedisplay();
}
int xI1=0,yI1=780;
void drawCar2() {

	DrawRoundRect(xI1,yI1,30,25,colors[YELLOW],6);
	DrawCircle(xI1, yI1, 5, colors[BLACK]);
	DrawCircle(xI1+30, yI1, 5, colors[BLACK]);
	DrawCircle(xI1, yI1+25, 5, colors[BLACK]);
	DrawCircle(xI1+30, yI1+25, 5, colors[BLACK]);
	glutPostRedisplay();
}
// enemy car one
int enemy_xI = 300,enemy_yI = 400;
void draw_enemy_car1()
{
	DrawRoundRect(enemy_xI,enemy_yI,30,25,colors[BLUE],6);
	DrawCircle(enemy_xI, enemy_yI, 5, colors[BLACK]);
	DrawCircle(enemy_xI+30,enemy_yI, 5, colors[BLACK]);
	DrawCircle(enemy_xI, enemy_yI+25, 5, colors[BLACK]);
	DrawCircle(enemy_xI+30, enemy_yI+25, 5, colors[BLACK]);
	glutPostRedisplay();
}

//enemy car 2
int enemy2_xI = 20, enemy2_yI = 320;
void draw_enemy_car2()
{	
	DrawRoundRect(enemy2_xI,enemy2_yI,30,25,colors[SPRING_GREEN],6);
	DrawCircle(enemy2_xI, enemy2_yI, 5, colors[BLACK]);
	DrawCircle(enemy2_xI+30,enemy2_yI, 5, colors[BLACK]);
	DrawCircle(enemy2_xI, enemy2_yI+25, 5, colors[BLACK]);
	DrawCircle(enemy2_xI+30, enemy2_yI+25, 5, colors[BLACK]);
	glutPostRedisplay();

}

//enemy car 3
int enemy3_xI = 610, enemy3_yI = 360;
void draw_enemy_car3()
{	
	DrawRoundRect(enemy3_xI,enemy3_yI,30,25,colors[DARK_CYAN],6);
	DrawCircle(enemy3_xI, enemy3_yI, 5, colors[BLACK]);
	DrawCircle(enemy3_xI+30,enemy3_yI, 5, colors[BLACK]);
	DrawCircle(enemy3_xI, enemy3_yI+25, 5, colors[BLACK]);
	DrawCircle(enemy3_xI+30, enemy3_yI+25, 5, colors[BLACK]);
	glutPostRedisplay();

}

//enemy car 1 move 
bool flag = true;
void moveCar() {
	
	if (enemy_xI > 10 && flag) {
		enemy_xI -= 10;
		//cout << "going left";
		if(enemy_xI < 20)
			
			flag = false;

	}
	else if (enemy_xI < 550 && !flag) {
		//cout << "go right";
		enemy_xI += 10;
		if (enemy_xI > 400)
			flag = true;
	}
}

//enemy car 2 move
bool flag2 = true;
void moveCar2() {
	
	if (enemy2_xI > 10 && flag2) {
		enemy2_xI -= 10;
		//going left 
		if(enemy2_xI < 20)
			
			flag2 = false;

	}
	else if (enemy2_xI < 350 && !flag2) {
		//cout << "go right";
		enemy2_xI += 10;
		if (enemy2_xI > 200)
			flag2 = true;
	}
}

//enemy car 3 move
bool flag3 = true;
void moveCar3() {
	
	if (enemy3_xI > 10 && flag3) {
		enemy3_xI -= 10;
		//cout << "going left";
		if(enemy3_xI < 550)
			
			flag3 = false;

	}
	else if (enemy3_xI < 1010 && !flag3) {
		//cout << "go right";
		enemy3_xI += 10;
		if (enemy3_xI > 940)
			flag3 = true;
	}
}

//pessengers
void pessengers( int px ,int py)
{

	srand(time(0));
       for(int i=0;i<4;i++){	
	DrawCircle(px,py,10,colors[DARK_BLUE]);
	i;
	}
glutPostRedisplay();
}

void Menu()//MENU DISPLAY
{

	glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	DrawSquare(400,400,1200,colors[BLACK]);		
	 DrawString( 400, 600, "RUSH HOUR", colors[WHITE]);
	 
	 DrawString(380,500,"Press ENTER to Start",colors[WHITE]);
	  
	
	 DrawString(400,450,"LEADERBOARD",colors[WHITE]);
	 
	 glutPostRedisplay();

}

int sec =0;
int Min=0;
bool timer()
{
string t="0";
stringstream time(t);

	for(int i=0;i<90;i++)
	{
	
	 DrawString(500,820,"TIME: ",colors[BLACK]);
	 DrawString(584,820,": ",colors[BLACK]);
	DrawString(570,820,to_string(Min),colors[BLACK]);

	 DrawString(590,820,to_string(sec/6000),colors[BLACK]);
		if(sec/6000==60)
		{
		Min+=1;
		sec = 0;
		}
					
		sec++;	 
         i; 
 if(Min==3)
    break;
           }
glutPostRedisplay();
 return true;
}
/*          
 * Main Canvas drawing function.
 * */
//Pessengers

void pessenger(int px,int py)
{
	    DrawCircle(px,py,10,colors[DARK_BLUE]);
	    glutPostRedisplay();
}

//Pessnegrs vaarialbles
int px = (rand()%80)*10;
int py = (rand()%70)*10;

int px1 = (rand()%80)*10;
int py1 = (rand()%70)*10;
int px2 = (rand()%80)*10;
int py2 = (rand()%70)*10;
int px3 = (rand()%80)*10;
int py3 = (rand()%70)*10;
//drop off location variables
int dx = 8000;
int dy = 7000;

bool psnger_wipe1();
bool dropoff(int,int);
bool dropoffpoint(int,int);
//drop off radnom genreator
int dx1=(rand()%90)*10;
int dy1=(rand()%70)*10;
int dx2=(rand()%80)*10;
int dy2=(rand()%60)*10;
int dx3=(rand()%70)*10;
int dy3=(rand()%50)*10;
int dx4=(rand()%70)*10;
int dy4=(rand()%60)*10;


//score
int score=0;
void Score()
{
 
 	for(int i=0;i<40;i++)
	{
	
	 DrawString(50,820,"Score: ",colors[BLACK]);	 
	 DrawString(130,820,to_string(score/3000),colors[BLACK]);
	//score increasing after droping pessenger
		if(xI>=(dx1-10)&&xI<=(dx1+10)&&yI>=(dy1-10)&&yI<=(dy1+10))
		 score += 10;
		
		if(xI>=(dx2-10)&&xI<=(dx2+10)&&yI>=(dy2-10)&&yI<=(dy2+10))
		 score += 10;
		
		if(xI>=(dx3-10)&&xI<=(dx3+10)&&yI>=(dy3-10)&&yI<=(dy3+10))
		 score += 10;
		
		if(xI>=(dx4-10)&&xI<=(dx4+10)&&yI>=(dy4-10)&&yI<=(dy4+10))
		 score += 10;
				
		//negative Points pessnger hiting
		if(xI>=(px-10)&&xI<=(px+10)&&yI>=(py-10)&&yI<=(py+10))
		 score -= 5;
		
		if(xI>=(px1-10)&&xI<=(px1+10)&&yI>=(py1-10)&&yI<=(py1+10))
		 score -= 5;
		
		if(xI>=(px2-10)&&xI<=(px2+10)&&yI>=(py2-10)&&yI<=(py2+10))
		 score -= 5;
		 //negative points of obstacles red texi
		//if(Drawredcar()==true){
		if(xI>=499&&xI<=540&&yI>=720&&yI<=761)//tree
		 score -= 2;
		
		if(xI>=299&&xI<=340&&yI>=560&&yI<=601)//tree
		 score -= 2;
		 
		if(xI>=749&&xI<=790&&yI>=480&&yI<=521)//tree
		 score -= 2;
		 
		if(xI>=449&&xI<=240&&yI>=490&&yI<=281)//trees
		 score -= 2;
		 
		if(xI>=210&&xI<=250&&yI>=200&&yI<=240)//box
		 score -= 2;
		 
		if(xI>=810&&xI<=850&&yI>=160&&yI<=200)//box
		 score -= 2;
		 
		if(xI>=160&&xI<=200&&yI>=640&&yI<=680)//box
		 score -= 2;
		//}
		//negative points of obstacles yellow taxi
		if(xI>=500&&xI<=540&&yI>=720&&yI<=760)//tree
		 score -= 4;
		
		if(xI>=300&&xI<=340&&yI>=560&&yI<=600)//tree
		 score -= 4;
		 
		if(xI>=750&&xI<=790&&yI>=480&&yI<=520)//tree
		 score -= 4;
		 
		if(xI>=450&&xI<=240&&yI>=490&&yI<=280)//trees
		 score -= 4;
		 
		if(xI>=210&&xI<=250&&yI>=200&&yI<=240)//box
		 score -= 4;
		 
		if(xI>=810&&xI<=850&&yI>=160&&yI<=200)//box
		 score -= 4;
		 
		if(xI>=160&&xI<=200&&yI>=640&&yI<=680)//box
		 score -= 4;
		 
		i; 
        }
//glutPostRedisplay();


}


void GameDisplay()/**/{
	// set the background color using function glClearColor.
	// to change the background play with the red, green and blue values below.
	// Note that r, g and b values must be in the range [0,1] where 0 means dim rid and 1 means pure red and so on.
 	
 	if(menu==1)
 	{
 	 Menu();
 	}
 	else if(menu==2)
 	{
 	
 		glClearColor(0/*Red Component*/, 0,	//148.0/255/*Green Component*/,
			0.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour
	DrawSquare(200,400,1200,colors[BLACK]);		
	 DrawString( 400, 600, "Red TAXI", colors[WHITE]);
	 
	 DrawString(380,500,"Yellow Taxi",colors[WHITE]);
	  
	
	 DrawString(400,450,"Random",colors[WHITE]);
	 
	 glutPostRedisplay();

 	
 	}
 	
 	else if(menu==5)
	drawCar();
	else if(menu==4)
	drawCar2();
 	
 	else if(menu==3){
  glClearColor(1/*Red Component*/, 1,	//148.0/255/*Green Component*/,
			1.0/*Blue Component*/, 0 /*Alpha component*/); // Red==Green==Blue==1 --> White Colour

  	glClear (GL_COLOR_BUFFER_BIT); //Update the colors
	//Red Square
	//DrawSquare(400, 20, 40, colors[RED]);
	
	//Green Square
	//DrawSquare( 250 , 250 ,20,colors[GREEN]); 

	//Display Score
	//DrawString( 50, 810, "Score=0", colors[BLUE]);
	
	// Trianlge Vertices v1(300,50) , v2(500,50) , v3(400,250)
	//DrawTriangle( 300, 450 , 340, 450 , 320 , 490, colors[YELLOW] ); 
	

	//Grid 20x20
	//DrawLine(int x1, int y1, int x2, int y2, int lwidth, float *color)
	DrawLine( 1 , 4 ,  1000 , 4 , 1 , colors[BLACK] );	
	DrawLine( 1 , 800 ,  1000 , 800 , 1 , colors[BLACK] );
	DrawLine( 2 , 4 ,  2 , 800 , 1 , colors[BLACK] );
	grid();
	
	//Buildings bottom half middle ___| shape
	DrawRectangle(350,200,250,40,colors[BLACK]);
	DrawRectangle(550,200,50,120,colors[BLACK]);
		
	//Middle building --1
	DrawRectangle(350,360,150,40,colors[BLACK]);
	DrawRectangle(450,360,50,80,colors[BLACK]);
	
	//middle small box building
	DrawRectangle(450,480,50,40,colors[BLACK]);
	
	//Buildings 2nd line horizontal buildings right
	DrawRectangle(450,680,550,40,colors[BLACK]);
	//2nd line small building left
	DrawRectangle(100,680,150,40,colors[BLACK]);
		
	//Buildings 3x2 box
	DrawRectangle(100,160,100,120,colors[BLACK]);
	
	//Buildings -\ shape top left side
	DrawRectangle(350,520,50,160,colors[BLACK]);
	DrawRectangle(250,520,150,40,colors[BLACK]);	
	
	//Buildings top left upside down L
	DrawRectangle(150,440,50,120,colors[BLACK]);
	DrawRectangle(100,520,100,40,colors[BLACK]);	
	
	//right vertical building
	DrawRectangle(900,440,50,200,colors[BLACK]);
	//left vertical building bottom middle
	DrawRectangle(250,80,50,280,colors[BLACK]);
	
	// vertical |-- building
	DrawRectangle(600,400,50,240,colors[BLACK]);	
	DrawRectangle(650,520,150,40,colors[BLACK]);
	
	//right bottom horizontal building
	DrawRectangle(850,40,100,40,colors[BLACK]);
	//bottom vertical building start from 2 becuz my grid start from 2 on y-axis
	DrawRectangle(450,2,50,118,colors[BLACK]);
	
	//right |--- building bottom right
	DrawRectangle(700,240,300,40,colors[BLACK]);
	DrawRectangle(700,120,50,160,colors[BLACK]);
	
	//trees Obstacle
	DrawTriangle( 500, 720 ,540, 720 , 520 , 760, colors[GREEN] );//right top tree
	DrawTriangle( 300, 560 ,340, 560 , 320 , 600, colors[GREEN] );//2nd left tree from top
	DrawTriangle( 750, 480 ,790, 480 , 770 , 520, colors[GREEN] );// right most tree from top middle
	DrawTriangle( 450, 240 ,490, 240 , 470 , 280, colors[GREEN] );// Middle Bottom tree 
	
	//Boxes Obstacle
	DrawSquare( 210 , 200 ,40,colors[BURLY_WOOD]); //left bottom box
	DrawSquare( 810 , 160 ,40,colors[BURLY_WOOD]);//Right bottom box 
	DrawSquare( 160 , 640 ,40,colors[BURLY_WOOD]); //top left box
	
	/*DrawCircle(50,670,10,colors[RED]);
	DrawCircle(70,670,10,colors[RED]);
	DrawCircle(90,670,10,colors[RED]);
	DrawRoundRect(500,200,50,100,colors[DARK_SEA_GREEN],70);
	DrawRoundRect(100,200,100,50,colors[DARK_OLIVE_GREEN],20);	
	DrawRoundRect(100,100,50,100,colors[DARK_OLIVE_GREEN],30);
	DrawRoundRect(200,100,100,50,colors[LIME_GREEN],40);
	DrawRoundRect(350,100,100,50,colors[LIME_GREEN],20);
	*/
	drawCar();

	draw_enemy_car1();//enemy car1
	draw_enemy_car2();//enemy car2
	draw_enemy_car3();//enemy car3
	//DrawCircle(530,400,10,colors[DARK_BLUE]);


	   
	   pessengers(px,py);
	   pessengers(px1,py1);
	   pessengers(px2,py2);
	   pessengers(px3,py3);
	  
	  // dropoff(dx,dy);
	   timer();

	   dropoffpoint(dx,dy);
	   
	   Score();}
	/*
	   if(!(xI==510 && yI == 400))
	   pessenger(510,400,colors[DARK_BLUE]);
	   if(xI!=700 && yI != 500)
	   pessenger(700,500,colors[DARK_BLUE]);
 	   if(xI!=830 && yI != 60)
	   pessenger(830,60,colors[DARK_BLUE]);*/
	  
	
	glutSwapBuffers(); // do not modify this line..


}
//checking collusion right
bool collision_right()
{
	if(xI==180&&yI>=180&&yI<=230)//box
	return true;
	 
	if(xI==780&&yI>=140&&yI<=190)//box
	return true;
	 
	if(xI==130&&yI>=620&&yI<=670)//box
	return true;
	
	if(xI==420&&yI>=240 && yI<=270)//tree
	return true;
	
	if(xI==720&&yI>=460 && yI<=570)//tree
	return true;
	
	if(xI==270&&yI>=560 && yI<=590)//tree
	return true;
	
	if(xI==470&&yI>=720 && yI<=750)//tree
	return true;
		
	if(xI==420 && yI>=0 && yI<=110)//bottom middle vertical building
	return true;

	if(xI==970 && yI>=0 && yI<=800)
	return true;//grid collision limit 

	if(xI==320 && yI>=180 && yI<=230)//middle bottom building --| horizontal
	return true;

	if(xI==520 && yI>=200 && yI<=310)//middle bottom building --| vertical line
	return true;

	if(xI==320 && yI>=340 && yI<=390)//horizontal middle of --i
	return true;

	if(xI==420 && yI>=360 && yI<=430)//vertical middle of --i
	return true;
	
	if(xI==420 && yI>=460 && yI<=510)//top middle small block
	return true;

	if(xI==420 && yI>=660 && yI<=710)//2nd line horizontal building right
	return true;

	if(xI==70 && yI>=660 && yI<=710)//2nd line horizontal building left  
	return true;
	
	if(xI==320 && yI>=510 && yI<=670)//left building from top vertical line of shape__1 
	return true;

	if(xI==220 && yI>=500 && yI<=550)//left building from top horizontal line of shape__1 
	return true;
	
	if(xI==70 && yI>=500 && yI<=550)// left building from top horizontal line of shape oppostie L shape 
	return true;

	if(xI==120 && yI>=420 && yI<=550)// left building from top verical line of shape oppostie L shape 
	return true;
	
	if(xI==70 && yI>=140 && yI<=270)// left building from bottom box 3x2
	return true;

	if(xI==220 && yI>=60 && yI<=350)// left building from bottom vertical line 
	return true;

	if(xI==820 && yI>=20 && yI<=70)// right horizontal building from bottom box 
	return true;

	if(xI==670 && yI>=100 && yI<=270)// right building from bottom vertical line of shape |---
	return true;

	if(xI==870 && yI>=420 && yI<=630)// right budling from top vertical line  
	return true;

	if(xI==570 && yI>=380 && yI<=630)// right budling from top vertical line of shape l---
	return true;
	

	return false;
}

bool collision_left()//collision left
{
	 
	if(xI==850&&yI>=140&&yI<=190)//box
	return true;
	 
	if(xI==200&&yI>=620&&yI<=670)//box
	return true;
	
	if(xI==490&&yI>=240 && yI<=270)//tree
	return true;
	
	if(xI==790&&yI>=460 && yI<=570)//tree
	return true;
	
	if(xI==340&&yI>=560 && yI<=590)//tree
	return true;
	
	if(xI==540&&yI>=720 && yI<=750)//tree
	return true;
	
	if(xI==500 && yI>=0 && yI<=110)//bottom middle vertical building
	return true;

	if(xI==0 && yI>=0 && yI<=800)
	return true;//grid collision limit 

	if(xI==600 && yI>=180 && yI<=230)//middle bottom building --| horizontal
	return true;

	if(xI==600 && yI>=210 && yI<=310)//middle bottom building --| vertical line
	return true;

	if(xI==500 && yI>=340 && yI<=390)//horizontal middle of --i
	return true;

	if(xI==500 && yI>=360 && yI<=430)//vertical middle of --i
	return true;
	
	if(xI==500 && yI>=460 && yI<=510)//top middle small block
	return true;

	if(xI==250 && yI>=660 && yI<=710)//2nd line horizontal building left  
	return true;
	
	if(xI==400 && yI>=500 && yI<=670)//left building from top vertical line of shape__1 
	return true;

	if(xI==300 && yI>=500 && yI<=550)//left building from top horizontal line of shape__1 
	return true;
	
	if(xI==150 && yI>=500 && yI<=550)// left building from top horizontal line of shape oppostie L shape 
	return true;

	if(xI==200 && yI>=420 && yI<=550)// left building from top verical line of shape oppostie L shape 
	return true;
	
	if(xI==200 && yI>=140 && yI<=270)// left building from bottom box 3x2
	return true;

	if(xI==300 && yI>=60 && yI<=350)// left building from bottom vertical line 
	return true;

	if(xI==950 && yI>=20 && yI<=70)// right horizontal building from bottom box 
	return true;

	if(xI==750 && yI>=100 && yI<=270)// right building from bottom vertical line of shape |---
	return true;

	if(xI==950 && yI>=420 && yI<=630)// right budling from top vertical line  
	return true;

	if(xI==650 && yI>=380 && yI<=630)// right budling from top vertical line of shape l---
	return true;
	
	if(xI==800 && yI>=500 && yI<=550)// right budling from top horizantal line of shape l---
	return true;
	

	return false;



}

bool collision_down()//collision down
{
	if(yI==230&&xI>=200&&xI<=280)//box
	return true;
	 
	if(yI==200&&xI>=790&&xI<=840)//box
	return true; 
	
	if(yI==280&&xI>=430 && xI<=480)//tree
	return true;
	
	if(yI==600&&xI>=280 && xI<=330)//tree
	return true;
	
	if(yI==760&&xI>=480 && xI<=530)//tree
	return true;
	
	if(yI==120 && xI>=430 && xI<=490)//bottom middle vertical building
	return true;
	
	if(yI==0 && xI>=0 && xI<=970)
	return true;//grid collision limit 

	if(yI==240 && xI>=330 && xI<=590)//middle bottom building --| horizontal
	return true;

	if(yI==320 && xI>=530 && xI<=590)//middle bottom building --| vertical line
	return true;

	if(yI==520 && xI>=430 && xI<=490)//top middle small block 
	return true;

	if(yI==440 && xI>=430 && xI<=490)//vertical of middle --i
	return true;
	
	if(yI==400 && xI>=330 && xI<=490)//horizontal of middle --i
	return true;

	if(yI==720 && xI>=80 && xI<=240)//2nd line horizontal building left  
	return true;

	if(yI==720 && xI>=430 && xI<=970)//2nd line horizontal building right
	return true;
	
	if(yI==680 && xI>=330 && xI<=390)//left building from top vertical line of shape__1 
	return true;

	if(yI==560 && xI>=230 && xI<=390)//left building from top horizontal line of shape__1 
	return true;
	
	if(yI==560 && xI>=80 && xI<=140)// left building from top horizontal line of shape oppostie L shape 
	return true;

	if(yI==560 && xI>=130 && xI<=190)// left building from top verical line of shape oppostie L shape 
	return true;
	
	if(yI==280 && xI>=80 && xI<=190)// left building from bottom box 3x2
	return true;

	if(yI==360 && xI>=230 && xI<=290)// left building from bottom vertical line 
	return true;

	if(yI==80 && xI>=830 && xI<=940)// right horizontal building from bottom box 
	return true;

	if(yI==280 && xI>=680 && xI<=970)// right building from bottom shape |---
	return true;

	if(yI==640 && xI>=880 && xI<=940)// right budling from top vertical line  
	return true;

	if(yI==640 && xI>=580 && xI<=640)// right budling from top vertical line of shape l---
	return true;
	
	if(yI==560 && xI>=580 && xI<=790)// right budling from top horizantal line of shape l---
	return true;
	
	return false;
}

bool collision_up()//collision up
{
	if(yI==170&&xI>=200&&xI<=280)//box
	return true;
	 
	if(yI==130&&xI>=790&&xI<=840)//box
	return true; 

	if(yI==620&&xI>=130&&xI<=190)//box
	return true;
	
	if(yI==450&&xI>=730 && xI<=780)//tree
	return true;
	
	if(yI==790 && xI>=0 && xI<=970)
	return true;//grid collision limit 

	if(yI==170 && xI>=330 && xI<=590)//middle bottom building --| horizontal
	return true;
	
	if(yI==450 && xI>=430 && xI<=490)//top middle small block 
	return true;

	if(yI==330 && xI>=330 && xI<=490)//horizontal of middle --i
	return true;

	if(yI==650 && xI>=80 && xI<=240)//2nd line horizontal building left  
	return true;

	if(yI==650 && xI>=430 && xI<=970)//2nd line horizontal building right
	return true;
	
	
	if(yI==490 && xI>=230 && xI<=390)//left building from top horizontal line of shape__1 
	return true;
	
	if(yI==490 && xI>=80 && xI<=140)// left building from top horizontal line of shape oppostie L shape 
	return true;

	if(yI==410 && xI>=130 && xI<=190)// left building from top verical line of shape oppostie L shape 
	return true;
	
	if(yI==130 && xI>=80 && xI<=190)// left building from bottom box 3x2
	return true;

	if(yI==50 && xI>=230 && xI<=290)// left building from bottom vertical line 
	return true;

	if(yI==10 && xI>=830 && xI<=940)// right horizontal building from bottom box 
	return true;

	if(yI==210 && xI>=680 && xI<=970)// right horizontal line building from bottom shape |---
	return true;

	if(yI==90 && xI>=680 && xI<=740)// right vertical line building from bottom shape |---
	return true;


	if(yI==410 && xI>=880 && xI<=940)// right budling from top vertical line  
	return true;

	if(yI==370 && xI>=580 && xI<=640)// right budling from top vertical line of shape l---
	return true;
	
	if(yI==490 && xI>=580 && xI<=790)// right budling from top horizantal line of shape l---
	return true;
	
	return false;
}

/*This function is called (automatically) whenever any non-printable key (such as up-arrow, down-arraw)
 * is pressed from the keyboard
 *
 * You will have to add the necessary code here when the arrow keys are pressed or any other key is pressed...
 *
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 *
 * */

void NonPrintableKeys(int key, int x, int y) {
	if (key
			== GLUT_KEY_LEFT /*GLUT_KEY_LEFT is constant and contains ASCII for left arrow key*/) {
		// what to do when left key is pressed...
		if((collision_left())==false)
		{
		 xI -= 10;
		 xI1-= 20;
		}
	} 
	else if (key
			== GLUT_KEY_RIGHT /*GLUT_KEY_RIGHT is constant and contains ASCII for right arrow key*/) {
		if((collision_right())==false)
		{
		 xI += 10;
		 xI1+= 20;
		} 
	} 
	else if (key
			== GLUT_KEY_UP/*GLUT_KEY_UP is constant and contains ASCII for up arrow key*/) {
	  if(collision_up()==false)
	   {
		yI += 10;
		yI1=+ 20;
	   }	
	}

	else if (key
			== GLUT_KEY_DOWN/*GLUT_KEY_DOWN is constant and contains ASCII for down arrow key*/) {
		if(collision_down()==false)	
		{
		  yI -= 10;
		  yI1-= 20;
		}
	}

	/* This function calls the Display function to redo the drawing. Whenever you need to redraw just call
	 * this function*/

	glutPostRedisplay();

}

bool psng=true;
bool psnger_wipe1()//it wipes pessenger
{

	    if(xI>=(px-10)&&xI<=(px+10)&&yI>=(py-10)&&yI<=(py+10))
	    {
	    return false;
	    }
	 return true;   
}	    
bool psnger_wipe2()
{	    
	    if(xI>=(px1-10)&&xI<=(px1+10)&&yI>=(py1-10)&&yI<=(py1+10)){
	    return false;
	    }
	return true;
}	   
bool psnger_wipe3()
{	    
	    if(xI>=(px2-10)&&xI<=(px2+10)&&yI>=(py2-10)&&yI<=(py2+10))
	    {
	    return false;
	    }
	    return true;
}
bool psnger_wipe4()
{	    
	    if(xI>=(px3-10)&&xI<=(px3+10)&&yI>=(py3-10)&&yI<=(py3+10))
	    {
	    return false;
	    }
	    return true;
}


//drop off
bool dropoff(int dxx1,int dyy1)//point the location when near the pessenger even when space not pressed 
{
   	if(psnger_wipe1()!=true)
   	{
   	
	 DrawSquare( dxx1 ,dyy1 ,20,colors[GREEN]);
	 return true;			
	} 
	glutPostRedisplay();

}
//drop off permantlocation 
bool dropoffpoint(int dxx1,int dyy1)
{	
	DrawSquare( dxx1, dyy1, 20,colors[GREEN]);
	glutPostRedisplay();
}


/*This function is called (automatically) whenever any printable key (such as x,b, enter, etc.)
 * is pressed from the keyboard
 * This function has three argument variable key contains the ASCII of the key pressed, while x and y tells the
 * program coordinates of mouse pointer when key was pressed.
 * */
void PrintableKeys(unsigned char key, int x, int y) {
	if (key == 27/* Escape key ASCII*/) {
		exit(1); // exit the program when escape key is pressed.
	}

	if (key == 'b' || key == 'B') //Key for placing the bomb
			{
		//do something if b is pressed
		cout << "b pressed" << endl;

	}
	
	if(key == 'a' || key == 'A')
	{	
	  menu=1;
	}


	if(key == 13)
	{	
	  menu=2;
	}
		
	if(key == 'f' || key == 'F')
	{	
	  menu=3;
	}

	if(key == 'y' || key == 'Y')
	{	
	  menu=4;
	}


	if(key == 'R' || key == 'R')
	{	
	  menu=5;
	}



			
			
  	  if (key == 32)//space bar ascii
	  {
	     //psenger location
	     if((psnger_wipe1()&&dropoffpoint(dx,dy))==false)	    
	     {
	      px=2000;py=2000; 
	      dx=dx1;dy=dy1;
	     
	     }
	     //pessenger drop
	     if(xI>=(dx1-10)&&xI<=(dx1+10)&&yI>=(dy1-10)&&yI<=(dy1+10))
	     {
	      px=dx1;py=dy1;
	      dx1=2000;dy1=2000;
	     }
	     //psenger location
	     if((psnger_wipe2()&&dropoffpoint(dx,dy))==false)	    
	     {
	      px1=2000;py1=2000;
	      dx=dx2;dy=dy2;
	     }
	     //pessenger drop
	     if(xI>=(dx2-10)&&xI<=(dx2+10)&&yI>=(dy2-10)&&yI<=(dy2+10))
	     {
	      px=dx2;py=dy2;
	      dx2=2000;dy2=2000;
	     }
	     //psenger location
	     if((psnger_wipe3()&&dropoffpoint(dx,dy))==false)	    
	     {
	      px2=2000;py2=2000;
	      dx=dx3;dy=dy3;
	     }
	     //pessenger drop
	     if(xI>=(dx3-10)&&xI<=(dx3+10)&&yI>=(dy3-10)&&yI<=(dy3+10))
	     {
	      px=dx3;py=dy3;
	      dx3=2000;dy3=2000;
	     }
	     if((psnger_wipe4()&&dropoffpoint(dx,dy))==false)	    
	     {
	      px3=2000;py3=2000;
	      dx=dx4;dy=dy4;
	     }
	     //pessenger drop
	     if(xI>=(dx4-10)&&xI<=(dx4+10)&&yI>=(dy4-10)&&yI<=(dy4+10))
	     {
	      py3=dy4;px3=dx4;
	      dx4=2000;dy4=2000;
	     } 
	      cout << "space pressed";	
	  }

	
	glutPostRedisplay();
}



/*
 * This function is called after every 1000.0/FPS milliseconds
 * (FPS is defined on in the beginning).
 * You can use this function to animate objects and control the
 * speed of different moving objects by varying the constant FPS.
 *
 * */
void Timer(int m) {

	// implement your functionality here
	moveCar();// 1st enemy car move
	moveCar2();	
	moveCar3();
	// once again we tell the library to call our Timer function after next 1000/FPS
	glutTimerFunc(100, Timer, 0);
}


/*This function is called (automatically) whenever your mouse moves witin inside the game window
 *
 * You will have to add the necessary code here for finding the direction of shooting
 *
 * This function has two arguments: x & y that tells the coordinate of current position of move mouse
 *
 * */
void MousePressedAndMoved(int x, int y) {
	cout << x << " " << y << endl;
	glutPostRedisplay();
}
void MouseMoved(int x, int y) {
	//cout << x << " " << y << endl;
	glutPostRedisplay();
}

/*This function is called (automatically) whenever your mouse button is clicked witin inside the game window
 *
 * You will have to add the necessary code here for shooting, etc.
 *
 * This function has four arguments: button (Left, Middle or Right), state (button is pressed or released),
 * x & y that tells the coordinate of current position of move mouse
 *
 * */
void MouseClicked(int button, int state, int x, int y) {

	if (button == GLUT_LEFT_BUTTON) // dealing only with left button
			{
		//DrawString(400,700,"Press 1 to start\n",colors[WHITE]);
		//DrawString(400,640,"Press 2 to scores\n",colors[WHITE]);

		
		cout << GLUT_DOWN << " " << GLUT_UP << endl;

	} else if (button == GLUT_RIGHT_BUTTON) // dealing with right button
			{
			cout<<"Right Button Pressed"<<endl;

	}
	glutPostRedisplay();
}




void grid()
{
	int i=0;
	for (i;i<=1000;i+=50)
	DrawLine( i , 4 ,  i , 800 , 1 , colors[BLACK] );	

glutPostRedisplay();

}
/*
 * our gateway main function
 * */
int main(int argc, char*argv[]) {

	int width = 1020, height = 840; // i have set my window size to be 800 x 600

	srand(time(0));
	InitRandomizer(); // seed the random number generator...
	glutInit(&argc, argv); // initialize the graphics library...
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA); // we will be using color display mode
	glutInitWindowPosition(50, 50); // set the initial position of our window
	glutInitWindowSize(width, height); // set the size of our window
	glutCreateWindow("Rush Hour by Usman Zafar"); // set the title of our game window
	SetCanvasSize(width, height); // set the number of pixels...

	// Register your functions to the library,
	// you are telling the library names of function to call for different tasks.
	//glutDisplayFunc(display); // tell library which function to call for drawing Canvas.

	glutDisplayFunc(GameDisplay); // tell library which function to call for drawing Canvas.
	glutSpecialFunc(NonPrintableKeys); // tell library which function to call for non-printable ASCII characters
	glutKeyboardFunc(PrintableKeys); // tell library which function to call for printable ASCII characters
	
	// This function tells the library to call our Timer function after 1000.0/FPS milliseconds...
	glutTimerFunc(1000.0, Timer, 0);



	glutMouseFunc(MouseClicked);
	glutPassiveMotionFunc(MouseMoved); // Mouse
	glutMotionFunc(MousePressedAndMoved); // Mouse

	// now handle the control to library and it will call our registered functions when
	// it deems necessary...
	glutMainLoop();
	return 1;
}
#endif /* RushHour_CPP_ */
