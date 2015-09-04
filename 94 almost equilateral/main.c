#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    long long halfbase,hypotenuse=3,height=0,ans=0;
    for(halfbase=2,hypotenuse=3;halfbase<166666666;halfbase++){
        height=sqrt(hypotenuse*hypotenuse-halfbase*halfbase);
        if(height*height+halfbase*halfbase==hypotenuse*hypotenuse){
            ans+=2*(halfbase+hypotenuse);
            printf("%lld,%lld,%lld\n",halfbase,height,hypotenuse);
        }
        hypotenuse+=2;
        height=sqrt(hypotenuse*hypotenuse-halfbase*halfbase);
        if(height*height+halfbase*halfbase==hypotenuse*hypotenuse){
            ans+=2*(halfbase+hypotenuse);
            printf("%lld,%lld,%lld\n",halfbase,height,hypotenuse);
        }
    }
    printf("%d",ans);
    return 0;
}
