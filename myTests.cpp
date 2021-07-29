#include "Student.hpp"
#include "UniversityDb.hpp"
#include <iostream>
#include <algorithm>

UniversityDb originalDatabase()
{
    UniversityDb originalUniversity("Original University");
    Student studentA("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male);
    Student studentB("Janusz","Nowak","Wroclaw, ul. szeroka", "2234","4213",Student::Gender::male);
    Student studentC("Adam","","Krakow, ul. zakopana", "9234","6213",Student::Gender::male);
    Student studentD("Kamila","Witos","Gdansk ul. zmorska", "6234","",Student::Gender::female);
    Student studentE("Maria","Sklodowska-Curie","Gdansk ul. zmorska", "7234","5214",Student::Gender::female);
    originalUniversity.addNewStudent(studentA);
    originalUniversity.addNewStudent(studentB);
    originalUniversity.addNewStudent(studentC);
    originalUniversity.addNewStudent(studentD);
    originalUniversity.addNewStudent(studentE);
    //originalUniversity.printUniversity();
    return originalUniversity;
}

UniversityDb sortedBySurnameDatabase()
{
    static UniversityDb sortedUniversity("Sorted by Surname University");
    Student studentB("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male);
    Student studentC("Janusz","Nowak","Wroclaw, ul. szeroka", "2234","4213",Student::Gender::male);
    Student studentA("Adam","","Krakow, ul. zakopana", "9234","6213",Student::Gender::male);
    Student studentE("Maria","Sklodowska-Curie","Gdansk ul. zmorska", "7234","5214",Student::Gender::female);
    Student studentD("Kamila","Witos","Gdansk ul. zmorska", "6234","",Student::Gender::female);
    
    sortedUniversity.addNewStudent(studentA);
    sortedUniversity.addNewStudent(studentB);
    sortedUniversity.addNewStudent(studentC);
    sortedUniversity.addNewStudent(studentE);
    sortedUniversity.addNewStudent(studentD);
    //sortedUniversity.printUniversity();
    return sortedUniversity;
}

bool sortBySurnameTest()
{
    UniversityDb original = originalDatabase();
    UniversityDb reference = sortedBySurnameDatabase();
    original.printUniversity();
    ////////////////////////////////////////////////////////////////////////////////

    original.sortBySurname();

    ////////////////////////////////////////////////////////////////////////////////
    original.printUniversity();
    reference.printUniversity();
    if(original.getUniversityVector() == reference.getUniversityVector())
         return true;
    else
        return false;
}

UniversityDb sortedByPESELDatabase()
{
    UniversityDb sortedUniversity("Sorted by PESEL University");
    Student studentA("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male);
    Student studentB("Janusz","Nowak","Wroclaw, ul. szeroka", "2234","4213",Student::Gender::male);
    Student studentC("Adam","","Krakow, ul. zakopana", "9234","6213",Student::Gender::male);
    Student studentD("Kamila","Witos","Gdansk ul. zmorska", "6234","",Student::Gender::female);
    Student studentE("Maria","Sklodowska-Curie","Gdansk ul. zmorska", "7234","5214",Student::Gender::female);
    
    sortedUniversity.addNewStudent(studentD);
    sortedUniversity.addNewStudent(studentA);
    sortedUniversity.addNewStudent(studentB);
    sortedUniversity.addNewStudent(studentE);
    sortedUniversity.addNewStudent(studentC);
    //sortedUniversity.printUniversity();
    return sortedUniversity;
}

bool sortByPESELTest()
{
    UniversityDb original = originalDatabase();
    UniversityDb reference = sortedByPESELDatabase();
    original.printUniversity();
    ////////////////////////////////////////////////////////////////////////

    original.sortByPESEL();

    ////////////////////////////////////////////////////////////////////////
    original.printUniversity();
    reference.printUniversity();
    if(original.getUniversityVector() == reference.getUniversityVector())
         return true;
    else
        return false;
}

UniversityDb DatabaseWithNewStudent()
{
    UniversityDb University("Database with new student");
    Student studentA("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male);
    Student studentB("Janusz","Nowak","Wroclaw, ul. szeroka", "2234","4213",Student::Gender::male);
    Student studentC("Adam","","Krakow, ul. zakopana", "9234","6213",Student::Gender::male);
    Student studentD("Kamila","Witos","Gdansk ul. zmorska", "6234","",Student::Gender::female);
    Student studentE("Maria","Sklodowska-Curie","Gdansk ul. zmorska", "7234","5214",Student::Gender::female);
    Student newStudent("Albert","Einstein","Princeton 89", "7896","9876",Student::Gender::male);
    
    University.addNewStudent(studentA);
    University.addNewStudent(studentB);
    University.addNewStudent(studentC);
    University.addNewStudent(studentD);
    University.addNewStudent(studentE);
    University.addNewStudent(newStudent);

    return University;
}

bool addStudentTest()
{
    UniversityDb original = originalDatabase();
    UniversityDb reference = DatabaseWithNewStudent();
    original.printUniversity();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Student newStudent("Albert","Einstein","Princeton 89", "7896","9876",Student::Gender::male);
    original.addNewStudent(newStudent);

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    original.printUniversity();
    reference.printUniversity();
    if(original.getUniversityVector() == reference.getUniversityVector())
         return true;
    else
        return false;
}

UniversityDb DatabaseWithDeletedStudentByIndexNumber()
{
    UniversityDb University("Database with deleted student");
    Student studentA("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male);
    Student studentB("Janusz","Nowak","Wroclaw, ul. szeroka", "2234","4213",Student::Gender::male);
    Student studentC("Adam","","Krakow, ul. zakopana", "9234","6213",Student::Gender::male);
    Student studentD("Kamila","Witos","Gdansk ul. zmorska", "6234","",Student::Gender::female);
    //Student studentE("Maria","Sklodowska-Curie","Gdansk ul. zmorska", "7234","5214",Student::Gender::female);
    
    University.addNewStudent(studentA);
    University.addNewStudent(studentB);
    University.addNewStudent(studentC);
    University.addNewStudent(studentD);
    //University.addNewStudent(studentE);

    return University;
}



bool deleteByIndexNumberTest()
{
    UniversityDb original = originalDatabase();
    UniversityDb reference = DatabaseWithDeletedStudentByIndexNumber();
    original.printUniversity();
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    original.deleteByIndexNumber2("7234");

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    original.printUniversity();
    reference.printUniversity();
    if(original.getUniversityVector() == reference.getUniversityVector())
         return true;
    else
        return false;
}
bool searchBySurnameTest()
{
    UniversityDb original = originalDatabase();
    original.addNewStudent(Student("Adam","Nowak","Krakow, ul. zakopana", "9234","6213",Student::Gender::male));
    std::vector<Student> reference1;
    reference1.push_back(Student("Janusz","Nowak","Wroclaw, ul. szeroka", "2234","4213",Student::Gender::male));
    reference1.push_back(Student("Adam","Nowak","Krakow, ul. zakopana", "9234","6213",Student::Gender::male));

    std::vector<Student> reference2;
    reference2.push_back(Student("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male));
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    std::vector<Student> students1 = original.searchBySurname("Nowak"); // there are dwo Nowak
    std::vector<Student> students2 = original.searchBySurname("Kowalski"); // there is one Kowalski
    std::vector<Student> students3 = original.searchBySurname("Kowalczyk"); // there is no Kowalczyk

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////
    
    if(students1 == reference1   &&   students2 == reference2   &&   students3.empty())
         return true;
    else
        return false;
}

bool searchByPESELtest()
{
    UniversityDb original = originalDatabase();
    Student reference1("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male);
    Student reference2("Jan","Kowalski","Wroclaw, ul. Dluga", "1234","1213",Student::Gender::male);
    //////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Student student1 = original.searchByPESEL("1213"); // There is such PESEL in database
    Student student2 = original.searchByPESEL("1111"); // There is no such PESEL in database

    /////////////////////////////////////////////////////////////////////////////////////////////////////////////

    if( student1 == reference1 && !(student2 == reference2)  )
        return true;
    else
        return false;
}

void showDatabaseTest()
{
    UniversityDb students = originalDatabase();
    students.printUniversity();

    UniversityDb students2("");
    students2.printUniversity();
}

void storageStudentsTest()
{
    
}
