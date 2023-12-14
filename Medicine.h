#pragma once
#include <string>
#include <iostream>
#include "Person.h"
using  namespace std;
class MedicineManagement;
class ReceiptManagement;
class Receipt;
class Medicine
{
private:
    string ID;
    string Name;
    string NSX;
    string HSD;
    string Uses;
    string Guide;
    long long int Price;
    long long int Left;
    string SideEffects;
public:
    friend class Receipt;
    friend class ReceiptManagement;
    friend class MedicineManagement;
    Medicine();
    Medicine(const Medicine &);
    ~Medicine();
    void WarningLeft();
    void WarningHSD();
    friend Person;
    friend ostream& operator<<(ostream&, const Medicine&);
    friend istream& operator>>(istream&, Medicine&);
    void readMedicineFromFile (ifstream &);
    void EditID();
    void EditName();
    void EditNSX();
    void EditHSD();
    void EditUses();
    void EditGuide();
    void EditPrice();
    void EditSideEffects();
    void EditLeft();
    void MenuEdit();
    void Edit();
};

/*
- thuốc:
	+ ngày sx, hsd
	+ công dụng
	+ liều lượng
	+ cách sử dụng
	+ giá tiền
	+ số lượng còn 
	+ tác dụng phụ
	+ thông báo khi thuốc còn ít thì nhập thêm hàng
	+ cảnh báo khi thuốc gần hết hạn sử dụng

*/