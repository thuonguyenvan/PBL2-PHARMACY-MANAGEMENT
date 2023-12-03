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
    }

}

int main() {
    // Lấy thời gian hiện tại
    auto now = std::chrono::system_clock::now();
    
    // Chuyển đổi sang dạng time_t
    std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

    // Khai báo buffer để chứa chuỗi thời gian
    const int bufferSize = 20; // Đủ cho chuỗi "dd/mm/yyyy hh:mm:ss"
    char buffer[bufferSize];

    // Chuyển đổi time_t thành chuỗi
    if (std::strftime(buffer, bufferSize, "%d/%m/%Y %H:%M:%S", std::localtime(&currentTime))) {
        std::string currentTimeStr(buffer);

        // In thời gian hiện tại dưới dạng chuỗi
        std::cout << "Thời gian hiện tại: " << currentTimeStr << std::endl;
    }

    return 0;
}
