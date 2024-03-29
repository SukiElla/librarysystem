#include <algorithm>
#include "File.h"
#include "Manager.h"
#include "Book.h"
using namespace std;
bool compare(Book b1,Book b2)
{
    return b1.flag > b2.flag;
}
Book * Manager::FindBook(string id) {
    for(Book &b : booklist)
    {
        if(b.GetBookID() == id)
        {
            return &b;
        }
    }
    return nullptr;
}
bool Manager::AddNewBook(string id, string name, string writer, string publisher,int num,string field) {
    for( Book &b : booklist)
    {
        if(b.GetBookID() == id)
        {
            return false;
        }
    }
    booklist.push_back(Book(id,name,writer,publisher,num,field));
    booklist.back().m_no = int(booklist.size());
    return true;
}
bool Manager::AddOldBook(string id,int num) {
    int flag = 0;
    for( Book &b : booklist)
    {
        if(b.GetBookID() == id)
        {
            b.m_totalnum+=num;
            flag = 1;
        }
    }
    return flag;
}
bool Manager::RemoveBook(string id) {
    int flag = 0;
    for(auto i = booklist.begin();i != booklist.end(); i++){
        if( i->GetBookID() == id)
        {
            booklist.erase(i);
            flag = 1;
        }
    }
    return flag;
}
Reader* Manager::FindReader(string id) {
    for(Reader &r : readerlist)
    {
        if(r.GetID() == id) {
            return &r;
        }
    }
    return NULL;
}
bool Manager::AddReader(string id, string name, string psw,int sex)
{
    for( Reader &r : readerlist)
    {
        if(r.GetID() == id) {
            return false;
        }
    }
    readerlist.push_back( Reader(id,name,psw,sex));
    readerlist.back().m_no = int(readerlist.size());
    return true;
}
bool Manager::RemoveReader(string id) {
    int flag = 0;
    for( auto i = readerlist.begin();i != readerlist.end();i++) {
        if(i->GetID() == id) {
            readerlist.erase(i);
            flag = 1;
        }
    }
    return flag;
}
Ladmin* Manager::FindAdmin(string id) {
    for(Ladmin &a : ladminlist)
    {
        if(a.GetID() == id)
        {
            return &a;
        }
    }
    return nullptr;
}
bool Manager::RemoveAdmin(string id) {
    int flag = 0;
    for(auto i = ladminlist.begin(); i!=ladminlist.end(); i++) {
        if(i->GetID() == id) {
            ladminlist.erase(i);
            flag = 1;
        }
    }
    return flag;
}
bool Manager::AddAdmin(string id, string name, string psw,int sex) {
    for(Ladmin & a : ladminlist) {
        if(a.GetID() == id) {
            return false;
        }
    }
    ladminlist.push_back(Ladmin(id,name,psw,sex));
}
void Manager::FindBookName(string name) {
    int n = name.length();
    for(Book &b : booklist) {
        for(int i=0;i<n;i++) {
            Chinese c1;
            Chinese c2;
            wstring w1_str = c1.strToWstr(name);
            string temp = b.GetBookName();
            wstring w2_str = c2.strToWstr(temp);
            if(temp.find(name) != temp.npos) {
                b.flag++;
            }
        }
    }
    for(Book &b : booklist) {
        if(b.flag != 0) {
            //cout << b.GetBookID() << b.GetBookName() << b.GetBookWriter() << b.GetBookPublisher();
            //b.m_indate.Display();
            //cout << b.GetBookTotalnum() << b.GetBookLeftnum() << endl;
        }
    }
}
Book* Manager::BorrowBook(string id) {
    int flag = 0;
    for(Book &b : booklist) {
        if(b.GetBookID() == id) {
            if(b.GetBookLeftnum() == 0) {
                return 0;
            } else {
                b.m_leftnum--;
                flag = 1;
                break;
            }
        }
    }
}
void Manager::ReturnBook(string id) {
    for(Book &b : booklist) {
        if(b.GetBookID() == id){
            b.m_leftnum++;
            //cout << "还书成功" << endl;
        }
    }
}
void Manager::FindBookField(string field) {
    int n = field.length();
    for(Book &b : booklist) {
        for(int i=0;i<n;i++) {
            Chinese c1;
            Chinese c2;
            wstring w1_str = c1.strToWstr(field);
            string temp = b.GetBookName();
            wstring w2_str = c2.strToWstr(temp);
            if(temp.find(field) != temp.npos) {
                b.flag++;
            }
        }
    }
    for(Book &b : booklist) {
        if(b.flag != 0) {
            //cout << b.GetBookID() << b.GetBookName() << b.GetBookWriter() << b.GetBookPublisher();
            //b.m_indate.Display();
            //cout << b.GetBookTotalnum() << b.GetBookLeftnum() << endl;
        }
    }
}
void Manager::FindBookWriter (string writer) {
    int n = writer.length();
    for(Book &b : booklist) {
        for(int i=0;i<n;i++) {
            Chinese c1;
            Chinese c2;
            wstring w1_str = c1.strToWstr(writer);
            string temp = b.GetBookName();
            wstring w2_str = c2.strToWstr(temp);
            if(temp.find(writer) != temp.npos) {
                b.flag++;
            }
        }
    }
    for(Book &b : booklist) {
        if(b.flag != 0) {
            //cout << b.GetBookID() << b.GetBookName() << b.GetBookWriter() << b.GetBookPublisher();
            //b.m_indate.Display();
            //cout << b.GetBookTotalnum() << b.GetBookLeftnum() << endl;
        }
    }
}
//
// Created by yl on 2021/5/11.
//

