#pragma once
#include<iostream>
using namespace std;
#include "Person.h"

class Staff: public Person
{
private:
    string StaffID;
    double Salary;
public:
    Staff();
    Staff(const Staff&);
    ~Staff();
    friend ostream& operator << (ostream &, const Staff&);
};