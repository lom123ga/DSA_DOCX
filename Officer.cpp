#include "Officer.h"



void Officer::takeValue(){
    cout << "Name: "; getline(cin,name);
    cout << "Age: "; cin >> age; cin.ignore();
    cout << "Gender: "; cin >> gender; cin.ignore();
    cout << "Home: "; getline(cin,hometown);
    cout << "Salary Coefficients: "; cin >> salaryCoefficients; cin.ignore();
}

void Officer::setName(string name){
    this->name = name;
}

void Officer::setAge(int age){
    this->age = age;
}

void Officer::setGender(string gender){
    this->gender = gender;
}

void Officer::setHometown(string hometown){
    this->hometown = hometown;
}

void Officer::setSalaryCoefficients(float salaryCoefficients){
    this->salaryCoefficients = salaryCoefficients;
}

string Officer::getName(){
    return name;
}

int Officer::getAge(){
    return this->age;
}

string Officer::getGender(){
    return this->gender;
}

string Officer::getHometown(){
    return this->hometown;
}

float Officer::getSalaryCoefficients(){
    return this->salaryCoefficients;
}

float Officer::getSalary(){
    return salaryCoefficients*3000000;
}

void Officer::getOfficer(){
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Gender: " << getGender() << endl;
    cout << "Home: " << getHometown() << endl;
    cout << "SalaryCoefficients :" << getSalaryCoefficients() << endl;
}