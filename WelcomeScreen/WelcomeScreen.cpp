#pragma once
#include "WelcomeScreen.h"
using namespace std;

void WelcomeScreen::Run(){
    retry:    char temp = WelcomeScreen::Show();
    switch(temp){
        case 1:{
            GuestLogin::Run();
            break;
        }
        case 2:{
            EmployeeLogin::Run();
            break;
        }
        case 3:{
            exit(0);
            break;
        }
        default: goto retry;
    }
}

char WelcomeScreen::Show(){
    cout << "~~~~~~~~~~~|||~~~~~~~~~~~|||~~~~~~~~~~~\n";
    cout << "              PLACEHOLDER\n\n";
    cout << "             Vui long chon:\n";
    cout << "             1. Khach hang.\n";
    cout << "             2. Nhan vien.\n\n";
    cout << "             3. Thoat ung dung.\n\n";
    cout << "~~~~~~~~~~~|||~~~~~~~~~~~|||~~~~~~~~~~~\n";
    char temp;
    cin >> temp;
    return temp;
}