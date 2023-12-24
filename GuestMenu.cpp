#pragma once
#include "GuestMenu.h"
#include "MedicineManagement.cpp"
#include "Receipt.cpp"
using namespace std;

char GuestMenu::Show(const int& index){
    cout << GuestMenu::count++ << ". Xem va mua thuoc.\n";
    cout << GuestMenu::count++ << ". Xem gio hang va thanh toan.\n";
    if (index != -1) cout << GuestMenu::count++ << ". Xem thong tin ca nhan.\n";
    WorkMenu::Show();
    GuestMenu::count = 1;
    char temp;
    cin >> temp;
    getenter;
    return temp;
}

void GuestMenu::ReceiptMenu(CustomerManagement& csList, const int& index, Receipt& receipt, ReceiptManagement& rcList){
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
                if (index != -1){
                    cout << "Tong hoa don hien tai la: " << receipt.returnTotal() << '\n'; 
                    cout << "Quy khach hien co " << csList.returnInfo(index).returnPoint() << " diem.\n";
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
                ReceiptMenu(csList,index,receipt,rcList);
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
            case '4':{      // tro lai || thoat
                if (index==-1)
                    exitPressed = true;
                return;
            }
            case '5':{      // thoat
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