#pragma once
using namespace std;
#include "ReceiptManagement.h"
#include "Receipt.cpp"
#include "../Medicine/MedicineManagement.cpp"
ReceiptManagement::ReceiptManagement()
{
    //List = new Receipt[1];
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

void ReceiptManagement::addNewReceipt(const Receipt & R){
    if (!R.CountMedicine) return;
    this -> Count ++;
    if (this -> Count == 1){
        List = new Receipt[1];
        List[0] = R;
    }
    else {
        Receipt tr[Count - 1];
        for (int i = 0; i < Count - 1; i++) tr[i] = List[i];
        delete[] List;
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
        File << List[i].status << "|";
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


void ReceiptManagement::showReceiptByDate1(const string & bg, const string & ed){
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
        cout << "- Khong co giao dich nao tu ngay " << bg << " den ngay " << ed << endl; 
        return;
    }
    int c = 0;
    for (int i = id; i < Count; ++i){
        rcDate = List[i].DateOfTran.substr(0, 10);
        if (!soSanhNgay(rcDate, ed)) break;
        List[i].showReceipt();
        c++;
    }
    cout << "- Co " << c << " giao dich  tu ngay " << bg << " den ngay " << ed << endl;
}


void ReceiptManagement::showReceiptByMonth1(const string & bg, const string & ed){
    string rcDate = List[0].DateOfTran.substr(3, 7);
    int t = soSanhNgay(bg, rcDate);
    int id = -1;
    if (t) id = 0;
    else{
        for (int i = 1; i < Count; ++i){
            rcDate = List[i].DateOfTran.substr(3, 7);
            t = soSanhNgay(bg, rcDate);
            if (t) {
                id = i; 
                break;
            }
        }
    }
    if (id == -1){
        cout << "- Khong co giao dich nao tu thang " << bg << " den thang " << ed << endl; 
        return;
    }
    int c = 0;
    for (int i = id; i < Count; ++i){
        rcDate = List[i].DateOfTran.substr(3, 7);
        if (!soSanhNgay(rcDate, ed)) break;
        List[i].showReceipt();
        c++;
    }
    cout << "- Co " << c << " giao dich tu thang " << bg << " den thang " << ed << endl;
}


void ReceiptManagement::showReceiptByYear1(const string & bg, const string & ed){
    string rcDate = List[0].DateOfTran.substr(6, 4);
    int t = soSanhNam(bg, rcDate);
    int id = -1;
    if (t) id = 0;
    else{
        for (int i = 1; i < Count; ++i){
            rcDate = List[i].DateOfTran.substr(6, 4);
            t = soSanhNam(bg, rcDate);
            if (t) {
                id = i; 
                break;
            }
        }
    }
    if (id == -1){
        cout << "- Khong co giao dich nao tu nam " << bg << " den nam " << ed << endl; 
        return;
    }
    int c = 0;
    for (int i = id; i < Count; ++i){
        rcDate = List[i].DateOfTran.substr(6, 4);
        if (!soSanhNam(rcDate, ed)) break;
        List[i].showReceipt();
        c++;
    }
    cout << "- Co " << c << " giao dich  tu nam " << bg << " den nam " << ed << endl;
}

void ReceiptManagement::showReceiptByDate(){
    string s1, s2;
    cout << "- Nhap ngay bat dau theo dinh dang dd/mm/yyyy: ";
    cin >> s1;
    cout << "- Nhap ngay ket thuc theo dinh dang dd/mm/yyyy: ";
    cin >> s2;
    showReceiptByDate1(s1, s2);
}

void ReceiptManagement::showReceiptByMonth(){
    string s1, s2;
    cout << "- Nhap thang bat dau theo dinh dang mm/yyyy: ";
    cin >> s1;
    cout << "- Nhap thang ket thuc theo dinh dang mm/yyyy: ";
    cin >> s2;
    showReceiptByMonth1(s1, s2);
}

void ReceiptManagement::showReceiptByYear(){
    string s1, s2;
    cout << "- Nhap nam bat dau: ";
    cin >> s1;
    cout << "- Nhap nam ket thuc: ";
    cin >> s2;
    showReceiptByYear1(s1, s2);
}
void ReceiptManagement::showOrderHistory(const string &CSDT){
    int c = 0;
    for (int i = 0; i < Count; ++i){
        if (this -> List[i].Customer::SDT == CSDT) {
            List[i].showReceipt(); 
            c++;
        }
    }
    cout << "- Co tong cong " << c << " giao dich" << endl;
}

void ReceiptManagement::showReceiptByStaff(const string& ID){
    int c = 0;
    for (int i = 0; i < Count; ++i){
        if (this -> List[i].Staff::StaffID == ID) {
            List[i].showReceipt(); 
            c++;
        }
    }
    cout << "- Co tong cong " << c << " giao dich" << endl;
}

void ReceiptManagement::showAllUnpaidReceipt(){
    cout << "- Nhung hoa don chua thanh toan la:\n";
    for (int i = 0; i < Count; ++i) {
        if (!List[i].status) List[i].showReceipt();
    }
    cout << endl;
}

int ReceiptManagement::findReceiptByID(const string &ID){
    for (int i = 0; i < Count; i++){
        if (List[i].ReceiptID == ID) return i;
    }
    return -1;
}

void ReceiptManagement::deleteOODReceipt(MedicineManagement &MD){
    string cd = getCurrentDate().substr(0, 10);
    int c = 0;
    for (int i = 0; i < Count; i++) {
        if (!List[i].status && tinhSoNgay(List[i].DateOfTran.substr(0, 10), cd) > 10){
            for (int j = 0; j < List[i].CountMedicine; ++j) {
                MD.List[MD.CheckExisted(List[i].List[j].ID) - 1].Left += List[i].Number[j];
            }
            List[i].status = 2;
            c++;
        }
    }
    Receipt tr[Count - c];
    int k = 0;
    for (int i = 0; i < Count; i++){
        if (List[i].status !=2 ) tr[k++] = List[i];
    }
    delete [] List;
    Count -= c;
    this -> List = new Receipt[Count];
    for (int i = 0; i < Count; i++){
        List[i] = tr[i];
    }
}

void ReceiptManagement::removeReceipt(const string &rcid, MedicineManagement& mdList, CustomerManagement& csList){
    int idx = -1;
    for (int i = 0; i < Count; ++i){
        if (List[i].ReceiptID == rcid){
            idx = i;
            break;
        }
    }
    if (idx == -1){
        cout << "- Khong tim thay hoa don voi id " << rcid << endl;
    }
    else{
        if (!List[idx].status){
            for (int i=0; i<List[idx].CountMedicine; i++){
                mdList.List[mdList.CheckExisted(List[idx].List[i].ID)-1].Left += List[idx].Number[i];
            }
        }
        else {
            cout << "Thuoc co duoc hoan lai khong?\n";
            cout << "1. Co.\n";
            cout << "2. Khong.\n";
            char temp;
            cin >> temp;
            getenter;
            if (temp == '1'){
                csList.DeductPoint(List[idx].Total*0.05/100,csList.FindCustomerByPhoneNum(List[idx].Customer::SDT));
                for (int i=0; i<List[idx].CountMedicine; i++){
                    mdList.List[mdList.CheckExisted(List[idx].List[i].ID)-1].Left += List[idx].Number[i];
                }
            }
        }
        Receipt tr[Count - 1];
        int k = 0;
        for (int i = 0; i < Count; ++i){
            if (i != idx) tr[k++] = List[i];
        }
        delete [] List;
        Count -= 1;
        List = new Receipt[Count];
        for (int i = 0; i < Count; ++i) List[i] = tr[i];
    }
}