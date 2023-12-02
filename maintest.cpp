#include "Person.cpp"
#include "CustomerManagement.cpp"
using namespace std;
int main(){
    CustomerManagement CL;
    ifstream FileCustomer("./Data/Customer.txt");
    CL.readCustomerFromFile(FileCustomer);
    CL.ViewAllCustomers();
    CL.updateCustomerFile();
    FileCustomer.close();
}
/*
thuongnguyenvan2209@gmail.com
Nguyen Van Thuong
0766739336
22/09/2004
049204010868
1 Le Duan, Hai Chau, Da Nang
*/