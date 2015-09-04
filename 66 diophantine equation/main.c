#include <stdio.h>
#include <stdlib.h>
#include <math.h>

static int a[1000];
static int numcoef,dencoef;

int invert(int D, int nc,int dc,int wn);
int gcf(int a,int b);

int main()
{
    int D=0,bestD=0;
    int wholenum=0,startden=0;
    int period=0;
    int convergent=1;
    int convidx=0;
    int numerator[1000],denominator[1000];
    int highx[1000];
    int fracidx=0;
    int temp=0,carry=0;
    int x2[2000],y2[2000];
    int digit1=0,digit2=0;
    int bigger=0;

    for(digit1=0;digit1<1000;digit1++) highx[digit1]=0;

    for(D=2;D<1000;D++){
        a[0]=sqrt(D);
        if(a[0]*a[0]==D) continue;
        invert(D,1,1,a[0]);
        startden=dencoef;
        wholenum=a[0];
        period=0;
        do{
            period++;
            a[period]=(sqrt(D)+wholenum)*numcoef/dencoef;
            wholenum=dencoef*a[period]-wholenum;
            invert(D,numcoef,dencoef,wholenum);
        }while(!((dencoef==startden)&&(numcoef==1)&&(wholenum==a[0])));

        /*printf("\n%d\n%d\n",D,period); // printing the continued fractions
        for(fracidx=0;fracidx<=period;fracidx++){
            printf("%d,",a[fracidx]);
        }
        printf("\n");*/

        for(convergent=1;1;convergent++){
            for(fracidx=0;fracidx<1000;fracidx++) numerator[fracidx]=denominator[fracidx]=0;
            for(fracidx=0;fracidx<2000;fracidx++) x2[fracidx]=y2[fracidx]=0;
            denominator[0]=1;
            for(convidx=convergent;convidx>=1;convidx--){
                carry=0;
                for(fracidx=0;fracidx<1000;fracidx++){
                    temp=denominator[fracidx]*a[((convidx-1)%period)+1]+numerator[fracidx]+carry;
                    carry=temp/10;
                    numerator[fracidx]=denominator[fracidx];
                    denominator[fracidx]=temp%10;
                }
            }

            for(fracidx=0,carry=0;fracidx<1000;fracidx++){
                temp=denominator[fracidx]*a[0]+numerator[fracidx]+carry;
                carry=temp/10;
                numerator[fracidx]=temp%10;
            }

            /*for(fracidx=9;fracidx>=0;fracidx--) printf("%d",numerator[fracidx]);
            printf("/");
            for(fracidx=9;fracidx>=0;fracidx--) printf("%d",denominator[fracidx]);
            printf("\n");*/

            for(digit1=0;digit1<1000;digit1++){
                for(digit2=0;digit2<1000;digit2++){
                    x2[digit1+digit2]+=numerator[digit1]*numerator[digit2];
                    y2[digit1+digit2]+=denominator[digit1]*denominator[digit2];
                }
            }
            for(digit1=0;digit1<1999;digit1++){
                x2[digit1+1]+=x2[digit1]/10;
                x2[digit1]=x2[digit1]%10;
                y2[digit1+1]+=y2[digit1]/10;
                y2[digit1]=y2[digit1]%10;
            }
            x2[1999]=x2[1999]%10;
            y2[1999]=y2[1999]%10;

            /*for(digit1=4;digit1>=0;digit1--) printf("%d",x2[digit1]);
            printf("/");
            for(digit1=4;digit1>=0;digit1--) printf("%d",y2[digit1]);
            printf("\n");*/

            y2[0]=y2[0]*D+1;
            for(digit1=1;digit1<2000;digit1++){
                y2[digit1]=y2[digit1]*D+(y2[digit1-1]/10);
                y2[digit1-1]=y2[digit1-1]%10;
            }
            for(digit1=0;digit1<2000&&x2[digit1]==y2[digit1];digit1++);
            if(digit1==2000) break;
        }
        for(digit1=999;digit1>=0&&numerator[digit1]==highx[digit1];digit1--);
        if(numerator[digit1]>highx[digit1]){
            bestD=D;
            for(digit2=0;digit2<=digit1;digit2++) highx[digit2]=numerator[digit2];
        }
    }
    printf("%d",bestD);
    return 0;
}

int invert(int D,int nc,int dc,int wn)
{
    int GCF;
    numcoef=dc;
    dencoef=nc*(D-wn*wn);
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

