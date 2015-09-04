#include <iostream>
#include <fstream>

using namespace std;

int main()
{
    int pathMtx[80][80];
    char junk;
    int x,y,xySum;

    ifstream pathFile("81 path matrix.txt");

    if(!pathFile.is_open())
        cout<<"couldn't open path!";

    else
    {
        for(y=0;y<80;y++)
        {
            for(x=0;x<79;x++)
            {
                pathFile>>pathMtx[y][x];
                pathFile>>junk;
            }
            pathFile>>pathMtx[y][79];
        }
        pathFile.close();

        for(xySum=157;xySum>=79;xySum--) // bottom right half of triangle
        {
            for(y=79;xySum-y<=79;y--)
            {
                x=xySum-y;
                if(y==79) pathMtx[y][x]+=pathMtx[79][x+1];
                else if(x==79) pathMtx[y][x]+=pathMtx[y+1][79];
                else pathMtx[y][x]+=min(pathMtx[y+1][x],pathMtx[y][x+1]);
            }
        }

        for(xySum=78;xySum>=0;xySum--)
        {
            for(y=xySum;y>=0;y--)
            {
                x=xySum-y;
                pathMtx[y][x]+=min(pathMtx[y+1][x],pathMtx[y][x+1]);
            }
        }

        cout<<pathMtx[0][0];
    }
    return 0;
}
