#include <GL/glut.h>   //�ϥ�GLUT�禡�w
#include <math.h>
void display(){

    glBegin(GL_POLYGON); //�}�l�e
        for(float a=90/180.0*3.1415926; a<=3.1415926; a+=0.00001)
            glVertex2f( cos(a),sin(a) );
        glVertex2f( 30/128.0,0/128.0 );
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
