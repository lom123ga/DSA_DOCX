#include "Header.h"
#include "WorkShop.h"

int main(){
    WorkShop workShop = WorkShop();
    while (1){
        cout << "=================MENU================\n";
        cout << "1. Nhap thong tin can bo\n"; 
        cout << "2. them moi mot cong nhan\n";
        cout << "3. hien thi thong tin can bo\n";
        cout << "4. hien thi thong tin tat ca cac cong nhan\n";
        cout << "5. tinh tien luong cua can bo\n";
        cout << "6. tinh tong tien luong cua cong nhan\n";
        cout << "7. sap xep lai thu tu cong nhan theo luong giam dan\n";	
        cout << "8. sap xep lai thu tu cong nhan theo ten(theo thu tu tu dien)\n";
        cout << "9. Exit\n";
        cout << "select :))\n";
        int choice ;
        cin >> choice;
        cin.ignore();
        if (choice == 9) break ;
        else if (choice == 1) workShop.setOfficer();
        else if (choice == 2) workShop.addWorker();
        else if (choice == 3) workShop.showOfficer();
        else if (choice == 4) workShop.showWorkers();
        else if (choice == 5) workShop.showSalaryOfficer();
        else if (choice == 6) workShop.showSalaryWorkers();
        else if (choice == 7) workShop.sortBySalary();
        else if (choice == 8) workShop.sortByName();
    }
    return 0;
}