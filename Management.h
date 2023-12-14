<<<<<<< HEAD
#pragma once
using namespace std;
#include "Customer.cpp"
template <class T>
class Management
{
protected:
    T *List;
    int Count;
public:
    friend class ifstream;
    Management();
    ~Management();
    void Add();
    void View();
   // void Edit(const string &);
    void Remove(const string &);
    int CheckExisted(const string &);
    void readCountFromFile(ifstream &);
    void Edit(const string &);
    int returnCount();
    string returnEmail(const int&);
    string returnPassword(const int&);
    string returnName(const int&);
    T returnInfo(const int&);
};
=======
#pragma once
using namespace std;
#include "Customer.cpp"
template <class T>
class Management
{
protected:
    T *List;
    int Count;
public:
    friend class ifstream;
    Management();
    ~Management();
    void Add();
    void View();
   // void Edit(const string &);
    void Remove(const string &);
    int CheckExisted(const string &);
    void readCountFromFile(ifstream &);
    void Edit(const string &);
    int returnCount();
    string returnEmail(const int&);
    string returnPassword(const int&);
    string returnName(const int&);
    T returnInfo(const int&);
};
>>>>>>> efacc985dacfb5baa6091624f41eb57542a778ce
