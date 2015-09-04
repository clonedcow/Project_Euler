#include <iostream>
using namespace std;

bool isBouncy(int n);

int main()
{
    int bouncy=0;
    int i;

    for(i=1;1;i++){
        if(isBouncy(i)) bouncy++;
        if(((float)bouncy)*100/99==i) break;
        //cout<<i/(bouncy+1)<<",";
    }
    cout<<i;
    //for(int i=0;i<1000000;i++) isBouncy(i);//cout<<i<<","<<isBouncy(i)<<"\n";

    //cout<<isBouncy(1254567);
    return 0;
}

bool isBouncy(int n)
{
    int dir=0;
    int curr;
    int prev=n%10;
    n/=10;

    while(n!=0){
        curr=n%10;
        if(dir==0) dir=(curr>prev) ? 1 : (curr<prev) ?  -1 : 0;
        else if((curr<prev && dir==1) || (curr>prev && dir==-1)) return true;

        //cout<<curr<<","<<prev<<","<<dir<<"\n";
        prev=curr;
        n/=10;
    }
    return false;
}
