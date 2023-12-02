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
    cout << left << setw(7) << "ID" << left << setw(25) << "Ho va ten"  << left << setw(15) << "So dien thoai" << left << setw(12)<< "Ngay sinh" << left << setw(14) 
    << "CCCD" << left << setw(40) << "Dia chi" << left << setw(10) << "Luong" << endl;
    this -> View();
}
/*
thuongnguyenvan2209@gmail.com
Nguyen Van Thuong
0766739336
22/09/2004
049204010868
1 Le Duan, Hai Chau, Da Nang
*/