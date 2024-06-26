#include <GL/glut.h>

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
	glPushMatrix();
        glRotatef(angle++, 0 ,0 , 1);
        myArm();
    glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char*argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week10-2");
	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();
}
