#include <stdio.h>
#include <GL/glut.h>

float square_center[] = {0.0,0.0,0.0}; 

void square(){
    glBegin(GL_POLYGON);
        glVertex3f(square_center[0]-0.25, square_center[1]-0.25, square_center[2]-0.25);
        glVertex3f(square_center[0]+0.25, square_center[1]-0.25, square_center[2]-0.25);
        glVertex3f(square_center[0]+0.25, square_center[1]+0.25, square_center[2]-0.25);
        glVertex3f(square_center[0]-0.25, square_center[1]+0.25, square_center[2]-0.25);
    glEnd();
}

void displayMe(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();
        square();
    glFlush();
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE);
    glutInitWindowSize(300, 300);
    glutCreateWindow("Hello world");
    glutDisplayFunc(displayMe);
    glutMainLoop();
    return 0;
}