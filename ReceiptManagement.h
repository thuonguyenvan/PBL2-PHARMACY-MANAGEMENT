<<<<<<< HEAD
#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement: public MedicineManagement
{
private:
    Receipt *List;
    int Count;
public:
    ReceiptManagement();
    ~ReceiptManagement();
    string chooseMedicine();
    void addNewReceipt(const Customer&, const Staff&, const MedicineManagement&);
   // void removeReceipt(const string &);
};

=======
#pragma once
using namespace std;
#include "Receipt.h"
class ReceiptManagement: public MedicineManagement
{
private:
    Receipt *List;
    int Count;
public:
    ReceiptManagement();
    ~ReceiptManagement();
    string chooseMedicine();
    void addNewReceipt(const Customer&, const Staff&, const MedicineManagement&);
   // void removeReceipt(const string &);
};

>>>>>>> efacc985dacfb5baa6091624f41eb57542a778ce
