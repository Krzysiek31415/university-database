#include <algorithm>
#include <cctype>
#include <exception>
#include <memory>
#include <numeric>
#include "Student.hpp"
#include <string>
#include <vector>
// add change student data

std::map<char,std::string> Student::Gender{{'m',"male"},{'f',"female"}, {'o',"other"}};

bool isNumber(const std::string & numberString)
{
    return !numberString.empty() && 
            std::find_if(numberString.begin(), 
                         numberString.end(), 
                         [](unsigned char c) { return !std::isdigit(c); }) == numberString.end();
}

Student::Student(const std::string & name, const std::string & surname, const std::string & address, const std::string & indexNumber,
    const std::string & PESEL, const std::string & gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
{
    setPESEL(PESEL);
    setIndexNumber(indexNumber);
    setGender(gender);
    studentData_.push_back(&name_);
    studentData_.push_back(&surname_);
    studentData_.push_back(&address_);
    studentData_.push_back(&indexNumber_);
    studentData_.push_back(&PESEL_);
    studentData_.push_back(&gender_);

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
    return true;
    if( ( PESEL.back() - '0' ) == 0)
    {
        return ( sum % 10 ) == 0;
    }
    else
    {
        return ( PESEL.back() - '0' ) == 10 - ( sum % 10 );
    }
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

bool Student::setPESEL(const std::string & PESEL)
{
    if(validatePESEL(PESEL))
    {
        PESEL_ = PESEL;
        return true;
    }
    else
    {
        return false;
    }
}

void Student::setGender(const std::string & gender)
{
    if(gender.size() != 1 || (gender[0] != 'm' && gender[0] != 'f'))
    {
        gender_ = Gender['o'];
    }
    else
    {
        gender_ = Gender[gender[0]];
    }
    
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
std::vector<std::string *> Student::getStudentData() const
{
    return studentData_;
}

Student& Student::fillInStudentData()
{
    std::vector<std::string> descriptionStudentData{"Name: ", "Surname: ", "Address: ", "Index number: ",
                                        "PESEL: ", "Gender [m - male, f - female, o - other]: "};
    std::vector<std::string> tempStudentData(7);

    for(size_t n = 0; n < descriptionStudentData.size(); ++n)
    {
        std::cout << descriptionStudentData[n];
        std::cin >> std::ws;
        std::getline(std::cin, tempStudentData[n]);
    }
    //return Student::Student{};

    // std::cout<<"Name: "; std::cin >> std::ws;
    // std::getline(std::cin,name_);
    // studentData_.push_back(&name_);

    // std::cout<<"Surname: "; std::cin >> std::ws;
    // std::getline(std::cin,surname_);

    // std::cout<<"Address: "; std::cin >> std::ws;
    // std::getline(std::cin,address_);

    // std::string temp;
    // std::cout<<"Index number: "; std::cin>>std::ws;std::getline(std::cin, indexNumber_);
    // while(!isNumber(indexNumber_))
    // {
    //     std::cout<<"Error. It is not a index number. Please enter it again. \n";
    //     std::cout<<"Index number: "; std::cin>>std::ws;std::getline(std::cin, indexNumber_);
    // }

    // std::cout<<"PESEL: "; std::cin>>std::ws;std::getline(std::cin, PESEL_);
    // while(!isNumber(PESEL_))
    // {
    //     std::cout<<"Error. It is not a PESEL. Please enter it again. \n";
    //     std::cout<<"PESEL number: "; std::cin>>std::ws;std::getline(std::cin, PESEL_);
    // }

    // std::cout<<"Gender [male - m, female - f, other - o]: ";
    // std::cin>>std::ws;std::getline(std::cin,gender_);


    return *this;
}

std::shared_ptr<Student> makeStudent()
{
    std::vector<std::string> descriptionStudentData{"Name: ", "Surname: ", "Address: ", "Index number: ",
                                        "PESEL: ", "Gender [m - male, f - female, o - other]: "};
    std::vector<std::string> temp(7);

    for(size_t n = 0; n < descriptionStudentData.size(); ++n)
    {
        std::cout << descriptionStudentData[n];
        std::cin >> std::ws;
        std::getline(std::cin, temp[n]);
    }
    std::shared_ptr<Student> student{new Student{temp[0], temp[1], temp[2], temp[3], temp[4], temp[5]}};
    return student;
}

void Student::showStudent()
{
    for(auto data: this->studentData_)
    {
        std::cout << std::left << std::setw(13) << *data << "| ";
    }
    std::cout << '\n';
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



