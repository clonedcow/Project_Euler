#include <stdio.h>
#include <iostream>
using namespace std;
// if you repeat the process of adding a number to its reverse and it never becomes a palindrome, it is a lychrel number.
// find the number of lychrel numbers

int main()
{
    int sum[50],reverse[50],num_digits,temp_base,total=0;   // num_digits is actually the number of digits minus 1, easier to use for arrays
    bool is_lychrel;
    
    for(int base=1;base<10000;base++){                      // go through all the bases
        is_lychrel=1;
        
        for(int i=49;i>0;i--){                              // clear arrays for next base
            sum[i]=0;
            reverse[i]=0;
        }
        temp_base=base;                                     // store base in sum array
        sum[0]=temp_base%10;
        temp_base/=10;
        sum[1]=temp_base%10;
        temp_base/=10;
        sum[2]=temp_base%10;
        temp_base/=10;
        sum[3]=temp_base%10;
        
        if(sum[3]!=0) num_digits=3;                         // find the number of digits the base has
        else if(sum[2]!=0) num_digits=2;
        else if(sum[1]!=0) num_digits=1;
        else num_digits=0;
        
        for(int it=0;it<50;it++){                           // reverse and add 50 times
            for(int rev_it=num_digits;rev_it>=0;rev_it--){  // reverse number and store in reverse
                reverse[rev_it]=sum[num_digits-rev_it];
            }
            
            for(int sum_it=num_digits;sum_it>=0;sum_it--){  // add sum and reverse and store in sum
                sum[sum_it+1]+=(sum[sum_it]+reverse[sum_it])/10;
                sum[sum_it]=(sum[sum_it]+reverse[sum_it])%10;
            }
            
            for(int fix_sum_it=0;fix_sum_it<=num_digits;fix_sum_it++){ // there may be some carries I need to perform after adding
                sum[fix_sum_it+1]+=sum[fix_sum_it]/10;
                sum[fix_sum_it]=sum[fix_sum_it]%10;
            }
            
            if(sum[num_digits+1]!=0) num_digits++; // check if we get an extra digit
            
            for(int pal_it=num_digits/2;pal_it<=num_digits;pal_it++){ // check if the number is a palindrome
                if(sum[pal_it]!=sum[num_digits-pal_it]) break;        // if 2 compared digits don't match it's not a palindrome and we can exit loop
                if(pal_it==num_digits) is_lychrel=0;                  // if we've gone through the whole array and all the digits match we have a palindrome and no lychrel
            }
            
            if(is_lychrel==0) break;
        }
        
        if(is_lychrel==1) total++;
    }
    cout<<total;
    system("pause");
    
    return 0;
}
