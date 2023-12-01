#include "LoginForm.h"
using namespace std;

int LoginForm::count = 1;

int LoginForm::checkLogin(string& email, string& password){
    if (email != "a"){
        cout << "Email doesn't exist.\n";
        return false;
    }
    else if (password != "a"){
        cout << "Password is incorrect.\n";
        return false;
    }
    else return true;
}

void LoginForm::Show(){
    cout << LoginForm::count++ << ". Login.\n";
    cout << LoginForm::count++ << ". Back.\n";
    cout << LoginForm::count++ << ". Exit.\n";
}