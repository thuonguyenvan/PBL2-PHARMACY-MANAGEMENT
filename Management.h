#pragma once
using namespace std;
#include "./Customer/Customer.cpp"
template <class T>
class Management
{
protected:
    T *List;
    int Count;
public:
    friend class ifstream;
    Management();
    ~Management();
    void Add();
    void View();
    void Remove(const string &);
    int CheckExisted(const string &);
    void readCountFromFile(ifstream &);
    void Edit(const string &);
    int returnCount();
    string returnEmail(const int&);
    string returnPassword(const int&);
    string returnName(const int&);
    T returnInfo(const int&);
};
