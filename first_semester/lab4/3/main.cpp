#include <iostream>
#include <fstream>
using namespace std;


int main()
{
    ifstream in("input.txt");
    ofstream out("output.txt");
    int n,m,i,j;
    in>>n;
    in>>m;
    int** mass=new int*[n];
    for(i=0;i<n;i++)
        mass[i]= new int[m];
    for(i=0;i<n;i++)
        for(j=0;j<m;j++)
            in>>mass[i][j];
    int min=INT_MAX,nomer=0;
    for(i=0;i<m;i++)
    {
        for(j=0;j<n;j++)
        {
            if(min>mass[j][i])
            {
                min=mass[j][i];
                nomer=i;
            }
        }
    }
    for(i=0;i<n;i++)
    {
        if(mass[i][nomer]<0)
            mass[i][nomer]=0;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<m;j++)
            out<<mass[i][j]<<" ";
        out<<endl;
    }
    for(i=0;i<n;i++)
        delete[] mass[i];
    delete[] mass;
    return 0;
}