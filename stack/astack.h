#ifndef ASTACK_H
#define ASTACK_H

#include <algorithm>

template <class T>
class astack
{
public:

    typedef std::size_t size_type;

    // default constructor
    astack()
    {
        _capacity = 1;
        _data = new T[_capacity];
        _top = 0;
    }

    // copy constructor
    astack(const stack &s)
    {
        _capacity = s._capacity;
        _top      = s._top;
        _data     = new T[_capacity];
        std::copy(s._data + 1, s._data + _top + 1, _data+1);
    }

    // destructor
    ~astack()
    {
        delete [] _data;
    }

    // assigment

    void operator =(const astack & s)
    {
        if (this == &s)
            return;

        delete [] _data;
        _capacity = s._capacity;
        _top = s._top;
        _data = new T[_capacity];
        std::copy(s._data+1, s._data + _top + 1, _data+1);
    }

    // pre: none
    // post: returns true iff this astack is empty
    bool empty() const
    {
        return (_top == 0);
    }

    // pre: none
    // post: returns the number of elements in this astack
    size_type size() const
    {
        return _top;
    }

    // pre: this astack is not empty
    // post: returns the (actual) top element of this astack

    T & top()
    {
        assert(!empty());
        return _data[_top];
    }

    T & top() const
    {
        assert(!empty());
        return _data[_top];
    }

    // pre: this astack is not empty
    // post: removes the top element of this astack
    void pop()
    {
        assert(!empty());
        --_top;
    }

    // pre: none
    // post: a copy of entry has been added to this astack
    void push(const T & entry)
    {
        if (_top == _capacity-1)
        {
            _capacity *= 2;
            T * newdata = new T[_capacity];
            std::copy(_data+1, _data+_top+1, newdata+1);
            delete [] _data;
            _data = newdata;
        }
        _data[++_top] = entry;
    }


private:

    T *_data;
    size_type _capacity, _top;

    // invariants:
    //_data is a dynamic array of size _capacity
    //_data[1], _data[2], ..., _data[_top] contain the elements
    //in order of insertion
    // _data[_top] is the last element inserted
    // _data[0] is not used

};

#endif // ASTACK_H

