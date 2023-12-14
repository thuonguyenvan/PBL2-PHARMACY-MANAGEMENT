<<<<<<< HEAD
#pragma once
using namespace std;
#include "Management.cpp"
#include "Medicine.cpp"
class Receipt;
class ReceptManagement;
class  MedicineManagement: public Management<Medicine>
{
public:
    friend class Receipt;
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
    void updateMedicineFile();
=======
#pragma once
using namespace std;
#include "Management.cpp"
#include "Medicine.cpp"
class Receipt;
class ReceptManagement;
class  MedicineManagement: public Management<Medicine>
{
public:
    friend class Receipt;
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
>>>>>>> efacc985dacfb5baa6091624f41eb57542a778ce
};