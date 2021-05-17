#include "Reader.h"
#include "Manager.h"
#include <iostream>
#include "Book.h"
#include "vector"
#include "User.h"
#include <fstream>
#include <unistd.h>
#include <ctime>
using namespace std;
void Find()
{
    string name;
    cout << "请输入您要查询的书籍名" << endl;
    cin>>name;
    Manager::FindBookName(name);
    cout << "按任意键返回" << endl;
    system("pause");
}
void Reader::ShowMenu()
{
    system("cls");
    cout << "=============================欢迎使用图书管理系统：==========================" << endl;
    cout << "                              1.查询图书" << endl;
    cout << "                              2.借阅图书" << endl;
    cout << "                              3.归还图书" << endl;
    cout << "                              4.借阅记录" << endl;
    cout << "                              5.支付欠款" << endl;
    cout << "                              0.退出登录" << endl;
    if(0 == m_borrow_able) cout<<"您当前存在欠款，无法借书，请结清欠款后使用" << endl;
    else cout << "您当前可借书数量：" << m_borrow_number <<"本" <<endl;
    cout << "请输入命令" << endl;
    int command;
    cin>>command;
    while(!(0 <= command <= 5)) {
        cout << "无效的命令" << endl;
        cout << "请输入命令" << endl;
        cin>> command;
    }
    switch (command) {
        case 0:
            ShowMenu();
            Init();
            break;
        case 1:
            Find();
            ShowMenu();
            break;
        case 2:
            BorrowBook();
            ShowMenu();
            break;
        case 3:
            ReturnBook();
            ShowMenu();
            break;
        case 4:
            ShowRecord();
            ShowMenu();
            break;
        case 5:
            pay();
            ShowMenu();
            break;
        default:break;
    }
}
Reader::Reader(string id, string name, string psw):User(id,name,psw) {
    this->SetAble();
    this->SetNUmber();
}
Reader::Reader()= default;
Reader::~Reader() = default;
bool Reader::pay() {
    cout << "欠款已结清，按任意键返回" << endl;
    m_borrow_able = 1;
    ShowMenu();
}
bool Reader::GetState() {
    return m_borrow_able;
}
Reader::Reader(bool o,int a){}
void Reader::SetAble() { m_borrow_able = 1; }
void Reader::SetNUmber() { m_borrow_number  = 10; }
void Reader::Init() {
    string s = GetName()+".data";
    ofstream fout;
    if((access(s.c_str(),F_OK) == -1)) { fout.open(s.c_str()); fout.close(); }
}
void Reader::LoadRecord() {
    string s = GetName()+".data";
    ifstream fin;
    fin.open(s.c_str());
    string id;
    string name;
    string writer;
    int byear,bmonth,bday;
    int ryear,rmonth,rday;
    while(fin >> id >> name >> writer >> byear >> bmonth >> bday >> ryear >> rmonth >> rday) {
        record.push_back(Bookrecord(id,name,writer,byear,bmonth,bday,ryear,rmonth,rday));
    }
    fin.close();
}
void Reader::CheckRecord() {
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Date n(ltm->tm_year+1900,1+ltm->tm_mon,ltm->tm_mday);
    for(Bookrecord &b: record) {
        if(n > b.m_rdate) {
            m_borrow_able = false;
        }
    }
    if( m_borrow_number == 10 ) {
        m_borrow_able = false;
    }
}
void Reader::FlushRecord() {
    string s  = GetName()+".data";
    ofstream fout;
    fout.open(s.c_str());
    for(auto i = record.begin(); i != record.end(); i++) {
        fout << i->m_id << " " << i->m_name << " " << i->m_writer << " " << i->m_bdate.Ryear() << " " << i->m_bdate.Rmonth()  << i->m_bdate.Rday() << " " << i->m_rdate.Ryear() << " " << i->m_rdate.Rmonth() << " " << i->m_rdate.Rday() << endl;
    }
    fout.close();
    return;
}
bool Reader::FindBook(string name) {
    Manager::FindBookName(name);
}
bool Reader::BorrowBook() {
    string id;
    cout << "请输入图书编号" << endl;
    cin >> id;
    time_t now = time(0);
    tm *ltm = localtime(&now);
    Date n(ltm->tm_year+1900,1+ltm->tm_mon,ltm->tm_mday);
    Date m = n + 60;
    if(auto p = Manager::BorrowBook(id)) {
        record.push_back(Bookrecord(p->GetBookID(),p->GetBookName(),p->GetBookWriter(),n.Ryear(),n.Rmonth(),n.Rday(),m.Ryear(),m.Rmonth(),m.Rday()));
        m_borrow_number--;
    }
    return 1;

}
void Reader::ShowRecord() {
    cout << "id" <<" name " <<"writer" << "publisher" << endl;
    for(Bookrecord &r : record) {
        cout << r.m_id << r.m_name << r.m_writer;
        r.m_bdate.Display();
        r.m_rdate.Display();
    }
}
bool Reader::ReturnBook() {
    string id;
    cout << "请输入图书编号" << endl;
    cin >> id;
    int flag = 0;
    for(auto i = record.begin(); i != record.end(); i++) {
        if(i->m_id == id) {
            flag = 1;
            Manager::ReturnBook(id);
            record.erase(i);
            m_borrow_number++;
        }
    }
    if(flag == 0) {
        cout << "查不到此书的借阅信息" << endl;
    }
}
//
// Created by yl on 2021/5/7.
//