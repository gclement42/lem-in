#include "lem_in.h"

t_vector3 points[NUM_POINTS];
int size = 0;

void init_points(t_lem_in lem_in) {
int i;
    float min_x, max_x, min_y, max_y;

    // Initialize min and max values
    min_x = max_x = lem_in.rooms[0].pos.x;
    min_y = max_y = lem_in.rooms[0].pos.y;

    // Find min and max values
    for (i = 1; i < lem_in.n_rooms; i++) {
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

    // Print normalized points for verification
    for (i = 0; i < lem_in.n_rooms; i++) {
        printf("%f %f %f\n", points[i].x, points[i].y, points[i].z);
    }
}

static void draw(void) {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	// part du système de coordonnées de base (matrice identité)
	glLoadIdentity();

	int num_points = sizeof(points) / sizeof(points[0]);

	float centroid_x = 0.0, centroid_y = 0.0, centroid_z = 0.0;
	for (int i = 0; i < num_points; i++) {
		centroid_x += points[i].x;
		centroid_y += points[i].y;
		centroid_z += points[i].z;
	}
	centroid_x /= num_points;
	centroid_y /= num_points;
	centroid_z /= num_points;
	// fixe le point de vue 
    float camera_x = centroid_x;
	float camera_y = centroid_y;
	float camera_z = centroid_z + 20.0; // Position the camera 20 units away from the centroid

	gluLookAt(camera_x, camera_y, camera_z,  // position (x, y, z) of the eye
			centroid_x, centroid_y, centroid_z,  // point aimed at
			0.0, 1.0, 0.0);

	glPointSize(5.0);

	// dessine les points
	glBegin(GL_POINTS);
	for (int i = 0; i < size; i++) {
		glVertex3f(points[i].x, points[i].y, points[i].z);
	}
	glEnd();
	// ~ affiche
	glutSwapBuffers();
}

void reshape(int largeur, int hauteur) {

	// Evite une division par zéro
	if (hauteur <= 0) hauteur = 1;

	double ratio = largeur;
	ratio /= hauteur; // ratio est un double : évite la division entière

	// Reset the coordinate system before modifying
	if (ratio >= 1.0) {
        glOrtho(0.0, 1.0 * ratio, 0.0, 1.0, -1.0, 1.0);
    } else {
        glOrtho(0.0, 1.0, 0.0, 1.0 / ratio, -1.0, 1.0);
    }
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	// Set the new viewport size
	glViewport(0, 0, largeur, hauteur);

	// Set the correct perspective.
	gluPerspective(45.0, ratio, 1.0, 100.0);

	// Choose the projection matrix to be the matrix 
	// manipulated by the following calls
	glMatrixMode(GL_MODELVIEW);
	// Set the projection matrix to be the identity matrix
	glLoadIdentity();
    gluLookAt(0.5, 0.5, 2.0,  // position (x, y, z) of the eye
              0.5, 0.5, 0.0,  // point aimed at
              0.0, 1.0, 0.0);
}

void idle(void) {
	glutPostRedisplay();
	glutIdleFunc(0);
}

void init_window(int argc, char **argv, t_lem_in lem_in)
{
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