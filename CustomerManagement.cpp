#pragma once
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

void CustomerManagement::updateCustomerFile(){
    ofstream File("./Data/Customer.txt");
    File << Count << "\n";
    for (int i = 0; i < Count; ++i){
        File << List[i].Name << "|";
        File << List[i].SDT << "|";
        File << List[i].DateOfBirth << "|";
        File << List[i].CCCD << "|";
        File << List[i].Address << "|";
        File << List[i].Email << "|";
        File << List[i].Password << "|";
        File << List[i].Point<< "\n";
    }
    File.close();
}

void CustomerManagement::addNewCustomer(){
    this->Add();
}

void CustomerManagement::removeCustomer(const string &E){
    this->Remove(E);
}

void CustomerManagement::editCustomer(const string &E){
    this->Edit(E);
}

/*
void List::List_overwriteNewArticle()
{
    ofstream outFile("../Data/Article.txt", ofstream::trunc);
    outFile << "Ma bao|Ten cong bo|Tac gia|Tap chi|Thoi gian\n";
    for (int i=0; i<Article_count; i++)
    {
        outFile <<  Art[i].Article_id << "|";
        outFile <<  Art[i].Article_name << "|";
        outFile <<  Art[i].Author_id << "|";
        outFile <<  Art[i].Journal_id << "|";
        outFile <<  Art[i].Publish_time << ",\n";
    }
    outFile.close();

}
*/
/*
thuongnguyenvan2209@gmail.com
Nguyen Van Thuong
0766739336
22/09/2004
049204010868
1 Le Duan, Hai Chau, Da Nang
*/