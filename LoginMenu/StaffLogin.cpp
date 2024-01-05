#include "StaffLogin.h"
#include "../WorkMenu/StaffMenu.cpp"
#include "../Staff/StaffManagement.cpp"
using namespace std;

char StaffLogin::Show(){
    cout << " _____ _____ ___  ____________   _     _____ _____ _____ _   _ \n";
    cout << "/  ___|_   _/ _ \\ |  ___|  ___| | |   |  _  |  __ \\_   _| \\ | |\n";
    cout << "\\ `--.  | |/ /_\\ \\| |_  | |_    | |   | | | | |  \\/ | | |  \\| |\n";
    cout << " `--. \\ | ||  _  ||  _| |  _|   | |   | | | | | __  | | | . ` |\n";
    cout << "/\\__/ / | || | | || |   | |     | |___\\ \\_/ / |_\\ \\_| |_| |\\  |\n";
    cout << "\\____/  \\_/\\_| |_/\\_|   \\_|     \\_____/\\___/ \\____/\\___/\\_| \\_/\n\n";
    cout << "\t\t|--------------------------|\n";
    LoginForm::Show();
    cout << "\t\t|--------------------------|\n\n";
    StaffLogin::count = 1;
    char temp;
    cout << "Nhap lua chon: ";
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