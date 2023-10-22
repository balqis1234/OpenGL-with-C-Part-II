#include <Windows.h>
#include <stdlib.h>
#include <math.h>
#include <gl\gl.h>
#include <gl\glu.h>
#include <gl\glut.h>
#include <math.h>
#include <iostream>

using namespace std;

#define SCREEN_HEIGHT 1400
#define SCREEN_WIDTH 1400
#define PI 3.1415926535897932384626433832795
#define FPS 2

int X = 0;
int Y = 0;
int Z = 0;
int dx = 0;
int dy = 0;
int dz = 0;

//Lily
float Lily_X = 0;
float Lily_Y = 0;
float LilyStatus = 1;

//mrs creepy
float ghost_X = 0;
float ghost_Y = 0;
int ghostStatus = 1;

//gate
float gate_X = 0;
float gate_Y = 0;
float gate_Z = 0;
float gateStatus = 1;

//Lily head
float Lily_head_X = 0;
float Lily_head_Y = 0;
float LilyHeadStatus = 1;

//Lily organ
float Lily_organ_X = 0;
float Lily_organ_Y = 0;
float LilyOrganStatus = 1;

void MyTimerFunc(int value);

/*=======================
********SHAPES***********
========================*/

//Circle
void circle(int x, int y, int r, int n) {
	double inc = (2 * PI) / n;

	glBegin(GL_POLYGON);

	for (double theta = 0.0; theta <= 2 * PI; theta += inc) {
		glVertex2d(r * cos(theta) + x, r * sin(theta) + y);
	}
	glEnd();
}

//Semicircle
void semicircle(int centerx, int centery, int r, int n) {
	glBegin(GL_POLYGON);
	for (int i = 0; i <= n; i++) {
		double theta = PI * double(i) / double(n);
		double x = r * cos(theta);
		double y = r * sin(theta);
		glVertex2d(centerx + x, centery + y);
	}
	glEnd();
}

//Equilateral Triangle
void triangle(int x, int y, int z) {

	glBegin(GL_TRIANGLES);
	glVertex2i(x, y);
	glVertex2i(x + (z / 2), z * sin(-60) + y);
	glVertex2i(x + z, y);
	glEnd();
}

//Isoscels Triangle
void triangle2(int x, int y, int z) {

	glBegin(GL_POLYGON);
	glVertex2i(x + (z / 2), y + 80);
	glVertex2i(x, y);
	glVertex2i(x + z, y);
	glEnd();
}

//Inverted Isoscels Triangle
void triangle3(int x, int y, int z) {

	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + (z / 2), y - 30);
	glVertex2i(x + z, y);
	glEnd();
}

void triangle4(float x1, float y1, float x2, float y2, float x3, float y3) {
	glBegin(GL_TRIANGLES);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glEnd();

}

void quads(float x1, float y1, float x2, float y2, float x3, float y3, float x4, float y4)
{
	glBegin(GL_QUADS);
	glVertex2f(x1, y1);
	glVertex2f(x2, y2);
	glVertex2f(x3, y3);
	glVertex2f(x4, y4);
	glEnd();
}

void quads2(float x1, float y1,float z1, float x2, float y2, float z2, float x3, float y3, float z3, float x4, float y4, float z4)
{
	glBegin(GL_QUADS);
	glVertex3f(x1, y1, z1);
	glVertex3f(x2, y2, z2);
	glVertex3f(x3, y3, z3);
	glVertex3f(x4, y4, z4);
	glEnd();
}

void rectangle(float x, float y, float w, float h)
{
	glBegin(GL_POLYGON);
	glVertex2i(x, y);
	glVertex2i(x + w, y);
	glVertex2i(x + w, y + h);
	glVertex2i(x, y + h);
	glEnd();
}

void rectangle2(float x, float y, float w, float h, float z)
{
	glBegin(GL_POLYGON);
	glVertex3i(x, y, z);
	glVertex3i(x + w, y, z);
	glVertex3i(x + w, y + h, z );
	glVertex3i(x, y + h, z);
	glEnd();
}


/*=============================
********SCENE 1 OBJECTS*******
==============================*/

void Lily_backside()
{
	glPushMatrix();

	//--leg--
	//left leg
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(168, -1120, 56, -280);
	//bottom
	quads(140, -1400, 168, -1372, 224, -1372, 140, -1400);
	//left
	quads(140, -1148, 168, -1120, 168, -1372, 140, -1400);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(196, -1148, 224, -1120, 224, -1372, 196, -1400);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(140, -1148, 56, -280);

	//right leg
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(392, -1092, 56, -280);
	//bottom
	quads(364, -1400, 392, -1372, 448, -1372, 420, -1400);
	//left
	quads(364, -1120, 392, -1092, 392, -1372, 364, -1400);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(420, -1120, 448, -1092, 448, -1372, 420, -1400);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(364, -1120, 56, -280);

	//--body--
	//body 1
	glColor3f(0.21, 0.47, 0.89);
	triangle4(280, -980, 280, -588, 560, -1064);
	//body 2
	triangle4(0, -1120, 280, -588, 280, -980);
	//body base
	quads(0, -1120, 280, -980, 560, -1064, 280, -1176);
	//body 3
	glColor3f(0.18, 0.43, 0.83);
	triangle4(0, -1120, 280, -588, 280, -1176);
	//body 4
	glColor3f(0.21, 0.47, 0.89);
	triangle4(280, -1176, 280, -588, 560, -1064);

	//--head/hair--
	//--ponytail--
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(84, -364, 84, -224);
	//bottom
	quads(56, -616, 84, -588, 168, -588, 140, -616);
	//left
	glColor3f(0.12, 0.12, 0.13);
	quads(56, -392, 84, -364, 84, -588, 56, -616);
	//right
	quads(140, -392, 168, -364, 168, -588, 140, -616);
	//top
	glColor3f(0.15, 0.15, 0.16);
	quads(56, -392, 84, -364, 112, -364, 140, -392);
	//front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(56, -392, 84, -224);

	//--head--
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(196, -364, 280, -280);
	//bottom
	quads(140, -700, 196, -644, 476, -644, 420, -700);
	//left
	glColor3f(0.12, 0.12, 0.13);
	quads(140, -420, 196, -364, 196, -644, 140, -700);
	//right
	quads(420, -420, 476, -420, 476, -644, 420, -700);
	//top
	glColor3f(0.15, 0.15, 0.16);
	quads(140, -420, 196, -364, 476, -364, 420, -420);
	//front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(140, -420, 280, -280);

	//--arm--
	//left arm
	glColor3f(0.87, 0.84, 0.79);
	//back
	quads(56, -616, 196, -756, 168, -812, 0, -644);
	//bottom
	quads(0, -728, 56, -700, 168, -812, 112, -784);
	//left
	quads(0, -644, 56, -616, 56, -700, 0, -728);
	//top
	glColor3f(0.94, 0.93, 0.90);
	quads(0, -644, 56, -616, 196, -756, 168, -812);
	//front
	glColor3f(0.87, 0.84, 0.79);
	quads(0, -644, 168, -812, 112, -896, 0, -728);

	//right arm
	glColor3f(0.87, 0.84, 0.79);
	//back
	quads(392, -756, 588, -644, 616, -700, 420, -840);
	//bottom
	quads(420, -840, 616, -700, 588, -756, 392, -896);
	//left
	quads(364, -840, 392, -756, 420, -840, 392, -896);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(560, -700, 588, -644, 616, -700, 588, -756);
	//top
	quads(364, -840, 392, -756, 588, -644, 560, -700);
	//front
	glColor3f(0.87, 0.84, 0.79);
	quads(560, -700, 560, -700, 588, -756, 392, -896);

	glPopMatrix();
}

/*=======================
********SCENE 1 *******
========================*/

