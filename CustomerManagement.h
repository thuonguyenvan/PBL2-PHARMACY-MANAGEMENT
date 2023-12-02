#pragma once
using namespace std;
#include "Management.cpp"

class CustomerManagement: public Management<Customer>
{
public:
    void readCustomerFromFile(ifstream &);
    void ViewAllCustomers();
};