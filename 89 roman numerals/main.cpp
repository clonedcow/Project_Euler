#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int rtod(char rom);

int main()
{
    int num[1000];
    int origTot=0,newTot=0,numIdx,cur,next,curVal;
    bool masMil;
    string curNum;
    ifstream numFile("roman numerals.txt");
    if(!numFile.is_open())
        cout<<"couldn't open file!";
    else
    {
        while(getline(numFile,curNum))
        {
            origTot+=curNum.size();

            for(numIdx=0,curVal=0;numIdx<curNum.size()-1;numIdx++)
            {
                cur=rtod(curNum[numIdx]);
                next=rtod(curNum[numIdx+1]);
                if(cur<next) curVal-=cur;
                else curVal+=cur;
            }
            curVal+=rtod(curNum[numIdx]);

            masMil=curVal>1000;
            while(curVal!=0)
            {
                cur=curVal%10;
                curVal/=10;

                if((cur==4 || cur==9) && (curVal!=0 || !masMil))
                    newTot+=2;
                else newTot+=(cur%5)+cur/5;
            }
        }
        numFile.close();
    }

    cout<<origTot-newTot;
    return 0;
}

int rtod(char rom)
{
    switch(rom)
    {
        case 'I':return 1;
        case 'V':return 5;
        case 'X':return 10;
        case 'L':return 50;
        case 'C':return 100;
        case 'D':return 500;
        case 'M':return 1000;
    }
    return 0;
}
