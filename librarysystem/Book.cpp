#include "Book.h"
#include "string"

Book::Book(){}
Book::~Book(){}
Book::Book(string id,string name,string writer,string publisher,int totalnum,int leftnum)
{
    m_id = id;
    m_name = name;
    m_writer = writer;
    m_publisher = publisher;
    //m_totalnum = totalnum;
    //m_leftnum = leftnum;
}
Book::Book(string id,string name,string writer,string publisher,int year,int month,int day,int total,int leftnum):m_indate(year,month,day) {
    m_id = id;
    m_name = name;
    m_writer = writer;
    m_publisher = publisher;
    m_totalnum = total;
    m_leftnum = leftnum;
}
string Book::GetBookID(){ return m_id; }
string Book::GetBookName(){ return m_name; }
string Book::GetBookWriter(){ return m_writer; }
string Book::GetBookPublisher(){ return m_publisher; }
int Book::GetBookTotalnum() {return m_totalnum; }
int Book::GetBookLeftnum() { return m_leftnum; }
time_t now = time(0);
tm *ltm = localtime(&now);
Book::Book(string id, string name, string writer, string publisher,int num): m_indate(ltm->tm_year+1900,1+ltm->tm_mon,ltm->tm_mday)
{
    m_id = id;
    m_name = name;
    m_writer = writer;
    m_publisher = publisher;
    m_totalnum = num;
}
//
// Created by yl on 2021/5/7.
//
