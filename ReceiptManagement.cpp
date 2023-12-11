using namespace std;
#include "ReceiptManagement.h"
#include "Receipt.cpp"
#include "MedicineManagement.cpp"
ReceiptManagement::ReceiptManagement(): MedicineManagement()
{
    List = new Receipt[1];
    Count = 0;
}

ReceiptManagement::~ReceiptManagement()
{
    delete []List;
}

string ReceiptManagement::chooseMedicine(){
    string s;
    cout << "- Nhap ID thuoc muon mua hoac 1 de thoat: ";
    cin >> s;
    return s;
}

void ReceiptManagement::addNewReceipt(const Customer &C, const Staff &S, const MedicineManagement& MM){
    Receipt R(C, S, MM);
    R.DateOfTran = getCurrentDate();
    string t = chooseMedicine();
    while (t != "1"){
        int p = MedicineManagement::CheckExisted(t);
        if (!p) cout << "- Thuoc khong ton tai, vui lonng nhap thuoc khac: ";
        else{
            int l = MedicineManagement::List[p-1].Left;
            cout << "- Nhap so luong ban muon mua (hien con: " << l << "):  ";
            int n;
            cin >> n;
            while (n > l || n < 0) {
                cout << "- So luong khong hop le vui long nhap lai, (hien con: " << l << "):  ";
                cin >> n;
            } 
            MedicineManagement::List[p-1].Left -= n;
            R.addNewMedicine(MedicineManagement::List[p-1], n);
        }
        t = chooseMedicine();
    }
    this -> Count ++;
    if (this -> Count == 1){
        List = new Receipt[1];
        List[0] = R;
    }
    else {
        Receipt tr[Count - 1];
        for (int i = 0; i < Count - 1; i++) tr[i] = List[i];
        delete [] List;
        List = new Receipt[Count];
        List[Count - 1] = R;
        for (int i = 0; i < Count - 1; i++) List[i] = tr[i];
    }
}
