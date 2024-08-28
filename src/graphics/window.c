#include "lem_in.h"

static void display_me(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POLYGON);
	glVertex2f(0.0, 0.0);
	glVertex2f(0.5, 0.0);
	glVertex2f(0.5, 0.5);
	glVertex2f(0.0, 0.5);
	glEnd();
	glFlush();
}

void init_window(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Lem-in");
	glutDisplayFunc(display_me);
	glutMainLoop();
}