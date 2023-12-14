#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement: public MedicineManagement
{
private:
    Receipt *List;
    int Count;
public:
    ReceiptManagement();
    ~ReceiptManagement();
    string chooseMedicine();
    void addNewReceipt(const Customer&, const Staff&, const MedicineManagement&);
   // void removeReceipt(const string &);
};

