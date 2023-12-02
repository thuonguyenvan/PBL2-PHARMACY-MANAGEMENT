#pragma once
using namespace std;
#include "Management.cpp"
#include "Medicine.cpp"
class  MedicineManagement: public Management< Medicine>
{
public:
    void readMedicineFromFile(ifstream &);
    void ViewAllMedicines();
    void addNewMedicine(const string = "!");
    void removeMedicine(const string &);
    void editMedicine(const string &);
    void increaseAmount(const string &);
    int CheckExisted(const string&);
};