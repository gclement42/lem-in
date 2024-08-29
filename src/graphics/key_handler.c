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

void mouse_motion_listener(int x, int y) {
	if (mouse_state == 1) {
		int dx;
		float *rotation_angle;

		dx = x - last_mouse_pos.x;
		rotation_angle = get_rotation_angle();
		*rotation_angle += dx * 0.01f;
		if (*rotation_angle > 2 * M_PI) {
			*rotation_angle -= 2 * M_PI;
		} else if (*rotation_angle < 0) {
			*rotation_angle += 2 * M_PI;
		}
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