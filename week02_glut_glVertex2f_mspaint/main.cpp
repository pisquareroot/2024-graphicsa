#include <GL/glut.h>   //�ϥ�GLUT�禡�w

void display(){

    glBegin(GL_POLYGON); //�}�l�e
        glVertex2f((52-128)/128.0,-(59-128)/128.0);
        glVertex2f((100-128)/128.0,-(27-128)/128.0);
        glVertex2f((141-128)/128.0,-(48-128)/128.0);
        glVertex2f((122-128)/128.0,-(96-128)/128.0);
        glVertex2f((70-128)/128.0,-(102-128)/128.0);
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
