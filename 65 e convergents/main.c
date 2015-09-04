#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num[1000];
    int den[1000];
    int digitidx;
    int a;
    int carry;
    int temp;
    int sum=0;

    for(digitidx=0;digitidx<1000;digitidx++){
        num[digitidx]=den[digitidx]=0;
    }
    den[0]=1;

    for(a=33;a>=1;a--){
        for(digitidx=0,carry=0;digitidx<1000;digitidx++){
            temp=num[digitidx]+carry+den[digitidx];
            carry=temp/10;
            num[digitidx]=den[digitidx];
            den[digitidx]=temp%10;
        }
        for(digitidx=0,carry=0;digitidx<1000;digitidx++){
            temp=num[digitidx]+carry+den[digitidx]*2*a;
            carry=temp/10;
            num[digitidx]=den[digitidx];
            den[digitidx]=temp%10;
        }
        for(digitidx=0,carry=0;digitidx<1000;digitidx++){
            temp=num[digitidx]+carry+den[digitidx];
            carry=temp/10;
            num[digitidx]=den[digitidx];
            den[digitidx]=temp%10;
        }
    }
    for(digitidx=0,carry=0;digitidx<1000;digitidx++){
            temp=num[digitidx]+carry+den[digitidx]*2;
            num[digitidx]=temp%10;
            carry=temp/10;
            sum+=num[digitidx];
            printf("%d",num[digitidx]);
    }
    printf("\n%d",sum);

    return 0;
}
