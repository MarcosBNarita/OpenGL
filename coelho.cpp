#include <stdlib.h>
#include <GL/glut.h>
#include <stdio.h>
#include <math.h>

#define pi 3.1415926535898
#define janela_altura 800
#define janela_largura 1200



void tela(GLsizei w, GLsizei h);
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

	//orelha esquerda
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(15) + 25, sin(ang)*(40) + 90);
	}
	glEnd();

	//orelha direita
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(15) + 65, sin(ang)*(40) + 90);
	}
	glEnd();


	//interior orelha esquerda
	glColor3f(0.91, 0.53, 0.60);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(8) + 25, sin(ang)*(30) + 90);
	}
	glEnd();

	//interior orelha direita
	glColor3f(0.91, 0.53, 0.60);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(8) + 65, sin(ang)*(30) + 90);
	}
	glEnd();

	//pé esquerdo
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(25)+5, sin(ang)*(8)+2);
	}
	glEnd();

	//pé direito
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(25) + 85, sin(ang)*(8)+2);
	}
	glEnd();

	//corpo
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(45) + 45, sin(ang)*(30) + 30);
	}
	glEnd();

	//barriga
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(30) + 45, sin(ang)*(20) + 30);
	}
	glEnd();

	//cabeça
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(45) + 45, sin(ang)*(22) + 75);
	}
	glEnd();

	//boca
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(15) + 45, sin(ang)*(7) + 70);
	}
	glEnd();

	//nariz
	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(7) + 45, sin(ang)*(3) + 72);
	}
	glEnd();

	//olho direito
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(7) + 65, sin(ang)*(5.5) + 83);
	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(4) + 65, sin(ang)*(3) + 83);
	}
	glEnd();

	//olho esquerdo
	glColor3f(1.0, 1.0, 1.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(7) + 25, sin(ang)*(5.5) + 83);
	}
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(4) + 25, sin(ang)*(3) + 83);
	}
	glEnd();

	//mão direita
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(12) + 65, sin(ang)*(8) + 40);
	}
	glEnd();

	//mão esquerda
	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(12) + 25, sin(ang)*(8) + 40);
	}
	glEnd();


	//ovo direito
	int cont = 1;
	glBegin(GL_POLYGON);
	for (int i = 0; i < circ_pnt; i++) {
		if (cont < 3) {
			glColor3f(1.0, 0.43, 0.15);
			cont++;
		}
		else if (cont < 9){
			glColor3f(0.42, 0.89, 0.26);
			cont++;
		}
		else if (cont == 9){
			cont = 1;
		}
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(60) + 240, sin(ang)*(45) + 45);
	}
	glEnd();

	//ovo esquerdo
	cont = 1;
	glBegin(GL_POLYGON);
	for (int i = circ_pnt; i > 0; i--) {
		if (cont < 3) {
			glColor3f(0.42, 0.89, 0.26);
			cont++;
		}
		else if (cont < 9) {
			glColor3f(1.0, 0.43, 0.15);
			cont++;
		}
		else if (cont == 9) {
			cont = 1;
		}
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(60) - 150, sin(ang)*(45) + 45);
	}
	glEnd();

	//laço ovo esquerdo
	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-225, 110);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-150, 90);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-225, 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-75, 110);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(-150, 90);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(-75, 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = circ_pnt/4; i < circ_pnt*3/4; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + -225, sin(ang)*(12) + 97.5);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = circ_pnt / 4; i < circ_pnt * 3 / 4; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + -225, sin(ang)*(12) + 82.5);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = circ_pnt*0.25; i > 0 - circ_pnt*0.25; i--) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + -76, sin(ang)*(12) + 97.5);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(0.0, 1.0, 0.0);
	for (int i = circ_pnt*0.25; i > 0 - circ_pnt*0.25; i--) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + -76, sin(ang)*(12) + 82.5);
	}
	glEnd();


	//laço ovo direito
	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(165, 110);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(240, 90);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(165, 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(315, 110);
	glColor3f(0.0, 1.0, 0.0);
	glVertex2f(240, 90);
	glColor3f(1.0, 0.0, 0.0);
	glVertex2f(315, 70);
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = circ_pnt / 4; i < circ_pnt * 3 / 4; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + 165, sin(ang)*(12) + 97.5);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = circ_pnt / 4; i < circ_pnt * 3 / 4; i++) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + 165, sin(ang)*(12) + 82.5);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = circ_pnt*0.25; i > 0 - circ_pnt*0.25; i--) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + 314, sin(ang)*(12) + 97.5);
	}
	glEnd();

	glBegin(GL_POLYGON);
	glColor3f(1.0, 0.0, 0.0);
	for (int i = circ_pnt*0.25; i > 0 - circ_pnt*0.25; i--) {
		ang = (2 * pi*i) / circ_pnt;
		glVertex2f(cos(ang)*(16) + 314, sin(ang)*(12) + 82.5);
	}
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