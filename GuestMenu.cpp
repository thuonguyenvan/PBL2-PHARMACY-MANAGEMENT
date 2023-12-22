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

void GuestMenu::Run(CustomerManagement& csList, const int& index, MedicineManagement &mdList, ReceiptManagement& rcList){
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
    while (true){
        system("cls");
        char temp = this->Show(index);
        switch(temp){
            case '1':{      // Xem thuoc
                BuyMedicine(mdList,receipt);
                break;
            }
            case '2':{      // Xem gio hang
                ReceiptMenu(receipt,rcList);
                break;
            }
            case '3':{      // xem thong tin ca nhan || tro lai
                if (index!=-1){
                    int authentication = -1;
                    EditInformation(c,authentication);
                }
                else
                    return;
                break;
            }
            case '4':{      // tro lai || thoat
                if (index==-1)
                    exitPressed = true;
                return;
            }
            case '5':{      // thoat
                if (index!=-1){
                    exitPressed = true;
                    return;
                }
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