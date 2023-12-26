#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement
{
public:
    Receipt *List;
    int Count;
public:
    ReceiptManagement();
    ~ReceiptManagement();
    string chooseMedicine();
    void addNewReceipt(const Receipt &);
    void readReceiptFromFile(ifstream &);
    void updateReceiptFile();

    void showReceiptByDate1(const string &, const string &);
    void showReceiptByMonth1(const string &, const string &);
    void showReceiptByYear1(const string &, const string &);
    void showReceiptByDate();
    void showReceiptByMonth();
    void showReceiptByYear();

    void showOrderHistory(const string &); //truyen vao sdt cua khach hang hay cai gi do sua lai sau
    void readCountFromFile(ifstream &in)
    {
        in >> Count;
        string t; 
        getline(in, t, '\n');
    }
    void showAllUnpaidReceipt();
    int findReceiptByID(const string &); //tra ve vi tri cua hoa don
    void deleteOODReceipt(MedicineManagement &); // truyen MD vao de tra lai thuoc , ham xoa hoa don qua han
    void removeReceipt(const string &);
};

