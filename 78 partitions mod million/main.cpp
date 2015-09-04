#include <iostream>
using namespace std;

#define MAXTEST 100000

int main()
{
    int P[MAXTEST];
    int test,k,sign;

    P[0]=1;

    for(test=1;test<MAXTEST;test++)
    {
        P[test]=0;
        for(k=1,sign=1;k*(3*k-1)/2<=test;k++)
        {
            P[test]+=sign*P[test-k*(3*k-1)/2];

            if(k*(3*k+1)/2<=test)
                P[test]+=sign*P[test-k*(3*k+1)/2];

            P[test]%=1000000;
            sign=-sign;
        }
        //cout<<test<<","<<P[test]<<endl;

        if(P[test]%1000000==0)
            cout<<test<<","<<P[test];
    }
    return 0;
}

/* too slow and memory consuming
#define MAXTEST 10000

int partialSums[MAXTEST][MAXTEST];
int main()
{
    int test,binCnt1,binCnt2,rem;
    long long totSums[MAXTEST];

    totSums[1]=0;

    for(test=1;test<MAXTEST;test++) // go through numbers to find partitions
    {
        totSums[test]=0;
        for(binCnt1=1;binCnt1<test;binCnt1++)  // find the number of summations given binCnt1 objects in the first bin
        {
            rem=test-binCnt1;
            if(rem<=binCnt1)                    // if there are less remaining objects than in the first bin,
                partialSums[test][binCnt1]=totSums[rem];// just use the number of summations rem can have

            else
            {
                partialSums[test][binCnt1]=0;                       // otherwise the second bin can only have up to the amount of the first bin
                for(binCnt2=1;binCnt2<=binCnt1;binCnt2++)
                {
                    partialSums[test][binCnt1]+=partialSums[rem][binCnt2];
                    partialSums[test][binCnt1]%=1000000;
                }
            }

            totSums[test]+=partialSums[test][binCnt1];
            totSums[test]%=1000000;
        }

        partialSums[test][test]=1;
        totSums[test]++;
        totSums[test]%=1000000;

        if(totSums[test]%10000==0)
        {
            cout<<test<<","<<totSums[test]<<endl;
        }
    }
    return 0;
}*/
