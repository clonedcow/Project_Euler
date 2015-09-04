#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
using namespace std;

#define PRIMECOUNT 100000
int primes[PRIMECOUNT];

vector<pair<int,int> > pFactor(int a);
int solCnt(vector<pair<int,int> > const &factors);

int main()
{
    int n,solutions=0;
    char junk;

    ifstream pFile("../primes.txt");

    if(!pFile.is_open())
        return -1;

    for(int pIdx=0;pIdx<PRIMECOUNT;pIdx++)
    {
        pFile>>primes[pIdx];
        pFile>>junk;
    }
    pFile.close();

    for(n=1;solutions<1000;n++){
        solutions=solCnt(pFactor(n));
        //cout<<n<<","<<solutions<<endl;
    }
    n--;

    cout<<n<<","<<solutions;

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

int solCnt(vector<pair<int,int> > const &factors)
{
    unsigned int i,tot=1;

    for(i=0;i<factors.size();i++) tot*=factors[i].second*2+1;

    return (tot+1)/2;
}
