#include "StaffMenu.h"
#include "MedicineManagement.cpp"
using namespace std;

char StaffMenu::Show(const int& authentication){
    cout << StaffMenu::count++ << ". Xem va tim thuoc.\n";
    cout << StaffMenu::count++ << ". Tao giao dich.\n";
    cout << StaffMenu::count++ << ". Quan ly khach hang.\n";
    if (!authentication){
        cout << StaffMenu::count++ << ". Quan ly nhan vien.\n";
        cout << StaffMenu::count++ << ". Quan ly thuoc.\n";
        cout << StaffMenu::count++ << ". Xem thu chi.\n";
    }
    cout << StaffMenu::count++ << ". Xem thong tin ca nhan.\n";
    WorkMenu::Show();
    StaffMenu::count = 1;
    char temp;
    cin >> temp;
    getenter;
    return temp;
}

int StaffMenu::checkAuthentication(StaffManagement& stList, const int& index){
    string ID = stList.returnID(index);
    if (ID[0] == 'M') return 0;
    else return 1;
}

void StaffMenu::Run(StaffManagement& stList, const int& index){
    MedicineManagement mdList;
    ifstream FileMedicine("./Data/Medicine.txt");
    mdList.readMedicineFromFile(FileMedicine);
    FileMedicine.close();
    int authentication = checkAuthentication(stList,index);
<<<<<<< Updated upstream
    retry:    system("cls");
=======
    Customer c;
    Staff s(stList.returnInfo(index));
    Receipt receipt(c,s);
    bool breaker = false;
    while (!breaker){
        system("cls");
>>>>>>> Stashed changes
        char temp = this->Show(authentication);
        switch(temp){
            case '1':{      // Xem thuoc
                system("cls");
                StaffMenu::ViewMedsOptionMenu();
                char temp;
                cin >> temp;
                if (temp == '1')
                    mdList.ViewAllMedicines();
                else{
                    system("cls");
                    StaffMenu::ViewMedsFindMenu();
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
            case '2':{      // tao giao dich
                system("cls");
                cout << "Tao giao dich";
                break;
            }
            case '3':{      // Quan ly khach
                system("cls");
                cout << "Quan ly khach";
                break;
            }
            case '4':{      // tro lai
                system("cls");
                if (authentication){
                    stList.returnInfo(index);
                }
                else
                    cout << "quan ly nhan vien";
                break;
            }
            case '5':{      // thoat
                if (!authentication){
                    cout << "quan ly thuoc";
                }
                else this->backPressed = true;
                break;
            }
            case '6':{
                if (!authentication){
                    cout << "xem thu chi";
                }
                else exit(0);
                break;
            }
            case '7':{
                if (!authentication) this->backPressed = true;
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                    goto retry;
                }
            }
            case '8':{
                if (!authentication) exit(0);
            }
            default:{
                cout << "Lua chon khong hop le!\n";
                system("pause");
                system("cls");
                goto retry;
            }
        }
}