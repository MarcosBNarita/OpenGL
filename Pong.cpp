#include <string>
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <sstream> 
#include <math.h> 
#include <gl\gl.h>
#include <gl\glu.h>
#include "GL/freeglut.h"
#define VK_W 0x57
#define VK_S 0x53

void draw(void);
void enable2D(int, int);
void update(int);
void updateBola(void);
int score1 = 0;
int score2 = 0;
int width = 500;
int height = 200;
int interval = 1000 / 60;
//barras
int velocidade = 3;
float barraey1 = 75;
float barraey2 = 125;
float barrady1 = 75;
float barrady2 = 125;
// bola
float bolax = width / 2;
float bolay = height / 2;
float bdirx = 0.8f;
float bdiry = 0.0f;
int tambola = 8;
int velbola = 3;

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

	//Barras
	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(10, barraey2);
	glVertex2f(20, barraey2);
	glVertex2f(20, barraey1);
	glVertex2f(10, barraey1);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(480, barrady2);
	glVertex2f(490, barrady2);
	glVertex2f(490, barrady1);
	glVertex2f(480, barrady1);
	glEnd();

	GLfloat ang;
	GLfloat circ_pnt = 160;
	glColor3f(1.0, 1.0, 1.0);
	glLineWidth(3.0f);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * 3.1415*i) / circ_pnt;
		glVertex2f(cos(ang)*(6) + bolax, sin(ang)*(6) + bolay);
	}
	glEnd();

	glutSwapBuffers();
}

void keyboard() {
	// barra esquerda
	if (GetAsyncKeyState(VK_W) && barraey2 < height) barraey1 += velocidade;
	if (GetAsyncKeyState(VK_W) && barraey2 < height) barraey2 += velocidade;
	if (GetAsyncKeyState(VK_S) && barraey1 > 0) barraey1 -= velocidade;
	if (GetAsyncKeyState(VK_S) && barraey1 > 0) barraey2 -= velocidade;

	// barra direita
	if (GetAsyncKeyState(VK_UP) && barrady2 < height) barrady1 += velocidade;
	if (GetAsyncKeyState(VK_UP) && barrady2 < height) barrady2 += velocidade;
	if (GetAsyncKeyState(VK_DOWN) && barrady1 > 0) barrady1 -= velocidade;
	if (GetAsyncKeyState(VK_DOWN) && barrady1 > 0) barrady2 -= velocidade;
}


void updateBola() {
	bolax += bdirx * velbola;
	bolay += bdiry * velbola;

	// colisão raquete esquerda
	if (bolax < 25 &&
		bolax > 5 &&
		bolay < barraey2+5 &&
		bolay > barraey1-5) {
		float t = ((bolay - (barraey1 + 25)) / 50);
		bdirx = fabs(bdirx);
		bdiry = t;
	}

	// colisão raquete direita
	if (bolax > 475 &&
		bolax < 495 &&
		bolay < barrady2 + 5 &&
		bolay > barrady1 - 5) {
		float t = ((bolay - (barrady1 + 25)) / 50);
		bdirx = -fabs(bdirx);
		bdiry = t;
	}

	// colisão parede esquerda
	if (bolax < 0) {
		++score2;
		bolax = width / 2;
		bolay = height / 2;
		bdirx = fabs(0.8);
		bdiry = 0;
	}

	// colisão parede direita
	if (bolax > width) {
		++score1;
		bolax = width / 2;
		bolay = height / 2;
		bdirx = -fabs(0.8);
		bdiry = 0;
	}

	// colisão teto
	if (bolay > height-6) {
		bdiry = -fabs(bdiry); // force it to be negative
	}

	// colisão chão
	if (bolay < 6) {
		bdiry = fabs(bdiry); // force it to be positive
	}

}

void update(int value) {
	keyboard();
	updateBola();
	glutTimerFunc(interval, update, 0);
	glutPostRedisplay();
}

void enable2D(int width, int height) {
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0f, width, 0.0f, height, 0.0f, 1.0f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