void bedroom() //scene 1
{
	//floor
	glColor3f(0.5, 0.0, 0.0); //dark red
	quads(-840, 0, 1400, 0, 1400, -1400, -1400, -1400);

	//---------wall------------------
	//left-wall
	glColor3f(0.77, 0.64, 0.52); //light brown
	quads(-1400, 1400, -840, 1400, -840, 0, -1400, -1400);
	//right-wall
	glColor3f(0.79, 0.68, 0.56); //darker tint of light brown
	quads(-840, 1400, 1400, 1400, 1400, 0, -840, 0);

	
	//--------book shelf----------
	glColor3f(0.39, 0.34, 0.28); //dark brown
	//back
	rectangle(-700, 1260, 700, -1400);
	//left
	quads(-840, 1120, -700, 1260, -700, -140, -840, -280);
	//bottom
	quads(-700, -140, 0, -140, -140, -280, -840, -280);
	//top
	glColor3f(0.44, 0.39, 0.32);
	quads(-700, 1260, 0, 1260, -140, 1120, -840, 1120);
	glColor3f(0.39, 0.34, 0.28); //dark brown
	//right
	quads(-140, 1120, 0, 1260, 0, -140, -140, -280);

	//inner book shelf 1
	glColor3f(0.25, 0.21, 0.16); //darker brown
	//back
	rectangle(-700, 1064, 504, -224);
	//base
	glColor3f(0.31, 0.27, 0.22); //darker brown 0.31, 0.27, 0.22
	quads(-700, 840, -196, 840, -196, 700, -784, 700);
	
	//inner book shelf 2
	glColor3f(0.25, 0.21, 0.16); //darker brown
	//back
	rectangle(-700, 644, 504, -364);
	//base
	glColor3f(0.31, 0.27, 0.22); //darker brown 0.31, 0.27, 0.22
	quads(-700, 280, -196, 280, -196, 140, -784, 140);

	//inner book shelf 3
	glColor3f(0.25, 0.21, 0.16); //darker brown
	rectangle(-700, 84, 504, -224);
	//base
	glColor3f(0.31, 0.27, 0.22); //darker brown 0.31, 0.27, 0.22
	quads(-700, -140, -196, -140, -196, -224, -784, -224);

	//front book shelf 
	//front-top
	glColor3f(0.51, 0.45, 0.37);
	rectangle(-840, 1120, 700, -56);
	//front-right
	rectangle(-196, 1120, 56, -1400);
	//front-left
	rectangle(-840, 1120, 56, -1400);
	//front-bottom
	rectangle(-840, -224, 700, -56);
 
	//------------picture frame---------------- 
	//outer picture frame
	glColor3f(0.39, 0.34, 0.28); //dark brown
	//left
	quads(924, 1120, 952, 1148, 952, 672, 924, 644);
	//top
	quads(924, 1120, 952, 1148, 1372, 1148, 1344, 1120);
	//bottom
	quads(924, 644, 952, 672, 1372, 672, 1344, 644);
	//right
	glColor3f(0.46, 0.40, 0.27);
	quads(1344, 1120, 1372, 1148, 1372, 672, 1344, 644);
	//front
	glColor3f(0.50, 0.77, 0.86);
	rectangle(924, 1120, 420, -476);

	//mountain picture 2
	glColor3f(0.41, 0.10, 0.10); //red-brown
	quads(1176, 840, 1344, 1120, 1344, 644, 1260, 644);

	//mountain picture 1
	glColor3f(0.28, 0.07, 0.07); //red-brown
	glBegin(GL_TRIANGLES);
	glVertex2f(924, 644);
	glVertex2f(1120, 980);
	glVertex2f(1260, 644);
	glEnd();

	//----------------window----------------
	//outside view 
	//left
	glColor3f(0.08, 0.09, 0.28);
	rectangle(84, 812, 336, -476);
	//right
	rectangle(448, 812, 364, -476);

	//----------------------ghost lurking---------------------------
	//--hair 1--
	// right
	glColor3f(0.0, 0.0, 0.0);
	quads(616, 728, 644, 756, 644, 672, 616, 644);
	// top
	quads(224, 728, 252, 756, 644, 756, 616, 728);
	//front
	glColor3f(0.12, 0.12, 0.13);
	rectangle(224, 728, 392, -84);
	//--hair 2--
	//right
	glColor3f(0.0, 0.0, 0.0);
	quads(616, 644, 644, 672, 644, 392,616, 364);
	//front
	glColor3f(0.12, 0.12, 0.13);
	rectangle(504, 644, 112, -280);
	//--hair 3--
	//right
	glColor3f(0.0, 0.0, 0.0);
	quads(336, 672, 364, 672, 364, 392, 336, 336);
	//front
	glColor3f(0.12, 0.12, 0.13);
	rectangle(224, 644, 112, -280);

	//--cloth--
	glColor3f(1.0, 0.0, 0.0);
	quads(336, 504, 420, 448, 420, 364, 336, 392);
	quads(448, 448, 504, 476, 504, 392, 448, 364);

	//--face--
	glColor3f(0.24, 0.45, 0.30);
	rectangle(280, 644, 280, -140);
	triangle4(280, 504, 560, 504,434, 434);
	
	//--eyes--
	// outer left eye
	glColor3f(0.0, 0.0, 0.0);
	circle(350, 574, 28, 360);
	//outer right eye
	glColor3f(0.0, 0.0, 0.0);
	circle(490, 574, 28, 360);
	//inner left eye
	glColor3f(1.0, 0.0, 0.0);
	circle(350, 574, 14, 360);
	//inner right eye
	glColor3f(1.0, 0.0, 0.0);
	circle(490, 574, 14, 360);

	//--mouth--
	triangle4(364, 532, 504, 532, 434, 464);

	//--leg--
	glColor3f(0.16, 0.35, 0.21);
	//left leg 1
	quads(140, 560, 196, 504, 140, 476, 112, 476);
	//left leg 2
	quads(84, 532, 140, 560, 112, 476, 84, 448);
	//right leg 1
	quads(644, 504, 728, 588, 756, 504, 700, 448);
	//right leg 2
	quads(728, 588, 812, 560, 812, 476, 756, 504);

	//--arm--
	glColor3f(0.24, 0.45, 0.30);
	//left arm 1
	rectangle(168, 504, 56, -84);
	//left arm 2
	quads(84, 420, 168, 504, 168, 420, 84, 336);
	//right arm 1
	rectangle(644, 504, 28, -84);
	//right arm 2
	quads(672, 504, 812, 420, 840, 364, 672, 420);
	
	//---------------window frame-----------------
	//back
	glColor3f(0.46, 0.40, 0.27);
	//left
	quads(56, 840, 112, 896, 112, 336, 56, 280);
	//top
	glColor3f(0.39, 0.34, 0.28); //dark brown
	quads(112, 896, 896, 896, 840, 840, 56, 840);
	//bottom
	quads(56, 280, 112, 336, 896, 336, 840, 280);
	//right
	glColor3f(0.46, 0.40, 0.27);
	quads(840, 840, 896, 896, 896, 336, 840, 280);
	
	//front-top
	glColor3f(0.54, 0.47, 0.33);
	rectangle(56, 840, 784, -28);
	//front-right
	rectangle(812, 840, 28, -560);
	//front-left
	rectangle(56, 840, 28, -560);
	//front-bottom
	rectangle(56, 308, 784, -28);
	//middle 
	rectangle(420, 840, 28, -560);

	//----------------bed----------------
	
	//mattress 
	glColor3f(0.96, 0.75, 0.89); //light pink
	//back
	rectangle(784, -168, 700, -952);
	//left
	glColor3f(0.96, 0.70, 0.87);
	quads(700, -280, 784, -168, 784, -1120, 700, -1400);
	//front
	glColor3f(0.96, 0.75, 0.89); //light pink
	rectangle(700, -280, 700, -1120);

	//blanket
	//left
	glColor3f(0.94, 0.36, 0.52);
	quads(672, -560, 700, -532, 700, -1400, 672, -1400);
	//top
	glColor3f(0.92, 0.39, 0.53); //light pink
	quads(672, -560, 700, -532, 1400, -532, 1400, -560);
	//front
	rectangle(672, -560, 728, -840);
	
	//bedframe
	glColor3f(0.26, 0.19, 0.05); //brown
	//back
	rectangle(784, 252, 700, -420);
	//left 
	quads(700, 140, 784, 252, 784, -168, 700, -280);
	//top
	glColor3f(0.44, 0.39, 0.32);
	quads(700, 140, 784, 252, 1484, 252, 1400, 140);
	//bottom
	quads(700, -280, 784, -168, 1484, -168, 1400, -280);
	//right - out of frame
	quads(1400, 140, 1484, 252, 1484, -168, 1400, -280);
	//front
	glColor3f(0.37, 0.33, 0.27);
	rectangle(700, 140, 700, -420);
	//inner bedframe
	glColor3f(0.86, 0.63, 0.36); //brown
	rectangle(840, 140, 420, -420);

	//pillow
	glColor3f(0.92, 0.39, 0.53); //light pink
	//back
	rectangle(896, -280, 420, -140);
	//left
	glColor3f(0.94, 0.3, 0.49);
	quads(840, -336, 896, -280, 896, -420, 840, -476);
	//top
	glColor3f(0.96, 0.42, 0.56);
	quads(840, -336, 896, -280, 1316, -280, 1260, -336);
	//bottom
	glColor3f(0.92, 0.39, 0.53);
	quads(840, -476, 896, -420,1316, -420, 1260, -476);
	//right
	glColor3f(0.94, 0.3, 0.49);
	quads(1260, -336, 1316, -280, 1316, -420, 1260, -476);
	//front
	glColor3f(0.92, 0.39, 0.53);
	rectangle(840, -336, 420, -140);
	
	//-------------------door---------------------
	//door
	glColor3f(0.26, 0.19, 0.05); //brown
	//back
	quads(-1316, 616, -1036, 868, -1036, -504, -1316, -1204);
	//left
	glColor3f(0.32, 0.24, 0.06);
	quads(-1316, 616, -1260, 560, -1260, -1064, -1316, -1204);
	//right
	quads(-1036, 868, -980, 840, -980, -364, -1036, -504);
	//top
	glColor3f(0.32, 0.24, 0.06);
	quads(-1316, 616, -1260, 560, -980, 840, -1036, 868);
	//front
	glColor3f(0.26, 0.19, 0.05); //brown
	quads(-1260, 560, -980, 840, -980, -364, -1260, -1064);

	//door handle
	glColor3f(0.77, 0.64, 0.52); //light brown
	//left
	quads(-1120, 112, -1092, 84, -1092, 28, -1120, 56);
	//right
	quads(-1064, 168, -1036, 140, -1036, 84, -1064, 84);
	//top
	glColor3f(0.89, 0.75, 0.62); //light brown
	quads(-1120, 112, -1064, 168, -1036, 140, -1092, 84);
	//front
	glColor3f(0.77, 0.64, 0.52); 
	quads(-1092, 84, -1036, 140, -1036, 84, -1092, 28);
	
	//---------------Lily-----------------
	Lily_backside();
}

/*=============================
********SCENE 2 OBJECTS*******
==============================*/

void mrs_creepy()
{
	//-------------------Mrs Creepy---------------------
	glPushMatrix();
	//--arm--
	// **right arm**
	//back
	glColor3f(0.24, 0.45, 0.30);
	rectangle(-112, -728, 196, -56);
	//bottom
	quads(-140, -812, -112, -784, 84, -784, 56, -812);
	//left
	quads(-140, -756, -112, -728, -112, -784, -140, -812);
	//right
	quads(56, -784, 84, -728, 84, -784, 56, -812);
	//top
	quads(-140, -756, -112, -728, 84, -728, 56, -756);
	//front
	rectangle(-140, -756, 196, -56);

	//--cloth--
	glColor3f(1.0, 0.0, 0.0);
	//back
	rectangle(56, -588, 308, -756);
	//bottom
	glColor3f(0.86, 0.03, 0.03);
	quads(0, -1400, 56, -1344, 364, -1344, 308, -1400);
	//left
	quads(0, -644, 56, -588, 56, -1344, 0, -1400);
	//right
	quads(308, -644, 364, -588, 364, -1344, 308, -1400);
	//top
	quads(0, -644, 56, -588, 364, -588, 308, -644);
	//front
	glColor3f(1.0, 0.0, 0.0);
	rectangle(0, -644, 308, -756);

	//**hair 2**
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(56, -364, 56, -420);
	//bottom
	quads(0, -840, 56, -784, 112, -784, 56, -840);
	//left
	quads(0, -420, 56, -364, 56, -784, 0, -840);
	//right
	glColor3f(0.12, 0.12, 0.13);
	quads(56, -420, 112, -364, 112, -784, 56, -840);
	//top
	glColor3f(0.16, 0.16, 0.17);
	quads(0, -420, 56, -364, 112, -364, 56, -420);
	//front
	glColor3f(0.17, 0.17, 0.19);
	rectangle(0, -420, 56, -420);

	//--face--
	//back
	glColor3f(0.24, 0.45, 0.30);
	rectangle(112, -448, 168, -140);
	//bottom
	quads(56, -644, 112, -588, 280, -588, 224, -644);
	//left
	quads(56, -504, 112, -448, 112, -588, 56, -644);
	//right
	quads(224, -504, 280, -448, 280, -588, 224, -644);
	//front
	rectangle(56, -504, 168, -140);

	//--chin--
	//back
	triangle4(112, -588, 224, -588, 140, -700);
	//left
	triangle4(56, -644, 112, -588, 140, -700);
	//right
	triangle4(140, -700, 224, -588, 280, -588);
	//front

	//--hair--
	//**hair 1**
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(280, -420, 56, -364);
	//bottom
	quads(224, -840, 280, -784, 336, -784, 280, -840);
	//left
	quads(224, -420, 280, -364, 280, -784, 224, -840);
	//right
	glColor3f(0.12, 0.12, 0.13);
	quads(280, -420, 336, -364, 336, -784, 280, -840);
	//top
	glColor3f(0.16, 0.16, 0.17);
	quads(224, -420, 280, -364, 336, -364, 280, -420);
	//front
	glColor3f(0.17, 0.17, 0.19);
	rectangle(224, -420, 56, -420);

	//**hair 3**
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(56, -364, 280, -84);
	//bottom
	quads(0, -504, 56, -448, 336, -448, 280, -504);
	//right
	glColor3f(0.12, 0.12, 0.13);
	quads(280, -420, 336, -364, 336, -448, 280, -504);
	//left
	quads(0, -420, 56, -364, 56, -448, 0, -504);
	//top
	glColor3f(0.16, 0.16, 0.17);
	quads(0, -420, 56, -364, 336, -364, 280, -420);
	//front
	glColor3f(0.17, 0.17, 0.19);
	rectangle(0, -420, 280, -84);

	// **left arm**
	//back
	glColor3f(0.24, 0.45, 0.30);
	rectangle(168, -728, 196, -56);
	//bottom
	quads(140, -812, 168, -784, 364, -784, 336, -812);
	//left
	quads(140, -756, 168, -728, 168, -784, 140, -812);
	//right
	quads(336, -756, 364, -728, 364, -784, 336, -812);
	//top
	quads(140, -728, 168, -728, 364, -728, 336, -756);
	//front
	rectangle(140, -756, 196, -56);

	//--eyes--
	// outer left eye
	glColor3f(0.0, 0.0, 0.0);
	circle(98, -560, 28, 360);
	//outer right eye
	glColor3f(0.0, 0.0, 0.0);
	circle(182, -560, 28, 360);
	//inner left eye
	glColor3f(1.0, 0.0, 0.0);
	circle(98, -560, 14, 360);
	//inner right eye
	glColor3f(1.0, 0.0, 0.0);
	circle(182, -560, 14, 360);

	//--mouth--
	triangle4(84, -616, 196, -616, 140, -672);

	glPopMatrix();
}

