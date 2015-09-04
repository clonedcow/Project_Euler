#include<stdio.h>
#include<math.h>
   
int prime[1000];

void fillprime()
{    
    int testprime=5,testndx;
    bool isprime=0;
    prime[0]=2,prime[1]=3;
    
    
    for(int fillarray=2;fillarray<1000;fillarray++)
    {
        prime[fillarray]=0;
    }
    
    for(int arrayndx=2;arrayndx<1000;arrayndx++)/*move along in the array that stores primes after finding a prime*/
    {                                           
        for(isprime=0;isprime==0;testprime+=2)/*stay in same array space as long as there's no prime*/
        {                               
            for(testndx=1,isprime=1;(sqrt(prime[testndx])<=testprime)&&(prime[testndx]!=0);testndx++)/*check if a number is prime*/
            {                                                                                       
                if((testprime%prime[testndx])==0)
                {
                    isprime=0;
                    break;
                }
            }
            
            if(isprime==1)/*if it is prime add it to the prime array*/      
            {
                prime[arrayndx]=testprime;
            }
        }
    }
}

bool testprime(int n)
{
    for(int index=0;prime[index]*prime[index]<=n;index++){
        if((n%prime[index])==0)
            return 0;
    }
    return 1;
}

int rotatenum(int n,int digitcount)
{
    switch(digitcount){
    case 2:n=n/10+10*(n%10);break;
    case 3:n=n/10+100*(n%10);break;
    case 4:n=n/10+1000*(n%10);break;
    case 5:n=n/10+10000*(n%10);break;
    case 6:n=n/10+100000*(n%10);break;
    default:break;
    }
    
    return n;
}

int main()
{
    int d1,d2,d3,d4,d5,d6,test,vartest,digitcount,rotation,total=0;
    bool valid;
    
    fillprime();
    
    for(d1=0;d1<=9;d1+=2){//only numbers with odd digits need to be tested
        for(d2=0;d2<=9;d2+=2){if((d2==0)&&(d1!=0))d2=1;
            for(d3=0;d3<=9;d3+=2){if((d3==0)&&(d2!=0))d3=1;
                for(d4=0;d4<=9;d4+=2){if((d4==0)&&(d3!=0))d4=1;
                    for(d5=0;d5<=9;d5+=2){if((d5==0)&&(d4!=0))d5=1;                        
                        for(d6=1;d6<=9;d6+=2){
                            test=100000*d1+10000*d2+1000*d3+100*d4+10*d5+d6;
                            vartest=test;
                            valid=1;
                            digitcount=0;
                            
                            do{//find the number of digits
                            vartest/=10;
                            digitcount++;
                            }while(vartest!=0);
                            
                            for(rotation=1,vartest=test;rotation<digitcount;rotation++){
                                vartest=rotatenum(vartest,digitcount);
                                if(vartest<test){
                                    valid=0;
                                    break;
                                }
                            }
                            if(valid==0)
                                continue;
                            if(!testprime(test))
                                continue;
                             
                            for(rotation=1,vartest=test;rotation<digitcount;rotation++){//forgot that rotations for numbers without 6 digits are different
                                vartest=rotatenum(vartest,digitcount);
                                if(!testprime(vartest)){
                                    valid=0;
                                    break;
                                } 
                            }
                            
                            if(valid==1){
                                printf("%d\n",test);
                                total+=digitcount;
                            }
                        }
                        if(d5==0)d5--;    
                    }
                    if(d4==0)d4--;
                }
                if(d3==0)d3--;
            }
            if(d2==0)d2--;        
        }
        if(d1==0)d1--;        
    }
    
    printf("%d",total);
    scanf("%d",&total);
    return 0;
}
