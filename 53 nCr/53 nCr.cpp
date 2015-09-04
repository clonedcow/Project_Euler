//53 nCr
#include<iostream>
using namespace std;

int combinations(int n, int r)
{
    int tempr=r,tempn=n;
    float nCr=1;
    for(;tempr>0;tempr--,tempn--){
        nCr*=tempn;
        nCr/=tempr; 
    }
    return nCr;
}

int main()
{
    int n,r,total=0;
    float nCr;
    for(n=23;n<=100;n++){
        for(r=0,nCr=0;(nCr<=1000000)&&((2*r)<=(n+1));r++){
            nCr=combinations(n,r);
        }
        if(nCr>1000000){
            r--;
            total+=(n-2*r+1);
        }
    }
    cout<<total;
    system("pause");
    return 0;
}
