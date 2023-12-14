#pragma once
#include "Staff.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"
Staff::Staff()
{
    Name = "";
    StaffID = "";
}

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

void Staff::EditSalary(){
    cout <<"- Nhap luong moi";
    cin >> Salary;
}

void Staff::EditStaffID(){
    cout <<"- Nhap ID moi";
    edit(this -> StaffID);
}
void Staff::MenuEdit(){
    Person::MenuEdit();
    cout << "\n                      8. Luong";
    cout << "\n                      9. ID";
    cout << "\n                      10. Thoat";
}

void Staff::Edit(){
    MenuEdit();
    int t;
    cin >> t;
    while (t < 1 || t > 10){
        cout << "- Lua chon khong hop le, vui long nhap lai";
        MenuEdit();
        cin >> t;
    }
    if (t < 8) Person::Edit();
    else{
        switch (t)
        {
            case 8: 
                EditSalary();
                break;
            case 9:
                EditStaffID();
                break;
            case 10:
                break;
        }
    }
}