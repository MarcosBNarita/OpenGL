#include<GL/glew.h>
#include<GL/glut.h>
#include<stdio.h>
#include<stdlib.h>

#define windowH 900
#define windowW 1600

void reshape(GLsizei w, GLsizei h);
void display();

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE);
	glutInitWindowSize(windowW, windowH);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("First 3D test");
	glutDisplayFunc(display);
	glutReshapeFunc(reshape);
	glutMainLoop();
	return 0;
}

void reshape(GLsizei w, GLsizei h) {
	if (h == 0) h = 1;
	GLfloat aspect = (GLfloat)w / (GLfloat)h;

	glViewport(0, 0, w, h);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(65.0f, aspect, 0.1f, 100.0f);

	glClearColor(0, 0, 0, 1);
	glEnable(GL_DEPTH_TEST);
	glShadeModel(GL_SMOOTH);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);
}

void display() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(-1.5f, 0.0f, -6.0f);

	glBegin(GL_TRIANGLES);
	//front
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, 1);
	//right
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(1, -1, 1);
	glColor3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	//back
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 1, 0);
	glVertex3f(1, -1, -1);
	glColor3f(0, 0, 1);
	glVertex3f(-1, -1, -1);
	//left
	glColor3f(1, 0, 0);
	glVertex3f(0, 1, 0);
	glColor3f(0, 0, 1);
	glVertex3f(-1, -1, -1);
	glColor3f(0, 1, 0);
	glVertex3f(-1, -1, 1);
	glEnd();



	glBegin(GL_QUADS);


	//left
	glColor3f(0, 0, 1);
	glVertex3f(2, 2, 0);
	glColor3f(0, 1, 0);
	glVertex3f(2, 3, 0);
	glColor3f(1, 0, 0);
	glVertex3f(2, 3, -1);
	glColor3f(0, 1, 1);
	glVertex3f(2, 2, -1);
	

	//upper
	glColor3f(1, 1, 0);
	glVertex3f(2, 3, 0);
	glColor3f(1, 0, 0);
	glVertex3f(3, 3, 0);
	glColor3f(0, 0, 1);
	glVertex3f(3, 3, -1);
	glColor3f(0, 1, 0);
	glVertex3f(2, 3, -1);

	//right
	glColor3f(0, 1, 0);
	glVertex3f(3, 2, 0);
	glColor3f(1, 0, 1);
	glVertex3f(3, 3, 0);
	glColor3f(0, 0, 1);
	glVertex3f(3, 3, -1);
	glColor3f(1, 0, 0);
	glVertex3f(3, 2, -1);

	//back
	glColor3f(1, 0, 0);
	glVertex3f(2, 3, -1);
	glColor3f(1, 1, 0);
	glVertex3f(3, 3, -1);
	glColor3f(1, 0, 1);
	glVertex3f(3, 2, -1);
	glColor3f(0, 0, 1);
	glVertex3f(2, 2, -1);

	//bottom
	glColor3f(0, 1, 1);
	glVertex3f(2, 2, 0);
	glColor3f(0, 0, 1);
	glVertex3f(3, 2, 0);
	glColor3f(1, 1, 0);
	glVertex3f(3, 2, -1);
	glColor3f(1, 0, 0);
	glVertex3f(2, 2, -1);

	//front
	glColor3f(1, 0, 0);
	glVertex3f(2, 3, 0);
	glColor3f(1, 1, 0);
	glVertex3f(3, 3, 0);
	glColor3f(1, 0, 1);
	glVertex3f(3, 2, 0);
	glColor3f(0, 0, 1);
	glVertex3f(2, 2, 0);

	glEnd();

	glutSwapBuffers();
}