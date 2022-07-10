#include "class.h"
Teacher::Teacher(const std::string &name)
{m_name = name;}
std::vector<std::shared_ptr<Student>> Teacher::getStudents()
{return m_students;}

void Teacher::addStudent(const std::shared_ptr<Student>& student)
{m_students.push_back(student);}


Student::Student(std::shared_ptr<Teacher> teacher,std::string name)
{
    m_name = name;
    m_teacher = teacher;
}
std::shared_ptr<Teacher> Student::getTeacher()
{return m_teacher;}