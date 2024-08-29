#include "lem_in.h"

t_camera camera;
float rotation_angle = 0.0f;

float *get_rotation_angle() {
	return &rotation_angle;
}

t_camera get_camera() {
	return camera;
}

void setup_camera(t_sphere *points, int size) {
    t_vector3 centroid;
    t_vector3 eye;
    t_vector3 up;

    centroid.x = 0;
    centroid.y = 0;
    centroid.z = 0;

    for (int i = 0; i < size; i++) {
        centroid.x += points[i].pos.x;
        centroid.y += points[i].pos.y;
        centroid.z += points[i].pos.z;
    }
    centroid.x /= size;
    centroid.y /= size;
    centroid.z /= size;

    float radius = 20.0f;
    eye.x = centroid.x + radius * cos(rotation_angle);
    eye.y = centroid.y;
    eye.z = centroid.z + radius * sin(rotation_angle);

    up.x = 0;
    up.y = 1;
    up.z = 0;

    camera.eye = eye;
    camera.center = centroid;
    camera.up = up;
}
