//54 poker hands
#include<iostream>
#include<fstream>
using namespace std;

bool onepair(int num[5])
{
    if((num[0]==num[1])||(num[1]==num[2])||(num[2]==num[3])||(num[3]==num[4]))
        return 1;
    return 0;
}

bool twopair(int num[5])
{
    if(((num[0]==num[1])&&(num[2]==num[3]))||((num[0]==num[1])&&(num[3]==num[4]))||((num[1]==num[2])&&(num[3]==num[4])))
        return 1;
    return 0;
}

bool threekind(int num[5])
{
    if((num[0]==num[2])||(num[1]==num[3])||(num[2]==num[4]))
        return 1;
    return 0;
}

bool straight(int num[5])
{
    if(num[4]!=14){
        if(((num[1]-num[0])==1)&&((num[2]-num[1])==1)&&((num[3]-num[2])==1)&&((num[4]-num[3])==1))
            return 1;
        return 0;
    }
    else if((num[0]==2)&&(num[1]==3)&&(num[2]==4)&&(num[3]==5))
        return 1;
    return 0;
}

bool flush(char suit[5])
{
    if((suit[1]==suit[0])&&(suit[2]==suit[0])&&(suit[3]==suit[0])&&(suit[4]==suit[0]))
        return 1;
    return 0;
}

bool fullhouse(int num[5])
{
    if(((num[0]==num[1])&&(num[2]==num[4]))||((num[0]==num[2])&&(num[3]==num[4])))
        return 1;
    return 0;
}

bool fourkind(int num[5])
{
    if((num[3]==num[0])||(num[4]==num[1]))
        return 1;
    return 0;
}

bool straightflush(int num[5],char suit[5])
{
    if(straight(num)&&flush(suit))
        return 1;
    return 0;
}

bool royalflush(int num[5],char suit[5])
{
    if(straightflush(num,suit)&&(num[4]==14))
        return 1;
    return 0;
}

int value(int num[5],char suit[5])
{
    /*for(int i=0;i<5;i++){
        cout<<num[i]<<suit[i]<<" ";
    }
    system("pause");*/
    
    if(royalflush(num,suit))return 9;
    else if(straightflush(num,suit))return 8;
    else if(fourkind(num))return 7;
    else if(fullhouse(num))return 6;
    else if(flush(suit))return 5;
    else if(straight(num))return 4;
    else if(threekind(num))return 3;
    else if(twopair(num))return 2;
    else if(onepair(num))return 1;
    else return 0;
}

int hand1win(int num1[5],int num2[5],int val1,int val2)
{
    if(val1>val2)
            return 1;
    else{
        if(val2>val1)
            return 0;
        else{
            switch(val1){
                case 0:for(int index=4;1;index--){
                           if(num1[index]>num2[index])return 1;
                           if(num2[index]>num1[index])return 0;
                       }return 0;
                case 1:int pair1num,pair2num;
                       if(num1[0]==num1[1])pair1num=num1[1];//finding which number is in a pair in hand1
                       else if(num1[1]==num1[2])pair1num=num1[2];
                       else if(num1[2]==num1[3])pair1num=num1[3];
                       else pair1num=num1[4];
                       
                       if(num2[0]==num2[1])pair2num=num2[1];//finding which number is in a pair in hand2
                       else if(num2[1]==num2[2])pair2num=num2[2];
                       else if(num2[2]==num2[3])pair2num=num2[3];
                       else pair2num=num2[4];
                       
                       if(pair1num>pair2num)return 1;
                       if(pair2num>pair1num)return 0;
                       
                       for(int index=4;1;index--){
                           if(num1[index]>num2[index])return 1;
                           if(num2[index]>num1[index])return 0;
                       }return 0;
                case 2:if(num1[3]>num2[3])return 1;
                       if(num2[3]>num1[3])return 0;
                       if(num1[1]>num2[1])return 1;
                       if(num2[1]>num1[1])return 0;
                       for(int index=4;1;index-=2){
                           if(num1[index]>num2[index])return 1;
                           if(num2[index]>num1[index])return 0;
                       }return 0;
                case 3:if(num1[2]>num2[2])
                           return 1;
                       return 0;
                case 4:if(num1[0]>num2[0])
                           return 1;
                       return 0;
                case 5:for(int index=4;1;index--){
                           if(num1[index]>num2[index])return 1;
                           if(num2[index]>num1[index])return 0;
                       }return 0;
                case 6:if(num1[2]>num2[2])
                           return 1;
                       return 0;
                case 7:if(num1[2]>num2[2])
                           return 1;
                       return 0;
                default:;
            }
        }
    }
}

int main()
{
    char current;//current character read from file
    char suit1[5],suit2[5];
    int num1[5],num2[5];
    int iteration,subiteration,temp;//for sorting numbers
    int hand1value,hand2value;
    int cardindex;
    int p1wins=0;
    
    ifstream text("54 pokerhands.txt");
    if(!text)
        return 0;
    
    while(!text.eof()){
        for(cardindex=0;cardindex<5;cardindex++){//reading in card values of hand1 and finding the value of the hand
            text>>current;
            if(current-'0'<10){
                num1[cardindex]=current-'0';
            }
            else{
                switch(current){
                    case 'T':num1[cardindex]=10;break;
                    case 'J':num1[cardindex]=11;break;
                    case 'Q':num1[cardindex]=12;break;
                    case 'K':num1[cardindex]=13;break;
                    case 'A':num1[cardindex]=14;break;
                    default:;
                }
            }
            text>>suit1[cardindex];
        }//end of reading in num and suit of hand1
        
        for(iteration=0;iteration<4;iteration++){//sort hand1 from lowest to highest
            for(subiteration=0;subiteration<(4-iteration);subiteration++){
                if(num1[subiteration]>num1[subiteration+1]){
                    temp=num1[subiteration];
                    num1[subiteration]=num1[subiteration+1];
                    num1[subiteration+1]=temp;
                }
            }
        }
        
        for(cardindex=0;cardindex<5;cardindex++){//reading in card values of hand2
            text>>current;
            if(current-'0'<10){
                num2[cardindex]=current-'0';
            }
            else{
                switch(current){
                    case 'T':num2[cardindex]=10;break;
                    case 'J':num2[cardindex]=11;break;
                    case 'Q':num2[cardindex]=12;break;
                    case 'K':num2[cardindex]=13;break;
                    case 'A':num2[cardindex]=14;break;
                    default:;
                }
            }
            text>>suit2[cardindex];
        }//end of reading in num and suit of hand2
        
        for(iteration=0;iteration<4;iteration++){//sort hand1 from lowest to highest
            for(subiteration=0;subiteration<(4-iteration);subiteration++){
                if(num2[subiteration]>num2[subiteration+1]){
                    temp=num2[subiteration];
                    num2[subiteration]=num2[subiteration+1];
                    num2[subiteration+1]=temp;
                }
            }
        }
        
        hand1value=value(num1,suit1);
        hand2value=value(num2,suit2);
        
        p1wins+=hand1win(num1,num2,hand1value,hand2value);
    }
    text.close();
    
    cout<<p1wins;
    system("pause");
    return 0;
}
