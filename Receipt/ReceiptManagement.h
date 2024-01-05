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
    void showOrderHistory(const string &);
    void showReceiptByStaff(const string&);
    void readCountFromFile(ifstream &in)
    {
        in >> Count;
        string t; 
        getline(in, t, '\n');
    }
    void showAllUnpaidReceipt();
    int findReceiptByID(const string &);
    void deleteOODReceipt(MedicineManagement &);
    void removeReceipt(const string &, MedicineManagement&, CustomerManagement&);
};

