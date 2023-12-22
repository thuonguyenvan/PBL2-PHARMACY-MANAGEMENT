#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement: public MedicineManagement
{
private:
    Receipt *List;
    int Count;
public:
    ReceiptManagement(const MedicineManagement &);
    ~ReceiptManagement();
    string chooseMedicine();
    void addNewReceipt(const Customer&, const Staff&, const MedicineManagement&);
    void readReceiptFromFile(ifstream &);
    void updateReceiptFile();
   // void removeReceipt(const string &);
};

