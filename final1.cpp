#include <iostream>
#include <cmath>
#include <GL/glut.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <iomanip>
#include <locale>
#include <sstream>


//#include "GluCylinders.h"
using namespace std;

#define PI 3.141592653589
#define DEG2RAD(deg) (deg * PI / 180)
#define DEF_D 5

// Function Declarations
void drawScene();
void update1(int value1);
//void update2(int value2);
void drawBox(float len);
void drawBall1(float rad);
void drawBall2(float rad);
void drawBall3(float rad);
void drawTriangle();
void drawBase(float len);
void drawcone();
void drawLINE();
void drawLINE2(float uih);
void drawSB();
void drawGluCylinder(float height, float radius, float slices, float stacks);
void initRendering();
void handleResize(int w, int h);
void handleKeypress1(unsigned char key, int x, int y);
void handleKeypress2(int key, int x, int y);
void handleMouseclick(int button, int state, int x, int y);
void processMouseActiveMotion(int x, int y);
void drawBitmapText(char *string,float x,float y,float z) 
{  
	char *c;
	glRasterPos3f(x, y,z);
	
	for (c=string; *c != '\0'; c++) 
	{
		glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, *c);
	}
}

void drawStrokeText(char*string,int x,int y,int z)
{
	char *c;
	glPushMatrix();
	glTranslatef(x, y+8,z);
	// glScalef(0.09f,-0.08f,z);
	
	for (c=string; *c != '\0'; c++)
	{
		glutStrokeCharacter(GLUT_STROKE_ROMAN , *c);
	}
	glPopMatrix();
}
//void handleMouseclick(int button, int state, int x, int y);

// Global Variables
int m;
int frn;
float ball1_x[100];
float ball1_y[100];
int liv1[100];
float ball1_rad[100];
float ball1_velx[100];
float ball1_vely[100];
float ball2_x[100];
float ball2_y[100];
int liv2[100];
float ball2_rad[100];
float ball2_velx[100];
float ball2_vely[100];
float ball3_x[100];
float ball3_y[100];
int liv3[100];
float ball3_rad[100];
float ball3_velx[100];
float ball3_vely[100];
float stopb1[100];
float stopb2[100];
int flag1=1;
int flag2=1;
int flag3=1;
int flag4=1;
float cri_x_max;
float cri_x_min;
float tri_x_max;
float tri_x_min;
float sri_x_max;
float sri_x_min;
int li;
int ui=0;

//float ball2_x = -1.0f;
//float ball3_x = -1.5f;

//float ball2_y = 1.0f;
//float ball3_y = 1.0f;

//float ball2_velx = 0.00f;
//float ball3_velx = 0.00f;

//float ball2_vely = -0.02f;
//float ball3_vely = -0.02f;

//float ball2_rad = 0.2f;
//float ball3_rad = 0.2f;
float box_len ;
float tri_x = 1.0f;
float tri_y = -2.0f;
float cri_x = -1.0f;
float cri_y = -2.0f;
float theta = 90.0f; 
float heta[100];
float cyrad = 0.75f;
float l2_velx[100] ;
float l2_vely[100] ;
int turn =2;
float l2_x[100];
float l2_y[100];
int livl[100];
float sb_x = 0.0f;
float sb_y = -2.0f;
float gen = 0;
float b;
float l;
int k;
float peta = theta;
int score1;
int score2;
int score3;
char r[10]="SCORE";
char s[3];
string Result;  
//char *p;
int i,j,p,q;
int w1=0;
int w2=0;
char ar2[10];
char ar3[10];
char ar4[10];
char pau[20]="PAUSE";
char gend[20]="GAME_OVER";
float q1;
float b1;
float yu1;
float tu1;
float acce;
float accetimer;


//float  PI=3.14159265358979f;
float ALPHA = 0.5f;
float ALPHA2 = 0.5f;
float ALPHA3 = 0.5f;
float ALPHA4 = 0.5f;
int tim = 10;
float length,height;
float red_position,green_position ,canon_position;
float level;

