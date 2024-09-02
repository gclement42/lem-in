#include "lem_in.h"
#include <math.h>

t_sphere rooms[1000];
t_sphere ants[1000];
t_lem_in *g_lem_in;
int size = 0;
int ants_size = 0;

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

void init_rooms(t_lem_in lem_in) {
    int i;

    for (i = 0; i < lem_in.n_rooms; i++) {
        rooms[i].pos.x = lem_in.rooms[i].pos.x;
        rooms[i].pos.y = lem_in.rooms[i].pos.y;
        rooms[i].pos.z = lem_in.rooms[i].pos.z;
        if (i == lem_in.end)
            rooms[i].color = (t_color){1.0, 0.0, 0.0, 1.0};
        else if (i == lem_in.start)
            rooms[i].color = (t_color){0.0, 1.0, 0.0, 1.0};
        else
            rooms[i].color = (t_color){1.0, 1.0, 1.0, 1.0};
        rooms[i].links = get_links(lem_in, &lem_in.rooms[i].links);
        rooms[i].links_size = lem_in.rooms[i].links.size;
    }
    size = lem_in.n_rooms;
}

void init_ants_sphere(t_lem_in lem_in) {
    int i;

    for (i = 0; i < lem_in.n_ants; i++) {
        ants[i].pos.x = lem_in.rooms[lem_in.start].pos.x;
        ants[i].pos.y = lem_in.rooms[lem_in.start].pos.y;
        ants[i].pos.z = lem_in.rooms[lem_in.start].pos.z;
        ants[i].color = (t_color){1.0, 1.0, 0.0, 1.0};
    }
    ants_size = lem_in.n_ants;
}

bool check_if_all_ants_in_end(t_lem_in *lem_in) {
    for (int i = 0; i < lem_in->n_ants; i++) {
        if (lem_in->ants[i].room->id != lem_in->end)
            return false;
    }
    return true;
}

void update(int value) 
{
    float speed = 0.1f;
    int count = 0;
    for (int i = 0; i < ants_size; i++)
    {
        t_room room = *g_lem_in->ants[i].room;
        t_vector3 dir = {room.pos.x - ants[i].pos.x, room.pos.y - ants[i].pos.y, room.pos.z - ants[i].pos.z};
        float length = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
        if (length > 0.1f)
        {
            ants[i].pos.x += dir.x / length * speed;
            ants[i].pos.y += dir.y / length * speed;
            ants[i].pos.z += dir.z / length * speed;
        }
        else {
            ants[i].pos = room.pos;
            count++;
        }
    }
    if (count == ants_size) {
        if (check_if_all_ants_in_end(g_lem_in)) {
            printf("All ants are in end\n");
            return;
        }
        move_ants_manager(g_lem_in);
    }
    glutTimerFunc(value, update, value);
}

void draw_cylinder(t_vector3 p1, t_vector3 p2, float radius) {
    float angle;
    float length;
    GLUquadric *quad = gluNewQuadric();
    t_vector3 dir = {p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
    
    length = sqrt(dir.x * dir.x + dir.y * dir.y + dir.z * dir.z);
    
    glPushMatrix();
    glColor4d(1.0, 1.0, 1.0, 1.0);
    glTranslatef(p1.x, p1.y, p1.z);

    angle = acos(dir.z / length) * 180.0 / M_PI;

    glRotatef(angle, -dir.y, dir.x, 0.0);
    gluCylinder(quad, radius, radius, length, 20, 20);
    glPopMatrix();
    gluDeleteQuadric(quad);
}

void draw_sphere(t_vector3 pos, float radius, t_color color) {
    GLUquadric *quad = gluNewQuadric();
    glPushMatrix();
    glColor4d(color.r, color.g, color.b, color.o);
    glTranslatef(pos.x, pos.y, pos.z);
    gluSphere(gluNewQuadric(), radius, 20, 20);
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
        glColor4d(rooms[i].color.r, rooms[i].color.g, rooms[i].color.b, rooms[i].color.o);
        glTranslatef(rooms[i].pos.x, rooms[i].pos.y, rooms[i].pos.z);
        glutWireSphere(0.75, 20, 20);
        glPopMatrix();

        for (size_t j = 0; j < rooms[i].links_size; j++) {
            draw_cylinder(rooms[i].pos, rooms[i].links[j], 0.1);
        }
    }

    // printf("Ants size: %d\n", ants_size);
    for (int i = 0; i < ants_size; i++) {
        // printf("Ant %d is in room %s\n", g_lem_in->ants[i].id, g_lem_in->ants[i].room->name);
        draw_sphere(ants[i].pos, 0.40, ants[i].color);
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
    size_t timer =  1;
    g_lem_in = &lem_in;
    init_rooms(lem_in);
    init_ants_sphere(lem_in);
    setup_camera(rooms, size);
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
    glutIdleFunc(idle);
    move_ants_manager(g_lem_in);
    glutTimerFunc(timer, update, timer);
    glutMainLoop();
}