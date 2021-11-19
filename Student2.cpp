#include <algorithm>
#include <cctype>
#include <exception>
#include <memory>
#include <numeric>
#include "Student2.hpp"
#include <string>
#include <vector>

std::vector<std::string> Student::descriptionStudentData{"Name: ", "Surname: ", "Address: ", "Index number: ",
                                        "PESEL: ", "Gender [m - male, f - female, o - other]: "};

Student::Student(const std::string & name, const std::string & surname, const std::string & address, const std::string & indexNumber,
    const std::string & PESEL, const std::string & gender):
    Person::Person(name, surname, address, PESEL, gender )
{
    setIndexNumber(indexNumber);
    auto it = personData_.begin();
    personData_.insert(it + 3, &indexNumber_);
    // delete set earnings in class student
    personData_.insert(it + 6, &earnings_);
}

Student::~Student()
{
}


bool Student::setIndexNumber(const std::string & indexNumber)
{
    if(isNumber(indexNumber))
    {
        indexNumber_ = indexNumber;
        return true;
    }
    else
    {
        return false;
    }
}

// std::vector<std::string *> Student::getStudentData() const
// {
//     return studentData_;
// }

// Student& Student::fillInStudentData()
// {
//     std::vector<std::string> descriptionStudentData{"Name: ", "Surname: ", "Address: ", "Index number: ",
//                                         "PESEL: ", "Gender [m - male, f - female, o - other]: "};
//     std::vector<std::string> tempStudentData(7);

//     for(size_t n = 0; n < descriptionStudentData.size(); ++n)
//     {
//         std::cout << descriptionStudentData[n];
//         std::cin >> std::ws;
//         std::getline(std::cin, tempStudentData[n]);
//     }
//     return *this;
// }

std::shared_ptr<Student> makeStudent()
{
    
    std::vector<std::string> temp(7);

    for(size_t n = 0; n < Student::descriptionStudentData.size(); ++n)
    {
        std::cout << Student::descriptionStudentData[n];
        std::cin >> std::ws;
        std::getline(std::cin, temp[n]);
    }
    std::shared_ptr<Student> student{new Student{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]}};
    return student;
}





