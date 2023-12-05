#pragma once
#include "Receipt.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"

Receipt::Receipt()
{
    CountMedicine = 0;
    Customer::Name = "";
    Customer::SDT = "";
    Customer::CCCD = "";
    StaffID = "";
    Staff::Name = "";
    Total = 0;
    
}

Receipt::~Receipt()
{
    delete []List;
    delete []Number;
}
Receipt::Receipt(const Customer& C, const Staff& S)
    :Customer(C), Staff(S), DateOfTran(getCurrentDate()), CountMedicine(0), Total(0)
{
}

void Receipt::addNewMedicine(const Medicine &M, const int &n){
    CountMedicine++;
    Total += M.Price * n;
    if (CountMedicine == 1){
        List = new Medicine[1];
        List[0] = M;
        Number = new int[1];
        Number[0] = n;
    }
    else {
        Medicine tm[CountMedicine - 1];
        int tn[CountMedicine - 1];
        for (int i = 0; i < CountMedicine - 1; ++ i){
            tm[i] = List[i];
            tn[i] = Number[i];
        } 
        delete [] List;
        delete [] Number;
        List = new Medicine[CountMedicine];
        Number = new int[CountMedicine];
        for (int i = 0; i < CountMedicine - 1 ; ++i){
            List[i] = tm[i];
            Number[i] = tn[i];
        }
        List[CountMedicine - 1] = M;
        Number[CountMedicine - 1] = n;
    }
    cout << "-  Da thanh cong.";
}

void Receipt::showReceipt(){
    cout << "           GOAT PHARMACY \n";
    cout << "Ma giao dich: " << ReceiptID << "     Time: " << DateOfTran << endl;
    cout << "Ten nhan vien: " << Staff::Name << "    Ma nhan vien: " << StaffID << endl;
    cout << "Ten khach hang:    " << Customer::Name << "    So dien thoai: " << Customer::SDT << endl;
    cout << "   STT " << "  Ma thuoc    " << "  Ten thuoc   " << "  So luong    " << "  Gia\n" ;
    for (int i = 1; i <= CountMedicine; ++i){
        cout << i << "  "<< List[i - 1].ID << "  "<< List[i - 1].Name << "  " << Number[i - 1] << "  "<< Number[i - 1] * List[i].Price << endl;
    } 
    cout << "Tong cong: " << Total << endl;

}

void Receipt :: readReceiptFromFile (ifstream &in) 
{
    string t;
    // getline(in, ID, '|');
    // getline(in, Name, '|');
    // getline(in, NSX,'|');
    // getline(in, HSD,'|');
    // getline(in, Uses,'|');
    // getline(in, Guide, '|');
    // in >> Left;
    // getline(in, t, '|');
    // in >> Price;
    // getline(in, t, '|');
    // getline(in, SideEffects, '\n');
    
}