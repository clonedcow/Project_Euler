//45 triangle pentagonal hexagonal number
#include<iostream>
#include<math.h>
#include<stdio.h>
using namespace std;

int main()
{
    long long Tbase,Pbase,Hbase,h;
    for(Hbase=144;;Hbase++){
        h=Hbase*(2*Hbase-1);
        Pbase=int(sqrt(floor(2*h/3)))+1;
        Tbase=int(sqrt(2*h));
        
        //cout<<h<<","<<Pbase*(3*Pbase-1)/2<<"\n";
        //system("pause");
        if(h==Pbase*(3*Pbase-1)/2){
            break;
        }
    }
    
    cout<<Tbase*(Tbase+1)/2;
    system("pause");
    return 0;
}
