#include <iostream>
#include "LinkList.h"
using namespace std;

int main()
{
    int a = 0;
    int *p = &a;
    LinkList<int> li;
    li.append(0);
    li.append(1);
    li.append(2);
    li.append(3);
    li.append(4);
    li.append(5);
    li.append(6);
    li.append(7);
    li.append(8);
    li.popback(p);
    cout << "��ջ a = " << a << endl;
    cout <<"������"<< li.Length()<<endl;
    cout << "����Ԫ�ص�ֵ�ǣ�";
    cout << li << endl;
    int e = 0;
    cout << li.LocateElem(0) << endl;
    if(li.PriorElem(7, &e))
        cout << e << endl;

    cout << "��ת�����Ԫ�ص�ֵ�ǣ�";
    li.Reverse();
    cout << li << endl;
    li.append(100);
    cout << li << endl;

    return 0;
}
