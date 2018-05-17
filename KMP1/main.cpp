#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h>

#define MYKMP 1
#define MAX 1000

using namespace std;

int myKMP(const string &S, const string &T);
int KMP(const string &S, const string &T);
int index(const string &str1, const string &str2);
int main()
{
    ifstream infile;
    infile.open("pi1b.txt", ios::in);
    if(!infile)
    {
        cerr << "File could not be open!" << endl;
        abort();
    }
    register string pi1b;
    infile >> pi1b;
    infile.close();

    string t[MAX];
    register int num;
    for (register int a = 0; a < MAX; ++a)
    {
        t[a] = to_string(a);
        while(t[a].length() < 6)
            t[a] = "0"+t[a];
    }
    DWORD start_time = GetTickCount();
    for (register int a = 0; a < MAX; ++a)
    {
    #if(MYKMP == 1)
        num = myKMP(pi1b, t[a]); // 我的KMP算法
    #elif(MYKMP == 2)
        num = KMP(pi1b, t[a]); // KMP算法
    #elif(MYKMP == 3)
        num = index(pi1b, t[a]); // 朴素算法
    #else
        num = pi1b.find(t[a]); // string方法
    #endif
        if(a % 100 == 0)
            cout << t[a] << ": " << num << endl;
    }
    DWORD end_time = GetTickCount();
    cout << "The run time is:" << (end_time - start_time)/1000.0 << " s!" << endl;
    return 0;
}

inline void get_next(const string &str, int *pnext)
{ //获取串的next数组
    register int k(0); // k值
    size_t len(str.length()); // 串长度
    pnext[0] = -1; // next矩阵的第0位为-1
    pnext[1] = 0;  // next矩阵的第1位为0
    for(register size_t j(2); j < len; ++j)
    {// 从字符串T的第2个字符开始，计算每个字符的next值
        while(k > 0 && str[j-1] != str[k])//k>0并且最后一位和第k位不相等
            k = pnext[k]; // k 回溯
        if(str[j-1] == str[k]) //最后一位和第k位相等
            ++k; // k加1
        pnext[j] = k; // 第j位等于k
    }
}

int myKMP(const string &S, const string &T)
{
    register int *next = new int[T.length()];
    get_next(T, next);
    register int i = 0, j = 0; // 起始下标
    while (S[i] != '\0' && T[j] != '\0') //串尾
    {
        if (S[i] == T[j]) // 匹配
        {
            ++i;
            ++j; // 下一个
        }
        else // S[i] != T[j]
        {
            j = next[j]; // j回溯
        }
        if (j == -1) //T串首
        {
            ++i;
            ++j; // 下一个
        }
    }
    delete[] next;
    if (T[j] == '\0')
        return i - j;
    else
        return -1;
}

vector<int> getNext(const string &T)
{
    vector<int> next(T.size(), 0);            // next矩阵，含义参考王红梅版《数据结构》p84。
    next[0] = -1;                            // next矩阵的第0位为-1
    int k = 0;                            // k值
    for (size_t j = 2; j < T.size(); ++j)        // 从字符串T的第2个字符开始，计算每个字符的next值
    {
        while (k > 0 && T[j - 1] != T[k])
            k = next[k];
        if (T[j - 1] == T[k])
            k++;
        next[j] = k;
    }
    return next;                            // 返回next矩阵
}

int KMP(const string &S, const string &T)
{
    vector<int> next = getNext(T);
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            j = next[j];
        }
        if (j == -1)
        {
            ++i;
            ++j;
        }
    }
    if (T[j] == '\0')
        return i - j;
    else
        return -1;
}

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
            ++i;
        }
        return -1;
}
