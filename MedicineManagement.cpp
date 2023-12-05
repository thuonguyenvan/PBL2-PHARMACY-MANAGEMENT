using namespace std;
#include "MedicineManagement.h"
#include "Medicine.cpp"
#include "Person.cpp"

void MedicineManagement::readMedicineFromFile(ifstream &File){
    this->readCountFromFile(File);
    this -> List = new Medicine[this -> Count];
    for (int i = 0; i < Count; ++ i){
        List[i].readMedicineFromFile(File);
    }
}

void MedicineManagement::ViewAllMedicines(){
    cout << left << setw(7) << "ID" << left << setw(15) << "Ten thuoc"  << left << setw(13) << "Ngay san xuat" << left << setw(13)<< "Han su dung" << left << setw(20) 
    << "Cong dung" << left << setw(40) << "Huong dan su dung" << left << setw(10) << "Tac dung phu" << left << setw(10) << "So luong con" << left << setw(10) << "Gia" <<  endl;
    this -> View();
}
int MedicineManagement::CheckExisted(const string &ID){
    for (int i = 0; i < Count;  ++i) if (List[i].ID == ID) return i + 1;
    return 0;
}
void MedicineManagement::addNewMedicine(const string tid){
    string s;
    if (tid == "!"){
        cout << "- Nhap ID thuoc: ";
        cin >> s;
        int pos = CheckExisted(s);
        if (pos){
            cout << "- Thuoc da ton tai, ban co muon tang so luong thuoc khong: ";
            cout << "        1. Tang so luong          2. Thoat";
            int option;
            cin >> option;
            if (option == 1){
                increaseAmount(s);
            }
            else return;
        }
    }
    else s = tid;
    Medicine tmp;
    tmp.ID = s;
    cin >> tmp;
    Count++;
    if (Count == 1){
        this -> List = new Medicine[1];
        List[0] = tmp;
    }
    else {
        Medicine *M =  new Medicine[Count - 1];
        for (int i = 0; i < Count - 1; ++i){
            M[i] = List[i];
        }
        delete [] this -> List;
        this -> List = new Medicine[Count];
        List[Count - 1] = tmp;
        for (int i = 0; i < Count - 1; ++i){
            List[i] = M[i];
        }
    }
    cout << "\n- Da them thanh cong";
}

void MedicineManagement::removeMedicine(const string &ID){
    if (!CheckExisted(ID)) cout << "- Thuoc khong ton tai";
    else {
        this -> Count--;
        Medicine *tmp = new Medicine[Count]; 
        int p = 0;
        for (int i = 0; i < Count + 1; ++ i){
            if (this -> List[i].ID != ID)  tmp[p++] = this ->List[i];
        }
        delete[] this -> List;
        this -> List = new Medicine[Count];
        for (int i = 0; i < Count - 1; ++ i){
            this -> List[i] = tmp[i];
        }
        // cho nay se them ham update tac gia vao file
        cout << "/nDa xoa thanh cong thuoc. ";
    }
}

void MedicineManagement::editMedicine(const string &ID){
    int p = CheckExisted(ID);
    if (!p) cout << "- Thuoc khong ton tai";
    else {
        List[p - 1].Edit();
    }
}

void MedicineManagement::increaseAmount(const string &ID){
    int p = CheckExisted(ID);
    if (!p) cout << "- Thuoc khong ton tai";
    else {
        cout << "- Nhap so luong thuoc muon nhap them: ";
        int t;
        cin >> t;
        List[p - 1].Left += t;
        cout << "- Da them thanh cong. ";
    }
}

Medicine MedicineManagement::pickMedicine(const string &ID){
    int p = CheckExisted(ID);
    return List[p-1];
}

string MedicineManagement::returnMedicineName(const int& index){
    return this->List[index].Name;
}

string MedicineManagement::returnMedicineFunction(const int& index){
    return this->List[index].Uses;
}

void MedicineManagement::returnMedicineInfo(const int& index){
    cout << List[index];
}
    
/*
thuongnguyenvan2209@gmail.com
Nguyen Van Thuong
0766739336
22/09/2004
049204010868
1 Le Duan, Hai Chau, Da Nang
*/