int main(int argc, char **argv) {

    // Initialize GLUT
    glutInit(&argc, argv);
    
    scanf("%f",&length);
	scanf("%f",&height);
	scanf("%f",&level);
	scanf("%f",&red_position);
	scanf("%f",&green_position);
	scanf("%f",&canon_position);

    box_len = length;
    printf("%f\n",length);
    printf("%f\n",level);
    acce = level;
    cout<<level<<endl;
    cri_x = red_position;
    tri_x = green_position;
    sb_x = canon_position;
   
    //b = int(windowWidth);
    //l = int(windowHeight);
    ball1_x[0] = -box_len/4;
    ball1_y[0] = ((box_len/2)-(box_len/8));
    ball1_velx[0] = 0.0f;
    ball1_vely[0] = -0.02f;
    ball1_rad[0] = (box_len/20);

    ball2_x[0] = -(box_len/4);
    ball2_y[0] = ((box_len/2)-(box_len/8));
    ball2_velx[0] = 0.0f;
    ball2_vely[0] = -0.02f;
    ball2_rad[0] =(box_len/20);


    ball3_x[0] = -(box_len/4);
    ball3_y[0] = ((box_len/2)-(box_len/8));
    ball3_velx[0] = 0.0f;
    ball3_vely[0] = -0.02f;
    ball3_rad[0] =(box_len/20);

    cri_x_max=(box_len/2);
    cri_x_min=-(box_len/2);
    tri_x_min=-(box_len/2);
    tri_x_max=(box_len/2);

    sri_x_min=-(box_len/2);
    sri_x_max=(box_len/2);


    for(i=1;i<50;i++)
    {	ball1_rad[i]=0.2f;
        liv1[i]=0;
		ball1_velx[i]=0.0f;
		ball1_vely[i]=0.0f;
		
		ball2_rad[i]=0.2f;
        liv2[i]=0;
		ball2_velx[i]=0.0f;
		ball2_vely[i]=0.0f;
		
		ball3_rad[i]=0.2f;
        liv3[i]=0;
		ball3_velx[i]=0.0f;
		ball3_vely[i]=0.0f;
        
        l2_y[i]=0.0f;
        l2_x[i]=0.0f;
        livl[i]=0;
        l2_vely[i]=0.0f;
        l2_velx[i]=0.0f;


	}
        srand(time(0));
    turn=1;
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
     int w = glutGet(GLUT_SCREEN_WIDTH);
    int h = glutGet(GLUT_SCREEN_HEIGHT);
    int windowWidth = w * 2 / 3;
    int windowHeight = h * 2 / 3;
    glutInitWindowSize(windowWidth, windowHeight);
    glutInitWindowPosition((w - windowWidth) / 2, (h - windowHeight) / 2);

    glutCreateWindow("CSE251_sampleCode");  // Setup the window
    initRendering();
   

    // Register callbacks
    glutDisplayFunc(drawScene);
    glutIdleFunc(drawScene);
    glutKeyboardFunc(handleKeypress1);
    glutSpecialFunc(handleKeypress2);
    //glutMouseFunc(handleMouseclick);
    glutMouseFunc(handleMouseclick);
    //glutPassiveMotionFunc(processMouseActiveMotion);
    glutMotionFunc(processMouseActiveMotion);
    glutReshapeFunc(handleResize);
    
    glutTimerFunc(10, update1, 0);
	//glutTimerFunc(10, update2, 0);
    glutMainLoop();
    return 0;
}

// Function to draw objects on the screen
void drawScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    
    glPushMatrix();
	
    // Draw Box
    glTranslatef(0.0f, 0.0f, -5.0f);
    glColor3f(1.0f, 0.0f, 0.0f);
    drawBox(box_len);
   glPushMatrix();
   glColor3f(0,1,0);
	 
	//Draw score1
	glRasterPos2f(0.1f, 0.1f);
	//print(2.0f,2.0f,"SCORE:%d", score1);
	sprintf(ar2,"%d",score1);
//strcat(r,ar2);
	drawBitmapText(ar2,3,1.5,0);
   glPopMatrix();
   
   
   
   
   glPushMatrix();
   glColor3f(1,0,0);
	 
	//Draw score2
	glRasterPos2f(0.1f, 0.1f);
	//print(2.0f,2.0f,"SCORE:%d", score1);
	sprintf(ar3,"%d",score2);
//strcat(r,ar2);
	drawBitmapText(ar3,3,0,0);
   glPopMatrix();
   




   glPushMatrix();
   glColor3f(0,0,1);
     

//Draw score3
    glRasterPos2f(0.1f, 0.1f);
    //print(2.0f,2.0f,"SCORE:%d", score1);
    sprintf(ar4,"%d",score3);
