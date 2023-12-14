<<<<<<< HEAD
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
    CustomerManagement csList;
    ifstream FileCustomer("./Data/Customer.txt");
    csList.readCustomerFromFile(FileCustomer);
    FileCustomer.close();
    int authentication = checkAuthentication(stList,index);
<<<<<<< HEAD
=======
<<<<<<< Updated upstream
    retry:    system("cls");
=======
>>>>>>> main
    Customer c;
    Staff s(stList.returnInfo(index));
    Receipt receipt(c,s);
    bool breaker = false;
    while (!breaker){
        system("cls");
<<<<<<< HEAD
=======
>>>>>>> Stashed changes
>>>>>>> main
        char temp = this->Show(authentication);
        switch(temp){
            case '1':{      // Xem thuoc
                StaffMenu::BuyMedicine(mdList,receipt);
                break;
            }
            case '2':{      // tao giao dich
                system("cls");
                cout << "Tao giao dich";
                break;
            }
            case '3':{      // Quan ly khach
                system("cls");
                csList.ViewAllCustomers();
                // cout << "Chon STT khach muon chinh sua: ";
                // int ID;
                // cin >> ID;
                system("pause");
                break;
            }
            case '4':{      // tro lai
                system("cls");
                if (authentication){
                    cout << s;
                    system("pause");
                }
                else{
                    system("cls");
                    stList.ViewAllStaffs();
                    // cout << "Chon STT khach muon chinh sua: ";
                    // int ID;
                    // cin >> ID;
                    system("pause");
                    break;
                }
                break;
            }
            case '5':{      // thoat
                if (!authentication){
                    system("cls");
                    mdList.ViewAllMedicines();
                    // cout << "Chon STT khach muon chinh sua: ";
                    // int ID;
                    // cin >> ID;
                    system("pause");
                }
                else breaker = true;
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
                if (!authentication){
                    cout << s;
                    system("pause");
                }
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case '8':{
                if (!authentication)
                    breaker = true;
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case '9':{
                if (!authentication) exit(0);
            }
            default:{
                cout << "Lua chon khong hop le!\n";
                system("pause");
                system("cls");
                break;
            }
        }
    }
=======
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
    CustomerManagement csList;
    ifstream FileCustomer("./Data/Customer.txt");
    csList.readCustomerFromFile(FileCustomer);
    FileCustomer.close();
    int authentication = checkAuthentication(stList,index);
    Customer c;
    Staff s(stList.returnInfo(index));
    Receipt receipt(c,s);
    bool breaker = false;
    while (!breaker){
        system("cls");
        char temp = this->Show(authentication);
        switch(temp){
            case '1':{      // Xem thuoc
                StaffMenu::BuyMedicine(mdList,receipt);
                break;
            }
            case '2':{      // tao giao dich
                system("cls");
                cout << "Tao giao dich";
                break;
            }
            case '3':{      // Quan ly khach
                system("cls");
                csList.ViewAllCustomers();
                // cout << "Chon STT khach muon chinh sua: ";
                // int ID;
                // cin >> ID;
                system("pause");
                break;
            }
            case '4':{      // tro lai
                system("cls");
                if (authentication){
                    cout << s;
                    system("pause");
                }
                else{
                    system("cls");
                    stList.ViewAllStaffs();
                    // cout << "Chon STT khach muon chinh sua: ";
                    // int ID;
                    // cin >> ID;
                    system("pause");
                    break;
                }
                break;
            }
            case '5':{      // thoat
                if (!authentication){
                    system("cls");
                    mdList.ViewAllMedicines();
                    // cout << "Chon STT khach muon chinh sua: ";
                    // int ID;
                    // cin >> ID;
                    system("pause");
                }
                else breaker = true;
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
                if (!authentication){
                    cout << s;
                    system("pause");
                }
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case '8':{
                if (!authentication)
                    breaker = true;
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case '9':{
                if (!authentication) exit(0);
            }
            default:{
                cout << "Lua chon khong hop le!\n";
                system("pause");
                system("cls");
                break;
            }
        }
    }
>>>>>>> efacc985dacfb5baa6091624f41eb57542a778ce
}