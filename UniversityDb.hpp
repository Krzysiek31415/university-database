#pragma once
#include "Student.hpp"
#include <string>
#include <vector>
void mainMenu();
class UniversityDb 
{
    std::string universityName_{};
    std::vector<Student> university_{};

public:
    UniversityDb();
    UniversityDb(std::string universityName);
    std::string getUniversityName() const;
    void universityMenu();
    //void addExistingStudent(Student student);
    void addNewStudent(Student student);
    void printUniversity();
    void searchBySurname(std::string surname);
    void searchByPESEL(std::string PESEL);
    std::vector<Student>::iterator searchByIndexNumber(std::string indexNumber);
    void sortBySurname();
    void sortByPESEL();
    void deleteByIndexNumber(std::string indexNumber);
    void deleteByIndexNumber2(std::string indexNumber);

};

