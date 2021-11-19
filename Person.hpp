#pragma once
#include <map>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


class Person 
{
public:
    static std::vector<int>  PESELcoefficients;
    static std::vector<std::string> descriptionPersonData;
    static std::map<char,std::string> Gender;

    Person(const std::string & name, const std::string & surname, const std::string & address,
           const std::string & PESEL, const std::string & gender);
    virtual ~Person();

    friend bool isNumber(const std::string& s);

    std::string getName() const ;
    std::string getSurname() const;
    std::string getAddress() const;
    //std::string getIndexNumber() const;
    std::string getPESEL() const;
    std::string getGender() const;
    std::string getEarnings() const;
    std::vector<std::string *> getPersonData() const;

    void setName(const std::string & name);
    bool setPESEL(const std::string & PESEL);

    //bool setIndexNumber(const std::string & indexNumber);

    void setGender(const std::string & gender);
    static void heading();
    //Person& fillInPersonData();
    void showPerson();
    //add function: changePersonData
    std::string getIndexNumber() const;
    friend bool operator== (const Person & one, const Person & two);
    //friend std::shared_ptr<Person> makePerson();

private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string PESEL_{};
    std::string gender_{};
public:
    std::string indexNumber_{"  ---"};
    std::string earnings_{"  ---"};
    std::vector<std::string *> personData_{};
private:
    bool validatePESEL(const std::string & PESEL);
    
};

bool isNumber(const std::string& s);



