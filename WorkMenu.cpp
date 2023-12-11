#pragma once
#include "WorkMenu.h"
using namespace std;

int WorkMenu::count = 1;

WorkMenu::WorkMenu(){}

WorkMenu::~WorkMenu(){}

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
            return i;
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
            List.returnMedicineInfo(i);
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
 //   cin.clear();
//    getenter;
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
//    cin.clear();
    getenter;
    getline(cin, ID);
    if (ID.empty()){
        this->leftEmpty = true;
        return "null";
    }
    else return ID;
}

void WorkMenu::BuyMedicine(MedicineManagement& mdList, Receipt& receipt){
    bool breaker = false;
    while (!breaker){
        system("cls");
        char temp;
        WorkMenu::ViewMedsOptionMenu();
        cin >> temp;
        while(temp<'1' || temp>'3'){
            cout << "Lua chon khong phu hop!\n";
            system("pause");
            system("cls");
            WorkMenu::ViewMedsOptionMenu();
            cin >> temp;
        }
        switch(temp){
            case '1':{
                mdList.ViewAllMedicines();
                string ID = this->ChooseMedicineID();
                if (this->leftEmpty){
                    this->leftEmpty = false;
                    return;
                }
                receipt.buyMedicine(ID);
                cout << "\nBan co muon mua tiep khong?\n";
                cout << "1. Tiep tuc mua hang.\n";
                cout << "2. Quay lai.\n";
                cin >> temp;
                while(temp<'1' || temp>'2'){
                    cout << "Lua chon khong phu hop.\n";
                    system("pause");
                    system("cls");
                    cout << "Chon mua thanh cong.\n";
                    cout << "Ban co muon mua tiep khong?\n";
                    cout << "1. Tiep tuc mua hang.\n";
                    cout << "2. Quay lai.\n";
                    cin >> temp;
                }
                switch(temp){
                    case '1':{
                        break;
                    }
                    case '2':{
                        breaker = true;
                        break;
                    }
                }
                break;
            }
            case '2':{
                system("cls");
                WorkMenu::ViewMedsFindMenu();
                cin >> temp;
                while(temp<'1' || temp>'3'){
                    cout << "Lua chon khong phu hop.\n";
                    system("pause");
                    system("cls");
                    WorkMenu::ViewMedsFindMenu();
                    cin >> temp;
                }
                switch(temp){
                    case '1':{
                        retryFindName: int index = this->SearchByName(mdList);
                        if (this->leftEmpty){           // kiem tra trong de quay lai
                            this->leftEmpty = false;
                            system("cls");
                            return;
                        }
                        if (index != (-1)){     // tim thay thuoc
                            system("cls");
                            mdList.returnMedicineInfo(index);
                            string ID = this->ChooseMedicineID();
                            if (this->leftEmpty){
                                this->leftEmpty = false;
                                return;
                            }
                            receipt.buyMedicine(ID);
                            cout << "\nBan co muon mua tiep khong?\n";
                            cout << "1. Tiep tuc mua hang.\n";
                            cout << "2. Quay lai.\n";
                            cin >> temp;
                            while(temp<'1' || temp>'2'){
                                cout << "Lua chon khong phu hop.\n";
                                system("pause");
                                system("cls");
                                cout << "Chon mua thanh cong.\n";
                                cout << "Ban co muon mua tiep khong?\n";
                                cout << "1. Tiep tuc mua hang.\n";
                                cout << "2. Quay lai.\n";
                                cin >> temp;
                            }
                            switch(temp){
                                case '1':{
                                    break;
                                }
                                case '2':{
                                    breaker = true;
                                    break;
                                }
                            }
                        }
                        else{       // khong tim thay
                            system("pause");
                            goto retryFindName;
                        }
                        break;
                    }
                    case '2':{
                        bool found = this->SearchByFunction(mdList);
                        if (this->leftEmpty){           // kiem tra trong de quay lai
                            this->leftEmpty = false;
                            system("cls");
                            return;
                        }
                        if (found){
                            string ID = this->ChooseMedicineID();
                            if (this->leftEmpty){
                                this->leftEmpty = false;
                                return;
                            }
                            receipt.buyMedicine(ID);
                            cout << "\nBan co muon mua tiep khong?\n";
                            cout << "1. Tiep tuc mua hang.\n";
                            cout << "2. Quay lai.\n";
                            cin >> temp;
                            while(temp<'1' || temp>'2'){
                                cout << "Lua chon khong phu hop.\n";
                                system("pause");
                                system("cls");
                                cout << "Chon mua thanh cong.\n";
                                cout << "Ban co muon mua tiep khong?\n";
                                cout << "1. Tiep tuc mua hang.\n";
                                cout << "2. Quay lai.\n";
                                cin >> temp;
                            }
                            switch(temp){
                                case '1':{
                                    break;
                                }
                                case '2':{
                                    breaker = true;
                                    break;
                                }
                            }
                        }
                        break;
                    }
                    case '3':{
                        breaker = true;
                        break;
                    }
                }
            }
            case '3':{
                breaker = true;
                break;
            }
        }
    }
}