#pragma once
#include<iostream>
using namespace std;
#include "../Person.h"
class CustomerManagement;
class Customer :  public Person
{
protected:
    int Point = 0;
public:
    friend class CustomerManagement;
    Customer();
    Customer(const Customer&);
    ~Customer();
    friend ostream& operator<<(ostream &, const Customer&);
    void readCustomerFromFile(ifstream &);
    int returnPoint();
};

/*
- người mua:
	+ thông tin cá nhân
	+ tra cứu thuốc
	+ thêm tài khoản
	+ tích điểm
	+ góp ý
*/