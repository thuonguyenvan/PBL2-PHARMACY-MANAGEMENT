#include "LoginForm.cpp"
using namespace std;

class StaffLogin: public LoginForm{
    public:
        void Run(CustomerManagement &csList, StaffManagement &stList, MedicineManagement &mdList);
        char Show();
};