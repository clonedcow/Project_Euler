#include <iostream>
#include <fstream>
using namespace std;

bool interior(int x1,int y1,int x2,int y2,int x3,int y3,int x,int y);
bool sameSide(int xl1,int yl1,int xl2,int yl2,int x1,int y1,int x2,int y2);

int main()
{
    int triIdx;
    int x1,x2,x3,y1,y2,y3;
    int total=0;
    char junk;
    //cout<<sameSide(1,1,-1,-1,0,1,1,0);
    ifstream triangles("triangles.txt");

    if(!triangles.is_open()){
        cout<<"file couldn't open.\n";
        return 0;
    }

    for(triIdx=0;triIdx<1000;triIdx++)
    {
        triangles>>x1>>junk>>y1>>junk>>x2>>junk>>y2>>junk>>x3>>junk>>y3;
        if(interior(x1,y1,x2,y2,x3,y3,0,0)) total++;
    }
    triangles.close();

    cout<<total;
    return 0;
}

bool interior(int x1,int y1,int x2,int y2,int x3,int y3,int x,int y)
{
    if(sameSide(x1,y1,x2,y2,x3,y3,x,y)&&sameSide(x1,y1,x3,y3,x2,y2,x,y)&&sameSide(x2,y2,x3,y3,x1,y1,x,y)) return true;
    return false;
}

bool sameSide(int xl1,int yl1,int xl2,int yl2,int x1,int y1,int x2,int y2)  // returns true if two endpoints of line segment are the same
{
    if(xl1==xl2 && yl1==yl2) return true;
    if(xl1==xl2 && ((x1>=xl1&&x2>=xl1) || (x1<xl1&&x2<xl1))) return true;
    if(yl1==yl2 && ((y1>=yl1&&y2>=yl1) || (y1<yl1&&y2<yl1))) return true;

    if( y1==double((yl2-yl1)*(x1-xl1)+yl1*(xl2-xl1))/(xl2-xl1) || y2==double((yl2-yl1)*(x2-xl1)+yl1*(xl2-xl1))/(xl2-xl1) ) return true;
    if( y1>double((yl2-yl1)*(x1-xl1)+yl1*(xl2-xl1))/(xl2-xl1) && y2>double((yl2-yl1)*(x2-xl1)+yl1*(xl2-xl1))/(xl2-xl1) ) return true;
    if( y1<double((yl2-yl1)*(x1-xl1)+yl1*(xl2-xl1))/(xl2-xl1) && y2<double((yl2-yl1)*(x2-xl1)+yl1*(xl2-xl1))/(xl2-xl1) ) return true;

    return false;
}
