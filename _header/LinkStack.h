#include "LinkList.h"

// Á´Õ»
template <typename ElemType> // Ä£°å
class LinkStack : virtual private LinkList<ElemType>
{
public:
    void initStack(); // ³õÊ¼»¯Õ»
    bool isEmpty() const;
    void destroyStack();
    bool pop(ElemType *e);
    void push(const ElemType &e);
    bool top(ElemType *e);
    int count() const;
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const LinkStack<S> &LK); // 重载输出<<
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
bool LinkStack<ElemType>::top(ElemType *e)
{
    return LinkList<ElemType>::GetElem(0, e);
}

template <typename ElemType>
int LinkStack<ElemType>::count() const
{
    return LinkList<ElemType>::Length();
}

// 重载输出<<
template <typename ElemType>
std::ostream &operator<<(std::ostream &os, const LinkStack<ElemType> &LK)
{
    int len = LK.Length();
    ElemType *p = new ElemType;

    for(int i=0; i<len;++i)
    {
        if(LK.GetElem(i, p));
        os << *p << " ";
    }
    delete p;
    return os;
}
