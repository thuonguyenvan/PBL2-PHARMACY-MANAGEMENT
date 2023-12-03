#pragma once
#include<string>
#include<iostream>
#include "Customer.cpp"
#include "Staff.h"
#include "Medicine.cpp"
using namespace std;
class ReceiptManagement;
class Receipt: public Customer, public Staff
{
private:
    string ReceiptID;
    string DateOfTran;
    int CountMedicine;
    Medicine *List;
public:
    friend class ReceiptManagement;
    Receipt();
    Receipt(const Customer&, const Staff&);
    ~Receipt();
};