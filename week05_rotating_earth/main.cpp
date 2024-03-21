#include <opencv/highgui.h>
#include <opencv/cv.h>
#include <GL/glut.h>
GLUquadric * quad = NULL; ///建立空指標
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename);
    cvCvtColor(img,img, CV_BGR2RGB);
    glEnable(GL_TEXTURE_2D);
    GLuint id;
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
float angle = 0;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glEnable(GL_DEPTH_TEST);
    glPushMatrix();
    glRotatef(90,1,0,0);
    glRotatef(angle+=1.5,0,0,1);
    gluSphere(quad,1,30,30);
    glPopMatrix();
    //glutSolidTeapot(0.5);
    glutSwapBuffers();
}
int main(int argc,char*argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("C:/Users/Administrator/Desktop/earth.jpg");
    quad = gluNewQuadric(); ///把指標設置好
    gluQuadricTexture(quad,1); ///做好地球的貼圖
    glutMainLoop();
}
