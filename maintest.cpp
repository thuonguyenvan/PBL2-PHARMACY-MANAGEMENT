#include "Person.cpp"
#include "StaffManagement.cpp"
using namespace std;
int main(){
    StaffManagement CL;
    ifstream FileStaff("./Data/Staff.txt");
    CL.readStaffFromFile(FileStaff);
    CL.ViewAllStaffs();
}
/*
thuongnguyenvan2209@gmail.com
Nguyen Van Thuong
0766739336
22/09/2004
049204010868
1 Le Duan, Hai Chau, Da Nang
*/