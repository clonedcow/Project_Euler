#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

#define PRIMECOUNT 100000
int primes[PRIMECOUNT];
int chain[1000000][2];

vector<pair<int,int> > pFactor(int a);
int sumFact(vector<pair<int,int> > pFacts);

int main()
{
    int pIdx,base,curIdx,chainStart,maxLen=0,bestMin,curLen,curMin;
    char junk;

    ifstream pFile("../primes.txt");

    if(!pFile.is_open())
        return -1;

    for(pIdx=0;pIdx<PRIMECOUNT;pIdx++)
    {
        pFile>>primes[pIdx];
        pFile>>junk;
    }
    pFile.close();

    chain[0][0]=-1;
    chain[0][1]=-1;
    for(base=1;base<1000000;base++)
    {
        if(chain[base][0]==0)
        {
            curIdx=base;
            do
            {
                chain[curIdx][0]=base;
                chain[curIdx][1]=sumFact(pFactor(curIdx));
                curIdx=chain[curIdx][1];
            }while(curIdx<1000000 && chain[curIdx][0]==0);

            if(curIdx<1000000 && chain[curIdx][0]==base)
            {
                chainStart=curIdx;
                for(curLen=1,curMin=curIdx,curIdx=chain[curIdx][1];curIdx!=chainStart;curLen++,curIdx=chain[curIdx][1])
                {
                    if(curIdx<curMin) curMin=curIdx;
                }
                if(curLen>maxLen)
                {
                    maxLen=curLen;
                    bestMin=curMin;
                }
            }
        }
    }

    //cout<<sumFact(pFactor(1));
    cout<<maxLen<<","<<bestMin;
    return 0;
}

vector<pair<int,int> > pFactor(int a)
{
    vector<pair<int,int> > pFact;
    pair<int,int> basePow;
    int pIdx,rem=a;

    for(pIdx=0;primes[pIdx]<=rem;pIdx++)
    {
        if(rem%primes[pIdx]==0)
        {
            basePow.first=primes[pIdx];
            basePow.second=0;
            do
            {
                basePow.second++;
                rem/=primes[pIdx];
            }while(rem%primes[pIdx]==0);
            pFact.push_back(basePow);
        }
    }
    return pFact;
}

int sumFact(vector<pair<int,int> > pFacts)
{
    vector<int> powers;
    int baseIdx,factIdx,maxIdx,prod,sum,powIdx,powCnt;

    for(baseIdx=0,maxIdx=1;baseIdx<pFacts.size();baseIdx++)
    {
        maxIdx*=pFacts[baseIdx].second+1;
        powers.push_back(0);
    }

    for(factIdx=0,sum=0;factIdx<maxIdx-1;factIdx++)
    {
        for(prod=1,baseIdx=0;baseIdx<powers.size();baseIdx++)
        {
            for(powCnt=0;powCnt<powers[baseIdx];powCnt++)
                prod*=pFacts[baseIdx].first;
        }

        sum+=prod;

        powers[powers.size()-1]++;
        for(powIdx=powers.size()-1;powers[powIdx]>pFacts[powIdx].second;powers[powIdx]=0,powIdx--,powers[powIdx]++);
    }

    return sum;
}
