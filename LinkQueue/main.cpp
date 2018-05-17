#include <iostream>
#include <string>
#include "CircleList.h"
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
    CircleList<Info> st;
    Info *p = new Info[1];
    cout << "=============学生序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    st.InsertHead(val1);
    cout << "=============学生序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    st.append(val2);
    cout << "=============学生序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    st.append(val3);
    cout << "=============学生序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    st.InsertHead(val4);
    cout << "=============学生序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    st.popback(p);
    cout << "================删除项=================\n" << *p << endl;
    cout << "=============删除后的序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    st.Delete(1, p);
    cout << "================删除项=================\n" << *p << endl;
    cout << "=============删除后的序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    st.append(val3);
    st.append(val4);
    cout << "=============原始学生序列==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;

    CircleList<Info> org_st = st;
    st.Reverse();
    cout << "=============反序输出序列==============\n" << st << endl;
    cout << "=============拷贝序列==============\n" << org_st << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;
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
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;
    st.Replace(2, val3);
    st.Replace(0, val4);
    cout << "=============替换0,2的序列==============\n" << st << endl;
    if (st == org_st)
        cout << "判断现有序列和原始序列是否相等：" << " 相等 " << endl;
    else
        cout << "判断现有序列和原始序列是否相等：" << " 不相等 " << endl;
    if (st.GetTailElem(p))
        cout << "尾节点元素：\n" << *p;
    if (st.GetHeadElem(p))
        cout << "头节点元素：\n" << *p;
    cout << "元素 val4 位置" << st.LocateElem(val4) << endl;
    st.PriorElem(val3, p);
    cout << "元素 val3 上一个是" << *p;
    st.NextElem(val3, p);
    cout << "元素 val3 下一个是" << *p;
    st.pophead(p);
    st.pophead(p);
    st.pophead(p);
    cout << "=============原始学生序列==============\n" << st << endl;
    st.Reverse();
    cout << "=============反序输出序列==============\n" << st << endl;
    st = org_st;
    cout << "=============原始学生序列==============\n" << st << endl;
    delete p;
    return 0;
}
