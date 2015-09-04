//prime that's the sum of the most primes
#include<iostream>
#define PrimeCount 30000
using namespace std;

int prime[PrimeCount];

bool IsPrime(int n)
{
    for(int index=0;(prime[index]*prime[index])<=n;index++){
        if((n%prime[index])==0)
            return 0;
    }
    return 1;
}

void FillPrime()
{
    int index=2,test,TestIndex;
    bool IsPrime;
    prime[0]=2;
    prime[1]=3;
    
    for(test=5;index<PrimeCount;test+=2){
        IsPrime=1;
        
        for(TestIndex=1;(prime[TestIndex]*prime[TestIndex])<=test;TestIndex++){//test if test is prime
            if((test%prime[TestIndex])==0){
                IsPrime=0;
                break;
            }
        }
        
        if(IsPrime==1){
            prime[index]=test;
            index++;
        }
    }
}

int main()
{
    int count=0,MaxSum=0,test,LowIndex,SumIndex;
    bool PrimeFound=0;
    FillPrime();
    
    for(count=0;MaxSum<=1000000;count++){
        MaxSum+=prime[count];
    }
    
    for(count--;PrimeFound==0;count--){                        
        for(SumIndex=0,test=0;SumIndex<count;SumIndex++){//find value of sum starting from 2
            test+=prime[SumIndex];
        }
        
        for(LowIndex=0;test<=1000000;LowIndex++){
            if(IsPrime(test)){
                PrimeFound=1;
                break;
            }
            test-=prime[LowIndex];
            test+=prime[LowIndex+count];
        }
    }
    
    cout<<test;
    system("pause");
    return 0;
}
