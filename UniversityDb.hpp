#pragma once
#include <string>
#include <vector>
#include "Student.hpp"




class UniversityDb
{
    std::string universityName_;
    std::vector<Student> university_;
public:
    UniversityDb();
    UniversityDb(std::string universityName);
    UniversityDb & addStudent(Student student);
    void printUniversity();
    void printStudent(size_t number);
    void searchBySurname(std::string surname);
    void searchByPESEL(unsigned long PESEL);
    std::vector<Student>::iterator searchByIndexNumber(unsigned long indexNumber);
    void sortBySurname();
    void sortByPESEL();
    void deleteByIndexNumber(unsigned long indexNumber);
    void deleteByIndexNumber2(unsigned long indexNumber);

};