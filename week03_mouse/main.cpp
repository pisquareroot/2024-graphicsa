#include <GL/glut.h>
#include <stdio.h> //���Fprintf()

void mouse(int button, int state, int x, int y){
    //printf("Hello Mouse!\n");
    printf("%d %d %d %d\n",button, state,x,y); //���L�ѼưT��
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
    glutMouseFunc(mouse); //�ŧimouse�禡
    glutMainLoop();
}
