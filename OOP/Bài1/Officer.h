#include "Header.h"

class Officer{
private :
    string name;
    int age;
    string gender;
    string hometown;
    float salaryCoefficients;
public :
    Officer(){
        this->name = "";
        this->age = 0;
        this->gender = "";
        this->hometown = "";
        this->salaryCoefficients = 0;
    }

    Officer(string name, int age, string gender, string hometown, float salaryCoefficients){
        this->name = name;
        this->age = age;
        this->gender =gender;
        this->hometown = hometown;
        this->salaryCoefficients = salaryCoefficients;
    }
    void takeValue();
    void setName(string name);
    void setAge(int age);
    void setGender(string gender);
    void setHometown(string hometown);
    void setSalaryCoefficients(float salaryCoefficients);
    string getName();
    int getAge();
    string getGender();
    string getHometown();
    float getSalaryCoefficients();
    float getSalary();
    void getOfficer();
};

