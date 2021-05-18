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
    void ShowMenu();
    bool GetState();
    void ShowRecord();
    Reader();
    Reader(string id,string name,string psw);
    Reader(bool,int);
    ~Reader();
    void LoadRecord();
    void CheckRecord();
    void FlushRecord();
    void Init();
};//
// Created by yl on 2021/5/7.
//
#endif //LIBRARYSYSTEM_READER_H
