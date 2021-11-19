#pragma once
#include <map>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include "Person.hpp"

class Employee : public Person
{
public:
    static std::vector<std::string> descriptionEmployeeData;
    
    Employee(const std::string & name, const std::string & surname, const std::string & address, 
    const std::string & PESEL, const std::string & gender, const std::string & earnings);

    virtual ~Employee();

    std::string getEarnings() const;

    bool setEarnings(const std::string & earnings);

    friend std::shared_ptr<Employee> makeEmployee();

};

std::shared_ptr<Employee> makeEmployee();