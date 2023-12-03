#pragma once
#include "LoginForm.h"
#include <limits>
using namespace std;

int LoginForm::count = 1;

template<typename T>
int LoginForm::checkLogin(T& List){
    system("cls");
    string email, password;
    bool checkEmail = false, checkPassword = false;
    cout << "De trong de quay lai.\n";
    cout << "Nhap email: ";
    getenter;
    getline(cin, email);
    if (email.empty()){
        this->leftEmpty = true;
        return -1;
    }
    cout << "Nhap mat khau: ";
    getline(cin, password);
    if (password.empty()){
        this->leftEmpty = true;
        return -1;
    }
    for (int i=0; i<List.returnCount(); i++){
        if (email == List.returnEmail(i)){
            checkEmail = true;
            if (password == List.returnPassword(i)){
                checkPassword = true;
                return i;
            }
        }
    }
    if (!checkEmail){
        cout << "Email doesn't exist.\n";
        return (-1);
    }
    else if (!checkPassword){
        cout << "Password is incorrect.\n";
        return (-1);
    }
    else return 0;
}

void LoginForm::Show(){
    cout << LoginForm::count++ << ". Login.\n";
    cout << LoginForm::count++ << ". Back.\n";
    cout << LoginForm::count++ << ". Exit.\n";
}