void Lily_side_view()
{
	glPushMatrix();
	
	//--leg--
	//right leg
	glColor3f(0.87, 0.84, 0.79);
	//back
	quads(-784, -812, -728, -812, -840, -980, -896, -980);
	//bottom
	quads(-952, -1008, -896, -980, -840, -980, -896, -1008);
	//left
	quads(-952, -1008, -812, -812, -784, -812, -896, -980);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(-896, -1008, -756, -812, -728, -812, -840, -980);
	//front
	glColor3f(0.87, 0.84, 0.79);
	quads(-952, -1008, -812, -812, -756, -812, -896, -1008);

	//left leg 2
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-672, -784, 56, -168);
	//bottom
	quads(-700, -980, -672, -952, -616, -952, -644, -980);
	//left
	quads(-700, -840, -672, -784, -672, -952, -700, -980);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(-644, -840, -616, -784, -616, -952, -644, -980);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-700, -840, 56, -140);

	//left leg 1 - bending her leg to run
	//back
	rectangle(-672, -896, 168, -56);
	//bottom
	quads(-700, -980, -672, -952, -504, -952, -532, -980);
	//left
	quads(-700, -924, -672, -896, -672, -952, -700, -980);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(-532, -924, -504, -896, -504, -952, -532, -980);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-700, -924, 168, -56);

	//--cloth--
	//body 1
	glColor3f(0.21, 0.47, 0.89);
	triangle4(-784, -756, -728, -448, -588, -756);
	//body 2
	triangle4(-868, -840, -728, -448, -784, -756);
	//body base
	quads(-868, -840, -784, -756, -588, -756, -644, -840);
	//body 3
	glColor3f(0.18, 0.43, 0.83);
	triangle4(-728, -448, -644, -840, -588, -756);
	//body 4
	glColor3f(0.21, 0.47, 0.89);
	triangle4(-868, -840, -728, -448, -644, -840);

	//back hair
	rectangle(-784, -224, 196, -224);

	//--face--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-784, -280, 140, -168);
	//bottom
	quads(-840, -504, -784, -448, -644, -448, -700, -504);
	//left
	quads(-840, -336, -784, -280, -784, -448, -840, -504);
	//right
	quads(-700, -336, -644, -280, -644, -448, -700, -504);
	//front
	rectangle(-840, -336, 140, -168);

	//--eyes--
	//outer eye
	glColor3f(1.0, 1.0, 1.0);
	circle(-784, -392, 28, 360);
	//inner eye
	glColor3f(0.0, 0.0, 0.0);
	circle(-784, -392, 10, 360);

	//--mouth--
	glColor3f(1.0, 0.0, 0.0);
	circle(-812, -476, 28, 360);

	//--hair--
	glColor3f(0.0, 0.0, 0.0);
	// bottom
	quads(-840, -336, -784, -280, -588, -280, -644, -336);
	quads(-700, -504, -644, -448, -588, -448, -644, -504);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-840, -280, -784, -224, -784, -280, -840, -336);
	// right
	quads(-644, -280, -588, -224, -588, -448, -644, -504);
	// front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-840, -280, 196, -56);
	rectangle(-700, -336, 56, -168);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-840, -280, -784, -224, -588, -224, -644, -280);

	//--ponytail--
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-616, -196, 112, -252);
	// bottom
	quads(-644, -476, -616, -448, -504, -448, -532, -476);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-644, -224, -616, -196, -616, -448, -644, -476);
	// right
	quads(-532, -224, -504, -196, -504, -448, -532, -476);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-644, -224, -616, -196, -504, -196, -532, -224);
	// front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-644, -224, 112, -252);

	//--arm--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-616, -532, 56, -56);
	//bottom
	quads(-784, -672, -616, -588, -560, -588, -728, -672);
	//left
	quads(-784, -616, -616, -532, -616, -588, -784, -672);
	//right
	quads(-728, -616, -560, -532, -560, -588, -728, -672);
	//top
	glColor3f(0.94, 0.93, 0.90);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-784, -616, 56, -56);

	glPopMatrix();
}

void bedroom_door()
{
	glColor3f(0.26, 0.19, 0.05); //brown
	//back
	quads(-1260, 560, -1064, 140, -1064, -1400, -1260, -1176);
	//left
	glColor3f(0.32, 0.24, 0.06);
	rectangle(-1316, 560, 56, -1736);
	//right
	rectangle(-1120, 140, 56, -1540);
	//top
	glColor3f(0.32, 0.24, 0.06);
	quads(-1316, 560, -1260, 560, -1064, 140, -1120, 140);
	//front
	glColor3f(0.26, 0.19, 0.05); //brown
	quads(-1316, 560, -1120, 140, -1120, -1400, -1316, -1176);

	//door frame
	//top
	glColor3f(0.32, 0.24, 0.06);
	quads(-1316, 560, -1036, 840, -1008, 812, -1260, 560);

	//----------------door handle---------------------
	glColor3f(0.77, 0.64, 0.52); //light brown
	//bottom
	quads(-1204, -504, -1176, -476, -1120, -476, -1148, -504);
	//left
	quads(-1204, -448, -1176, -420, -1176, -476, -1204, -504);
	//right
	quads(-1148, -448, -1120, -420, -1120, -476, -1148, -504);
	//top
	glColor3f(0.89, 0.75, 0.62); //light brown
	quads(-1204, -448, -1176, -420, -1120, -420, -1148, -448);
	//front
	glColor3f(0.77, 0.64, 0.52);
	rectangle(-1204, -448, 56, -56);
}


/*=================================
************SCENE 2**************
==================================*/

