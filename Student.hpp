#include<string>
class Student
{
    enum class Gender{male, female, other};

    std::string name_;
    std::string surname_;
    std::string address_;
    unsigned int indexNumber_;
    unsigned int PESEL_;
    Gender gender_;

public:
    Student(std::string name, std::string surname, std::string address,
    unsigned int indexNumber, unsigned int PESEL, Gender gender)
    :   name_(name),
        surname_(surname),
        address_(address),
        indexNumber_(indexNumber),
        PESEL_(PESEL),
        gender_(gender)
        {}
    Student(std::string name, std::string surname)
    :   Student(name, surname, "", 0, 0, Gender::other)
        {}
    void setName(std::string name){name_ = name;}
    void setSurname(std::string surname){surname_ = surname;}
    void setAddress(std::string address){address_ = address;}
    void setIndexNumber(unsigned int indexNumber){indexNumber_= indexNumber;}
    void setPESEL(unsigned int PESEL){PESEL_= PESEL;}
    void setGender(Gender gender){gender_ = gender;}

    std::string getName() const {return name_;}
    std::string getSurname() const {return surname_;}
    std::string getAddress() const {return address_;}
    unsigned int getIndexNumber() const {return indexNumber_;}
    unsigned int getPESEL() const {return PESEL_;}
    Gender getGender() const {return gender_;}

};