#include "CircleList.h"

// 队列的链式存储结构
template <typename ElemType> // 模板
class LinkQueue: public CircleList<ElemType>
{
public:
    void initQueue(); // 初始化队列
    bool isEmpty() const; // 重写判空函数
    void destroyQueue(); // 删除队列
    bool deQueue(ElemType *e); // 出队操作
    void enQueue(const ElemType &e); //入队操作
    bool getHead(ElemType *e); // 获取队首元素
    int count() const; // 队列长度
};
// 初始化队列
template <typename ElemType>
void LinkQueue<ElemType>::initQueue()
{
    CircleList<ElemType>::clearCircList();
}
// 重写判空函数
template <typename ElemType>
bool LinkQueue<ElemType>::isEmpty() const
{
    return CircleList<ElemType>::isEmpty();
}
// 删除队列
template <typename ElemType>
void LinkQueue<ElemType>::destroyQueue()
{
    CircleList<ElemType>::clearCircList();
}
// 出队操作
template <typename ElemType>
bool LinkQueue<ElemType>::deQueue(ElemType *e)
{
    return CircleList<ElemType>::pophead(e);
}
//入队操作
template <typename ElemType>
void LinkQueue<ElemType>::enQueue(const ElemType &e)
{
    CircleList<ElemType>::append(e);
}
// 获取队首元素
template <typename ElemType>
bool LinkQueue<ElemType>::getHead(ElemType *e)
{
    return CircleList<ElemType>::GetHeadElem(e);
}
// 队列长度
template <typename ElemType>
int LinkQueue<ElemType>::count() const
{
    return CircleList<ElemType>::Length();
}
