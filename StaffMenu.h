#include "WorkMenu.cpp"
#include "StaffManagement.cpp"
using namespace std;

class StaffMenu: public WorkMenu{
    public:
        char Show(const int&);
        void Run(StaffManagement& stList, const int& index, MedicineManagement &mdList, CustomerManagement &csList);
        int checkAuthentication(StaffManagement&, const int&);
        void ManagementMenu(StaffManagement& stList, MedicineManagement &mdList, CustomerManagement &csList, int check);
};