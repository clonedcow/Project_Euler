#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

static bool casefound[9];
static int ans[6];
static int anscase[6];

bool cycfig(int stage, int minbound);
bool triangle(int num);
bool square(int num);
bool pentagonal(int num);
bool hexagonal(int num);
bool heptagonal(int num);
bool octagonal(int num);

int main()
{
    int i;
    for(i=0;i<9;i++){
        casefound[i]=false;
    }
    for(i=0;i<6;i++){
        ans[i]=0;
    }
    printf("%d\n",cycfig(1,1));
    for(i=0;i<6;i++){
        printf("%d%d,%d\n",ans[i],ans[(i+1)%6],anscase[i]);
    }
    return 0;
}

bool cycfig(int stage, int minbound)
{
    int testnum,testnum1;
    int testcase;
    switch(stage){
        case 1:
            for(testnum=10;testnum<100;testnum++){
                for(testnum1=testnum;testnum1<100;testnum1++){
                    if(triangle(testnum*100+testnum1)){
                        anscase[0]=3;
                        casefound[3]=true;
                        ans[0]=testnum;
                        ans[1]=testnum1;
                        if(cycfig(2,testnum))
                            return true;
                        casefound[3]=false;
                    }
                    if(square(testnum*100+testnum1)){
                        anscase[0]=4;
                        casefound[4]=true;
                        ans[0]=testnum;
                        ans[1]=testnum1;
                        if(cycfig(2,testnum))
                            return true;
                        casefound[4]=false;
                    }
                    if(pentagonal(testnum*100+testnum1)){
                        anscase[0]=5;
                        casefound[5]=true;
                        ans[0]=testnum;
                        ans[1]=testnum1;
                        if(cycfig(2,testnum))
                            return true;
                        casefound[5]=false;
                    }
                    if(hexagonal(testnum*100+testnum1)){
                        anscase[0]=6;
                        casefound[6]=true;
                        ans[0]=testnum;
                        ans[1]=testnum1;
                        if(cycfig(2,testnum))
                            return true;
                        casefound[6]=false;
                    }
                    if(heptagonal(testnum*100+testnum1)){
                        anscase[0]=7;
                        casefound[7]=true;
                        ans[0]=testnum;
                        ans[1]=testnum1;
                        if(cycfig(2,testnum))
                            return true;
                        casefound[7]=false;
                    }
                    if(octagonal(testnum*100+testnum1)){
                        anscase[0]=8;
                        casefound[8]=true;
                        ans[0]=testnum;
                        ans[1]=testnum1;
                        if(cycfig(2,testnum))
                            return true;
                        casefound[8]=false;
                    }
                }
            }
            break;
        case 2:
        case 3:
        case 4:
        case 5:
            for(testnum=minbound;testnum<100;testnum++){
                ans[stage]=testnum;
                for(testcase=3;testcase<9;testcase++){
                    if(casefound[testcase]==false){
                        switch(testcase){
                            case 3:
                                if(triangle(ans[stage-1]*100+ans[stage])){
                                    anscase[stage-1]=3;
                                    casefound[3]=true;
                                    if(cycfig(stage+1,minbound))
                                        return true;
                                    casefound[3]=false;
                                }
                                break;
                            case 4:
                                if(square(ans[stage-1]*100+ans[stage])){
                                    anscase[stage-1]=4;
                                    casefound[4]=true;
                                    if(cycfig(stage+1,minbound))
                                        return true;
                                    casefound[4]=false;
                                }
                                break;
                            case 5:
                                if(pentagonal(ans[stage-1]*100+ans[stage])){
                                    anscase[stage-1]=5;
                                    casefound[5]=true;
                                    if(cycfig(stage+1,minbound))
                                        return true;
                                    casefound[5]=false;
                                }
                                break;
                            case 6:
                                if(hexagonal(ans[stage-1]*100+ans[stage])){
                                    anscase[stage-1]=6;
                                    casefound[6]=true;
                                    if(cycfig(stage+1,minbound))
                                        return true;
                                    casefound[6]=false;
                                }
                                break;
                            case 7:
                                if(heptagonal(ans[stage-1]*100+ans[stage])){
                                    anscase[stage-1]=7;
                                    casefound[7]=true;
                                    if(cycfig(stage+1,minbound))
                                        return true;
                                    casefound[7]=false;
                                }
                                break;
                            case 8:
                                if(octagonal(ans[stage-1]*100+ans[stage])){
                                    anscase[stage-1]=8;
                                    casefound[8]=true;
                                    if(cycfig(stage+1,minbound))
                                        return true;
                                    casefound[8]=false;
                                }
                                break;
                            default: break;
                        }
                    }
                }
            }
            break;
        case 6:
            for(testcase=3;testcase<9;testcase++){
                if(!casefound[testcase]){
                    anscase[5]=testcase;
                    break;
                }
            }
            switch(testcase){
                case 3:
                    if(triangle(ans[5]*100+ans[0]))
                        return true;
                    break;
                case 4:
                    if(square(ans[5]*100+ans[0]))
                        return true;
                    break;
                case 5:
                    if(pentagonal(ans[5]*100+ans[0]))
                        return true;
                    break;
                case 6:
                    if(hexagonal(ans[5]*100+ans[0]))
                        return true;
                    break;
                case 7:
                    if(heptagonal(ans[5]*100+ans[0]))
                        return true;
                    break;
                case 8:
                    if(octagonal(ans[5]*100+ans[0]))
                        return true;
                    break;
                default: break;
            }
            break;
        default: return false;
    }
    return false;
}

bool triangle(int num)
{
    double root;
    root=(-1+sqrt(1+8*num))/2;
    if(root==((int)root)) return true;
    return false;
}

bool square(int num)
{
    double root;
    root=sqrt(num);
    if(root==((int)root)) return true;
    return false;
}

bool pentagonal(int num)
{
    double root;
    root=(1+sqrt(1+24*num))/6;
    if(root==((int)root)) return true;
    return false;
}

bool hexagonal(int num)
{
    double root;
    root=(1+sqrt(1+8*num))/4;
    if(root==((int)root)) return true;
    return false;
}

bool heptagonal(int num)
{
    double root;
    root=(3+sqrt(9+40*num))/10;
    if(root==((int)root)) return true;
                    return false;
}

bool octagonal(int num)
{
    double root;
    root=(2+sqrt(4+12*num))/6;
    if(root==((int)root)) return true;
    return false;
}
