#include <iostream>
#include <windows.h>
#include <ctime>
//scale of the drawing on screen
#define scale 1
//size of the matrix
#define siz 50
using namespace std;
HDC dng = GetDC(0);
int screen[siz][siz];
int i,j,done,n;
void refresh() {
    for(i=0;i<siz*scale;i++) {
        for(j=0;j<siz*scale;j++){
            SetPixel(dng,i,j,RGB(screen[i/scale][j/scale],screen[i/scale][j/scale],screen[i/scale][j/scale]));
        }
    }
}
int main()
{
    srand(time(NULL));
    Sleep(1000);
    for (i=0;i<siz;i++) {
        screen[i][0]=screen[i][siz-1]=0;
        screen[0][i]=screen[siz-1][i]=0;
    }
    for(i=1;i<siz-1;i++) {
        for(j=1;j<siz-1;j++){
            screen[i][j] = rand()%255;
        }
    }
    refresh();
    while(1){
        n++;
        for(i=1;i<siz-1;i++){
            for(j=1;j<siz-1;j++){
                screen[i][j] = (screen[i+1][j] + screen[i][j+1] + screen[i-1][j] + screen[i][j-1] + screen[i+1][j+1] + screen[i-1][j+1] + screen[i-1][j-1] + screen[i+1][j-1] + rand()%255)/8;

            }
        }
        if (n%1000==0) {refresh(); cout<<n<<endl;}
    }
    return 0;
}
