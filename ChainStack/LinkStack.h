#include "LinkList.h"

// ��ջ
template <typename ElemType> // ģ��
class LinkStack : public LinkList<ElemType>
{
public:
    void initStack(); // ��ʼ��ջ
    bool isEmpty() const;
    void destroyStack();
    bool pop(ElemType *e);
    void push(const ElemType &e);
    bool top(ElemType *e);
    int count() const;
};

template <typename ElemType>
void LinkStack<ElemType>::initStack()
{
    LinkList<ElemType>::clearSqList();
}

template <typename ElemType>
bool LinkStack<ElemType>::isEmpty() const
{
    return LinkList<ElemType>::isEmpty();
}

template <typename ElemType>
void LinkStack<ElemType>::destroyStack()
{
    LinkList<ElemType>::clearSqList();
}

template <typename ElemType>
bool LinkStack<ElemType>::pop(ElemType *e)
{
    return LinkList<ElemType>::pophead(e);
}

template <typename ElemType>
void LinkStack<ElemType>::push(const ElemType &e)
{
    LinkList<ElemType>::InsertHead(e);
}

template <typename ElemType>
int LinkStack<ElemType>::count() const
{
    return LinkList<ElemType>::Length();
}

