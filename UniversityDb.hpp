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
    std::vector<Student>& getUniversityVector();
    void universityMenu();
    //void addExistingStudent(Student student);
    void addNewStudent(Student student);
    void printUniversity();
    std::vector<Student> searchBySurname(std::string surname);
    Student searchByPESEL(std::string PESEL);
    std::vector<Student>::iterator searchByIndexNumber(std::string indexNumber);
    void sortBySurname();
    void sortByPESEL();
    void deleteByIndexNumber(std::string indexNumber);
    void deleteByIndexNumber2(std::string indexNumber);
    friend bool operator== (const UniversityDb & one, const UniversityDb & two);
};

