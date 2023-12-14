<<<<<<< HEAD
#include "LoginForm.cpp"
using namespace std;

class StaffLogin: public LoginForm{
    public:
        void Run(CustomerManagement &csList, StaffManagement &stList, MedicineManagement &mdList);
        char Show();
=======
#include "LoginForm.cpp"
using namespace std;

class StaffLogin: public LoginForm{
    public:
        void Run();
        char Show();
>>>>>>> efacc985dacfb5baa6091624f41eb57542a778ce
};