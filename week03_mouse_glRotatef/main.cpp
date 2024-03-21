#include <GL/glut.h>
#include <stdio.h>
float teapotX = 0,teapotY = 0; //設定茶壺的座標點
float angle = 0; //設定角度
//當滑鼠事件發生，重設座標
void mouse(int button, int state, int x, int y){
    teapotX = (x-150)/150.0;
    teapotY = -(y-150)/150.0;
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//清除前一刻畫面
    glPushMatrix();
        //glTranslatef(teapotX,teapotY,0);//更新茶壺的座標
        glRotated(angle,0,0,1);
        glutSolidTeapot(0.2);
    glPopMatrix();
    glutSwapBuffers();
}
void motion(int x,int y){
    angle = x; //以x軸為基準，滑鼠點擊拖曳時，角度隨x軸的移動距離改變
    display();
}
int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03 mouse");
    glutDisplayFunc(display);
    glutMouseFunc(mouse);
    glutMotionFunc(motion);//宣告motion的函數
    glutMainLoop();
}
