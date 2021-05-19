#ifndef LIBRARYSYSTEM_BOOK_H
#define LIBRARYSYSTEM_BOOK_H
#include <string>
#include "Date.h"
#include "Chinese.h"
using namespace std;
class Book
{
private:
    string m_id;
    string m_name;
    string m_writer;
    string m_publisher;
    string m_field;
public:
    Date m_indate;
    int m_no;
    int flag = 0;
    int m_totalnum;
    int m_leftnum;
    Book();
    Book(string,string,string,string,int,int);
    string GetBookID();
    string GetBookName();
    string GetBookWriter();
    string GetBookPublisher();
    string GetBookField();
    int GetBookTotalnum();
    int GetBookLeftnum();
    Book(string id, string name, string writer, string publisher,int num,string field);
    ~Book();
    Book(string id,string name,string writer,string publisher,int year,int month,int day,int total,int leftnum,string field);
};//
// Created by yl on 2021/5/7.
//

#endif //LIBRARYSYSTEM_BOOK_H