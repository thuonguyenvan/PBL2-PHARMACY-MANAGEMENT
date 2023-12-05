#pragma once
#include "Management.h"
#include <iostream>
#include <iomanip>
#include <fstream>
//#include <limits>
#include "extraFunction.cpp"
//#define getenter cin.ignore(numeric_limits<streamsize>::max(), '\n');
// quan ly nhan vien, khach hang, quan ly, thuoc

template <class T>
Management<T>::Management()
{
    this -> Count = 0;
}

template <class T>
Management<T>::~Management()
{
    delete[] List;
}


template <class T>
int Management<T>::CheckExisted(const string &Email)
{  
    for (int i = 0; i < Count; ++i){
        if (this -> List[i].Email == Email) return i + 1;
    }
    return 0;
}

template <class T>
void Management<T>::Add()
{  
    string Email;
    retry: cout << "De trong de quay lai.\n";
    cout << "Nhap Email: ";
    getenter;
    getline(cin, Email);
    if (Email.empty()) return;
    if (CheckExisted(Email)) {
        cout << "\nEmail nay da duoc dung. \n";
        system("pause");
        system("cls");
        goto retry;
    }
    else {
        this -> Count++;
        T tmp;
        tmp.Email = Email;
        cin >> tmp;
        if (this -> Count == 1){
            this -> List = new T[1];
            this -> List[0] = tmp;
        }
        else {
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
        }
        // cho nay se them ham update tac gia vao file
        cout << "\nDa them thanh cong. \n";
    }
}

template <class T>
void Management<T>::Remove(const string &Email)
{  
    if (!CheckExisted(Email)) {
        cout << "\nNguoi dung khong ton tai. \n";
    }
    else {
        this -> Count--;
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
        cout << "/nDa xoa thanh cong nguoi dung. ";
    }
}

template <class T>
void Management<T>::View()
{  
    for (int i = 0; i < Count; ++i) {
        cout << this -> List[i];
    }
}

template <class T>
void Management<T>::readCountFromFile(ifstream &in)
{
    in >> Count;
    string t; 
    getline(in, t, '\n');
}

template <class T>
void Management<T>::Edit(const string &E){
    int pos = CheckExisted(E);
    if (!pos){
        cout << "- Nguoi dung khong ton tai";
    }
    else{
        List[pos - 1].Edit();
    }
}

template <class T>
int Management<T>::returnCount(){
    return this->Count;
}

template <class T>
string Management<T>::returnEmail(const int& index){
    return this->List[index].Email;
}

template <class T>
string Management<T>::returnPassword(const int& index){
    return this->List[index].Password;
}

template <class T>
string Management<T>::returnName(const int& index){
    return this->List[index].Name;
}
// lop quan ly nhan vien:


