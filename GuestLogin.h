#include "LoginForm.cpp"
#include "CustomerManagement.cpp"
#include "StaffManagement.cpp"
#include "MedicineManagement.cpp"
using namespace std;

class GuestLogin: public LoginForm{
    public:
        char Show();
        void Run(CustomerManagement &, StaffManagement &, MedicineManagement &);
};