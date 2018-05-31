#include <iostream>
using namespace std;

class Clock
{
private:
    int hour, minute, second;
public:
    void Set(int h, int m, int s)
    {
        hour = h;
        minute = m;
        second = s;
    }
    void virtual Show()
    {
         cout << hour << ":" << minute << ":" << second;
    }
};

class Watch : public Clock
{
public:
    int band;
    void Show()
    {
        cout << "Watch";
        Clock::Show();
    }
};

int main()
{

    return 0;
}