//strcat(r,ar2);
    drawBitmapText(ar4,-3,0,0);
   glPopMatrix();




   //Pause system
   if(turn==4)
   {
   glPushMatrix();
   glColor3f(0,0,1);
	 
	
	glRasterPos2f(0.1f, 0.1f);
	//print(2.0f,2.0f,"SCORE:%d", score1);
	//sprintf(ar3,"%d",score2);
//strcat(r,ar2);
	drawBitmapText(pau,0,0,0);
   glPopMatrix();
}
   

    //GAME OVER

    if(turn==11)
   {
   glPushMatrix();
   glColor3f(0,0,1);
     
    
    glRasterPos2f(0.1f, 0.1f);
    //print(2.0f,2.0f,"SCORE:%d", score1);
    //sprintf(ar3,"%d",score2);
//strcat(r,ar2);
    drawBitmapText(gend,0,0,0);
   glPopMatrix();
}
   
     // Draw BASE
    glPushMatrix();
    glTranslatef(0.0f, -(box_len/2), 0.0f);
    //glRotatef(theta, 0.0f, 0.0f, 1.0f);
	glScalef(1.0f, 1.0f, 1.0f);
    drawBase(box_len);
    glPopMatrix();
    
   
   
    // Draw Ball3
    //glPushMatrix();
    //glTranslatef(ball3_x, ball3_y, 0.0f);
    //glColor3f(0.0f, 1.0f, 0.0f);
    //drawBall3(ball3_rad);
    //glPopMatrix();
    

    // Draw Cylinder1
    glPushMatrix();
    glTranslatef(tri_x, tri_y, -0.5f);
    //glRotatef(theta, 0.0f, 0.0f, 1.0f);
    glRotatef( -90.0f, 1.0f, 0.0f, 0.0f);
	glColor4f( 0.0f, 1.0f, 0.0f, ALPHA);					// Reddish color
	// Parameters: height, radius, slices, stacks
	
    glScalef(0.5f, 0.5f, 0.5f);
    drawGluCylinder((box_len/4), (box_len*0.1875), 50, 50 );
    
    glPopMatrix();
    
    
    // Draw Cylinder2
    glPushMatrix();
    glTranslatef(cri_x, cri_y, -0.5f);
    //glRotatef(theta, 0.0f, 0.0f, 1.0f);
    glRotatef( -90.0f, 1.0f, 0.0f, 0.0f );
	glColor4f( 1.0f, 0.0f, 0.0f, ALPHA2 );					// Reddish color
	// Parameters: height, radius, slices, stacks
	
    glScalef(0.5f, 0.5f, 0.5f);
    drawGluCylinder((box_len/4), (box_len*0.1875), 50, 50 );
    
    glPopMatrix();
    
    // Draw Cylinder3
    glPushMatrix();
    glTranslatef(sb_x, sb_y, -1.0f);
    //glRotatef(theta, 0.0f, 0.0f, 1.0f);
    glRotatef( -90.0f, 1.0f, 0.0f, 0.0f);
    glRotatef(-theta+90, 0.0f, 1.0f, 0.0f);
	glColor4f( 0.0f, 0.0f, 1.0f, ALPHA3);					// Reddish color
	// Parameters: height, radius, slices, stacks
	
    glScalef(0.5f, 0.5f, 0.5f);
    drawGluCylinder((box_len/4), (box_len/40), 50, 50 );
    //drawGluCylinder(1.0f, 0.1f, 50, 50 );
    glPopMatrix();
    
    
     // Draw SHOOTERBASE
    glPushMatrix();
    glTranslatef(sb_x, sb_y, -1.0f);
    //glRotatef(theta, 0.0f, 0.0f, 1.0f);
    glScalef((box_len/20),(box_len/20),(box_len/20));
    drawSB();
    glPopMatrix();
    
    
    
    // Draw CONE
    //glPushMatrix();
    //glTranslatef(sb_x, sb_y, -1.0f);
    //glRotatef(peta-90, 0.0f, 0.0f, 1.0f);
    //glColor3f(1.0f, 0.0f, 0.0f);
    //glScalef(0.5f, 0.5f, 0.5f);
    //drawcone();
    //glPopMatrix();
  
    // Draw LINE
    //glPushMatrix();
    //glTranslatef(sb_x, sb_y, -1.0f);
    //glRotatef(theta, 0.0f, 0.0f, 1.0f);
    //glColor3f(0.9f, 0.91f, 0.98f);
    //glScalef((box_len/8), (box_len/8), (box_len/8));
    //drawLINE();
    //glPopMatrix();
    
    
    

     // Draw LINE2
    for(li=0;li<50;li++)
        {
            if(livl[li]==1)
                {
     
                    glPushMatrix();
                    glTranslatef(l2_x[li], l2_y[li], -1.0f);
                    //glRotatef(theta, 0.0f, 0.0f, 1.0f);
                    glColor3f(0.9f, 0.91f, 0.98f);
                    glScalef(box_len/10, box_len/10, box_len/10);
                    glLineWidth (2.0f);
                    drawLINE2(heta[li]);
                    glPopMatrix();
                }
        }
   
   
   
    // Draw Ball2
    for(j=0;j<50;j++)
        {if(ball2_y[j]<1.75)
            {if(liv2[j]==1)
                {    

                    glPushMatrix();
                    glTranslatef(ball2_x[j], ball2_y[j], 0.0f);
                    glColor3f(1.0f, 0.0f, 0.0f);
                    drawBall2(ball2_rad[j]);
                    glPopMatrix();
                }
            }
        }   
    
    
     // Draw Ball3
    for(j=0;j<50;j++)
        {if(ball3_y[j]<1.75)
            {if(liv3[j]==1)
                {    
                    glPushMatrix();
                    glTranslatef(ball3_x[j], ball3_y[j], 0.0f);
                    glColor3f(0.0f, 0.0f, 1.0f);
                    drawBall3(ball3_rad[j]);
                    glPopMatrix();
                }
            }
        }   
    
    
    
    
    
     // Draw Ball1
    for(j=0;j<50;j++)
        {if(ball1_y[j]<1.75f)
            {if(liv1[j]==1)
                {
                    glPushMatrix();
                    glTranslatef(ball1_x[j], ball1_y[j], 0.0f);
                    glColor3f(0.0f, 1.0f, 0.0f);
                    drawBall1(ball1_rad[j]);
                    glPopMatrix();
	           }
            }
        }
    glPopMatrix();
    glutSwapBuffers();
}

