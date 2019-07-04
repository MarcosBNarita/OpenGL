#include <stdlib.h>
#include <GL/glut.h>


void keyboard(unsigned char key, int x, int y);
void resize(GLsizei w, GLsizei h);
void display(void);


int main(int argc, char** argv)
{
	glutInit(&argc, argv);  // controla se o sistema operacional tem suporte a janelas.

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);  // quantidade de buffer de cores e que o padrao de cores é RGB ou RGBA

	glutInitWindowSize(600, 600);  // tamanho da janela

								   //glutFullScreen();  // full screen

	glutInitWindowPosition(10, 300); // posicao inicial da janela

	glutCreateWindow("GLUT Test wagner---- exercicio de glut");   /// cria a janela

	glutKeyboardFunc(&keyboard);

	glutReshapeFunc(&resize); // 

	glutDisplayFunc(display);

	glutMainLoop();

	return EXIT_SUCCESS;
}


void keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
	case '\x1B':
		exit(EXIT_SUCCESS);
		break;
	}
}

void resize(GLsizei w, GLsizei h)
{

	if (h == 0) h = 1;  // Evita a divisao por zero

	glViewport(0, 0, w, h);  // Especifica as dimensões da Viewport

							 // Inicializa o sistema de coordenadas
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Estabelece a janela de seleção (left, right, bottom, top)
	if (w <= h)
	{
		gluOrtho2D(0.0f, 250.0f, 0.0f, 250.0f*h / w);
	}
	else
	{
		gluOrtho2D(0.0f, 250.0f*w / h, 0.0f, 250.0f);
	}
	glMatrixMode(GL_MODELVIEW);


}

void display()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glClearColor(0.0f, 1.0f, 1.0f, 1.0f);  // cor do fundo

	glClear(GL_COLOR_BUFFER_BIT);  // limpa a tela com a cor do fundo

	glBegin(GL_QUADS);
	glColor3f(0.0f, 0.0f, 1.0f);
	glVertex2f(0, 0);
	glVertex2f(200, 0);
	glVertex2f(200, 50);
	glVertex2f(0, 50);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.0f, 1.0f, 0.0f);
	glVertex2f(200, 0);
	glVertex2f(250, 0);
	glVertex2f(250, 50);
	glVertex2f(200, 50);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.42f, 0.23f, 0.16f);
	glVertex2f(150, 0);
	glVertex2f(200, 0);
	glVertex2f(200, 50);
	glVertex2f(150, 50);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.42f, 0.23f, 0.16f);
	glVertex2f(220, 50);
	glVertex2f(230, 50);
	glVertex2f(230, 100);
	glVertex2f(220, 100);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.16f);
	glVertex2f(205, 100);
	glVertex2f(245, 100);
	glVertex2f(225, 200);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.42f, 0.23f, 0.16f);
	glVertex2f(50, 50);
	glVertex2f(100, 50);
	glVertex2f(125, 75);
	glVertex2f(25, 75);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(0.42f, 0.23f, 0.16f);
	glVertex2f(75, 75);
	glVertex2f(80, 75);
	glVertex2f(80, 150);
	glVertex2f(75, 150);
	glEnd();

	glBegin(GL_QUADS);
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(50, 100);
	glVertex2f(110, 100);
	glVertex2f(110, 140);
	glVertex2f(50, 140);
	glEnd();

	
	glFlush(); // executa o desenho
}
