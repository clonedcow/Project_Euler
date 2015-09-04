#include <iostream>

using namespace std;

long double bin(int pow,int choose);

int main()
{
    long double E[32];
    long double total;
    int total,pow,sumIdx;

    for(int EIdx=31;EIdx>=0;EIdx--){
        pow=32-EIdx;
        total=;
        for(sumIdx=1;sumIdx<pow;sumIdx++)
            total+=bin(pow,sumIdx)*E[sumIdx+EIdx]
    }
    cout << "Hello world!" << endl;
    return 0;
}

long double bin(int pow,int choose)
