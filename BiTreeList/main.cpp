#include <iostream>
#include "BiTreeList.h"

using namespace std;

int main()
{
    char preList[] = "ABD##E##CF##G##";
    //BiTree<char>* bitree=new BiTree<char>(preList, 15, 0, '#');// ����һ�ö�����
    BiTree<char>* bitree=new BiTree<char>();// ����һ�ö�����
    bitree->PreOrder(); // ǰ�����
    cout << endl;
    bitree->InOrder();  // �������
    cout << endl;
    bitree->PostOrder(); // �������
    cout << endl;
    bitree->LeverOrder(); // �������
    delete bitree;
    return 0;
}
