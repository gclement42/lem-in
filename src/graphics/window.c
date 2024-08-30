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

void draw_cylinder(t_vector3 p1, t_vector3 p2, float radius) {
    GLUquadric *quad = gluNewQuadric();
    
    // Calculer le vecteur entre les deux points
    t_vector3 dir = {p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
    
    // Calculer la longueur du vecteur (distance entre les deux sphères)
    float length = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    
    // Calculer l'angle et l'axe de rotation pour orienter le cylindre
    glPushMatrix();
    glTranslatef(p1.x, p1.y, p1.z);

    // Calcul de l'angle de rotation
    float angle = acos(dir.z / length) * 180.0 / M_PI;

    // Déterminer l'axe de rotation
    glRotatef(angle, -dir.y, dir.x, 0.0);
    
    // Dessiner le cylindre
    gluCylinder(quad, radius, radius, length, 20, 20);
    
    glPopMatrix();
    
    gluDeleteQuadric(quad);
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
        // Dessiner les sphères
        glPushMatrix();
        glColor4d(points[i].color.r, points[i].color.g, points[i].color.b, points[i].color.o);
        glTranslatef(points[i].pos.x, points[i].pos.y, points[i].pos.z);
        glutWireSphere(0.75, 20, 20);
        glPopMatrix();
        
        // Si ce n'est pas la première sphère, dessiner un cylindre entre cette sphère et la précédente
        if (i > 0) {
            glColor4d(1.0, 1.0, 1.0, 1.0); // Couleur du cylindre
            draw_cylinder(points[i - 1].pos, points[i].pos, 0.2f); // Rayon du cylindre
        }
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
    glutInitWindowSize(800, 600);
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