void bedroom2() //scene 2 - mrs creepy broke the window
{
	//floor
	glColor3f(0.5, 0.0, 0.0); //dark red
	quads(-840, 0, 1400, 0, 1400, -1400, -1400, -1400);

	//---------wall------------------
	//left-wall
	glColor3f(0.77, 0.64, 0.52); //light brown
	quads(-1400, 1400, -840, 1400, -840, 0, -1400, -1400);
	//right-wall
	glColor3f(0.79, 0.68, 0.56); //darker tint of light brown
	quads(-840, 1400, 1400, 1400, 1400, 0, -840, 0);


	//--------book shelf----------
	glColor3f(0.39, 0.34, 0.28); //dark brown
	//back
	rectangle(-700, 1260, 700, -1400);
	//left
	quads(-840, 1120, -700, 1260, -700, -140, -840, -280);
	//bottom
	quads(-700, -140, 0, -140, -140, -280, -840, -280);
	//top
	glColor3f(0.44, 0.39, 0.32);
	quads(-700, 1260, 0, 1260, -140, 1120, -840, 1120);
	glColor3f(0.39, 0.34, 0.28); //dark brown
	//right
	quads(-140, 1120, 0, 1260, 0, -140, -140, -280);

	//inner book shelf 1
	glColor3f(0.25, 0.21, 0.16); //darker brown
	//back
	rectangle(-700, 1064, 504, -224);
	//base
	glColor3f(0.31, 0.27, 0.22); //darker brown 0.31, 0.27, 0.22
	quads(-700, 840, -196, 840, -196, 700, -784, 700);

	//inner book shelf 2
	glColor3f(0.25, 0.21, 0.16); //darker brown
	//back
	rectangle(-700, 644, 504, -364);
	//base
	glColor3f(0.31, 0.27, 0.22); //darker brown 0.31, 0.27, 0.22
	quads(-700, 280, -196, 280, -196, 140, -784, 140);

	//inner book shelf 3
	glColor3f(0.25, 0.21, 0.16); //darker brown
	rectangle(-700, 84, 504, -224);
	//base
	glColor3f(0.31, 0.27, 0.22); //darker brown 0.31, 0.27, 0.22
	quads(-700, -140, -196, -140, -196, -224, -784, -224);

	//front book shelf 
	//front-top
	glColor3f(0.51, 0.45, 0.37);
	rectangle(-840, 1120, 700, -56);
	//front-right
	rectangle(-196, 1120, 56, -1400);
	//front-left
	rectangle(-840, 1120, 56, -1400);
	//front-bottom
	rectangle(-840, -224, 700, -56);

	//------------picture frame---------------- 
	//outer picture frame
	glColor3f(0.39, 0.34, 0.28); //dark brown
	//left
	quads(924, 1120, 952, 1148, 952, 672, 924, 644);
	//top
	quads(924, 1120, 952, 1148, 1372, 1148, 1344, 1120);
	//bottom
	quads(924, 644, 952, 672, 1372, 672, 1344, 644);
	//right
	glColor3f(0.46, 0.40, 0.27);
	quads(1344, 1120, 1372, 1148, 1372, 672, 1344, 644);
	//front
	glColor3f(0.50, 0.77, 0.86);
	rectangle(924, 1120, 420, -476);

	//mountain picture 2
	glColor3f(0.41, 0.10, 0.10); //red-brown
	quads(1176, 840, 1344, 1120, 1344, 644, 1260, 644);

	//mountain picture 1
	glColor3f(0.28, 0.07, 0.07); //red-brown
	glBegin(GL_TRIANGLES);
	glVertex2f(924, 644);
	glVertex2f(1120, 980);
	glVertex2f(1260, 644);
	glEnd();

	//----------------window----------------
	//outside view 
	//left
	glColor3f(0.08, 0.09, 0.28);
	rectangle(84, 812, 336, -476);
	//right
	rectangle(448, 812, 364, -476);

	//---------------window frame-----------------
	//back
	glColor3f(0.46, 0.40, 0.27);
	//left
	quads(56, 840, 112, 896, 112, 336, 56, 280);
	//top
	glColor3f(0.39, 0.34, 0.28); //dark brown
	quads(112, 896, 896, 896, 840, 840, 56, 840);
	//bottom
	quads(56, 280, 112, 336, 896, 336, 840, 280);
	//right
	glColor3f(0.46, 0.40, 0.27);
	quads(840, 840, 896, 896, 896, 336, 840, 280);

	//front-top
	glColor3f(0.54, 0.47, 0.33);
	rectangle(56, 840, 784, -28);
	//front-right
	rectangle(812, 840, 28, -560);
	//front-left
	rectangle(56, 840, 28, -560);
	//front-bottom
	rectangle(56, 308, 784, -28);
	//middle 
	rectangle(420, 840, 28, -560);

	//----------------window glass breaking-------------
	//--left window glass 1--
	// back
	glColor3f(0.19, 0.36, 0.40);
	triangle4(112, 812, 280, 588, 112, 476);
	// bottom
	quads(84, 812, 112, 812, 112, 476, 84, 448);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(84, 448, 112, 476, 280, 588, 280, 560);
	// left
	quads(84, 812, 112, 812, 280, 588, 280, 560);
	// front
	glColor3f(0.19, 0.36, 0.40);
	triangle4(84, 812, 280, 560, 84, 448);
	
	//--left window glass 2--
	// back
	triangle4(84, 476, 196, 392, 112, 364);
	// bottom
	triangle4(84, 476, 112, 364, 84, 308);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(84, 308, 112, 364, 196, 392, 196, 364);
	// left
	quads(84, 448, 84, 476, 196, 392, 196, 364);
	// front
	glColor3f(0.19, 0.36, 0.40);
	triangle4(84, 448, 196, 364, 84, 308);

	//--right window glass bottom--
	// back
	triangle4(560, 364, 784, 504, 784, 336);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(560, 336, 560,364, 784, 336, 812, 308);
	// left
	quads(560,336, 560,364, 784, 504, 812, 476);
	// front
	glColor3f(0.19, 0.36, 0.40);
	triangle4(560, 336, 812, 476, 812, 308);
	
	//--right window glass middle--
	// back
	triangle4(616, 560, 756, 644, 756, 504);
	// bottom
	quads(756, 504, 756, 644, 812, 672, 812, 420);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(616, 532, 616, 560, 756, 504, 812, 420);
	// left
	quads(616, 532, 616, 560, 812, 672, 812, 644);
	// front
	glColor3f(0.19, 0.36, 0.40);
	triangle4(616, 532, 812, 644, 812, 420);
	
	//--right window top--
	// back
	triangle4(616, 728, 728, 812, 728, 644);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(616, 700, 616, 728, 728, 644, 728, 616);
	// left
	quads(616, 700, 616, 728, 728, 812, 784, 812 );
	// front 
	glColor3f(0.19, 0.36, 0.40);
	triangle4(616, 700, 784, 812, 728, 616);
	quads(728, 616, 784, 812, 812, 812, 812, 672);

	//--glass on the floor--
	// **glass 1**
	// back
	triangle4(28, -84, 112, 0, 280, -84);
	// bottom
	quads(56, -112, 28, -84, 280,-84, 280, -112);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(112, 0, 280, -84, 280, -112, 140, -28);
	// left
	glColor3f(0.85, 0.91, 0.94);
	quads(28, -84, 112, 0, 140, -28, 56, -112);
	// front
	glColor3f(0.19, 0.36, 0.40);
	triangle4(56, -112, 140, -28, 280, -112);

	// **glass 2**
	// back
	rectangle(448, -112, 140, -84);
	// bottom
	quads(420, -224, 448, -196, 588, -196, 560, -224);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(560, -140, 588, -112, 588, -196, 560, -224);
	// left
	glColor3f(0.85, 0.91, 0.94);
	quads(420, -140, 448, -112, 448, -196, 420, -224);
	//top
	quads(420, -140, 448, -112, 588, -112, 560, -140);
	// front
	glColor3f(0.19, 0.36, 0.40);
	rectangle(420, -140, 140, -84);

	// **glass 3**
	// back
	quads(364, -392, 420, -336, 560, -364, 504, -448);
	// bottom
	glColor3f(0.85, 0.91, 0.94);
	quads(364, -392, 364, -364, 504, -420, 504, -448);
	// right
	glColor3f(0.75, 0.85, 0.86);
	quads(504, -448, 504, -420, 560, -336, 560, -364);
	// left
	quads(364, -392, 364, -364, 504, -420, 504, -448);
	// top
	quads(420, -280, 560, -336, 560, -364, 420, -336);
	// front
	glColor3f(0.19, 0.36, 0.40);
	quads(364, -364, 420, -280, 560, -336, 504, -420);

	// **glass 4**
	// back
	triangle4(168, -308, 280, -140, 280, -308);
	// bottom
	quads(84, -336, 168, -308, 280, -308, 252, -336);
	// right
	glColor3f(0.75, 0.85, 0.86);
	triangle4(252, -336, 280, -140, 280, -308);
	// left
	triangle4(84, -336, 280, -140, 168, -308);
	// front
	glColor3f(0.19, 0.36, 0.40);
	triangle4(84, -336, 280, -140, 252, -336);

	//----------------bed----------------
	//mattress 
	glColor3f(0.96, 0.75, 0.89); //light pink
	//back
	rectangle(784, -168, 700, -952);
	//left
	glColor3f(0.96, 0.70, 0.87);
	quads(700, -280, 784, -168, 784, -1120, 700, -1400);
	//front
	glColor3f(0.96, 0.75, 0.89); //light pink
	rectangle(700, -280, 700, -1120);

	//blanket
	//left
	glColor3f(0.94, 0.36, 0.52);
	quads(672, -560, 700, -532, 700, -1400, 672, -1400);
	//top
	glColor3f(0.92, 0.39, 0.53); //light pink
	quads(672, -560, 700, -532, 1400, -532, 1400, -560);
	//front
	rectangle(672, -560, 728, -840);

	//bedframe
	glColor3f(0.26, 0.19, 0.05); //brown
	//back
	rectangle(784, 252, 700, -420);
	//left 
	quads(700, 140, 784, 252, 784, -168, 700, -280);
	//top
	glColor3f(0.44, 0.39, 0.32);
	quads(700, 140, 784, 252, 1484, 252, 1400, 140);
	//bottom
	quads(700, -280, 784, -168, 1484, -168, 1400, -280);
	//right - out of frame
	quads(1400, 140, 1484, 252, 1484, -168, 1400, -280);
	//front
	glColor3f(0.37, 0.33, 0.27);
	rectangle(700, 140, 700, -420);
	//inner bedframe
	glColor3f(0.86, 0.63, 0.36); //brown
	rectangle(840, 140, 420, -420);

	//pillow
	glColor3f(0.92, 0.39, 0.53); //light pink
	//back
	rectangle(896, -280, 420, -140);
	//left
	glColor3f(0.94, 0.3, 0.49);
	quads(840, -336, 896, -280, 896, -420, 840, -476);
	//top
	glColor3f(0.96, 0.42, 0.56);
	quads(840, -336, 896, -280, 1316, -280, 1260, -336);
	//bottom
	glColor3f(0.92, 0.39, 0.53);
	quads(840, -476, 896, -420, 1316, -420, 1260, -476);
	//right
	glColor3f(0.94, 0.3, 0.49);
	quads(1260, -336, 1316, -280, 1316, -420, 1260, -476);
	//front
	glColor3f(0.92, 0.39, 0.53);
	rectangle(840, -336, 420, -140);

	glColor3f(0.08, 0.09, 0.28);

	//---------------outside the door---------------------
	glColor3f(0.08, 0.09, 0.28);
	quads(-1260, 560, -1036, 784, -1036, -504, -1260, -1036);

	//-------------------door---------------------
	//door frame
	//right
	glColor3f(0.26, 0.19, 0.05); //brown
	quads(-1036, 840, -1008, 812, -1008, -420, -1036, -504);
	
	mrs_creepy();

}
/*=================================
********scene 3 - 4 OBJECTS*******
==================================*/

void gate()
{
	glPushMatrix();
	//back
	glColor3f(0.21, 0.10, 0.05);
	rectangle2(-1344, 1316, 84, -420, -94);
	//bottom
	quads2(-1400, 840, -60, -1344, 896, -64, -1260, 896, -64, -1316, 840, -60);
	//left
	quads2(-1400, 1260, -80, -1344, 1316, -92, -1344, 896, -64,  -1400, 840, -60);
	//right
	glColor3f(0.28, 0.16, 0.18);
	quads2(-1316, 1260, -90,  -1260,   1316, -92, -1260, 896, -64, -1316, 840, -60);
	//top
	glColor3f(0.45, 0.26, 0.20);
	quads2(-1400, 1260, -90, -1344, 1316, -94, -1260, 1316, -94, -1316, 1260, -90);
	//front
	glColor3f(0.29, 0.15, 0.09);
	rectangle2(-1400, 1260, 84, -420, -90);
	glPopMatrix();
}

void gate2()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate();
	glPopMatrix();
}

void gate3()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate2();
	glPopMatrix();
}

void gate4()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate3();
	glPopMatrix();
}

void gate5()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate4();
	glPopMatrix();
}

void gate6()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate5();
	glPopMatrix();
}

void gate7()
{
	glPushMatrix();
	glTranslatef(X + 840, Y - 0, 0);
	gate6();
	glPopMatrix();
}

void gate8()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate7();
	glPopMatrix();
}

void gate9()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate8();
	glPopMatrix();
}

void gate10()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate9();
	glPopMatrix();
}

void gate11()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate10();
	glPopMatrix();
}

void gate12()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate11();
	glPopMatrix();
}

