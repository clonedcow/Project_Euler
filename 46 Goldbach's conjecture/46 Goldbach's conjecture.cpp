//46 one of Christian Goldbach's conjectures
#include<stdio.h>
#include<math.h>

#define primesize 1000

int prime[primesize];

void fillprime()
{
    int testprime=5,testndx;//prime array generating variables
    bool isprime=0;                    //
    prime[0]=2,prime[1]=3;             //
    
    
    for(int fillarray=2;fillarray<primesize;fillarray++)
    {
        prime[fillarray]=0;
    }
    
    for(int arrayndx=2;arrayndx<primesize;arrayndx++)/*move along in the array that stores primes after finding a prime*/
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

bool testgold(int test)
{
    int primeindex=1,square,difference;
    for(square=1;(2*square*square)<test;square++)//see if difference between twice a square and the test is a prime
    {
        difference=test-(2*square*square);
        
        for(primeindex=1;prime[primeindex]<=difference;primeindex++)//if difference is a prime
        {
             if(prime[primeindex]==difference)
                 return 1;
        }
    }
    
    return 0;
}

bool testcomposite(int test, int lowbndndx)//test if odd number is composite
{
    if(prime[lowbndndx]==test)
        return 0;
    return 1;
}

int main()
{
    int lowbndndx=3,ans;
    bool ansfound=0;
    
    fillprime();
    
    //printf("%d\n",prime[primesize-1]);//print last prime in array
    
    for(int odd=9;ansfound==0;odd+=2)//going through odd numbers
    {
        if(prime[lowbndndx+1]<=odd)//increase lower prime bound of odd numbers
            lowbndndx++;
        
        if(testcomposite(odd,lowbndndx))//test if conjecture holds true if the number is composite
        {
            //if(odd<200)
            //printf("%d ",odd);
            ansfound=!(testgold(odd));
            //printf("%d\n",ansfound);
        }
        
        if(ansfound==1)//found the answer
            ans=odd;
    }
    
    printf("%d",ans);
    scanf("%d",ans);
    return 0;
}
