#include <iostream>
#include "..\CustomerManagement.cpp"
#include "..\StaffManagement.cpp"
#include "..\MedicineManagement.cpp"
using namespace std;

class ExecuteCode{
    public:
        void static Run(MedicineManagement &M, CustomerManagement &C, StaffManagement &S);
        char static Show();
};