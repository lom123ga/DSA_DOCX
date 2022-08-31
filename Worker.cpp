#include "Worker.h"

void Worker::takeValue(){
    cout << "Name: "; getline(cin,name);
    cout << "Age: "; cin >> age; cin.ignore();
    cout << "Gender: "; cin >> gender;
    cout << "Home: "; getline(cin,hometown);
    cout << "Day work: "; cin >> numberDayWork; cin.ignore();
}

void Worker::setName(string name){
    this->name = name;
}

void Worker::setAge(int age){
    this->age = age;
}

void Worker::setGender(string gender){
    this->gender = gender;
}

void Worker::setHometown(string hometown){
    this->hometown = hometown;
}

void Worker::setNumberDayWork(int numberDayWork){
    this->numberDayWork = numberDayWork;
}

string Worker::getName(){
    return name;
}

int Worker::getAge(){
    return age;
}

string Worker::getGender(){
    return gender;
}

string Worker::getHometown(){
    return hometown;
}

int Worker::getNumberDayWork(){
    return numberDayWork;
}

int Worker::getSalary(){
    return numberDayWork*100000;
}

void Worker::getWorker(){
    cout << "Name: " << getName() << endl;
    cout << "Age: " << getAge() << endl;
    cout << "Gender: " << getGender() << endl;
    cout << "Home: " << getHometown() << endl;
}