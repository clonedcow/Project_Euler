//27 prime-generating quadratic
#include<stdio.h>
#include<math.h>

int prime[400];

void fillprime()
{
    int testprime=5,testndx;
    bool isprime=0;
    prime[0]=2,prime[1]=3;
    
    
    for(int fillarray=2;fillarray<400;fillarray++)
    {
        prime[fillarray]=0;
    }
    
    for(int arrayndx=2;arrayndx<400;arrayndx++)/*move along in the array that stores primes after finding a prime*/
    {                                           
        for(isprime=0;isprime==0;testprime+=2)/*stay in same array space as long as there's no prime*/
        {                               
            for(testndx=1,isprime=1;(sqrt(prime[testndx])<=testprime)&&(prime[testndx]!=0);testndx++)/*check if a number is prime*/
            {                                                                                       
                if((testprime%prime[testndx])==0)
                {
                    isprime=0;
                    break;
                }
            }
            
            if(isprime==1)/*if it is prime add it to the prime array*/      
            {
                prime[arrayndx]=testprime;
            }
        }
    }
}

bool testprime(int n)
{
    for(int index=0;prime[index]<=sqrt(n);index++)
    {
        if(n%prime[index]==0)
            return false;
    }
    
    return true;
}

int main()
{
    int a,b,besta=0,bestb=0,input,isprime,quadval,mostprimes=0;
    
    fillprime();
    
    for(a=1;a<1000;)//n^2+an+b
    {
        for(b=1;prime[b]<1000;b++)
        {
            for(input=1,isprime=1;isprime==1;input++)
            {
                quadval=(input*input)+(a*input)+prime[b];
                if(quadval<2)
                    break;
                else
                    isprime=testprime(quadval);
            }
            
            if((input-1)>mostprimes)
            {
                mostprimes=input-1;
                besta=a;
                bestb=prime[b];
            }
        }
        
        if(a>0)
            a=-a;
        else 
            a=2-a;
    }
    
    printf("%d,%d,%d",besta,bestb,mostprimes);
    scanf("%d",&a);
    return 0;
}
