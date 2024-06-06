#include <GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSolidTeapot(0.5);
	glutSwapBuffers();
}

void reshape(int w,int h){
    glViewport(0,0,w,h);  ///限定視窗會看到的區域
    float ar = w/(float) h;
    glMatrixMode(GL_PROJECTION); ///切換投影矩陣
    glLoadIdentity();
    gluPerspective(60, ar, 0.01, 100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(0,2,-2,0,0,0,0,1,0);
}

int main(int argc, char*argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(600,400); ///可以改變視窗大小
	glutCreateWindow("week16-2");
	glutReshapeFunc(reshape);///加這行可以改善之前視窗拖動時物件變形的問題
	glutDisplayFunc(display);
	glutMainLoop();
}
