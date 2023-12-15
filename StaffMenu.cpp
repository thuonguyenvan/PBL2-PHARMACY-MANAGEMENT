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

void StaffMenu::ManagementMenu(StaffManagement& stList, MedicineManagement &mdList, CustomerManagement &csList, int check){
    while (true){
        system("cls");
        char temp;
        if (check == 1)
            csList.ViewAllCustomers();
        else if (check == 2)
            mdList.ViewAllMedicines();
        else
            stList.ViewAllStaffs();
        cout << "\n1. Them.\n";
        cout << "2. Chinh sua.\n";
        cout << "3. Xoa.\n";
        cout << "4. Quay lai.\n";
        cin >> temp;
        getenter;
        while(temp<'1' || temp>'4'){
            cout << "Lua chon khong phu hop!\n";
            system("pause");
            system("cls");
            if (check == 1)
                csList.ViewAllCustomers();
            else if (check == 2)
                mdList.ViewAllMedicines();
            else
                stList.ViewAllStaffs();
            cout << "\n1. Them.\n";
            cout << "2. Chinh sua.\n";
            cout << "3. Xoa.\n";
            cout << "4. Quay lai.\n";
            cin >> temp;
            getenter;
        }
        switch(temp){
            case '1':{
                system("cls");
                if (check == 1) csList.addNewCustomer();
                else if (check == 2) mdList.addNewMedicine();
                else stList.addNewStaff();
                break;
            }
            case '2':{
                if (check != 2){
                    string email;
                    cout << "Nhap email cua nguoi muon chinh sua: ";
                    getline(cin,email);
                    if (!email.empty()){
                        if (check == 1) csList.editCustomer(email);
                        else stList.editStaff(email);
                    }
                }
                else{
                    string ID;
                    cout << "Nhap ID cua thuoc muon chinh sua: ";
                    getline(cin,ID);
                    if (!ID.empty()) mdList.editMedicine(ID);
                }
                break;
            }
            case '3':{
                if (check != 2){
                    string email;
                    cout << "Nhap email cua nguoi muon xoa: ";
                    getline(cin,email);
                    if (!email.empty()){
                        if (check == 1) csList.removeCustomer(email);
                        else stList.removeStaff(email);
                    }
                }
                else{
                    string ID;
                    cout << "Nhap ID cua thuoc muon xoa: ";
                    getline(cin,ID);
                    if (!ID.empty()) mdList.removeMedicine(ID);
                }
                break;
            }
            case '4':{
                return;
                break;
            }
        }
    }
}

void StaffMenu::Run(StaffManagement& stList, const int& index, MedicineManagement &mdList, CustomerManagement &csList){
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
                ManagementMenu(stList,mdList,csList,1);
                break;
            }
            case '4':{      //  xem ttcn || quan ly nv
                if (authentication){
                    EditInformation(s,0);
                }
                else{
                    system("cls");
                    ManagementMenu(stList,mdList,csList,0);
                    break;
                }
                break;
            }
            case '5':{      // quan ly thuoc || tro ve
                if (!authentication){
                    system("cls");
                    ManagementMenu(stList,mdList,csList,2);
                }
                else breaker = true;
                break;
            }
            case '6':{      // xem thu chi
                if (!authentication){
                    cout << "xem thu chi";
                }
                else exit(0);
                break;
            }
            case '7':{      // xem ttcn
                if (!authentication){
                    EditInformation(s,0);
                }
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case '8':{      // tro ve
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
}