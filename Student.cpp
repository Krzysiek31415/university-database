#include <algorithm>
#include <cctype>
#include <exception>
#include <numeric>
#include "Student.hpp"
#include <string>
#include <vector>

std::vector<std::string> Gender= std::vector<std::string>{"male", "female", "other"};

bool isNumber(const std::string & numberString)
{
    return !numberString.empty() && 
            std::find_if(numberString.begin(), 
                         numberString.end(), 
                         [](unsigned char c) { return !std::isdigit(c); }) == numberString.end();
}

// Student::Gender charToEnum(const char genderAbbreviation)
// {
//     switch(genderAbbreviation)
//     {
//         case 'm':
//             return Student::Gender::male;
//         case 'f':
//             return Student::Gender::female;
//         case 'o':
//             return Student::Gender::other;
//         default:
//             return Student::Gender::other;

//     }
// }


Student::Student(const std::string & name, const std::string & surname, const std::string & address, const std::string & indexNumber,
    const std::string & PESEL, const std::string & gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
    , gender_(gender)
{
    setPESEL(PESEL);
    setIndexNumber(indexNumber);
    studentData.push_back(&name_);
    studentData.push_back(&surname_);
    studentData.push_back(&address_);
    studentData.push_back(&indexNumber_);
    studentData.push_back(&PESEL_);
    studentData.push_back(&gender_);

}


bool Student::validatePESEL(const std::string & PESEL)
{
    std::vector<int>  coefficients{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};
    std::vector<int> PESELnumbers;

    std::transform(PESEL.begin(), 
                   std::prev( PESEL.end() ),
                   std::back_inserter(PESELnumbers), 
                   [](auto c) mutable { return c - '0'; });

    long long sum = std::inner_product(coefficients.begin(),
                                       coefficients.end(),
                                       PESELnumbers.begin(), 0);
    if( ( PESEL.back() - '0' ) == 0)
    {
        return ( sum % 10 ) == 0;
    }
    else
    {
        return ( PESEL.back() - '0' ) == 10 - ( sum % 10 );
    }
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

void Student::setIndexNumber(const std::string & indexNumber)
{
    if(isNumber(indexNumber))
    {
        indexNumber_ = indexNumber;
    }
    else
    {
        throw std::logic_error("Incorrect input. IndexNumber not a number.");
    }
}

void Student::setPESEL(const std::string & PESEL)
{
    if(validatePESEL(PESEL))
    {
        PESEL_ = PESEL;
    }
    else
    {
        throw std::logic_error("Incorrect input. Incorrect PESEL.");
    }
}

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
std::string  Student::getGender() const
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
    std::cin>>std::ws;std::getline(std::cin,gender_);
    return *this;
}

std::string Student::showStudent()
{
    std::cout << std::left << std::setw(13) << getName() << "| ";
    std::cout << std::left << std::setw(13) << getSurname() << "| ";
    std::cout << std::left << std::setw(13) << getAddress() << "| ";
    std::cout << std::left << std::setw(13) << getIndexNumber() << "| ";
    std::cout << std::left << std::setw(13) << getPESEL() << "| ";
    std::cout << std::left << std::setw(13) << getGender() << "| \n";

    std::string studentData;
    studentData += getName() + "|" + getSurname() + "|" + getAddress() + "|" +
                getIndexNumber() + "|" + getPESEL() + "|" + getGender();

    return studentData;
}

bool operator== (const Student & one,const Student & two)
{
    if(one.getName() == two.getName() &&
        one.getSurname() == two.getSurname() &&
        one.getAddress() == two.getAddress() &&
        one.getPESEL() == two.getPESEL() &&
        one.getIndexNumber() == two.getIndexNumber() &&
        one.getGender() == two.getGender()
    )
    {
        return true;
    }
    else
    {
        return false;
    }
}

// std::string Student::genderToString(Student::Gender gender)
// {
//     switch (gender) 
//     {
//     case Student::Gender::male :
//         return "male";
//         break;
//     case Student::Gender::female :
//         return "female";
//         break;
//     case Student::Gender::other :
//         return "other";
//         break;
//     default:
//         return "";
//     }
// }



