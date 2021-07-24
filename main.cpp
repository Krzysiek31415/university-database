#include "Student.hpp"
#include "UniversityDb.hpp"
#include <iostream>



int main()
{
    mainMenu();
    Student Pawel;
    Student Jan("Jan", "Nowak");
    Jan.setPESEL(92909008768);
    Jan.setIndexNumber(182696UL);
    Jan.setGender(Student::Gender::male);
    // Jan.showStudent();
    Student Ula("Urszula", "Nowak");
    Ula.setIndexNumber(192696UL);
    // std::cout<<Jan.getName()<<"\n";
    // std::cout<<Jan.getPESEL()<<"\n";
    //Student John;
    //John.showStudent();
    //John.fillInStudentData();
    Student Paul("Pawel", "Jasinski");
    Student JanB("Jan", "Brzechwa");
    // std::cout<<John.getName()<<"\n";
    UniversityDb PWr("Politechnika Wroclawska");
    PWr.addExistingStudent(Pawel);
    PWr.addExistingStudent(JanB);
    PWr.addExistingStudent(Jan);
    //PWr.addExistingStudent(John);
    // PWr.addExistingStudent(John);
    //Jan.showStudent();
    PWr.addExistingStudent(Paul);
    PWr.addExistingStudent(Ula);
    // PWr.printUniversity();
    //PWr.printStudent(0);
    // PWr.searchBySurname("Nowak");
    // PWr.searchByPESEL(92909008768);
    // auto it = PWr.searchByIndexNumber(182696UL);
    // it->showStudent();
    //PWr.addExistingStudent();

    //PWr.printUniversity();
    //PWr.addNewStudent();
    PWr.printUniversity();
    // PWr.deleteByIndexNumber2(192696UL);
    // PWr.sortBySurname  ();
    // PWr.printUniversity();
    

    return 0;
}