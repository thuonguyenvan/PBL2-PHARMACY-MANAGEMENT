#pragma once
#include ".\ExecuteCode\ExecuteCode.cpp"
using namespace std;

int main(){

    MedicineManagement mdList;
    ifstream FileMedicine("./Data/Medicine.txt");
    mdList.readMedicineFromFile(FileMedicine);
    FileMedicine.close();

    CustomerManagement csList;
    ifstream FileCustomer("./Data/Customer.txt");
    csList.readCustomerFromFile(FileCustomer);
    FileCustomer.close();

    StaffManagement stList;
    ifstream FileStaff("./Data/Staff.txt");
    stList.readStaffFromFile(FileStaff);
    FileStaff.close();

    ReceiptManagement rcList;
    ifstream FileReceipt("./Data/Receipt.txt");
    rcList.readReceiptFromFile(FileReceipt);
    FileReceipt.close();
    //rcList.List[2].showReceipt();
    ExecuteCode::Run(mdList, csList, stList,rcList);
    //rcList.showReceiptByYear();
    rcList.updateReceiptFile();
    mdList.updateMedicineFile();
    csList.updateCustomerFile();
    stList.updateStaffFile();
}
//thuongnguyenvan2209@gmail.com