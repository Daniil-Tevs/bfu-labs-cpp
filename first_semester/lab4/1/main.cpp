#include <iostream>
#include <fstream>
int countDigit(int a)
{
    if(a==0)
        return 0;
    return a%10 + countDigit(a/10);
}
int main()
{
    std::ifstream in("../input.txt");
    std::ofstream out("../output.txt");
    int* mass = new int[10000];
    int tmp, i =0;
    while(!in.eof())
    {
        in>>tmp;
        mass[i] = tmp;
        i++;
    }
    bool fl = false;
    for(int j=0;j<i;j++)
        if(countDigit(mass[j]) == 12)
        {fl = true; break;}
    if(fl) {
        for (int k = 0; k < i; k++)
            for (int j=k;j<i;j++)
                if(mass[k]<=mass[j])
                    std::swap(mass[k],mass[j]);
    }
    else
    {
        for (int k = 0; k < i; k++)
            for (int j=k;j<i;j++)
                if(mass[k]>=mass[j])
                    std::swap(mass[k],mass[j]);
    }
    for(int j=0;j<i;j++)
        out<<mass[j]<<" ";

    delete[] mass;

    return 0;
}
