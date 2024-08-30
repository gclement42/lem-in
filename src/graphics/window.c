#include "lem_in.h"
#include <math.h>

t_sphere points[1000];
int size = 0;

t_vector3 *get_links(t_lem_in lem_in, t_array *links) {
    t_vector3 *res = malloc(sizeof(t_vector3) * links->size);
    size_t i = 0;
    while (i < links->size) {
        t_room *room = get_room(&lem_in, links->arr[i]);
        res[i] = (t_vector3){room->pos.x, room->pos.y, room->pos.z};
        i++;
    }
    return res;
}

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
        points[i].links = get_links(lem_in, &lem_in.rooms[i].links);
        points[i].links_size = lem_in.rooms[i].links.size;
    }
    size = lem_in.n_rooms;
}

void draw_cylinder(t_vector3 p1, t_vector3 p2, float radius) {
    GLUquadric *quad = gluNewQuadric();
    
    t_vector3 dir = {p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
    
    float length = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    
    glPushMatrix();
    glColor4d(1.0, 1.0, 1.0, 1.0);
    glTranslatef(p1.x, p1.y, p1.z);

    float angle = acos(dir.z / length) * 180.0 / M_PI;

    glRotatef(angle, -dir.y, dir.x, 0.0);
    
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
        glPushMatrix();
        glColor4d(points[i].color.r, points[i].color.g, points[i].color.b, points[i].color.o);
        glTranslatef(points[i].pos.x, points[i].pos.y, points[i].pos.z);
        glutWireSphere(0.75, 20, 20);
        glPopMatrix();

        for (size_t j = 0; j < points[i].links_size; j++) {
            draw_cylinder(points[i].pos, points[i].links[j], 0.1);
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