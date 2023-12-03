#include "GuestLogin.h"
using namespace std;

char GuestLogin::Show(){
    cout << GuestLogin::count++ << ". No account.\n";
    cout << GuestLogin::count++ << ". Register.\n";
    LoginForm::Show();
    GuestLogin::count = 1;
    char temp;
    cin >> temp;
    return temp;
}

void GuestLogin::Run(){
    CustomerManagement csList;
    ifstream FileCustomer("./Data/Customer.txt");
    csList.readCustomerFromFile(FileCustomer);
    FileCustomer.close();
    retry:    system("cls");
        char temp = this->Show();
        switch(temp){
            case '1':{      // khong dung tai khoan
                system("cls");
                //NoAccount::Run();
                cout << "noacc";
                break;
            }
            case '2':{      // dang ky
                system("cls");
                csList.addNewCustomer();
                system("pause");
                goto retry;
                break;
            }
            case '3':{      // dang nhap
                retryLogin: system("cls");
                int index = this->checkLogin(csList);
                if (this->leftEmpty){           // kiem tra trong de quay lai
                    this->leftEmpty = false;
                    system("cls");
                    goto retry;
                }
                if (index != (-1)){     // dang nhap thanh cong
                    //GuestMenu::Run();
                    system("cls");
                    cout << "Welcome " << csList.returnEmail(index);
                }
                else{       // dang nhap khong thanh cong
                    system("pause");
                    goto retryLogin;
                }
                break;
            }
            case '4':{      // tro lai
                system("cls");
                this->backPressed = true;
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
                goto retry;
            }
        }
}