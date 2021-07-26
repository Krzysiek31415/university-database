#pragma once
#include <iomanip>
#include <iostream>
#include <string>
class Student {
public:
    enum class Gender {
        male,
        female,
        other
    };

private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    unsigned long indexNumber_{};
    unsigned long PESEL_{};
    Gender gender_{};
    std::string genderToString(Gender gender);

public:
    //Student();
    Student(std::string name, std::string surname, std::string address, 
    unsigned long indexNumber, unsigned long PESEL,Gender gender);
    Student(std::string name, std::string surname);
    void setName(std::string name);
    void setSurname(std::string surname);
    void setAddress(std::string address);
    void setIndexNumber(unsigned long indexNumber);
    void setPESEL(unsigned long PESEL);
    void setGender(Gender gender);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    unsigned long getIndexNumber() const;
    unsigned long getPESEL() const;
    Gender getGender() const;
    //Student& fillInStudentData();
    void showStudent();
};

