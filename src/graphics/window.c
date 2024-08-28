#include "lem_in.h"

t_vector3 points[1000]; // Assurez-vous que NUM_POINTS est défini correctement
int size = 0;

void init_points(t_lem_in lem_in) {
    int i;
    float min_x, max_x, min_y, max_y;

    // Initialize min and max values
    min_x = max_x = lem_in.rooms[0].pos.x;
    min_y = max_y = lem_in.rooms[0].pos.y;

    // Find min and max values
    for (i = 0; i < lem_in.n_rooms; i++) {
        if (lem_in.rooms[i].pos.x < min_x) min_x = lem_in.rooms[i].pos.x;
        if (lem_in.rooms[i].pos.x > max_x) max_x = lem_in.rooms[i].pos.x;
        if (lem_in.rooms[i].pos.y < min_y) min_y = lem_in.rooms[i].pos.y;
        if (lem_in.rooms[i].pos.y > max_y) max_y = lem_in.rooms[i].pos.y;
    }

    // Normalize points
    for (i = 0; i < lem_in.n_rooms; i++) {
        points[i].x = (lem_in.rooms[i].pos.x - min_x) / (max_x - min_x);
        points[i].y = (lem_in.rooms[i].pos.y - min_y) / (max_y - min_y);
        points[i].z = 0.0;
    }

    size = lem_in.n_rooms; // Mettre à jour la taille des points

    // Print normalized points for verification
    for (i = 0; i < lem_in.n_rooms; i++) {
        printf("%f %f %f\n", points[i].x, points[i].y, points[i].z);
    }
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
    float camera_z = centroid_z + 1.50; // Position the camera 20 units away from the centroid

    gluLookAt(camera_x, camera_y, camera_z,  // position (x, y, z) of the eye
              centroid_x, centroid_y, centroid_z,  // point aimed at
              0.0, 1.0, 0.0);  // up vector

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

    gluPerspective(45.0, ratio, 1.0, 100.0);

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