#include <iostream>
using namespace std;

//prime number array
#define PrimeCount 5000

int prime[PrimeCount];

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
        
        if(IsPrime==1){//if test is prime then add it to the array
            prime[index]=test;
            index++;
        }
    }
}

//function to test if a number's prime
bool IsPrime(int n)
{
    for(int index=0;(prime[index]*prime[index])<=n;index++){
        if((n%prime[index])==0)
            return 0;
    }
    
    return 1;
}

int main()
{
    FillPrime();
    
    int size,test,diagonal_primes=0,diagonal_total=0;
    float prime_ratio=1;
    
    for(size=3;1;size+=2){
        diagonal_total=size*2-1;
        
        test=size*(size-1)+1; //size*size-(size-1)
        diagonal_primes+=IsPrime(test);
        diagonal_primes+=IsPrime(test-size+1);
        diagonal_primes+=IsPrime(test-2*size+2);
        
        prime_ratio=(float)diagonal_primes/(float)diagonal_total;
        
        if(prime_ratio<.1) break;
    }
    
    cout<<size<<","<<diagonal_primes<<","<<diagonal_total<<","<<prime_ratio;
    system("pause");
            
    return 0;
}
