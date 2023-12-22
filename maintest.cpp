#include <iostream>
#include <string>
#include <chrono>
#include <ctime>
using namespace std;
string getCurrentDate(){
    auto now = chrono::system_clock::now();
    time_t currentTime = std::chrono::system_clock::to_time_t(now);
    const int bufferSize = 20; // Đủ cho chuỗi "dd/mm/yyyy hh:mm:ss"
    char buffer[bufferSize];
    if (strftime(buffer, 20, "%d/%m/%Y %H:%M:%S", localtime(&currentTime))) {
        std::string currentTimeStr(buffer);
        return currentTimeStr;
    }
}

int main() {
    cout << 1;
    printf("%d", 2);
    return 0;
}
