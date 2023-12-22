#pragma once
#include "Receipt.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"

Receipt::Receipt()
{
    status = 0;
    CountMedicine = 0;
    Customer::Name = "";
    Customer::SDT = "";
    Customer::CCCD = "";
    StaffID = "";
    Staff::Name = "";
    Total = 0;
    List = new Medicine[1];
    Number = new int[1];
    ReceiptID = generate_transaction_code();
}

Receipt::~Receipt()
{
    delete[] List;
    delete[] Number;
}
Receipt::Receipt(const Customer& C, const Staff& S)
    :Customer(C), Staff(S), DateOfTran(getCurrentDate()), CountMedicine(0), Total(0), ReceiptID(generate_transaction_code())
{
    List = new Medicine[1];
    Number = new int[1];
    status = 0;
}

void Receipt::addNewMedicine(const Medicine &M, const int &n){
    int p = checkExistedMedicine(M.ID);
    if (p){
        Number[p - 1] += n;
        Total += M.Price * n;
        return;
    }
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
    cout << "-  Da them thanh cong.";
}

void Receipt::showReceipt(){
    refreshReceipt();
    cout << "           GOAT PHARMACY \n";
    cout << "Ma giao dich: " << ReceiptID << "     Time: " << DateOfTran << endl;
    cout << "Ten nhan vien: " << Staff::Name << "    Ma nhan vien: " << StaffID << endl;
    cout << "Ten khach hang:    " << Customer::Name << "    So dien thoai: " << Customer::SDT << endl;
    cout << "   STT " << "  Ma thuoc    " << "  Ten thuoc   " << "  So luong    " << "  Gia\n" ;
    for (int i = 1; i <= CountMedicine; ++i){
        cout << i << "  "<< List[i - 1].ID << "  "<< List[i - 1].Name << "  " << Number[i - 1] << "  "<< Number[i - 1] * List[i - 1].Price << endl;
    } 
    cout << "Tong cong: " << Total  << "       Trang thai: " << (status ? "Da thanh toan" : "Chua thanh toan") << endl;

}


void Receipt::refreshReceipt(){
    int cnt = 0;
    Medicine tl[CountMedicine];
    int tn[CountMedicine];
    for (int i = 0; i < CountMedicine; ++i){
        tn[i] = Number[i];
        tl[i] = List[i];
        cnt += Number[i] == 0;
    }
    if (!cnt) return;
    delete [] this->List;
    delete [] this->Number;
    CountMedicine -= cnt;
    this -> List = new Medicine[CountMedicine];
    this -> Number = new int[CountMedicine];
    int cur = 0;
    for (int i = 0; i < CountMedicine + cnt; ++i){
        if (tn[i]) {
            List[cur] = tl[i];
            Number[cur++] = tn[i];
        }
    }
}

int Receipt::checkExistedMedicine(const string &ID){
    for (int i = 0; i < CountMedicine; ++i){
        if (List[i].ID == ID) return i + 1;
    }
    return 0;
}

void Receipt::editMedicineInReceipt(const string &ID){
    int p = checkExistedMedicine(ID);
    if (!p){
        cout << "- Thuoc khong ton tai";
        return;
    }
    cout << "- Nhap moi so luong muon mua: ";
    int n;
    cin >> n;
    getenter;
    while (n < 0 || n > Number[p - 1]) {
        cout << "- So luong khong hop le, vui long nhap lai: ";
        cin >> n;
        getenter;
    }
    Number[p - 1] = n;
}
void Receipt::editReceipt(){
    showReceipt();
    string tid;
    cout << "- Nhap ID thuoc can chinh sua hoac nhap 1 de thoat: ";
    cin >> tid;
    getenter;
    while (tid != "1"){
        system("cls");
        editMedicineInReceipt(tid);
        showReceipt();
        cout << "- Nhap ID thuoc can chinh sua hoac nhap 1 de thoat: ";
        cin >> tid;
        getenter;
    }
}

void Receipt::buyMedicine(const string& ID, MedicineManagement& mdList){
    int p = mdList.CheckExisted(ID);
    if (!p) {
        cout << "- Thuoc khong ton tai";
        return;
    }
    int n;
    cout << "- Nhap so luong thuoc muon mua: ";
    cin >> n;
    getenter;
    while (n < 0 || n > mdList.List[p - 1].Left) {
        cout << "- So luong thuoc khong hop le, vui long nhap lai: ";
        cin >> n;
        getenter;
    }
    mdList.List[p - 1].Left -= n;
    addNewMedicine(mdList.List[p - 1], n);
}

long long Receipt::returnTotal(){
    return this->Total;
}

void Receipt::ClearReceipt(){
    CountMedicine = 0;
    Total = 0;
    delete[] List;
    delete[] Number;
    List = new Medicine[1];
    Number = new int[1];
}

void Receipt :: readReceiptFromFile (ifstream &in) 
{
    string t;
    getline(in, ReceiptID, '|');
    in >> status;
    getline(in, t, '|');
    getline(in, DateOfTran, '|');
    in >> CountMedicine;
    getline(in, t, '|');
    getline(in, Staff::Name,'|');
    getline(in, StaffID,'|');
    getline(in, Customer::Name,'|');
    getline(in, Customer::SDT,'|');
    this -> List = new Medicine[CountMedicine];
    this -> Number = new int[CountMedicine];
    for (int i = 0; i < CountMedicine; i++){
        getline(in, List[i].ID, '|');
        getline(in, List[i].Name, '|');
        in >> Number[i];
        getline(in, t, '|');
        in >> List[i].Price;
        getline(in, t, '|');
    }
    in >> Total;
    getline(in, t, '\n');
}