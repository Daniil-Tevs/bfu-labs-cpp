#include <iostream>

int main() {
    int N;
    int tmp, min = INT_MAX, number,sum = 0;
    std::cin>>N;
    for(int i=0;i<N;i++)
    {
        std::cin>>tmp;
        if(tmp % 10 !=1)
            sum+=tmp;
        if(tmp<min && tmp % 10 !=1)
        {
            min = tmp;
            number = i+1;
        }
    }
    std::cout<<sum<<"\n"<<min<<"\n"<<number;
    return 0;
}
