#include <iostream>

using namespace std;

int main()
{
    int vec[3][2];
    int index1,index2,tot=0;

    for(index1=1;index1<2601;index1++)
    {
        vec[0][0]=index1%51;
        vec[0][1]=index1/51;
        for(index2=index1+1;index2<2601;index2++)
        {
            vec[1][0]=index2%51;
            vec[1][1]=index2/51;
            vec[2][0]=vec[1][0]-vec[0][0];
            vec[2][1]=vec[1][1]-vec[0][1];

            if(vec[0][0]*vec[1][0]+vec[0][1]*vec[1][1]==0)tot++;
            if(vec[0][0]*vec[2][0]+vec[0][1]*vec[2][1]==0)tot++;
            if(vec[1][0]*vec[2][0]+vec[1][1]*vec[2][1]==0)tot++;
        }
    }
    cout<<tot;
    return 0;
}
