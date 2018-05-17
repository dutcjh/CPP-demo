#include <iostream>
#include <string>
using namespace std;

int index(const string &str1, const string &str2)
{
        register int i(0), j(0);
        if(str1.empty() || str2.empty()) return -1;
        while (str1[i])
        {
            j = 0;
            while(str1[i] && str2[j] && !(str1[i]-str2[j]))
                ++i, ++j;
            if (!str2[j])
                return (i-j);
            i++;
        }
        return -1;
}


int main()
{
    string s1 = "abcabxab";
    string s2 = "a";
    cout << "s1: " << s1 << endl;
    cout << "s2: " << s2 << endl;
    cout << index(s1, s2)<< endl;
    return 0;
}
