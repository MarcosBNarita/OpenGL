#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
#define pi 3.1415926535898

void draw(void);
std::string int2str(int x);
void drawText(float x, float y, std::string text);
void updateCarro(void);
void enable2D(int, int);
void update(int);
int score = 0;
int width = 500;
int height = 200;
int interval = 1000 / 60;
//carros
int v1 = 6;
int v2 = 5;
int v3 = 7;
int v4 = 10;
float carro1x = 0;
float carro2x = 0;
float carro3x = width;
float carro4x = width;
// galinha
float galx = width / 2;
float galy = 10;
int vg = 3;

// Main
int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(width, height);
	glutCreateWindow("Pong");

	glutDisplayFunc(draw);
	glutTimerFunc(interval, update, 0);
	enable2D(width, height);
	glColor3f(1.0f, 1.0f, 1.0f);
	glutMainLoop();
	return 0;
}


void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();

	//pontuação
	drawText(width / 2 - 10, height - 15, int2str(score));


	//Faixas
	for (int i = 0; i < 250; i++) {
		glLineWidth(4.0f);
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f((i*10), (height / 2));
		glVertex2f(((i*10)+5), (height / 2));
		glEnd();
	}

	for (int i = 0; i < 250; i++) {
		glLineWidth(4.0f);
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f((i * 10), (height-65));
		glVertex2f(((i * 10) + 5), (height-65));
		glEnd();
	}


	glLineWidth(4.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0, (height-30));
	glVertex2f(800, (height-30));
	glEnd();

	for (int i = 0; i < 250; i++) {
		glLineWidth(4.0f);
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f((i * 10), (height - 65));
		glVertex2f(((i * 10) + 5), (height - 65));
		glEnd();
	}


	glLineWidth(4.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0, (height - 30));
	glVertex2f(800, (height - 30));
	glEnd();
	

	for (int i = 0; i < 200; i++) {
		glLineWidth(4.0f);
		glBegin(GL_LINES);
		glColor3f(1.0f, 1.0f, 1.0f);
		glVertex2f((i * 10), (height - 135));
		glVertex2f(((i * 10) + 5), (height - 135));
		glEnd();
	}


	glLineWidth(4.0f);
	glBegin(GL_LINES);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0, (height - 170));
	glVertex2f(800, (height - 170));
	glEnd();

	//carro 1
	glBegin(GL_QUADS);
	glColor3f(1.0f, 0.0f, 0.0f);
	glVertex2f(carro1x, 35);
	glVertex2f(carro1x, 60);
	glVertex2f(carro1x-50, 60);
	glVertex2f(carro1x-50, 35);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.3f, 0.7f);
	glVertex2f(carro1x-10, 38);
	glVertex2f(carro1x-10, 57);
	glVertex2f(carro1x - 25, 57);
	glVertex2f(carro1x - 25, 38);
	glEnd();

	//carro 2
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(carro2x, 70);
	glVertex2f(carro2x, 95);
	glVertex2f(carro2x - 50, 95);
	glVertex2f(carro2x - 50, 70);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.3f, 0.7f);
	glVertex2f(carro2x - 10, 73);
	glVertex2f(carro2x - 10, 92);
	glVertex2f(carro2x - 25, 92);
	glVertex2f(carro2x - 25, 73);
	glEnd();

	//carro 3
	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 1.0f);
	glVertex2f(carro3x, 105);
	glVertex2f(carro3x, 130);
	glVertex2f(carro3x + 50, 130);
	glVertex2f(carro3x + 50, 105);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.3f, 0.7f);
	glVertex2f(carro3x + 25, 108);
	glVertex2f(carro3x + 25, 127);
	glVertex2f(carro3x + 10, 127);
	glVertex2f(carro3x + 10, 108);
	glEnd();

	//carro 4
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(carro4x , 140);
	glVertex2f(carro4x , 165);
	glVertex2f(carro4x + 50, 165);
	glVertex2f(carro4x + 50, 140);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.3f, 0.7f);
	glVertex2f(carro4x + 25, 143);
	glVertex2f(carro4x + 25, 162);
	glVertex2f(carro4x + 10, 162);
	glVertex2f(carro4x + 10, 143);
	glEnd();

	GLfloat circ_pnt = 720;
	GLfloat ang, raioX = 115.0f, raioY = 50.0f;

	//galinha
	glColor3f(1.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(8) + galx, sin(ang)*(8) + galy);
	}
	glEnd();

	glColor3f(1.0, 0.5, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(4) + galx-8, sin(ang)*(4) + galy+8);
	}
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);
	glVertex2f(galx-11.5, galy+9.5);
	glVertex2f(galx-11.5, galy+5.5);
	glVertex2f(galx-15, galy+7.5);
	glEnd();

	glColor3f(0.0, 0.5, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(1) + galx - 9, sin(ang)*(1) + galy + 9);
	}
	glEnd();

	glutSwapBuffers();
}

void drawText(float x, float y, std::string text) {
	glRasterPos2f(x, y);
	glutBitmapString(GLUT_BITMAP_8_BY_13, (const unsigned char*)text.c_str());
}

void keyboard() {
	if (GetAsyncKeyState(VK_UP) && galy+12 < height) galy += vg;
	if (GetAsyncKeyState(VK_DOWN) && galy-12 > 0) galy -= vg;
	if (GetAsyncKeyState(VK_LEFT) && galx-16 > 0) galx -= vg;
	if (GetAsyncKeyState(VK_RIGHT) && galx+12 < width) galx += vg;
}

void updateCarro() {
	carro1x += v1;
	carro2x += v2;
	carro3x -= v3;
	carro4x -= v4;

	if (carro1x > width + 100)
		carro1x = 0;

	if (carro2x > width + 100)
		carro2x = 0;

	if (carro3x < -50)
		carro3x = width;

	if (carro4x < -50)
		carro4x = width;


	//colisão carro 1
	if (galx - 12 < carro1x && galx + 12 > carro1x - 50 && (galy-7) < 60 && (galy+7) > 35) {
		galx = width / 2;
		galy = 10;
	}

	//colisão carro 2
	if (galx - 12 < carro2x && galx + 12 > carro2x - 50 && (galy - 7) < 95 && (galy + 7) > 70) {
		galx = width / 2;
		galy = 10;
	}

	//colisão carro 3
	if (galx - 12 > carro3x && galx + 12 < carro3x + 50 && (galy - 7) < 130 && (galy + 7) > 105) {
		galx = width / 2;
		galy = 10;
	}

	//colisão carro 4
	if (galx - 12 > carro4x && galx + 12 < carro4x + 50 && (galy - 7) < 165 && (galy + 7) > 140) {
		galx = width / 2;
		galy = 10;
	}

	if (galy > height - 12) {
		galx = width / 2;
		galy = 10;
		score++;
	}

}



void update(int value) {
	keyboard();
	updateCarro();
	glutTimerFunc(interval, update, 0);
	glutPostRedisplay();
}

std::string int2str(int x) {
	// converts int to string
	std::stringstream ss;
	ss << x;
	return ss.str();
}

void enable2D(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}
