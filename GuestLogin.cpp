#include "GuestLogin.h"
using namespace std;

void GuestLogin::Show(){
    cout << GuestLogin::count++ << ". No account.\n";
    cout << GuestLogin::count++ << ". Register.\n";
    LoginForm::Show();
    GuestLogin::count = 1;
}

void GuestLogin::Run(){

}