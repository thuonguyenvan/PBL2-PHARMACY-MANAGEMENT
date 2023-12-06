#pragma once
using namespace std;
#include "Management.cpp"
#include "Medicine.cpp"
class ReceptManagement;
class  MedicineManagement: public Management<Medicine>
{
public:
    friend class ReceptManagement;
    void readMedicineFromFile(ifstream &);
    void ViewAllMedicines();
    void addNewMedicine(const string = "!");
    void removeMedicine(const string &);
    void editMedicine(const string &);
    void increaseAmount(const string &);
    int CheckExisted(const string&);
    Medicine pickMedicine(const string&);
    string returnMedicineName(const int&);
    string returnMedicineFunction(const int&);
    void returnMedicineInfo(const int&);
    int returnMedicineAmount(const int&);
};