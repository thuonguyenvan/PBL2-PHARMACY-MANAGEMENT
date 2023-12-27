#include "StaffLogin.h"
#include "StaffMenu.cpp"
#include "StaffManagement.cpp"
using namespace std;

char StaffLogin::Show(){
    cout << "~~~~~~~~~~~|||~~~~~~~~~~~|||~~~~~~~~~~~\n";
    cout << "              STAFF LOGIN\n\n";
    LoginForm::Show();
    cout << "~~~~~~~~~~~|||~~~~~~~~~~~|||~~~~~~~~~~~\n";
    StaffLogin::count = 1;
    char temp;
    cin >> temp;
    getenter;
    return temp;
}

void StaffLogin::Run(StaffManagement &stList, CustomerManagement &csList, MedicineManagement &mdList, ReceiptManagement& rcList){
    while (true){
        system("cls");
        char temp = this->Show();
        switch(temp){
            case '1':{      // dang nhap
                while (true){
                    system("cls");
                    int index = this->checkLogin(stList);
                    if (this->leftEmpty){           // kiem tra trong de quay lai
                        this->leftEmpty = false;
                        system("cls");
                        break;
                    }
                    else{
                        if (index != (-1)){     // dang nhap thanh cong
                            system("cls");
                            cout << "Welcome " << stList.returnEmail(index);
                            StaffMenu staffMenu;
                            staffMenu.Run(stList,index, mdList, csList,rcList);
                            if (staffMenu.exitPressed){
                                exitPressed = true;
                                return;
                            }
                            break;
                        }
                        else{       // dang nhap khong thanh cong
                            system("pause");
                        }
                    }
                }
                break;
            }
            case '2':{      // tro lai
                return;
            }
            case '3':{      // thoat
                exitPressed = true;
                return;
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