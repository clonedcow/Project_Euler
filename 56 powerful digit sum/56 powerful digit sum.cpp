//56 powerful digit sum
#include <iostream>
using namespace std;

int main()
{
    int digits[200],num_digits,best_base,best_pow,best_sum=0; // num_digits is actually number of digits minus 1
    
    for(int base=2;base<100;base++){    // go through each base
        for(int index=0;index<200;index++) digits[index]=0;    // for each base clear array
        
        digits[0]=base%10;                                     // set digits to base
        digits[1]=base/10;
        
        if(digits[1]!=0) num_digits=1;                         // find the number of digits in base
        else num_digits=0;
        
        for(int pow=2,sum=0;pow<=100;pow++){                   // go through each power
            for(int index=num_digits;index>=0;index--)         // go through each digit
                digits[index]*=base;
            
            for(int index=0;index<=num_digits+2;index++){      // take care of carries
                digits[index+1]+=digits[index]/10;
                digits[index]%=10;
            }    
            
            if(digits[num_digits+2]!=0) num_digits+=2;         // find the new number of digits
            else if(digits[num_digits+1]!=0) num_digits++;
            
            sum=0;                                             // clear sum
            for(int index=0;index<=num_digits;index++) sum+=digits[index]; // find the sum of the digits
            
            if(sum>best_sum){ // if the sum is bigger than a previous sum record base, power, and new sum
                best_sum=sum;
                best_base=base;
                best_pow=pow;
            }
        }
    }
    
    cout<<best_sum;
    system("pause");
    return 0;
}
