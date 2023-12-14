<<<<<<< HEAD
#include "LoginForm.cpp"
#include "CustomerManagement.cpp"
#include "StaffManagement.cpp"
#include "MedicineManagement.cpp"
using namespace std;

class GuestLogin: public LoginForm{
    public:
        char Show();
        void Run(CustomerManagement &, StaffManagement &, MedicineManagement &);
=======
#include "LoginForm.cpp"
using namespace std;

class GuestLogin: public LoginForm{
    public:
        char Show();
        void Run();
>>>>>>> efacc985dacfb5baa6091624f41eb57542a778ce
};