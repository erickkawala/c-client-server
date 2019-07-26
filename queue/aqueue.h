ifndef AQUEUE_H
#define AQUEUE_H


class aqueue
{
public:
    aqueue();

private:


    T *_data;
    size_type _front, _rear;
    // _data[_front], _data[_front+1], ..., _data[_rear] contain the
    // elements of this array (wrapping around if necessary)
};

#endif // AQUEUE_H

