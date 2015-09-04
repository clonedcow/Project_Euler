#include <iostream>
using namespace std;

#define PRIMECOUNT 1000
#define MAXTEST 1000
int prime[PRIMECOUNT];

int primeSums[MAXTEST][PRIMECOUNT];

void fillPrime();

int main()
{
    int test,curTot,primeIdx1,primeIdx2,rem;
    int totSums[MAXTEST];
    fillPrime();

    totSums[1]=0;

    for(test=2;test<MAXTEST;test++) // go through numbers to look for the first one with over 5000 prime summations
    {
        totSums[test]=0;
        for(primeIdx1=0;prime[primeIdx1]<test;primeIdx1++)  // find the number of summations given prime[primeIdx1] primes in the first bin
        {
            if(primeIdx1==PRIMECOUNT)
            {
                cout<<"table not big enough!";
                system("pause");
            }
            curTot=0;
            rem=test-prime[primeIdx1];
            if(rem<=prime[primeIdx1])                    // if there are less remaining objects than in the first bin,
                primeSums[test][primeIdx1]=totSums[rem];// just use the number of summations rem can have

            else
            {
                primeSums[test][primeIdx1]=0;                       // otherwise the second bin can only have up to the amount of the first bin
                for(primeIdx2=0;primeIdx2<=primeIdx1;primeIdx2++)
                    primeSums[test][primeIdx1]+=primeSums[rem][primeIdx2];
            }

            totSums[test]+=primeSums[test][primeIdx1];
        }
        if(prime[primeIdx1]==test)
        {
            primeSums[test][primeIdx1]=1;
            totSums[test]++;
        }

        if(totSums[test]>=5000)
        {
            cout<<test<<","<<totSums[test];
            break;
        }
    }
    /* for checking table to see if algorithm is correct
    for(int i=1;i<11;i++)
    {
        cout.width(3);
        cout<<i<<":";
        for(int j=0;j<10;j++)
        {
            cout<<primeSums[i][j]<<" ";
        }
        cout<<totSums[i]<<endl;
    }
    */
    return 0;
}

void fillPrime()
{
    int index=2,test,TestIndex;
    bool IsPrime;
    prime[0]=2;
    prime[1]=3;

    for(test=5;index<PRIMECOUNT;test+=2){
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
