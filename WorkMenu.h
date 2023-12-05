#include <iostream>
using namespace std;

class WorkMenu{
    protected:
        int static count;
    public:
        void Show();
        void ViewMedsOptionMenu();
        void ViewMedsFindMenu();
        template<typename T>
        int SearchByName(T&);
        template<typename T>
        bool SearchByFunction(T&);
        void DisplayInfo(string&);
        void DisplayAccountList();
        void DisplayReceipt();
        bool backPressed = false;
        bool leftEmpty = false;
};