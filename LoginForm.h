#pragma once
#include <iostream>
using namespace std;

class LoginForm{
    protected:
        static int count;
    public:
        int checkLogin(string& email, string& password);
        bool backPressed = false;
        void Show();
};