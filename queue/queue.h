#ifndef QUEUE_H
#define QUEUE_H

#include "node.h"


template <class T>
class queue
{
public:

    typedef std::size_t size_type;

    // default constructor
    queue()
    {
        _front = _rear = nullptr;
        _size = 0;
    }

    // copy constructor
    queue(const queue & q)
    {
        _size = q._size;
        list_copy(q._front, q._rear, _front, _rear);
    }

    // destructor
    ~queue()
    {
        list_clear(_front, _rear);
    }

    // assignment operator
    void operator=(const queue & q)
    {
        if (this == &q)
            return;

        list_clear(_front, _rear);
        _size = q._size;
        list_copy(q._front, q._rear, _front, _rear);
    }

    // pre: none
    // post: returns size
    size_type size() const
    {
        return _size;
    }

    // pre: queue not empty
    // post: returns the front of the queue
    T & front()
    {
        return _front->data();
    }

    T & front() const
    {
        return _front->data();
    }

    // pre: none
    // post: returns true iff queue is empty
    bool empty() const
    {
        return (_size == 0);
    }

    // pre: queue is not empty
    // post: front element has been removed from this queue
    void pop()
    {
        list_head_remove(_front, _rear);
        --_size;
    }


    // pre: none
    // post: a copy of entry has been added to the rear of this queue
    void push(const T & entry)
    {
        list_tail_insert(_front, _rear, entry);
        ++_size;
    }

private:

    node<T> *_front, *_rear;  // points to front and rear nodes of this queue
    size_type _size;  // number of elements in this queue


};

#endif // QUEUE_H

