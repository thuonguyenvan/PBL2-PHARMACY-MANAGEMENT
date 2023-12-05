#pragma once
#include <iostream>
#include <chrono>
#include <string.h>
#include <limits>
using namespace std;
#include "extraFunction.h"
#define getenter cin.ignore(numeric_limits<streamsize>::max(), '\n');;

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
    getenter;
    getline(cin, t);
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