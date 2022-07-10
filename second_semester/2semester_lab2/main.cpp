#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
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

double key(double &d) {
    return d;
}

void QUICKSORT(int a, int b, std::vector<double> &x)
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
void BUBBlE_SORT(std::vector<double> &mas,int n)
{
    for(int i=1;i<n;i++)
    {
        if(mas[i]>mas[i-1])
            continue;
        int j=i-1;
        while(j>=0 && mas[j]>mas[j+1])
        {
            std::swap(mas[j],mas[j+1]);
            j--;
        }
    }
}
int main() {
    std::ofstream out("../output.txt");
    int t=0,mass_N[4]={1000,10000,100000,500000};
    while(t<3) {
        int N=mass_N[t];
        std::vector<long double> res;
        std::vector<double> mass, mass1;
        for (int i = 0; i < N; i++) {
            mass.push_back(10+rand() % 1000);
            mass1.push_back(mass[i]);
        }
        for (int i = 0; i < N; i++)
            out << mass[i] << " ";
        out << "\n";
        Timer t1;
        QUICKSORT(0, mass.size() - 1, mass);
        res.push_back(t1.elapsed());
        for (int i = 0; i < N; i++)
            out << mass[i] << " ";
        out << "\n";
        Timer t2;
        BUBBlE_SORT(mass1, mass1.size());
        res.push_back(t2.elapsed());
        for (int i = 0; i < N; i++)
            out << mass1[i] << " ";
        out.setf(std::ios_base::fixed);
        out << "\nquicksort " << res[0] << "\nbubble_sort " << res[1]<<"\n";
        t++;
    }
    return 0;
}
