#include <iostream>
#include <string>
#include "LinkQueue.h"

using namespace std;

template <typename T>
struct BiNode /* 结点结构 */
{
    T data; // 数据域
    BiNode<T> *lchild, *rchild; // 左右孩子结点
};

template <typename T>
class BiTree
{
private:
    BiNode<T> *root; // 指向根结点的头结点
    BiNode<T> *Creat(BiNode<T> *bt); // 构造函数调用
    BiNode<T> *CreatBT(const T preList[], const int size, int &index, const T end);
    void Release(BiNode<T> *bt);  // 析构函数调用
    void PreOrder(BiNode<T> *bt);  //前序遍历函数调用
    void InOrder(BiNode<T> *bt); // 中序遍历函数调用
    void PostOrder(BiNode<T> *bt); // 后序遍历函数调用
public:
    BiTree() { root = Creat(root); } // 构造函数
    BiTree(const T preList[], const int size, int index, const T end)
    { root = CreatBT(preList, size, index, end); } // 构造函数
    BiTree(const BiTree<T> &bt) = delete; //拷贝构造函数禁用
    ~BiTree() { Release(root); } //析构函数
    void PreOrder() { PreOrder(root); }      // 递归前序遍历二叉树
    void InOrder() { InOrder(root); }        // 递归中序遍历二叉树
    void PostOrder() { PostOrder(root); }    // 递归后序遍历二叉树
    void LeverOrder();                       // 层序遍历二叉树
};

template<typename T>
inline void BiTree<T>::LeverOrder()
{
    LinkQueue<BiNode<T>*> Q;  // 定义一个队列
    Q.initQueue();      // 初始化队列
    if(root != nullptr) Q.enQueue(root);// 根指针入队
    BiNode<T>* q = new BiNode<T>; //暂存器
    while (Q.deQueue(&q)) // 出队
    {
        cout << q->data; // 显示输出
        if (q->lchild) Q.enQueue(q->lchild);// 左孩子入队
        if (q->rchild) Q.enQueue(q->rchild);// 右孩子入队
    }
}

template<typename T>
inline BiNode<T>* BiTree<T>::CreatBT(const T preList[], const int size, int &index, const T end)
{
    BiNode<T>* root = nullptr;
    if((index < size) && (preList[index] != end))
    {
        root = new BiNode<T>();
        root->data = preList[index];
        root->lchild = CreatBT(preList, size, ++index, end);
        root->rchild = CreatBT(preList, size, ++index, end);
    }
    return root;
}

template<typename T>
inline BiNode<T>* BiTree<T>::Creat(BiNode<T>* bt)
{
    T ch;
    cin >> ch; // 输入结点的数据信息，假设为字符
    if(ch == '#') bt = nullptr; // 建立一棵空树
    else
    {
        bt = new BiNode<T>;// 生成一个结点，数据域为ch
        bt->data = ch;
        bt->lchild = Creat(bt->lchild);// 递归建立左子树
        bt->rchild = Creat(bt->rchild);// 递归建立右子树
    }
    return bt;
}

template<typename T>
inline void BiTree<T>::Release(BiNode<T>* bt)
{
    if(bt)
    {
        Release(bt->lchild);// 释放左子树
        Release(bt->rchild);// 释放右子树
        delete bt;          // 释放根节点
    }
}

template<typename T>
inline void BiTree<T>::PreOrder(BiNode<T>* bt)
{
    if (bt == nullptr) return;  // 递归调用的结束条件
    cout << bt->data;           // 访问根节点bt的数据域
    PreOrder(bt->lchild);       // 前序递归遍历bt的左子树
    PreOrder(bt->rchild);       // 前序递归遍历bt的右子树
}

template<typename T>
inline void BiTree<T>::InOrder(BiNode<T>* bt)
{
    if (bt == nullptr) return;  // 递归调用的结束条件
    InOrder(bt->lchild);        // 中序递归遍历bt的左子树
    cout << bt->data;           // 访问根节点bt的数据域
    InOrder(bt->rchild);        // 中序递归遍历bt的右子树
}

template<typename T>
inline void BiTree<T>::PostOrder(BiNode<T>* bt)
{
    if (bt == nullptr) return;  // 递归调用的结束条件
    PostOrder(bt->lchild);      // 后序递归遍历bt的左子树
    PostOrder(bt->rchild);      // 后序递归遍历bt的右子树
    cout << bt->data;           // 访问根节点bt的数据域
}
