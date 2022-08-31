#include "Header.h"

class Worker{
private :
    string name;
    int age;
    string gender;
    string hometown;
    int numberDayWork;
public :
    Worker(){
        this->name = "";
        this->age = 0;
        this->gender = "";
        this->hometown = "";
        this->numberDayWork = 0;
    }

    Worker(string name, int age, string gender, string hometown, int numberDayWork){
        this->name = name;
        this->age = age;
        this->gender = gender;
        this->hometown = hometown;
        this->numberDayWork = numberDayWork;
    }
    void takeValue();
    void setName(string name);
    void setAge(int age);
    void setGender(string gender);
    void setHometown(string hometown);
    void setNumberDayWork(int numberDayWork);
    string getName();
    int getAge();
    string getGender();
    string getHometown();
    int getNumberDayWork();
    int getSalary();
    void getWorker();
};

