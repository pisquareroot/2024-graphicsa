#include <GL/glut.h>
float s=1; ///縮放比例
void display(){
    glClearColor(0.5,1.0,1.0,1.0); ///清背景的水藍色
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT); ///清背景
    glPushMatrix();
        glScalef(s,s,s);
        glutSolidTeapot(0.5);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y){
    s = 1 +(x-150)/150.0;
    display();
}
int main(int argc,char*argv[]){
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week04 mouse glScalef");
    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMainLoop();
}
