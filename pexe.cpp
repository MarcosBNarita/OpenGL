#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define pi 3.1415926535898
#define janela_altura 400
#define janela_largura 600
float tx = 0.0, ty = 0.0, xStep = 4, yStep = 4;
float pexer = 1.0, pexeg = 0.3, pexeb = 0.2;
float flagpexe = 0.0;
float corpexe = 0.0;

void display(void);
void tela(GLsizei w, GLsizei h);
void keyboard(unsigned char key, int x, int y);
void anima(int valor);

int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela

														//glutFullScreen();  // full screen

	glutInitWindowPosition(100, 100); // posicao inicial da janela

	glutCreateWindow("colisão");   /// cria a janela

	glutKeyboardFunc(&keyboard);

	glutReshapeFunc(tela); // 

	glutDisplayFunc(display);

	glutTimerFunc(150, anima, 1);

	glutMainLoop();

	return (0);
}

void keyboard(unsigned char key, int x, int y)
{

	if (key == '1') {
		if (corpexe==0.0) {
			pexer = 0.0;
			pexeg = 0.50;
			pexeb = 0.50;
			corpexe = 1.0;
		}else if (corpexe==1.0) {
			pexer = 1.0;
			pexeg = 0.3;
			pexeb = 0.2;
			corpexe = 0.0;
		}

		

	}

	glutPostRedisplay();

}

void anima(int valor) {
	if ((tx) > (60) || (tx) < (-60)) {
		xStep = -xStep;
	}

	if (tx > 60) {
		flagpexe = 1.0;
	}

	if (tx < -60) {
		flagpexe = 0.0;
	}

	if ((ty) > (40) || (ty) < (-40)) {
		yStep = -yStep;
	}
	tx += xStep;
	ty += yStep;

	glutPostRedisplay();
	glutTimerFunc(150, anima, 1);
}


void desenhar()
{
	GLfloat circ_pnt = 100;
	GLfloat ang, raioX = 50.0f, raioY = 50.0f;


	glColor3f(0.1, 0.3, 0.9);
	glLineWidth(3.0f);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(100) + 0, sin(ang)*(100) + 0);
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-150, 75);
	glVertex2f(150, 75);
	glVertex2f(150, 150);
	glVertex2f(-150, 150);
	glEnd();


	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(100) + 0, sin(ang)*(100) + 0);
	}
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-158, 85);
	glVertex2f(150, 85);
	glVertex2f(150, 150);
	glVertex2f(-150, 150);
	glEnd();
	

	glTranslated(tx, ty, 0.0f);

	if (flagpexe == 1.0) {
		glRotated(0, 0, 0, 1);
	}
	else {
		glRotated(180, 0, 1, 0);
	}


	// Peixe
	glColor3f(pexer, pexeg, pexeb);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(20) + 0, sin(ang)*(15) + 0);
	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(2) - 6, sin(ang)*(2) + 5);
	}
	glEnd();

	glColor3f(pexer, pexeg, pexeb);
	glBegin(GL_POLYGON);
	glVertex2f(10, 0);
	glVertex2f(25, 15);
	glVertex2f(25, -15);
	glEnd();



}
void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);

	glViewport(0, 0, janela_largura, janela_altura);

	desenhar();


	glFlush(); // executa o desenho
}



void tela(GLsizei w, GLsizei h)
{

	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	// Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);


}