#include "Person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"
#define getenter fflush(stdin);
Person::Person()
{}

Person::Person(const Person &P)
    : Name(P.Name), SDT(P.SDT), DateOfBirth(P.DateOfBirth), CCCD(P.CCCD), Address(P.Address)
{}

Person::~Person()
{}

ostream &operator << (ostream &out, const Person &P) 
{
    out << left << setw(20) << P.Name  << left << setw(13) << P.SDT << left << setw(12)<< P.DateOfBirth << left << setw(14) 
    << P.CCCD << left << setw(40) << P.Address << endl;
    return out;
}

istream &operator >> (istream &in, Person &P) 
{
    cout << endl << "- Nhap ho va ten: "; 
    getenter;
    getline(cin, P.Name);
    removeSpaces(P.Name);
    cout << "- Nhap so dien thoai: ";
    getenter;
    getline(cin, P.SDT);
    cout << "- Nhap Email: ";
    getenter;
    getline(cin, P.Email);
    cout << "- Nhap ngay thang nam sinh (dd/mm/yyyy): ";
    getenter;
    getline(cin, P.DateOfBirth);
    cout << "- Nhap so can cuoc cong dan: ";
    getenter;
    getline(cin, P.CCCD);
    removeSpaces(P.CCCD);
    cout << "- Nhap dia chi (ex: 01 Le Duan, Hai Chau, Da Nang): ";
    getenter;
    getline(cin, P.Address);
    return in;
}
