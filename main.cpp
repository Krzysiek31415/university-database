#include "Student.hpp"
#include "UniversityDb.hpp"
#include "myTests.hpp"
#include <iostream>

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

    
    
    return 0;
}