#pragma once
using namespace std;
#include "../Management.cpp"
#include "Medicine.cpp"
class Receipt;
class ReceiptManagement;
class  MedicineManagement: public Management<Medicine>
{
public:
    friend class Receipt;
    friend class ReceiptManagement;
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
    void updateMedicineFile();
    void increaseLeft(const int&, const long long&);
};