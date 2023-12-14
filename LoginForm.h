#pragma once
#include <iostream>
#include "CustomerManagement.cpp"
using namespace std;

class LoginForm{
    protected:
        static int count;
    public:
        template<typename T>
        int checkLogin(T&);
        bool leftEmpty = false;
        void static Show();
};