// Function to handle all calculations in the scene
// updated evry 10 milliseconds
void update1(int value) {
	
	if(turn!=4 && turn!=11)
	
	
	{
	
	tim = tim+10;
    ALPHA4 = ALPHA4+0.005f;

	accetimer = accetimer+10;
    if(accetimer >=100)
        {acce=acce+0.00000005f;
            accetimer=0;
        }
	frn = rand()%3;
	//cout<<frn;
	if(frn==0)
    {
	//srand(time(0));

    //float randomNumber1 = ((float[]) {1.9, 1.2, 1.1, 0.6, 0.2, 0, -0.1, -0.3, -0.7, -1, -1.4, -1.7})[rand() % 12];
    for(p=0;p<49;p++)
    {
		//float randomNumber1 = ((float[]) {1.9, 1.2, 1.1, 0.6, 0.2, 0, -0.1, -0.3, -0.7, -1, -1.4, -1.7})[rand() % 12];
float randomNumber1 = ( ( (float) rand()/(float) (RAND_MAX) ) * (box_len-(box_len/10) ) - (box_len/2 - box_len/20) );
		if(ball1_y[p] <= 0.4f )
			{ball1_x[p+1] = randomNumber1;
			ball1_y[p+1] = box_len ;
			liv1[p+1] = 1;
			ball1_velx[p+1] = 0.0f;
			ball1_vely[p+1] = -0.01f;
			//ball1_rad[p+1] = 0.2f;
            }
			
	}
	
	}

    if(frn==1)
    {

	
	for(p=0;p<49;p++)
    {//srand(time(0));
		//float randomNumber1 = ((float[]) {1.9, 1.2, 1.1, 0.6, 0.2, 0, -0.1, -0.3, -0.7, -1, -1.4, -1.7})[rand() % 12];
float randomNumber2 = ( ( (float) rand()/(float) (RAND_MAX) ) * (box_len-(box_len/10) ) - (box_len/2 - box_len/20) );
		if(ball2_y[p] <= 0.4f )
			{ball2_x[p+1] = randomNumber2;
			ball2_y[p+1] = box_len ;
			liv2[p+1] = 1;
			ball2_velx[p+1] = 0.0f;
			ball2_vely[p+1] = -0.01f;
			//ball2_rad[p+1] = 0.2f;
		}
	}
	
	}




    if(frn==2)
    {
	for(p=0;p<49;p++)
    {//srand(time(0));
		//float randomNumber1 = ((float[]) {1.9, 1.2, 1.1, 0.6, 0.2, 0, -0.1, -0.3, -0.7, -1, -1.4, -1.7})[rand() % 12];
float randomNumber3 = ( ( (float) rand()/(float) (RAND_MAX) ) * (box_len-(box_len/10) ) - (box_len/2 - box_len/10) );
		if(ball3_y[p] <= 0.4f )
			{ball3_x[p+1] = randomNumber3;
			ball3_y[p+1] = box_len ;
			liv3[p+1]=1;
			ball3_velx[p+1] = 0.0f;
			ball3_vely[p+1] = -0.01f;
			//ball3_rad[p+1] = 0.2f;
		}
	}
	
	}
	//srand(time(0));
     //float randomNumber2 = ((((float rand())/(float RAND_MAX())) * (len-(2*ball1_rad))) - (len/2 - ball1_rad));
    //float randomNumber2 = ((float[]) {-1.5, -1.8, -1, -0.8, -0.5, -0.1, 0, 0.2, 0.5, 0.9, 1.3, 1.6, 1.9})[rand() % 13];
    //if(ball3_y < -box_len/2 || (ball3_rad == 0))
		//{ball3_x = randomNumber2;
		//ball3_y = 1.0f ;
		//ball3_rad = 0.2f;
		//}
	
	
	
	
	
    
   
    // Handle ball1 collisions with box
    for(p=0;p<50;p++)
    {


        if((ball1_vely[p]<0.0f) && (ball1_y[p]>sb_y+(box_len/8)) && (ball1_y[p]<sb_y+(box_len/6)) && (liv1[p]==1) && (((ball1_x[p]-sb_x<=box_len/20) && (ball1_x[p]>=sb_x)) || ((sb_x-ball1_x[p]<=box_len/20) &&(sb_x>=ball1_x[p]))))
             {turn=11;
                cout<<turn<<endl;
            }
    //if(ball1_x[p] + ball1_rad[p] > box_len/2 || ball1_x[p] - ball1_rad[p] < -box_len/2)
        //{ball1_velx[p] *= -1;}
    if(((ball1_y[p]) < (-box_len/2)+(box_len/4)) && (ball1_vely[p]<0) && ((ball1_x[p] + ball1_rad[p]) < (tri_x + cyrad)) &&  ((ball1_x[p] - ball1_rad[p]) > (tri_x - cyrad)) && (liv1[p]==1))
       { //ball1_vely *= 0;
        //ball1_velx *= 0;
        //ball1_rad[p] *= 0;
        score1=score1+1;
        liv1[p]=0;
        //char text[32];
	}
	
	if(((ball1_y[p] - ball1_rad[p]) < (-box_len/2)) && (liv1[p]==1) && (((ball1_x[p] + ball1_rad[p]) > (tri_x + cyrad)) ||  ((ball1_x[p] - ball1_rad[p]) < (tri_x - cyrad))))
       { ball1_vely[p] *= 0;
        ball1_velx[p] *= 0;
        
        if(ball1_x[p]>cri_x)
        {cri_x_max=ball1_x[p];
			}
			
		if(ball1_x[p]<cri_x)
		{cri_x_min=ball1_x[p];
			}
			
			
			
		 if(ball1_x[p]>tri_x)
        {tri_x_max=ball1_x[p];
			}
			
		if(ball1_x[p]<tri_x)
		{tri_x_min=ball1_x[p];
			}
			
			
			
		if(ball1_x[p]>sb_x)
        {sri_x_max=ball1_x[p];
			}
			
		if(ball1_x[p]<sb_x)
		{sri_x_min=ball1_x[p];
			}	
        //ball1_rad[p] *= 0;
        //score1=score1+1;
        //char text[32];
        
	}
	
	
	
}




for(p=0;p<50;p++)
    {


        if( (ball2_vely[p]<0.0f) && (ball2_y[p]<sb_y+(box_len/6)) && (ball2_y[p]>sb_y+(box_len/8)) && (liv2[p]==1) && (((ball2_x[p]-sb_x<=box_len/20) && (ball2_x[p]>=sb_x)) || ((sb_x-ball2_x[p]<=box_len/20) &&(sb_x>=ball2_x[p]))))
            {turn=11;
                cout<<turn<<endl;
            }
   // if(ball2_x[p] + ball2_rad[p] > box_len/2 || ball2_x[p] - ball2_rad[p] < -box_len/2)
       // {ball2_velx[p] *= -1;}
    if(((ball2_y[p]) < (-box_len/2)+(box_len/4)) && (ball2_vely[p]<0) && ((ball2_x[p] + ball2_rad[p]) < (cri_x + cyrad)) &&  ((ball2_x[p] - ball2_rad[p]) > (cri_x - cyrad)) && (liv2[p]==1) )
       { 
        //ball2_rad[p] *= 0;
        score2=score2+1;
        liv2[p]=0;
        //char text[32];
	}
	
	if(((ball2_y[p] - ball2_rad[p]) < (-box_len/2)) && (liv2[p]==1) && (((ball2_x[p] + ball2_rad[p]) > (cri_x + cyrad)) ||  ((ball2_x[p] - ball2_rad[p]) < (cri_x - cyrad))))
       { ball2_vely[p] *= 0;
        ball2_velx[p] *= 0;
        
        if(ball2_x[p]>cri_x)
        {cri_x_max=ball2_x[p];
			}
			
		if(ball2_x[p]<cri_x)
		{cri_x_min=ball2_x[p];
			}
			
			
			
		 if(ball2_x[p]>tri_x)
        {tri_x_max=ball2_x[p];
			}
			
		if(ball2_x[p]<tri_x)
		{tri_x_min=ball2_x[p];
			}
			
			
		if(ball2_x[p]>sb_x)
        {sri_x_max=ball2_x[p];
			}
			
		if(ball2_x[p]<sb_x)
		{sri_x_min=ball2_x[p];
			}	
        //stopb2[w2]=ball2_x[p];
        //w2++;
        //ball1_rad[p] *= 0;
        //score1=score1+1;
        //char text[32];
        
	}
	
	
	
}



for(p=0;p<50;p++)
    {if(liv3[p]==1 && (ball3_y[p]<box_len/2))
        {for(j=0;j<50;j++)
            {if(livl[j]==1)
                {
                    float xdis1=(ball3_x[p]-l2_x[j]);
                    float ydis1=(ball3_y[p]-l2_y[j]);
                    float dis1=pow((xdis1),2);
                    float dis2=pow((ydis1),2);
                    float dis3=sqrt(dis1+dis2);
                    if(dis3<ball3_rad[p] && liv3[p]==1)
                        {
                            score3 = score3+1;
                            liv3[p]=0;
                            livl[j]=0;
                        }
                }
            }
        }
    }

for(p=0;p<50;p++)
    {if(liv2[p]==1 && (ball2_y[p]<box_len/2))
        {for(j=0;j<50;j++)
            {if(livl[j]==1)
                {
                    float xdis12=(ball2_x[p]-l2_x[j]);
                    float ydis12=(ball2_y[p]-l2_y[j]);
                    float dis12=pow((xdis12),2);
                    float dis22=pow((ydis12),2);
                    float dis32=sqrt(dis12+dis22);
                    if(dis32<ball2_rad[p] && liv2[p]==1)
                        {
                            score3 = score3-1;
                            liv2[p]=0;
                            livl[j]=0;
                        }
                }
            }
        }
    }

for(p=0;p<50;p++)
    {if(liv1[p]==1 && (ball1_y[p]<box_len/2))
        {for(j=0;j<50;j++)
            {if(livl[j]==1)
                {
                    float xdis11=(ball1_x[p]-l2_x[j]);
                    float ydis11=(ball1_y[p]-l2_y[j]);
                    float dis11=pow((xdis11),2);
                    float dis21=pow((ydis11),2);
                    float dis31=sqrt(dis11+dis21);
                    if(dis31<ball1_rad[p] && liv1[p]==1)
                        {
                            score3 = score3-1;
                            liv1[p]=0;
                            livl[j]=0;
                        }
                }
            }
        }
    }


for(p=0;p<50;p++)
    { 

        if((ball3_vely[p]<0.0f) && (ball3_y[p]>sb_y+(box_len/8)) && (ball3_y[p]<sb_y+(box_len/6))&& (liv3[p]==1) && (((ball3_x[p]-sb_x<=box_len/20) && (ball3_x[p]>=sb_x)) || ((sb_x-ball3_x[p]<=box_len/20) &&(sb_x>=ball3_x[p]))))
             {turn=11;
                cout<<turn<<endl;
            }
	
	if(((ball3_y[p] - ball3_rad[p]) < (-box_len/2)) && (liv3[p]==1)) 
       { ball3_vely[p] *= 0;
        ball3_velx[p] *= 0;
        
        if(ball3_x[p]>cri_x)
        {cri_x_max=ball3_x[p];
			}
			
		if(ball3_x[p]<cri_x)
		{cri_x_min=ball3_x[p];
			}
			
			
			
		 if(ball3_x[p]>tri_x)
        {tri_x_max=ball3_x[p];
			}
			
		if(ball3_x[p]<tri_x)
		{tri_x_min=ball3_x[p];
			}
			
			
		if(ball3_x[p]>sb_x)
        {sri_x_max=ball3_x[p];
			}
			
		if(ball3_x[p]<sb_x)
		{sri_x_min=ball3_x[p];
			}	
        //stopb2[w2]=ball2_x[p];
        //w2++;
        //ball1_rad[p] *= 0;
        //score1=score1+1;
        //char text[32];
        
	}
	
	
	
}


   
    
    // Update position 
    for(p=0;p<50;p++)
    {   
        ball1_vely[p] = (-acce+ball1_vely[p]);
        ball2_vely[p] = (-acce+ball2_vely[p]);
        ball3_vely[p] = (-acce+ball3_vely[p]);



        ball1_x[p] += ball1_velx[p];
        ball1_y[p] += ball1_vely[p];
        
        ball2_x[p] += ball2_velx[p];
        ball2_y[p] += ball2_vely[p];
        
        ball3_x[p] += ball3_velx[p];
        ball3_y[p] += ball3_vely[p];
        //ball2_x += ball2_velx;
        //ball2_y += ball2_vely;
       // ball3_x += ball3_velx;
        //ball3_y += ball3_vely;
        l2_x[p] += l2_velx[p];
        l2_y[p] += l2_vely[p];
        if(l2_x[p]>(box_len/2))
            {heta[p]=180-heta[p];
                l2_velx[p]=-l2_velx[p];
            }
        if(l2_x[p]<-(box_len/2))
            {heta[p]=180-heta[p];
                l2_velx[p]=-l2_velx[p];
            }
    }
}
    glutTimerFunc(10, update1, 0);
}


