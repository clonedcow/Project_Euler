#include <iostream>
#define BLOCK_WIDTH 50
#define MAX_LENGTH 1000

using namespace std;

int main()
{
    long long combos[MAX_LENGTH+1][2]={0};
    int idx;

    for(idx=0;idx<BLOCK_WIDTH;idx++) combos[idx][0]=1;

    for(;idx<=MAX_LENGTH;idx++){
        combos[idx][0]=combos[idx-1][0]+combos[idx-1][1];           // single black blocks
        if(combos[idx][0]>1000000){
            cout<<idx-1;
            break;
        }
        combos[idx][1]=combos[idx-BLOCK_WIDTH][0]+combos[idx-1][1]; // long red blocks
    }
    return 0;
}
