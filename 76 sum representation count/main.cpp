#include <iostream>

using namespace std;

int sumRepCnt(int objects,int limit);

int main()
{
    cout << sumRepCnt(100,100) << endl;
    return 0;
}

int sumRepCnt(int objects,int limit)
{
    int tot=0,curBinCnt;

    if(objects==0) return 1;

    for(curBinCnt=1;curBinCnt<=objects && curBinCnt<=limit;curBinCnt++)
        tot+=sumRepCnt(objects-curBinCnt,curBinCnt);

    return tot;
}
