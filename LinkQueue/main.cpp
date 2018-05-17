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
    cout << "=============ѧ������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    st.InsertHead(val1);
    cout << "=============ѧ������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    st.append(val2);
    cout << "=============ѧ������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    st.append(val3);
    cout << "=============ѧ������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    st.InsertHead(val4);
    cout << "=============ѧ������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    st.popback(p);
    cout << "================ɾ����=================\n" << *p << endl;
    cout << "=============ɾ���������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    st.Delete(1, p);
    cout << "================ɾ����=================\n" << *p << endl;
    cout << "=============ɾ���������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    st.append(val3);
    st.append(val4);
    cout << "=============ԭʼѧ������==============\n" << st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;

    CircleList<Info> org_st = st;
    st.Reverse();
    cout << "=============�����������==============\n" << st << endl;
    cout << "=============��������==============\n" << org_st << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;
    st.RemoveElem(val3);
    cout << "=============ɾ��val3ѧ������==============\n" << st << endl;
    st.pophead(p);
    cout << "================ɾ����=================\n" << *p << endl;
    cout << "=============ɾ���������==============\n" << st << endl;
    st.InsertHead(val1);
    cout << "=============ͷ������������==============\n" << st << endl;
    st.append(val4);
    cout << "=============β������������==============\n" << st << endl;
    cout << "=============ԭʼ����==============\n" << org_st << endl;
    if (st != org_st)
        cout << "�ж��������к�ԭʼ�����Ƿ���ȣ�" << " ����� " << endl;
    else
        cout << "�ж��������к�ԭʼ�����Ƿ���ȣ�" << " ��� " << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;
    st.Replace(2, val3);
    st.Replace(0, val4);
    cout << "=============�滻0,2������==============\n" << st << endl;
    if (st == org_st)
        cout << "�ж��������к�ԭʼ�����Ƿ���ȣ�" << " ��� " << endl;
    else
        cout << "�ж��������к�ԭʼ�����Ƿ���ȣ�" << " ����� " << endl;
    if (st.GetTailElem(p))
        cout << "β�ڵ�Ԫ�أ�\n" << *p;
    if (st.GetHeadElem(p))
        cout << "ͷ�ڵ�Ԫ�أ�\n" << *p;
    cout << "Ԫ�� val4 λ��" << st.LocateElem(val4) << endl;
    st.PriorElem(val3, p);
    cout << "Ԫ�� val3 ��һ����" << *p;
    st.NextElem(val3, p);
    cout << "Ԫ�� val3 ��һ����" << *p;
    st.pophead(p);
    st.pophead(p);
    st.pophead(p);
    cout << "=============ԭʼѧ������==============\n" << st << endl;
    st.Reverse();
    cout << "=============�����������==============\n" << st << endl;
    st = org_st;
    cout << "=============ԭʼѧ������==============\n" << st << endl;
    delete p;
    return 0;
}
