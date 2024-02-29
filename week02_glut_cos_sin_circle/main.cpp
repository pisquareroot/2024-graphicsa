#include <GL/glut.h>   //使用GLUT函式庫
#include <math.h>
void display(){

    glBegin(GL_POLYGON); //開始畫
        for(float a=90/180.0*3.1415926; a<=3.1415926; a+=0.00001)
            glVertex2f( cos(a),sin(a) );
        glVertex2f( 30/128.0,0/128.0 );
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
