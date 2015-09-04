//38 best right triangle perimeter
#include<iostream>
using namespace std;

int main()
{
    int hiTriCount=0,curTriCount,bestP=0,side1,side2,side3;
    for(int p=3;p<=1000;p++){//start with perimeter 3
        curTriCount=0;    
        for(side1=1;side1<=p/3;side1++){//side 1 is the shorter leg
            for(side2=side1+1;side2<=((p-side1)/2);side2++){//side 2 is the longer leg
                side3=p-side1-side2;//side 3 is the hypotenuse
                if(((side1*side1)+(side2*side2))==(side3*side3))//testing if it's a right triangle
                    curTriCount++;//number of right triangles for particular p increases by 1
            }
        }
        if(curTriCount>hiTriCount){//change the perimeter with most right triangles and the number of triangles to beat
            hiTriCount=curTriCount;
            bestP=p;
        }
    }
    
    cout<<bestP<<"\n";
    system("pause");
    return 0;
}
