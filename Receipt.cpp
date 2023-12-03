#pragma once
#include "Receipt.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"

Receipt::Receipt()
{
    CountMedicine = 0;
    Customer::Name = "";
    Customer::SDT = "";
    Customer::CCCD = "";
    StaffID = "";
    Staff::Name = "";
    
}

Receipt::~Receipt()
{
    delete []List;
}
Receipt::Receipt(const Customer& C, const Staff& S)
    :Customer(C), Staff(S), DateOfTran(getCurrentDate()), CountMedicine(0)
{}