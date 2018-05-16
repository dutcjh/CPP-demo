#include <iostream>
#include <string>
#include "LinkStack.h"
using namespace std;


int main()
{
    LinkStack<int> s;
    int a[4]={1,2,3,4};
    for (int i=0;i<4;i++)
    {
        s.push(a[i]);
    }
    cout << s << endl;
    LinkStack<int> s1;
    s1 = s;
    for (int i=0;i<4;i++)
    {
        int temp;
        s.pop(&temp);
        cout<<temp<<endl;
    }
    cout<<s1.count() << endl;
    cout<<s.count();
    return 0;
}
