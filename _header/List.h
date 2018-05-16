/*****************************************************
                单链表模板类
代码说明：含附加头结点和尾结点的单链表模板类
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

// 链表
template <typename ElemType> // 模板
class List
{
private:
    NODE<ElemType> *head, *tail;
    inline void deepCopy(const List<ElemType> &original); // 深度复制
public:
    List(); // 构造函数
    List(const List<ElemType> &LK);// 拷贝构造函数
    ~List(); // 析构函数
    void clearList(); // 清空函数
    bool isEmpty() const{ return head.next == nullptr; } // 判空函数
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
    List<ElemType> &operator=(const List<ElemType> &s) //重载=
    { deepCopy(s); return *this; }
    bool operator==(const List<ElemType> &s); // 判断两个序列是否相等
    bool operator!=(const List<ElemType> &s); // 判断两个序列是否不相等
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const List<S> &LK); // 重载输出<<
};
// 构造函数
template <typename ElemType>
List<ElemType>::List()
{
    head = (NODE<ElemType> *) new NODE<ElemType>();
    head->next = nullptr; // a1 为空
    tail = head;
}
// 深度复制
template <typename ElemType>
void List<ElemType>::deepCopy(const List<ElemType> &original)
{
    NODE<ElemType> *copyptr = head = new NODE<ElemType>;
    NODE<ElemType> *originalptr = original.head;
    while(originalptr->next)
    {
        copyptr->next = new NODE<ElemType>;  //这一句是关键
        originalptr = originalptr->next;
        copyptr = copyptr->next;
        copyptr->data = originalptr->data;
    }
    copyptr->next = nullptr;
    tail = copyptr; // 尾节点
}
// 拷贝构造函数
template <typename ElemType>
List<ElemType>::List(const List<ElemType> &original)
{
    deepCopy(original);
}
// 析构函数
template <typename ElemType>
List<ElemType>::~List()
{
    clearList();
//    NODE<ElemType> *p = head;
//    while (head)
//    {
//        p = head;
//        head = head->next;
//        delete(p);
//    }
//    tail = head;
}
// 清空函数
template <typename ElemType>
void List<ElemType>::clearList()
{
    NODE<ElemType> *p;
    while (head->next)
    {
        p = head->next;
        head->next = p->next;
        delete(p);
    }
    tail = head;
}
// 获取链表长度
template <typename ElemType>
int List<ElemType>::Length() const
{
    NODE<ElemType> *p = head->next;
    int len = 0;
    while (p)
    {
        len++;
        p = p->next;
    }
    return len;
}
// 获取元素
template <typename ElemType>
bool List<ElemType>::GetElem(int i, ElemType *e) const
{
    NODE<ElemType> *p = head->next;
    int j = 0;
    while (p && j<i)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr) return false;
    *e = p->data;
    return true;
}
// 获取尾节点元素
template <typename ElemType>
bool List<ElemType>::GetTailElem(ElemType *e) const
{
    if(head == tail) return false;
    *e = tail->data;
    return true;
}
// 获取头节点元素
template <typename ElemType>
bool List<ElemType>::GetHeadElem(ElemType *e) const
{
    if(head == tail) return false;
    *e = head->next->data;
    return true;
}
// 替换i处元素
template <typename ElemType>
bool List<ElemType>::Replace(const int i, const ElemType &e)
{
    NODE<ElemType> *p = head->next;
    int j = 0;
    while(p && j<i)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr) return false;
    p->data = e; //替换
    return true;
}
// 查找元素位置
template <typename ElemType>
int List<ElemType>::LocateElem(const ElemType &e) const
{
    NODE<ElemType> *p = head->next;
    int i = 0;
    while(p)
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
bool List<ElemType>::RemoveElem(ElemType &e)
{
    NODE<ElemType> *p = head->next, *p0 = head;
    while(p)
    {
        if(p->data == e) //找到这个元素
        {
            p0->next = p->next; // 完成删除
            if(p == tail) //如果删除了尾节点
                tail = p0;
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
bool List<ElemType>::PriorElem(ElemType cur_e, ElemType *pre_e) const
{
    NODE<ElemType> *p = head->next;
    if (p->data == cur_e) return false; // 头结点
    while (p->next)
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
bool List<ElemType>::NextElem(ElemType cur_e, ElemType *next_e) const
{
    NODE<ElemType> *p = head->next;
    while (p && p->next)
    {
        if (p->data == cur_e)
        {
            *next_e = p->next->data;
            return true;
        }
        else p = p->next;
    }
    return false; // 遍历完不存在或者只有一个头结点
}
// 指定位置插入
template <typename ElemType>
bool List<ElemType>::Insert(const int i, const ElemType &e)
{
    NODE<ElemType> *p = head, *s;
    int j = 0;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr) return false; //到队尾
    s = (NODE<ElemType> *) new NODE<ElemType>;
    s->data = e;
    s->next = p->next;
    p->next = s;
    if(p == tail) // 最后插入
        tail = s;
    return true;
}
// 末尾插入
template <typename ElemType>
void List<ElemType>::append(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = nullptr;
    tail->next = s;
    tail = s;
}
// 头部插入
template <typename ElemType>
void List<ElemType>::InsertHead(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = head->next;
    head->next = s;
    if(tail == head) // 空表头插
        tail = s;
}
// 删除指点位置的元素
template <typename ElemType>
bool List<ElemType>::Delete(int i, ElemType *e)
{
    NODE<ElemType> *p = head->next, *p0 = head;
    int j = 0;
    while (p && j < i)
    {
        p0 = p;
        p = p->next;
        j++;
    }
    if (p == nullptr) return false;
    p0->next = p->next;
    *e = p->data;
    if(p == tail) //删除了尾节点
        tail = p0;
    delete p;
    return true;
}
// 末尾删除
template <typename ElemType>
bool List<ElemType>::popback(ElemType *e)
{
    if(head == tail) return false; //空表
    NODE<ElemType> *p = head, *s;
    while (p->next->next)
        p = p->next;
    s = tail; // 被删量
    *e = s->data;
    p->next = nullptr;
    tail = p;
    delete s;
    return true;
}
// 头部删除
template <typename ElemType>
bool List<ElemType>::pophead(ElemType *e)
{
    if(head == tail) return false; //空表
    NODE<ElemType> *p = head->next;
    head->next = p->next;
    *e = p->data;
    if (p == tail) //单元素表删除
        tail = head;
    delete p;
    return true;
}
// 反转一个链表
template <typename ElemType>
NODE<ElemType>* List<ElemType>::Reverse()
{
    if (head->next == nullptr) return head; // 空表
    NODE<ElemType> *p = head->next, *q = head->next->next, *r;
    p->next = nullptr; // a1.next = null
    while (q)
    {
        r = q->next; // a3 null
        q->next = p; // a2.next = a1
        p = q;  //  p: a1->a2
        q = r; // q: a2->a3 null
    }
    tail = head->next; // a1
    head->next = p; //  a2
    return head;
}
// 判断两个序列是否相等
template <typename ElemType>
bool List<ElemType>::operator==(const List<ElemType> &s)
{
    if (Length() != s.Length()) return false; // 长度不等
    NODE<ElemType> *ptr = head->next, *qtr = s.head->next;
    if(ptr == nullptr && qtr == nullptr) return true;
    if (ptr->data != qtr->data) return false;
    while(ptr->next)
    {
        if(ptr->data != qtr->data)
            return false;
        ptr = ptr->next;
        qtr = qtr->next;
    }
    return true;
}
// 判断两个序列是否不相等
template <typename ElemType>
bool List<ElemType>::operator!=(const List<ElemType> &s)
{
    return !(*this == s);
}
// 重载输出<<
template <typename ElemType>
std::ostream &operator<<(std::ostream &os, const List<ElemType> &LK)
{
    NODE<ElemType> *p = LK.head->next;
    while (p)
    {
        os << p->data << " ";
        p = p->next;
    }
    return os;
}
