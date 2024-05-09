#include <GL/glut.h>
#include "glm.h"
#include <opencv/highgui.h> ///�ϥ� OpenCV 2.1 ���²��, �u�n�� High GUI �Y�i
#include <opencv/cv.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCVŪ��
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV���m (�ݭncv.h)
    glEnable(GL_TEXTURE_2D); ///1. �}�ҶK�ϥ\��
    GLuint id; ///�ǳƤ@�� unsigned int ���, �s �K��ID
    glGenTextures(1, &id); /// ����Generate �K��ID
    glBindTexture(GL_TEXTURE_2D, id); ///�j�wbind �K��ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��T, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// �K�ϰѼ�, �W�L�]�˪��d��S, �N���жK��
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// �K�ϰѼ�, ��j�ɪ�����, �γ̪��I
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// �K�ϰѼ�, �Y�p�ɪ�����, �γ̪��I
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

///GLMmodel* pmodel = NULL;
///GLMmodel* left_hand = NULL;
///GLMmodel* right_hand = NULL;
GLMmodel* upperA = NULL;
GLMmodel* lowerA = NULL;
void drawUpperA(void){
    if (!upperA){
        upperA = glmReadOBJ("data/upperA.obj");
        if (!upperA) exit(0);
        glmUnitize(upperA);
        glmFacetNormals(upperA);
        glmVertexNormals(upperA, 90.0);
    }
    glmDraw(upperA, GLM_SMOOTH | GLM_TEXTURE);
}

void drawLowerA(void){
    if (!lowerA){
        lowerA = glmReadOBJ("data/lowerA.obj");
        if (!lowerA) exit(0);
        glmUnitize(lowerA);
        glmFacetNormals(lowerA);
        glmVertexNormals(lowerA, 90.0);
    }
    glmDraw(lowerA, GLM_SMOOTH | GLM_TEXTURE);
}

void myBody(){
    glPushMatrix();
        glColor3f(0.2,0.8,0.8);
        glutSolidCube(0.6);
    glPopMatrix();
}

float angle=0,da=1;
void display(){
    angle+=da;
    if(angle>90)da=-1;
    if(angle<0)da=1;
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
        glDisable(GL_TEXTURE_2D);  ///���N�K�ϥ\�������Aø�s����A�H�K�C��Q�K�ϼv�T
        ///myBody();
        ///glutSolidSphere(0.1,30,30); ///�o�O�w���I
        glEnable(GL_TEXTURE_2D);
        glColor3f(1,1,1); ///�N�C��]���զ�

        drawUpperA();
        glPushMatrix();
            glTranslatef(-0.02,-0.09,0);
            glRotatef(angle,1,0,0);
            glTranslatef(0,-0.21,0);
            drawLowerA();
        glPopMatrix();

    glutSwapBuffers();
}

const GLfloat light_ambient[]  = { 0.0f, 0.0f, 0.0f, 1.0f };
const GLfloat light_diffuse[]  = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_specular[] = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat light_position[] = { 2.0f, 5.0f, -5.0f, 0.0f };

const GLfloat mat_ambient[]    = { 0.7f, 0.7f, 0.7f, 1.0f };
const GLfloat mat_diffuse[]    = { 0.8f, 0.8f, 0.8f, 1.0f };
const GLfloat mat_specular[]   = { 1.0f, 1.0f, 1.0f, 1.0f };
const GLfloat high_shininess[] = { 100.0f };

int main(int argc, char *argv[]){
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week12-2");
    glutIdleFunc(display);
    glutDisplayFunc(display);
    myTexture("data/Diffuse.jpg");

    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    glEnable(GL_LIGHT0);
    glEnable(GL_NORMALIZE);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_LIGHTING);

    glLightfv(GL_LIGHT0, GL_AMBIENT,  light_ambient);
    glLightfv(GL_LIGHT0, GL_DIFFUSE,  light_diffuse);
    glLightfv(GL_LIGHT0, GL_SPECULAR, light_specular);
    glLightfv(GL_LIGHT0, GL_POSITION, light_position);

    glMaterialfv(GL_FRONT, GL_AMBIENT,   mat_ambient);
    glMaterialfv(GL_FRONT, GL_DIFFUSE,   mat_diffuse);
    glMaterialfv(GL_FRONT, GL_SPECULAR,  mat_specular);
    glMaterialfv(GL_FRONT, GL_SHININESS, high_shininess);

    glutMainLoop();
}
