#pragma once
#include<iostream>
using namespace std;
#include "Person.h"
class Receipt;
class StaffManagement;
class Staff: public Person
{
private:
    string StaffID;
    long long int Salary;
public:
    friend class Receipt;
    friend class StaffManagement;
    Staff();
    Staff(const Staff&);
    ~Staff();
    friend ostream& operator << (ostream &, const Staff&);
    friend istream& operator >> (istream&, Staff&);
    void readStaffFromFile (ifstream &);
    void EditSalary();
    void EditStaffID();
    void MenuEdit();
    void Edit();

};