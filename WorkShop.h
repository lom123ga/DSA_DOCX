#include "Header.h"
#include "Worker.h"
#include "Officer.h"

class WorkShop{
private :
    Officer manager;
    vector<Worker> workers;
public :
    WorkShop(){
        this->manager = Officer();
        this->workers = {};
    }

    WorkShop(Officer manager, vector<Worker> workers){
        this->manager = manager;
        this->workers = workers;
    }
    void setOfficer();
    void addWorker();
    void showOfficer();
    void showWorkers();
    void showSalaryOfficer();
    void showSalaryWorkers();
    void sortBySalary();
    void sortByName();
    //friend bool cmp1(Worker a, Worker b);
    //friend bool cmp2(Worker a, Worker b);
};

