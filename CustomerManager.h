#pragma once
using namespace std;
#include "Customer.h"

class CustomerManager
{
private:
    Customer *List;
    static int numberOfCustomer;
public:
    CustomerManager();
    ~CustomerManager();
    void AddCustomer(const Customer&);
    void RemoveCustomer(int ID);
    void EditCustomer(int ID);
    friend ostream& operator << (ostream&, const Customer &);
    
};