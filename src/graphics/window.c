#include "lem_in.h"

t_vector3 points[1000]; // Assurez-vous que NUM_POINTS est défini correctement
int size = 0;

void init_points(t_lem_in lem_in) {
    int i;

    // Normalize points
    for (i = 0; i < lem_in.n_rooms; i++) {
        points[i].x = lem_in.rooms[i].pos.x;
        points[i].y = lem_in.rooms[i].pos.y;
        points[i].z = 0.0;
		
    }

    size = lem_in.n_rooms;
}

static void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Calculate the centroid of the points
    float centroid_x = 0.0, centroid_y = 0.0, centroid_z = 0.0;
    for (int i = 0; i < size; i++) {
        centroid_x += points[i].x;
        centroid_y += points[i].y;
        centroid_z += points[i].z;
    }
    centroid_x /= size;
    centroid_y /= size;
    centroid_z /= size;

    // Set the camera position and aim at the centroid
    float camera_x = centroid_x;
    float camera_y = centroid_y;
    float camera_z = centroid_z + 100; // Position the camera 20 units away from the centroid

    gluLookAt(camera_x, camera_y, camera_z,  // position (x, y, z) of the eye
              centroid_x, centroid_y, centroid_z,  // point aimed at
              0.0, 1.0, 0.0);  // up vector

	glPointSize(5.0);
    // Draw the points
    glBegin(GL_POINTS);
    for (int i = 0; i < size; i++) {
        glVertex3f(points[i].x, points[i].y, points[i].z);
    }
    glEnd();

    // Swap buffers
    glutSwapBuffers();
}

void reshape(int largeur, int hauteur) {
    if (hauteur <= 0) hauteur = 1;

    double ratio = largeur / (double)hauteur;

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glViewport(0, 0, largeur, hauteur);

    gluPerspective(45.0, ratio, 1.0, 1000.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void idle(void) {
    glutPostRedisplay();
}

void init_window(int argc, char **argv, t_lem_in lem_in) {
    init_points(lem_in);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lem-in");
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle);
    glutMainLoop();
}