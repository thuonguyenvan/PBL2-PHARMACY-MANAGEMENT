#pragma once
#include <iostream>
#include <string.h>
using namespace std;
#include "extraFunction.h"
#define getenter fflush(stdin);

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
