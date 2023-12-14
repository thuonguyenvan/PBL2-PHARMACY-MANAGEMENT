#pragma once
#include "GuestMenu.h"
#include "MedicineManagement.cpp"
#include "Receipt.cpp"
using namespace std;

char GuestMenu::Show(const int& index){
    cout << GuestMenu::count++ << ". Xem va mua thuoc.\n";
    cout << GuestMenu::count++ << ". Xem gio hang va thanh toan.\n";
    if (index != -1) cout << GuestMenu::count++ << ". Xem thong tin ca nhan.\n";
    WorkMenu::Show();
    GuestMenu::count = 1;
    char temp;
    cin >> temp;
    getenter;
    return temp;
}

void GuestMenu::Run(CustomerManagement& csList, const int& index){
    MedicineManagement mdList;
    ifstream FileMedicine("./Data/Medicine.txt");
    mdList.readMedicineFromFile(FileMedicine);
    FileMedicine.close();
    Customer c;
    if (index!=-1){
        Customer temp(csList.returnInfo(index));
        c = temp;
    }
    else{
        Customer temp;
        c = temp;
    }
    Staff s;
    Receipt receipt(c,s);
    bool breaker = false;
    while (!breaker){
        system("cls");
        char temp = this->Show(index);
        switch(temp){
            case '1':{      // Xem thuoc
                this->BuyMedicine(mdList,receipt);
                break;
            }
            case '2':{      // Xem gio hang
                system("cls");
                receipt.showReceipt();
                system("pause");
                break;
            }
            case '3':{      // tro lai
            //    system("cls");
                if (index!=-1){
                    cout << c;
                    system("pause");
                }
                else
                    breaker = true;
                break;
            }
            case '4':{      // thoat
                if (index!=-1)
                    breaker = true;
                else
                    exit(0);
                break;
            }
            case '5':{
                if (index!=-1) exit(0);
            }
            default:{
                cout << "Lua chon khong hop le!\n";
                system("pause");
                system("cls");
                break;
            }
        }
    }
}