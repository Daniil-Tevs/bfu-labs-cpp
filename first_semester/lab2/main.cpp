#include <iostream>

int main() {
    ///First task
    int A,B,C;
    std::cin>>A>>B>>C;
    if((A+B)%C == 0)
        if(C%B == 0)
            std::cout<<(A+B)/C - C/B;
        else
            std::cout<<(A+B)/C+B*C;
    else
        std::cout<<A-B+C;
    ///Second task
    int N;
    std::cin>>N;
    switch (N) {
        case 1111: std::cout<<"Apple";break;
        case 1234: std::cout<<"Cheese";break;
        case 2222: std::cout<<"Milk";break;
        case 2345: std::cout<<"Bread";break;
        case 3333: std::cout<<"Water";break;
        default:std::cout<<"Don't found this product";
    }
    return 0;
}
