#pragma once
using namespace std;
#include "Management.cpp"
class MedicineManagement //: public Management<Medicine>
{
public:
    void AddNewMedicine();
    void AddNumberOfMedicine(const string &ID);
};

/*
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

*/