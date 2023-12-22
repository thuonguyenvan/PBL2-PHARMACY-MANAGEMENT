#include "StaffLogin.h"
#include "StaffMenu.cpp"
#include "StaffManagement.cpp"
using namespace std;

char StaffLogin::Show(){
    LoginForm::Show();
    StaffLogin::count = 1;
    char temp;
    cin >> temp;
    getenter;
    return temp;
}

void StaffLogin::Run(StaffManagement &stList, CustomerManagement &csList, MedicineManagement &mdList, ReceiptManagement& rcList){
    bool breaker = false;
    while (!breaker){
        system("cls");
        char temp = this->Show();
        switch(temp){
            case '1':{      // dang nhap
                retryLogin: system("cls");
                int index = this->checkLogin(stList);
                if (this->leftEmpty){           // kiem tra trong de quay lai
                    this->leftEmpty = false;
                    system("cls");
                }
                else{
                    if (index != (-1)){     // dang nhap thanh cong
                        system("cls");
                        cout << "Welcome " << stList.returnEmail(index);
                        StaffMenu staffMenu;
                        staffMenu.Run(stList,index, mdList, csList,rcList);
                    }
                    else{       // dang nhap khong thanh cong
                        system("pause");
                        goto retryLogin;
                    }
                }
                break;
            }
            case '2':{      // tro lai
                system("cls");
                breaker = true;
                break;
            }
            case '3':{      // thoat
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