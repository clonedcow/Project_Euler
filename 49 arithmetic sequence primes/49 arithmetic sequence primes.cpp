//49 arithmetic sequence primes
#include<iostream>
using namespace std;

bool SameDigits(int digits[4],int n)
{
    int digit,used[4],index;
    
    for(int i=0;i<4;i++)
        used[i]=0;
    
    for(;n>0;n/=10){
        digit=n%10;
        for(index=0;index<4;index++){
            if((digits[index]==digit)&&(used[index]==0)){
                used[index]=1;
                break;
            }
            else if(index==3){
                return 0;
            }
        }
    }
    return 1;
}

int main()
{
    int index,mod,temp,prime1,prime2,prime3,digits[4];
    bool prime[10000],done=0;
    prime[0]=0;
    prime[1]=0;
    
    for(index=2;index<10000;index++){
        prime[index]=1;
        for(mod=2;(mod*mod)<=index;mod++){
            if(index%mod==0)
                prime[index]=0;
        }
    }
    
    for(prime1=2000;prime1<10000;prime1++){
        if(prime[prime1]==1){
            index=3;
            for(temp=prime1;index>=0;temp/=10){//getting digits used
                digits[index]=temp%10;
                index--;
            }

            /*for(int i=0;i<4;i++){DEBUG:see if the digits stored are correct
                cout<<digits[0][i]; 
            }
            system("pause");*/
            
            for(prime2=prime1+2;(2*prime2-prime1)<10000;prime2++){
                if((prime[prime2]==1)&&SameDigits(digits,prime2)){
                    /*cout<<prime1<<","<<prime2<<"\n";
                    system("pause");*/
                    prime3=2*prime2-prime1;
                    if((prime[prime3]==1)&&SameDigits(digits,prime3))
                        done=1;
                }
                if(done==1)
                    break;
            }
        }
        if(done==1)
            break;
    }
    
    cout<<prime1<<prime2<<prime3;
    system("pause");
    return 0;
}
