#ifndef _VECTOR_H__
#define _VECTOR_H__

#include <iostream>
#include <vector>

namespace ft
{

    template <class T, class Alloc = std::allocator<T> >
    class Vector
    {
    private:
        T *data;
        Alloc u;
        int size;
        int capacity;

    public:
        typedef typename T value_type;
        typedef typename T* pointer_type;
        typedef typename T& reference_type;
        typedef typename Alloc allocator_type;
        // typedef allocator_type::reference reference;
        // typedef allocator_type::const_reference	 const_reference;≈≈≈
        // typedef allocator_type::pointer T*;
        // typedef allocator_type::const_pointer const T*;

        explicit Vector(const allocator_type &alloc = allocator_type()) : u(alloc)
        {
            size = 0;
            capacity = 0;
        };
        explicit Vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : u(alloc)
        {
            size = n;
            capacity = n;
            data = u.allocate(n);
            for (int i = 0; i < size; i++)
            {
                data[i] = val;
            }
        };
        class iterator
        {
            private:
                pointer_type iterator_pointer;
            public:
                iterator(/* args */);
                iterator(pointer_type ptr) : iterator_pointer(ptr){};
                iterator &operator++()
                {
                    iterator_pointer++;
                    return (*this);
                }
                iterator &operator=(const iterator &rhs)
                {
                    this->iterator_pointer = rhs.iterator_pointer;
                    return (*this);
                }
                // iterator &operator(const iterator &rhs)
                // {
                //     this->iterator_pointer = rhs.iterator_pointer;
                //     return (*this);
                // }
                iterator &operator+=(const iterator &rhs)
                {
                    this->iterator_pointer += rhs.iterator_pointer;
                    return (*this);
                }
                iterator &operator-=(const iterator &rhs)
                {
                    this->iterator_pointer -= rhs.iterator_pointer;
                    return (*this);
                }
                iterator &operator++(int)
                {
                    iterator tmp = this;
                    ++(*this);
                    return (tmp);
                }
                iterator &operator--()
                {
                    iterator_pointer--;
                    return (*this);
                }
                iterator &operator--(int)
                {
                    iterator tmp = this;
                    --(*this);
                    return (tmp);
                }
                reference_type operator[](int index)
                {
                    /*there maybe a need for a pointer here*/ return *(iterator_pointer + index);
                }
                pointer_type operator->()
                {
                    return (iterator_pointer);
                }
                reference_type operator*()
                {
                    return /*probably needs to be derefrenced*/ (iterator_pointer);
                }
                bool operator==(const iterator &rhs) const
                {
                    return (this->iterator_pointer == rhs.iterator);
                }
                bool operator!=(const iterator &rhs) const
                {
                    return (this->iterator_pointer != rhs.iterator);
                }
                bool operator<(const iterator &rhs) const
                {
                    return (this->iterator_pointer < rhs.iterator);
                }
                bool operator<=(const iterator &rhs) const
                {
                    return (this->iterator_pointer <= rhs.iterator);
                }
                bool operator>=(const iterator &rhs) const
                {
                    return (this->iterator_pointer >= rhs.iterator);
                }
                bool operator>(const iterator &rhs) const
                {
                    return (this->iterator_pointer > rhs.iterator);
                }
            ~iterator();
        };
        Vector(/* args */);
        ~Vector();
    };
}

#endif