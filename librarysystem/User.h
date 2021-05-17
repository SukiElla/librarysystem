#ifndef LIBRARYSYSTEM_USER_H
#define LIBRARYSYSTEM_USER_H
#include <string>
using namespace std;
class User
{
private:
    string m_id;
    string m_name;
    string m_psw;
public:
    User();
    User(string,string,string);
    ~User();
    string GetID();
    string GetName();
    string GetPsw();
};
//
// Created by yl on 2021/5/11.
//

#endif //LIBRARYSYSTEM_USER_H
