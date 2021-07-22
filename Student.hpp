#pragma once
#include<string>
#include<iostream>
#include <iomanip>
class Student
{
    enum class Gender{male, female, other};

    std::string name_;
    std::string surname_;
    std::string address_;
    unsigned long indexNumber_;
    unsigned long PESEL_;
    Gender gender_;

public:
    Student(){}
    Student(std::string name, std::string surname, std::string address,
    unsigned long indexNumber, unsigned long PESEL, Gender gender)
    :   name_(name),
        surname_(surname),
        address_(address),
        indexNumber_(indexNumber),
        PESEL_(PESEL),
        gender_(gender)
        {}
    Student(std::string name, std::string surname)
    :   Student(name, surname, "", 0UL, 0UL, Gender::other)
        {}
    void setName(std::string name){name_ = name;}
    void setSurname(std::string surname){surname_ = surname;}
    void setAddress(std::string address){address_ = address;}
    void setIndexNumber(unsigned long indexNumber){indexNumber_= indexNumber;}
    void setPESEL(unsigned long PESEL){PESEL_= PESEL;}
    void setGender(Gender gender){gender_ = gender;}

    std::string getName() const {return name_;}
    std::string getSurname() const {return surname_;}
    std::string getAddress() const {return address_;}
    unsigned long getIndexNumber() const {return indexNumber_;}
    unsigned long getPESEL() const {return PESEL_;}
    Gender getGender() const {return gender_;}

    void showStudent()
    {
        std::cout<<std::left<<std::setw(13)<<getName()<<"| ";
        std::cout<<std::left<<std::setw(13)<<getSurname()<<"| ";
        std::cout<<std::left<<std::setw(13)<<getAddress()<<"| ";
        std::cout<<std::left<<std::setw(13)<<getIndexNumber()<<"| ";
        std::cout<<std::left<<std::setw(13)<<getPESEL()<<"| ";
        std::cout<<std::left<<std::setw(13)<<(int)getGender()<<"| \n";
    }
};