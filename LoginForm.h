#pragma once
#include <iostream>
#include "CustomerManagement.cpp"
using namespace std;

class LoginForm{
    protected:
        static int count;
    public:
        int checkLogin(CustomerManagement&);
        bool backPressed = false;
        bool leftEmpty = false;
        void static Show();
};