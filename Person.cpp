#pragma once
#include "Person.h"
#include <iostream>
#include <iomanip>
#include <fstream>
//#include <limits>
#include "extraFunction.cpp"
//#define getenter cin.ignore(numeric_limits<streamsize>::max(), '\n');
Person::Person()
{}

Person::Person(const Person &P)
    : Name(P.Name), SDT(P.SDT), DateOfBirth(P.DateOfBirth), CCCD(P.CCCD), Address(P.Address), Password(P.Password)
{}

Person::~Person()
{}

ostream &operator << (ostream &out, const Person &P) 
{
    out << left << setw(20) << P.Name  << left << setw(13) << P.SDT << left << setw(12)<< P.DateOfBirth << left << setw(14) 
    << P.CCCD << left << setw(40) << P.Address << endl ;
    return out;
}

istream &operator >> (istream &in, Person &P) 
{
    cout << endl << "- Nhap ho va ten: "; 
//    getenter;
    //getline(cin, P.Name);
    cin >> P.Name;
    getenter;
    cout << "- Nhap so dien thoai: ";
//    getenter;
    getline(cin, P.SDT);
    cout << "- Nhap ngay thang nam sinh (dd/mm/yyyy): ";
//    getenter;
    getline(cin, P.DateOfBirth);
    cout << "- Nhap so can cuoc cong dan: ";
//    getenter;
    getline(cin, P.CCCD);
    removeSpaces(P.CCCD);
    cout << "- Nhap dia chi (ex: 01 Le Duan, Hai Chau, Da Nang): ";
//    getenter;
    getline(cin, P.Address);
    cout << "- Nhap mau khau: ";
//   getenter;
    getline(cin, P.Password);
    return in;

}

void Person::EditName(){
    cout << "- Nhap ten moi: ";
    edit(this -> Name);
}
void Person::EditSDT(){
    cout << "- Nhap so dien thoai moi: ";
    edit(this -> SDT);
}

void Person::EditDateOfBirth(){
    cout << "- Nhap ngay thang nam sinh moi (dd/mm/yyyy): ";
    edit(this -> DateOfBirth);
}

void Person::EditCCCD(){
    cout << "- Nhap so CCCD moi: ";
    edit(this -> CCCD);
}

void Person::EditAddress(){
    cout << "- Nhap dia chi moi (so nha, ten duong, thon/phuong, quan/huyen, tinh/thanh pho): ";
    edit(this -> Address);
}

void Person::EditEmail(){
    cout <<"- Nhap dia chi email moi";
    edit(this -> Email);
}

void Person::EditPassword(){
    cout << "- Nhap mat khau moi: ";
    edit(this -> Password);
}

void Person::MenuEdit(){
    cout << "- Nhap thong tin can thay doi hoac lua chon thoat: ";
    cout << "\n                      1. Ten";
    cout << "\n                      2. So dien thoai";
    cout << "\n                      3. Ngay sinh";
    cout << "\n                      4. Can cuoc cong dan";
    cout << "\n                      5. Dia chi";
    cout << "\n                      6. Email";
    cout << "\n                      7. Mat khau";
}
void Person::Edit(int t){
    if (t == -1){
        MenuEdit();
        cout << "\n                      8. Thoat\n";
        cin >> t;
        getenter;
        while (t < 1 || t > 8){
            cout << "- Lua chon khong hop le, vui long nhap lai";
            MenuEdit();
            cout << "\n                      8. Thoat\n";
            cin >> t;
            getenter;
        }
    }
    switch(t){
        case 1: 
            EditName();
            break;
        case 2: 
            EditSDT();
            break;
        case 3: 
            EditDateOfBirth();
            break;
        case 4: 
            EditCCCD();
            break;
        case 5: 
            EditAddress();
            break;
        case 6: 
            EditEmail();
            break;
        case 7: 
            EditPassword();
            break;
        case 8: 
            break;
    }

}