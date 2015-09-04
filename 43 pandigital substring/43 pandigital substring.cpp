//43 pandigital substring divisibility
#include<iostream>
using namespace std;

int main()
{
    int d0,d1,d2,d3,d4,d5,d6,d7,d8,d9,sum1=0,sum2=0;
    bool digitused[10];
    
    for(int i=0;i<=9;i++){
        digitused[i]=0;
    }
    
    for(d0=1;d0<=9;d0++){digitused[d0]=1;
        for(d1=0;d1<=9;d1++){while((digitused[d1]==1)&&(d1<=9)){d1++;}if(d1==10)break;digitused[d1]=1;
            for(d2=0;d2<=9;d2++){while((digitused[d2]==1)&&(d2<=9)){d2++;}if(d2==10)break;digitused[d2]=1;
                for(d3=0;d3<=9;d3++){while((digitused[d3]==1)&&(d3<=9)){d3++;}if(d3==10)break;digitused[d3]=1;
                    for(d4=0;d4<=9;d4++){while((digitused[d4]==1)&&(d4<=9)){d4++;}if(d4==10)break;digitused[d4]=1;
                        for(d5=0;d5<=9;d5++){while((digitused[d5]==1)&&(d5<=9)){d5++;}if(d5==10)break;digitused[d5]=1;
                            for(d6=0;d6<=9;d6++){while((digitused[d6]==1)&&(d6<=9)){d6++;}if(d6==10)break;digitused[d6]=1;
                                for(d7=0;d7<=9;d7++){while((digitused[d7]==1)&&(d7<=9)){d7++;}if(d7==10)break;digitused[d7]=1;
                                    for(d8=0;d8<=9;d8++){while((digitused[d8]==1)&&(d8<=9)){d8++;}if(d8==10)break;digitused[d8]=1;
                                        for(d9=0;digitused[d9]==1;d9++){}
                                            /*cout<<d0<<d1<<d2<<d3<<d4<<d5<<d6<<d7<<d8<<d9<<"\n";
                                            system("pause");*/
                                            if(  (((100*d1+10*d2+d3)%2)==0) 
                                               &&(((100*d2+10*d3+d4)%3)==0)
                                               &&(((100*d3+10*d4+d5)%5)==0)
                                               &&(((100*d4+10*d5+d6)%7)==0) 
                                               &&(((100*d5+10*d6+d7)%11)==0) 
                                               &&(((100*d6+10*d7+d8)%13)==0) 
                                               &&(((100*d7+10*d8+d9)%17)==0)  ){
                                                cout<<d0<<d1<<d2<<d3<<d4<<d5<<d6<<d7<<d8<<d9<<"\n";
                                                sum1+=10000*d0+1000*d1+100*d2+10*d3+d4;
                                                sum2+=10000*d5+1000*d6+100*d7+10*d8+d9;
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
        digitused[d0]=0;
    }
    
    cout<<sum1<<"\n"<<sum2;
    system("pause");
    return 0;    
}
