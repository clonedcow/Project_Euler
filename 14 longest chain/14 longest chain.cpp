/*14*/
#include <stdio.h>

int main()
{
    unsigned int originaln,n,bestn=0,counter,maxcounter=0;
    
    for(originaln=500000;originaln<1000000;originaln=originaln+1)/*going through each number*/
    {
        n=originaln;/*stores in another variable to operate on*/
        counter=0;/*reset counter for new n*/
        
        do/*keep adding to counter while n isn't 1*/
        {
            if((n%2)==0)
            {
            n=n/2;
            }
            else
            {
            n=3*n+1;
            }
            counter=counter+1;
        }while(n!=1);
        
        if(counter>maxcounter)/*if the counter is longest make it new longest counter and also change n*/
        {
            maxcounter=counter;
            bestn=originaln;
        }     
    }
    printf("%d %d",bestn,maxcounter);
    scanf("%d",n);
    
    return 0;
}
