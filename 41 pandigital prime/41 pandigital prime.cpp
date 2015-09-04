//41 largest pandigital prime
#include<iostream>
#include<math.h>
using namespace std;

int prime[1000];

void fillprime()
{
    int primecount=1000,testprime=5,testndx;
    bool isprime=0;
    prime[0]=2,prime[1]=3;
    
    
    for(int fillarray=2;fillarray<primecount;fillarray++)
    {
        prime[fillarray]=0;
    }
    
    for(int arrayndx=2;arrayndx<primecount;arrayndx++)/*move along in the array that stores primes after finding a prime*/
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

bool isPrime(int n)
{
    for(int index=0;(prime[index]*prime[index])<=n;index++){
        if((n%prime[index])==0)
            return 0;
    }
    return 1;
}

int nextPandigital(int n)
{
    int index=0,temp,digitsSorted[9];
    for(int i=0;i<9;i++)digitsSorted[i]=0;
    while(((n%100)/10)<(n%10)){//while left digit is smaller than right digit
        digitsSorted[index]=n%10;
        n/=10;
        index++;
    }
    
    if(n==0){//if the input to this function is the smallest n digit pandigital
        for(int i=digitsSorted[1];i>0;i--){
            n+=i;
            n*=10;
        }
        n/=10;
        return n;
    }
    
    digitsSorted[index]=n%10;
    n/=10;
    
    //for(index=0;index<9;index++)cout<<digitsSorted[index]<<",";//Debug:digits we need to sort
       
    for(index=8;digitsSorted[index]<(n%10);index--){}
    index++;
    temp=n%10;
    n-=n%10;
    n+=digitsSorted[index];
    digitsSorted[index]=temp;
    
    for(index=0;digitsSorted[index]!=0;index++){
        n*=10;
        n+=digitsSorted[index];
    }
    
    return n;
}

int main()
{
    fillprime();
    int pandigital;
    //max of 7 digits because sum of 1 to 8 and 1 to 9 are both divisible by 3
    
    for(pandigital=7654321;1;pandigital=nextPandigital(pandigital)){
        /*cout<<pandigital<<"\n";//DEBUG:print each pandigital number
        system("pause");*/
        if(isPrime(pandigital))
            break;
    }
    
    cout<<"prime:"<<pandigital<<"\n";
    system("pause");
    return 0;
}
