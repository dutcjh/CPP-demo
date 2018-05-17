#include <iostream>
#include <string>
#include "LinkStack.h"
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
    LinkStack<Info> st;
    Info *p = new Info[1];
    st.push(val1);
    st.push(val2);
    cout << "===========��ǰ��ջ==============\n" << st << endl;
    st.push(val3);
    st.push(val4);
    cout << "===========��ǰ��ջ==============\n" << st << endl;
    st.pop(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ����==============\n" << st << endl;
    st.pop(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ��ջ==============\n" << st << endl;
    cout << "===========���г���==============\n" << st.count()<< endl;
    st.top(p);
    cout << "===========����Ԫ��==============\n" << *p;
    st.pop(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ��ջ==============\n" << st << endl;
    st.pop(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ��ջ==============\n" << st << endl;
    if(st.pop(p))
        cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ��ջ==============\n" << st << endl;

    delete p;
    return 0;
}
