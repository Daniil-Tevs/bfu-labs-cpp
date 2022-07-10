#include <iostream>
#include "class.h"

int main() {
    codeGenerator** test4 = new codeGenerator*[3];

//    generateJava test1;
//    std::cout<<test1.getCode()<<std::endl;
//    generateCpp test2;
//    std::cout<<test2.getCode()<<std::endl;
//    generatePHP test3;
//    std::cout<<test3.getCode();
    test4[0] = new generateCpp;
    test4[1] = new generateJava;
    test4[2] = new generatePHP;
    for(int i=0;i<3;i++)
    {
        std::cout<<test4[i]->getCode()<<std::endl;
    }
    return 0;
}
