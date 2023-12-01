#pragma once
using namespace std;
#include "Management.cpp"
#include "Customer.cpp"
#include "Person.cpp"

int main()
{
    Management<Customer> CustomerList;
    CustomerList.Add();
    CustomerList.View();
    return 0;
}