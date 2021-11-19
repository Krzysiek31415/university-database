#pragma once
#include "Student2.hpp"
#include "Person.hpp"
#include <memory>
#include <string>
#include <vector>

class UniversityDb 
{
    std::string universityName_{};
    std::vector<std::shared_ptr<Person>> university_{};

public:
    UniversityDb();

    UniversityDb(std::string universityName);

    std::string getUniversityName() const;

    std::vector<std::shared_ptr<Person>>& getUniversityVector();

    void universityMenu();

    void addNewPerson(std::shared_ptr<Person> person);

    void printUniversity();

    std::vector<std::shared_ptr<Person>> searchBySurname(const std::string & surname);

    std::shared_ptr<Person> searchByPESEL(const std::string & PESEL);

    std::shared_ptr<Person> searchByIndexNumber(std::string indexNumber);

    void sortBySurname();

    void sortByPESEL();

    void sortByEarnings();

    //void deleteByIndexNumber(std::string indexNumber);

    void deleteByIndexNumber2(std::string indexNumber);

    void changeEarningsByPESEL(std::string PESEL );

    void writeToFile(const std::string & fileName);

    void loadFromFile(const std::string & fileName);

    std::vector<std::string> lineToStringVector(std::string & line);

    //friend std::shared_ptr<Person> makePerson();
};



