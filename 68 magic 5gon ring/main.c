#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool findans(bool *used, int *ans, int *bestans, int depth, int sum);

int main()
{
    int initidx;
    bool used[11];
    int ans[10];
    int bestans[10];
    int sum=0;

    for(initidx=0;initidx<10;initidx++){
        used[initidx]=false;
        best[initidx]=0;
    }
    used[10]=false;

    for(sum=18;sum>=14;sum++){
        findans(&used[0],&ans[0],&bestans[0],0,sum);
    }
    return 0;
}

bool findans(bool *used, int *ans, int *bestans, int depth, int sum)
{
    int c1=0,c2=0,c3=0;
    switch(depth){
    case 0:
        for(c1=6;c1>=1;c1--){
            ans[0]=c1;
            used[c1]=true;
            for(c2=9;c2>=1;c2--){
                if(!used[c2]){
                    c3=sum-c1-c2;
                    if(c3>=1&&c3<=10&&!used[c3]){
                        ans[1]=c2;
                        used[c2]=true;
                        ans
                    }
                }
            }
            used[c1]=false;
        }
        break;
    case 1:
        break;
    case 2:
        break;
    case 3:
        break;
    case 4:
        break;
    }
    return false;
}
