#include <GL/glut.h>   //�ϥ�GLUT�禡�w

void display(){

    glBegin(GL_POLYGON); //�}�l�e
        glColor3f(1,0,0); glVertex2f(0,1);
        glColor3f(0,1,0); glVertex2f(1,-0.6);
        glColor3f(0,0,1); glVertex2f(-1,-0.6);
    glEnd(); //�����e

    glutSwapBuffers();
}

int main(int argc, char *argv[]){ //main()�禡
    glutInit(&argc, argv); //�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("�q���Ͼǲ�01�P"); //�}�@��GLUT����
    glutDisplayFunc(display); //display()�禡�e��
    glutMainLoop(); //�D�n���j�� �������{��
}
