#include <GL/glut.h>
#include <stdio.h>
float angle = 0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle+=0.01,0,0,1);
        glTranslatef(0.8,0,0);
        glScalef(0.3, 0.3, 0.3);
        glutSolidTeapot(0.5);
    glPopMatrix();
    glutSwapBuffers();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week04 rotate translate scale");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
