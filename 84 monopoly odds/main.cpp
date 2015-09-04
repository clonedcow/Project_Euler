#include <iostream>
#include <vector>
#include <utility>
#include <stdlib.h>
using namespace std;

bool sqrPairCmp(pair<int,int> a,pair<int,int> b);

int main()
{
    vector<pair<int,int> > sqrCnt;
    int sqrIdx,turn,curSqr=0,die1,die2,dblCnt,CC,CH;
    bool jailBound;

    for(sqrIdx=0;sqrIdx<40;sqrIdx++)
        sqrCnt.push_back(make_pair(sqrIdx,0));

    srand(time(NULL));

    for(turn=0;turn<10000000;turn++)
    {
        for(dblCnt=0,jailBound=false;true;)
        {
            die1=rand()%6+1;
            die2=rand()%6+1;
            curSqr+=die1;
            curSqr+=die2;
            curSqr%=40;
            switch(curSqr)
            {
                case 2: // community chest
                case 17:
                case 33:
                    CC=rand()%16;
                    switch(CC)
                    {
                        case 0: curSqr=0; break;
                        case 1: jailBound=true; break;
                        default: break;
                    }
                    break;
                case 7: // chance
                case 22:
                case 36:
                    CH=rand()%16;
                    switch(CH)
                    {
                        case 0: curSqr=0; break;
                        case 1: jailBound=true; break;
                        case 2: curSqr=11; break;
                        case 3: curSqr=24; break;
                        case 4: curSqr=39; break;
                        case 5: curSqr=5; break;
                        case 6:
                        case 7: if(curSqr==7) curSqr=15;
                                else if(curSqr==22) curSqr=25;
                                else curSqr=5;
                                break;
                        case 8: if(curSqr==22) curSqr=28;
                                else curSqr=12;
                                break;
                        case 9: curSqr-=3; break;
                        default: break;
                    }
                    break;
                case 30:// go to jail
                    jailBound=true;
                    break;
                default:
                    break;
            }

            if(jailBound)
            {
                curSqr=10;
                break;
            }

            if(die1==die2)
            {
                dblCnt++;
                if(dblCnt==3)
                {
                    curSqr=10;
                    break;
                }
            }
            else break;
        }
        sqrCnt[curSqr].second++;
    }

    make_heap(sqrCnt.begin(),sqrCnt.end(),sqrPairCmp);
    cout<<sqrCnt.front().first<<","<<sqrCnt.front().second<<endl;pop_heap(sqrCnt.begin(),sqrCnt.end(),sqrPairCmp);sqrCnt.pop_back();
    cout<<sqrCnt.front().first<<","<<sqrCnt.front().second<<endl;pop_heap(sqrCnt.begin(),sqrCnt.end(),sqrPairCmp);sqrCnt.pop_back();
    cout<<sqrCnt.front().first<<","<<sqrCnt.front().second<<endl;pop_heap(sqrCnt.begin(),sqrCnt.end(),sqrPairCmp);sqrCnt.pop_back();
    return 0;
}

bool sqrPairCmp(pair<int,int> a,pair<int,int> b)
{
    return a.second<b.second;
}
