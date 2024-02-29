#include <GL/glut.h>   //使用GLUT函式庫

void display(){
    glColor3f(180/255.0, 255/255.0 , 255/255.0);
    glutSolidTeapot(0.5);

    glColor3f(255/255.0, 255/255.0 , 180/255.0);
    glutSolidTeapot(0.2);
    glutSwapBuffers();
}

int main(int argc, char *argv[]){ //main()函式
    glutInit(&argc, argv); //開啟GLUT功能
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("電腦圖學第01周"); //開一個GLUT視窗
    glutDisplayFunc(display); //display()函式畫圖
    glutMainLoop(); //主要的迴圈 不結束程式
}
