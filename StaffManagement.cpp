#pragma once
using namespace std;
#include "Management.cpp"
#include "Staff.cpp"
#include "Person.cpp"

int main()
{
    Management<Staff> StaffList;
    StaffList.Add();
    StaffList.View();
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