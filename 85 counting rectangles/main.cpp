#include <iostream>

using namespace std;

int main()
{
    int h,w=1415,minDif=1000000,bestH,bestW;
    for(h=1;(h-1)*(h-1)*h*h<8000000;h++)
    {
        while(h*(h+1)*w*(w+1)>8000000)
        {
            if(h*(h+1)*w*(w+1)-8000000<minDif)
            {
                bestH=h;
                bestW=w;
                minDif=h*(h+1)*w*(w+1)-8000000;
            }

            w--;
        }
        if(8000000-h*(h+1)*w*(w+1)<minDif)
        {
            bestH=h;
            bestW=w;
            minDif=8000000-h*(h+1)*w*(w+1);
        }
    }
    cout<<bestH*bestW;
    return 0;
}
