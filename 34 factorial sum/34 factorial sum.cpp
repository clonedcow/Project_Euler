//34 factorial sum
#include<stdio.h>

int main()
{
    int product,test,remainder,factorialsum,totalsum=0,factorial[10];
    
    factorial[0]=1; 
    for(int base=1;base<=9;base++){
        factorial[base]=factorial[base-1]*base;//current factorial is just previous factorial times current number
    }
    //for(int i=0;i<=9;i++){printf("%d\n",factorial[i]);}
    
    for(test=11;test<10000000;test++){
        factorialsum=0;
        remainder=test;
        
        do{
            factorialsum+=factorial[remainder%10];
            remainder=remainder/10;
        }while((remainder!=0)&&(factorialsum<=test));
        
        if(factorialsum==test){
            printf("%d\n",test);
            totalsum+=test;
        }
    }
    
    printf("%d",totalsum);
    scanf("%d",test);
    return 0;
}
