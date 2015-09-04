#include <iostream>
#include "..\comalg.h"
using std::cout;
using std::endl;

//prime number array
int prime[PRIMECOUNT];

void fillPrime();
bool isPrime(int n);

int main()
{
    unsigned int i,j,n,totn,bestn=2;
    double bestTotRat=2;

    fillPrime();

    for(i=5;i<PRIMECOUNT;i++)
    {
        for(j=5;j<i && prime[j]*prime[i]<10000000;j++)
        {
            n=prime[i]*prime[j];
            totn=n-prime[i]-prime[j]+1;
            if(arePermutations(n,totn) && n/((double)totn)<bestTotRat)
            {
                bestn=n;
                bestTotRat=n/((double)totn);
                cout<<n<<" "<<totn<<" "<<bestTotRat<<endl;
            }
        }
    }
    return 0;
}

// fills the prime array
void fillPrime()
{
    int index=2,test,TestIndex;
    bool IsPrime;
    prime[0]=2;
    prime[1]=3;

    for(test=5;index<PRIMECOUNT;test+=2){
        IsPrime=1;

        for(TestIndex=1;(prime[TestIndex]*prime[TestIndex])<=test;TestIndex++){//test if test is prime
            if((test%prime[TestIndex])==0){
                IsPrime=0;
                break;
            }
        }

        if(IsPrime==1){//if test is prime then add it to the array
            prime[index]=test;
            index++;
        }
    }
}
