/*****************************************************
                循环链表模板类
代码说明：含尾结点的循环链表模板类，不含头指针
作    者：一水之间
日    期：v1.0  2018-4-6
*****************************************************/
#include <iostream>

// 单节点定义
template <typename ElemType>
struct NODE
{
    ElemType data;
    struct NODE *next;
};

// 循环链表
template <typename ElemType> // 模板
class CircleList
{
private:
    NODE<ElemType> *rear; //尾指针
    inline void deepCopy(const CircleList<ElemType> &original); // 深度复制
public:
    CircleList(); // 构造函数
    CircleList(const CircleList<ElemType> &LK);// 拷贝构造函数
    ~CircleList(); // 析构函数
    void clearCircList(); // 清空函数
    bool isEmpty() const{ return rear->next == rear; } // 判空函数
    int Length() const;  // 获取链表长度
    bool GetElem(int i, ElemType *e) const; // 获取元素
    bool GetTailElem(ElemType *e) const; // 获取尾节点元素
    bool GetHeadElem(ElemType *e) const; // 获取头节点元素
    int LocateElem(const ElemType &e) const; // 查找元素位置
    bool RemoveElem(ElemType &e); //移除指定元素
    bool Replace(const int i, const ElemType &e); // 替换i处元素
    bool PriorElem(ElemType cur_e, ElemType *pre_e) const; // 取上一个元素
    bool NextElem(ElemType cur_e, ElemType *next_e) const; // 取下一个元素
    bool Insert(const int i, const ElemType &e); // 指定位置插入
    void append(const ElemType &e); // 末尾插入
    void InsertHead(const ElemType &e); // 头部插入
    bool Delete(int i, ElemType *e); // 删除指定位置的元素
    bool popback(ElemType *e); // 末尾删除
    bool pophead(ElemType *e); // 头部删除
    NODE<ElemType> *Reverse(); // 反转一个链表
    CircleList<ElemType> &operator=(const CircleList<ElemType> &s) //重载=
    { deepCopy(s); return *this; }
    bool operator==(const CircleList<ElemType> &s); // 判断两个序列是否相等
    bool operator!=(const CircleList<ElemType> &s); // 判断两个序列是否不相等
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const CircleList<S> &LK); // 重载输出<<
};
// 构造函数
template <typename ElemType>
CircleList<ElemType>::CircleList()
{
    rear = (NODE<ElemType> *) new NODE<ElemType>();
    rear->next = rear; // 指向自己
}
// 深度复制
template <typename ElemType>
void CircleList<ElemType>::deepCopy(const CircleList<ElemType> &original)
{
    rear = new NODE<ElemType>;
    rear->next = rear;
    NODE<ElemType> *copyptr = rear->next; // 头节点
    NODE<ElemType> *originalptr = original.rear->next; // 头节点
    while(originalptr != original.rear) // 没有到尾节点
    {
        copyptr->next = new NODE<ElemType>;  //这一句是关键 a1
        originalptr = originalptr->next; // b1
        copyptr = copyptr->next; // a1
        copyptr->data = originalptr->data; // a1 = b1
    }
    copyptr->next = rear; // 尾节点指向头节点
    rear = copyptr; // 头节点变成尾节点
}
// 拷贝构造函数
template <typename ElemType>
CircleList<ElemType>::CircleList(const CircleList<ElemType> &original)
{
    deepCopy(original);
}
// 析构函数
template <typename ElemType>
CircleList<ElemType>::~CircleList()
{
    clearCircList();
}
// 清空函数
template <typename ElemType>
void CircleList<ElemType>::clearCircList()
{
    NODE<ElemType> *head = rear->next, *p;
    while (head != rear)
    {
        p = head->next; // a1
        head->next = p->next; // a2
        if (p == rear)
            rear = head;
        delete(p); // 销毁a1
    }
}
// 获取链表长度
template <typename ElemType>
int CircleList<ElemType>::Length() const
{
    NODE<ElemType> *p = rear->next->next; // a0
    int len = 0;
    while (p != (rear->next))
    {
        len++;
        p = p->next;
    }
    return len;
}
// 获取元素
template <typename ElemType>
bool CircleList<ElemType>::GetElem(int i, ElemType *e) const
{
    NODE<ElemType> *p = rear->next->next; // a0
    int j = 0;
    while ((p != rear->next) && j<i)
    {
        p = p->next;
        j++;
    }
    if (p == rear->next) return false; // 回到了头节点
    *e = p->data;
    return true;
}
// 获取尾节点元素
template <typename ElemType>
bool CircleList<ElemType>::GetTailElem(ElemType *e) const
{
    if(rear->next == rear) return false; // 空表
    *e = rear->data;
    return true;
}
// 获取头节点元素
template <typename ElemType>
bool CircleList<ElemType>::GetHeadElem(ElemType *e) const
{
    if(rear->next == rear) return false; // 空表
    *e = rear->next->next->data;
    return true;
}
// 替换i处元素
template <typename ElemType>
bool CircleList<ElemType>::Replace(const int i, const ElemType &e)
{
    NODE<ElemType> *p = rear->next->next; // a0
    int j = 0;
    while ((p != rear->next) && j<i)
    {
        p = p->next;
        j++;
    }
    if (p == rear->next) return false; // 回到了头节点
    p->data = e; //替换
    return true;
}
// 查找元素位置
template <typename ElemType>
int CircleList<ElemType>::LocateElem(const ElemType &e) const
{
    NODE<ElemType> *p = rear->next->next; // a0
    int i = 0;
    while(p != rear->next)
    {
        if (p->data == e) return i;
        else p = p->next;
        i++;
    }
    std::cout << "ERROR: 表中不存在指定的元素" << std::endl;
    return -1;
}
//移除指定元素
template <typename ElemType>
bool CircleList<ElemType>::RemoveElem(ElemType &e)
{
    NODE<ElemType> *p = rear->next->next, *p0 = rear->next;
    while(p != rear->next)
    {
        if(p->data == e) //找到这个元素
        {
            p0->next = p->next; // 完成删除
            if(p == rear) //如果删除了尾节点
                rear = p0;
            delete(p);
            return true;
        }
        else
        {
            p0 = p; // 保存上一个节点
            p = p->next;
        }
    }
    return false;
}
// 取上一个元素
template <typename ElemType>
bool CircleList<ElemType>::PriorElem(ElemType cur_e, ElemType *pre_e) const
{
    NODE<ElemType> *p = rear->next->next;
    if (rear->next == rear) return false; // 空表
    if (p->data == cur_e) // a0
    {
        *pre_e = rear->data; // an
        return true;
    }
    while (p->next != rear->next) // a1
    {
        if (p->next->data == cur_e)
        {
            *pre_e = p->data;
            return true;
        }
        else p = p->next;
    }
    return false; // 遍历完不存在或者只有一个头结点
}
// 取下一个元素
template <typename ElemType>
bool CircleList<ElemType>::NextElem(ElemType cur_e, ElemType *next_e) const
{
    NODE<ElemType> *p = rear->next->next; // a0
    while (p != rear->next)
    {
        if (p->data == cur_e)
        {
            if (p != rear)
                *next_e = p->next->data;
            else
                *next_e = p->next->next->data; // a0
            return true;
        }
        else p = p->next;
    }
    return false; // 遍历完不存在或者只有一个头结点
}
// 指定位置插入
template <typename ElemType>
bool CircleList<ElemType>::Insert(const int i, const ElemType &e)
{
    NODE<ElemType> *q = rear->next, *s;
    int j = 0;
    while ((q != rear)  && j < i)
    {
        q = q->next;
        j++;
    }
    if (j < i) return false; //下标越界
    s = (NODE<ElemType> *) new NODE<ElemType>;
    s->data = e;
    if (q == rear) // 插到队尾
    {
        s->next = rear->next;
        rear->next = s;
        rear = s;
        return true;
    }
    s->next = q->next;
    q->next = s;
    return true;
}
// 末尾插入
template <typename ElemType>
void CircleList<ElemType>::append(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = rear->next;
    rear->next = s;
    rear = s;
}
// 头部插入
template <typename ElemType>
void CircleList<ElemType>::InsertHead(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = rear->next->next;
    if(rear==rear->next) // 空表头插
    {
        rear->next = s;
        rear = s;
    }
    else
        rear->next->next = s;
}
// 删除指点位置的元素
template <typename ElemType>
bool CircleList<ElemType>::Delete(int i, ElemType *e)
{
    NODE<ElemType> *p = rear->next->next, *p0 = rear->next;
    int j = 0;
    while ((p != rear->next) && j < i)
    {
        p0 = p;
        p = p->next;
        j++;
    }
    if (p == rear->next) return false;
    p0->next = p->next;
    *e = p->data;
    if(p == rear) //删除了尾节点
        rear = p0;
    delete p;
    return true;
}
// 末尾删除
template <typename ElemType>
bool CircleList<ElemType>::popback(ElemType *e)
{
    if(rear == rear->next) return false; //空表
    NODE<ElemType> *p = rear->next, *s;
    while (p->next->next != rear->next)
        p = p->next;
    s = rear; // 被删量
    *e = s->data;
    p->next = rear->next;
    rear = p;
    delete s;
    return true;
}
// 头部删除
template <typename ElemType>
bool CircleList<ElemType>::pophead(ElemType *e)
{
    if(rear == rear->next) return false; //空表
    NODE<ElemType> *p = rear->next->next;
    rear->next->next = p->next;
    *e = p->data;
    if (p == rear) //单元素表删除
        rear = rear->next;
    delete p;
    return true;
}
// 反转一个链表
template <typename ElemType>
NODE<ElemType>* CircleList<ElemType>::Reverse()
{
    if (rear == rear->next || Length()==1) return rear; // 空表或单一元素表
    NODE<ElemType> *p = rear->next->next, *q = p->next, *r;
    p->next = rear->next; // a1.next = head
    rear = p; // rear->a1
    while (q != rear->next)
    {
        r = q->next; // a3 head
        q->next = p; // a2.next = a1
        p = q;  //  p: a1->a2
        q = r; // q: a2->a3 null
    }
    q->next = p; //  a2
    return rear;
}
// 判断两个序列是否相等
template <typename ElemType>
bool CircleList<ElemType>::operator==(const CircleList<ElemType> &s)
{
    int L = Length();
    if (L != s.Length()) return false; // 长度不等
    NODE<ElemType> *ptr = rear->next->next, *qtr = s.rear->next->next;
    for(int i = 0; i<L; i++)
    {
        if(ptr->data != qtr->data) return false;
        ptr = ptr->next;
        qtr = qtr->next;
    }
    return true;
}
// 判断两个序列是否不相等
template <typename ElemType>
bool CircleList<ElemType>::operator!=(const CircleList<ElemType> &s)
{
    return !(*this == s);
}
// 重载输出<<
template <typename ElemType>
std::ostream &operator<<(std::ostream &os, const CircleList<ElemType> &LK)
{
    NODE<ElemType> *p = LK.rear->next->next; //a0
    while (p != LK.rear->next)
    {
        os << p->data << " ";
        p = p->next;
    }
    return os;
}

