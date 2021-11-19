#include "UniversityDb.hpp"
#include "Student2.hpp"
#include "Person.hpp"
#include "Employee.hpp"
#include <algorithm>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <string>
#include <vector>

// add class Interface with menu, mainmenu, enter input control data...
//std::shared_ptr<Person> makePerson();

void UniversityDb::writeToFile(const std::string & path)
{
    std::fstream file; 
    file.open(path, std::ios::out | std::ios::trunc); //, std::ios::out | std::ios::trunc);
    if(file.good())
    {
        //file << this->getUniversityName() << '\n';
        for(const auto & student: this->getUniversityVector())
        {
            for(const auto & data: student->getPersonData())
            {
                file << *data << "|";
            }
            file <<'\n';
        }
        file.close();
    }
    else
    {
        std::cout<< "File open error.\n";
    }
}

std::vector<std::string> UniversityDb::lineToStringVector(std::string & line)
{
    // add if line has good data: if has 6 |
    std::vector<std::string> data;
    size_t beginData{};
    size_t endData{};
    while(endData != std::string::npos)
    {
        endData = line.find("|", beginData);
        data.push_back(line.substr(beginData, endData-beginData));
        beginData = endData + 1; 
        if(endData == line.size()-1)
        {
            break;
        }
    }
    return data;
}

void UniversityDb::loadFromFile(const std::string & path)
{
    std::fstream file; 
    file.open(path, std::ios::in ); 
    if(file.good())
    {
        std::string line;
        while(!file.eof())
        {
            std::getline(file,line);
            // if(lineNr++ == 0) // if in first line is name of University
            // {
            //     continue;
            // }
            std::vector<std::string> data = lineToStringVector(line);
            // if(data.size() != 7)
            // {
            //     continue;
            // }
            if(isNumber(data[3]))
            {
                std::shared_ptr<Student> student{new Student{ data[0], data[1], data[2], data[3], data[4], data[5]}};
                this->addNewPerson(student);
            }
            else
            {
                std::shared_ptr<Employee> employee{new Employee{ data[0], data[1], data[2], data[4], data[5], data[6]}};
                this->addNewPerson(employee);
            }
            
            
        }
        file.close();
    }
    else
    {
        std::cout<< "File open error.\n";
    }
}


UniversityDb::UniversityDb(std::string universityName)
    : universityName_(universityName)
{
}
std::string UniversityDb:: getUniversityName() const
{
    return universityName_;
}

std::vector<std::shared_ptr<Person>>& UniversityDb::getUniversityVector() 
{
    return university_;
}

void UniversityDb::addNewPerson(std::shared_ptr<Person> person)
{
    university_.push_back(person);
}

void UniversityDb::printUniversity()
{
    // add 
    std::cout << std::right << std::setw(50) << universityName_ << "\n";
    std::cout << std::cout.fill('-') << std::setw(99) << "\n   ";
    std::cout.fill(' ');
    std::vector<std::string> texts { "Name", "Surname", "Address", "Index Number", "PESEL", "Gender", "Earnings" };
    for (const auto & data : texts) {
        std::cout << std::left << std::setw(13) << data << "| ";
    }
    std::cout << std::cout.fill('-') << std::setw(99) << "\n";
    std::cout << "\n";
    std::cout.fill(' ');
    size_t number {1};
    for (const auto & student : university_) {
        std::cout << number++ << ". ";
        student->showPerson();
    }
    std::cout<<"\n";
}

std::vector<std::shared_ptr<Person>> UniversityDb::searchBySurname(const std::string & surname)
{
    std::vector<std::shared_ptr<Person>> students{};
    std::copy_if( university_.begin(),
                  university_.end(), 
                  std::back_inserter(students),
                  [&surname](auto elem)
                  { return elem->getSurname() == surname;}
    );
    // move to menu::case or to class interface
    if( !students.size() ){
        std::cout<<"There is no such surname.\n";
    }
    else{
        for(const auto & student: students){
            student->showPerson();
        }
    }
    return students;
}

