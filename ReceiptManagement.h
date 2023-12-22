#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement: public Management<Receipt>
{
public:
    Receipt *List;
    int Count;
public:
    ReceiptManagement();
    ~ReceiptManagement();
    string chooseMedicine();
    void addNewReceipt(const Customer&, const Staff&, MedicineManagement&);
    void readReceiptFromFile(ifstream &);
    void updateReceiptFile();

    void showReceiptByDate1(const string &, const string &);
    void showReceiptByMonth1(const string &, const string &);
    void showReceiptByYear1(const string &, const string &);
    void showReceiptByDate();
    void showReceiptByMonth();
    void showReceiptByYear();
   // void removeReceipt(const string &);
};

