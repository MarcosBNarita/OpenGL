#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define pi 3.1415926535898
#define janela_altura 400
#define janela_largura 600



void tela(GLsizei w,GLsizei h);
void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(janela_largura, janela_altura);  // tamanho da janela

								   //glutFullScreen();  // full screen

	glutInitWindowPosition(100, 100); // posicao inicial da janela

	glutCreateWindow("mealncia");   /// cria a janela

	glutReshapeFunc(tela); // 

	glutDisplayFunc(display);

	glutMainLoop();

	return (0);
}


void desenhar()
{
	GLfloat circ_pnt = 720;
	GLfloat ang, raioX = 115.0f, raioY = 50.0f;

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = circ_pnt; i > (circ_pnt/2); i--) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*raioX, sin(ang)*raioY);
		printf("%f   %f\n", cos(ang)*raioX, sin(ang)*raioY);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = circ_pnt; i > (circ_pnt / 2); i--) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(raioX-20), sin(ang)*(raioY-10));
		printf("%f   %f\n", cos(ang)*(raioX - 20), sin(ang)*(raioY - 10));
	}
	glEnd();

	glEnable(GL_POINT_SMOOTH);
	glHint(GL_POINT_SMOOTH_HINT, GL_NICEST);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glPointSize(5.0f);

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(60, -10);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(0, -12);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-30, -20);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-60, -13);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(-10, -30);
	glEnd();

	glBegin(GL_POINTS);
	glColor3f(0.0f, 0.0f, 0.0f);
	glVertex2f(15, -25);
	glEnd();
}



void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glClearColor(0.0f, 0.0f, 1.0f, 1.0f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glTranslatef(janela_largura / 2, janela_altura / 2, 0.0f);

	glViewport(0, 0, janela_largura / 2, janela_altura);
	
	desenhar();


	glFlush(); // executa o desenho
}



void tela(GLsizei w, GLsizei h)
{

							 // Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluOrtho2D(0, janela_largura, 0, janela_altura);

	glMatrixMode(GL_MODELVIEW);


}
