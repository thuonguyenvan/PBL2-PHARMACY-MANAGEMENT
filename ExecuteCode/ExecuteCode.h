<<<<<<< HEAD
#include <iostream>
#include "..\CustomerManagement.cpp"
#include "..\StaffManagement.cpp"
#include "..\MedicineManagement.cpp"
using namespace std;

class ExecuteCode{
    public:
        void static Run(MedicineManagement &M, CustomerManagement &C, StaffManagement &S);
        char static Show();
=======
#include <iostream>
using namespace std;

class ExecuteCode{
    public:
        void static Run();
        char static Show();
>>>>>>> efacc985dacfb5baa6091624f41eb57542a778ce
};