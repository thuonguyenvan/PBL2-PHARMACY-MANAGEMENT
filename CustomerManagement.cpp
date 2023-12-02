using namespace std;
#include "CustomerManagement.h"
#include "Customer.cpp"
#include "Person.cpp"

void CustomerManagement::readCustomerFromFile(ifstream &File){
    this->readCountFromFile(File);
    this -> List = new Customer[this -> Count];
    for (int i = 0; i < Count; ++ i){
        List[i].readCustomerFromFile(File);
    }
}

void CustomerManagement::ViewAllCustomers(){
    cout << left << setw(25) << "Ho va ten"  << left << setw(15) << "So dien thoai" << left << setw(12)<< "Ngay sinh" << left << setw(14) 
    << "CCCD" << left << setw(40) << "Dia chi" << left << setw(3) << "Diem tich luy" << endl;
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