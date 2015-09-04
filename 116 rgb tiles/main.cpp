#include <iostream>
using namespace std;

#define R_LEN 2
#define G_LEN 3
#define B_LEN 4
#define ROW_LEN 50

int main()
{
    long long r[ROW_LEN+1]={0};
    long long g[ROW_LEN+1]={0};
    long long b[ROW_LEN+1]={0};

    for(int i=0;i<R_LEN;i++) r[i]=1;
    for(int i=0;i<G_LEN;i++) g[i]=1;
    for(int i=0;i<B_LEN;i++) b[i]=1;

    for(int i=R_LEN;i<=ROW_LEN;i++) r[i]=r[i-1]+r[i-R_LEN];
    for(int i=G_LEN;i<=ROW_LEN;i++) g[i]=g[i-1]+g[i-G_LEN];
    for(int i=B_LEN;i<=ROW_LEN;i++) b[i]=b[i-1]+b[i-B_LEN];

    cout<<r[ROW_LEN]+g[ROW_LEN]+b[ROW_LEN]-3;
    return 0;
}
