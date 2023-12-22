#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement: public Management<Receipt>
{
private:
    Receipt *List;
    int Count;
public:
    ReceiptManagement();
    ~ReceiptManagement();
    string chooseMedicine();
    void addNewReceipt(const Customer&, const Staff&, MedicineManagement&);
    void readReceiptFromFile(ifstream &);
    void updateReceiptFile();

    void showReceiptByDate(const string &, const string &);
    void showReceiptByMonth(const string &, const string &);
    void showReceiptByYear(const string &, const string &);
   // void removeReceipt(const string &);
};

