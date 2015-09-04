//29 distinct powers
#include<stdio.h>

int main()
{
    int i,base,exp,total=0;
    bool base2[601],base3[401];
    
    for(i=0;i<=600;i++)
    {
        base2[i]=0;
    }
    
    for(i=0;i<=400;i++)
    {
        base3[i]=0;
    }
    
    for(base=2;base<=100;base++)
    {
        switch (base)
        {
        case 2:for(exp=2;exp<=100;exp+=1){base2[exp]=1;}break;
        case 4:for(exp=4;exp<=200;exp+=2){base2[exp]=1;}break;
        case 8:for(exp=6;exp<=300;exp+=3){base2[exp]=1;}break;
        case 16:for(exp=8;exp<=400;exp+=4){base2[exp]=1;}break;
        case 32:for(exp=10;exp<=500;exp+=5){base2[exp]=1;}break;
        case 64:for(exp=12;exp<=600;exp+=6){base2[exp]=1;}break;
        case 3:for(exp=2;exp<=100;exp+=1){base3[exp]=1;}break;
        case 9:for(exp=4;exp<=200;exp+=2){base3[exp]=1;}break;
        case 27:for(exp=6;exp<=300;exp+=3){base3[exp]=1;}break;
        case 81:for(exp=8;exp<=400;exp+=4){base3[exp]=1;}break;
        case 25:total+=50;break;
        case 36:total+=50;break;
        case 49:total+=50;break;
        case 100:total+=50;break;
        default:total+=99;break;
        }
        //printf("%d\n",total);
    }
    //printf("%d\n",total);
    
    for(i=0;i<=600;i++)
    {
        //if(base2[i]==1)
            //total++;
        total+=base2[i];
    }
    
    for(i=0;i<=400;i++)
    {
        //if(base3[i]==1)
            //total++;
        total+=base3[i];
    }
    
    printf("%d",total);
    scanf("%d",&base);
    return 0;
}
