#include <iostream>
#include <string>
#include "LinkList.h"
using namespace std;

struct Info
{
    string name;
    unsigned id;
    friend ostream &operator<<(ostream &os, const Info &info)
        { return os << "name: " << info.name << "\nID: " << info.id << endl;}
};


int main()
{
    Info val1,val2,val3,val4;
    val1.id =201281001,val1.name="Kevin",val2.id=201281002,val2.name="Cathy",\
    val3.id=201281003,val3.name="Lucy",val4.id=201281004,val4.name="Gravin";
    LinkList<Info> st;
    st.append(val1);
    st.append(val2);
    st.append(val3);
    st.Insert(1, val4);
    cout << "=============ԭʼѧ������==============\n" << st << endl;
    Info *p = new Info[1];
    st.popback(p);
    cout << "================ɾ����=================\n" << *p << endl;
    cout << "=============ɾ���������==============\n" << st << endl;
    st.Delete(1, p);
    cout << "================ɾ����=================\n" << *p << endl;
    cout << "=============ɾ���������==============\n" << st << endl;
    st.append(val3);
    st.append(val4);
    cout << "=============ԭʼѧ������==============\n" << st << endl;
    LinkList<Info> org_st = st;
    st.Reverse();
    cout << "=============�����������==============\n" << st << endl;
    cout << "=============��������==============\n" << org_st << endl;

    return 0;
}
