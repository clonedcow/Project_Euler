#include <iostream>
using namespace std;

#define PRIMECOUNT 1000
int prime[PRIMECOUNT];
bool found[50000000]={};
void fillPrime();

int main()
{
    int b2,b3,b4,tot=0;
    fillPrime();

    for(b2=0;prime[b2]*prime[b2]<50000000;b2++)
    {
        for(b3=0;prime[b2]*prime[b2]+prime[b3]*prime[b3]*prime[b3]<50000000;b3++)
        {
            for(b4=0;prime[b2]*prime[b2]+prime[b3]*prime[b3]*prime[b3]+prime[b4]*prime[b4]*prime[b4]*prime[b4]<50000000;b4++)
            {
                if(!found[prime[b2]*prime[b2]+prime[b3]*prime[b3]*prime[b3]+prime[b4]*prime[b4]*prime[b4]*prime[b4]])
                {
                    found[prime[b2]*prime[b2]+prime[b3]*prime[b3]*prime[b3]+prime[b4]*prime[b4]*prime[b4]*prime[b4]]=true;
                    tot++;
                }
            }
        }
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
