#pragma once
#include<string>
#include<iostream>
using namespace std;
template<class T>
class Management;
class Person
{
protected:
    string Name;
    string SDT;
    string DateOfBirth;
    string CCCD;
    string Address;
    string Email;
    string Password;
public:
    template<class T>
    friend class Management;
    Person();
    Person(const Person &);
    ~Person();
    void EditName();
    void EditSDT();
    void EditDateOfBirth();
    void EditCCCD();
    void EditAddress();
    void EditEmail();
    void EditPassword();
    void MenuEdit();
    void Edit(int = -1);
    friend istream &operator >> (istream&, Person &);
    friend ostream &operator << (ostream&, const Person &);
    string returnSDT();
    string returnName();
};
