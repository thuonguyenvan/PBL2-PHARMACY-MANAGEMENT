#pragma once
#include "Staff.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"
Staff::Staff()
{}

Staff::Staff(const Staff& S)
    :Person(S), Salary(S.Salary), StaffID(S.StaffID)
{}

Staff::~Staff()
{}

ostream &operator << (ostream &out, const Staff &P) 
{
    out << left << setw(5) << P.Authentication << left << setw(5) << P.StaffID << left << setw(20) << P.Name  << left << setw(13) << P.SDT << left << setw(12)<< P.DateOfBirth << left << setw(14) 
    << P.CCCD << left << setw(40) << P.Address << left << setw(10) << P.Salary << endl;
    return out;
}
istream &operator >> (istream &in, Staff &S){
    cout << "- Nhap phan quyen (Manager: 0, Staff: 1): ";
    cin >> S.Authentication;
    cout << "- Nhap ID cua nhan vien: ";
    in >> S.StaffID;
    in >> static_cast<Person&>(S);
    cout << "- Nhap luong cua nhan vien: ";
    in >> S.Salary;
    return in;
}