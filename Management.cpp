#include "Management.h"
#include <iostream>
#include <iomanip>
#include <fstream>
#include "extraFunction.cpp"
#define getenter fflush(stdin);
// quan ly nhan vien, khach hang, quan ly, thuoc

template <class T>
Management<T>::Management()
{}

template <class T>
Management<T>::~Management()
{
    delete[] List;
}


template <class T>
bool Management<T>::CheckExisted(const string &Email)
{  
    for (int i = 0; i < Count; ++i){
        if (this -> List[i].Email == Email) return true;
    }
    return false;
}

template <class T>
void Management<T>::Add()
{  
    string Email;
    cout << "Nhap Email: ";
    cin >> Email;
    if (CheckExisted(Email)) {
        cout << "\nEmail nay da duoc dung. \n";
    }
    else {
        Count++;
        T tmp;
        tmp.Email = Email;
        cin >> tmp;
        T newT[Count - 1];
        for (int i = 0; i < Count - 1; ++ i){
            newT[i] = this -> List[i];
        }
        delete[] this -> List;
        this -> List = new T[Count];
        this -> List[Count - 1] = tmp;
        for (int i = 0; i < Count - 1; ++ i){
            this -> List[i] = newT[i];
        }
        // cho nay se them ham update tac gia vao file
        cout << "/Da them thanh cong nguoi dung. ";
    }
}

template <class T>
void Management<T>::Remove(const string &Email)
{  
    if (!CheckExisted(Email)) {
        cout << "\nNguoi dung khong ton tai. \n";
    }
    else {
        Count--;
        T tmp[Count];
        int p = 0;
        for (int i = 0; i < Count + 1; ++ i){
            if (this -> List[i].Email != Email)  tmp[p++] = this ->List[i];
        }
        delete[] this -> List;
        this -> List = new T[Count];
        for (int i = 0; i < Count - 1; ++ i){
            this -> List[i] = tmp[i];
        }
        // cho nay se them ham update tac gia vao file
        cout << "/Da xoa thanh cong nguoi dung. ";
    }
}

template <class T>
void Management<T>::View()
{  
    for (int i = 0; i < Count; ++i) {
        cout << this -> List[i] << endl;
    }
}






// lop quan ly nhan vien:






