#include <opencv/highgui.h>
int main(){
    IplImage * img = cvLoadImage("C:/Users/Administrator/Desktop/images.jpg");
    cvShowImage("week05",img);
    cvWaitKey(0);
}
