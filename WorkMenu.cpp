#include "WorkMenu.h"
using namespace std;

int WorkMenu::count = 1;

void WorkMenu::Show(){
    cout << WorkMenu::count++ << ". Tro ve.\n";
    cout << WorkMenu::count++ << ". Thoat.\n";
}

void WorkMenu::DisplayInfo(string& ID){
    
}

void WorkMenu::DisplayAccountList(){
    
}

void WorkMenu::DisplayReceipt(){
    
}