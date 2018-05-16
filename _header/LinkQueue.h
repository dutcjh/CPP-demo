#include "CircleList.h"

// ���е���ʽ�洢�ṹ
template <typename ElemType> // ģ��
class LinkQueue: public CircleList<ElemType>
{
public:
    void initQueue(); // ��ʼ������
    bool isEmpty() const; // ��д�пպ���
    void destroyQueue(); // ɾ������
    bool deQueue(ElemType *e); // ���Ӳ���
    void enQueue(const ElemType &e); //��Ӳ���
    bool getHead(ElemType *e); // ��ȡ����Ԫ��
    int count() const; // ���г���
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
