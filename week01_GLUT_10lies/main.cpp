#include <GL/glut.h>   //�ϥ�GLUT�禡�w

void display(){
    glutSolidTeapot(0.5);
    glutSwapBuffers();
}

int main(int argc, char *argv[]){ //main()�禡
    glutInit(&argc, argv); //�}��GLUT�\��
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("�q���Ͼǲ�01�P"); //�}�@��GLUT����
    glutDisplayFunc(display); //display()�禡�e��
    glutMainLoop(); //�D�n���j�� �������{��
}
