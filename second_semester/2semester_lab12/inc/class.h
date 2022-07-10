#include <iostream>
#include <vector>
class Student;
class Teacher{
private:
    std::string m_name;
    std::vector<std::shared_ptr<Student>> m_students;
public:
    Teacher(const std::string& name);
    std::vector<std::shared_ptr<Student>> getStudents();
    void addStudent(const std::shared_ptr<Student>& student);
    ~Teacher() = default;
};

class Student{
private:
    std::shared_ptr<Teacher> m_teacher = nullptr;
    std::string m_name;
public:
    Student(std::shared_ptr<Teacher> teacher,std::string name);
    ~Student() = default;
    std::shared_ptr<Teacher> getTeacher();
};