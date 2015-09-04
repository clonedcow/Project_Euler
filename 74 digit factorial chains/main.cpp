#include <iostream>
#include "..\comalg.h"
using namespace std;

int digFacSum(int a);

int main()
{
    int start,chainLen,chainIdx,curFacSum,tot=0;
    int chain[61];

    for(start=1;start<1000000;start++)  // iterate through all starting numbers less than 1,000,000
    {
        for(chainLen=0,curFacSum=start;chainLen<=60;chainLen++)  // fill the chain
        {
            chain[chainLen]=curFacSum;

            for(chainIdx=0;chainIdx<chainLen;chainIdx++)    // check if the current factorial sum matches previous entries
                if(chain[chainIdx]==curFacSum) break;

            if(chainIdx!=chainLen) break;   // a repeat has been found

            curFacSum=digFacSum(curFacSum); // find the next digit factorial sum
        }

        if(chainLen==60)tot++;
    }

    cout<<tot;
    return 0;
}

int digFacSum(int a)
{
    int fac[10]={1,1,2,6,24,120,720,5040,40320,362880};
    int sum=0;

    while(a!=0)
    {
        sum+=fac[a%10];
        a/=10;
    }
    return sum;
}
