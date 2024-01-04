#pragma once
#include "ExecuteCode.h"
#include "..\GuestLogin.cpp"
#include "..\StaffLogin.cpp"
#include "..\CustomerManagement.cpp"
#include "..\StaffManagement.cpp"
#include "..\MedicineManagement.cpp"
using namespace std;

void ExecuteCode::Run(MedicineManagement &M, CustomerManagement &C, StaffManagement &S, ReceiptManagement& R){
    while (true){
        system("cls");
        char temp = ExecuteCode::Show();
        switch(temp){
            case '1':{
                GuestLogin guestLogin;
                guestLogin.Run(C, S, M,R);
                if (guestLogin.exitPressed) return;
                break;
            }
            case '2':{
                StaffLogin staffLogin;
                staffLogin.Run(S, C, M,R);
                if (staffLogin.exitPressed) return;
                break;
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

char ExecuteCode::Show(){
    cout << " _____ _____  ___ _____  ______ _   _   ___  _________  ___  ___  _______   __ \n";             
    cout << "|  __ \\  _  |/ _ \\_   _| | ___ \\ | | | / _ \\ | ___ \\  \\/  | / _ \\/  __ \\ \\ / /\n";
    cout << "| |  \\/ | | / /_\\ \\| |   | |_/ / |_| |/ /_\\ \\| |_/ / .  . |/ /_\\ \\ /  \\/\\ V / \n";
    cout << "| | __| | | |  _  || |   |  __/|  _  ||  _  ||    /| |\\/| ||  _  | |     \\ /  \n";
    cout << "| |_\\ \\ \\_/ / | | || |   | |   | | | || | | || |\\ \\| |  | || | | | \\__/\\ | | \n";
    cout << " \\____/\\___/\\_| |_/\\_/   \\_|   \\_| |_/\\_| |_/\\_| \\_\\_|  |_/\\_| |_/\\____/ \\_/ \n\n";
    cout << "\t\t\t\u00A6--------------------\u00A6\n";
    cout << "\t\t\t\u00A6 1. Khach hang.     \u00A6\n";
    cout << "\t\t\t\u00A6--------------------\u00A6\n";
    cout << "\t\t\t\u00A6 2. Nhan vien.      \u00A6\n";
    cout << "\t\t\t\u00A6--------------------\u00A6\n";
    cout << "\t\t\t\u00A6 3. Thoat ung dung. \u00A6\n";
    cout << "\t\t\t\u00A6--------------------\u00A6\n\n";
    char temp;
    cout << "Nhap lua chon: ";
    cin >> temp;
    getenter;
    return temp;
}