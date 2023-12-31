#include <iostream>
#include "../Medicine/MedicineManagement.cpp"
#include "../Receipt/Receipt.cpp"
using namespace std;

class WorkMenu{
    protected:
        int static count;
    public:
        WorkMenu();
        ~WorkMenu();
        void Show();
        void ViewMedsOptionMenu();
        void ViewMedsFindMenu();
        template<typename T>
        int SearchByName(T&);
        template<typename T>
        bool SearchByFunction(T&);
        bool leftEmpty = false;
        bool exitPressed = false;
        int ChooseMedicineAmount();
        string ChooseMedicineID();
        void BuyMedicine(MedicineManagement&, Receipt&);
        template<typename T>
        void EditInformation(T&, int&);
};