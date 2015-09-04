#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

int main()
{
    int prime[100];
    double logprime[100];
    double half_log_product=0;
    int primeidx=0;
    int testprime=0;
    int testprimeidx=0;
    bool isprime=false;

    prime[0]=2;

    for(primeidx=1,testprime=3,testprimeidx=0,isprime=true;primeidx<100;testprime+=2,testprimeidx=0,isprime=true){
        while(prime[testprimeidx]*prime[testprimeidx]<=testprime){
            if(testprime%prime[testprimeidx]==0){
                isprime=false;
                break;
            }
            testprimeidx++;
        }
        if(isprime){
            prime[primeidx]=testprime;
            primeidx++;
        }
    }

    for(primeidx=0;primeidx<100;primeidx++){
        logprime[primeidx]=log(prime[primeidx]);
        if(prime[primeidx]<190) half_log_product+=logprime[primeidx];
    }

    half_log_product/=2;

    printf("%f",half_log_product);
    return 0;
}
