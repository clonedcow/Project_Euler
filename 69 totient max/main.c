#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define PRIME_NUM 100000

int phi(int *prime, int n);

int main()
{
    int prime[PRIME_NUM];
    int primeidx=0;
    int testprime=0;
    int testprimeidx=0;
    bool isprime=false;
    int n=0,bestn=0;
    double fract=0, hifract=0;

    prime[0]=2;
    for(primeidx=1,testprime=3,testprimeidx=0,isprime=true;primeidx<PRIME_NUM;testprime+=2,testprimeidx=0,isprime=true){
        while(prime[testprimeidx]*prime[testprimeidx]<=testprime){
            if(testprime%prime[testprimeidx]==0){
                isprime=false;
                break;
            }
            testprimeidx++;
        }
        if(isprime){
            //printf("%d\n",testprime);
            prime[primeidx]=testprime;
            primeidx++;
        }
    }

    for(n=2;n<=1000000;n++){
        fract=(double)n/phi(&prime[0],n);
        //printf("%d,%f\n",n,fract);
        if(fract>hifract){
            printf("%d,%f\n",n,fract);
            hifract=fract;
            bestn=n;
        }
    }

    printf("%d",bestn);
    return 0;
}

int phi(int *prime, int n)
{
    bool sieve[n];
    int primeidx=0;
    int sieveidx=0;
    int relprimecnt=1;

    for(sieveidx=0;sieveidx<n;sieveidx++) sieve[sieveidx]=true;

    for(primeidx=0;prime[primeidx]*2<=n;primeidx++){
        if(n%prime[primeidx]==0){
            //printf("%d",prime[primeidx]);
            for(sieveidx=prime[primeidx];sieveidx<n;sieveidx+=prime[primeidx])sieve[sieveidx]=false;
        }
    }

    for(sieveidx=2;sieveidx<n;sieveidx++){
        //if(sieve[sieveidx])printf("%d,",sieveidx);
        relprimecnt+=sieve[sieveidx];
    }

    return relprimecnt;
}
