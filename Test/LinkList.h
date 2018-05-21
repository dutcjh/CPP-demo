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
class LinkList
{
private:
    NODE<ElemType> *head;
    inline void deepCopy(const LinkList<ElemType> &original); // 深度复制
public:
    LinkList():head(nullptr){} // 构造函数
    LinkList(const LinkList<ElemType> &LK);// 拷贝构造函数
    ~LinkList(); // 析构函数
    void clearSqList(); // 清空函数
    bool isEmpty() const{ return head == nullptr; } // 判空函数
    int Length() const;  // 获取链表长度
    bool GetElem(int i, ElemType *e) const; // 获取元素
    int LocateElem(const ElemType &e) const; // 查找元素位置
    bool RemoveElem(ElemType &e); //移除指定元素
    bool Replace(const int i, const ElemType &e); // 替换i出元素
    bool PriorElem(ElemType cur_e, ElemType *pre_e) const; // 取上一个元素
    bool NextElem(ElemType cur_e, ElemType *next_e) const; // 取下一个元素
    bool Insert(const int i, const ElemType &e); // 指定位置插入
    bool append(const ElemType &e); // 末尾插入
    void InsertHead(const ElemType &e); // 头部插入
    bool Delete(int i, ElemType *e); // 删除指定位置的元素
    bool popback(ElemType *e); // 末尾删除
    bool pophead(ElemType *e); // 头部删除
    NODE<ElemType> *Reverse(); // 反转一个链表
    LinkList<ElemType> &operator=(const LinkList<ElemType> &s) //重载=
    { deepCopy(s); return *this; }
    bool operator==(const LinkList<ElemType> &s); // 判断两个序列是否相等
    bool operator!=(const LinkList<ElemType> &s); // 判断两个序列是否不相等
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const LinkList<S> &LK); // 重载输出<<
};
// 深度复制
template <typename ElemType>
void LinkList<ElemType>::deepCopy(const LinkList<ElemType> &original)
{
    head = nullptr;
    if(original.head == nullptr)
        return;
    NODE<ElemType> *copyptr = head = new NODE<ElemType>;
    NODE<ElemType> *originalptr = original.head;
    copyptr->data = originalptr->data;
    while(originalptr->next  != nullptr)
    {
        copyptr->next = new NODE<ElemType>;  //这一句是关键
        originalptr = originalptr->next;
        copyptr = copyptr->next;
        copyptr->data = originalptr->data;
    }
    copyptr->next = nullptr;

}
// 拷贝构造函数
template <typename ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &original)
{
    deepCopy(original);
}
// 析构函数
template <typename ElemType>
LinkList<ElemType>::~LinkList()
{
    NODE<ElemType> *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
// 清空函数
template <typename ElemType>
void LinkList<ElemType>::clearSqList()
{
    NODE<ElemType> *p = head;
    while (head)
    {
        p = head;
        head = head->next;
        delete(p);
    }
}
// 获取链表长度
template <typename ElemType>
int LinkList<ElemType>::Length() const
{
    NODE<ElemType> *p = head;
    int len = 0;
    while (p != nullptr)
    {
        len++;
        p = p->next;
    }
    return len;
}
// 获取元素
template <typename ElemType>
bool LinkList<ElemType>::GetElem(int i, ElemType *e) const
{
    NODE<ElemType> *p = head;
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
// 替换i处元素
template <typename ElemType>
bool LinkList<ElemType>::Replace(const int i, const ElemType &e)
{
    if(head == nullptr) return false; //空
    if(i == 0) // 第一个节点
    {
        head->data = e;
        return true;
    }
    NODE<ElemType> *p = head;
    int j = 0;
    while (p->next && j < i-1) // 前一个节点下车
    {
        p = p->next;
        j++;
    }
    if (p->next == nullptr) return false;
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = p->next->next;
    p->next  = s;
    return true;
}
// 查找元素位置
template <typename ElemType>
int LinkList<ElemType>::LocateElem(const ElemType &e) const
{
    int i = 0;
    NODE<ElemType> *p = head;
    while (p!=nullptr)
    {
        if (p->data == e) return i;
        else p = p->next;
        i++;
    }
    std::cout << "表中不存在指定的元素" << std::endl;
    return -1;
}
//移除指定元素
template <typename ElemType>
bool LinkList<ElemType>::RemoveElem(ElemType &e)
{
    if(head == nullptr) // 空链表
        return false;
    NODE<ElemType> *p = head;
    if(head->data == e) // 第一个匹配
    {
        e = head->data;
        head = p->next;
        delete p;
        return true;
    }
    while (p->next != nullptr)
    {
        if(p->next->data == e)
        {
            NODE<ElemType> *tempptr = p->next;
            e = tempptr->data;
            p->next = tempptr->next;
            delete tempptr;
            return true;
        }
        p = p->next;
    }
    return false;
}
// 取上一个元素
template <typename ElemType>
bool LinkList<ElemType>::PriorElem(ElemType cur_e, ElemType *pre_e) const
{
    NODE<ElemType> *p = head;
    if (p->data == cur_e) return false; // 头结点
    while (p->next != nullptr)
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
bool LinkList<ElemType>::NextElem(ElemType cur_e, ElemType *next_e) const
{
    NODE<ElemType> *p = head;
    if (head == nullptr || head->next == nullptr) return false;
    while (p->next != nullptr)
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
bool LinkList<ElemType>::Insert(const int i, const ElemType &e)
{
    NODE<ElemType> *p = head, *s;
    int j = 0;
    if (i == 0)
    {
        s = (NODE<ElemType> *) new NODE<ElemType>[1];
        s -> data = e;
        s -> next = p;
        head = s;
        return true;
    }
    while (p && j < i-1)
    {
        p = p->next;
        j++;
    }
    if (p == nullptr) return false; //到队尾
    s = (NODE<ElemType> *) new NODE<ElemType>[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// 末尾插入
template <typename ElemType>
bool LinkList<ElemType>::append(const ElemType &e)
{
    return Insert(Length(), e);
    /*
    NODE<ElemType> *p = head, *s;
    while(p->next)
    {
        p = p->next;
    }
    s = (NODE<ElemType> *) new NODE<ElemType>[1];
    s->data = e;
    p->next = s;*/
}
// 头部插入
template <typename ElemType>
void LinkList<ElemType>::InsertHead(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = head;
    head = s;
}
// 删除指点位置的元素
template <typename ElemType>
bool LinkList<ElemType>::Delete(int i, ElemType *e)
{
    NODE<ElemType> *p = head, *s;
    if (p == nullptr) return false;
    int j = 0;
    if (i==0)
    {
        head = head->next;
        *e = p->data;
        delete p;
        return true;
    }
    while (p && j < i-1)
    {
        j++;
        p = p->next;
    }
    if (p == nullptr) return false;
    s = p->next;
    p->next = p->next->next;
    *e = s->data;
    delete s;
    s = nullptr;
    return true;
}
// 末尾删除
template <typename ElemType>
bool LinkList<ElemType>::popback(ElemType *e)
{
    return Delete(Length()-1, e);
}
// 头部删除
template <typename ElemType>
bool LinkList<ElemType>::pophead(ElemType *e)
{
    NODE<ElemType> *p = head;
    if(p==nullptr) return false;
    head = head->next;
    *e = p->data;
    delete p;
    return true;
}
// 反转一个链表
template <typename ElemType>
NODE<ElemType>* LinkList<ElemType>::Reverse()
{
    if (head == nullptr || head->next == nullptr) return head;
    NODE<ElemType> *p = head, *q = head->next, *r;
    head->next = nullptr;
    while (q)
    {
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    head = p;
    return head;
}

// 判断两个序列是否相等
template <typename ElemType>
bool LinkList<ElemType>::operator==(const LinkList<ElemType> &s)
{
    if (Length() != s.Length()) return false;
    NODE<ElemType> *ptr = head, *qtr = s.head;
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
bool LinkList<ElemType>::operator!=(const LinkList<ElemType> &s)
{
    return !(*this == s);
}

// 重载输出<<
template <typename ElemType>
std::ostream &operator<<(std::ostream &os, const LinkList<ElemType> &LK)
{
    NODE<ElemType> *p = LK.head;
    while (p)
    {
        os << p->data << " ";
        p = p->next;
    }
    return os;
}
