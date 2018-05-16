/*****************************************************
                ������ģ����
����˵����������ͷ����β���ĵ�����ģ����
��    �ߣ�һˮ֮��
��    �ڣ�v1.0  2018-4-6
*****************************************************/
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
class List
{
private:
    NODE<ElemType> *head, *tail;
    inline void deepCopy(const List<ElemType> &original); // ��ȸ���
public:
    List(); // ���캯��
    List(const List<ElemType> &LK);// �������캯��
    ~List(); // ��������
    void clearList(); // ��պ���
    bool isEmpty() const{ return head.next == nullptr; } // �пպ���
    int Length() const;  // ��ȡ������
    bool GetElem(int i, ElemType *e) const; // ��ȡԪ��
    bool GetTailElem(ElemType *e) const; // ��ȡβ�ڵ�Ԫ��
    bool GetHeadElem(ElemType *e) const; // ��ȡͷ�ڵ�Ԫ��
    int LocateElem(const ElemType &e) const; // ����Ԫ��λ��
    bool RemoveElem(ElemType &e); //�Ƴ�ָ��Ԫ��
    bool Replace(const int i, const ElemType &e); // �滻i��Ԫ��
    bool PriorElem(ElemType cur_e, ElemType *pre_e) const; // ȡ��һ��Ԫ��
    bool NextElem(ElemType cur_e, ElemType *next_e) const; // ȡ��һ��Ԫ��
    bool Insert(const int i, const ElemType &e); // ָ��λ�ò���
    void append(const ElemType &e); // ĩβ����
    void InsertHead(const ElemType &e); // ͷ������
    bool Delete(int i, ElemType *e); // ɾ��ָ��λ�õ�Ԫ��
    bool popback(ElemType *e); // ĩβɾ��
    bool pophead(ElemType *e); // ͷ��ɾ��
    NODE<ElemType> *Reverse(); // ��תһ������
    List<ElemType> &operator=(const List<ElemType> &s) //����=
    { deepCopy(s); return *this; }
    bool operator==(const List<ElemType> &s); // �ж����������Ƿ����
    bool operator!=(const List<ElemType> &s); // �ж����������Ƿ����
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const List<S> &LK); // �������<<
};
// ���캯��
template <typename ElemType>
List<ElemType>::List()
{
    head = (NODE<ElemType> *) new NODE<ElemType>();
    head->next = nullptr; // a1 Ϊ��
    tail = head;
}
// ��ȸ���
template <typename ElemType>
void List<ElemType>::deepCopy(const List<ElemType> &original)
{
    NODE<ElemType> *copyptr = head = new NODE<ElemType>;
    NODE<ElemType> *originalptr = original.head;
    while(originalptr->next)
    {
        copyptr->next = new NODE<ElemType>;  //��һ���ǹؼ�
        originalptr = originalptr->next;
        copyptr = copyptr->next;
        copyptr->data = originalptr->data;
    }
    copyptr->next = nullptr;
    tail = copyptr; // β�ڵ�
}
// �������캯��
template <typename ElemType>
List<ElemType>::List(const List<ElemType> &original)
{
    deepCopy(original);
}
// ��������
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
// ��պ���
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
// ��ȡ������
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
// ��ȡԪ��
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
// ��ȡβ�ڵ�Ԫ��
template <typename ElemType>
bool List<ElemType>::GetTailElem(ElemType *e) const
{
    if(head == tail) return false;
    *e = tail->data;
    return true;
}
// ��ȡͷ�ڵ�Ԫ��
template <typename ElemType>
bool List<ElemType>::GetHeadElem(ElemType *e) const
{
    if(head == tail) return false;
    *e = head->next->data;
    return true;
}
// �滻i��Ԫ��
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
    p->data = e; //�滻
    return true;
}
// ����Ԫ��λ��
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
    std::cout << "ERROR: ���в�����ָ����Ԫ��" << std::endl;
    return -1;
}
//�Ƴ�ָ��Ԫ��
template <typename ElemType>
bool List<ElemType>::RemoveElem(ElemType &e)
{
    NODE<ElemType> *p = head->next, *p0 = head;
    while(p)
    {
        if(p->data == e) //�ҵ����Ԫ��
        {
            p0->next = p->next; // ���ɾ��
            if(p == tail) //���ɾ����β�ڵ�
                tail = p0;
            delete(p);
            return true;
        }
        else
        {
            p0 = p; // ������һ���ڵ�
            p = p->next;
        }
    }
    return false;
}
// ȡ��һ��Ԫ��
template <typename ElemType>
bool List<ElemType>::PriorElem(ElemType cur_e, ElemType *pre_e) const
{
    NODE<ElemType> *p = head->next;
    if (p->data == cur_e) return false; // ͷ���
    while (p->next)
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
    return false; // �����겻���ڻ���ֻ��һ��ͷ���
}
// ָ��λ�ò���
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
    if (p == nullptr) return false; //����β
    s = (NODE<ElemType> *) new NODE<ElemType>;
    s->data = e;
    s->next = p->next;
    p->next = s;
    if(p == tail) // ������
        tail = s;
    return true;
}
// ĩβ����
template <typename ElemType>
void List<ElemType>::append(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = nullptr;
    tail->next = s;
    tail = s;
}
// ͷ������
template <typename ElemType>
void List<ElemType>::InsertHead(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = head->next;
    head->next = s;
    if(tail == head) // �ձ�ͷ��
        tail = s;
}
// ɾ��ָ��λ�õ�Ԫ��
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
    if(p == tail) //ɾ����β�ڵ�
        tail = p0;
    delete p;
    return true;
}
// ĩβɾ��
template <typename ElemType>
bool List<ElemType>::popback(ElemType *e)
{
    if(head == tail) return false; //�ձ�
    NODE<ElemType> *p = head, *s;
    while (p->next->next)
        p = p->next;
    s = tail; // ��ɾ��
    *e = s->data;
    p->next = nullptr;
    tail = p;
    delete s;
    return true;
}
// ͷ��ɾ��
template <typename ElemType>
bool List<ElemType>::pophead(ElemType *e)
{
    if(head == tail) return false; //�ձ�
    NODE<ElemType> *p = head->next;
    head->next = p->next;
    *e = p->data;
    if (p == tail) //��Ԫ�ر�ɾ��
        tail = head;
    delete p;
    return true;
}
// ��תһ������
template <typename ElemType>
NODE<ElemType>* List<ElemType>::Reverse()
{
    if (head->next == nullptr) return head; // �ձ�
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
// �ж����������Ƿ����
template <typename ElemType>
bool List<ElemType>::operator==(const List<ElemType> &s)
{
    if (Length() != s.Length()) return false; // ���Ȳ���
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
// �ж����������Ƿ����
template <typename ElemType>
bool List<ElemType>::operator!=(const List<ElemType> &s)
{
    return !(*this == s);
}
// �������<<
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
