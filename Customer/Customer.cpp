#pragma once
#include "Customer.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "../extraFunction.cpp"
Customer::Customer()
{
    Point = 0;
}

Customer::Customer(const Customer& C)
    :Person(C), Point(C.Point)
{}

Customer::~Customer()
{}

ostream &operator << (ostream &out, const Customer &P) 
{
    out << left << setw(25) << P.Name  << left << setw(15) << P.SDT << left << setw(12)<< P.DateOfBirth << left << setw(14) 
    << P.CCCD << left << setw(40) << P.Address << "Diem tich luy: " << left << setw(3) << P.Point << left << setw(25) << P.Email << endl;
    return out;
}
void Customer :: readCustomerFromFile (ifstream &in) 
{
    getline(in, Name, '|');
    getline(in,SDT,'|');
    getline(in,DateOfBirth,'|');
    getline(in,CCCD,'|');
    getline(in, Address, '|');
    getline(in, Email, '|');
    getline(in, Password, '|');
    in >> Point;
    string t;
    getline(in, t, '\n');
}

int Customer::returnPoint(){
    return Point;
}