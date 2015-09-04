//32 pandigital product
#include<stdio.h>
#include<iostream>
using namespace std;

int main()
{
    int index,n1,n2,n3,n4,n5,n6,n7,n8,d1,d2,d3,d4,d5,d6,d7,d8,d9,mult1,mult2,product,sum=0;//keeps track of nth available digit to use and that digit
    bool digitused[10];
    digitused[0]=1;
    
    for(index=1;index<=9;index++){digitused[index]=0;}
    
    for(n1=1;n1<=9;n1++){
        for(index=n1,d1=1;index>0;d1++){if(digitused[d1]==0)index--;}d1--;digitused[d1]=1;//printf("%d",d1);
        for(n2=1;n2<=8;n2++){
            for(index=n2,d2=1;index>0;d2++){if(digitused[d2]==0)index--;}d2--;digitused[d2]=1;//printf("%d",d2);
            for(n3=1;n3<=7;n3++){
                for(index=n3,d3=1;index>0;d3++){if(digitused[d3]==0)index--;}d3--;digitused[d3]=1;//printf("%d",d3);
                for(n4=1;n4<=6;n4++){
                    for(index=n4,d4=1;index>0;d4++){if(digitused[d4]==0)index--;}d4--;digitused[d4]=1;//printf("%d",d4);             
                    for(n5=1;n5<=5;n5++){
                        for(index=n5,d5=1;index>0;d5++){if(digitused[d5]==0)index--;}d5--;digitused[d5]=1;//printf("%d",d5);
                        for(n6=1;n6<=4;n6++){
                            for(index=n6,d6=1;index>0;d6++){if(digitused[d6]==0)index--;}d6--;digitused[d6]=1;//printf("%d",d6);
                            for(n7=1;n7<=3;n7++){
                                for(index=n7,d7=1;index>0;d7++){if(digitused[d7]==0)index--;}d7--;digitused[d7]=1;//printf("%d",d7);
                                for(n8=1;n8<=2;n8++){
                                    for(index=n8,d8=1;index>0;d8++){if(digitused[d8]==0)index--;}d8--;digitused[d8]=1;//printf("%d",d8);
                                    d9=1;
                                    while(digitused[d9]==1){d9++;}//printf("%d\n",d9);
                                    
                                    //system("pause");
                                    
                                    mult1=10*d1+d2;
                                    mult2=100*d3+10*d4+d5;
                                    product=1000*d6+100*d7+10*d8+d9;
                                    if((mult1*mult2)==product){
                                        sum+=product;
                                        printf("%d\n",product);
                                    }
                                    mult1=d1;
                                    mult2=1000*d2+100*d3+10*d4+d5;
                                    product=1000*d6+100*d7+10*d8+d9;
                                    if((mult1*mult2)==product){
                                        sum+=product;                       
                                        printf("%d\n",product);
                                    }
                                                                                                               
                                    digitused[d8]=0;
                                }
                                digitused[d7]=0;
                            }
                            digitused[d6]=0;
                        }
                        digitused[d5]=0;
                    }
                    digitused[d4]=0;
                }
                digitused[d3]=0;
            }
            digitused[d2]=0;           
        }
        digitused[d1]=0;
    }
    
    printf("%d",sum);
    scanf("%d",&d1);
    return 0;
}
