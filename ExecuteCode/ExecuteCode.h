#include <iostream>
#include "../Customer/CustomerManagement.cpp"
#include "../Staff/StaffManagement.cpp"
#include "../Medicine/MedicineManagement.cpp"
#include "../Receipt/ReceiptManagement.cpp"
using namespace std;

class ExecuteCode{
    public:
        void static Run(MedicineManagement &M, CustomerManagement &C, StaffManagement &S, ReceiptManagement& R);
        char static Show();
};