#include "Student.hpp"
#include <string>
#include <cctype>
#include <algorithm>
bool isNumber(const std::string& numberString)
{
    return !numberString.empty() && std::find_if(numberString.begin(), 
        numberString.end(), [](unsigned char c) { return !std::isdigit(c); }) == numberString.end();
}
std::string Student::genderToString(Student::Gender gender)
{
    switch (gender) 
    {
    case Student::Gender::male :
        return "male";
        break;
    case Student::Gender::female :
        return "female";
        break;
    case Student::Gender::other :
        return "other";
        break;
    default:
        return "";
    }
}

Student::Gender charToEnum(const char genderAbbreviation)
{
    switch(genderAbbreviation)
    {
        case 'm':
            return Student::Gender::male;
        case 'f':
            return Student::Gender::female;
        case 'o':
            return Student::Gender::other;
        default:
            return Student::Gender::other;
            
    }
}

Student::Student(std::string name, std::string surname, std::string address, std::string indexNumber,
    std::string PESEL, Gender gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
    , indexNumber_(indexNumber)
    , PESEL_(PESEL)
    , gender_(gender)
{
}
// Student::Student(std::string name, std::string surname)
//     : Student(name, surname, "", 0UL, 0UL, Gender::other)
// {
// }

// void Student::setName(std::string name)
// {
//     name_ = name;
// }
// void Student::setSurname(std::string surname)
// {
//     surname_ = surname;
// }
// void Student::setAddress(std::string address)
// {
//     address_ = address;
// }
// void Student::setIndexNumber(std::string indexNumber)
// {
//     indexNumber_ = indexNumber;
// }
// void Student::setPESEL(std::string PESEL)
// {
//     PESEL_ = PESEL;
// }
// void Student::setGender(Gender gender)
// {
//     gender_ = gender;
// }

std::string Student::getName() const
{
    return name_;
}
std::string Student::getSurname() const
{
    return surname_;
}
std::string Student::getAddress() const
{
    return address_;
}
std::string Student::getIndexNumber() const
{
    return indexNumber_;
}
std::string Student::getPESEL() const
{
    return PESEL_;
}
Student::Gender Student::getGender() const
{
    return gender_;
}
Student& Student::fillInStudentData()
{
    
    std::cout<<"Name: "; std::cin>>std::ws;std::getline(std::cin,name_);
    std::cout<<"Surname: "; std::cin>>std::ws;std::getline(std::cin,surname_);
    std::cout<<"Address: "; std::cin>>std::ws;std::getline(std::cin,address_);
    std::cout<<"Index number: "; std::cin>>std::ws;std::getline(std::cin, indexNumber_);
    while(!isNumber(indexNumber_))
    {
        std::cout<<"Error. It is not a index number. Please enter it again. \n";
        std::cout<<"Index number: "; std::cin>>std::ws;std::getline(std::cin, indexNumber_);
    }
    std::cout<<"PESEL: "; std::cin>>std::ws;std::getline(std::cin, PESEL_);
    while(!isNumber(PESEL_))
    {
        std::cout<<"Error. It is not a PESEL. Please enter it again. \n";
        std::cout<<"PESEL number: "; std::cin>>std::ws;std::getline(std::cin, PESEL_);
    }
    std::cout<<"Gender [male - m, female - f, other - o]: "; 
    char genderAbbreviation{};
    std::cin>>genderAbbreviation;
    gender_ = charToEnum(genderAbbreviation);
    return *this;
}

void Student::showStudent()
{
    std::cout << std::left << std::setw(13) << getName() << "| ";
    std::cout << std::left << std::setw(13) << getSurname() << "| ";
    std::cout << std::left << std::setw(13) << getAddress() << "| ";
    std::cout << std::left << std::setw(13) << getIndexNumber() << "| ";
    std::cout << std::left << std::setw(13) << getPESEL() << "| ";
    std::cout << std::left << std::setw(13) << genderToString(getGender()) << "| \n";
}


