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
std::string UniversityDb:: getUniversityName() const
{
    return universityName_;
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
    std::cout<<"        MENU\n";
    std::cout<<"1. Create new database.\n";
    std::cout<<"2. Choose a database.\n";
    std::cout<<"3. Delete database.\n";
    std::cout<<"4. Exit.\n ";
    static std::vector<UniversityDb> universities;
    
    int position;
    std::cin>>position;
    switch(position)
    {
        case 1:
        {
            std::cout<<"    CREATING NEW UNIVERSITY DATABASE \n";
            std::cout<<"Name of university: \n";
            std::string nameOfUniversity{};
            std::cin>>std::ws; 
            std::getline(std::cin, nameOfUniversity);
            UniversityDb university(nameOfUniversity); 
            universities.push_back(university);
            break;
        }   
        case 4:
        {
            std::exit(0);
        }
        case 2:
        {
            std::cout<<"    CHOOSING A DATABASE \n";
            if(universities.empty())
            {
                std::cout<<"Database is empty.\n";
            }
            else
            {
                size_t n = 0;
                for(auto elem: universities)
                {
                    std::cout<<++n<<". "<<elem.getUniversityName()<<"\n";
                }
                size_t selectionDatabase;
                std::cin>>selectionDatabase;
                while(true)
                {
                    universities[selectionDatabase-1].universityMenu();
                }
                

            }
            
        }
            
    }


}

void UniversityDb::universityMenu()
{
    std::cout<<"    "<<this->getUniversityName();
    std::cout<<" MENU\n ";
    std::cout<<"1. Show database.\n";
    std::cout<<"2. Add new student.\n ";
    std::cout<<". Add existing student.\n ";
    std::cout<<". Search by surname.\n ";
    std::cout<<". Search by index number.\n ";
    std::cout<<". Search by PESEL.\n ";
    std::cout<<". Sort by index number.\n ";
    std::cout<<". Sort by surname.\n ";
    std::cout<<". Exit.\n ";

    int position;
    std::cin>>position;
    switch(position)
    {
        case 1:
        {
            std::cout<<"    "<<this->getUniversityName()<<"\n";
            //std::cout<<"Name of university: \n";
            this->printUniversity();
            break;
        }   
        case 2:
        {
            std::cout<<"    "<<this->getUniversityName()<<"\n";
            this->addNewStudent();
            break;
        } 
        case 4:
        {
            std::exit(0);
        }
    }
}