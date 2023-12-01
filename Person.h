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
public:
    template<class T>
    friend class Management;
    Person();
    Person(const Person &);
    ~Person();
    friend istream &operator >> (istream&, Person &);
    friend ostream &operator << (ostream&, const Person &);
};
