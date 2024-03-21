#include <GL/glut.h>
#include <stdio.h>
float teapotX = 0,teapotY = 0; //�]�w�������y���I
float angle = 0; //�]�w����
//��ƹ��ƥ�o�͡A���]�y��
void mouse(int button, int state, int x, int y){
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//�M���e�@��e��
    glPushMatrix();
        //glTranslatef(teapotX,teapotY,0);//��s�������y��
        glRotated(angle,0,0,1);
        glutSolidTeapot(0.2);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y){
    angle = x; //�Hx�b����ǡA�ƹ��I���즲�ɡA�����Hx�b�����ʶZ������
    display();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);//�ŧimotion�����
    glutMainLoop();
}
