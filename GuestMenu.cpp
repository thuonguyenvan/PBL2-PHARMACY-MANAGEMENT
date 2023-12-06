#include "GuestMenu.h"
#include "MedicineManagement.cpp"
using namespace std;

char GuestMenu::Show(const int& index){
    cout << GuestMenu::count++ << ". Xem va mua thuoc.\n";
    cout << GuestMenu::count++ << ". Xem gio hang va thanh toan.\n";
    if (index != -1) cout << GuestMenu::count++ << ". Xem thong tin ca nhan.\n";
    WorkMenu::Show();
    GuestMenu::count = 1;
    char temp;
    cin >> temp;
    return temp;
}

void GuestMenu::Run(CustomerManagement& csList, const int& index){
    MedicineManagement mdList;
    ifstream FileMedicine("./Data/Medicine.txt");
    mdList.readMedicineFromFile(FileMedicine);
    FileMedicine.close();
    retry:    system("cls");
        char temp = this->Show(index);
        switch(temp){
            case '1':{      // Xem thuoc
                system("cls");
                GuestMenu::ViewMedsOptionMenu();
                cin >> temp;
                while(temp<'1' || temp>'3'){
                    cout << "Lua chon khong phu hop!\n";
                    system("pause");
                    system("cls");
                    GuestMenu::ViewMedsOptionMenu();
                    cin >> temp;
                }
                switch(temp){
                    case '1':{
                        bool breaker = false;
                        do{
                            mdList.ViewAllMedicines();
                            string ID = this->ChooseMedicineID();
                            if (this->leftEmpty){
                                this->leftEmpty = false;
                                goto retry;
                            }
                            int medIndex = mdList.CheckExisted(ID);
                            if (!medIndex){
                                cout << "ID ban da chon khong phu hop!\n";
                            //    goto retryBuyAll;
                            }
                            else{
                                bool breaker1 = false;
                                do{
                                    int amount = this->ChooseMedicineAmount();
                                    if (this->leftEmpty){
                                        this->leftEmpty = false;
                                        goto retry;
                                    }
                                    if (amount<1 || amount>mdList.returnMedicineAmount(medIndex-1)){
                                        cout << "So luong khong phu hop!\n";
                                    //    goto retryAmount;
                                    }
                                    else{
                                        cout << "Chon mua thanh cong.\n";
                                        cout << "Ban co muon mua tiep khong?\n";
                                        cout << "1. Tiep tuc mua hang.\n";
                                        cout << "2. Quay lai.\n";
                                        cin >> temp;
                                        while(temp<'1' || temp>'2'){
                                            cout << "Lua chon khong phu hop.\n";
                                            system("pause");
                                            system("cls");
                                            cout << "Chon mua thanh cong.\n";
                                            cout << "Ban co muon mua tiep khong?\n";
                                            cout << "1. Tiep tuc mua hang.\n";
                                            cout << "2. Quay lai.\n";
                                            cin >> temp;
                                        }
                                        switch(temp){
                                            case '1':{
                                                breaker1 = true;
                                                break;
                                            }
                                            case '2':{
                                                goto retry;
                                                break;
                                            }
                                        }
                                    }
                                } while (!breaker1);
                            }
                        } while (!breaker);
                        break;
                    }
                    case '2':{
                        system("cls");
                        GuestMenu::ViewMedsFindMenu();
                        cin >> temp;
                        while(temp<'1' || temp>'3'){
                            cout << "Lua chon khong phu hop.\n";
                            system("pause");
                            system("cls");
                            GuestMenu::ViewMedsFindMenu();
                            cin >> temp;
                        }
                        switch(temp){
                            case '1':{
                                retryFindName: int index = this->SearchByName(mdList);
                                if (this->leftEmpty){           // kiem tra trong de quay lai
                                    this->leftEmpty = false;
                                    system("cls");
                                    goto retry;
                                }
                                if (index != (-1)){     // tim thay thuoc
                                    system("cls");
                                    mdList.returnInfo(index);
                                    int amount = this->ChooseMedicineAmount();
                                    if (this->leftEmpty){
                                        this->leftEmpty = false;
                                        goto retry;
                                    }
                                    else{
                                        cout << "Chon mua thanh cong.\n";
                                        goto retry;
                                    }
                                }
                                else{       // khong tim thay
                                    system("pause");
                                    goto retryFindName;
                                }
                                break;
                            }
                            case '2':{
                                retryFindFunction:
                                bool breaker = false;
                                do{
                                    bool found = this->SearchByFunction(mdList);
                                    if (this->leftEmpty){           // kiem tra trong de quay lai
                                        this->leftEmpty = false;
                                        system("cls");
                                        goto retry;
                                    }
                                    if (found){
                                        bool breaker1 = false;
                                        do{
                                            string ID = this->ChooseMedicineID();
                                            if (this->leftEmpty){
                                                this->leftEmpty = false;
                                                goto retry;
                                            }
                                            int medIndex = mdList.CheckExisted(ID);
                                            if (!medIndex){
                                                cout << "ID ban da chon khong phu hop!\n";
                                            }
                                            else{
                                                bool breaker2 = false;
                                                do{
                                                    int amount = this->ChooseMedicineAmount();
                                                    if (this->leftEmpty){
                                                        this->leftEmpty = false;
                                                        goto retry;
                                                    }
                                                    if (amount<1 || amount>mdList.returnMedicineAmount(medIndex-1)){
                                                        cout << "So luong khong phu hop!\n";
                                                    }
                                                    else{
                                                        cout << "Chon mua thanh cong.\n";
                                                        cout << "Ban co muon mua tiep khong?\n";
                                                        cout << "1. Tiep tuc mua hang.\n";
                                                        cout << "2. Quay lai.\n";
                                                        cin >> temp;
                                                        while(temp<'1' || temp>'2'){
                                                            cout << "Lua chon khong phu hop.\n";
                                                            system("pause");
                                                            system("cls");
                                                            cout << "Chon mua thanh cong.\n";
                                                            cout << "Ban co muon mua tiep khong?\n";
                                                            cout << "1. Tiep tuc mua hang.\n";
                                                            cout << "2. Quay lai.\n";
                                                            cin >> temp;
                                                        }
                                                        switch(temp){
                                                            case '1':{
                                                                breaker1 = true;
                                                                breaker2 = true;
                                                                break;
                                                            }
                                                            case '2':{
                                                                goto retry;
                                                                break;
                                                            }
                                                        }
                                                    }
                                                } while (!breaker2);
                                            }
                                        } while (!breaker1);
                                    }
                                    break;
                                } while (!breaker);
                            }
                            case '3':{
                                goto retry;
                                break;
                            }
                        }
                    }
                    case '3':{
                        goto retry;
                        break;
                    }
                }
            }
            case '2':{      // Xem gio hang
                system("cls");
                cout << "Gio hang";
                break;
            }
            case '3':{      // tro lai
                system("cls");
                if (index!=-1){
                    csList.returnInfo(index);
                }
                else
                    this->backPressed = true;
                break;
            }
            case '4':{      // thoat
                if (index!=-1) this->backPressed = true;
                else
                    exit(0);
                break;
            }
            case '5':{
                if (index!=-1) exit(0);
            }
            default:{
                cout << "Lua chon khong hop le!\n";
                system("pause");
                system("cls");
                goto retry;
            }
        }
}