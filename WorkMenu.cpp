#pragma once
#include "WorkMenu.h"
using namespace std;

int WorkMenu::count = 1;

void WorkMenu::Show(){
    cout << WorkMenu::count++ << ". Tro ve.\n";
    cout << WorkMenu::count++ << ". Thoat.\n";
}

void WorkMenu::ViewMedsOptionMenu(){
    cout << "1. Xem tat ca thuoc.\n";
    cout << "2. Tim thuoc.\n";
    cout << "3. Tro ve.\n";
}

void WorkMenu::ViewMedsFindMenu(){
    cout << "1. Tim theo ten.\n";
    cout << "2. Tim theo chuc nang.\n";
    cout << "3. Tro ve.\n";
}

template<typename T>
int WorkMenu::SearchByName(T& List){
    system("cls");
    string name;
    bool checkName = false;
    cout << "De trong de quay lai.\n";
    cout << "Nhap ten can tim: ";
    getenter;
    getline(cin, name);
    if (name.empty()){
        this->leftEmpty = true;
        return -1;
    }
    for (int i=0; i<List.returnCount(); i++){
        if (name == List.returnMedicineName(i)){
            checkName = true;
            break;
        }
    }
    if (!checkName){
        cout << "Ten khong ton tai.\n";
        return (-1);
    }
    else return 0;
}

template<typename T>
bool WorkMenu::SearchByFunction(T& List){
    system("cls");
    string function;
    bool checkFunction = false;
    cout << "De trong de quay lai.\n";
    cout << "Nhap chuc nang can tim: ";
    getenter;
    getline(cin, function);
    if (function.empty()){
        this->leftEmpty = true;
        return true;
    }
    for (int i=0; i<List.returnCount(); i++){
        if (function == List.returnMedicineFunction(i)){
            checkFunction = true;
            List.returnInfo(i);
        }
    }
    if (!checkFunction)
        cout << "Khong tim thay thuoc voi chuc nang nay.\n";
    return checkFunction;
}

int WorkMenu::ChooseMedicineAmount(){
    string amountStr;
    int amount;
    cout << "Nhap so luong thuoc muon mua hoac de trong de quay lai: ";
    getenter;
    getline(cin, amountStr);
    if (amountStr.empty()){
        this->leftEmpty = true;
        return -1;
    }
    amount = stoi(amountStr,nullptr);
    return amount;
}

string WorkMenu::ChooseMedicineID(){
    string ID;
    cout << "Nhap ID thuoc ban muon mua (de trong de quay lai): ";
    getenter;
    getline(cin, ID);
    if (ID.empty()){
        this->leftEmpty = true;
        return "null";
    }
    else return ID;
}

void WorkMenu::DisplayReceipt(){
    
}