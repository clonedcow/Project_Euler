#include <iostream>
#include "..\comalg.h"
using namespace std;

#define PRIMECOUNT 100000
int prime[PRIMECOUNT];

void fillPrime();

int main()
{
    long long d,primeIdx,primeFactorIdx,rem,numPrimeFactors,selPrimes,selPrimesCpy,maxSelPrimes,prod,phi,sign,phiTot=0;
    fillPrime();

    for(d=2;d<=1000000;d++)
    {
        //cout<<d;
        int primeFactors[10]={0,0,0,0,0,0,0,0,0,0}; // list of distinct prime factors for a denominator
        numPrimeFactors=0;                          // the number of distinct prime factors

        rem=d;
        for(primeIdx=0;prime[primeIdx]*prime[primeIdx]<=rem;primeIdx++)
        {
            if(rem%prime[primeIdx]==0)                          // check if prime goes into remainder
            {
                primeFactors[numPrimeFactors]=prime[primeIdx];  // if so add it to the list of prime factors
                numPrimeFactors++;                              // increment the number of prime factors
                rem/=prime[primeIdx];                           // divide remainder by that prime number
            }
            while(rem%prime[primeIdx]==0)   // keep dividing by that prime number until it doesn't divide evenly
                rem/=prime[primeIdx];
        }
        if(rem!=1)                              // if the remainder isn't 1, then itself is a prime factor
        {
            primeFactors[numPrimeFactors]=rem;  // add it to the list
            numPrimeFactors++;                  // increment the number of prime factors
        }

        /* use inclusion-exclusion to find phi(d) */
        selPrimes=1;    // used to pick a subset of the prime factors
        maxSelPrimes=1<<numPrimeFactors;
        phi=d;

        for(;selPrimes<maxSelPrimes;selPrimes++)
        {
            selPrimesCpy=selPrimes;
            prod=d;
            sign=1;
            primeFactorIdx=0;

            while(selPrimesCpy!=0)
            {
                if(selPrimesCpy%2)  // if last bit is 1
                {
                    sign*=-1;                           // flip the sign
                    prod/=primeFactors[primeFactorIdx]; // divide by the prime factor
                }
                primeFactorIdx++;                   // move to the next select bit
                selPrimesCpy>>=1;
            }
            phi+=sign*prod;
        }
        //cout<<","<<phi<<endl;
        phiTot+=phi;
    }

    cout<<phiTot;
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
