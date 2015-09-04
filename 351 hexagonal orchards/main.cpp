#include <iostream>
#include <vector>
using namespace std;

vector<double> solveMtx(vector<vector<double> > eq);
vector<double>& multRow(vector<double>& eq,double factor);

int main()
{
    cout << "Hello world!" << endl;
    return 0;
}

vector<double> solveMtx(vector<vector<double> > eq)
{
    vector<double> sol;
    int varCnt=int(eq.size());

    for(int row=0;row<varCnt;row++){
        if(eq[row].size()!=varCnt+1)
            return sol;
    }

    for(int baseRow=0;baseRow<varCnt;baseRow++)
    {
        for(int subRow=baseRow+1;subRow<varCnt;subRow++)
        {
            multRow(eq[baseRow],eq[subRow][baseRow]/eq[baseRow][baseRow]);
            addRow()
        }
    }
}

vector<double>& addRow(vector<double>& eq1,vector<double>& eq2)
{
    for(unsigned int term=0;term<eq1.size();term++) eq1[term]+=eq2[term];
    return eq1;
}

vector<double>& multRow(vector<double>& eq,double factor)
{
    for(unsigned int term=0;term<eq.size();term++) eq[term]*=factor;
    return eq;
}
