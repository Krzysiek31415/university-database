#pragma once
#include "Student.hpp"
#include <memory>
#include <string>
#include <vector>

void mainMenu();
class UniversityDb 
{
    std::string universityName_{};
    std::vector<std::shared_ptr<Student>> university_{};

public:
    UniversityDb();

    UniversityDb(std::string universityName);

    std::string getUniversityName() const;

    std::vector<std::shared_ptr<Student>>& getUniversityVector();

    void universityMenu();

    void addNewStudent(std::shared_ptr<Student> student);

    void printUniversity();

    std::vector<std::shared_ptr<Student>> searchBySurname(std::string surname);

    Student searchByPESEL(std::string PESEL);

    std::shared_ptr<Student> searchByIndexNumber(std::string indexNumber);

    void sortBySurname();

    void sortByPESEL();

    //void deleteByIndexNumber(std::string indexNumber);

    void deleteByIndexNumber2(std::string indexNumber);

    void writeToFile(const std::string & fileName);

    void loadFromFile(const std::string & fileName);
};



