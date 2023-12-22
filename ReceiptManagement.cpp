#pragma once
using namespace std;
#include "ReceiptManagement.h"
#include "Receipt.cpp"
#include "MedicineManagement.cpp"
ReceiptManagement::ReceiptManagement()
{
    List = new Receipt[1];
    Count = 0;
}

ReceiptManagement::~ReceiptManagement()
{
    delete []List;
}

string ReceiptManagement::chooseMedicine(){
    string s;
    cout << "- Nhap ID thuoc muon mua hoac 1 de thoat: ";
    cin >> s;
    return s;
}

void ReceiptManagement::addNewReceipt(const Customer &C, const Staff &S, MedicineManagement& MM){
    Receipt R(C, S);
    R.DateOfTran = getCurrentDate();
    string t = chooseMedicine();
    while (t != "1"){
        int p = MM.CheckExisted(t);
        if (!p) cout << "- Thuoc khong ton tai, vui lonng nhap thuoc khac: ";
        else{
            int l = MM.List[p-1].Left;
            cout << "- Nhap so luong ban muon mua (hien con: " << l << "):  ";
            int n;
            cin >> n;
            while (n > l || n < 0) {
                cout << "- So luong khong hop le vui long nhap lai, (hien con: " << l << "):  ";
                cin >> n;
            } 
            MM.List[p-1].Left -= n;
            R.addNewMedicine(MM.List[p-1], n);
        }
        t = chooseMedicine();
    }
    this -> Count ++;
    if (this -> Count == 1){
        List = new Receipt[1];
        List[0] = R;
    }
    else {
        Receipt tr[Count - 1];
        for (int i = 0; i < Count - 1; i++) tr[i] = List[i];
        delete [] List;
        List = new Receipt[Count];
        List[Count - 1] = R;
        for (int i = 0; i < Count - 1; i++) List[i] = tr[i];
    }
}

void ReceiptManagement::readReceiptFromFile(ifstream &File){
    this->readCountFromFile(File);
    this -> List = new Receipt[this -> Count];
    for (int i = 0; i < Count; ++ i){
        List[i].readReceiptFromFile(File);
    }
}


void ReceiptManagement::updateReceiptFile(){
    ofstream File("./Data/Receipt.txt");
    File << Count << "\n";
    for (int i = 0; i < Count; ++i){
        File << List[i].ReceiptID << "|";
        File << List[i].DateOfTran << "|";
        File << List[i].CountMedicine << "|";
        File << List[i].Staff::Name << "|";
        File << List[i].Staff::StaffID << "|";
        File << List[i].Customer::Name << "|";
        File << List[i].Customer::SDT << "|";
        for (int j =  0; j < List[i].CountMedicine; ++j){
            File << List[i].List[j].ID << "|";
            File << List[i].List[j].Name << "|";
            File << List[i].Number[j] << "|";
            File << List[i].List[j].Price << "|";
        }
        File << List[i].Total<< "\n";
    }
    File.close();
}


void ReceiptManagement::showReceiptByDate(const string & bg, const string & ed){
    string rcDate = List[0].DateOfTran.substr(0, 10);
    int t = soSanhNgay(bg, rcDate);
    int id = -1;
    if (t) id = 0;
    else{
        for (int i = 1; i < Count; ++i){
            rcDate = List[i].DateOfTran.substr(0, 10);
            t = soSanhNgay(bg, rcDate);
            if (t) {
                id = i; 
                break;
            }
        }
    }
    if (id == -1){
        printf("- Khong co giao dich nao tu ngay %s den ngay %s", bg, ed);
        return;
    }
    int c = 0;
    for (int i = id; i < Count; ++i){
        rcDate = List[i].DateOfTran.substr(0, 10);
        if (!soSanhNgay(rcDate, ed)) break;
        List[i].showReceipt();
        c++;
    }
    printf("- Co tong cong %d giao dich tu ngay %s den ngay %s", c, bg, ed);
}


void ReceiptManagement::showReceiptByMonth(const string & bg, const string & ed){
    string rcDate = List[0].DateOfTran.substr(3, 10);
    int t = soSanhNgay(bg, rcDate);
    int id = -1;
    if (t) id = 0;
    else{
        for (int i = 1; i < Count; ++i){
            rcDate = List[i].DateOfTran.substr(3, 10);
            t = soSanhNgay(bg, rcDate);
            if (t) {
                id = i; 
                break;
            }
        }
    }
    if (id == -1){
        printf("- Khong co giao dich nao tu thang %s den thang %s", bg, ed);
        return;
    }
    int c = 0;
    for (int i = id; i < Count; ++i){
        rcDate = List[i].DateOfTran.substr(3, 10);
        if (soSanhNgay(rcDate, ed)) break;
        List[i].showReceipt();
        c++;
    }
    printf("- Co tong cong %d giao dich tu thang %s den thang %s", c, bg, ed);
}


void ReceiptManagement::showReceiptByYear(const string & bg, const string & ed){
    string rcDate = List[0].DateOfTran.substr(6, 10);
    int t = soSanhNam(bg, rcDate);
    int id = -1;
    if (t) id = 0;
    else{
        for (int i = 1; i < Count; ++i){
            rcDate = List[i].DateOfTran.substr(6, 10);
            t = soSanhNam(bg, rcDate);
            if (t) {
                id = i; 
                break;
            }
        }
    }
    if (id == -1){
        printf("- Khong co giao dich nao tu nam %s den nam %s", bg, ed);
        return;
    }
    int c = 0;
    for (int i = id; i < Count; ++i){
        rcDate = List[i].DateOfTran.substr(3, 10);
        if (soSanhNam(rcDate, ed)) break;
        List[i].showReceipt();
        c++;
    }
    printf("- Co tong cong %d giao dich tu nam %s den nam %s", c, bg, ed);
}