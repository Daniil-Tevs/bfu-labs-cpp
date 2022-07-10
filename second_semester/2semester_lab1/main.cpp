#include <iostream>
#include <fstream>
#include <vector>
#include <chrono> // для функций из std::chrono

class Timer
{
private:
    // Псевдонимы типов используются для удобного доступа к вложенным типам
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
int main() {
    std::ifstream in("../input.txt");
    std::ofstream out("../output.txt");
    int d=1;
    int N,k,a,b; in>>N;
    std::vector<double> res;
    while(d<=2)
    {
        N=100*d;
        std::vector<std::vector<double>> matrix1;
        std::vector<std::vector<double>> matrix2;
        std::vector<std::vector<double>> matrix3;
        for(int i=0;i<N;i++) {
            std::vector<double> v;
            matrix1.push_back(v);
            for (int j = 0; j < N; j++) {
    //            in >> a;
    //            matrix1[i].push_back(a);
                  matrix1[i].push_back(1+rand()%100);
            }
        }
        for(int i=0;i<N;i++) {
            std::vector<double> v;
            matrix2.push_back(v);
            for (int j = 0; j < N; j++) {
    //            in >> a;
    //            matrix2[i].push_back(a);
                  matrix2[i].push_back(1+rand()%100);
            }
        }
        for(int i=0;i<N;i++) {
            std::vector<double> v;
            matrix3.push_back(v);
            for (int j = 0; j < N; j++) {
                matrix3[i].push_back(0);
            }
        }
        Timer t;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                k=0;
                while(k<N)
                {
                    matrix3[i][j]+=matrix1[i][k]*matrix2[k][j];
                    k++;
                }
            }
        }
        res.push_back(t.elapsed());
        out<<res[(d-1)*d]<<std::endl;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
                out<<matrix3[i][j]<<" ";
            out<<"\n";
        }
    //    std::cout<<(N*N*(1+2*N))/(12*pow(10,8));
        std::cout<<(N*N*N)/(12*pow(10,8));
        res.push_back((N*N*N)/(12*pow(10,8)));
        d++;
    }
    std::cout<<std::endl<<res[2]/res[0]<<std::endl;
    std::cout<<res[3]/res[1]<<std::endl;
    return 0;
}
