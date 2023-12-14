#include "LoginForm.cpp"
using namespace std;

class StaffLogin: public LoginForm{
    public:
        void Run(StaffManagement &stList, CustomerManagement &csList, MedicineManagement &mdList);
        char Show();
};