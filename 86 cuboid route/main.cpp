#include <iostream>
#include <math.h>
using namespace std;

int main()
{
    int M,s,tot=0;
    double sq;
    for(M=2;tot<1000000;M++)
    for(s=2;s<=2*M;s++)
    {
        sq=sqrt(M*M+s*s);
        if(sq==(int(sq)))
        {
            if(s<=M+1) tot+=s/2;
            else tot+=(2*M-s+2)/2;
        }
    }
    cout<<M-1<<","<<tot;
    return 0;
}
