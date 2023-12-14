#pragma once
#include "ExecuteCode.h"
#include "..\GuestLogin.cpp"
#include "..\StaffLogin.cpp"

using namespace std;

void ExecuteCode::Run(){
    

    retry:    char temp = ExecuteCode::Show();
    bool backPressed = false;
    switch(temp){
        case '1':{
            GuestLogin guestLogin;
            guestLogin.Run();
            backPressed = guestLogin.backPressed;
            break;
        }
        case '2':{
            StaffLogin staffLogin;
            staffLogin.Run();
            backPressed = staffLogin.backPressed;
            break;
        }
        case '3':{
            exit(0);
            break;
        }
        default:{
            cout << "Lua chon khong hop le!\n";
            system("pause");
            system("cls");
            goto retry;
        }
    }
    if (backPressed) goto retry;
}

char ExecuteCode::Show(){
    cout << "~~~~~~~~~~~|||~~~~~~~~~~~|||~~~~~~~~~~~\n";
    cout << "              PLACEHOLDER\n\n";
    cout << "             Vui long chon:\n";
    cout << "             1. Khach hang.\n";
    cout << "             2. Nhan vien.\n\n";
    cout << "             3. Thoat ung dung.\n\n";
    cout << "~~~~~~~~~~~|||~~~~~~~~~~~|||~~~~~~~~~~~\n";
    char temp;
    cin >> temp;
    getenter;
    return temp;
}