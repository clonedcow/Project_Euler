//42 triangle words
#include<iostream>
#include<math.h>
#include<fstream>
using namespace std;

int main()
{
    char c;
    int wordCount=0,wordScore;
    
    ifstream word("42 words.txt");
    if(!word)
        cout<<"couldn't open file\n";
        
    do{
        word>>c;//'"' at start of word
        c='@';
        wordScore=0;
        
        do{//calculating the score of the word
            wordScore+=c-'@';
            word>>c;
        }while(c!='"');
        
        wordScore*=2;//testing if it's a trianglular word
        if((int(sqrt(wordScore))*(1+int(sqrt(wordScore))))==wordScore)
            wordCount++;
        
        word>>c;//','
    }while(!word.eof());
    
    word.close();
    
    cout<<wordCount<<"\n";
    system("pause");
    return 0;
}
