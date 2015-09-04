#include <iostream>

using namespace std;

bool mysteryMatch(uint64_t square);

int main()
{
    uint64_t base;
    for(base=100000000;base<200000000;base+=10)
    {
        if(mysteryMatch((base+3)*(base+3)))
        {
            cout<<base+3;
            break;
        }
        if(mysteryMatch((base+7)*(base+7)))
        {
            cout<<base+7;
            break;
        }
    }
    return 0;
}

bool mysteryMatch(uint64_t square)
{
    //cout<<square<<endl;
    if(((square/100)%10)==8 &&
       ((square/10000)%10)==7 &&
       ((square/1000000)%10)==6 &&
       ((square/100000000)%10)==5 &&
       ((square/100000000/100)%10)==4 &&
       ((square/100000000/10000)%10)==3 &&
       ((square/100000000/1000000)%10)==2 &&
       ((square/100000000/100000000)%10)==1
       )
        return true;
    return false;
}
