#pragma once
#include "ExecuteCode.h"
#include "../LoginMenu/GuestLogin.cpp"
#include "../LoginMenu/StaffLogin.cpp"
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
    cout << "\t\t           |--------------------|\n";
    cout << "\t\t           | 1. Khach hang.     |\n";
    cout << "\t\t           |--------------------|\n";
    cout << "\t\t           | 2. Nhan vien.      |\n";
    cout << "\t\t           |--------------------|\n";
    cout << "\t\t           | 3. Thoat ung dung. |\n";
    cout << "\t\t           |--------------------|\n\n";
    char temp;
    cout << "Nhap lua chon: ";
    cin >> temp;
    getenter;
    return temp;
}