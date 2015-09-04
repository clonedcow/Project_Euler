#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define maxbase 30000

int main()
{
    int numdigits[maxbase][11];
    int compi=0;
    int base=1;
    long long remainder=0;
    int minbound=0;
    int ans[10];
    int numcubeperm=0;
    int i,j;

    for(i=0;i<maxbase;i++){
        for(j=0;j<11;j++){
            numdigits[i][j]=0;
        }
    }

    while(base<maxbase){
        remainder=(long long)base*base*base;
        ans[0]=base;
        while(remainder!=0){
            numdigits[base][remainder%10]++;
            numdigits[base][10]++;
            remainder/=10;
        }
        if(numdigits[base][10]!=numdigits[base-1][10]){
            minbound=base;
            base++;
            continue;
        }
        for(compi=minbound,numcubeperm=1;compi<base;compi++){
            for(i=0;i<10;i++){
                if(numdigits[base][i]!=numdigits[compi][i]) break;
            }
            if(i==10){
                ans[numcubeperm]=compi;
                numcubeperm++;
            }
        }
        if(numcubeperm==5){
            for(i=0;i<5;i++){
                printf("%d,%lld\n",ans[i],(long long)ans[i]*ans[i]*ans[i]);
            }
            return 0;
        }
        base++;
    }

    return 0;
}
