#include "WorkShop.h"



void WorkShop::setOfficer(){
    manager.takeValue();
}

void WorkShop::addWorker(){
    Worker res = Worker();
    res.takeValue();
    workers.push_back(res);
}

void WorkShop::showOfficer(){
    manager.getOfficer();
}

void WorkShop::showWorkers(){
    int d = 1;
    for(auto x : workers){
        cout << "STT : " << d++ << endl;
        x.getWorker(); 
    }
}

void WorkShop::showSalaryOfficer(){
    printf("\nSalary : %.5f\n", manager.getSalary()); 
    //cout << "Salary " << manager.getSalary() << endl;
}

void WorkShop::showSalaryWorkers(){
    int salary = 0;
    for (auto x : workers){
        salary += x.getSalary();
    }
    cout << "Salary : " << salary << endl;
}

bool cmp1(Worker a, Worker b){
    return a.getSalary() > b.getSalary();
}

bool cmp2(Worker a, Worker b){
    stringstream s1(a.getName());
    stringstream s2(b.getName());
    string token1,token2;
    while (s1 >> token1){}
    while (s2 >> token2){}
    return (token1 < token2);
}

void WorkShop::sortBySalary(){
    sort(workers.begin(), workers.end(), cmp1);
}

void WorkShop::sortByName(){
    sort(workers.begin(), workers.end(), cmp2);
}