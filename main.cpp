#include "Menu.hpp"
#include "UniversityDb.hpp"
#include "Employee.hpp"
//#include "myTests.hpp"
#include <iostream>
#include "Person.hpp"
#include <algorithm>
#include <cctype>
//#include "Student.hpp"
#include "Student2.hpp"
#include <string>
#include <vector>
#include <numeric>
#include <type_traits>
#include <typeinfo>

// void tests()
// {
//     std::cout<<"Sorted by surname: "             <<sortBySurnameTest()<<std::endl;
//     std::cout<<"Sorted by PESEL: "               <<sortByPESELTest()<<std::endl;
//     std::cout<<"Add new student: "               <<addStudentTest()<<std::endl;
//     std::cout<<"Delete student by index number: "<<deleteByIndexNumberTest()<<std::endl;
//     std::cout<<"Search by surname:\n"            <<searchBySurnameTest()<<std::endl;
//     std::cout<<"Search by PESEL:\n"              <<searchByPESELtest()<<std::endl;
    
//     std::cout<<"Show database: \n";
//     showDatabaseTest();
// }


int main()
{   

    //tests();

    mainMenu();

    // try
    // {
    //     Student Patryk("Patryk", "Burak", "Pichorowice 37", "123456", "90052904377", Student::Gender::male);
    // }
    // catch(const std::exception& e)
    // {
    //     std::cerr << e.what() << '\n';
    // }

    // Employee one{"jan","kowalski", "golanka", "333", "male", "100"};
    // Student two{"jan","kowalski", "golanka", "123","3", "male"};
    // std::cout<< one.getEarnings() << std::endl;
    // std::cout<< two.getEarnings() << std::endl;
    // std::cout << typeid(one).name() << std::endl;
    // std::cout << typeid(two).name() << std::endl;
    // std::cout << typeid(Student).name() << std::endl;

    // std::shared_ptr<Person> st1{new Student{"jan","a", "golanka", "123","3", "male"}};
    // std::shared_ptr<Person> st2{new Student{"jan","d", "golanka", "123","3", "male"}};
    // std::cout << typeid(*st1).name() << std::endl;
    // std::cout << (typeid(*st1).name() == typeid(Student).name()) << std::endl;
    //std::cout << typeid(st2).name() << std::endl;


    // std::cout << std::is_same< decltype(st1), std::shared_ptr<Student> >::value << std::endl;
    // std::shared_ptr<Person> emp1{new Employee{"jan","bi", "golanka", "4242", "m", "430"}};
    // std::shared_ptr<Person> emp2{new Employee{"jan","k", "golanka", "17464", "m", "12000"}};
    // std::shared_ptr<Person> emp3{new Employee{"jan","c", "golanka", "9463", "f", "700"}};
    
    // std::cout<< emp1->getEarnings() << std::endl;
    // std::cout<< emp2->getEarnings() << std::endl;
    // std::cout<< emp3->getEarnings() << std::endl;
    // std::cout<< st1->getEarnings() << std::endl;

    // std::cout<< emp1->getGender() << std::endl;
    // std::cout<< emp2->getGender() << std::endl;
    // std::cout<< emp3->getGender() << std::endl;

    // std::cout<< emp1->getPESEL() << std::endl;
    // std::cout<< emp2->getPESEL()  << std::endl;
    // std::cout<< emp3->getPESEL()  << std::endl;

    // UniversityDb UWr("UWr");
    // UWr.addNewPerson(st1);
    // UWr.addNewPerson(emp1);
    // UWr.addNewPerson(emp2);
    // UWr.addNewPerson(emp3);
    // UWr.printUniversity();
    // UWr.sortByEarnings();
    // UWr.printUniversity();
    // UWr.changeEarningsByPESEL("17464");
    // UWr.printUniversity();
    // // one.heading();
    // // one.showPerson();
    // std::cout << std::boolalpha << (one == one) << '\n';
    // std::cout << std::boolalpha << (one.getGender() == one.getGender()) << '\n';

    
    return 0;
}