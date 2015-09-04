//48: final 10 digits
#include<stdio.h>

int main()
{
    unsigned int product1,product2,sum1=0,sum2=0;
    
    for(int base=1;base<=999;base++)
    {
        product1=0;
        product2=base;
        
        for(int power=2;power<=base;power++)
        {
            product1*=base;
            product2*=base;
            product1+=(product2/100000);//transferring carry
            product1=product1%100000;
            product2=product2%100000;
        }
        
        sum1+=product1;
        sum2+=product2;
        sum1+=(sum2/100000);
        sum1=sum1%100000;
        sum2=sum2%100000;
    }
    
    printf("%d%d",sum1,sum2);
    scanf("%d",&sum1);
    return 0;
}
