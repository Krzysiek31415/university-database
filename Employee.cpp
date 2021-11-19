#include <algorithm>
#include <cctype>
#include <exception>
#include <memory>
#include <numeric>
#include "Employee.hpp"
#include <string>
#include <vector>

std::vector<std::string> Employee::descriptionEmployeeData{"Name: ", "Surname: ", "Address: ",
                                        "PESEL: ", "Gender [m - male, f - female, o - other]: ", "Earnings: "};

Employee::Employee(const std::string & name, const std::string & surname, 
    const std::string & address, const std::string & PESEL, 
    const std::string & gender, const std::string & earnings)
    : Person::Person(name, surname, address, PESEL, gender )
{
    auto it = personData_.begin();
    personData_.insert(it + 3, &indexNumber_);
    setEarnings(earnings);
    personData_.push_back(&earnings_);
}

Employee::~Employee()
{
}


bool Employee::setEarnings(const std::string & earnings)
{
    if(isNumber(earnings))
    {
        earnings_ = earnings;
        return true;
    }
    else
    {
        return false;
    }
}

std::string Employee::getEarnings() const
{
    return earnings_;
}

// std::vector<std::string *> Employee::getEmployeeData() const
// {
//     return studentData_;
// }

std::shared_ptr<Employee> makeEmployee()
{
    
    std::vector<std::string> temp(7);
    for(size_t n = 0; n < Employee::descriptionEmployeeData.size(); ++n)
    {
        std::cout << Employee::descriptionEmployeeData[n];
        std::cin >> std::ws;
        std::getline(std::cin, temp[n]);
    }
    std::shared_ptr<Employee> employee{new Employee{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]}};
    return employee;
}



