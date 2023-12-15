#pragma once
#include "Medicine.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"
//#define getenter fflush(stdin);
Medicine::Medicine()
{}

Medicine::Medicine(const Medicine& M)
    : ID(M.ID), Name(M.Name), NSX(M.NSX), HSD(M.HSD), Uses(M.Uses), Guide(M.Guide), Price(M.Price), Left(M.Left), SideEffects(M.SideEffects)
{}

Medicine::~Medicine()
{}

void Medicine::WarningLeft(){
    cout << "!!! Thuoc " << this->Name << ", Ma so: " << this->ID << " con lai rat it trong kho (" << this->Left <<")\n";
}

void Medicine::WarningHSD(){
    cout << "!!! Thuoc " << this->Name << ", Ma so: " << this->ID << " sap het han su dung (" << this->HSD <<")\n";
}

ostream& operator<<(ostream &out, const Medicine &M){
    out << left << setw(7) << M.ID << left << setw(15) << M.Name << left << setw(13) << M.NSX << left << setw(13)<< M.HSD << left << setw(20) 
    << M.Uses << left << setw(40) << M.Guide << left << setw(10) << M.SideEffects << left << setw(10) << M.Left << left << setw(10) << M.Price <<  endl;
    return out;
}

istream &operator >> (istream &in, Medicine &M) 
{
    cout << endl << "- Nhap ten thuoc: "; 
    //getenter;
    getline(cin, M.Name);
    removeSpaces(M.Name);
    cout << "- Nhap ngay san xuat (dd/mm/yyyy): ";
    //getenter;
    getline(cin, M.NSX);
    removeSpaces(M.NSX);
    cout << "- Nhap han su dung (dd/bb/yyyy): ";
    //getenter;
    getline(cin, M.HSD);
    removeSpaces(M.HSD);
    cout << "- Nhap cong dung cua thuoc: ";
    //getenter;
    getline(cin, M.Uses);
    cout << "- Nhap gia cua thuoc: ";
    //getenter;
    cin >> M.Price;
    getenter;
    return in;
}

void Medicine::EditID(){
    cout << "- Nhap ID moi: ";
    edit(this -> ID);
}

void Medicine::EditName(){
    cout << "- Nhap ten thuoc moi: ";
    edit(this -> Name);
}

void Medicine::EditNSX(){
    cout << "- Nhap ngay san xuat moi: ";
    edit(this -> NSX);
}

void Medicine::EditHSD(){
    cout << "- Nhap han su dung moi: ";
    edit(this -> HSD);
}

void Medicine::EditUses(){
    cout << "- Nhap cong dung moi: ";
    edit(this -> Uses);
}
void Medicine::EditGuide(){
    cout << "- Nhap huong dan su dung moi: ";
    edit(this -> Guide);
}

void Medicine::EditPrice(){
    cout << "- Nhap gia moi: ";
    cin >> Price;
    getenter;
}
void Medicine::EditSideEffects(){
    cout << "- Nhap tac dung phu moi: ";
    edit(this->SideEffects);
}
void Medicine :: readMedicineFromFile (ifstream &in) 
{
    string t;
    getline(in, ID, '|');
    getline(in, Name, '|');
    getline(in, NSX,'|');
    getline(in, HSD,'|');
    getline(in, Uses,'|');
    getline(in, Guide, '|');
    in >> Left;
    getline(in, t, '|');
    in >> Price;
    getline(in, t, '|');
    getline(in, SideEffects, '\n');
    
}

void Medicine::MenuEdit(){
    cout << "- Nhap thong tin can thay doi hoac lua chon thoat: ";
    cout << "\n                      1. ID";
    cout << "\n                      2. Ten";
    cout << "\n                      3. Ngay san xuat";
    cout << "\n                      4. Han su dung";
    cout << "\n                      5. Cong dung";
    cout << "\n                      6. Cach dung";
    cout << "\n                      7. So luong trong kho";
    cout << "\n                      8. Gia";
    cout << "\n                      9. Tac dung phu";
    cout << "\n                      10. Thoat";
    cout << "- Nhap lua chon cua ban: ";
}

void Medicine::EditLeft(){
    cout << "- Nhap luong thuoc con lai moi: ";
    cin >> Left;
    getenter;
}

void Medicine::Edit(){
    MenuEdit();
    int t;
    cin >> t;
    getenter;
    while (t < 1 || t > 10){
        cout << "- Lua chon khong hop le, vui long chon lai\n";
        MenuEdit();
        cin >> t;
        getenter;
    }
    switch (t){
        case 1:
            EditID();
            break;
        case 2:
            EditName();
            break;
        case 3:
            EditNSX();
            break;
        case 4:
            EditHSD();
            break;
        case 5:
            EditUses();
            break;
        case 6:
            EditGuide();
            break;;
        case 7:
            EditLeft();
            break;
        case 8:
            EditPrice();
            break;
        case 9:
            EditSideEffects();
            break;
        case 10: 
            break;
    }
}
// void EditName();
//     void EditNSX();
//     void EditHSD();
//     void EditUses();
//     void EditGuide();
//     void EditPrice();
//     void EditSideEffects();
/*
truong hop cung loai thuoc nhung khac NSX
string Name;
    string NSX;
    string HSD;
    string Uses;
    string Guide;
    int Price;
    int Left;
    string SideEffects;
*/