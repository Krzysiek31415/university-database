#pragma once
#include <map>
#include <iomanip>
#include <iostream>
#include <memory>
#include <string>
#include <vector>


// add static size_t numberStudents; in constructor inc, in d-tor dec;
// add class File{}, load to file, writ to file, parseString to vector, c-tor, d-tor,
//                   add pole std::fstream
class Student 
{
public:
    Student(){}
    Student(const std::string & name, const std::string & surname, const std::string & address, const std::string & indexNumber,
    const std::string & PESEL, const std::string & gender);

    friend bool isNumber(const std::string& s);

    std::string getName() const;
    std::string getSurname() const;
    std::string getAddress() const;
    std::string getIndexNumber() const;
    std::string getPESEL() const;
    std::string getGender() const;
    std::vector<std::string *> getStudentData() const;

    bool setPESEL(const std::string & PESEL);
    bool setIndexNumber(const std::string & indexNumber);
    void setGender(const std::string & gender);

    Student& fillInStudentData();
    void showStudent();
    //add function: changeStudentData
    friend bool operator== (const Student & one, const Student & two);
    friend std::shared_ptr<Student> makeStudent();


private:
    std::string name_{};
    std::string surname_{};
    std::string address_{};
    std::string indexNumber_{};
    std::string PESEL_{};
    std::string gender_{};
    std::vector<std::string *> studentData_{};
public:
    bool validatePESEL(const std::string & PESEL);
    static std::map<char,std::string> Gender;
};

bool isNumber(const std::string& numberString);



