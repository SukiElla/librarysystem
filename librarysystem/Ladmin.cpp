#include "Ladmin.h"
#include <iostream>
#include <utility>
#include "Manager.h"
void Init();
void Refresh();
using namespace std;
void AddAdmin()
{
    string id;
    string name;
    string psw;
    cout << "输入id name psw" << endl;
    cin >> id >> name >> psw;
    if(Manager::FindAdmin(id)) cout << "has exist" << endl;
    else Manager::AddAdmin(id,name,psw);
    cout << "success" << endl;
    cout << "go to the main menu" << endl;
}
void AddBook()
{
    string id;
    string name;
    string writer;
    string publisher;
    int num;
    cout << "输入id name writer publisher num" << endl;
    cin >> id >> name >> writer >> publisher >> num;
    if(Manager::FindBook(id)) Manager::AddOldBook(id,num);
    else Manager::AddNewBook(id,name,writer,publisher,num);
    cout << "success" << endl;
    cout << "go to the main menu" << endl;
}
void Ladmin::ShowMenu() {
    system("cls");
    cout << "==========================欢迎使用图书馆后台管理系统：==========================" << endl;
    cout << "                              1.新书录入" << endl;
    cout << "                              2.图书查询" << endl;
    cout << "                              3.删除图书" << endl;
    cout << "                              4.图书列表" << endl;
    cout << "                              5.借阅记录" << endl;
    cout << "                              6.新增用户" << endl;
    cout << "                              7.用户列表" << endl;
    cout << "                              0.退出登录" << endl;
    int command = -1;
    cout << "请输入命令" << endl;
    cin>>command;
    while (!(0<=command && command<=7)) {
        cout << "命令有误，请重新输入" << endl;
        cout << "请输入命令" << endl;
        cin>>command;
    }
    string id;
    switch (command) {
        case 1:
            AddBook();
            ShowMenu();
            break;
        case 2:
            Manager::FindBookName("计算机");
            ShowMenu();
            break;
        case 3:
            cin>>id;
            Manager::RemoveBook(id);
            Refresh();
            break;
        case 4:
            GetBooks();
            ShowMenu();
            break;
        case 5:;
        case 6:
            AddAdmin();
            ShowMenu();
            break;
        case 7:
            GetUsers();
            ShowMenu();
            break;
        case 0:
            Init();
            break;
        default:break;
    }
}
void Ladmin::GetUsers()  {
    cout << "ID" <<"        "<< "姓名" <<"         "<< "当前状态" << endl;
    for(auto & i : Manager::readerlist) {
        cout << i.GetID() <<"        "<< i.GetName()<<"           ";
        if(i.GetState()) cout <<"可借";
        else cout <<"不可借";
        cout << endl;
    }
    cout << "按任意键返回主菜单" << endl;
    system("pause");
    ShowMenu();
}
void Ladmin::GetBooks() {
    cout << "ID     书名            作者           出版社       入库日期     馆藏数量   余量" << endl;
    for(auto & i : Manager::booklist) {
        cout << i.GetBookID() << i.GetBookName() << i.GetBookWriter() << i. GetBookPublisher();
        i.m_indate
        .Display();
        cout << i.GetBookTotalnum() << i. GetBookLeftnum() << endl;
    }
}
Ladmin::Ladmin() = default;
Ladmin::Ladmin(string id, string name, string psw):User(std::move(id),std::move(name),std::move(psw)) {}
Ladmin::~Ladmin() = default;
//
// Created by yl on 2021/5/15.
//

