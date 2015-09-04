//22 name scores
#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;

struct node
{
    char name[15];
    node *next;
};

bool isafter(node *newname,node *curname)//function comparing two names
{
    
    if(curname==NULL)//make sure the node exists
        return 0;
    for(int i=0;i<15;i++){
        if((newname->name[i])>(curname->name[i]))
            return 1;
        if((newname->name[i])<(curname->name[i]))
            return 0;
    }
    return 0;
}

int main()
{
    bool sorted=0;
    int charindex,namescore=0,nameindex=1,sum=0;
    char current;
    node *head=NULL,*newname=NULL,*sorttracker=NULL;
    
    head=new node;//start with an empty node
    for(charindex=0;charindex<15;charindex++)head->name[charindex]=' ';
    head->next=NULL;
    sorttracker=head;
    
    ifstream namefile("22 names.txt");
    if(!namefile)
        return 0;
    
    while(!namefile.eof()){//reading all the names and sorting them into a linked list
        sorted=0;
        sorttracker=head;//when sorting always start comparing with head                   
        namefile>>current;//read in '"' at start of name
        namefile>>current;//read in first letter
        
        newname=new node;//create new node for name
        charindex=0;//start inserting characters at beginning
        
        do{//read name into node
            newname->name[charindex]=current;
            charindex++;
            namefile>>current;
        }while(current!='"');//the quotes after the name are already read when loop is exited
        for(;charindex<15;charindex++)newname->name[charindex]=' ';
        
        /*for(int i=0;i<15;i++)cout<<newname->name[i];//DEBUG:print name after is read from file
        system("pause");*/
        
        while(isafter(newname,sorttracker->next)){
            sorttracker=sorttracker->next;
        }
        newname->next=sorttracker->next;
        sorttracker->next=newname;
        
        /*int j;//DEBUG:list names in alphabetical order
        for(node *i=head;i!=NULL;i=i->next){
            for(j=0;j<15;j++){cout<<i->name[j];}
        }
        system("pause");*/
        
        namefile>>current;//read in ',' separating names
    }
    namefile.close();//close file after reading all the names
    
    for(sorttracker=head->next;sorttracker!=NULL;sorttracker=sorttracker->next,nameindex++){
        for(charindex=0,namescore=0;sorttracker->name[charindex]!=' ';charindex++){
            namescore+=sorttracker->name[charindex]-'@';
        }
        sum+=nameindex*namescore;
    }
    cout<<sum<<"\n";

    system("pause");
    return 0;
}




