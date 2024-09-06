#include "lem_in.h"

int mouse_state = 0;
t_vector2 last_mouse_pos;

void keyboard_listener(unsigned char key, int x, int y) {
    (void)x;
    (void)y;
    if (key == 27)
        exit(0); //#TO-DO: free all mallocs
    if (key == 32)
        lock_camera_on_ant();
}

t_vector3 calc_forward(t_camera camera) {
	t_vector3 forward;	
	forward.x = camera.center.x - camera.eye.x;
	forward.y = camera.center.y - camera.eye.y;
	forward.z = camera.center.z - camera.eye.z;
	float forward_length = sqrt(forward.x * forward.x + forward.y * forward.y + forward.z * forward.z);
	forward.x /= forward_length;
	forward.y /= forward_length;
	forward.z /= forward_length;
	return forward;
}

t_vector3 calc_right(t_camera camera, t_vector3 forward) {
    t_vector3 right = {
        forward.y * camera.up.z - forward.z * camera.up.y,
        forward.z * camera.up.x - forward.x * camera.up.z,
        forward.x * camera.up.y - forward.y * camera.up.x
    };

    float right_length = sqrt(right.x * right.x + right.y * right.y + right.z * right.z);
    right.x /= right_length;
    right.y /= right_length;
    right.z /= right_length;
	return right;
}

void special_keyboard_listener(int key, int x, int y) {
    (void)x;
    (void)y;

    t_camera *camera = get_camera();
    if (camera->locked_on_ant) {
        if (key == GLUT_KEY_LEFT) {
            camera->ant_followed--;
            if (camera->ant_followed < 0)
                camera->ant_followed = get_n_ants() - 1;
        } else if (key == GLUT_KEY_RIGHT) {
            camera->ant_followed++;
            if (camera->ant_followed >= get_n_ants())
                camera->ant_followed = 0;
        }
        return;
    }
        
	t_vector3 forward = calc_forward(*camera);
	t_vector3 right = calc_right(*camera, forward);

    t_vector3 move = {0, 0, 0};

    if (key == GLUT_KEY_UP) {
        move.x = forward.x * 0.5f;
        move.y = forward.y * 0.5f;
        move.z = forward.z * 0.5f;
    } else if (key == GLUT_KEY_DOWN) {
        move.x = -forward.x * 0.5f;
        move.y = -forward.y * 0.5f;
        move.z = -forward.z * 0.5f;
    } else if (key == GLUT_KEY_LEFT) {
        move.x = -right.x * 0.5f;
        move.y = -right.y * 0.5f;
        move.z = -right.z * 0.5f;
    } else if (key == GLUT_KEY_RIGHT) {
        move.x = right.x * 0.5f;
        move.y = right.y * 0.5f;
        move.z = right.z * 0.5f;
    }

    move_camera(move);
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