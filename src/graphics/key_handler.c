#include "lem_in.h"

void keyboard_listener(unsigned char key, int x, int y) {
    (void)x;
    (void)y;
    if (key == 27) {
        exit(0);
    }
}

void special_keyboard_listener(int key, int x, int y) {
    (void)x;
    (void)y;
	float *rotation_angle;

	rotation_angle = get_rotation_angle();
    if (key == GLUT_KEY_LEFT) 
    {
        *rotation_angle = *rotation_angle - 0.1f;
        if (*rotation_angle < 0) {
            *rotation_angle = *rotation_angle + (2 * M_PI);
        }
    } 
    else if (key == GLUT_KEY_RIGHT) 
    {
        *rotation_angle = *rotation_angle + 0.1f;
        if (*rotation_angle < 0) {
            *rotation_angle += *rotation_angle + (2 * M_PI);
        }
    }
    glutPostRedisplay();
}