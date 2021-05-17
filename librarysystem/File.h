#ifndef LIBRARYSYSTEM_FILE_H
#define LIBRARYSYSTEM_FILE_H
#include "Reader.h"
#include <vector>
#include "Ladmin.h"
using namespace std;
class File
{
public:
    bool LoadReader(vector<Reader> &readers);
    static bool FlushReader(vector<Reader> &readers);
    bool LoadAdmin(vector<Ladmin> &ladmins);
    static bool FlushAdmin(vector<Ladmin> &ladmins);
    bool LoadBook(vector<Book> &books);
    static bool FlushBook(vector<Book> &books);
    void Init();
};
//
// Created by yl on 2021/5/7.
//


#endif //LIBRARYSYSTEM_FILE_H
