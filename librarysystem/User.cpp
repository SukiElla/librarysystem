#include "User.h"
#include <string>
using namespace std;
User::User(string id, string name, string psw)
{
    m_id = id;
    m_name = name;
    m_psw = psw;
}
User::User(){}
User::~User(){}
string User::GetID() { return m_id; }
string User::GetName() { return m_name; }
string User::GetPsw() { return m_psw; }
//
// Created by yl on 2021/5/11.
//
