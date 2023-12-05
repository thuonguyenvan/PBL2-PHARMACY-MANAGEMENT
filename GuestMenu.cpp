#include "GuestMenu.h"
#include "MedicineManagement.cpp"
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
    MedicineManagement mdList;
    ifstream FileMedicine("./Data/Medicine.txt");
    mdList.readMedicineFromFile(FileMedicine);
    FileMedicine.close();
    retry:    system("cls");
        char temp = this->Show(index);
        switch(temp){
            case '1':{      // Xem thuoc
                system("cls");
                GuestMenu::ViewMedsOptionMenu();
                char temp;
                cin >> temp;
                if (temp == '1')
                    mdList.ViewAllMedicines();
                else{
                    system("cls");
                    GuestMenu::ViewMedsFindMenu();
                    cin >> temp;
                    if (temp == '1'){
                        retryFindName: int index = this->SearchByName(mdList);
                        if (this->leftEmpty){           // kiem tra trong de quay lai
                            this->leftEmpty = false;
                            system("cls");
                            goto retry;
                        }
                        if (index != (-1)){     // tim thay thuoc
                            system("cls");
                            cout << "Da tim thay " << mdList.returnMedicineName(index);
                        }
                        else{       // khong tim thay
                            system("pause");
                            goto retryFindName;
                        }
                        break;
                    }
                    else{
                        retryFindFunction: bool found = this->SearchByFunction(mdList);
                        if (this->leftEmpty){           // kiem tra trong de quay lai
                            this->leftEmpty = false;
                            system("cls");
                            goto retry;
                        }
                        if (!found) goto retryFindFunction;
                        break;
                    }
                }
                system("pause");
                goto retry;
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