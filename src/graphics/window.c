#include "lem_in.h"
#include <math.h>

t_sphere points[1000];
int size = 0;

void init_points(t_lem_in lem_in) {
    int i;

    for (i = 0; i < lem_in.n_rooms; i++) {
        points[i].pos.x = lem_in.rooms[i].pos.x;
        points[i].pos.y = lem_in.rooms[i].pos.y;
        points[i].pos.z = lem_in.rooms[i].pos.z;
        if (i == lem_in.start)
            points[i].color = (t_color){1.0, 0.0, 0.0, 1.0};
        else if (i == lem_in.end)
            points[i].color = (t_color){0.0, 1.0, 0.0, 1.0};
        else
            points[i].color = (t_color){1.0, 1.0, 1.0, 1.0};
    }
    size = lem_in.n_rooms;
}


static void draw(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();


    t_camera camera = get_camera();
    gluLookAt(
        camera.eye.x, camera.eye.y, camera.eye.z,
        camera.center.x, camera.center.y, camera.center.z,
        camera.up.x, camera.up.y, camera.up.z);

    for (int i = 0; i < size; i++) {
        glPushMatrix();
        glColor4d(points[i].color.r, points[i].color.g, points[i].color.b, points[i].color.o);
        glTranslatef(points[i].pos.x, points[i].pos.y, points[i].pos.z);
        glutWireSphere(0.75, 20, 20);
        glPopMatrix();
    }

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
    setup_camera(points, size);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(1920, 1080);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Lem-in");
    glutKeyboardFunc(keyboard_listener);
    glutSpecialFunc(special_keyboard_listener);
    glutMouseFunc(mouse_listener);
    glutMotionFunc(mouse_motion_listener);
    glutDisplayFunc(draw);
    glutReshapeFunc(reshape);
    glutIdleFunc(idle); // Enregistrer la fonction idle
    glutMainLoop();
}