std::shared_ptr<Person> UniversityDb::searchByPESEL(const std::string & PESEL)
{
    auto student = std::find_if( university_.begin(), university_.end(), 
                                 [&PESEL](auto elem)
                                 { return elem->getPESEL() == PESEL;}
    );
    //move display student to menu::case or in future to class interface
    if(student == university_.end()){
        std::cout<<"There is no such PESEL.\n";
        return nullptr;
    }
    else{
        std::cout << "1. ";
        (*student)->showPerson();
    }
    return *student;
}
// std::shared_ptr<Student> UniversityDb::searchByIndexNumber(std::string indexNumber)
// {
//     // now not use
//     // make stl
//     std::cout << "Search by index number: " << indexNumber << "\n";
//     for (auto it = university_.begin(); it != university_.end(); ++it) {
//         if ((*it)->getIndexNumber() == indexNumber) {
//             std::cout << "-----------------dziala"
//                       << "\n";
//             return (*it);
//         }
//     }
//     return nullptr;
// }
void UniversityDb::sortBySurname()
{
    std::sort(university_.begin(), university_.end(),
        [](auto & lhs, auto & rhs) { return lhs->getSurname() < rhs->getSurname(); });
}
void UniversityDb::sortByPESEL()
{
    std::sort(university_.begin(), university_.end(),
        [](auto & lhs, auto & rhs) { return lhs->getPESEL() < rhs->getPESEL(); });
}


void UniversityDb::sortByEarnings()
{
    std::sort(university_.begin(), university_.end(),
        [](auto & lhs, auto & rhs) { return true;
            if( typeid(*lhs).name() == typeid(Student).name() ) 
            {
                return 0 > std::stod( rhs->getEarnings() ); 
            }
            else if( typeid(*rhs).name() == typeid(Student).name() ) 
            {
                return std::stod( lhs->getEarnings() ) > 0; 
            }
            else
            {
                return std::stod( lhs->getEarnings() ) > std::stod( rhs->getEarnings() ); 
            }
        }
    );
}
// void UniversityDb::deleteByIndexNumber(std::string indexNumber)
// {
//     // leve one version
//     // make stl
//     std::cout << "Delete by index number: " << indexNumber << "\n";
//     for (auto it = university_.begin(); it != university_.end(); ++it) {
//         if (it->getIndexNumber() == indexNumber) {
//             std::cout << "ok";
//         }
//     }
// }
void UniversityDb::deleteByIndexNumber2(std::string indexNumber)
{
    //use stl
    if(university_.empty())
    {
        return;
    }
    auto it = std::find_if(university_.begin(), university_.end(),
        [&indexNumber](auto obj) { return obj->getIndexNumber() == indexNumber; });
    std::cout<<"Deleted student: ";
    (*it)->showPerson();
    if (it != university_.end())
    {
        university_.erase(it);
    }
    else
    {
        std::cout<<"There is no such index number. \n";
    }
}

void UniversityDb::changeEarningsByPESEL(std::string PESEL )
{
    //use stl
    if(university_.empty())
    {
        return;
    }
    auto it = std::find_if(university_.begin(), university_.end(),
        [&PESEL](auto obj) { return obj->getPESEL() == PESEL; });
    
    if (it != university_.end())
    {
        Person::heading();
        (*it)->showPerson();
        std::cout<<"Change the payout to:  ";
        std::cin >> std::ws;
        std::string temp;
        std::getline(std::cin, temp);
        if(isNumber(temp))
        {
            (*it)->earnings_ = temp;
        } 
        else
        {
            std::cout << "It is not a number. Try once again.\n";
        }
    }
    else
    {
        std::cout<<"There is no such PESEL. \n";
    }
}


