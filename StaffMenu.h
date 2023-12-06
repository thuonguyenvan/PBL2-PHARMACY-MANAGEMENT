#include "WorkMenu.cpp"
#include "StaffManagement.cpp"
using namespace std;

class StaffMenu: public WorkMenu{
    public:
        char Show(const int&);
        void Run(StaffManagement&, const int&);
        int checkAuthentication(StaffManagement&, const int&);
};