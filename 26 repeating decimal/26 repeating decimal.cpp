//26 repeating decimal
#include<stdio.h>
#include<math.h>

int prime[500];

void fillarray()
{
    int testprime=5,testndx;
    bool isprime=0;
    prime[0]=2,prime[1]=3;
    
    
    for(int fillarray=2;fillarray<500;fillarray++)
    {
        prime[fillarray]=0;
    }
    
    for(int arrayndx=2;arrayndx<500;arrayndx++)/*move along in the array that stores primes after finding a prime*/
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

int main()
{
    int bestnum=0;
    fillarray();
    
    for(int remainder=0,curchain=1,maxchain=0,primendx=3;prime[primendx]<1000;primendx++,remainder=9,curchain=1)
    {
        do
        {
            remainder=remainder*10+9;//add extra digit of 9 when not divisible
            remainder=remainder%prime[primendx];//only care about remainder
            curchain++;
        }while(remainder!=0);
    
        if(curchain>maxchain)
        {
            maxchain=curchain;
            bestnum=prime[primendx];
        }
    }
    
    printf("%d",bestnum);
    scanf("%d",&bestnum);
    return 0;
}
