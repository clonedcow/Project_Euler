#include <iostream>
#include <algorithm>
#include <vector>
#include <fstream>
#include <utility>
using namespace std;

int main()
{
    int wtMtx[80][80];
    int pathMtx[80][79];
    int x,y,rowIdx,colIdx,minPath;
    char junk;
    vector< pair<int,int> > colWts;
    pair<int,int> minWt;

    ifstream pathFile("82 path matrix.txt");

    if(!pathFile.is_open())
        cout<<"couldn't open path!";

    else
    {
        for(y=0;y<80;y++)
        {
            for(x=0;x<79;x++)
            {
                pathFile>>wtMtx[y][x];
                pathFile>>junk;
            }
            pathFile>>wtMtx[y][79];
        }
        pathFile.close();

        for(rowIdx=0;rowIdx<80;rowIdx++)    // initialize first column to corresponding weights
            pathMtx[rowIdx][0]=wtMtx[rowIdx][0];

        for(colIdx=1;colIdx<79;colIdx++)    // initialize rest of matrix to max int
        {
            for(rowIdx=0;rowIdx<80;rowIdx++)
                pathMtx[rowIdx][colIdx]=INT_MAX;
        }

        for(colIdx=1;colIdx<79;colIdx++)
        {
            for(rowIdx=0;rowIdx<80;rowIdx++)
                colWts.push_back(make_pair(pathMtx[rowIdx][colIdx-1]+wtMtx[rowIdx][colIdx],rowIdx));

            make_heap(colWts.begin(),colWts.end());

            for(rowIdx=0;rowIdx<80;rowIdx++)
            {
                minWt=colWts.front();

                if(minWt.second==0)
                {
                    pathMtx[0][colIdx]=min(pathMtx[0][colIdx-1],pathMtx[1][colIdx])+wtMtx[0][colIdx];

                    for(int i=1;i<80;i++)
                    {
                        if(pathMtx[i-1][colIdx]+wtMtx[i][colIdx]<pathMtx[i][colIdx])pathMtx[i][colIdx]=pathMtx[i-1][colIdx]+wtMtx[i][colIdx];
                        else break;
                    }
                }
                else if(minWt.second==79)
                {
                    pathMtx[79][colIdx]=min(pathMtx[79][colIdx-1],pathMtx[78][colIdx])+wtMtx[79][colIdx];

                    for(int i=78;i>=0;i--)
                    {
                        if(pathMtx[i+1][colIdx]+wtMtx[i][colIdx]<pathMtx[i][colIdx])pathMtx[i][colIdx]=pathMtx[i+1][colIdx]+wtMtx[i][colIdx];
                        else break;
                    }
                }
                else
                {
                    pathMtx[minWt.second][colIdx]=min(pathMtx[minWt.second][colIdx-1],min(pathMtx[minWt.second+1][colIdx],pathMtx[minWt.second-1][colIdx]))+wtMtx[minWt.second][colIdx];

                    for(int i=minWt.second+1;i<80;i++)
                    {
                        if(pathMtx[i-1][colIdx]+wtMtx[i][colIdx]<pathMtx[i][colIdx])pathMtx[i][colIdx]=pathMtx[i-1][colIdx]+wtMtx[i][colIdx];
                        else break;
                    }
                    for(int i=minWt.second-1;i>=0;i--)
                    {
                        if(pathMtx[i+1][colIdx]+wtMtx[i][colIdx]<pathMtx[i][colIdx])pathMtx[i][colIdx]=pathMtx[i+1][colIdx]+wtMtx[i][colIdx];
                        else break;
                    }
                }

                pop_heap(colWts.begin(),colWts.end());colWts.pop_back();
            }
        }

        minPath=INT_MAX;

        for(rowIdx=0;rowIdx<80;rowIdx++)
        {
            if(wtMtx[rowIdx][79]+pathMtx[rowIdx][78]<minPath)
                minPath=wtMtx[rowIdx][79]+pathMtx[rowIdx][78];
        }
        cout<<minPath;
    }
    return 0;
}
