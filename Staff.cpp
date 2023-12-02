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
    out << left << setw(7) << P.StaffID << left << setw(25) << P.Name  << left << setw(15) << P.SDT << left << setw(12)<< P.DateOfBirth << left << setw(14) 
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
void Staff :: readStaffFromFile (ifstream &in) 
{
    getline(in, StaffID, '|');
    getline(in, Name, '|');
    getline(in,SDT,'|');
    getline(in,DateOfBirth,'|');
    getline(in,CCCD,'|');
    getline(in, Address, '|');
    getline(in, Email, '|');
    getline(in, Password, '|');
    in >> Salary;
    string t;
    getline(in, t, '\n');
}

