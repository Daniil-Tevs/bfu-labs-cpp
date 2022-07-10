#include <iostream>
#include "class.h"

int main() {
    auto teacher1 = std::make_shared<Teacher>("Alex");
    auto student1 = std::make_shared<Student>(teacher1,"Bob");
    auto student2 = std::make_shared<Student>(teacher1,"Ted");
    auto student3 = std::make_shared<Student>(teacher1,"Den");
    std::cout<<teacher1<<std::endl;
    std::cout<<student1->getTeacher()<<std::endl;
    teacher1->addStudent(student1);
    teacher1->addStudent(student2);
    teacher1->addStudent(student3);
    std::cout<<student1<<std::endl;
    std::cout<<teacher1->getStudents()[0];
    return 0;
}
