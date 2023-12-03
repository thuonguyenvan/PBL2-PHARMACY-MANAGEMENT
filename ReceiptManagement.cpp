using namespace std;
#include "ReceiptManagement.h"
#include "Receipt.cpp"
ReceiptManagement::ReceiptManagement()
{}

ReceiptManagement::~ReceiptManagement()
{
    delete []List;
}

void ReceiptManagement::CustomeraddNewReceipt(){
    this -> Count ++;
    Receipt R;
    
} 