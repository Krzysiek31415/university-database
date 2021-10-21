#include "Student.hpp"
#include "UniversityDb.hpp"
#include "myTests.hpp"
#include <iostream>

#include <algorithm>
#include <cctype>
#include "Student.hpp"
#include <string>
#include <vector>
#include <numeric>

void tests()
{
    std::cout<<"Sorted by surname: "             <<sortBySurnameTest()<<std::endl;
    std::cout<<"Sorted by PESEL: "               <<sortByPESELTest()<<std::endl;
    std::cout<<"Add new student: "               <<addStudentTest()<<std::endl;
    std::cout<<"Delete student by index number: "<<deleteByIndexNumberTest()<<std::endl;
    std::cout<<"Search by surname:\n"            <<searchBySurnameTest()<<std::endl;
    std::cout<<"Search by PESEL:\n"              <<searchByPESELtest()<<std::endl;
    
    std::cout<<"Show database: \n";
    showDatabaseTest();
}


int main()
{   
    //tests();
    mainMenu();
    try
    {
        Student Patryk("Patryk", "Burak", "Pichorowice 37", "123456", "90052904377", Student::Gender::male);
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
    

    
    
    return 0;
}