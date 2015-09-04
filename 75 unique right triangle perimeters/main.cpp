#include <iostream>
#include "..\comalg.h"
using namespace std;

#define PRIMECOUNT 100000

int prime[PRIMECOUNT];
int perimeterCnt[750001];
void fillPrime();

int main()
{
    int i,m,n,curPerimeter,perimMult,tot=0;

    fillPrime();

    for(i=0;i<750001;i++)
        perimeterCnt[i]=0;

    for(m=1;m<900;m++)
    {
        for(n=1+(m%2);n<m;n+=2)
        {
            if(!relPrime(m,n)) continue;

            curPerimeter=m*(m+n);

            for(perimMult=1;curPerimeter*perimMult<750001;perimMult++)
                perimeterCnt[curPerimeter*perimMult]++;
        }
    }

    for(i=1;i<750001;i++)
    {
        if(perimeterCnt[i]==1)
            tot++;
    }

    cout<<tot;
    return 0;
}

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
