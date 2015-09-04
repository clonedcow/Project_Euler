#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int i,sum=0;
    int encrypted_msg[1500],letter[3];
    char input;
    bool letter1_bad,letter2_bad;
    ifstream file;
    file.open("59 xor msg.txt");
    
    for(i=0;i<1500;encrypted_msg[i++]=-1){};
    
    i=0;
    while(!file.eof()){
        encrypted_msg[i]=0;
        
        do{
            file>>input;
            if(input==','||file.eof())break;
            encrypted_msg[i]+=input-'0';
            encrypted_msg[i]*=10;
        }while(1);
        
        encrypted_msg[i++]/=10;
        //cout<<encrypted_msg[i-1]<<",";
    }
    
    file.close();

    for(letter[0]='a';letter[0]<='z';letter[0]++){
    letter1_bad=0;
        for(letter[1]='a';letter[1]<='z';letter[1]++){
        letter2_bad=0;
            for(letter[2]='a';letter[2]<='z';letter[2]++){
                for(i=0;encrypted_msg[i]!=-1;i++){
                    if(!((encrypted_msg[i]^letter[i%3])>='a'&&(encrypted_msg[i]^letter[i%3])<='z'))
                    if(!((encrypted_msg[i]^letter[i%3])>='A'&&(encrypted_msg[i]^letter[i%3])<='Z'))
                    if(!((encrypted_msg[i]^letter[i%3])>=' '&&(encrypted_msg[i]^letter[i%3])<=';'))
                    break;
                }
                
                if(encrypted_msg[i]==-1){
                    for(i=0;encrypted_msg[i]!=-1;i++){
                        sum+=(encrypted_msg[i]^letter[i%3]);
                        cout<<char(encrypted_msg[i]^letter[i%3]);
                    }          
                    cout<<sum;
                    system("pause");
                    return 0;
                }
                
                if(letter1_bad==1||letter2_bad==1)break;
            }
            if(letter1_bad==1)break;
        }
    }

    return 0;
}
