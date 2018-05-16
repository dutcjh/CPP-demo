/*****************************************************
                ѭ������ģ����
����˵������β����ѭ������ģ���࣬����ͷָ��
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

// ѭ������
template <typename ElemType> // ģ��
class CircleList
{
private:
    NODE<ElemType> *rear; //βָ��
    inline void deepCopy(const CircleList<ElemType> &original); // ��ȸ���
public:
    CircleList(); // ���캯��
    CircleList(const CircleList<ElemType> &LK);// �������캯��
    ~CircleList(); // ��������
    void clearCircList(); // ��պ���
    bool isEmpty() const{ return rear->next == rear; } // �пպ���
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
    CircleList<ElemType> &operator=(const CircleList<ElemType> &s) //����=
    { deepCopy(s); return *this; }
    bool operator==(const CircleList<ElemType> &s); // �ж����������Ƿ����
    bool operator!=(const CircleList<ElemType> &s); // �ж����������Ƿ����
    template <typename S>
    friend std::ostream &operator<<(std::ostream &os, const CircleList<S> &LK); // �������<<
};
// ���캯��
template <typename ElemType>
CircleList<ElemType>::CircleList()
{
    rear = (NODE<ElemType> *) new NODE<ElemType>();
    rear->next = rear; // ָ���Լ�
}
// ��ȸ���
template <typename ElemType>
void CircleList<ElemType>::deepCopy(const CircleList<ElemType> &original)
{
    rear = new NODE<ElemType>;
    rear->next = rear;
    NODE<ElemType> *copyptr = rear->next; // ͷ�ڵ�
    NODE<ElemType> *originalptr = original.rear->next; // ͷ�ڵ�
    while(originalptr != original.rear) // û�е�β�ڵ�
    {
        copyptr->next = new NODE<ElemType>;  //��һ���ǹؼ� a1
        originalptr = originalptr->next; // b1
        copyptr = copyptr->next; // a1
        copyptr->data = originalptr->data; // a1 = b1
    }
    copyptr->next = rear; // β�ڵ�ָ��ͷ�ڵ�
    rear = copyptr; // ͷ�ڵ���β�ڵ�
}
// �������캯��
template <typename ElemType>
CircleList<ElemType>::CircleList(const CircleList<ElemType> &original)
{
    deepCopy(original);
}
// ��������
template <typename ElemType>
CircleList<ElemType>::~CircleList()
{
    clearCircList();
}
// ��պ���
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
        delete(p); // ����a1
    }
}
// ��ȡ������
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
// ��ȡԪ��
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
    if (p == rear->next) return false; // �ص���ͷ�ڵ�
    *e = p->data;
    return true;
}
// ��ȡβ�ڵ�Ԫ��
template <typename ElemType>
bool CircleList<ElemType>::GetTailElem(ElemType *e) const
{
    if(rear->next == rear) return false; // �ձ�
    *e = rear->data;
    return true;
}
// ��ȡͷ�ڵ�Ԫ��
template <typename ElemType>
bool CircleList<ElemType>::GetHeadElem(ElemType *e) const
{
    if(rear->next == rear) return false; // �ձ�
    *e = rear->next->next->data;
    return true;
}
// �滻i��Ԫ��
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
    if (p == rear->next) return false; // �ص���ͷ�ڵ�
    p->data = e; //�滻
    return true;
}
// ����Ԫ��λ��
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
    std::cout << "ERROR: ���в�����ָ����Ԫ��" << std::endl;
    return -1;
}
//�Ƴ�ָ��Ԫ��
template <typename ElemType>
bool CircleList<ElemType>::RemoveElem(ElemType &e)
{
    NODE<ElemType> *p = rear->next->next, *p0 = rear->next;
    while(p != rear->next)
    {
        if(p->data == e) //�ҵ����Ԫ��
        {
            p0->next = p->next; // ���ɾ��
            if(p == rear) //���ɾ����β�ڵ�
                rear = p0;
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
bool CircleList<ElemType>::PriorElem(ElemType cur_e, ElemType *pre_e) const
{
    NODE<ElemType> *p = rear->next->next;
    if (rear->next == rear) return false; // �ձ�
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
    return false; // �����겻���ڻ���ֻ��һ��ͷ���
}
// ȡ��һ��Ԫ��
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
    return false; // �����겻���ڻ���ֻ��һ��ͷ���
}
// ָ��λ�ò���
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
    if (j < i) return false; //�±�Խ��
    s = (NODE<ElemType> *) new NODE<ElemType>;
    s->data = e;
    if (q == rear) // �嵽��β
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
// ĩβ����
template <typename ElemType>
void CircleList<ElemType>::append(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = rear->next;
    rear->next = s;
    rear = s;
}
// ͷ������
template <typename ElemType>
void CircleList<ElemType>::InsertHead(const ElemType &e)
{
    NODE<ElemType> *s = new NODE<ElemType>;
    s->data = e;
    s->next = rear->next->next;
    if(rear==rear->next) // �ձ�ͷ��
    {
        rear->next = s;
        rear = s;
    }
    else
        rear->next->next = s;
}
// ɾ��ָ��λ�õ�Ԫ��
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
    if(p == rear) //ɾ����β�ڵ�
        rear = p0;
    delete p;
    return true;
}
// ĩβɾ��
template <typename ElemType>
bool CircleList<ElemType>::popback(ElemType *e)
{
    if(rear == rear->next) return false; //�ձ�
    NODE<ElemType> *p = rear->next, *s;
    while (p->next->next != rear->next)
        p = p->next;
    s = rear; // ��ɾ��
    *e = s->data;
    p->next = rear->next;
    rear = p;
    delete s;
    return true;
}
// ͷ��ɾ��
template <typename ElemType>
bool CircleList<ElemType>::pophead(ElemType *e)
{
    if(rear == rear->next) return false; //�ձ�
    NODE<ElemType> *p = rear->next->next;
    rear->next->next = p->next;
    *e = p->data;
    if (p == rear) //��Ԫ�ر�ɾ��
        rear = rear->next;
    delete p;
    return true;
}
// ��תһ������
template <typename ElemType>
NODE<ElemType>* CircleList<ElemType>::Reverse()
{
    if (rear == rear->next || Length()==1) return rear; // �ձ��һԪ�ر�
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
// �ж����������Ƿ����
template <typename ElemType>
bool CircleList<ElemType>::operator==(const CircleList<ElemType> &s)
{
    int L = Length();
    if (L != s.Length()) return false; // ���Ȳ���
    NODE<ElemType> *ptr = rear->next->next, *qtr = s.rear->next->next;
    for(int i = 0; i<L; i++)
    {
        if(ptr->data != qtr->data) return false;
        ptr = ptr->next;
        qtr = qtr->next;
    }
    return true;
}
// �ж����������Ƿ����
template <typename ElemType>
bool CircleList<ElemType>::operator!=(const CircleList<ElemType> &s)
{
    return !(*this == s);
}
// �������<<
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

