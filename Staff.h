#pragma once
#include<iostream>
using namespace std;
#include "Person.h"

class Staff: public Person
{
private:
    int Authentication;
    string StaffID;
    double Salary;
public:
    Staff();
    Staff(const Staff&);
    ~Staff();
    friend ostream& operator << (ostream &, const Staff&);
    friend istream& operator >> (istream&, Staff&);
};