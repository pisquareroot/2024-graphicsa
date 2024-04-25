#include <GL/glut.h>
#include <mmsystem.h> ///加上多媒體聲音系統
void myBody(){
    glPushMatrix();
        glColor3f(1,0,0); ///red
        glutWireCube(0.6);
	glPopMatrix();
}
void myArm(){
    glPushMatrix();
        glColor3f(0,1,0); ///green
        glScalef(1,0.4,0.4);
        glutWireCube(0.3);
	glPopMatrix();
}
float angle=0;
void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	myBody();

	glPushMatrix(); ///右半邊
        glTranslatef(0.3, 0.3, 0);
        glRotatef(angle, 0 ,0 , 1);
        glTranslatef(0.15, 0, 0);
        myArm();  ///右上手臂
        glPushMatrix();
            glTranslatef(0.15, 0, 0);
            glRotatef(angle, 0 ,0 , 1);
            glTranslatef(0.15, 0, 0);
            myArm();  ///右下手臂
        glPopMatrix();
    glPopMatrix();

    glPushMatrix(); ///左半邊
        glTranslatef(-0.3, 0.3, 0);
        glRotatef(-angle, 0 ,0 , 1);
        glTranslatef(-0.15, 0, 0);
        myArm();  ///左上手臂
        glPushMatrix();
            glTranslatef(-0.15, 0, 0);
            glRotatef(-angle, 0 ,0 , 1);
            glTranslatef(-0.15, 0, 0);
            myArm();  ///左下手臂
        glPopMatrix();
    glPopMatrix();

	glutSwapBuffers();
}
void motion(int x,int y){
    angle = x;
    glutPostRedisplay();
}
int main(int argc, char*argv[]){
	PlaySound("C:/horse.wav",NULL,SND_ASYNC);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10-9");
	glutDisplayFunc(display);
	glutMotionFunc(motion);
	glutIdleFunc(display);
	glutMainLoop();
}
