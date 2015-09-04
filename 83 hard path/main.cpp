#include <iostream>
#include <fstream>
#include <utility>
#include <vector>
using namespace std;

bool cmp(pair<int,pair<int,int> > &a,pair<int,pair<int,int> > &b);

int main()
{
    int wtMtx[80][80];
    int pathMtx[80][80];
    bool visited[80][80];
    int x,y;
    char junk;
    vector<pair<int,pair<int,int> > > adjHeap;
    pair<int,pair<int,int> > loWt;


    ifstream pathFile("83 path matrix.txt");

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

        for(y=0;y<80;y++)
        {
            for(x=0;x<80;x++)
                visited[y][x]=false;
        }

        x=0;
        y=0;
        adjHeap.push_back(make_pair(wtMtx[0][0],make_pair(0,0)));

        do
        {
            loWt=adjHeap.front();pop_heap(adjHeap.begin(),adjHeap.end(),cmp);adjHeap.pop_back();
            y=loWt.second.first;
            x=loWt.second.second;
            if(!visited[y][x])
            {
                visited[y][x]=true;

                pathMtx[y][x]=loWt.first;

                if(x>0)
                {
                    adjHeap.push_back(make_pair(pathMtx[y][x]+wtMtx[y][x-1],make_pair(y,x-1)));push_heap(adjHeap.begin(),adjHeap.end(),cmp);
                }
                if(x<79)
                {
                    adjHeap.push_back(make_pair(pathMtx[y][x]+wtMtx[y][x+1],make_pair(y,x+1)));push_heap(adjHeap.begin(),adjHeap.end(),cmp);
                }
                if(y>0)
                {
                    adjHeap.push_back(make_pair(pathMtx[y][x]+wtMtx[y-1][x],make_pair(y-1,x)));push_heap(adjHeap.begin(),adjHeap.end(),cmp);
                }
                if(y<79)
                {
                    adjHeap.push_back(make_pair(pathMtx[y][x]+wtMtx[y+1][x],make_pair(y+1,x)));push_heap(adjHeap.begin(),adjHeap.end(),cmp);
                }
            }
        }while((x!=79 || y!=79) && !adjHeap.empty());

        cout<<pathMtx[79][79];
    }
    return 0;
}

bool cmp(pair<int,pair<int,int> > &a,pair<int,pair<int,int> > &b)
{
    return a.first>b.first;
}
