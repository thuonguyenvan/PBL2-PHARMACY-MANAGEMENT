#pragma once
using namespace std;
#include "Management.cpp"
#include "Staff.cpp"
class StaffManagement: public Management<Staff>
{
public:
    void readStaffFromFile(ifstream &);
    void ViewAllStaffs();
    void updateStaffFile();
    void addNewStaff();
    void removeStaff(const string &);
    void editStaff(const string &);
};