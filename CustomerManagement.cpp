
using namespace std;
#include "Management.cpp"
#include "Customer.cpp"
#include "Person.cpp"

int main()
{
    Management<Customer> CustomerList;
    CustomerList.Add();
    CustomerList.View();

    return 0;
}
/*
thuongnguyenvan2209@gmail.com
Nguyen Van Thuong
0766739336
22/09/2004
049204010868
1 Le Duan, Hai Chau, Da Nang
*/