#pragma once
#include <map>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Person.hpp"

class Student : public Person
{
public:
    static std::vector<std::string> descriptionStudentData;

    Student(const std::string & name, const std::string & surname, const std::string & address, 
    const std::string & indexNumber, const std::string & PESEL, const std::string & gender);

    virtual ~Student();
    
    std::string getIndexNumber() const;

    bool setIndexNumber(const std::string & indexNumber);

    friend std::shared_ptr<Student> makeStudent();
};

std::shared_ptr<Student> makeStudent();




