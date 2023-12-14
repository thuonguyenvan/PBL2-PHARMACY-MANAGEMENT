#pragma once
#include<iostream>
using namespace std;
#include "Person.h"
class CustomerManagement;
class Customer :  public Person
{
protected:
    int Point = 0;
public:
    friend CustomerManagement;
    Customer();
    Customer(const Customer&);
    ~Customer();
    void AccumPoint();
    friend ostream& operator<<(ostream &, const Customer&);
    void readCustomerFromFile(ifstream &);
};

/*
- người mua:
	+ thông tin cá nhân
	+ tra cứu thuốc
	+ thêm tài khoản
	+ tích điểm
	+ góp ý
*/