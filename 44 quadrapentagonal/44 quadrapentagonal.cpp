//44 pentagonal sum and difference of pentagonal numbers
#include<iostream>
#include<math.h>
using namespace std;

bool IsPentagonal(int n)
{
    if(int((1+sqrt(1+24*n))/6)==((1+sqrt(1+24*n))/6))
        return 1;
    return 0;
}

int main()
{
    bool DifFound=0;
    int HiBase,LowBase;
    int pentagonal[10000];
    
    for(int i=0;i<10000;i++)
        pentagonal[i]=i*(3*i-1)/2;
    
    for(HiBase=2;DifFound==0;HiBase++){
        for(LowBase=1;(LowBase<HiBase)&&(DifFound==0);LowBase++){
            if(IsPentagonal(pentagonal[HiBase]-pentagonal[LowBase])&&IsPentagonal(pentagonal[LowBase]+pentagonal[HiBase])){
                DifFound=1;
            }
        }
    }
    
    cout<<pentagonal[HiBase-1]-pentagonal[LowBase-1];
    system("pause");
    return 0;
}
