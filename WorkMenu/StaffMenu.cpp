#include "StaffMenu.h"
#include "../Medicine/MedicineManagement.cpp"
using namespace std;

char StaffMenu::Show(const int& authentication){
    cout << " _____ _____ ___  ____________  ___  ___ _____ _   _ _   _\n";
    cout << "/  ___|_   _/ _ \\ |  ___|  ___| |  \\/  ||  ___| \\ | | | | |\n";
    cout << "\\ `--.  | |/ /_\\ \\| |_  | |_    | .  . || |__ |  \\| | | | |\n";
    cout << " `--. \\ | ||  _  ||  _| |  _|   | |\\/| ||  __|| . ` | | | |\n";
    cout << "/\\__/ / | || | | || |   | |     | |  | || |___| |\\  | |_| |\n";
    cout << "\\____/  \\_/\\_| |_/\\_|   \\_|     \\_|  |_/\\____/\\_| \\_/\\___/\n\n";
    cout << "\t\t|--------------------------------|\n";
    cout << "\t\t| " << StaffMenu::count++ << ". Xem va tim thuoc.           |\n";
    cout << "\t\t|--------------------------------|\n";
    cout << "\t\t| " << StaffMenu::count++ << ". Tao giao dich.              |\n";
    cout << "\t\t|--------------------------------|\n";
    cout << "\t\t| " << StaffMenu::count++ << ". Quan ly khach hang.         |\n";
    cout << "\t\t|--------------------------------|\n";
    if (!authentication){
        cout << "\t\t| " << StaffMenu::count++ << ". Quan ly nhan vien.          |\n";
        cout << "\t\t|--------------------------------|\n";
        cout << "\t\t| " << StaffMenu::count++ << ". Quan ly thuoc.              |\n";
        cout << "\t\t|--------------------------------|\n";
    }
    cout << "\t\t| " << StaffMenu::count++ << ". Quan ly hoa don.            |\n";
    cout << "\t\t|--------------------------------|\n";
    cout << "\t\t| " << StaffMenu::count++ << ". Xem thong tin ca nhan.      |\n";
    cout << "\t\t|--------------------------------|\n";
    WorkMenu::Show();
    cout << "\t\t|--------------------------------|\n\n";
    StaffMenu::count = 1;
    char temp;
    cout << "Nhap lua chon: ";
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
                        Customer c(csList.returnInfo(index));
                        receipt.addCustomerToReceipt(c.returnName(),c.returnSDT());
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
                                long long total = receipt.returnTotal()/100;
                                receipt.DeductTotal((csList.returnInfo(index).returnPoint()<total)?csList.returnInfo(index).returnPoint():total);
                                csList.DeductPoint((csList.returnInfo(index).returnPoint()<total)?csList.returnInfo(index).returnPoint():total,index);
                            }
                        }
                        csList.AccumPoint(receipt.returnTotal()/100,index);
                    }
                    else{
                        string name="";
                        receipt.addCustomerToReceipt(name,temp);
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

void StaffMenu::ReceiptManagementMenu(ReceiptManagement& rcList, const int& authentication, CustomerManagement& csList, MedicineManagement& mdList, Staff& s){
    while(true){
        system("cls");
        char temp;
        cout << "1. Xem tat ca hoa don.\n";
        cout << "2. Tim hoa don.\n";
        cout << "3. Xem hoa don chua thanh toan.\n";
        cout << "4. Xac nhan hoa don da thanh toan.\n";
        if (authentication)
            cout << "5. Tro ve.\n";
        else{
            cout << "5. Xoa hoa don.\n";
            cout << "6. Tro ve.\n";
        }
        cin >> temp;
        getenter
        switch (temp){
            case '1':{
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
                cout << "5. Tim theo khach hang.\n";
                cout << "6. Tim theo nhan vien.\n";
                cout << "7. Tro ve.\n";
                cin >> temp;
                getenter
                while (temp < '1' || temp > '7'){
                    cout << "Lua chon khong hop le!\n";
                    cout << "Vui long chon lai.\n";
                    system("pause");
                    system("cls");
                    cout << "1. Tim theo ngay.\n";
                    cout << "2. Tim theo thang.\n";
                    cout << "3. Tim theo nam.\n";
                    cout << "4. Tim theo ma giao dich.\n";
                    cout << "5. Tim theo khach hang.\n";
                    cout << "6. Tim theo nhan vien.\n";
                    cout << "7. Tro ve.\n";
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
                    case '5':{
                        string SDT;
                        cout << "Nhap SDT cua khach hang can tim: ";
                        getline(cin,SDT);
                        rcList.showOrderHistory(SDT);
                        system("pause");
                        break;
                    }
                    case '6':{
                        string ID;
                        cout << "Nhap ID cua nhan vien can tim: ";
                        getline(cin,ID);
                        rcList.showReceiptByStaff(ID);
                        system("pause");
                        break;
                    }
                    case '7': break;
                }
                break;
            }
            case '3':{
                system("cls");
                rcList.showAllUnpaidReceipt();
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
                    if (index != -1){
                        if (!rcList.List[index].returnStatus()){
                            rcList.List[index].showReceipt();
                            cout << "\n Ban co chac muon xac nhan hoa don nay da thanh toan khong?\n";
                            cout << "1. Co.\n";
                            cout << "2. Khong.\n";
                            cin >> temp;
                            getenter;
                            while (temp != '1' && temp != '2'){
                                cout << "Lua chon khong hop le!\n";
                                cout << "Vui long chon lai.\n";
                                system("pause");
                                rcList.List[index].showReceipt();
                                cout << "\n Ban co chac muon xac nhan hoa don nay da thanh toan khong?\n";
                                cout << "1. Co.\n";
                                cout << "2. Khong.\n";
                                cin >> temp;
                                getenter;
                            }
                            if (temp == '1'){
                                int index = csList.FindCustomerByPhoneNum(rcList.List[index].Customer::returnSDT());
                                csList.AccumPoint(rcList.List[index].returnTotal(),index);
                                cout << "Xac nhan thanh cong.\n";
                                rcList.List[index].editReceiptStatus();
                                rcList.List[index].addStaffToReceipt(s);
                            }
                        }
                        else{
                            cout << "Hoa don nay da duoc thanh toan!\n";
                        }
                    }
                    else cout << "Khong tim thay hoa don voi ma giao dich nay!\n";
                    system("pause");
                }
                break;
            }
            case '5':{
                if (!authentication){
                    system("cls");
                    cout << "Nhap ma giao dich cua hoa don can xoa: ";
                    string maGD;
                    getline(cin,maGD);
                    if (!maGD.empty()){
                        rcList.removeReceipt(maGD,mdList,csList);
                        system("pause");
                    }
                    break;
                }
                else return;
            }
            case '6':{
                if (!authentication) return;
            }
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
        char temp = this->Show(authentication);
        switch(temp){
            case '1':{      // Xem thuoc
                StaffMenu::BuyMedicine(mdList,receipt);
                break;
            }
            case '2':{      // tao giao dich
                ReceiptMenu(csList,receipt,rcList);
                break;
            }
            case '3':{      // Quan ly khach
                ManagementMenu(stList,mdList,csList,1);
                break;
            }
            case '4':{      //  xem ttcn || quan ly nv
                if (authentication)
                    ReceiptManagementMenu(rcList,authentication,csList,mdList,s);
                else
                    ManagementMenu(stList,mdList,csList,0);
                break;
            }
            case '5':{      // quan ly thuoc || tro ve
                if (!authentication)
                    ManagementMenu(stList,mdList,csList,2);
                else EditInformation(s,authentication);
                break;
            }
            case '6':{      // quan ly hoa don
                if (!authentication){
                    ReceiptManagementMenu(rcList,authentication,csList,mdList,s);
                }
                else{
                    return;
                }
                break;
            }
            case '7':{      // xem ttcn
                if (!authentication)
                    EditInformation(s,authentication);
                else{
                    exitPressed = true;
                    return;
                }
                break;
            }
            case '8':{      // tro ve
                if (!authentication)
                    return;
                else{
                    cout << "Lua chon khong hop le!\n";
                    system("pause");
                    system("cls");
                }
                break;
            }
            case '9':{
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