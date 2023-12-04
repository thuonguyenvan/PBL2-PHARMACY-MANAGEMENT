#include <iostream>
using namespace std;

class WorkMenu{
    protected:
        int static count;
    public:
        void Show();
        void DisplayInfo(string&);
        void DisplayAccountList();
        void DisplayReceipt();
        bool backPressed = false;
};