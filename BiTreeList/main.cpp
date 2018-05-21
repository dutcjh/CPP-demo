#include <iostream>
#include "BiTreeList.h"

using namespace std;

int main()
{
    char preList[] = "ABD##E##CF##G##";
    //BiTree<char>* bitree=new BiTree<char>(preList, 15, 0, '#');// 创建一棵二叉树
    BiTree<char>* bitree=new BiTree<char>();// 创建一棵二叉树
    bitree->PreOrder(); // 前序遍历
    cout << endl;
    bitree->InOrder();  // 中序遍历
    cout << endl;
    bitree->PostOrder(); // 后序遍历
    cout << endl;
    bitree->LeverOrder(); // 层序遍历
    delete bitree;
    return 0;
}
