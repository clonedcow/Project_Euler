#include <iostream>

using namespace std;

bool remGreater(int* rem,int* testRem,int digits);
int findDig(int* sqrt,int* rem,int digFnd);

int main()
{
    int sqrt[100];
    int rem[199];
    int tot=0,sum;

    int base,digFnd;

    for(base=1;base<100;base++)
    {
        //cout<<base<<endl;

        for(int i=1;i<199;i++) rem[i]=0;
        for(int i=0;i<100;i++) sqrt[i]=0;

        rem[0]=base;
        sum=0;

        for(digFnd=0;digFnd<100;digFnd++)
        {
            sum+=findDig(sqrt,rem,digFnd);
        }

        if(sqrt[0]*sqrt[0]==base) tot-=sqrt[0];
        tot+=sum;
        //cout<<"="<<sum<<endl;
    }
    cout<<tot;
    return 0;
}

int findDig(int* sqrt,int* rem,int digFnd)
{
    int testDig,digPow,digIdx;
    int testRem[199];

    for(testDig=9;testDig>=0;testDig--)
    {
        for(digIdx=0;digIdx<199;digIdx++)
            testRem[digIdx]=0;

        testRem[2*digFnd]=testDig*testDig;

        if(digFnd>0)
        {
            testRem[2*digFnd-1]=testRem[2*digFnd]/10;
            testRem[2*digFnd]%=10;
        }

        for(digPow=digFnd-1;digPow>=0;digPow--)
        {
            testRem[digPow+digFnd]+=sqrt[digPow]*2*testDig;
            if(digPow+digFnd>0)
            {
                testRem[digPow+digFnd-1]+=testRem[digPow+digFnd]/10;
                testRem[digPow+digFnd]%=10;
            }
        }

        if(digFnd-1>0)
        {
            testRem[digFnd-2]+=testRem[digFnd-1]/10;
            testRem[digFnd-1]%=10;
        }

        if(remGreater(rem,testRem,2*digFnd))
        {
            //cout<<testDig;
            /*for(int i=0;i<199;i++) cout<<rem[i];
            cout<<endl;
            for(int i=0;i<199;i++) cout<< testRem[i];
            cout<<endl;*/

            sqrt[digFnd]=testDig;

            for(digIdx=2*digFnd;digIdx>=0;digIdx--)
            {
                rem[digIdx]-=testRem[digIdx];
                if(rem[digIdx]<0)
                {
                    rem[digIdx]+=10;
                    rem[digIdx-1]--;
                }
            }
            return testDig;
        }
    }
}

bool remGreater(int* rem,int* testRem,int digits)
{
    int digIdx;

    for(digIdx=0;digIdx<=digits;digIdx++)
    {
        if(rem[digIdx]!=testRem[digIdx])
        {
            if(rem[digIdx]>testRem[digIdx]) return true;
            return false;
        }
    }
    return true;
}
