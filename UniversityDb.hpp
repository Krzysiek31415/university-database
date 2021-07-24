#pragma once
#include "Student.hpp"
#include <string>
#include <vector>

class UniversityDb 
{
    std::string universityName_;
    std::vector<Student> university_;

public:
    UniversityDb();
    UniversityDb(std::string universityName);
    void menu();
    void addExistingStudent(Student student);
    void addNewStudent();
    void printUniversity();
    void searchBySurname(std::string surname);
    void searchByPESEL(unsigned long PESEL);
    std::vector<Student>::iterator searchByIndexNumber(unsigned long indexNumber);
    void sortBySurname();
    void sortByPESEL();
    void deleteByIndexNumber(unsigned long indexNumber);
    void deleteByIndexNumber2(unsigned long indexNumber);
};

void mainMenu();