#pragma once
#include<string>
#include<iostream>
using namespace std;


class Person
{
public:
    string Name;
    string SDT;
    string DateOfBirth;
    string CCCD;
    string Address;
    string Email;
public:
    Person();
    Person(const Person &);
    ~Person();
    friend istream &operator >> (istream&, Person &);
    friend ostream &operator << (ostream&, const Person &);
};
