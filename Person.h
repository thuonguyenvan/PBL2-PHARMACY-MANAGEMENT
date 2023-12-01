#pragma once
#include<string>
#include<iostream>
using namespace std;

class Person
{
protected:
    string Name;
    string SDT;
    string DateOfBirth;
    string CCCD;
    string Address;
public:
    Person();
    Person(const Person &);
    ~Person();
    friend istream &operator >> (istream&, Person &);
    friend ostream &operator << (ostream&, const Person &);
};
