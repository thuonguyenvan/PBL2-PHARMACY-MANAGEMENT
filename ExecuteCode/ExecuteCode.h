#include <iostream>
#include "..\CustomerManagement.cpp"
#include "..\StaffManagement.cpp"
#include "..\MedicineManagement.cpp"
#include "..\ReceiptManagement.cpp"
using namespace std;

class ExecuteCode{
    public:
        void static Run(MedicineManagement &M, CustomerManagement &C, StaffManagement &S, ReceiptManagement& R);
        char static Show();
};