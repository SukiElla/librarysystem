//
// Created by yunlang on 2021/5/17.
//
#ifndef LIBRARYSYSTEM_BOOKRECORD_H
#define LIBRARYSYSTEM_BOOKRECORD_H
class Bookrecord {
public:
    string m_id;
    string m_name;
    string m_writer;
    Date m_bdate;
    Date m_rdate;
    Bookrecord(){}
    ~Bookrecord(){}
    Bookrecord(string id,string name,string writer,int byear,int bmonth,int bday,int ryear,int rmonth,int rday) : m_bdate(byear,bmonth,bday),m_rdate(ryear,rmonth,rday) {
        m_id = id;
        m_name = name;
        m_writer = writer;
    }
};
#endif //LIBRARYSYSTEM_BOOKRECORD_H
