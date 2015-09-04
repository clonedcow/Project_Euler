#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

int main()
{
    int pairIdx;
    int baseExpPairs[1000][2];
    double hi=0;
    char junk;
    ifstream F("base exp pairs.txt");

    if(!F.is_open())
        cout<<"couldn't open file!";

    else
    {
        for(pairIdx=0;pairIdx<1000;pairIdx++)
        {
            F>>baseExpPairs[pairIdx][0];
            F>>junk;
            F>>baseExpPairs[pairIdx][1];
        }
        F.close();

        for(pairIdx=0;pairIdx<1000;pairIdx++)
        {
            if(log(baseExpPairs[pairIdx][0])*baseExpPairs[pairIdx][1]>hi)
            {
                cout<<log(baseExpPairs[pairIdx][0])*baseExpPairs[pairIdx][1]<<","<<pairIdx<<endl;
                hi=log(baseExpPairs[pairIdx][0])*baseExpPairs[pairIdx][1];
            }
        }
    }
    return 0;
}
