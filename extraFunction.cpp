#pragma once
#include <iostream>
#include <chrono>
#include <string.h>
#include <limits>
using namespace std;
#include "extraFunction.h"
#define getenter cin.ignore(numeric_limits<streamsize>::max(), '\n');

void removeSpaces(string &str)
{
    string nstr;
    int i=0;
    while (i<str.length())
    {
        if (str[i]==' ') i++;
        else break;
    }
    for(; i<str.length();  ){
        if(str[i] == ' '){
            while(str[i+1] == ' ')
                i++;
        }
        nstr += str[i++];
    }
    str = nstr;
}

template <class T>
void edit(T& t){
    //getenter;
    string temp;
    getline(cin, temp);
    if (!temp.empty()) t = temp;
}

string getCurrentDate(){
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    const int bufferSize = 20; // Đủ cho chuỗi "dd/mm/yyyy hh:mm:ss"
    char buffer[bufferSize];
    if (strftime(buffer, 20, "%d/%m/%Y %H:%M:%S", localtime(&currentTime))) {
        std::string currentTimeStr(buffer);
        return currentTimeStr;
    }
    return NULL;
}

std::string generate_transaction_code(int length = 5) {
    const std::string characters = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    std::string transaction_code;

    // Khởi tạo seed cho hàm random dựa trên thời gian hiện tại
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    for (int i = 0; i < length; ++i) {
        int random_index = std::rand() % characters.length();
        transaction_code += characters[random_index];
    }
    string s = getCurrentDate();
    string t = "";
    for (int i = 0; i < 10; ++i) if (s[i] != '/') t += s[i];
    return transaction_code + t;
}

// int main() {
//     // Sử dụng hàm để tạo mã giao dịch
//     std::string transaction_code = generate_transaction_code();
//     std::cout << "Mã giao dịch mới: " << transaction_code << std::endl;

//     return 0;
// }

bool soSanhNgay(const std::string& ngay1, const std::string& ngay2) {
    int ngay1_int, thang1_int, nam1_int;
    int ngay2_int, thang2_int, nam2_int;

    sscanf(ngay1.c_str(), "%d/%d/%d", &ngay1_int, &thang1_int, &nam1_int);
    sscanf(ngay2.c_str(), "%d/%d/%d", &ngay2_int, &thang2_int, &nam2_int);

    if (nam1_int < nam2_int ||
        (nam1_int == nam2_int && thang1_int < thang2_int) ||
        (nam1_int == nam2_int && thang1_int == thang2_int && ngay1_int < ngay2_int)) {
        return true;
    } else if (nam1_int > nam2_int ||
               (nam1_int == nam2_int && thang1_int > thang2_int) ||
               (nam1_int == nam2_int && thang1_int == thang2_int && ngay1_int > ngay2_int)) {
        return false;
    } else {
        return true;
    }
}

#include <iostream>

bool soSanhThang(const std::string& thang1, const std::string& thang2) {
    int thang1_int, nam1_int;
    int thang2_int, nam2_int;

    sscanf(thang1.c_str(), "%d/%d", &thang1_int, &nam1_int);
    sscanf(thang2.c_str(), "%d/%d", &thang2_int, &nam2_int);

    if (nam1_int < nam2_int || (nam1_int == nam2_int && thang1_int < thang2_int)) {
        //std::cout << thang1 << " trước " << thang2 << std::endl;
        return true;
    } else if (nam1_int > nam2_int || (nam1_int == nam2_int && thang1_int > thang2_int)) {
       // std::cout << thang2 << " trước " << thang1 << std::endl;
        return false;
    } else {
       // std::cout << thang1 << " và " << thang2 << " là cùng một tháng." << std::endl;
        return true;
    }
}

bool soSanhNam(const std::string& nam1, const std::string& nam2) {
    int nam1_int, nam2_int;

    sscanf(nam1.c_str(), "%d", &nam1_int);
    sscanf(nam2.c_str(), "%d", &nam2_int);

    if (nam1_int < nam2_int) {
       // std::cout << nam1 << " trước " << nam2 << std::endl;
        return true;
    } else if (nam1_int > nam2_int) {
       // std::cout << nam2 << " trước " << nam1 << std::endl;
        return false;
    } else {
       // std::cout << nam1 << " và " << nam2 << " là cùng một năm." << std::endl;
        return true;
    }
}