void gate13()
{
	glPushMatrix();
	glTranslatef(X + 168, Y - 0, 0);
	gate12();
	glPopMatrix();
}
void gate14() //horizontal gate
{
	glPushMatrix();
	//back
	glColor3f(0.21, 0.10, 0.05);
	rectangle2(-1372, 1148, 980, -56, -82);
	//bottom
	quads2(-1400, 1064, -76, -1372, 1092, -78,  -392, 1092, -78, -420, 1064, -76);
	//left
	quads2(-1400, 1064, -76, -1400, 1120, -78, -1372, 1148,-78,  -1372, 1092, -76);
	//right
	glColor3f(0.28, 0.16, 0.18);
	quads2(-420, 1064, -76,  -420, 1120, -80,  -392, 1148, -82, -392, 1092, -78);
	//top
	glColor3f(0.45, 0.26, 0.20);
	quads2(-1400, 1120, -80, -1372, 1148, -82,  -392, 1148, -82, -420, 1120, -80);
	//front
	glColor3f(0.29, 0.15, 0.09);
	rectangle2(-1400, 1120, 980, -56, -80);
	glPopMatrix();
}
void gate15()
{
	glPushMatrix();
	glTranslatef(X + 1624, Y - 0, 0);
	gate14();
	glPopMatrix();
}

void gate16()
{
	glPushMatrix();
	glTranslatef(X + 196, Y - 0, 0);
	gate15();
	glPopMatrix();
}

void full_gate()
{
	gate();
	gate2();
	gate3();
	gate4();
	gate5();
	gate6();
	gate7();
	gate8();
	gate9();
	gate10();
	gate11();
	gate12();
	gate13();
	gate14();
	gate15();
	gate16();
}

void road_line()
{
	glPushMatrix();
	glColor3f(0.77, 0.52, 0.11);
	rectangle(-56, 840, 56, -280);
	glPopMatrix();
}

void road_line2()
{
	glPushMatrix();
	glTranslatef(X + 0, Y - 420, 0);
	road_line();
	glPopMatrix();
}

void road_line3()
{
	glPushMatrix();
	glTranslatef(X + 0, Y - 420, 0);
	road_line2();
	glPopMatrix();
}

void road_line4()
{
	glPushMatrix();
	glTranslatef(X + 0, Y - 420, 0);
	road_line3();
	glPopMatrix();
}

void road_line5()
{
	glPushMatrix();
	glTranslatef(X + 0, Y - 420, 0);
	road_line4();
	glPopMatrix();
}

/*=================================
********CHARACTER SCENE 3**********
==================================*/

void Lily_run()
{
	//--leg--
	//right leg
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle2(84,-112, 56, -280, 8);
	//bottom - stop here
	quads2(56, -420, 30, 84, -392, 28, 140, -392, 28,  112, -420, 30);
	//left
	quads(56, -140, 84, -112, 84, -392, 56, -420);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(112, -140, 140, -112, 140, -392, 112, -420);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle2(56, -140,56, -280, 10);

	//left leg 2
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-112, -112, 56, -280);
	//bottom
	quads(-140, -420, -112, -392, -56, -392, -84, -420);
	//left
	quads(-140, -140, -112, -112, -112, -392, -140, -420);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(-84, -140, -56, -112, -56, -392, -84, -420);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-140, -140, 56, -280);

	//--right arm--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(252, 196, 56, -56);
	//bottom
	quads(56, 28, 252, 140, 308, 140, 112, 28);
	//left
	quads(56, 84, 252, 196, 252, 140,56, 28);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(112, 84, 308, 196, 308, 140, 112, 28);
	//top
	glColor3f(0.94, 0.93, 0.90);
	quads(56, 84, 252, 196, 308, 196, 112, 84);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(56, 84, 56, -56);

	//--left arm--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-280, 84, 252, -56);
	//bottom
	quads(-308, 0, -280, 28, -28, 28, -56, 0);
	//left
	quads(-308, 0, -280, 28, -280, 84, -308, 56);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(-56, 56, -28, 84, -28, 28, -56, 0);
	//top
	glColor3f(0.94, 0.93, 0.90);
	quads(-308, 56, -280, 84, -28, 84, -56, 56);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-308, 56, 252, -56);
	
	//--cloth--
	//cloth 1
	glColor3f(0.21, 0.47, 0.89);
	triangle4(0, 280, -280,-140, 0, -56);
	//cloth 2
	triangle4(0, 280, 280, -140, 0, -56);
	//cloth base
	quads(-280, -140, 0, -56, 280, -140, 0, -224);
	//cloth 3
	glColor3f(0.18, 0.43, 0.83);
	triangle4(0, 280, 280, -140, 0, -224);
	//cloth 4
	glColor3f(0.21, 0.47, 0.89);
	triangle4(0, 280, -280, -140, 0, -224);

	//--head--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-140, 336, 280, -196);
	//bottom
	quads(-140, 140, -84, 196, 196, 196, 140, 140);
	//left
	quads(-140, 140, -140, 336, -84, 392, -84, 224);
	//right
	quads(140, 140, 140, 336, 196, 392, 196, 196);
	//front
	rectangle(-84, 392, 280, -196);

	//--ponytail--
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-196, 504, 84, -280);
	// bottom
	quads(-224, 196, -196, 224, -112, 224, -140, 196);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-224, 196, -224, 476, -196, 504, -196, 224);
	// right
	quads(-140, 224, -140, 476, -112, 504, -112, 224);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-224, 476, -196, 504, -112, 504, -140, 476);
	// front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-224, 476, 84, -280);

	//--hair 1--
	glColor3f(0.0, 0.0, 0.0);
	//front
	rectangle(-84, 476, 280, -84);
	// bottom
	quads(-140, 420, -84, 448, 196, 448, 140, 420);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-140, 420, -84, 476, -84, 196, -140, 140);
	// right
	quads(140, 392, 140, 420, 196, 476, 196, 392);
	// back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-140, 420, 280, -280);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-140, 420, -84, 476, 196, 476, 140, 420);

}

void ghost_chase()
{
	//--face--
	//back
	glColor3f(0.24, 0.45, 0.30);
	rectangle(-28, -840, 168, -140);
	//bottom
	quads(-84, -1036, -28, -980, 140, -980, 84, -1036);
	//left
	quads(-84, -896, -28, -840, -28, -980, -84, -1036);
	//right
	quads(84, -896, 140, -840, 140, -980, 84, -1036);
	//front
	rectangle(-84, -896, 168, -140);
	
	//--cloth--
	glColor3f(1.0, 0.0, 0.0);
	//back
	rectangle(-140, -1064, 392, -336);
	//left
	glColor3f(0.86, 0.03, 0.03);
	quads(-196, -1120, -140, -1064, -140, -1400, -196, -1400);
	//right
	quads(196, -1120, 252, -1064, 252, -1400, 196, -1400);
	//top
	quads(-196, -1120, -140, -1064, 252, -1064, 196, -1120);
	//front
	glColor3f(1.0, 0.0, 0.0);
	rectangle(-196, -1120, 392, -336);

	//--hair--
	//**hair 1**
	//back
	glColor3f(0.0, 0.0, 0.0);
	//bottom
	quads(-140, -1260, -84, -1204, 196, -1204, 140, -1260);
	//left
	quads(-140, -840, -84, -784, -84, -1204, -140, -1260);
	//right
	glColor3f(0.12, 0.12, 0.13);
	quads(140, -840, 196, -784, 196, -1204, 140, -1260 );
	//top
	glColor3f(0.16, 0.16, 0.17);
	quads(-140, -840, -84, -784, 196, -784, 140, -840);
	//front
	glColor3f(0.17, 0.17, 0.19);
	rectangle(-140, -840, 280, -420);
}

/*=================================
************SCENE 3**************
==================================*/

void house_garden() //scene 3
{
	//-------------------sky---------------------
	glColor3f(0.08, 0.09, 0.28);
	rectangle(-1400, 1400, 2800, -476);
	//-------------------grass---------------------
	glColor3f(0.04, 0.23, 0.09);
	rectangle(-1400, 924, 2800, -2324);
	//-------------------road---------------------
	glColor3f(0.26, 0.24, 0.25);
	quads(-336, 924, 196, 924, 560, -1400, -560, -1400);

	road_line();
	road_line2();
	road_line3();
	road_line4();
	road_line5();

	//-------------------Lily---------------------
	Lily_run();
	//-------------------Mrs Creepy---------------------
	ghost_chase();

}

/*=================================
********SCENE 4 OBJECTS**********
==================================*/
void tree_trunk()
{
	glPushMatrix();
	//back
	glColor3f(0.21, 0.10, 0.05);
	rectangle(-1204, -504, 84, -840);
	//bottom
	quads(-1260, -1400, -1204, -1344, -1120, -1344, -1176, -1400);
	//left
	quads(-1260, -560, -1204, -504, -1204, -1344, -1260, -1400);
	//right
	glColor3f(0.28, 0.16, 0.18);
	quads(-1176, -560, -1120, -504, -1120, -1344, -1176, -1400);
	//top
	glColor3f(0.45, 0.26, 0.20);
	quads(-1260, -560, -1204, -504, -1120, -504, -1176, -560);
	//front
	glColor3f(0.29, 0.15, 0.09);
	rectangle(-1260, -560, 84, -840);
	glPopMatrix();
}

void tree_leaf1()
{
	glPushMatrix();
	//back
	glColor3f(0.03, 0.35, 0.12);
	triangle4(-1120, -140, -1260, -420, -980, -420);
	//left
	glColor3f(0.02, 0.26, 0.08);
	triangle4(-1400, -560, -1260, -420, -1120, -140);
	//base
	glColor3f(0.01, 0.15, 0.05);
	quads(-1400, -560, -1260, -420, -980, -420, -1064, -560);
	//right
	glColor3f(0.02, 0.26, 0.08);
	triangle4(-1120, -140, -1064, -560, -980, -420);
	//front
	glColor3f(0.03, 0.35, 0.12);
	triangle4(-1120, -280, -1400, -560, -1064, -560);
	glPopMatrix();
}

void tree_leaf2()
{
	glPushMatrix();
	glTranslatef(X - 56, Y - 420, 0);
	tree_leaf1();
	glPopMatrix();
}

void full_tree()
{
	glPushMatrix();
	tree_trunk();
	tree_leaf1();
	tree_leaf2();
	glPopMatrix();
}

void full_tree2()
{
	glPushMatrix();
	glTranslatef(X + 420,0, 0);
	full_tree();
	glPopMatrix();
}

void full_tree3()
{
	glPushMatrix();
	glTranslatef(X - 70, Y + 560, 0);
	full_tree();
	glPopMatrix();
}

void full_tree4()
{
	glPushMatrix();
	glTranslatef(X + 280, Y + 560, 0);
	full_tree();
	glPopMatrix();
}

void full_tree5()
{
	glPushMatrix();
	glTranslatef(X + 280, Y + 560, 0);
	full_tree4();
	glPopMatrix();
}

void full_tree6()
{
	glPushMatrix();
	glTranslatef(0, Y + 896, 0);
	full_tree();
	glPopMatrix();
}

void full_tree7()
{
	glPushMatrix();
	glTranslatef(0, Y + 1204, 0);
	full_tree();
	glPopMatrix();
}

