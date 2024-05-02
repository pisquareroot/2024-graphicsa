#include <GL/glut.h>
#include "glm.h"
#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}

///GLMmodel* pmodel = NULL;
GLMmodel* left_hand = NULL;
GLMmodel* right_hand = NULL;
void l_hand(void){
    if (!left_hand){
        left_hand = glmReadOBJ("data/left_hand.obj");
        if (!left_hand) exit(0);
        glmUnitize(left_hand);
        glmFacetNormals(left_hand);
        glmVertexNormals(left_hand, 90.0);
    }
    glmDraw(left_hand, GLM_SMOOTH | GLM_TEXTURE);
}

void r_hand(void){
    if (!right_hand){
        right_hand = glmReadOBJ("data/right_hand.obj");
        if (!right_hand) exit(0);
        glmUnitize(right_hand);
        glmFacetNormals(right_hand);
        glmVertexNormals(right_hand, 90.0);
    }
    glmDraw(right_hand, GLM_SMOOTH | GLM_TEXTURE);
}

void myBody(){
    glPushMatrix();
        glColor3f(0.2,0.8,0.8);
        glutSolidCube(0.6);
    glPopMatrix();
}

float angle=0;
void display(){
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glDisable(GL_TEXTURE_2D);  ///先將貼圖功能關閉再繪製身體，以免顏色被貼圖影響
    myBody();
    glEnable(GL_TEXTURE_2D);
    glColor3f(1,1,1); ///將顏色設為白色
    glPushMatrix();
        glTranslated(0.3,0.3,-0.3);
        glRotatef(angle+=0.5,1,0,0);
        glTranslated(0,-0.3,0);
        r_hand();
    glPopMatrix();

    glPushMatrix();
        glTranslated(-0.3,0.3,-0.3);
        glRotatef(angle+=0.5,1,0,0);
        glTranslated(0,-0.3,0);
        l_hand();
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
    glutCreateWindow("week11-2");
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
