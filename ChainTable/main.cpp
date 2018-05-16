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
    bool operator==(const Info &s)
        {
            return (this->name == s.name) && (this->id == s.id);
        }
    bool operator!=(const Info &s)
        {
            return (this->name != s.name) || (this->id != s.id);
        }
};


int main()
{
    Info val1,val2,val3,val4;
    val1.id =201281001,val1.name="Kevin",val2.id=201281002,val2.name="Cathy",\
    val3.id=201281003,val3.name="Lucy",val4.id=201281004,val4.name="Gravin";
    LinkList<Info> st;
    st.InsertHead(val1);
    st.append(val2);
    st.append(val3);
    st.InsertHead(val4);
    cout << "=============原始学生序列==============\n" << st << endl;
    Info *p = new Info[1];
    st.popback(p);
    cout << "================删除项=================\n" << *p << endl;
    cout << "=============删除后的序列==============\n" << st << endl;
    st.Delete(1, p);
    cout << "================删除项=================\n" << *p << endl;
    cout << "=============删除后的序列==============\n" << st << endl;
    st.append(val3);
    st.append(val4);
    cout << "=============原始学生序列==============\n" << st << endl;
    LinkList<Info> org_st = st;
    st.Reverse();
    cout << "=============反序输出序列==============\n" << st << endl;
    cout << "=============拷贝序列==============\n" << org_st << endl;
    st.RemoveElem(val3);
    cout << "=============删除val3学生序列==============\n" << st << endl;
    st.pophead(p);
    cout << "================删除项=================\n" << *p << endl;
    cout << "=============删除后的序列==============\n" << st << endl;
    st.InsertHead(val1);
    cout << "=============头部插入后的序列==============\n" << st << endl;
    st.append(val4);
    cout << "=============尾部插入后的序列==============\n" << st << endl;
    cout << "=============原始序列==============\n" << org_st << endl;
    if (st != org_st)
        cout << "判断现有序列和原始序列是否相等：" << " 不相等 " << endl;
    else
        cout << "判断现有序列和原始序列是否相等：" << " 相等 " << endl;
    st.Replace(2, val3);
    st.Replace(0, val4);
    cout << "=============替换0,3的序列==============\n" << st << endl;
    if (st != org_st)
        cout << "判断现有序列和原始序列是否相等：" << " 不相等 " << endl;
    else
        cout << "判断现有序列和原始序列是否相等：" << " 相等 " << endl;
    delete p;
    return 0;
}
