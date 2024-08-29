#include "lem_in.h"

int mouse_state = 0;
t_vector2 last_mouse_pos;

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
	if (key == GLUT_KEY_UP)
		move_camera((t_vector3){-0.5f, 0, 0});
	else if (key == GLUT_KEY_DOWN)
		move_camera((t_vector3){0.5f, 0, 0});
	else if (key == GLUT_KEY_LEFT)
		move_camera((t_vector3){0, 0, -0.5f});
	else if (key == GLUT_KEY_RIGHT)
		move_camera((t_vector3){0, 0, 0.5f});
    glutPostRedisplay();
}

void mouse_motion_listener(int x, int y) {
	if (mouse_state == 1) {
		rotate_camera(x - last_mouse_pos.x, y - last_mouse_pos.y);
		glutPostRedisplay();
	}
	last_mouse_pos = (t_vector2){x, y};

}

void mouse_listener(int button, int state, int x, int y) {
	(void)x;
	(void)y;
	if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
		last_mouse_pos = (t_vector2){x, y};
		mouse_state = 1;
	}
	else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP)
		mouse_state = 0;
}