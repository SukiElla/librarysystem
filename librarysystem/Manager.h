#ifndef LIBRARYSYSTEM_MANAGER_H
#define LIBRARYSYSTEM_MANAGER_H

#include "Book.h"
#include "string"
#include "Reader.h"
#include <vector>
#include "Ladmin.h"
class Manager
{
public:
    static vector<Book> booklist;
    static vector<Reader> readerlist;
    static vector<Ladmin> ladminlist;
public:
    static Book* FindBook(string id);
    static bool RemoveBook(string id);
    static bool AddNewBook(string id, string name, string writer, string publisher,int num,string field);
    static bool AddOldBook(string id,int num);
    static Reader* FindReader(string id);
    static bool AddReader(string id,string name,string psw,int sex);
    static bool RemoveReader(string id);
    static Ladmin* FindAdmin(string id);
    static bool RemoveAdmin(string id);
    static bool AddAdmin(string id,string name,string psw,int sex);
    static void FindBookName(string name);
    static Book* BorrowBook(string id);
    static void ReturnBook(string id);
};

//
// Created by yl on 2021/5/11.
//
#endif //LIBRARYSYSTEM_MANAGER_H
