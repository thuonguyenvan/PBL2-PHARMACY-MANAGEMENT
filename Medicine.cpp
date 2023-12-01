#include "Medicine.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"
#define getenter fflush(stdin);
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
    out << M.ID << " " << M.Name << ": \n";
    return out;
}

istream &operator >> (istream &in, Medicine &M) 
{
    cout << endl << "- Nhap ten thuoc: "; 
    getenter;
    getline(cin, M.Name);
    removeSpaces(M.Name);
    cout << "- Nhap ngay san xuat (dd/mm/yyyy): ";
    getenter;
    getline(cin, M.NSX);
    removeSpaces(M.NSX);
    cout << "- Nhap han su dung (dd/bb/yyyy): ";
    getenter;
    getline(cin, M.HSD);
    removeSpaces(M.HSD);
    cout << "- Nhap cong dung cua thuoc: ";
    getenter;
    getline(cin, M.Uses);
    cout << "- Nhap gia cua thuoc: ";
    getenter;
    cin >> M.Price;
    return in;
}
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