void UniversityDb::universityMenu()
{
    bool exitMenu{};
    std::string position{};
    while(!exitMenu)
    {
        do{
            std::cout<<"    "<<this->getUniversityName();
            std::cout<<" MENU\n";
            std::cout<<"1. Show database.\n";
            std::cout<<"20. Add new student.\n";
            std::cout<<"21. Add new employee.\n";
            std::cout<<"3. Sort by PESEL.\n";
            std::cout<<"4. Sort by surname.\n";
            std::cout<<"41. Sorting by earnings.\n";
            std::cout<<"5. Search by surname.\n";
            std::cout<<"6. Search by PESEL.\n";
            std::cout<<"7. Delete by index number.\n";
            std::cout<<"71. Change earnings.\n";
            std::cout<<"8. Save database to file.\n";
            std::cout<<"9. Load from file.\n";
            std::cout<<"0. Go to the main menu.\n";
            //std::cout<<"4. Exit.\n\n"; save in file and read from file
            std::cout<<"Select an option number: ";
            std::cin >> position;
            if(!isNumber(position))
            {
                std::cout << "Error. Please enter it again." << std::endl;
            }
            else
            {
                break;
            }
        }while(true);

        switch(atoi(position.c_str()))
        {
            case 1:
            {
                std::cout<<"    "<<this->getUniversityName()<<"\n";
                this->printUniversity();
                if(university_.empty())
                {
                    std::cout<<"        University database is empty. \n\n";
                }
                break;
            }   
            case 20:
            {
                std::cout<<"    "<<this->getUniversityName()<<"\n";
                std::cout<<"Adding new student: \n";
                this->addNewPerson(makeStudent());
                break;
            } 
            case 21:
            {
                std::cout<<"    "<<this->getUniversityName()<<"\n";
                std::cout<<"Adding new employee: \n";
                this->addNewPerson(makeEmployee());
                break;
            } 
            case 3:
            {
                std::cout<<"Sorting by PESEL:";
                this->sortByPESEL();
                this->printUniversity();
                if(university_.empty())
                {
                    std::cout<<"        University database is empty. \n\n";
                }
                break;
            }
            case 4:
            {
                std::cout<<"Sorting by surname:";
                if(university_.empty())
                {
                    std::cout<<"        University database is empty. \n\n";
                }
                this->sortBySurname();
                this->printUniversity();
                break;
            }
            case 41:
            {
                std::cout<<"Sorting by earnings:";
                if(university_.empty())
                {
                    std::cout<<"        University database is empty. \n\n";
                }
                this->sortByEarnings();
                this->printUniversity();
                break;
            }
            case 5:
            {
                std::cout<<"Search by surname: ";
                std::string surname{};
                std::cin>>std::ws; 
                std::getline(std::cin, surname);
                this->searchBySurname(surname);
                break;
            }
            case 6:
            {
                std::cout<<"Search by PESEL. \nEnter PESEL: ";
                std::string PESEL{};
                std::cin>>PESEL;
                this->searchByPESEL(PESEL);
                break;
            }
            case 7:
            {
                std::cout<<"Delete by index number: ";
                std::string indexNumber{};;
                std::cin>>indexNumber;
                this->deleteByIndexNumber2(indexNumber);
                break;
            }
            case 71:
            {
                // change cin to getline
                std::cout<<"Delete by index number: ";
                std::string PESEL{};;
                std::cin>>PESEL;
                this->changeEarningsByPESEL(PESEL);
                break;
            }
            std::cout<<"71. Change earnings.\n";
            case 8:
            {
                std::cout<<"Save database to file. \n[path]:";
                std::string path{};
                std::cin >> std::ws;
                std::getline(std::cin, path);
                writeToFile(path);
                break;
            }
            case 9:
            {
                std::cout<<"Load database from file. \n[path]: ";
                std::string path{};
                std::cin >> std::ws;
                std::getline(std::cin, path);
                loadFromFile(path);
                break;
            }
            case 0:
            {
                exitMenu = true;
                break;
            }
            default:
            {
                std::cout<<"Error. Please enter option number again.\n";
                break;
            }
        }
    }
}


