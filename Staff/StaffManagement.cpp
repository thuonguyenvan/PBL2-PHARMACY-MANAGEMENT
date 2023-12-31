#pragma once
using namespace std;
#include "StaffManagement.h"
#include "Staff.cpp"
#include "../Person.cpp"

void StaffManagement::readStaffFromFile(ifstream &File){
    this->readCountFromFile(File);
    this -> List = new Staff[this -> Count];
    for (int i = 0; i < Count; ++ i){
        List[i].readStaffFromFile(File);
    }
}

void StaffManagement::ViewAllStaffs(){
    cout << left << setw(7) << "ID" << left << setw(25) << "Ho va ten"  << left << setw(15) << "So dien thoai" << left << setw(12)<< "Ngay sinh" << left << setw(14) 
    << "CCCD" << left << setw(40) << "Dia chi" << left << setw(10) << "Luong" << endl;
    this -> View();
}
void StaffManagement::updateStaffFile(){
    ofstream File("./Data/Staff.txt");
    File << Count << "\n";
    for (int i = 0; i < Count; ++i){
        File << List[i].StaffID << "|";
        File << List[i].Name << "|";
        File << List[i].SDT << "|";
        File << List[i].DateOfBirth << "|";
        File << List[i].CCCD << "|";
        File << List[i].Address << "|";
        File << List[i].Email << "|";
        File << List[i].Password << "|";
        File << List[i].Salary<< "\n";
    }
    File.close();
}

void StaffManagement::addNewStaff(){
    this->Add();
}

void StaffManagement::removeStaff(const string &E){
    this->Remove(E);
}

void StaffManagement::editStaff(const string &E){
    this->Edit(E);
}

string StaffManagement::returnID(const int& index){
    return this->List[index].StaffID;
}
/*
thuongnguyenvan2209@gmail.com
Nguyen Van Thuong
0766739336
22/09/2004
049204010868
1 Le Duan, Hai Chau, Da Nang
*/