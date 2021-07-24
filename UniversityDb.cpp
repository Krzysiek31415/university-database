#include "UniversityDb.hpp"
#include "Student.hpp"
#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

UniversityDb::UniversityDb(std::string universityName)
    : universityName_(universityName)
{
}
void menu()
{
    std::cout<<" MENU\n ";
    //std::cout<<"1. Create new database.\n";
    //std::cout<<". Choose a database.\n";
    std::cout<<". Show database\n";
    std::cout<<". Add new student.\n ";
    std::cout<<". Add existing student.\n ";
    std::cout<<". Search by surname.\n ";
    std::cout<<". Search by index number.\n ";
    std::cout<<". Search by PESEL.\n ";
    std::cout<<". Sort by index number.\n ";
    std::cout<<". Sort by surname.\n ";
    std::cout<<". Exit.\n ";
}
void UniversityDb::addExistingStudent(Student student)
{
    university_.push_back(student);
}
void UniversityDb::addNewStudent()
{
    std::cout<<"Adding new student: \n";
    std::string name; 
    std::string surname; 
    std::string address; 
    unsigned long indexNumber;
    unsigned long PESEL; 
    Student::Gender gender;

    std::cout<<"Name: "; std::cin>>name;
    std::cout<<"Surname: "; std::cin>>surname;
    std::cout<<"Address: "; std::cin>>std::ws;std::getline(std::cin,address);
    std::cout<<"Index number: "; std::cin>>indexNumber;
    std::cout<<"PESEL: "; std::cin>>PESEL;
    
    Student student(name,surname,address,indexNumber,PESEL,Student::Gender::male);
    university_.push_back(student);
    
}
void UniversityDb::printUniversity()
{
    std::cout << std::right << std::setw(50) << universityName_ << "\n";
    std::cout << std::cout.fill('-') << std::setw(95) << "\n   ";
    std::cout.fill(' ');
    std::vector<std::string> texts { "Name", "Surname", "Address", "Index Number", "PESEL", "Gender" };
    for (auto data : texts) {
        std::cout << std::left << std::setw(13) << data << "| ";
    }
    std::cout << std::cout.fill('-') << std::setw(93) << "\n";
    std::cout << "\n";
    std::cout.fill(' ');
    size_t number { 1 };
    for (auto student : university_) {
        std::cout << number++ << ". ";
        student.showStudent();
    }
}

void UniversityDb::searchBySurname(std::string surname)
{
    size_t number {1};
    std::cout << "Search by Surname: " << surname << "\n";
    for (auto student : university_) {
        if (student.getSurname() == surname) {
            std::cout << number++ << ". ";
            student.showStudent();
        }
    }
}
void UniversityDb::searchByPESEL(unsigned long PESEL)
{
    std::cout << "Search by PESEL: " << PESEL << "\n";
    for (auto student : university_) {
        if (student.getPESEL() == PESEL) {
            std::cout << "1. ";
            student.showStudent();
        }
    }
}
std::vector<Student>::iterator UniversityDb::searchByIndexNumber(unsigned long indexNumber)
{
    std::cout << "Search by index number: " << indexNumber << "\n";
    for (auto it = university_.begin(); it != university_.end(); ++it) {
        if (it->getIndexNumber() == indexNumber) {
            std::cout << "-----------------dziala"
                      << "\n";
            return it;
        }
    }
    return university_.end();
}
void UniversityDb::sortBySurname()
{
    std::cout << "Sort by surname: "
              << "\n";
    std::sort(university_.begin(), university_.end(),
        [](const Student& lhs, const Student& rhs) { return lhs.getSurname() < rhs.getSurname(); });
}
void UniversityDb::sortByPESEL()
{
    std::cout << "Sort by PESEL: "
              << "\n";
    std::sort(university_.begin(), university_.end(),
        [](const Student& lhs, const Student& rhs) { return lhs.getPESEL() < rhs.getPESEL(); });
}
void UniversityDb::deleteByIndexNumber(unsigned long indexNumber)
{
    std::cout << "Delete by index number: " << indexNumber << "\n";
    for (auto it = university_.begin(); it != university_.end(); ++it) {
        if (it->getIndexNumber() == indexNumber) {
            std::cout << "ok";
        }
    }
}
void UniversityDb::deleteByIndexNumber2(unsigned long indexNumber)
{
    std::cout << "Delete by index number: " << indexNumber << "\n";

    auto it = std::find_if(university_.begin(), university_.end(),
        [&indexNumber](const Student& obj) { return obj.getIndexNumber() == indexNumber; });
    it->showStudent();
    if (it != university_.end())
        university_.erase(it);
}

void mainMenu()
{
    std::cout<<" MENU\n ";
    std::cout<<"1. Create new database.\n";
    std::cout<<". Choose a database.\n";
    std::cout<<"1. Delete database.\n";
    std::cout<<". Exit.\n ";

    std::vector<UniversityDb> universities;
    int position;
    std::cin>>position;
    switch(position)
    {
        case 1:
            std::string nameOfUniversity;
            std::cin>>std::ws; 
            std::getline(std::cin, nameOfUniversity);
            UniversityDb university(nameOfUniversity); 
            break;
        case 2:
            
    }


}