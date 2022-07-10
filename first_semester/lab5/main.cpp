#include <fstream>
#include <iostream>
#include <string>
#include <windows.h>
#include <map>
#include <cctype>

#define N 1000

using namespace std;

//понижение регистра
void Registr(string &w)
{
    for (char & i : w)
    {
        i = tolower(i);
    }
}
bool Kolichestvo(string &w)
{
    setlocale(LC_ALL, "Rus");
    Registr(w);
    int glass[] = {224,229,232,238,243,251,253,254,255};
//    char soglas[]="йцкнгшщзхъфвпрлджчсмтьб";
    int glas=0,sogl=0,fl=0;
    for(int i=0;i<w.length();i++)
    {
        fl=0;
        int t=(unsigned char)w[i];
        for(int j=0;j<9;j++)
            if(t==glass[j]){fl=1;break;}
        if(fl==0)sogl++;
        else
            glas++;
    }
    if(glas==sogl)
        return true;
    else
        return false;
}

int main()
{
    setlocale(LC_ALL, "Rus");
    SetConsoleCP(1251);
    std::ifstream in("input.txt");
    std::ofstream out("output.txt");

    if (!in)
    {
        cerr << "File not found" << endl;
        exit(1);
    }
    string words[N];
    int nWords = 0;

    while (!in.eof())
    {
        string w;
        in >> w;
        while (ispunct(w[w.length() - 1]))
        {
            w.erase(w.length() - 1);
        }
        if (Kolichestvo(w)) {
            int pos = nWords;
            while (pos > 0)
            {
                if (w.length() < words[pos - 1].length())
                {
                    break;
                }
                else if (w.length() == words[pos - 1].length() && w < words[pos - 1])
                    break;
                pos--;
            }

            if (pos >= N)
                continue;
            if (pos < nWords && words[pos] == w)
                continue;
            if (nWords + 1 <= N && nWords>=1)
                words[nWords] = words[nWords - 1];
            for (int n = nWords - 1; n > pos; n--)
            {
                words[n] = words[n - 1];
            }
            words[pos] = w;
            if (nWords < N)
                nWords++;
        }
    }

    for (int j = 0; j < nWords; j++)
    {
        out << words[j] << endl;
    }
    out.close();
    return 0;
}
