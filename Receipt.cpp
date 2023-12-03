#pragma once
#include "Receipt.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"

Receipt::Receipt()
{}

Receipt::~Receipt()
{
    delete []List;
}
Receipt::Receipt(const Customer& C, const Staff& S)
    :Customer(C), StaffID(S.StaffID), StaffName(S.Name), DateOfTran(getCurrentDate()), CountMedicine(0)
{}