void full_tree8()
{
	glPushMatrix();
	glTranslatef(X + 280, 0, 0);
	full_tree7();
	glPopMatrix();
}

void full_tree9()
{
	glPushMatrix();
	glTranslatef(X + 1960, 0, 0);
	full_tree();
	glPopMatrix();
}
void full_tree10()
{
	glPushMatrix();
	glTranslatef(X + 560, 0, 0);
	full_tree9();
	glPopMatrix();
}
void full_tree11()
{
	glPushMatrix();
	glTranslatef(0, Y + 560, 0);
	full_tree9();
	glPopMatrix();
}
void full_tree12()
{
	glPushMatrix();
	glTranslatef(X + 430, Y + 560, 0);
	full_tree9();
	glPopMatrix();
}
void full_tree13()
{
	glPushMatrix();
	glTranslatef(X - 140, Y + 980, 0);
	full_tree9();
	glPopMatrix();
}
void full_tree14()
{
	glPushMatrix();
	glTranslatef(X - 280, Y + 1400, 0);
	full_tree9();
	glPopMatrix();
}

void full_tree15()
{
	glPushMatrix();
	glTranslatef(X + 140, Y + 1400, 0);
	full_tree9();
	glPopMatrix();
}

void full_tree16()
{
	glPushMatrix();
	glTranslatef(X + 420, Y + 1400, 0);
	full_tree9();
	glPopMatrix();
}

/*=================================
************SCENE 4 **********
==================================*/

void forest() //scene 4 - Lily run away
{
	//-------------------sky---------------------
	glColor3f(0.08, 0.09, 0.28);
	rectangle(-1400, 1400, 2800, -476);
	//-------------------grass---------------------
	glColor3f(0.04, 0.23, 0.09);
	rectangle(-1400, 924, 2800, -2324);
	//-------------------road---------------------
	glColor3f(0.26, 0.24, 0.25);
	quads(-336, 924, 196, 924, 560, -1400, -560, -1400);

	road_line();
	road_line2();
	road_line3();
	road_line4();
	road_line5();
	//-------------------trees---------------------
	full_tree8();
	full_tree7();
	full_tree6();
	full_tree5();
	full_tree4();
	full_tree3();
	full_tree2();
	full_tree();
	full_tree16();
	full_tree15();
	full_tree14();
	full_tree13();
	full_tree12();
	full_tree11();
	full_tree10();
	full_tree9();
	
	//-------------------Lily---------------------
	Lily_run();
	//-------------------Mrs Creepy---------------------
	ghost_chase();
}

void Lily_trips() //scene 5 - Lily trips on a rock and fell
{
	//-------------------sky---------------------
	glColor3f(0.08, 0.09, 0.28);
	rectangle(-1400, 1400, 2800, -476);
	//-------------------grass---------------------
	glColor3f(0.04, 0.23, 0.09);
	rectangle(-1400, 924, 2800, -2324);
	//-------------------road---------------------
	glColor3f(0.26, 0.24, 0.25);
	quads(-336, 924, 196, 924, 560, -1400, -560, -1400);

	road_line();
	road_line2();
	road_line3();
	road_line4();
	road_line5();
	//-------------------trees---------------------
	full_tree8();
	full_tree7();
	full_tree6();
	full_tree5();
	full_tree4();
	full_tree3();
	full_tree2();
	full_tree();
	full_tree16();
	full_tree15();
	full_tree14();
	full_tree13();
	full_tree12();
	full_tree11();
	full_tree10();
	full_tree9();

	//-------------------Lily---------------------
	Lily_run();
	//-------------------Mrs Creepy---------------------
}

/*=================================
************SCENE 6 OBJECTS**********
==================================*/

void Lily_eye_close1()
{
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-420, 28, 280, -56);
	glPopMatrix();
}
void Lily_eye_close2()
{
	glPushMatrix();
	glTranslatef(X + 560, 0, 0);
	Lily_eye_close1();
	glPopMatrix();
}

void Lily_eye_open1()
{
	glPushMatrix();
	//outer eye
	glColor3f(1.0, 1.0, 1.0);
	circle(-280, 0, 140, 360);
	//inner eye
	glColor3f(1.0, 0.0, 0.0);
	circle(-280, 0, 84, 360);
	glPopMatrix();
}
void Lily_eye_open2()
{
	glPushMatrix();
	glTranslatef(X + 560, 0 , 0);
	Lily_eye_open1();
	glPopMatrix();
}
void Lily_mouth_close()
{
	glPushMatrix();
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-280, -420, 560, -56);
	glPopMatrix();
}

void Lily_mouth_open()
{
	glPushMatrix();
	glColor3f(1.0, 0.0, 0.0);
	circle(0, -420, 224, 360);
	glPopMatrix();
}

void Lily_head()
{
	glPushMatrix();

	//--ponytail--
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-700, 980, 280, -1120);
	// bottom
	quads(-840, -280, -700, -140, -420, -140, -560, -280);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-840, 840, -700, 980, -700, -140, -840, -280);
	// right
	quads(-560, 840, -420, 980, -420, -140, -560, -280);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-840, 840, -700, 980, -420, 980, -560, 840);
	// front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-840, 840, 280, -1120);

	//--hair 1--
	glColor3f(0.0, 0.0, 0.0);
	//back
	rectangle(-420, 700, 1120, -1400);
	
	//--trachea--
	//back
	glColor3f(1.0, 0.6, 0.61);
	rectangle(0, -700, 168, -700);
	// left
	glColor3f(0.74, 0.13, 0.09);
	quads(-84, -784, 0, -700, 0, -1400, -84, -1400);
	// right
	quads(84, -784, 168, -700, 168, -1400, 84, -1400);
	//front
	glColor3f(1.0, 0.6, 0.61);
	rectangle(-84, -784, 168, -700);
	
	//--face--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-420, 420, 1120, -1120);
	//bottom
	quads(-560, -560, -420, -420, 700, -420, 560, -560);
	//left
	quads(-560, 280, -420, 420, -420, -700, -560, -840);
	//right-change to darker color
	quads(560, 280, 700, 420, 700, -700, 560, -840);
	//top
	quads(-560, 280, -420, 420, 700, 420, 560, 280);
	//front
	rectangle(-560, 280, 1120, -1120);
	
	// --hair 1--
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-560, 560, -420, 700, -420, 420, -560, 280);
	// right
	quads(560, 560, 700, 700, 700, 420, 560, 280);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-560, 560, -420, 700, 700, 700, 560, 560);
	//front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-560, 560, 1120, -280);

	glPopMatrix();
}

/*=================================
************SCENE 6**************
==================================*/

void Lily_fainted() //scene 6 part 1 - Lily still close her eyes
{
	//-------------------grass---------------------
	glColor3f(0.04, 0.23, 0.09);
	rectangle(-1400, 1400, 2800, -2800);
	//-------------------Lily head---------------------
	Lily_head();
	Lily_eye_close1();
	Lily_eye_close2();
	Lily_mouth_close();
}

void Lily_woke_up() //scene 6 - Lily woke up after fainted
{
	//-------------------grass---------------------
	glColor3f(0.04, 0.23, 0.09);
	rectangle(-1400, 1400, 2800, -2800);
	//-------------------Lily head---------------------
	Lily_head();
	Lily_eye_open1();
	Lily_eye_open2();
	Lily_mouth_close();
}

void Lily_shoked() //scene 6 - Lily shocked
{
	//-------------------grass---------------------
	glColor3f(0.04, 0.23, 0.09);
	rectangle(-1400, 1400, 2800, -2800);
	//-------------------Lily head---------------------
	Lily_head();
	Lily_eye_open1();
	Lily_eye_open2();
	Lily_mouth_open();
}

/*=================================
************SCENE 7 OBJECTS**********
==================================*/

void Lily_left_eye()
{
	glPushMatrix();
	//outer eye
	glColor3f(1.0, 1.0, 1.0);
	circle(-756, -140, 28, 360);
	//inner eye
	glColor3f(1.0, 0.0, 0.0);
	circle(-756, -140, 14, 360);
	glPopMatrix();
}
void Lily_right_eye()
{
	glPushMatrix();
	glTranslatef(X + 112, 0, 0);
	Lily_left_eye();
	glPopMatrix();
}
void Lily_left_trachea()
{
	glPushMatrix();
	//--trachea left --
	//back
	glColor3f(1.0, 0.6, 0.61);
	rectangle(-756, -364, 84, -28);
	//bottom
	quads(-784, -420, -756, -392, -672, -392, -700, -420);
	// left
	glColor3f(0.74, 0.13, 0.09);
	quads(-784, -392, -756, -364, -756, -392, -784, -420);
	// right
	quads(-700, -392, -672, -364, -672, -392, -700, -420);
	//top
	quads(-784, -392, -756, -364, -672, -364, -700, -392);
	//front
	glColor3f(1.0, 0.6, 0.61);
	rectangle(-784, -392, 84, -28);
	glPopMatrix();
}

void Lily_right_trachea()
{
	glPushMatrix();
	glTranslatef(X + 84, 0, 0);
	Lily_left_trachea();
	glPopMatrix();
}
void Lily_left_lung()
{
	glPushMatrix();
	//back
	glColor3f(0.99, 0.79, 0.79);
	quads(-868, -364, -812, -364, -812, -532, -952, -532);
	//bottom
	quads(-1008, -560, -952, -532, -812, -532, -840, -560);
	// left
	glColor3f(1.0, 0.71, 0.72);
	triangle4(-1008, -560, -952, -532, -868, -364);
	// right
	quads(-840, -392, -812, -364, -812, -532, -840, -560);
	// top
	glColor3f(0.98, 0.83, 0.82);
	quads(-896, -392, -868, -364, -812, -364, -840, -392);
	//front
	glColor3f(0.99, 0.79, 0.79);
	quads(-896, -392, -840, -392, -840, -560, -1008, -560);
	glPopMatrix();
}

void Lily_left_lung1()
{
	glPushMatrix();
	glTranslatef(X + 56, 0, 0);
	Lily_left_lung();
	glPopMatrix();
}

void Lily_right_lung()
{
	glPushMatrix();
	//back
	glColor3f(0.99, 0.79, 0.79);
	quads(-644, -364, -588, -364, -476, -532, -644, -532);
	//bottom
	quads(-672, -560, -644, -532, -476, -532, -504, -560);
	// left
	glColor3f(1.0, 0.71, 0.72);
	quads(-672, -392, -644, -364, -644, -532, -672, -560);
	// right
	quads(-616, -392, -588, -364, -476, -532, -504, -560);
	// top
	glColor3f(0.98, 0.83, 0.82);
	quads(-672, -392, -644, -364, -588, -364, -616, -392);
	//front
	glColor3f(0.99, 0.79, 0.79);
	quads(-672, -392, -616, -392, -504, -560, -672, -560);

	glPopMatrix();
}

