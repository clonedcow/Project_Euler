#include <iostream>
int visited[10000000]={};
using namespace std;

int main()
{
    int fillIdx,chainIdx,rem,prev,sum,endn,cnt,tot=1;

    visited[1]=1;
    visited[89]=89;

    for(fillIdx=1;fillIdx<10000000;fillIdx++)
    {
        if(visited[fillIdx]==0)
        {
            chainIdx=fillIdx;
            prev=0;
            cnt=0;
            while(visited[chainIdx]==0)
            {
                //cout<<chainIdx<<endl;
                cnt++;
                visited[chainIdx]=prev;
                for(sum=0,rem=chainIdx;rem!=0;rem/=10)
                    sum+=(rem%10)*(rem%10);

                prev=chainIdx;
                chainIdx=sum;
            }
            endn=visited[chainIdx];
            if(visited[chainIdx]==89) tot+=cnt;
            chainIdx=prev;
            while(visited[chainIdx]!=0)
            {
                prev=visited[chainIdx];
                visited[chainIdx]=endn;
                chainIdx=prev;
            }
            visited[chainIdx]=endn;
        }
    }
    cout<<tot<<endl;
    return 0;
}
