//113 non-bouncy/(increasing or decreasing) numbers
#include<iostream>
#include<iomanip>
using namespace std;

#define debug 1
#define n 20

int main()
{
    int total=0,digitCount,difference,prevDifference;
    unsigned int decreasing[101][10];//decreasing[number of digits][difference between first and last digit](increasing array is the same except w/o difference of 9)

    for(digitCount=0;digitCount<=100;digitCount++){//prefill both arrays with 0;
        for(difference=0;difference<=9;difference++){
            decreasing[digitCount][difference]=0;
        }
    } 
    decreasing[1][0]=1;

    for(digitCount=2;digitCount<=100;digitCount++){
        for(difference=0;difference<=9;difference++){
            for(prevDifference=0;prevDifference<=difference;prevDifference++){
                decreasing[digitCount][difference]+=decreasing[digitCount-1][prevDifference];
            }
        }
    }
    
    for(int i=1;i<=n;i++){
        for(difference=0;difference<=9;difference++){
            total+=decreasing[i][difference]*(10-difference);
            total+=decreasing[i][difference]*(9-difference);
        }
    }
    total=total-10*n;
    
    if(debug==1){//number of decreasing numbers for n digit numbers    
        cout<<"difference 1st and last digit:\n";
        for(difference=0;difference<=9;difference++){
                cout<<difference<<setw(10)<<decreasing[n][difference]<<"\n";
        }
        cout<<"\ntotal:"<<total<<"\n";
    }
    
    system("pause");
    return 0;
}
