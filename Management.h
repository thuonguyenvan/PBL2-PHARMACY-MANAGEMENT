#pragma once
using namespace std;
#include "Customer.cpp"
template <class T>
class Management
{
private:
    T *List;
    int Count = 0;
public:
    Management();
    ~Management();
    void Add();
    void View();
   // void Edit(const string &);
    void Remove(const string &);
    bool CheckExisted(const string &);
};