void Lily_right_lung2()
{
	glPushMatrix();
	glTranslatef(X + 28, 0, 0);
	Lily_right_lung();
	glPopMatrix();
}
void Lily_intestine()
{
	glPushMatrix();

	//back
	glColor3f(0.71, 0.03, 0.02);
	rectangle(-868, -504, 56, -140);
	//bottom
	quads(-896, -672, -868, -644, -812, -644, -840, -672);
	// left
	glColor3f(0.74, 0.07, 0.06);
	quads(-896, -532, -868, -504, -868, -644, -896, -672);
	// right
	quads(-840, -532, -812, -504, -812, -644, -840, -672);
	// top
	glColor3f(0.77, 0.1, 0.09);
	quads(-896, -532, -868, -504, -812, -504, -840, -532);
	//front
	glColor3f(0.71, 0.03, 0.02);
	rectangle(-896, -532, 56, -140);

	glPopMatrix();
}
void Lily_intestine2()
{
	glPushMatrix();
	//back
	glColor3f(0.71, 0.03, 0.02);
	rectangle(-812, -588, 280, -56);
	//bottom
	quads(-840, -672, -812, -644, -532, -644, -560, -672);
	// left
	glColor3f(0.74, 0.07, 0.06);
	quads(-840, -616, -812, -588, -812, -644, -840, -672);
	// right
	quads(-560, -616, -532, -588, -532,-644, -560, -672 );
	// top
	glColor3f(0.77, 0.1, 0.09);
	quads(-840, -616, -812, -588, -532, -588, -560, -616);
	//front
	glColor3f(0.71, 0.03, 0.02);
	rectangle(-840, -616,280, -56);
	glPopMatrix();
}
void Lily_intestine3()
{
	glPushMatrix();
	glTranslatef(X + 280, Y - 84, 0);
	Lily_intestine();
	glPopMatrix();
}
void Lily_intestine4()
{
	glPushMatrix();
	glTranslatef(0, Y - 140, 0);
	Lily_intestine2();
	glPopMatrix();
}
void Lily_intestine5()
{
	glPushMatrix();
	glTranslatef(0, Y - 224, 0);
	Lily_intestine();
	glPopMatrix();
}
void Lily_intestine6()
{
	glPushMatrix();
	glTranslatef(X - 56, Y - 140, 0);
	Lily_intestine4();
	glPopMatrix();
}
void Lily_intestine7()
{
	glPushMatrix();
	glTranslatef(X + 252, Y - 140, 0);
	Lily_intestine5();
	glPopMatrix();
}

void Lily_organ()
{
	glPushMatrix();
	
	//--intestine --
	Lily_intestine();
	Lily_intestine2();
	Lily_intestine6();
	Lily_intestine5(); //did not move
	Lily_intestine4(); //did not move
	Lily_intestine3(); //did not move
	Lily_intestine7(); //did not move

	//--lungs --
	Lily_left_lung1();
	Lily_left_trachea();
	Lily_right_trachea();
	Lily_right_lung2();
	//--trachea middle --
	//back
	glColor3f(1.0, 0.6, 0.61);
	rectangle(-700, -224, 56, -168);
	//bottom
	quads(-728, -420, -700, -392, -644, -392, -672, -420);
	// left
	glColor3f(0.74, 0.13, 0.09);
	quads(-728, -252, -700, -224, -700, -392, -728, -420);
	// right
	quads(-672, -252, -644, -224, -644, -392, -672, -420);
	//front
	glColor3f(1.0, 0.6, 0.61);
	rectangle(-728, -252, 56, -168);

	glPopMatrix();
}

void Lily_head2()
{
	glPushMatrix();

	//--ponytail--
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-896, 140, 84, -280);
	// bottom
	quads(-924, -196, -896, -140, -812, -140, -840, -196);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-924, 84, -896, 140, -896, -140, -924, -196);
	// right
	quads(-840, 84, -812, 140, -812, -140, -840, -196);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-924, 84, -896, 140, -812, 140, -840, 84);
	// front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-924, 84, 84, -280);

	//--hair 1--
	glColor3f(0.0, 0.0, 0.0);
	//back
	rectangle(-784, 56, 280, -280);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-840, 0, -784, 56, -784, -224, -840, -280);

	Lily_organ();
	
	//--face--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-784, -28, 280, -196);
	//bottom
	quads(-840, -280, -784, -224, -504, -224, -560, -280);
	//left
	glColor3f(0.9, 0.85, 0.76);
	quads(-840, -84, -784, -28, -784, -224, -840, -280 );
	//right-change to darker color
	quads(-560, -84, -504, -28, -504, -224, -560, -280);
	//top
	quads(-840, -84, -784, -28, -504, -28, -560, -84);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-840, -84, 280, -196);
	
	// --hair 1--
	//right
	glColor3f(0.12, 0.12, 0.13);
	quads(-560, 0, -504, 56, -504, -28, -560, -84);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-840, 0, -784, 56, -504, 56, -560, 0);
	//front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-840, 0, 280, -84);

	Lily_left_eye();
	Lily_right_eye();
	
	//--mouth--
	glColor3f(1.0, 0.0, 0.0);
	circle(-700, -224, 28, 360);

	glPopMatrix();
}
void Lily_left_leg()
{
	glPushMatrix();
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-308, -616, 280, -56);
	//bottom
	quads(-336, -700, -308, -672, -28, -672, -56, -700);
	//left
	quads(-336, -644, -308, -616, -308, -672, -336, -700);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(-56, -644, -28, -616, -28, -672, -56, -700);
	//top
	glColor3f(0.94, 0.93, 0.90);
	quads(-336, -644, -308, -616, -28, -616, -56, -644);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-336, -644, 280, -56);
	glPopMatrix();
}

void Lily_right_leg()
{
	glPushMatrix();
	glTranslatef(0, Y - 112, 0);
	Lily_left_leg();
	glPopMatrix();
}

void Lily_body()
{
	glPushMatrix();
	//--right arm--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-616, -812, 56, -56);
	//bottom
	quads(-728, -1064, -616, -868, -560, -868, -672, -1064);
	//left
	quads(-728, -1008, -616, -812, -560, -868, -728, -1064);
	//right
	glColor3f(0.94, 0.93, 0.90);
	quads(-672, -1008, -560, -812, -560, -868, -672, -1064);
	//top
	glColor3f(0.94, 0.93, 0.90);
	quads(-728, -1008, -616, -812, -560, -812, -672, -1008);
;	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-728, -1008,56, -56);

	// --leg--
	Lily_left_leg();
	Lily_right_leg();

	//--cloth--
	//cloth back
	glColor3f(0.21, 0.47, 0.89);
	triangle4(-840, -840, -420, -644, -420, -840);
	//cloth left
	triangle4(-840, -840, -420, -840, -280, -980);
	//cloth base
	quads(-420, -840, -420, -476, -280, -560, -280, -980);
	//cloth top
	glColor3f(0.18, 0.43, 0.83);
	triangle4(-840, -840, -280, -560, -420, -476);
	//cloth front
	glColor3f(0.21, 0.47, 0.89);
	triangle4(-840, -840, -280, -560, -280, -980);

	//--left arm--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-588, -644, 56, -56);
	//bottom
	quads(-588, -700, -532, -700, -448, -896, -504, -896);
	//left
	glColor3f(0.94, 0.93, 0.90);
	quads(-588, -700, -588, -644, -504, -840, -504, -896);
	//right
	quads(-532, -644, -448, -840, -448, -896, -532, -700);
	//top
	glColor3f(0.94, 0.93, 0.90);
	quads(-588, -644, -532, -644, -448, -840, -504, -840);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-504, -840,56, -56);
	glPopMatrix();
}
void Lily_body_new()
{
	glPushMatrix();
	glTranslatef(X + 420, Y - 112, 0);
	Lily_body();
	glPopMatrix();
}
void mrs_creepy2()
{
	glPushMatrix();
	glTranslatef(0, Y + 840, 0);
	mrs_creepy();
	glPopMatrix();
}

void big_tree_trunk()
{
	glPushMatrix();
	//back
	glColor3f(0.21, 0.10, 0.05);
	rectangle(1176, 756, 140, -2100);
	//bottom
	quads(1120, -1400, 1176, -1344, 1316, -1344, 1260, -1400);
	//left
	glColor3f(0.28, 0.16, 0.18);
	quads(1120, 700, 1176, 756, 1176, -1344, 1120, -1400);
	//right
	quads(1260, 700, 1316, 756, 1316, -1344, 1260, -1400);
	//top
	glColor3f(0.45, 0.26, 0.20);
	quads(1120, 700, 1176, 756, 1316, 756, 1260, 700);
	//front
	glColor3f(0.29, 0.15, 0.09);
	rectangle(1120, 700, 140, -2100);
	
	glPopMatrix();
}

void big_leaf()
{
	glPushMatrix();

	//back
	glColor3f(0.03, 0.35, 0.12);
	triangle4(1260, 1260, 1120, 700, 1680, 700);
	//left
	glColor3f(0.02, 0.26, 0.08);
	triangle4(840, 560, 1260, 1260, 1120, 700);
	//base
	glColor3f(0.01, 0.15, 0.05);
	quads(840, 560, 1120, 700, 1680, 700, 1540, 560);
	//right
	glColor3f(0.02, 0.26, 0.08);
	triangle4(1260, 1260, 1540, 560, 1680, 700);
	//front
	glColor3f(0.03, 0.35, 0.12);
	triangle4(840, 560, 1260, 1260, 1540, 560);

	glPopMatrix();
}

void big_leaf2()
{
	glPushMatrix();
	glTranslatef(X - 56, Y - 840, 0);
	big_leaf();
	glPopMatrix();
}

void full_big_tree()
{
	glPushMatrix();
	big_tree_trunk();
	big_leaf();
	big_leaf2();
	glPopMatrix();
}

void small_tree()
{
	glPushMatrix();
	glTranslatef(X - 56, Y + 1680, 0);
	full_tree();
	glPopMatrix();
}

void small_tree2()
{
	glPushMatrix();
	glTranslatef(X + 420, Y + 84, 0);
	small_tree();
	glPopMatrix();
}

void small_tree3()
{
	glPushMatrix();
	glTranslatef(X + 840, Y - 84, 0);
	small_tree();
	glPopMatrix();
}

void small_tree4()
{
	glPushMatrix();
	glTranslatef(X + 1260, Y - 56, 0);
	small_tree();
	glPopMatrix();
}

void small_tree5()
{
	glPushMatrix();
	glTranslatef(X + 1680, Y + 112, 0);
	small_tree();
	glPopMatrix();
}
void small_tree6()
{
	glPushMatrix();
	glTranslatef(X + 2100, Y - 112, 0);
	small_tree();
	glPopMatrix();
}

