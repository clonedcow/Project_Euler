#include <iostream>
using namespace std;

#define R_LEN 2
#define G_LEN 3
#define B_LEN 4
#define ROW_LEN 50

int main()
{
    long long tilings[ROW_LEN+1]={0};
    tilings[0]=1;

    for(int i=1;i<=ROW_LEN;i++){
        tilings[i]+=tilings[i-1];
        tilings[i]+=(i-R_LEN>=0)?tilings[i-R_LEN]:0;
        tilings[i]+=(i-G_LEN>=0)?tilings[i-G_LEN]:0;
        tilings[i]+=(i-B_LEN>=0)?tilings[i-B_LEN]:0;
    }

    cout<<tilings[ROW_LEN];
    return 0;
}
