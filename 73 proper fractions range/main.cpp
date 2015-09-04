#include <iostream>
#include "..\comalg.h"
using namespace std;

int main()
{
    int d,n,tot=0;
    for(d=2;d<=12000;d++)
    {
        for(n=d/3+1;2*n<d;n++)
        {
            if(relPrime(n,d)) tot++;
            //cout<<n<<"/"<<d<<endl;
        }
    }
    cout << tot << endl;
    return 0;
}