void drawBox(float len) {
   
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glBegin(GL_QUADS);
    glVertex2f(-len / 2, -len / 2);
    glVertex2f(len / 2, -len / 2);
    glVertex2f(len / 2, len / 2);
    glVertex2f(-len / 2, len / 2);
    glEnd();
    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}



void drawcone(){
    /* sides */
    glBegin(GL_TRIANGLES);
    for (k=0;k<=360;k+=DEF_D){
      glColor3f(0.0,0.0,1.0);
      glVertex3f(0,3,0);
      glColor3f(0.0,1.0,1.0);
      glVertex3f(cos(k)/2,0,-sin(k)/2);
      glColor3f(1.0,0.0,0.0);
      glVertex3f(cos(k+DEF_D)/2,0,-sin(k+DEF_D)/2);
    }
}
void drawBall1(float rad) {
    
   glBegin(GL_TRIANGLE_FAN);
   for(int i=0 ; i<360 ; i++) {
       glVertex2f((rad/2) * cos(DEG2RAD(i)), (rad/2) * sin(DEG2RAD(i)));
   }
   glEnd();

   glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(45)), (rad/2) * sin(DEG2RAD(45)));
    glVertex2f((rad/2) * cos(DEG2RAD(45))+(rad/2), (rad/2) * sin(DEG2RAD(45)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(0)), (rad/2) * sin(DEG2RAD(0)));
    glVertex2f((rad/2) * cos(DEG2RAD(0))+(rad/2), (rad/2) * sin(DEG2RAD(0)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(315)), (rad/2) * sin(DEG2RAD(315)));
    glVertex2f((rad/2) * cos(DEG2RAD(315))+(rad/2), (rad/2) * sin(DEG2RAD(315)));
    glEnd();
    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(135)), (rad/2) * sin(DEG2RAD(135)));
    glVertex2f((rad/2) * cos(DEG2RAD(135))-(rad/2), (rad/2) * sin(DEG2RAD(135)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(180)), (rad/2) * sin(DEG2RAD(180)));
    glVertex2f((rad/2) * cos(DEG2RAD(180))-(rad/2), (rad/2) * sin(DEG2RAD(180)));
    glEnd();


    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(225)), (rad/2) * sin(DEG2RAD(225)));
    glVertex2f((rad/2) * cos(DEG2RAD(225))-(rad/2), (rad/2) * sin(DEG2RAD(225)));
    glEnd();
}

