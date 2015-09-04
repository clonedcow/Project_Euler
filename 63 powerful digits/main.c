#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// pow(1,1) is apparently lower than 1

int numdigits(long long num);

int main()
{
    int base=0,ans=0,power=0;
    for(base=1;base<9;base++,power=1){
        while(numdigits(pow(base,power))==power){
            printf("%d,%d,%f\n",base,power,pow(base,power));
            power++;
            ans++;
        }
    }
    printf("%d",ans);
    return 0;
}

int numdigits(long long num)
{
    int total=0;
    while(num!=0){
        total++;
        num/=10;
    }
    return total;
}
