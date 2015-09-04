//37 truncatable primes quite slow needs optimization using array of left or right truncatable primes
#include<iostream>
#include<math.h>
using namespace std;

int prime[60000];

void fillprime()
{    
    int testprime=5,testndx;
    bool isprime=0;
    prime[0]=2,prime[1]=3;
    
    
    for(int fillarray=2;fillarray<60000;fillarray++)
    {
        prime[fillarray]=0;
    }
    
    for(int arrayndx=2;arrayndx<60000;arrayndx++)/*move along in the array that stores primes after finding a prime*/
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

bool isprime(int test)
{
    if(test<2)
        return 0;
    for(int testndx=0;(prime[testndx]*prime[testndx])<=test;testndx++){
        if((test%prime[testndx]==0)||(test==0)||(test==1))
            return 0;
    }
    return 1;
}

bool truncfromright(int test)
{
    test/=10;
    do{
        if(!isprime(test))
            return 0;
        test/=10;
    }while(test!=0);
    return 1;
}

bool truncfromleft(int test,int digitcount)
{ 
    int modulus;
    digitcount--;
    for(modulus=1;digitcount>0;digitcount--)
        modulus*=10;
    test=test%modulus;   
    do{
        if(!isprime(test))
            return 0;
        modulus/=10;
        test=test%modulus;
    }while(test!=0);
    return 1;
}

int countdigit(int n)
{
    int digitcount;
    for(digitcount=0;n>0;n/=10){
        digitcount++;
    }
    return digitcount;
}

int main()
{
    fillprime();
    
    int digitcount,sum=0,remainingprimes=11;
    for(int testndx=4;(remainingprimes>0)&&(testndx<60000);testndx++){
        if(truncfromright(prime[testndx])){//first test from right because it's easier
            digitcount=countdigit(prime[testndx]);//only test from left if right works
            if(truncfromleft(prime[testndx],digitcount)){
                cout<<prime[testndx]<<"\n";
                remainingprimes--;
                sum+=prime[testndx];
            }
        }
    }
    
    cout<<"sum:"<<sum<<"\n"<<prime[59999];
    system("pause");
    return 0;
}
