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
    int *Number;
    long long int Total;
public:
    friend class ReceiptManagement;
    Receipt();
    Receipt(const Customer&, const Staff&);
    ~Receipt();
    void addNewMedicine(const Medicine&, const int &);
    void showReceipt();
    void readReceiptFromFile(ifstream &);
};