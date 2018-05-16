#include <iostream>

// ���ڵ㶨��
template <typename ElemType>
struct NODE
{
    ElemType data;
    struct NODE *next;
};

// ����
template <typename ElemType> // ģ��
class LinkList
{
private:
    NODE<ElemType> *head;
    inline void deepCopy(const LinkList<ElemType> &original); // ��ȸ���
public:
    LinkList():head(nullptr){} // ���캯��
    LinkList(const LinkList<ElemType> &LK);// �������캯��
    ~LinkList(); // ��������
    void clearSqList(); // ��պ���
    bool isEmpty() const{ return head == nullptr; } // �пպ���
    int Length() const;  // ��ȡ������
    bool GetElem(int i, ElemType *e) const; // ��ȡԪ��
    int LocateElem(const ElemType &e) const; // ����Ԫ��λ��
    bool RemoveElem(ElemType &e); //�Ƴ�ָ��Ԫ��
    bool Replace(const int i, const ElemType &e); // �滻i��Ԫ��
    bool PriorElem(ElemType cur_e, ElemType *pre_e) const; // ȡ��һ��Ԫ��
    bool NextElem(ElemType cur_e, ElemType *next_e) const; // ȡ��һ��Ԫ��
    bool Insert(const int i, const ElemType &e); // ָ��λ�ò���
    bool append(const ElemType &e); // ĩβ����
    void InsertHead(const ElemType &e); // ͷ������
    bool Delete(int i, ElemType *e); // ɾ��ָ��λ�õ�Ԫ��
    bool popback(ElemType *e); // ĩβɾ��
    bool pophead(ElemType *e); // ͷ��ɾ��
    NODE<ElemType> *Reverse(); // ��תһ������
    LinkList<ElemType> &operator=(const LinkList<ElemType> &s) //����=
    { deepCopy(s); return *this; }
    bool operator==(const LinkList<ElemType> &s); // �ж����������Ƿ����
    bool operator!=(const LinkList<ElemType> &s); // �ж����������Ƿ����
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const LinkList<S> &LK); // �������<<
};
// ��ȸ���
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
        copyptr->next = new NODE<ElemType>;  //��һ���ǹؼ�
        originalptr = originalptr->next;
        copyptr = copyptr->next;
        copyptr->data = originalptr->data;
    }
    copyptr->next = nullptr;

}
// �������캯��
template <typename ElemType>
LinkList<ElemType>::LinkList(const LinkList<ElemType> &original)
{
    deepCopy(original);
}
// ��������
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
// ��պ���
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
// ��ȡ������
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
// ��ȡԪ��
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
// �滻i��Ԫ��
template <typename ElemType>
bool LinkList<ElemType>::Replace(const int i, const ElemType &e)
{
    if(head == nullptr) return false; //��
    if(i == 0) // ��һ���ڵ�
    {
        head->data = e;
        return true;
    }
    NODE<ElemType> *p = head;
    int j = 0;
    while (p->next && j < i-1) // ǰһ���ڵ��³�
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
// ����Ԫ��λ��
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
    std::cout << "���в�����ָ����Ԫ��" << std::endl;
    return -1;
}
//�Ƴ�ָ��Ԫ��
template <typename ElemType>
bool LinkList<ElemType>::RemoveElem(ElemType &e)
{
    if(head == nullptr) // ������
        return false;
    NODE<ElemType> *p = head;
    if(head->data == e) // ��һ��ƥ��
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
// ȡ��һ��Ԫ��
template <typename ElemType>
bool LinkList<ElemType>::PriorElem(ElemType cur_e, ElemType *pre_e) const
{
    NODE<ElemType> *p = head;
    if (p->data == cur_e) return false; // ͷ���
    while (p->next != nullptr)
    {
        if (p->next->data == cur_e)
        {
            *pre_e = p->data;
            return true;
        }
        else p = p->next;
    }
    return false; // �����겻���ڻ���ֻ��һ��ͷ���
}
// ȡ��һ��Ԫ��
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
    return false; // �����겻���ڻ���ֻ��һ��ͷ���
}
// ָ��λ�ò���
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
    if (p == nullptr) return false; //����β
    s = (NODE<ElemType> *) new NODE<ElemType>[1];
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}
// ĩβ����
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
// ͷ������
template <typename ElemType>
void LinkList<ElemType>::InsertHead(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = head;
    head = s;
}
// ɾ��ָ��λ�õ�Ԫ��
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
// ĩβɾ��
template <typename ElemType>
bool LinkList<ElemType>::popback(ElemType *e)
{
    return Delete(Length()-1, e);
}
// ͷ��ɾ��
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
// ��תһ������
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

// �ж����������Ƿ����
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
// �ж����������Ƿ����
template <typename ElemType>
bool LinkList<ElemType>::operator!=(const LinkList<ElemType> &s)
{
    return !(*this == s);
}

// �������<<
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
