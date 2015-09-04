//sqrt(n)=a0+1/(a1+1/(a2+1/(a3+...)))
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int a[1000];
static int numcoef,dencoef;

int invert(int base, int nc,int dc,int wn);
int gcf(int a,int b);

int main()
{
    int i;
    int base=0;
    int wholenum=0,startden=0;
    int aindex;
    int oddperiodcnt=0;

    for(base=2;base<10;base++){
        a[0]=sqrt(base);
        if(a[0]*a[0]==base) continue;
        invert(base,1,1,a[0]);
        startden=dencoef;
        wholenum=a[0];
        aindex=0;
        do{
            aindex++;
            a[aindex]=(sqrt(base)+wholenum)*numcoef/dencoef;
            wholenum=dencoef*a[aindex]-wholenum;
            invert(base,numcoef,dencoef,wholenum);
        }while(!((dencoef==startden)&&(numcoef==1)&&(wholenum==a[0])));
        oddperiodcnt+=aindex%2;

        printf("%d\n",base);
        for(i=0;i<=aindex;i++){
            printf("%d,",a[i]);
        }
        printf("\n\n");
    }
    printf("\n\n%d",oddperiodcnt);
    return 0;
}

int invert(int base,int nc,int dc,int wn)
{
    int GCF;
    numcoef=dc;
    dencoef=nc*(base-wn*wn);
    GCF=gcf(numcoef,dencoef);
    numcoef/=GCF;
    dencoef/=GCF;
    return 0;
}

int gcf(int a,int b)
{
    int temp,remainder;
    if(b>a){
        temp=b;
        b=a;
        a=temp;
    }
    do{
        remainder=a-a/b*b;
        a=b;
        b=remainder;
    }while(remainder>0);
    return a;
}
