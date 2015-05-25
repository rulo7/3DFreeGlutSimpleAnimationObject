#include <GL/glu.h>
#include <GL/gl.h>
#include <GL/freeglut.h>
//#include <GL/glut.h>

#include <iostream>
#include "PV3D.h"
#include "Camara.hpp"
#include "MunecoDeNieve.h"
#include "Ojos.h"
#include "Esfera.h"
using namespace std;

// Freeglut parameters
// Flag telling us to keep processing events
// bool continue_in_main_loop= true; //(**)

// Viewport size
int WIDTH = 500, HEIGHT = 500;

// Viewing frustum parameters
GLdouble xRight = 10, xLeft = -xRight, yTop = 10, yBot = -yTop, N = 1, F = 1000;

// Camera parameters
GLdouble eyeX = 100.0, eyeY = 100.0, eyeZ = 100.0; // Puntos de la escena que determinan donde esta la camara
GLdouble lookX = 0.0, lookY = 0.0, lookZ = 0.0; // Puntos donde mira la camara
GLdouble upX = 0, upY = 1, upZ = 0; // Vector de vista 
Camara* camara;
MunecoDeNieve* munecoDeNieve;
GLdouble angulo = 0.0;

void initGL() {
    glClearColor(0.2f, 0.2f, 0.2f, 1.0);
    glEnable(GL_LIGHTING); // Activa la luz, es necesario

    // Light0
    glEnable(GL_LIGHT0); // Activamos UNA luz (se pueden definir más)
    GLfloat d[] = {1.0, 1.0, 1.0, 1.0};
    glLightfv(GL_LIGHT0, GL_DIFFUSE, d); // Dispersión de la luz
    GLfloat a[] = {0.3f, 0.3f, 0.3f, 1.0};
    glLightfv(GL_LIGHT0, GL_AMBIENT, a); // Llevar luz a los objetos q no reciben luz directa de LIGHT0
    GLfloat p[] = {25.0, 25.0, 0.0, 1.0};
    glLightfv(GL_LIGHT0, GL_POSITION, p); // Posición de la luz

    glDisable(GL_LIGHT0);

    // Light 1
    glEnable(GL_LIGHT1);
    glEnable(GL_LIGHT2);


    glEnable(GL_COLOR_MATERIAL);
    glMaterialf(GL_FRONT, GL_SHININESS, 0.1f);
    glEnable(GL_DEPTH_TEST);
    glEnable(GL_NORMALIZE);
    glShadeModel(GL_SMOOTH); // La forma de rellenar caras con colores (GL_FLAT sombreado plano)

    // buildSceneObjects(); construir objetos


    camara = new Camara(new PV3D(eyeX, eyeY, eyeZ), new PV3D(lookX, lookY, lookZ), new PV3D(upX, upY, upZ));
    munecoDeNieve = new MunecoDeNieve(3.0, 2.0);

    // Camera set up
    //  glMatrixMode(GL_MODELVIEW);
    //  glLoadIdentity();
    //gluLookAt(eyeX, eyeY, eyeZ, lookX, lookY, lookZ, upX, upY, upZ);

    // Frustum set up
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xLeft, xRight, yBot, yTop, N, F);

    // Viewport set up
    glViewport(0, 0, WIDTH, HEIGHT);
}

void display(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // Drawing axes
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0, 0, 0);
    glVertex3f(20, 0, 0);

    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 20, 0);

    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0, 0, 0);
    glVertex3f(0, 0, 20);
    glEnd();



    glPushMatrix();
    glRotated(angulo, 0.0, 1.0, 0.0);
    munecoDeNieve->dibuja();
    glPopMatrix();

    
    glColor3f(1.0,0.0,1.0);
    glPushMatrix();
    glTranslated(0.0,0.0,2.0);
    munecoDeNieve->dibuja();    
    glPopMatrix();
    
    
    glFlush();
    glutSwapBuffers();
}

void resize(int newWidth, int newHeight) {
    WIDTH = newWidth;
    HEIGHT = newHeight;
    GLdouble RatioViewPort = (float) WIDTH / (float) HEIGHT;
    glViewport(0, 0, WIDTH, HEIGHT);

    GLdouble SVAWidth = xRight - xLeft;
    GLdouble SVAHeight = yTop - yBot;
    GLdouble SVARatio = SVAWidth / SVAHeight;
    if (SVARatio >= RatioViewPort) {
        GLdouble newHeight = SVAWidth / RatioViewPort;
        GLdouble yMiddle = (yBot + yTop) / 2.0;
        yTop = yMiddle + newHeight / 2.0;
        yBot = yMiddle - newHeight / 2.0;
    } else {
        GLdouble newWidth = SVAHeight*RatioViewPort;
        GLdouble xMiddle = (xLeft + xRight) / 2.0;
        xRight = xMiddle + newWidth / 2.0;
        xLeft = xMiddle - newWidth / 2.0;
    }

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(xLeft, xRight, yBot, yTop, N, F);
}

void key(unsigned char key, int x, int y) {
    bool need_redisplay = true;
    switch (key) {
        case 27: /* Escape key */
            //continue_in_main_loop = false; // (**)
            //Freeglut's sentence for stopping glut's main loop (*)
            glutLeaveMainLoop();
            break;
        case 'r':
            camara->recorridoEje(-0.1, 0.0, 0.0);
            break;
        case 't':
            camara->recorridoEje(0.1, 0.0, 0.0);
            break;
        case 'f':
            camara->recorridoEje(0.0, -0.1, 0.0);
            break;
        case 'g':
            camara->recorridoEje(0.0, 0.1, 0.0);
            break;
        case 'v':
            camara->recorridoEje(0.0, 0.0, -0.1);
            break;
        case 'b':
            camara->recorridoEje(0.0, 0.0, 0.1);
            break;
        case 'p':
            angulo += 1.0;
            break;
        case 'o':
            angulo -= 1.0;
            break;
        case 'z':
            glEnable(GL_LIGHT1);
            glEnable(GL_LIGHT2);
            break;
            break;
        case 'x':
            glDisable(GL_LIGHT1);
            glDisable(GL_LIGHT2);
            break;


        default:
            need_redisplay = false;
            break;
    }

    if (need_redisplay)
        glutPostRedisplay();
}

int main(int argc, char *argv[]) {
    cout << "Starting console..." << endl;

    int my_window; // my window's identifier

    // Initialization
    glutInitWindowSize(WIDTH, HEIGHT);
    glutInitWindowPosition(140, 140);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutInit(&argc, argv);

    // Window construction
    my_window = glutCreateWindow("Freeglut 3D-project");

    // Callback registration
    glutReshapeFunc(resize);
    glutKeyboardFunc(key);
    glutDisplayFunc(display);

    // OpenGL basic setting
    initGL();

    // Freeglut's main loop can be stopped executing (**)
    // while (continue_in_main_loop) glutMainLoopEvent();

    // Classic glut's main loop can be stopped after X-closing the window,
    // using the following freeglut's setting (*)
    glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

    // Classic glut's main loop can be stopped in freeglut using (*)
    glutMainLoop();

    // We would never reach this point using classic glut
    system("PAUSE");

    return 0;
}