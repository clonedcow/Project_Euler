//23: abundant numbers
#include<stdio.h>
#include<math.h>

int main()
{
    int abt[9001],tstabt=2,tstfctr,sumfctr;
    bool isabt;
    
    //
    //create array of abundant numbers
    //
    
    for(int abttstndx=0;abttstndx<9001;abttstndx++)//iterate through array
    {
        for(isabt=0;isabt==0;tstabt++)//test next number as long as number isn't abundant
        {                                 
            for(tstfctr=2,sumfctr=1;tstfctr<=sqrt(tstabt);tstfctr++)//test if number is abundant
            {
                if((tstabt%tstfctr)==0)
                    sumfctr=sumfctr+tstfctr+(tstabt/tstfctr);
            }
            
            if(pow(tstfctr-1,2)==tstabt)//avoid double counting square roots of numbers
                sumfctr=sumfctr-(tstfctr-1);
            
            if(sumfctr>tstabt)//add it to array if it is
            {
                abt[abttstndx]=tstabt;
                isabt=1;
            }
        }
    }
    
    /*for(int display=0;display<20;display++) //displays some abundant numbers
    {
        printf("%d\n",abt[display]);
    }*/
    
    //
    //rest of the code is to test if a number is the sum of two abundant numbers
    //
    
    int sumtstndx,df,dfndx;
    bool issum;
    long sumfails=0;
    
    for(int tstsumabt=1;tstsumabt<=28123;tstsumabt++)//testing each number for sum of abundancy
    {
        issum=0;
        for(sumtstndx=0,df=0;abt[sumtstndx]<=(tstsumabt/2);sumtstndx++)
        {
            df=tstsumabt-abt[sumtstndx];//difference between number we're testing and an abundant number
            
            for(dfndx=sumtstndx;abt[dfndx]<=df;dfndx++)
            {
                if(df==abt[dfndx])
                {
                    issum=1;
                    break;
                }
            }
            
            if(issum==1)
                break;    
        }
        
        if(issum==0)
        {
            sumfails+=tstsumabt;
            //printf("%d %d\n",tstsumabt,sumfails);
        }
    }
    
    printf("%d",sumfails);
    scanf("%d",&tstabt);
    return 0;
}
