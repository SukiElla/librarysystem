#ifndef LIBRARYSYSTEM_READER_H
#define LIBRARYSYSTEM_READER_H
#include "User.h"
#include "Book.h"
#include <vector>
#include "Bookrecord.h"
using namespace std;
class Reader : public User
{
private:
    bool m_borrow_able {};
    int m_borrow_number {};
    vector<Bookrecord> record;
public:
    void SetAble();
    void SetNUmber();
    int m_no{};
    bool ReturnBook();
    bool BorrowBook();
    bool FindBook(string);
    bool pay();
    //void ShowMenu();
    int GetState();
    int GetNumber();
    void ShowRecord();
    Reader();
    Reader(string id,string name,string psw,int sex);
    Reader(string id,string name,string psw,int sex,bool borrow_able,int borrow_number);
    Reader(bool,int);
    ~Reader();
    void CheckRecord();
    void Init();
    //void FlushRecord();
    //void LoadRecord();
};
//
// Created by yl on 2021/5/7.
//
#endif //LIBRARYSYSTEM_READER_H
