#pragma once
#include "GuestLogin.h"
#include "GuestMenu.cpp"
#include "CustomerManagement.cpp"
#include "StaffManagement.cpp"
#include "MedicineManagement.cpp"
using namespace std;

char GuestLogin::Show(){
    cout << GuestLogin::count++ << ". Khong dung tai khoan.\n";
    cout << GuestLogin::count++ << ". Dang ky.\n";
    LoginForm::Show();
    GuestLogin::count = 1;
    char temp;
    cin >> temp;
    getenter;
    return temp;
}

void GuestLogin::Run(CustomerManagement &csList, StaffManagement &stList, MedicineManagement &mdList, ReceiptManagement& rcList){
    bool breaker = false;
    while (!breaker){
        system("cls");
        char temp = this->Show();
        switch(temp){
            case '1':{      // khong dung tai khoan
                system("cls");
                int index = -1;
                GuestMenu guestMenu;
                guestMenu.Run(csList,index, mdList,rcList);
                break;
            }
            case '2':{      // dang ky
                system("cls");
                csList.addNewCustomer();
            //    csList.updateCustomerFile();
                break;
            }
            case '3':{      // dang nhap
                retryLogin: system("cls");
                int index = this->checkLogin(csList);
                if (this->leftEmpty){           // kiem tra trong de quay lai
                    this->leftEmpty = false;
                    system("cls");
                }
                else{
                    if (index != (-1)){     // dang nhap thanh cong
                        system("cls");
                        cout << "Welcome " << csList.returnEmail(index);
                        GuestMenu guestMenu;
                        guestMenu.Run(csList,index, mdList,rcList);
                    }
                    else{       // dang nhap khong thanh cong
                        system("pause");
                        goto retryLogin;
                    }
                }
                break;
            }
            case '4':{      // tro lai
                breaker = true;
                break;
            }
            case '5':{      // thoat
                exit(0);
                break;
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