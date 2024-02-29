#include <GL/glut.h>   //使用GLUT函式庫

void display(){

    glBegin(GL_POLYGON); //開始畫
        glColor3f(1,0,0); glVertex2f(0,1);
        glColor3f(0,1,0); glVertex2f(1,-0.6);
        glColor3f(0,0,1); glVertex2f(-1,-0.6);
    glEnd(); //結束畫

    glutSwapBuffers();
}

int main(int argc, char *argv[]){ //main()函式
    glutInit(&argc, argv); //開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("電腦圖學第01周"); //開一個GLUT視窗
    glutDisplayFunc(display); //display()函式畫圖
    glutMainLoop(); //主要的迴圈 不結束程式
}
