#include <iostream>
using namespace std;

class Circle
{
private:
    double r;
    double CArea(){return 3.14*r*r;}
    double CLen(){return 2*3.14*r;}
public:
    void Input(){cin >> r;}
    void Show()
    {
        cout << CArea() << endl;
        cout << CLen() << endl;
    }
};

class Rectangle
{
public:
    double a, b;
    double RArea(){return a*b;}
    double RLen(){return 2*(a+b);}
};


int main()
{
    Circle obj1;
    obj1.Input();
    obj1.Show();
    Rectangle obj2;
    cin >> obj2.a >> obj2.b;
    cout << obj2.RArea() << endl;
    cout << obj2.RLen() << endl;

    return 0;
}
