#include <iostream>
#include <vector>
#include <fstream>
#include <chrono> // для функций из std::chrono

class Timer
{
private:
    using clock_t = std::chrono::high_resolution_clock;
    using second_t = std::chrono::duration<double, std::ratio<1> >;
    std::chrono::time_point<clock_t> m_beg;

public:
    Timer() : m_beg(clock_t::now())
    {
    }
    void reset()
    {
        m_beg = clock_t::now();
    }
    double elapsed() const
    {
        return std::chrono::duration_cast<second_t>(clock_t::now() - m_beg).count();
    }
};
int key(int &d) {
    return d;
}
void QUICKSORT(int a, int b, std::vector<int> &x)
{
    if(a>=b)
        return;
    int m=a+rand()%(b-a+1);
    double k=key(x[m]);
    int l=a-1;
    int r=b+1;
    while(true)
    {
        do{l++;}while(key(x[l])<k);
        do{r--;}while(key(x[r])>k);
        if(l>=r)
            break;
        std::swap(x[l],x[r]);
    }
    r=l;l=r-1;
    QUICKSORT(a,l,x);
    QUICKSORT(r,b,x);
}
int SEARCH(int i,int n,int k,std::vector<int> &x)
{
    if(k<key(x[i]))
        return 0;
    if(k==key(x[i]))
        return x[i];
    if(k>key(x[n]))
        return 0;
    int a=i,b=n;
    int c;
    while(a+1<b)
    {
        c=(a+b)/2;
        if(k>key(x[c]))
            a=c;
        else
            b=c;
    }
    if(key(x[b])==k)
        return b;
    else
        return 0;
}
int main() {
    std::ofstream out("../output.txt");
    int M,N,a;
    std::cin>>N;
    std::cin>>M;
    std::vector<int> main_mass,requests,results,itog;
    std::vector<double> timer;
    for(int i=0;i<N;i++)
        main_mass.push_back(10+rand()%1000);
    for(int i=0;i<M;i++)
        requests.push_back(10 + rand() % 1000);
    QUICKSORT(0,N-1,main_mass);
    Timer t1;
    for(int i=0;i<M;i++)
    {
        a=SEARCH(0, N - 1, requests[i], main_mass);
        if(a!=0)
            results.push_back(requests[i]);
    }
    timer.push_back(t1.elapsed());
    Timer t2;
    for(int i=0;i<M;i++)
    {
        for(int j=0;j<N;j++)
        {
            if(requests[i]==main_mass[j])
            { itog.push_back(requests[i]);break; }
        }
    }
    timer.push_back(t2.elapsed());
    for(int i=0;i<N;i++)
        out<<main_mass[i]<<" ";
    out<<"\n";
    for(int i=0;i<M;i++)
        out<<requests[i]<<" ";
    out<<"\n";
    for(int i=0;i<results.size();i++)
        out<<results[i]<<" ";
    out<<"\n";
    for(int i=0;i<itog.size();i++)
        out<<itog[i]<<" ";
    out<<std::ios_base::fixed<<"\n"<<timer[0]<<"\n"<<timer[1];
    return 0;
}
