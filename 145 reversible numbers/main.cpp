#include <iostream>
using namespace std;

int rev(int n);
bool allOdd(int n);

int main()
{
    int n,tot;
    for(n=1;n<1000000000;n++)
    {
        if(n%10!=0 && allOdd(n+rev(n)))
            tot++;
    }
    cout<<tot;
    return 0;
}

int rev(int n)
{
    int r=0;

    do
    {
        r*=10;
        r+=n%10;
        n/=10;
    }while(n!=0);

    return r;
}

bool allOdd(int n)
{
    do
    {
        if(n%2==0) return false;
        n/=10;
    }while(n!=0);

    return true;
}
