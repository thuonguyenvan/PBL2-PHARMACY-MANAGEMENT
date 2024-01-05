#include "LoginForm.cpp"
using namespace std;

class GuestLogin: public LoginForm{
    public:
        char Show();
        void Run(CustomerManagement &, StaffManagement &, MedicineManagement &, ReceiptManagement&);
};