void drawBall2(float rad) {
    
   glBegin(GL_TRIANGLE_FAN);
   for(int i=0 ; i<360 ; i++) {
       glVertex2f((rad/2) * cos(DEG2RAD(i)), (rad/2) * sin(DEG2RAD(i)));
   }
   glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(45)), (rad/2) * sin(DEG2RAD(45)));
    glVertex2f((rad/2) * cos(DEG2RAD(45))+(rad/2), (rad/2) * sin(DEG2RAD(45)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(0)), (rad/2) * sin(DEG2RAD(0)));
    glVertex2f((rad/2) * cos(DEG2RAD(0))+(rad/2), (rad/2) * sin(DEG2RAD(0)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(315)), (rad/2) * sin(DEG2RAD(315)));
    glVertex2f((rad/2) * cos(DEG2RAD(315))+(rad/2), (rad/2) * sin(DEG2RAD(315)));
    glEnd();
    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(135)), (rad/2) * sin(DEG2RAD(135)));
    glVertex2f((rad/2) * cos(DEG2RAD(135))-(rad/2), (rad/2) * sin(DEG2RAD(135)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(180)), (rad/2) * sin(DEG2RAD(180)));
    glVertex2f((rad/2) * cos(DEG2RAD(180))-(rad/2), (rad/2) * sin(DEG2RAD(180)));
    glEnd();


    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(225)), (rad/2) * sin(DEG2RAD(225)));
    glVertex2f((rad/2) * cos(DEG2RAD(225))-(rad/2), (rad/2) * sin(DEG2RAD(225)));
    glEnd();

}


