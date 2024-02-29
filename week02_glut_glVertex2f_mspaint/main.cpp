#include <GL/glut.h>   //使用GLUT函式庫

void display(){

    glBegin(GL_POLYGON); //開始畫
        glVertex2f((52-128)/128.0,-(59-128)/128.0);
        glVertex2f((100-128)/128.0,-(27-128)/128.0);
        glVertex2f((141-128)/128.0,-(48-128)/128.0);
        glVertex2f((122-128)/128.0,-(96-128)/128.0);
        glVertex2f((70-128)/128.0,-(102-128)/128.0);
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
