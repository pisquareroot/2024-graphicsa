#include <windows.h>
#include <stdio.h>
int main(){
    ///PlaySound("C:/Do.wav",NULL,SND_SYNC);
    PlaySound("C:/mykbeat.wav",NULL,SND_ASYNC);
    printf("請輸入字元結束程式：");
    char c;
    scanf("%c",&c);
}
