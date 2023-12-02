#pragma once
#include <string>
#include <iostream>
#include "Person.h"
using  namespace std;
class Medicine
{
private:
    string ID;
    string Name;
    string NSX;
    string HSD;
    string Uses;
    string Guide;
    int Price;
    int Left;
    string SideEffects;
public:
    Medicine();
    Medicine(const Medicine &);
    ~Medicine();
    void WarningLeft();
    void WarningHSD();
    friend Person;
    friend ostream& operator<<(ostream&, const Medicine&);
    friend istream& operator>>(istream&, Medicine&);
    void readMedicineFromFile (ifstream &);
    void EditName();
    void EditNSX();
    void EditHSD();
    void EditUses();
    void EditGuide();
    void EditPrice();
    void EditSideEffects();
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