#pragma once
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

class Student 
{
public:
    // enum class Gender: char 
    // {
    //     male = 'm',
    //     female = 'f',
    //     other = 'o'
    // };

public:
    Student(){}
    Student(const std::string & name, const std::string & surname, const std::string & address, const std::string & indexNumber,
    const std::string & PESEL, const std::string & gender);

    //friend Gender charToEnum(const char genderAbbreviation);
    friend bool isNumber(const std::string& s);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getIndexNumber() const;
    std::string getPESEL() const;
    std::string getGender() const;

    void setPESEL(const std::string & PESEL);
    void setIndexNumber(const std::string & indexNumber);

    Student& fillInStudentData();
    std::string showStudent();
    friend bool operator== (const Student & one,const Student & two);


private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string indexNumber_{};
    std::string PESEL_{};
    std::string gender_{};
    static std::vector<std::string> Gender;
public:
    std::vector<std::string *> studentData{};

    //std::string genderToString(Gender gender);
    bool validatePESEL(const std::string & PESEL);
};

bool isNumber(const std::string& numberString);