void drawBall3(float rad) {
    
   glBegin(GL_TRIANGLE_FAN);
   for(int i=0 ; i<360 ; i++) {
       glVertex2f((rad/2) * cos(DEG2RAD(i)), (rad/2) * sin(DEG2RAD(i)));
   }
   glEnd();

   glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(45)), (rad/2) * sin(DEG2RAD(45)));
    glVertex2f((rad/2) * cos(DEG2RAD(45))+(rad/2), (rad/2) * sin(DEG2RAD(45)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(0)), (rad/2) * sin(DEG2RAD(0)));
    glVertex2f((rad/2) * cos(DEG2RAD(0))+(rad/2), (rad/2) * sin(DEG2RAD(0)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(315)), (rad/2) * sin(DEG2RAD(315)));
    glVertex2f((rad/2) * cos(DEG2RAD(315))+(rad/2), (rad/2) * sin(DEG2RAD(315)));
    glEnd();
    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(135)), (rad/2) * sin(DEG2RAD(135)));
    glVertex2f((rad/2) * cos(DEG2RAD(135))-(rad/2), (rad/2) * sin(DEG2RAD(135)));
    glEnd();

    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(180)), (rad/2) * sin(DEG2RAD(180)));
    glVertex2f((rad/2) * cos(DEG2RAD(180))-(rad/2), (rad/2) * sin(DEG2RAD(180)));
    glEnd();


    glBegin(GL_LINES);
    
    glVertex2f((rad/2) * cos(DEG2RAD(225)), (rad/2) * sin(DEG2RAD(225)));
    glVertex2f((rad/2) * cos(DEG2RAD(225))-(rad/2), (rad/2) * sin(DEG2RAD(225)));
    glEnd();
}
GLUquadricObj* myReusableQuadric = 0;
void drawGluCylinder( float height, float radius, float slices, float stacks ) {
	if ( ! myReusableQuadric ) {
		myReusableQuadric = gluNewQuadric();  
		// Should (but don't) check if pointer is still null --- to catch memory allocation errors.
		gluQuadricNormals( myReusableQuadric, GL_TRUE );
	}
	
	gluCylinder( myReusableQuadric, radius, radius, height, slices, stacks );
	
	
	
}



void reshape(int w,int h) 
{ 
	
    glViewport(0,0,w,h); 
    glMatrixMode(GL_PROJECTION); 
    glLoadIdentity(); 
    gluOrtho2D(0,w,h,0); 
    glMatrixMode(GL_MODELVIEW); 
    glLoadIdentity(); 
	
}

void drawBase(float box_len) {
	//glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

    glBegin(GL_QUADS);
    //gluCylinder(quadratic,0.1f,0.1f,3.0f,32,32);
    glColor3f(0.9f, 0.91f, 0.98f);
    glVertex2f(box_len/2, 0.0f);
    glColor3f(0.9f, 0.91f, 0.98f);
    glVertex2f(box_len/2, (box_len/10));
    glColor3f(0.9f, 0.91f, 0.98f);
    glVertex2f(-box_len/2, (box_len/10));
    glColor3f(0.9f, 0.91f, 0.98f);
    glVertex2f(-box_len/2, 0.0f);
    glEnd();
    //glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
}

void drawSB()
{
	 glBegin(GL_QUADS);                // Begin drawing the color cube with 6 quads
      // Top face (y = 1.0f)
      // Define vertices in counter-clockwise (CCW) order with normal pointing out
      glColor4f(0.623529f, 0.623529f, 0.372549f,ALPHA4);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
      // Bottom face (y = -1.0f)
      glColor4f(0.623529f, 0.623529f, 0.372549f,ALPHA4);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      // Front face  (z = 1.0f)
      glColor4f(0.623529f, 0.623529f, 0.372549f,ALPHA4);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      // Back face (z = -1.0f)
      glColor4f(0.623529f, 0.623529f, 0.372549f,ALPHA4);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      // Left face (x = -1.0f)
      glColor4f(0.623529f, 0.623529f, 0.372549f,ALPHA4);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
 
      // Right face (x = 1.0f)
      glColor4f(0.623529f, 0.623529f, 0.372549f,ALPHA4);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
   glEnd(); 
}





void drawLINE() {

    glBegin(GL_LINES);
    
    glVertex3f(0.0f, 0.0f, 0.0f);
    
    glVertex3f((2*cos(DEG2RAD(theta))),(2*sin(DEG2RAD(theta))), 0.0f);
    
    //glVertex3f(1.0f, -2.0f, 0.0f);
    
    glEnd();
}


void drawLINE2(float uih) {

    glBegin(GL_LINES);
    
    glVertex3f(0.0f, 0.0f, 0.0f);
    
    glVertex3f(cos(DEG2RAD(uih)),sin(DEG2RAD(uih)), 0.0f);
    
    glEnd();
}
// Initializing some openGL 3D rendering options
void initRendering() {

    glEnable(GL_DEPTH_TEST);        // Enable objects to be drawn ahead/behind one another
    glEnable(GL_COLOR_MATERIAL);    // Enable coloring
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);   // Setting a background color
    //glClearColor(0.7f, 0.9f, 1.0f, 1);
    glEnable(GL_BLEND); //Enable alpha blending
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA); //Set the blend function
}

