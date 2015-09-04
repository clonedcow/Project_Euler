#include <iostream>
#include <stdio.h>
#include <math.h>
#include "prime number list.cpp"
using namespace std;

int find_length(int num);

int main()
{
    int ndx[5],len[5],i,j;
    FillPrime();
    
    for(ndx[0]=5;ndx[0]<PrimeCount;ndx[0]++){
        len[0]=find_length(prime[ndx[0]]);
        for(ndx[1]=4;ndx[1]<ndx[0];ndx[1]++){
            len[1]=find_length(prime[ndx[1]]);
            for(ndx[2]=3;ndx[2]<ndx[1];ndx[2]++){
                len[2]=find_length(prime[ndx[2]]);
                for(ndx[3]=2;ndx[3]<ndx[2];ndx[3]++){
                    len[3]=find_length(prime[ndx[3]]);
                    for(ndx[4]=1;ndx[4]<ndx[3];ndx[4]++){
                        len[4]=find_length(prime[ndx[4]]);
                        
                        for(i=1;i<5;i++){
                            for(j=0;j<i;j++){
                                if(prime[ndx[i]]+prime[ndx[j]]*(int)pow(10,len[i])>1000000000){cout<<prime[ndx[i]]+prime[ndx[j]]*(int)pow(10,len[i])<<"omfg\n";system("pause");}
                                if(!IsPrime(prime[ndx[i]]+prime[ndx[j]]*(int)pow(10,len[i]))||!IsPrime(prime[ndx[j]]+prime[ndx[i]]*(int)pow(10,len[j]))) break;
                            }
                            if(j!=i) break;
                        }
                        if(i==5&&j==4){
                            cout<<prime[ndx[0]]<<","<<prime[ndx[1]]<<","<<prime[ndx[2]]<<","<<prime[ndx[3]]<<","<<prime[ndx[4]];
                            system("pause");
                            return 0;
                        }
                        
                        if(i<4&&j<4)break;
                    }
                    if(i<3&&j<3)break;
                }
                if(i<2&&j<2)break;
            }
        }
    }
    
    cout<<prime[PrimeCount-1];
    system("pause");
    return 0;
}

int find_length(int num)
{
    int length=0;
    while(num!=0){
        num/=10;
        length++;
    }
    return length;
}
