#include <GL/glut.h>
#include <stdio.h> //為了printf()

void mouse(int button, int state, int x, int y){
    if(state==GLUT_DOWN) printf("glVertex2f((%d-image_x/2)/(image_x/2),-(%d-image_y/2)/image_y/2);\n",x,y);
}

void display(){
    glutSolidTeapot(0.5);
    glutSwapBuffers();
}

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse");
    glutDisplayFunc(display);
    glutMouseFunc(mouse); //宣告mouse函式
    glutMainLoop();
}
