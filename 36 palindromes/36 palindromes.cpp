//36 palindromes
#include<iostream>
#include<math.h>
using namespace std;

int genpalindrome1(int remainder)//generates palindrome without repeating middle digit
{
    int palindrome;
    palindrome=remainder;
    remainder/=10;
    while(remainder!=0){  
        palindrome=10*palindrome+remainder%10;
        remainder/=10;
    }
    return palindrome;
}

int genpalindrome2(int remainder)//generates palindrome without middle digit repeated
{
    int palindrome;
    palindrome=remainder;
    while(remainder!=0){
        palindrome=10*palindrome+remainder%10;
        remainder/=10;
    }
    return palindrome;
}

bool binarypalindrome(int palindrome)//test if number is palindromic in binary
{
    if(palindrome%2==0)//if it's even it clearly can't be a palindrome in binary
        return 0;
    
    int digitcount=0,part1=0,part2=0,remainder=palindrome; 
    do{
        part2+=int((remainder%2)*pow(2,digitcount));//inserting first middle digit
        
        if((part1*pow(2,digitcount+1)+part2)<palindrome){
            part1*=2;//inserting that digit again
            part1+=remainder%2;
            
            if((part1*pow(2,digitcount+1)+part2)>=palindrome){
                if((part1*pow(2,digitcount+1)+part2)>palindrome)
                    return 0;
                return 1;
            }
        }
        else{
            if((part1*pow(2,digitcount+1)+part2)>palindrome)
                return 0;
            return 1;
        }
        
        remainder/=2;
        digitcount++;
    }while((part1*pow(2,digitcount)+part2)<palindrome);
}

int main()
{
    int palindrome,sum=0;
    for(int halfpalindrome=1;halfpalindrome<=999;halfpalindrome++){  
        palindrome=genpalindrome1(halfpalindrome);
        /*cout<<palindrome<<"\n";//DEBUG:prints first palindrome
        system("pause");*/
        if(binarypalindrome(palindrome)){
            /*cout<<"palindrome:"<<palindrome<<"\n";//DEBUG:prints again if it's a palindrome
            system("pause");*/
            sum+=palindrome;
        }
                
        palindrome=genpalindrome2(halfpalindrome);
        /*cout<<palindrome<<"\n";//DEBUG:prints second palindrome
        system("pause");*/
        if(binarypalindrome(palindrome)){
            /*cout<<"palindrome:"<<palindrome<<"\n";//DEBUG:prints again if it's a palindrome
            system("pause");*/
            sum+=palindrome;
        }
    }
    
    cout<<sum<<"\n";
    system("pause");
    return 0;
}
