#pragma once
#include<iostream>
using namespace std;
#include "Person.h"

class Staff: public Person
{
private:
    int Authentication;
    string StaffID;
    long long int Salary;
public:
    Staff();
    Staff(const Staff&);
    ~Staff();
    friend ostream& operator << (ostream &, const Staff&);
    friend istream& operator >> (istream&, Staff&);
    void readStaffFromFile (ifstream &);

};