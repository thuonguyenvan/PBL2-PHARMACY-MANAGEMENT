#include "WorkMenu.cpp"
using namespace std;

class GuestMenu: public WorkMenu{
    public:
        char Show(const int&);
        void GetCustomerInfo(Customer&, CustomerManagement&, int&);
        void Run(CustomerManagement&, const int&);
};