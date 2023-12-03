#pragma once
#include<string>
#include<iostream>
#include "Customer.cpp"
#include "Staff.h"
#include "Medicine.cpp"
using namespace std;
class ReceiptManagement;
class Receipt: public Customer
{
private:
    friend class ReceiptManagement;
    string ReceiptID;
    string DateOfTran;
    string StaffID;
    string StaffName;
    int CountMedicine;
    Medicine *List;
public:
    Receipt();
    Receipt(const Customer&, const Staff&);
    ~Receipt();
};