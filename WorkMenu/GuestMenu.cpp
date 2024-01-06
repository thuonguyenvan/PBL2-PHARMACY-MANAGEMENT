#pragma once
#include "GuestMenu.h"
#include "../Medicine/MedicineManagement.cpp"
#include "../Receipt/Receipt.cpp"
using namespace std;

char GuestMenu::Show(const int& index){
    cout << " _____ _   _ _____ _____ _____  ___  ___ _____ _   _ _   _ \n";
    cout << "|  __ \\ | | |  ___/  ___|_   _| |  \\/  ||  ___| \\ | | | | |\n";
    cout << "| |  \\/ | | | |__ \\ `--.  | |   | .  . || |__ |  \\| | | | |\n";
    cout << "| | __| | | |  __| `--. \\ | |   | |\\/| ||  __|| . ` | | | |\n";
    cout << "| |_\\ \\ |_| | |___/\\__/ / | |   | |  | || |___| |\\  | |_| |\n";
    cout << " \\____/\\___/\\____/\\____/  \\_/   \\_|  |_/\\____/\\_| \\_/\\___/\n\n";
    cout << "\t\t|--------------------------------|\n";
    cout << "\t\t| " << GuestMenu::count++ << ". Xem va mua thuoc.           |\n";
    cout << "\t\t|--------------------------------|\n";
    cout << "\t\t| " << GuestMenu::count++ << ". Xem gio hang va thanh toan. |\n";
    cout << "\t\t|--------------------------------|\n";
    if (index != -1){
        cout << "\t\t| " << GuestMenu::count++ << ". Xem thong tin ca nhan.      |\n";
        cout << "\t\t|--------------------------------|\n";
        cout << "\t\t| " << GuestMenu::count++ << ". Xem lich su mua hang.       |\n";
        cout << "\t\t|--------------------------------|\n";
    }
    WorkMenu::Show();
    cout << "\t\t|--------------------------------|\n";
    cout << "\t   Lien he 0972327742 de duoc ho tro va tu van.\n\n";
    GuestMenu::count = 1;
    char temp;
    cout << " Nhap lua chon: ";
    cin >> temp;
    getenter;
    return temp;
}

void GuestMenu::ReceiptMenu(CustomerManagement& csList, Customer& customer, const int& index, Receipt& receipt, ReceiptManagement& rcList){
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
                if (customer.returnSDT() != ""){
                    cout << "Tong hoa don hien tai la: " << receipt.returnTotal() << '\n'; 
                    cout << "Quy khach hien co " << csList.returnInfo(index).returnPoint() << " diem.\n";
                    if (csList.returnInfo(index).returnPoint() > 0){
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
                            cin >> temp;
                            getenter;
                        }
                        if (temp==1){
                            long long total = receipt.returnTotal()/100;
                            receipt.DeductTotal((csList.returnInfo(index).returnPoint()<total)?csList.returnInfo(index).returnPoint():total);
                            csList.DeductPoint((csList.returnInfo(index).returnPoint()<total)?csList.returnInfo(index).returnPoint():total,index);
                            Customer temp(csList.returnInfo(index));
                            customer = temp;
                        }
                    }
                }
                else{
                    string name, SDT;
                    cout << "Vui long nhap ten: ";
                    getline(cin,name);
                    cout << "Vui long nhap SDT: ";
                    getline(cin,SDT);
                    receipt.addCustomerToReceipt(name,SDT);
                }
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
                cout << "\nDon hang se tu dong bi xoa sau 10 ngay khong thanh toan va nhan thuoc.\n";
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

void GuestMenu::Run(CustomerManagement& csList, const int& index, MedicineManagement &mdList, ReceiptManagement& rcList){
    Customer c;
    if (index!=-1){
        Customer temp(csList.returnInfo(index));
        c = temp;
    }
    else{
        Customer temp;
        c = temp;
    }
    Staff s;
    Receipt receipt(c,s);
    while (true){
        system("cls");
        char temp = this->Show(index);
        switch(temp){
            case '1':{      // Xem thuoc
                BuyMedicine(mdList,receipt);
                break;
            }
            case '2':{      // Xem gio hang
                ReceiptMenu(csList,c,index,receipt,rcList);
                break;
            }
            case '3':{      // xem thong tin ca nhan || tro lai
                if (index!=-1){
                    int authentication = -1;
                    EditInformation(c,authentication);
                }
                else
                    return;
                break;
            }
            case '4':{      //xem lich su mua hang || thoat
                if (index==-1){
                    exitPressed = true;
                    return;
                }
                else{
                    rcList.showOrderHistory(c.returnSDT());
                    system("pause");
                    break;
                }
            }
            case '5':{      // tro lai
                if (index!=-1){
                    return;
                }
            }
            case '6':{      //thoat
                if (index!=-1){
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