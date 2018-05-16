#include "CircleList.h"

// ���е���ʽ�洢�ṹ
template <typename ElemType> // ģ��
class LinkQueue: virtual private CircleList<ElemType>
{
public:
    void initQueue(); // ��ʼ������
    bool isEmpty() const; // ��д�пպ���
    void destroyQueue(); // ɾ������
    bool deQueue(ElemType *e); // ���Ӳ���
    void enQueue(const ElemType &e); //��Ӳ���
    bool getHead(ElemType *e); // ��ȡ����Ԫ��
    int count() const; // ���г���
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const LinkQueue<S> &LK); // �������<<
};
// ��ʼ������
template <typename ElemType>
void LinkQueue<ElemType>::initQueue()
{
    CircleList<ElemType>::clearCircList();
}
// ��д�пպ���
template <typename ElemType>
bool LinkQueue<ElemType>::isEmpty() const
{
    return CircleList<ElemType>::isEmpty();
}
// ɾ������
template <typename ElemType>
void LinkQueue<ElemType>::destroyQueue()
{
    CircleList<ElemType>::clearCircList();
}
// ���Ӳ���
template <typename ElemType>
bool LinkQueue<ElemType>::deQueue(ElemType *e)
{
    return CircleList<ElemType>::pophead(e);
}
//��Ӳ���
template <typename ElemType>
void LinkQueue<ElemType>::enQueue(const ElemType &e)
{
    CircleList<ElemType>::append(e);
}
// ��ȡ����Ԫ��
template <typename ElemType>
bool LinkQueue<ElemType>::getHead(ElemType *e)
{
    return CircleList<ElemType>::GetHeadElem(e);
}
// ���г���
template <typename ElemType>
int LinkQueue<ElemType>::count() const
{
    return CircleList<ElemType>::Length();
}

// �������<<
template <typename ElemType>
std::ostream &operator<<(std::ostream &os, const LinkQueue<ElemType> &LK)
{
    int len=LK.count();
    ElemType *p = new ElemType;
    for (int i = 0; i < len; ++i)
    {
        if (LK.GetElem(i, p))
            os << *p << " ";
    }
    delete p;
    return os;
}
