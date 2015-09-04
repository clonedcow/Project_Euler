#include <iostream>
#define BLOCK_WIDTH 3
#define ROW_LENGTH 30

using namespace std;

int main()
{
    long long combos[ROW_LENGTH+1][2]={0};
    int idx;

    for(idx=0;idx<BLOCK_WIDTH;idx++) combos[idx][0]=1;

    for(;idx<=ROW_LENGTH;idx++){
        combos[idx][0]=combos[idx-1][0]+combos[idx-1][1];           // single black blocks
        combos[idx][1]=combos[idx-BLOCK_WIDTH][0]+combos[idx-1][1]; // long red blocks
    }
    cout<<combos[ROW_LENGTH][0]+combos[ROW_LENGTH][1];
    return 0;
}
