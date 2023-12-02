#pragma once
using namespace std;
#include "Management.cpp"
#include "Medicine.cpp"
class  MedicineManagement: public Management< Medicine>
{
public:
    void readMedicineFromFile(ifstream &);
    void ViewAllMedicines();
};