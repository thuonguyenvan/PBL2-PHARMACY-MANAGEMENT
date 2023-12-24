#include "StaffMenu.h"
#include "MedicineManagement.cpp"
using namespace std;

int StaffMenu::Show(const int& authentication){
    cout << StaffMenu::count++ << ". Xem va tim thuoc.\n";
    cout << StaffMenu::count++ << ". Tao giao dich.\n";
    cout << StaffMenu::count++ << ". Quan ly khach hang.\n";
    if (!authentication){
        cout << StaffMenu::count++ << ". Quan ly nhan vien.\n";
        cout << StaffMenu::count++ << ". Quan ly thuoc.\n";
        cout << StaffMenu::count++ << ". Quan ly hoa don.\n";
    }
    cout << StaffMenu::count++ << ". Xem thong tin ca nhan.\n";
    WorkMenu::Show();
    StaffMenu::count = 1;
    int temp;
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
            }
            default:{
                cout << "Lua chon khong phu hop!\n";
                system("pause");
                system("cls");
                break;
            }
        }
    }
}

void StaffMenu::ReceiptMenu(CustomerManagement& csList, Receipt& receipt, ReceiptManagement& rcList){
    while (true){
        system("cls");
        receipt.showReceipt();
        cout << "\n1. Chinh sua thuoc.\n";
        cout << "2. Tien hanh thanh toan.\n";
        cout << "3. Tro lai.\n";
        char temp;
        cin >> temp;
        getenter;
        switch(temp){
            case '1':{
                system("cls");
                receipt.editReceipt();
                break;
            }
            case '2':{
                cout << "Nhap so dien thoai cua khach (de trong de bo qua): ";
                string temp;
                getline(cin,temp);
                if (!temp.empty()){
                    int index = csList.FindCustomerByPhoneNum(temp);
                    if(index!=-1){
                        cout << "Tong hoa don hien tai la: " << receipt.returnTotal() << '\n'; 
                        cout << "Quy khach hien co " << csList.returnInfo(index).returnPoint() << "diem.\n";
                        if (csList.returnInfo(index).returnPoint() != 0){
                            cout << "Quy khach co muon dung diem khong? (Mot diem tuong duong 100 dong)\n";
                            cout << "1. Co.\n";
                            cout << "2. Khong.\n";
                            int temp;
                            cin >> temp;
                            getenter;
                            while (temp!=1 && temp!=2){
                                cout << "Lua chon khong hop le!\n";
                                cout << "Vui long chon lai.\n";
                                system("pause");
                                system("cls");
                                cout << "Quy khach co muon dung diem khong? (Mot diem tuong duong 100 dong)\n";
                                cout << "1. Co.\n";
                                cout << "2. Khong.\n";
                                int temp;
                                cin >> temp;
                                getenter;
                            }
                            if (temp==1){
                                receipt.DeductTotal((csList.returnInfo(index).returnPoint()<receipt.returnTotal()/100)?csList.returnInfo(index).returnPoint():receipt.returnTotal()/100);
                                csList.returnInfo(index).DeductPoint((csList.returnInfo(index).returnPoint()<receipt.returnTotal()/100)?csList.returnInfo(index).returnPoint():receipt.returnTotal()/100);
                            }
                        }
                        csList.returnInfo(index).AccumPoint(receipt.returnTotal());
                    }
                }
                receipt.editReceiptStatus();
                rcList.addNewReceipt(receipt);
                system("cls");
                cout << "Thong tin chuyen khoan:\n";
                cout << "   - So tai khoan: 0972327742\n";
                cout << "   - Ngan hang: MB Bank\n";
                cout << "   - Ten: Nguyen Huu Hung Dung\n";
                cout << "   - So tien: " << receipt.returnTotal() << '\n';
                cout << "\nVui long luu lai hinh anh chuyen khoan de nhan thuoc.\n";
                cout << "Hoac quy khach co the thanh toan truc tiep khi nhan thuoc.\n";
                cout << "\nXin cam on quy khach.\n";
                system("pause");
                receipt.ClearReceipt();
                return;
            }
            case '3':{
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

void StaffMenu::ReceiptManagementMenu(ReceiptManagement& rcList){
    while(true){
        system("cls");
        char temp;
        cout << "1. Xem tat ca hoa don.\n";
        cout << "2. Tim hoa don.\n";
        cout << "3. Xem hoa don chua thanh toan.\n";
        cout << "4. Tro ve.\n";
        cin >> temp;
        getenter
        switch (temp){
            case '1':{
                string bg = "0000";
                system("cls");
                rcList.showReceiptByYear1("0000","9999");
                system("pause");
                break;
            }
            case '2':{
                system("cls");
                cout << "1. Tim theo ngay.\n";
                cout << "2. Tim theo thang.\n";
                cout << "3. Tim theo nam.\n";
                cout << "4. Tim theo ma giao dich.\n";
                cout << "5. Tro ve.\n";
                cin >> temp;
                getenter
                while (temp < '1' || temp > '5'){
                    cout << "Lua chon khong hop le!\n";
                    cout << "Vui long chon lai.\n";
                    system("pause");
                    system("cls");
                    cout << "1. Tim theo ngay.\n";
                    cout << "2. Tim theo thang.\n";
                    cout << "3. Tim theo nam.\n";
                    cout << "4. Tim theo ma giao dich.\n";
                    cout << "5. Tro ve.\n";
                    cin >> temp;
                    getenter;
                }
                switch (temp){
                    case '1':{
                        system("cls");
                        rcList.showReceiptByDate();
                        system("pause");
                        break;
                    }
                    case '2':{
                        system("cls");
                        rcList.showReceiptByMonth();
                        system("pause");
                        break;
                    }
                    case '3':{
                        system("cls");
                        rcList.showReceiptByYear();
                        system("pause");
                        break;
                    }
                    case '4':{
                        system("cls");
                        string ID;
                        cout << "Nhap ma giao dich (de trong de quay lai): ";
                        getline(cin,ID);
                        if (!ID.empty()){
                            int index = rcList.findReceiptByID(ID);
                            if (index != -1) rcList.List[index].showReceipt();
                            else cout << "Khong tim thay hoa don voi ma giao dich nay!\n";
                            system("pause");
                        }
                        break;
                    }
                }
                break;
            }
            case '3':{
                system("cls");
                rcList.showAllUnpaidReceipt();
                system("pause");
                break;
            }
            case '4': return;
            default:{
                cout << "Lua chon khong hop le!\n";
                cout << "Vui long chon lai.\n";
                system("pause");
                break;
            }
        }
    }
}

void StaffMenu::Run(StaffManagement& stList, const int& index, MedicineManagement &mdList, CustomerManagement &csList, ReceiptManagement& rcList){
    int authentication = checkAuthentication(stList,index);
    Customer c;
    Staff s(stList.returnInfo(index));
    Receipt receipt(c,s);
    while (true){
        system("cls");
        int temp = this->Show(authentication);
        switch(temp){
            case 1:{      // Xem thuoc
                StaffMenu::BuyMedicine(mdList,receipt);
                break;
            }
            case 2:{      // tao giao dich
                ReceiptMenu(csList,receipt,rcList);
                break;
            }
            case 3:{      // Quan ly khach
                ManagementMenu(stList,mdList,csList,1);
                break;
            }
            case 4:{      //  xem ttcn || quan ly nv
                if (authentication)
                    EditInformation(s,authentication);
                else
                    ManagementMenu(stList,mdList,csList,0);
                break;
            }
            case 5:{      // quan ly thuoc || tro ve
                if (!authentication)
                    ManagementMenu(stList,mdList,csList,2);
                else return;
                break;
            }
            case 6:{      // xem thu chi
                if (!authentication){
                    ReceiptManagementMenu(rcList);
                }
                else{
                    exitPressed = true;
                    return;
                }
                break;
            }
            case 7:{      // xem ttcn
                if (!authentication)
                    EditInformation(s,authentication);
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 8:{      // tro ve
                if (!authentication)
                    return;
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case 9:{
                if (!authentication){
                    exitPressed = true;
                    return;
                }
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