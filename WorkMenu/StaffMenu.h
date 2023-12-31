#include "WorkMenu.cpp"
#include "../Staff/StaffManagement.cpp"
using namespace std;

class StaffMenu: public WorkMenu{
    public:
        char Show(const int&);
        void Run(StaffManagement&, const int&, MedicineManagement&, CustomerManagement&, ReceiptManagement&);
        int checkAuthentication(StaffManagement&, const int&);
        void ManagementMenu(StaffManagement&, MedicineManagement &, CustomerManagement&, int);
        void ReceiptMenu(CustomerManagement&, Receipt&, ReceiptManagement&);
        void ReceiptManagementMenu(ReceiptManagement&, const int&, CustomerManagement&, MedicineManagement&, Staff&);
};