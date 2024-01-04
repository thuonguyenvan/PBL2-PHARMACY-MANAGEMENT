#pragma once
#include "GuestLogin.h"
#include "GuestMenu.cpp"
#include "CustomerManagement.cpp"
#include "StaffManagement.cpp"
#include "MedicineManagement.cpp"
using namespace std;

char GuestLogin::Show(){
    cout << " _____ _   _ _____ _____ _____   _     _____ _____ _____ _   _ \n";
    cout << "|  __ \\ | | |  ___/  ___|_   _| | |   |  _  |  __ \\_   _| \\ | |\n";
    cout << "| |  \\/ | | | |__ \\ `--.  | |   | |   | | | | |  \\/ | | |  \\| |\n";
    cout << "| | __| | | |  __| `--. \\ | |   | |   | | | | | __  | | | . ` |\n";
    cout << "| |_\\ \\ |_| | |___/\\__/ / | |   | |___\\ \\_/ / |_\\ \\_| |_| |\\  |\n";
    cout << " \\____/\\___/\\____/\\____/  \\_/   \\_____/\\___/ \\____/\\___/\\_| \\_/\n\n";
    cout << "\t\t\u00A6--------------------------\u00A6\n";
    cout << "\t\t\u00A6 " << GuestLogin::count++ << ". Khong dung tai khoan. \u00A6\n";
    cout << "\t\t\u00A6--------------------------\u00A6\n";
    cout << "\t\t\u00A6 " << GuestLogin::count++ << ". Dang ky.              \u00A6\n";
    cout << "\t\t\u00A6--------------------------\u00A6\n";
    LoginForm::Show();
    cout << "\t\t\u00A6--------------------------\u00A6\n\n";
    GuestLogin::count = 1;
    char temp;
    cout << "Nhap lua chon: ";
    cin >> temp;
    getenter;
    return temp;
}

void GuestLogin::Run(CustomerManagement &csList, StaffManagement &stList, MedicineManagement &mdList, ReceiptManagement& rcList){
    while (true){
        system("cls");
        char temp = this->Show();
        switch(temp){
            case '1':{      // khong dung tai khoan
                system("cls");
                int index = -1;
                GuestMenu guestMenu;
                guestMenu.Run(csList,index, mdList,rcList);
                if (guestMenu.exitPressed){
                    exitPressed = true;
                    return;
                }
                break;
            }
            case '2':{      // dang ky
                system("cls");
                csList.addNewCustomer();
            //    csList.updateCustomerFile();
                break;
            }
            case '3':{      // dang nhap
                while(true){
                    system("cls");
                    int index = this->checkLogin(csList);
                    if (this->leftEmpty){           // kiem tra trong de quay lai
                        this->leftEmpty = false;
                        system("cls");
                        break;
                    }
                    else{
                        if (index != (-1)){     // dang nhap thanh cong
                            system("cls");
                            cout << "Welcome " << csList.returnEmail(index);
                            GuestMenu guestMenu;
                            guestMenu.Run(csList,index, mdList,rcList);
                            if (guestMenu.exitPressed){
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
            case '4':{      // tro lai
                return;
            }
            case '5':{      // thoat
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