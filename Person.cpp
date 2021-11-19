#include "Person.hpp"
#include <string>
#include <algorithm>
#include <cctype>
#include <exception>
#include <memory>
#include <numeric>
#include <vector>

std::vector<int> Person::PESELcoefficients{1, 3, 7, 9, 1, 3, 7, 9, 1, 3};

// std::vector<std::string> Person::descriptionPersonData{"Name: ", "Surname: ", "Address: ", "Index number: ",
//                                         "PESEL: ", "Gender [m - male, f - female, o - other]: "};


std::map<char,std::string> Person::Gender{{'m',"male"},{'f',"female"}, {'o',"other"}};

bool isNumber(const std::string & numberString)
{
    return !numberString.empty() && 
            std::find_if(numberString.begin(), 
                         numberString.end(), 
                         [](unsigned char c) { return !std::isdigit(c); }) == numberString.end();
}

Person::Person(const std::string & name, const std::string & surname, const std::string & address, 
    const std::string & PESEL, const std::string & gender)
    : name_(name)
    , surname_(surname)
    , address_(address)
{
    setPESEL(PESEL);
    setGender(gender);
    personData_.push_back(&name_);
    personData_.push_back(&surname_);
    personData_.push_back(&address_);
    personData_.push_back(&PESEL_);
    personData_.push_back(&gender_);
    // auto it = personData_.begin();
    // personData_.insert(it + 3, &indexNumber_);
    // personData_.insert(it + 6, &earnings_);
}

Person::~Person()
{
}

bool Person::validatePESEL(const std::string & PESEL)
{
    // do not work good
    std::vector<int> PESELnumbers;

    std::transform(PESEL.begin(), 
                   std::prev( PESEL.end() ),
                   std::back_inserter(PESELnumbers), 
                   [](auto c) mutable { return c - '0'; });

    return true;

    long long sum = std::inner_product(PESELcoefficients.begin(),
                                       PESELcoefficients.end(),
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

// bool Person::setIndexNumber(const std::string & indexNumber)
// {
//     if(isNumber(indexNumber))
//     {
//         indexNumber_ = indexNumber;
//         return true;
//     }
//     else
//     {
//         return false;
//     }
// }
void Person::setName(const std::string & name)
{
    name_ = name;
}

bool Person::setPESEL(const std::string & PESEL)
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

void Person::setGender(const std::string & gender)
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

std::string Person::getName() const
{
    return name_;
}
std::string Person::getSurname() const
{
    return surname_;
}
std::string Person::getAddress() const
{
    return address_;
}
std::string Person::getIndexNumber() const
{
    return indexNumber_;
}
std::string Person::getPESEL() const
{
    return PESEL_;
}
std::string  Person::getGender() const
{
    return gender_;
}
std::string Person::getEarnings() const
{
    return earnings_;
}
std::vector<std::string *> Person::getPersonData() const
{
    return personData_;
}

// Person& Person::fillInPersonData()
// {
//     std::vector<std::string> tempPersonData(7);

//     for(size_t n = 0; n < descriptionPersonData.size(); ++n)
//     {
//         std::cout << descriptionPersonData[n];
//         std::cin >> std::ws;
//         std::getline(std::cin, tempPersonData[n]);
//     }
//     //return Person::Person{};

//     // std::cout<<"Name: "; std::cin >> std::ws;
//     // std::getline(std::cin,name_);
//     // studentData_.push_back(&name_);

//     // std::cout<<"Surname: "; std::cin >> std::ws;
//     // std::getline(std::cin,surname_);

//     // std::cout<<"Address: "; std::cin >> std::ws;
//     // std::getline(std::cin,address_);

//     // std::string temp;
//     // std::cout<<"Index number: "; std::cin>>std::ws;std::getline(std::cin, indexNumber_);
//     // while(!isNumber(indexNumber_))
//     // {
//     //     std::cout<<"Error. It is not a index number. Please enter it again. \n";
//     //     std::cout<<"Index number: "; std::cin>>std::ws;std::getline(std::cin, indexNumber_);
//     // }

//     // std::cout<<"PESEL: "; std::cin>>std::ws;std::getline(std::cin, PESEL_);
//     // while(!isNumber(PESEL_))
//     // {
//     //     std::cout<<"Error. It is not a PESEL. Please enter it again. \n";
//     //     std::cout<<"PESEL number: "; std::cin>>std::ws;std::getline(std::cin, PESEL_);
//     // }

//     // std::cout<<"Gender [male - m, female - f, other - o]: ";
//     // std::cin>>std::ws;std::getline(std::cin,gender_);


//     return *this;
// }

// std::shared_ptr<Person> makePerson()
// {
//     // std::vector<std::string> descriptionPersonData{"Name: ", "Surname: ", "Address: ", //"Index number: ",
//     //                                     "PESEL: ", "Gender [m - male, f - female, o - other]: "};
//     std::vector<std::string> temp(7);

//     for(size_t n = 0; n < Person::descriptionPersonData.size(); ++n)
//     {
//         std::cout << Person::descriptionPersonData[n];
//         std::cin >> std::ws;
//         std::getline(std::cin, temp[n]);
//     }
//     std::shared_ptr<Person> person{new Person{temp[0], temp[1], temp[2], temp[3], temp[4]}};
//     return person;
// }

void Person::showPerson()
{
    for(auto data: this->personData_)
    {
        std::cout << std::left << std::setw(13) << *data << "| ";
    }
    std::cout << '\n';
}

bool operator== (const Person & one,const Person & two)
{
    // if(one.getName() == two.getName() &&
    //     one.getSurname() == two.getSurname() &&
    //     one.getAddress() == two.getAddress() &&
    //     one.getPESEL() == two.getPESEL() &&
    //     one.getIndexNumber() == two.getIndexNumber() &&
    //     one.getGender() == two.getGender() &&
    //     one.getEarnings() == two.getEarnings())
    if(one.personData_ == two.personData_)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Person::heading()
{
    std::cout <<  std::setw(105) << std::cout.fill('-') << "\n";
    std::cout.fill(' ');
    std::vector<std::string> texts { "Name", "Surname", "Address", "Index Number", "PESEL", "Gender", "Earnings" };
    for (const auto & data : texts) {
        std::cout << std::left << std::setw(13) << data << "| ";
    }
    std::cout << std::cout.fill('-') << std::setw(105) << "\n";
    std::cout << "\n";
    std::cout.fill(' ');
}


