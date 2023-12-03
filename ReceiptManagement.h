#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement
{
private:
    Receipt *List;
    int Count;
public:
    ReceiptManagement();
    ~ReceiptManagement();
    void addNewReceipt();
    void removeReceipt(const string &);
};

