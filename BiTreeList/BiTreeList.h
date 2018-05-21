#include <iostream>
#include <string>
#include "LinkQueue.h"

using namespace std;

template <typename T>
struct BiNode /* ���ṹ */
{
    T data; // ������
    BiNode<T> *lchild, *rchild; // ���Һ��ӽ��
};

template <typename T>
class BiTree
{
private:
    BiNode<T> *root; // ָ�������ͷ���
    BiNode<T> *Creat(BiNode<T> *bt); // ���캯������
    BiNode<T> *CreatBT(const T preList[], const int size, int &index, const T end);
    void Release(BiNode<T> *bt);  // ������������
    void PreOrder(BiNode<T> *bt);  //ǰ�������������
    void InOrder(BiNode<T> *bt); // ���������������
    void PostOrder(BiNode<T> *bt); // ���������������
public:
    BiTree() { root = Creat(root); } // ���캯��
    BiTree(const T preList[], const int size, int index, const T end)
    { root = CreatBT(preList, size, index, end); } // ���캯��
    BiTree(const BiTree<T> &bt) = delete; //�������캯������
    ~BiTree() { Release(root); } //��������
    void PreOrder() { PreOrder(root); }      // �ݹ�ǰ�����������
    void InOrder() { InOrder(root); }        // �ݹ��������������
    void PostOrder() { PostOrder(root); }    // �ݹ�������������
    void LeverOrder();                       // �������������
};

template<typename T>
inline void BiTree<T>::LeverOrder()
{
    LinkQueue<BiNode<T>*> Q;  // ����һ������
    Q.initQueue();      // ��ʼ������
    if(root != nullptr) Q.enQueue(root);// ��ָ�����
    BiNode<T>* q = new BiNode<T>; //�ݴ���
    while (Q.deQueue(&q)) // ����
    {
        cout << q->data; // ��ʾ���
        if (q->lchild) Q.enQueue(q->lchild);// �������
        if (q->rchild) Q.enQueue(q->rchild);// �Һ������
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
    cin >> ch; // �������������Ϣ������Ϊ�ַ�
    if(ch == '#') bt = nullptr; // ����һ�ÿ���
    else
    {
        bt = new BiNode<T>;// ����һ����㣬������Ϊch
        bt->data = ch;
        bt->lchild = Creat(bt->lchild);// �ݹ齨��������
        bt->rchild = Creat(bt->rchild);// �ݹ齨��������
    }
    return bt;
}

template<typename T>
inline void BiTree<T>::Release(BiNode<T>* bt)
{
    if(bt)
    {
        Release(bt->lchild);// �ͷ�������
        Release(bt->rchild);// �ͷ�������
        delete bt;          // �ͷŸ��ڵ�
    }
}

template<typename T>
inline void BiTree<T>::PreOrder(BiNode<T>* bt)
{
    if (bt == nullptr) return;  // �ݹ���õĽ�������
    cout << bt->data;           // ���ʸ��ڵ�bt��������
    PreOrder(bt->lchild);       // ǰ��ݹ����bt��������
    PreOrder(bt->rchild);       // ǰ��ݹ����bt��������
}

template<typename T>
inline void BiTree<T>::InOrder(BiNode<T>* bt)
{
    if (bt == nullptr) return;  // �ݹ���õĽ�������
    InOrder(bt->lchild);        // ����ݹ����bt��������
    cout << bt->data;           // ���ʸ��ڵ�bt��������
    InOrder(bt->rchild);        // ����ݹ����bt��������
}

template<typename T>
inline void BiTree<T>::PostOrder(BiNode<T>* bt)
{
    if (bt == nullptr) return;  // �ݹ���õĽ�������
    PostOrder(bt->lchild);      // ����ݹ����bt��������
    PostOrder(bt->rchild);      // ����ݹ����bt��������
    cout << bt->data;           // ���ʸ��ڵ�bt��������
}