void Lily_head3()
{
	glPushMatrix();

	//--ponytail--
	//back
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-896, 140, 84, -280);
	// bottom
	quads(-924, -196, -896, -140, -812, -140, -840, -196);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-924, 84, -896, 140, -896, -140, -924, -196);
	// right
	quads(-840, 84, -812, 140, -812, -140, -840, -196);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-924, 84, -896, 140, -812, 140, -840, 84);
	// front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-924, 84, 84, -280);

	//--hair 1--
	glColor3f(0.0, 0.0, 0.0);
	//back
	rectangle(-784, 56, 280, -280);
	// left
	glColor3f(0.12, 0.12, 0.13);
	quads(-840, 0, -784, 56, -784, -224, -840, -280);

	//--face--
	glColor3f(0.87, 0.84, 0.79);
	//back
	rectangle(-784, -28, 280, -196);
	//bottom
	quads(-840, -280, -784, -224, -504, -224, -560, -280);
	//left
	glColor3f(0.9, 0.85, 0.76);
	quads(-840, -84, -784, -28, -784, -224, -840, -280);
	//right-change to darker color
	quads(-560, -84, -504, -28, -504, -224, -560, -280);
	//top
	quads(-840, -84, -784, -28, -504, -28, -560, -84);
	//front
	glColor3f(0.87, 0.84, 0.79);
	rectangle(-840, -84, 280, -196);

	// --hair 1--
	//right
	glColor3f(0.12, 0.12, 0.13);
	quads(-560, 0, -504, 56, -504, -28, -560, -84);
	// top
	glColor3f(0.15, 0.15, 0.16);
	quads(-840, 0, -784, 56, -504, 56, -560, 0);
	//front
	glColor3f(0.0, 0.0, 0.0);
	rectangle(-840, 0, 280, -84);

	Lily_left_eye();
	Lily_right_eye();

	//--mouth--
	glColor3f(1.0, 0.0, 0.0);
	circle(-700, -224, 28, 360);

	glPopMatrix();
}

/*=================================
************SCENE 7**************
==================================*/

void Lily_ghost() // scene 7 - Lily realized her head was cut off
{
	//-------------------sky---------------------
	glColor3f(0.08, 0.09, 0.28);
	rectangle(-1400, 1400, 2800, -840);
	//-------------------grass---------------------
	glColor3f(0.04, 0.23, 0.09);
	rectangle(-1400, 560, 2800, -1960);
	//-------------------tree---------------------
	small_tree();
	small_tree2();
	small_tree3();
	small_tree4();
	small_tree5();
	small_tree6();
	full_big_tree();
	
	//-------------------characters---------------------
	Lily_body_new();
	
	mrs_creepy2();
}

/*=============================
*****SPEED & MOVEMENTS*******
==============================*/
void Lily_run_outside() {
	glPushMatrix();
	glTranslatef(-Lily_X + -140, Lily_Y, 0);
	Lily_side_view();
	glPopMatrix();
}
void ghost_chase_outside() {
	glPushMatrix();
	glTranslatef(-ghost_X + -140, ghost_Y, 0);
	Lily_side_view();
	glPopMatrix();
}

//scene 3 movement
void gate_Lily_run()
{
	glPushMatrix();
	glTranslatef(gate_X, gate_Y, gate_Z + 1400);
	full_gate();
	glPopMatrix();
}

void Lily_head_fly() {
	glPushMatrix();
	glTranslatef(Lily_head_X , Lily_head_Y, 0);
	Lily_head3();
	glPopMatrix();
}
void Lily_organ_fly() {
	glPushMatrix();
	glTranslatef(Lily_head_X, Lily_head_Y, 0);
	Lily_organ();
	glPopMatrix();
}

void move() {

	if (LilyStatus == 1) {
		Lily_X += 0.5;

		if (Lily_X == (SCREEN_WIDTH / 2) - 400) {
			Lily_X -= 0.5;
		}
	}
	glutPostRedisplay();

}

//scene 3 - Lily run 
void move2() //didnt work - trying to fix 
{
	if (gateStatus == 1) {
		gate_Z += 0.5;

		if (gate_Z == (100 / 2) - 400) {
			gate_Z -= 0.5;
		}
	}
	glutPostRedisplay();
}

//scene 10 movement
void move3()
{
	//Lily head move
	if (LilyHeadStatus == 1) {

		Lily_head_X += 0.5;
		Lily_head_Y += 0.5;
		if (Lily_head_X > SCREEN_WIDTH && Lily_head_Y > SCREEN_HEIGHT) {
			LilyHeadStatus++;
		}
	}
	else if (LilyHeadStatus == 2) {

		Lily_head_Y -= 0.5;
		if (Lily_head_X > SCREEN_WIDTH && Lily_head_Y < -SCREEN_HEIGHT) {
			LilyHeadStatus++;
		}
	}
	else if (LilyHeadStatus == 3) {

		Lily_head_X -= 0.5;
		Lily_head_Y += 0.5;
		if (Lily_head_X < -SCREEN_WIDTH && Lily_head_Y > SCREEN_HEIGHT) {
			LilyHeadStatus++;
		}
	}
	else if (LilyHeadStatus == 4) {

		Lily_head_Y -= 0.5;
		if (Lily_head_X < -SCREEN_WIDTH && Lily_head_Y < -SCREEN_HEIGHT) {
			LilyHeadStatus -= 3;

		}
	}
	else if (LilyHeadStatus == 5) {
		Lily_head_X == 0;
		Lily_head_Y == 0;

	}

	//Lily organ move
	if (LilyOrganStatus == 1) {

		Lily_organ_X += 0.5;
		Lily_organ_Y += 0.5;
		if (Lily_organ_X > SCREEN_WIDTH && Lily_organ_Y > SCREEN_HEIGHT) {
			LilyOrganStatus++;
		}
	}
	else if (LilyOrganStatus == 2) {

		Lily_organ_Y -= 0.5;
		if (Lily_organ_X > SCREEN_WIDTH && Lily_organ_Y < -SCREEN_HEIGHT) {
			LilyOrganStatus++;
		}
	}
	else if (LilyOrganStatus == 3) {

		Lily_organ_X -= 0.5;
		Lily_organ_Y += 0.5;
		if (Lily_organ_X < -SCREEN_WIDTH && Lily_organ_Y > SCREEN_HEIGHT) {
			LilyOrganStatus++;
		}
	}
	else if (LilyOrganStatus == 4) {

		Lily_organ_Y -= 0.5;
		if (Lily_organ_X < -SCREEN_WIDTH && Lily_organ_Y < -SCREEN_HEIGHT) {
			LilyOrganStatus -= 3;

		}
	}
	else if (LilyOrganStatus == 5) {
		Lily_organ_X == 0;
		Lily_organ_Y == 0;

	}

	glutPostRedisplay();
	
}


/*=============================
********DISPLAY FUNCTION*******
==============================*/

void display()
{
	bedroom();
	glFlush();
	glutSwapBuffers();
}
void display2()
{
	bedroom2();
	bedroom_door();
	Lily_side_view();
	glFlush();
	glutSwapBuffers();
}
void display3()
{
	bedroom2();
	Lily_run_outside();
	bedroom_door();
	move();
	glFlush();
	glutSwapBuffers();
}
void display4()
{
	house_garden();
	full_gate();
	glFlush();
	glutSwapBuffers();
}
void display5()
{
	house_garden();
	gate_Lily_run();
	move2();
	glFlush();
	glutSwapBuffers();
}
void display6()
{
	forest();
	glFlush();
	glutSwapBuffers();
}
void display7()
{
	Lily_fainted();
	glFlush();
	glutSwapBuffers();
}
void display8()
{
	Lily_woke_up();
	glFlush();
	glutSwapBuffers();
}
void display9()
{
	Lily_shoked();
	glFlush();
	glutSwapBuffers();
}
void display10()
{
	Lily_ghost();
	Lily_head2();
	glFlush();
	glutSwapBuffers();
}

void display11()
{
	Lily_ghost();
	Lily_head_fly();
	Lily_organ_fly();
	move3();
	glFlush();
	glutSwapBuffers();
}

void idle() {
	DWORD start = GetTickCount();
	while (GetTickCount() - start < 1000 / FPS);
	ghost_X += dx;
	ghost_Y += dy;

	if (ghost_X < 0 || ghost_X > SCREEN_WIDTH) dx *= -1;
	if (ghost_Y < 0 || ghost_Y > SCREEN_HEIGHT) dy *= -1;

	glutPostRedisplay();
}

void initGL() {

	glClearColor(0.55, 0.55, 0.55, 0.55);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-SCREEN_WIDTH, SCREEN_WIDTH, -SCREEN_HEIGHT, SCREEN_HEIGHT, 100, -100); //left, right, bottom, top, near, far = near n far

}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowSize(SCREEN_WIDTH, SCREEN_HEIGHT);
	glutCreateWindow("Mrs Creepy II");
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutTimerFunc(1000, MyTimerFunc, 0);

	initGL();
	glutMainLoop();
}

void MyTimerFunc(int value)
{
	if (value == 0)
	{
		glutDisplayFunc(display);
		glutIdleFunc(display);
		glutTimerFunc(2000, MyTimerFunc, 1);
	}

	else if (value == 1)
	{
		glutDisplayFunc(display2);
		glutIdleFunc(display2);
		glutTimerFunc(2000, MyTimerFunc, 2);
	}
	else if (value == 2)
	{
		glutDisplayFunc(display3);
		glutIdleFunc(display3);
		glutTimerFunc(2000, MyTimerFunc, 3);
	}
	else if (value == 3)
	{
		glutDisplayFunc(display4);
		glutIdleFunc(display4);
		glutTimerFunc(3000, MyTimerFunc, 4);
	}
	else if (value == 4)
	{
		glutDisplayFunc(display5);
		glutIdleFunc(display5);
		glutTimerFunc(2500, MyTimerFunc, 5);
	}
	else if (value == 5)
	{
		glutDisplayFunc(display6);
		glutIdleFunc(display6);
		glutTimerFunc(2000, MyTimerFunc, 6);
	}
	else if (value == 6)
	{
		glutDisplayFunc(display7);
		glutIdleFunc(display7);
		glutTimerFunc(2000, MyTimerFunc, 7);
	}
	else if (value == 7)
	{
		glutDisplayFunc(display8);
		glutIdleFunc(display8);
		glutTimerFunc(2000, MyTimerFunc, 8);
	}
	else if (value == 8)
	{
		glutDisplayFunc(display9);
		glutIdleFunc(display9);
		glutTimerFunc(2000, MyTimerFunc, 9);
	}
	else if (value == 9)
	{
		glutDisplayFunc(display10);
		glutIdleFunc(display10);
		glutTimerFunc(2000, MyTimerFunc, 10);
	}
	else if (value == 10)
	{
		glutDisplayFunc(display11);
		glutIdleFunc(display11);
		glutTimerFunc(2000, MyTimerFunc, 11);
	}
	
}
