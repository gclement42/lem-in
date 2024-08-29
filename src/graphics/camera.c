#include "lem_in.h"

t_camera camera;
float rotation_angle = 0.0f;
float vertical_angle = 0.0f;

float *get_rotation_angle() 
{
	return &rotation_angle;
}

t_camera get_camera() 
{
	return camera;
}

void move_camera(t_vector3 direction) 
{
	camera.eye.x += direction.x;
	camera.eye.y += direction.y;
	camera.eye.z += direction.z;
    camera.center.x += direction.x;
    camera.center.y += direction.y;
    camera.center.z += direction.z;
}

void rotate_camera(int x, int y) 
{
	float radius = 20.0f;
	rotation_angle += x * 0.01f;
    vertical_angle += y * 0.01f;
	if (rotation_angle > 2 * M_PI) {
		rotation_angle -= 2 * M_PI;
	} else if (rotation_angle < 0) {
		rotation_angle += 2 * M_PI;
	}

    if (vertical_angle > 2 * M_PI) {
        vertical_angle -= 2 * M_PI;
    } else if (vertical_angle < 0) {
        vertical_angle += 2 * M_PI;
    }

	camera.eye.x = camera.center.x + radius * cos(rotation_angle);
    camera.eye.y = camera.center.y + radius * sin(vertical_angle);
	camera.eye.z = camera.center.z + radius * sin(rotation_angle);
}

void setup_camera(t_sphere *points, int size) 
{
    t_vector3 centroid;
    t_vector3 eye;
    t_vector3 up;

    centroid.x = 0;
    centroid.y = 0;
    centroid.z = 0;

    for (int i = 0; i < size; i++) 
	{
        centroid.x += points[i].pos.x;
        centroid.y += points[i].pos.y;
        centroid.z += points[i].pos.z;
    }
    centroid.x /= size;
    centroid.y /= size;
    centroid.z /= size;

    float radius = 20.0f;
    eye.x = centroid.x + radius * cos(rotation_angle);
    eye.y = centroid.y + radius * sin(vertical_angle);
    eye.z = centroid.z + radius * sin(rotation_angle);

    up.x = 0;
    up.y = 1;
    up.z = 0;

    camera.eye = eye;
    camera.center = centroid;
    camera.up = up;
}
