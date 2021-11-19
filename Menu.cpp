#include <iostream>
#include "Student2.hpp"
#include "UniversityDb.hpp"
#include "Person.hpp"
#include "Menu.hpp"

void mainMenu()
{
    bool exitMainMenu{};
    while(!exitMainMenu)
    {
        static std::vector<UniversityDb> universities;
        std::string position{};
        do{
            std::cout<<"\n        MENU\n";
            std::cout<<"1. Create new database.\n";
            std::cout<<"2. Choose a database.\n";
            std::cout<<"3. Delete database.\n";
            //std::cout<<"5. Load from file.\n";
            std::cout<<"4. Exit.\n\n";
            
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
                std::cout<<"            CREATING NEW UNIVERSITY DATABASE \n";
                std::cout<<"Name of university: ";
                std::string nameOfUniversity{};
                std::cin>>std::ws; 
                std::getline(std::cin, nameOfUniversity);
                UniversityDb university(nameOfUniversity); 
                universities.push_back(university);
                break;
            }  
            case 2:
            {
                std::cout<<"            CHOOSING A DATABASE \n";
                if(universities.empty())
                {
                    std::cout<<"There is no database.\n";
                }
                else
                {
                    size_t n{};
                    for(auto elem: universities)
                    {
                        std::cout<< ++n <<". "<<elem.getUniversityName()<<"\n";
                    }
                    size_t selectionDatabase;
                    std::cin>>selectionDatabase;
                    universities[selectionDatabase-1].universityMenu();
                } 
                break;
            }
            case 3:
            {
                std::cout<<"            DATABASE DELETION. \n";
                if(universities.empty())
                {
                    std::cout<<"    There is no database.\n";
                }
                else
                {
                    size_t n{};
                    for(auto elem: universities)
                    {
                        std::cout<<++n<<". "<<elem.getUniversityName()<<"\n";
                    }
                    size_t selectionDatabase;
                    std::cin>>selectionDatabase;
                    universities.erase(universities.begin() + selectionDatabase - 1);
                }
                break;
            }
            case 4:
            {
                exitMainMenu = true;
                break;
            }
            // case 5:
            // {
                
            //     break;
            // }
            default:
            {
                std::cout<<"Error. Please enter it again.\n";
                break;
            }
        }
    }
}