// Function called when the window is resized
void handleResize(int w, int h) {

    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, (float)w / (float)h, 0.1f, 200.0f);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void handleKeypress1(unsigned char key, int x, int y) 
	{
 switch (key)
  {
  case 27:             
			exit (0);
			break;
  case 'g':
			turn = 1;
			ALPHA = 1.0f;
			ALPHA2 = 0.5f;
            ALPHA3 = 0.5f;

			break;
  case 'r':
			turn = 2;
			ALPHA2 = 1.0f;
			ALPHA = 0.5f;
            ALPHA3 = 0.5f;
            
			break;
  case 'b':
			turn = 3;
            ALPHA3 = 1.0f;
            ALPHA = 0.5f;
            ALPHA2 = 0.5f;
           
			break;
			
  case 'p':
			if(turn == 4)
				{turn=5;
					break;}
			else
				{turn = 4;
					break;}
			
			
  case 32 :
			if(turn==3 && tim>=100)
				{l2_x[ui] = sb_x;
				 l2_y[ui] = sb_y;
                 heta[ui] = theta;
				 l2_velx[ui] = cos(DEG2RAD(heta[ui]))/15;
				 l2_vely[ui] = sin(DEG2RAD(heta[ui]))/15;
				 tim =0;
				 livl[ui]=1;
                 ui++;
                 ALPHA4 = 0.5f;
				 break;
                }
 
			
  
  
  }
  
  
 
	
	
  
}
   

void handleKeypress2(int key, int x, int y) {
	
	if(turn == 1)
		{  
							
					
					
					

			if (key == GLUT_KEY_LEFT && (tri_x-cyrad/2)>-(box_len/2) && (tri_x<tri_x_max) && (tri_x>tri_x_min))
				{    
					tri_x -= 0.1;
					
						
			    }
			if (key == GLUT_KEY_RIGHT && (tri_x+cyrad/2)<(box_len/2) && (tri_x<tri_x_max) && (tri_x>tri_x_min))
			{ 
			
				tri_x += 0.1;
			}	
		}
	else if(turn == 2)
		{
			
			
			
			
			

			if (key == GLUT_KEY_LEFT && (cri_x-cyrad/2)>-(box_len/2) && (cri_x<cri_x_max) && (cri_x>cri_x_min))
				cri_x -= 0.1;
			if (key == GLUT_KEY_RIGHT && (cri_x+cyrad/2)<(box_len/2) && (cri_x<cri_x_max) && (cri_x>cri_x_min))
				cri_x += 0.1;
				
		}
		
		
	else if(turn == 3)
		{
			if (key == GLUT_KEY_UP)
				theta += 5;
			if (key == GLUT_KEY_DOWN)
				theta -= 5;
		
			if (key == GLUT_KEY_RIGHT && (sb_x<sri_x_max) && (sb_x>sri_x_min) && (sb_x+cyrad/2)<(box_len/2))
				sb_x += 0.1;
			if (key == GLUT_KEY_LEFT && (sb_x<sri_x_max) && (sb_x>sri_x_min) && (sb_x-cyrad/2)>-(box_len/2))
				sb_x -= 0.1;
	}
}

/*void handleMouseclick(int button, int state, int x, int y) {

    if (state == GLUT_DOWN)
    {
        if (button == GLUT_LEFT_BUTTON)
            theta += 15;
        else if (button == GLUT_RIGHT_BUTTON)
            theta -= 15;
    }
}*/

void handleMouseclick(int button, int state, int x, int y) {

    if (state == GLUT_DOWN)
    {   
        if (button == GLUT_LEFT_BUTTON)
            {
                
                float b;
                b =  (float)(x);
                float q;
                q = (float)(y);
                
                b1 = (float)(((4*b)/385)-3.5);
                
                q1 = (float)(-(((4*q)/385)-2.0));
                
                
                
           // cout << b1 << endl;
            cout << q1 << endl;

            if(((b1>tri_x && b1-tri_x<0.1f) || (b1<tri_x && tri_x-b1<0.1f)) && ((q1>tri_y && q1-tri_y<1.0f) ))
                {turn=1;
                    ALPHA = 1.0f;
                    ALPHA2 = 0.5f;
                    ALPHA3 = 0.5f;
                }

            else if(((b1>cri_x && b1-cri_x<0.1f) || (b1<cri_x && cri_x-b1<0.1f)) && ((q1>cri_y && q1-cri_y<1.0f) ))
                {turn=2;
                    ALPHA2 = 1.0f;
                    ALPHA = 0.5f;
                    ALPHA3 = 0.5f;
                }

            else if(((b1>sb_x && b1-sb_x<0.1f) || (b1<sb_x && sb_x-b1<0.1f)) && ((q1>sb_y && q1-sb_y<1.0f) ))
                {turn=3;
                    ALPHA3 = 1.0f;
                    ALPHA = 0.5f;
                    ALPHA2 = 0.5f;
                    
                }


        }
        else if (button == GLUT_RIGHT_BUTTON)
            {  turn=50;

                //cout << x;
            //cout << y;
            }
    }
}

void processMouseActiveMotion(int x, int y)
    {   
            {
                float yu;
            
            yu=(float)(x);
            yu1 = (float)(((4*yu)/385)-3.5);
            float tu;
            
            tu=(float)(y);
            tu1 = (float)(-(((4*tu)/385)-2.0));
            //cout << yu1 << endl;
            //cout << tu1 << endl;
            if(turn==1)
            {
                if((yu1<tri_x_max) && (yu1>tri_x_min))
                {
                tri_x=yu1;}
            }
            else if(turn==2)
            { 
               if((yu1<cri_x_max) && (yu1>cri_x_min))
                {
                cri_x=yu1;
                }
            }   
            else if(turn==3)
            {
                if((yu1<sri_x_max) && (yu1>sri_x_min))
                {
                sb_x=yu1;
                }
            }

            else if(turn==50)
                {
                    float th = (tu1-sb_y);
                    float thi = (yu1-sb_x);
                    theta = (atan2(th,thi) * (180 / PI));
                }

    }
}