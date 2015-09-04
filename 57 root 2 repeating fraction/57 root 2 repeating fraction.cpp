//57 root 2 repeating fraction
#include<iostream>
#define root2 1.41421
using namespace std;

int main()
{
    float num;
    int iteration,total;
    for(num=3,iteration=1,total=0;iteration<=1000;iteration++,num*=root2){
        if(num>=10){
            num/=10;
        }
        if(num<=root2){
            //cout<<iteration<<","<<num;
            //system("pause");
            total++;
        }
    }
    
    cout<<total;
    system("pause");
    return 0;
}
