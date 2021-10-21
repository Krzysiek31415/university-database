#pragma once
#include <iomanip>
#include <iostream>
#include <string>

class Student 
{
public:
    enum class Gender 
    {
        male,
        female,
        other
    };

public:
    Student(){}
    Student(const std::string & name, const std::string & surname, const std::string & address, const std::string & indexNumber,
    const std::string & PESEL, Gender gender=Student::Gender::other);

    friend Gender charToEnum(const char genderAbbreviation);
    friend bool isNumber(const std::string& s);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getIndexNumber() const;
    std::string getPESEL() const;
    Gender getGender() const;

    void setPESEL(const std::string & PESEL);
    void setIndexNumber(const std::string & indexNumber);

    Student& fillInStudentData();
    void showStudent();
    friend bool operator== (const Student & one,const Student & two);


private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string indexNumber_{};
    std::string PESEL_{};
    Gender gender_{};

    std::string genderToString(Gender gender);
    bool validatePESEL(const std::string & PESEL);
};

bool isNumber(const std::string& numberString);

