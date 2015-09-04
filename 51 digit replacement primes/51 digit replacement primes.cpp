//51 digit replacement prime
#include<iostream>
#define PrimeCount 1000
using namespace std;

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

bool IsPrime(int n)
{
    for(int index=0;(prime[index]*prime[index])<=n;index++){
        if((n%prime[index])==0)
            return 0;
    }
    return 1;
}

int ZeroDigits(int Test)
{
    int Increment=0;
    for(int Pow=1;Test>0;Pow*=10,Test/=10){
        if((Test%10)==0){
            Increment+=Pow;
        }
    }
    return Increment;
}

int OneDigits(int Test)
{
    int Increment=0;
    for(int Pow=1;Test>0;Pow*=10,Test/=10){
        if((Test%10)==1){
            Increment+=Pow;
        }
    }
    return Increment;
}

int main()
{
    FillPrime();
    int Base,Increment,IncrementMult,Composites,TempBase;
    
    for(Base=56000;1;Base++){
        Increment=ZeroDigits(Base);
        if(Increment!=0){   
            for(TempBase=Base,Composites=0,IncrementMult=0;(IncrementMult<=9)&&(Composites<=2);IncrementMult++){
                if(IsPrime(TempBase)==0){
                    Composites++;
                }
                TempBase+=Increment;
            }
            if(Composites<=2){
                break;
            }
        }
        Increment=OneDigits(Base);
        if(Increment!=0){
            for(TempBase=Base,Composites=0,IncrementMult=1;(IncrementMult<=9)&&(Composites<=1);IncrementMult++){
                if(IsPrime(TempBase)==0){
                    Composites++;
                }
                TempBase+=Increment;
            }
            if(Composites<=1){
                break;
            }
        }
    }
    
    cout<<Base;
    system("pause");
    return 0;
}
