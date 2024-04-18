#include <GL/glut.h>

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    ///實心放上面
	glPushMatrix();
        glTranslatef(-0.6,+0.3,0);
        glutSolidTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
        glTranslatef(0,+0.3,0);
        glutSolidCube(0.2);
	glPopMatrix();

	glPushMatrix();
        glTranslatef(0.6,+0.3,0);
        glutSolidSphere(0.2,20,20);
	glPopMatrix();

	///空心放下面
	glPushMatrix();
        glTranslatef(-0.6,-0.3,0);
        glutWireTeapot(0.2);
	glPopMatrix();

	glPushMatrix();
        glTranslatef(0,-0.3,0);
        glutWireCube(0.2);
	glPopMatrix();

	glPushMatrix();
        glTranslatef(0.6,-0.3,0);
        glutWireSphere(0.2,20,20);
	glPopMatrix();

	glutSwapBuffers();
}

int main(int argc, char*argv[]){
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutCreateWindow("week09-2");
	glutDisplayFunc(display);
	glutMainLoop();
}
