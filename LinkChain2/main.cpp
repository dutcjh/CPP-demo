#include <iostream>
#include <string>
#include "LinkQueue.h"
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
    LinkQueue<Info> st;
    Info *p = new Info[1];
    st.enQueue(val1);
    st.enQueue(val2);
    cout << "===========��ǰ����==============\n" << st << endl;
    st.enQueue(val3);
    st.enQueue(val4);
    cout << "===========��ǰ����==============\n" << st << endl;
    st.deQueue(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ����==============\n" << st << endl;
    st.deQueue(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ����==============\n" << st << endl;
    st.getHead(p);
    cout << "===========���г���==============\n" << st.count()<< endl;
    cout << "===========����Ԫ��==============\n" << *p;
    st.deQueue(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ����==============\n" << st << endl;
    st.deQueue(p);
    cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ����==============\n" << st << endl;
    if(st.deQueue(p))
        cout << "===========��ջ==============\n" << *p;
    cout << "===========��ǰ����==============\n" << st << endl;

    delete p;
    return 0;
}
