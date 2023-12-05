#include "WorkMenu.cpp"
using namespace std;

class GuestMenu: public WorkMenu{
    public:
        char Show(const int&);
        void Run(const int&);
};