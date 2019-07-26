ifndef NODE_H
#define NODE_H

#include <cstdlib>

template <class T>
class node
{
public:

    typedef T value_type;

    node(const value_type & init_data = value_type(),
         node * init_link = nullptr)
    {
        _data = init_data;
        _link = init_link;
    }

    value_type data() const
    {
        return _data;
    }

    value_type & data()
    {
        return _data;
    }


    node * link()
    {
        return _link;
    }

    const node * link() const
    {
        return _link;
    }

    void set_data(const value_type & new_data)
    {
        _data = new_data;
    }

    void set_link(node * new_link)
    {
        _link = new_link;
    }


private:
    value_type _data;
    node * _link;
};


template <class T>
class node_iterator
{
public:
    node_iterator(node<T> *initial = nullptr)
    {
        current = initial;
    }

    // returns the ACTUAL data element in this node,
    // not a copy of it
    // this is the meaning of &
    T & operator *() const
    {
        return current->data();
    }

    // returns THIS iterator, not a copy of it
    // this is the meaning of &
    node_iterator & operator ++() // pre-increment
    {
        current = current->link();
        return *this;
    }

    node_iterator operator ++(int) // post-increment
    {
        node_iterator orig = *this;
        current = current->link();
        return orig;
    }

    bool operator == (const node_iterator other) const
    {
        return current == other.current;
    }

    bool operator != (const node_iterator other) const
    {
        return current != other.current;
    }


private:
    node<T> * current;
};


// linked list toolkit functions

template <class T>
std::size_t list_size(const node<T> * head)
{
    std::size_t ans(0);
    for (const node<T> *p = head; p != nullptr; p = p->link() )
        ++ans;

    return ans;
}

template <class T>
void list_head_insert(node<T>* & head,
                      node<T>* &tail,
                      const T & value)
{
    head = new node<T>(value, head);
    if (tail == nullptr)
        tail = head;
}


template <class T>
void list_tail_insert(node<T> * & head,
                      node<T>* & tail,
                      const T & value)
{
    if (tail == nullptr)
    {
        head = tail = new node<T>(value, nullptr);
    }
    else
    {
        tail->set_link(new node<T>(value, nullptr));
        tail = tail->link();
    }
}

template <class T>
std::ostream & operator << (std::ostream & os, const node<T> * head)
{
    for (const node<T> * p = head; p != nullptr; p = p->link())
        os << "(" << p->data() << ", " << (void *) p->link() << ") ";
    return os;
}

template <class T>
void list_print(const node<T> *head,
                const node<T> *tail)
{
    for (const node<T> *p = head; p != nullptr; p = p->link())
        std::cout << p->data() << ", " << (void *) p->link() << " ";
    std::cout << std::endl;
}

template <class T, class NodePtr>
NodePtr list_search(NodePtr head, const T & value)
{
    NodePtr p;
    for (p = head; p != nullptr && p->data() != value;
         p = p->link())
        ;
    return p;
}


template <class NodePtr>
NodePtr list_locate(NodePtr head, std::size_t pos)
{
    NodePtr ans(head);

    for (std::size_t i = 0; i < pos && ans != nullptr; ++i)
        ans = ans->link();

    return ans;
}


template <class T>
void list_copy(const node<T> *orig_head,
               const node<T> *orig_tail,
               node<T> * & new_head,
               node<T> * & new_tail)
{
    new_head = new_tail = nullptr;
    for (const node<T> *p = orig_head;
         p != nullptr;
         p = p->link())
    {
        list_tail_insert(new_head, new_tail, p->data());
    }

}

template <class T>
void list_head_remove(node<T> * & head, node<T> * &tail)
{
    if (head == nullptr)
        return;

    node<T> *temp = head;
    head = head->link();
    delete temp;

    if (head == nullptr);
        tail = nullptr;
}


template <class T>
void list_clear(node<T> * & head, node<T> * & tail)
{
    while (head != nullptr)
        list_head_remove(head, tail);
}

template <class T>
void list_remove(node<T> * previous)
{
    node<T> * temp = previous->link();
    previous->set_link(temp->link());
    delete temp;
}

template <class T>
void list_insert(node<T> * previous, const T & value)
{
    previous->set_link(new node<T>(value, previous->link()));
}


#endif // NODE_H

