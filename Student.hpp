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

private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string indexNumber_{};
    std::string PESEL_{};
    Gender gender_{};
    std::string genderToString(Gender gender);

public:
    Student(std::string name="", std::string surname="", std::string address="", 
    std::string indexNumber="", std::string PESEL="",Gender gender=Student::Gender::other);
    //Student(std::string name="", std::string surname="");
    friend Gender charToEnum(const char genderAbbreviation);
    friend bool isNumber(const std::string& s);
    // void setName(std::string name);
    // void setSurname(std::string surname);
    // void setAddress(std::string address);
    // void setIndexNumber(std::string indexNumber);
    // void setPESEL(std::string PESEL);
    // void setGender(Gender gender);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getIndexNumber() const;
    std::string getPESEL() const;
    Gender getGender() const;
    Student& fillInStudentData();
    void showStudent();
    friend bool operator== (const Student & one,const Student & two);
};

bool isNumber(const std::string& numberString);

