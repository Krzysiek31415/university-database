#pragma once
#include <string>
#include <vector>
#include "Student.hpp"
#include <iostream>
#include <algorithm>
#include <iomanip>

class UniversityDb
{
    std::string universityName_;
    std::vector<Student> university_;
public:
    UniversityDb(){}
    UniversityDb(std::string universityName)
    :universityName_(universityName)
    {}
    UniversityDb & addStudent(Student student)
    {
        university_.push_back(student);
        return *this;
    }
    void printUniversity()
    {
        std::cout<<std::right<<std::setw(50)<<universityName_<<"\n";
        std::cout<<std::cout.fill('-') << std::setw(95)<<"\n   ";
        std::cout.fill(' ');
        std::vector<std::string> texts{"Name","Surname","Address","Index Number","PESEL","Gender"};
        for(auto data: texts)
        {
            std::cout<<std::left<<std::setw(13)<<data<<"| ";
        }
        std::cout<<std::cout.fill('-')  << std::setw(93)<<"\n";
        std::cout<<"\n";
        std::cout.fill(' ');
        size_t number{1};
        for(auto student: university_)
        {
            std::cout<<number++ << ". ";
            student.showStudent(); 
        }
            
    }
    void printStudent(size_t number)
    {
        if(number < university_.size())
        {
            std::cout<<number<<". ";
            university_[number].showStudent();
        }
    }
    void searchBySurname(std::string surname)
    {
        size_t number{1};
        std::cout<<"Search by Surname: "<<surname<<"\n";
        for(auto student: university_)
        {
            if(student.getSurname() == surname)
            {
                std::cout<<number++<<". ";
                student.showStudent();
            }
        }
    }
    void searchByPESEL(unsigned long PESEL)
    {
        std::cout<<"Search by PESEL: "<<PESEL<<"\n";
        for(auto student: university_)
        {
            if(student.getPESEL() == PESEL)
            {
                std::cout<<"1. ";
                student.showStudent();
            }
        }
    }
    std::vector<Student>::iterator searchByIndexNumber(unsigned long indexNumber)
    {
        std::cout<<"Search by index number: "<<indexNumber<<"\n";
        for(auto it = university_.begin(); it != university_.end(); ++it)
        {
            if(it->getIndexNumber() == indexNumber)
            {
                std::cout<<"-----------------dziala"<<"\n";
                return it;
            }

        }
        return university_.end();
    }
    void sortBySurname()
    {
        std::cout<<"Sort by surname: "<<"\n";
        std::sort( university_.begin(), university_.end(), [ ]( const Student& lhs, const Student& rhs )
        { 
            return lhs.getSurname() < rhs.getSurname();
        } );
    }
    void sortByPESEL()
    {
        std::cout<<"Sort by PESEL: "<<"\n";
        std::sort( university_.begin(), university_.end(), [ ]( const Student& lhs, const Student& rhs )
        {
            return lhs.getPESEL() < rhs.getPESEL();
        });
    }
    void deleteByIndexNumber(unsigned long indexNumber)
    {
        std::cout<<"Delete by index number: "<<indexNumber<<"\n";
        for(auto it = university_.begin(); it != university_.end(); ++it)
        {
            if(it->getIndexNumber() == indexNumber)
            {
                std::cout<<"ok";
            }

        }
    }
    void deleteByIndexNumber2(unsigned long indexNumber)
    {
        std::cout<<"Delete by index number: "<<indexNumber<<"\n";

        auto it = std::find_if(university_.begin(),university_.end(),[&indexNumber](const Student& obj)
        {
            return obj.getIndexNumber() == indexNumber;
        });
        it->showStudent();
        if(it != university_.end())
            university_.erase(it); 
          
    }

};