#include <iostream>
#include "..\comalg.h"

using namespace std;

int main()
{
    long long n,d,diffn,bestn,bestd=1,bestDiffn=1;

    for(d=1;d<1000000;d++)
    {
        n=3*d/7;
        diffn=3*d-7*n;
        if(diffn!=0 && bestd*diffn<d*bestDiffn)
        {
            bestn=n;
            bestd=d;
            bestDiffn=diffn;
            //cout<<n<<"/"<<d<<endl;
        }
    }
    cout<<bestn/gcd(bestn,bestd)<<"/"<<bestd/gcd(bestn,bestd);
    return 0;
}
