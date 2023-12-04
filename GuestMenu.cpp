#include "GuestMenu.h"
using namespace std;

char GuestMenu::Show(const int& index){
    cout << GuestMenu::count++ << ". Xem va mua thuoc.\n";
    cout << GuestMenu::count++ << ". Xem gio hang va thanh toan.\n";
    if (index != -1) cout << GuestMenu::count++ << ". Xem thong tin ca nhan.\n";
    WorkMenu::Show();
    GuestMenu::count = 1;
    char temp;
    cin >> temp;
    return temp;
}

void GuestMenu::Run(const int& index){
    retry:    system("cls");
        char temp = this->Show(index);
        switch(temp){
            case '1':{      // Xem thuoc
                system("cls");
                cout << "Xem thuoc";
                break;
            }
            case '2':{      // Xem gio hang
                system("cls");
                cout << "Gio hang";
                break;
            }
            case '3':{      // tro lai
                system("cls");
                if (index!=-1)  cout << "xem thong tin ca nhan";
                else
                    back: this->backPressed = true;
                break;
            }
            case '4':{      // thoat
                if (index!=-1) goto back;
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
                goto retry;
            }
        }
}