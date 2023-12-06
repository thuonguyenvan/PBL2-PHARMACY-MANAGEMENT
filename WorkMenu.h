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
        void DisplayReceipt();
        bool backPressed = false;
        bool leftEmpty = false;
        int ChooseMedicineAmount();
        string ChooseMedicineID();
};