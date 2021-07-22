#include <iostream>
#include "Student.hpp"
#include "UniversityDb.hpp"

int main()
{
    Student Jan("Jan","Nowak");
    Jan.setPESEL(92909008768);
    Jan.setIndexNumber(182696UL);
    //Jan.showStudent();
    Student Ula("Urszula","Nowak");
    Ula.setIndexNumber(192696UL);
    //std::cout<<Jan.getName()<<"\n";
    //std::cout<<Jan.getPESEL()<<"\n";
    Student John;
    Student Paul("Pawel", "Jasinski");
    Student JanB("Jan","Brzechwa");
    //std::cout<<John.getName()<<"\n";
    UniversityDb PWr("Politechnika Wroclawska");
    PWr.addStudent(JanB);
    PWr.addStudent(Jan);
    //PWr.addStudent(John);
    Jan.showStudent();
    PWr.addStudent(Paul);
    PWr.addStudent(Ula);
    //PWr.printUniversity();
    PWr.printStudent(0);
    //PWr.searchBySurname("Nowak");
    //PWr.searchByPESEL(92909008768);
    //auto it = PWr.searchByIndexNumber(182696UL);
    //it->showStudent();
    PWr.printUniversity();
    //PWr.deleteByIndexNumber2(192696UL);
    //PWr.sortBySurname  ();
    //PWr.printUniversity();

    return 0;
}