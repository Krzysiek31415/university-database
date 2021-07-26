#include "Student.hpp"
#include <string>

std::string Student::genderToString(Student::Gender gender)
{
    switch (gender) {
    case Student::Gender::male:
        return "Male";
        break;
    case Student::Gender::female:
        return "Female";
        break;
    case Student::Gender::other:
        return "other";
        break;
    default:
        return " ";
    }
}

// Student::Student()
// {
//     std::cout<<"Adding new student: \n";
//     std::string name{}; 
//     std::string surname{}; 
//     std::string address{}; 
//     unsigned long indexNumber{};
//     unsigned long PESEL{}; 
//     Student::Gender gender{};

//     std::cout<<"Name: "; std::cin>>name;
//     std::cout<<"Surname: "; std::cin>>surname;
//     std::cout<<"Address: "; std::cin>>std::ws;std::getline(std::cin,address);
//     std::cout<<"Index number: "; std::cin>>indexNumber;
//     std::cout<<"PESEL: "; std::cin>>PESEL;

//     this->setName(name);
//     this->setSurname(surname);
//     this->setAddress(address);
//     this->setIndexNumber(indexNumber);
//     this->setPESEL(PESEL);
//     this->setGender(Gender::other);
// }
Student::Student(std::string name, std::string surname, std::string address, unsigned long indexNumber,
    unsigned long PESEL, Gender gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
    , indexNumber_(indexNumber)
    , PESEL_(PESEL)
    , gender_(gender)
{
}
Student::Student(std::string name, std::string surname)
    : Student(name, surname, "", 0UL, 0UL, Gender::other)
{
}
void Student::setName(std::string name)
{
    name_ = name;
}
void Student::setSurname(std::string surname)
{
    surname_ = surname;
}
void Student::setAddress(std::string address)
{
    address_ = address;
}
void Student::setIndexNumber(unsigned long indexNumber)
{
    indexNumber_ = indexNumber;
}
void Student::setPESEL(unsigned long PESEL)
{
    PESEL_ = PESEL;
}
void Student::setGender(Gender gender)
{
    gender_ = gender;
}

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
unsigned long Student::getIndexNumber() const
{
    return indexNumber_;
}
unsigned long Student::getPESEL() const
{
    return PESEL_;
}
Student::Gender Student::getGender() const
{
    return gender_;
}
// Student& Student::fillInStudentData()
// {
//     std::string name{}; 
//     std::string surname{}; 
//     std::string address{}; 
//     unsigned long indexNumber{};
//     unsigned long PESEL{}; 
//     Gender gender{};

//     std::cout<<"Name: "; std::cin>>name;
//     std::cout<<"Surname: "; std::cin>>surname;
//     std::cout<<"Address: "; std::cin>>address;
//     std::cout<<"Index number: "; std::cin>>indexNumber;
//     std::cout<<"PESEL: "; std::cin>>PESEL;
//     //std::cout<<"Gender: "; std::cin>>gender;
//     Student student(name,surname,address,indexNumber,PESEL,Gender::male);
//     //std::cout<<"W student show student: \n";
//     //student.showStudent();
//     return *this;
// }

void Student::showStudent()
{
    std::cout << std::left << std::setw(13) << getName() << "| ";
    std::cout << std::left << std::setw(13) << getSurname() << "| ";
    std::cout << std::left << std::setw(13) << getAddress() << "| ";
    std::cout << std::left << std::setw(13) << getIndexNumber() << "| ";
    std::cout << std::left << std::setw(13) << getPESEL() << "| ";
    std::cout << std::left << std::setw(13) << genderToString(getGender()) << "| \n";
}