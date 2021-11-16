#ifndef _VECTOR_H__
#define _VECTOR_H__

#include <iostream>
#include <vector>

namespace ft
{
    template <class T, class Alloc = std::allocator<T> >
    class vector
    {
        private:
            T *data;
            Alloc u;
            int _size;
            int _capacity;

        public:
            typedef T value_type;
            typedef size_t size_type;
            typedef T* pointer_type;
            typedef T& reference_type;
            typedef Alloc allocator_type;
            typedef ptrdiff_t difference_type;
            // typedef iterator iterator_type;
            typedef typename allocator_type::reference reference;
            typedef typename allocator_type::const_reference	 const_reference;
            typedef typename allocator_type::pointer pointer;
            typedef typename allocator_type::const_pointer const_pointer;

        explicit vector(const allocator_type &alloc = allocator_type()) : u(alloc)
        {
            _size = 0;
            _capacity = 0;
        };
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : u(alloc)
        {
            _size = n;
            _capacity = n;
            data = u.allocate(n);
            for (int i = 0; i < _size; i++)
            {
                data[i] = val;
            }
        };
        template <class iterator>
        vector (iterator first, iterator last,
                 const allocator_type& alloc = allocator_type()) : u(alloc)
        {
            size_type distance = std::distance(first, last);
            data = u.allocate(distance);
            _size = 0;
            _capacity = distance;
            for (; first != last; first++)
            {
                data[_size] = *first;
                _size++;
            }
        }
        vector (const vector& f)
        {
            *this = f;
        }
        vector &operator=(vector const &rhs)
        {
            rhs.data = u.allocate(_capacity);
            for (int i = 0; i < _size; i++)
            {
                this->data[i] = rhs.data[i];
            }
            this->_capacity = rhs._capacity;
            this->_size = rhs._size;
            this->u = rhs.u;
            return (*this);
        }
//BROBABLY NEEDS TO BE HERE        // template <class value_type>
        class iterator
        {
            private:
                pointer_type iterator_pointer;
            public:
                iterator(/* args */)
                {
                    iterator_pointer = NULL;
                }
                explicit iterator(pointer_type ptr) : iterator_pointer(ptr){};
                // ex 
                template <class Iter>
                iterator (const iterator<Iter>& it)
                {
                    *this = it;
                }
                reference operator*() const
                {
                    return *(iterator_pointer);
                }
                iterator operator+ (difference_type n) const
                {
                    return *(iterator_pointer + n);
                }

                iterator &operator++()
                {
                    iterator_pointer++;
                    return (*this);
                }
                iterator operator++(int)
                {
                    iterator tmp = *this;
                    ++(*this);
                    return (tmp);
                }
                iterator& operator+=(difference_type n)
                {
                    this->iterator_pointer += n;
                    return (*this);
                }
                iterator operator- (difference_type n) const
                {
                    return *(iterator_pointer - n);
                }
                iterator &operator--()
                {
                    iterator_pointer--;
                    return (*this);
                }
                iterator operator--(int)
                {
                    iterator tmp = this;
                    --(*this);
                    return (tmp);
                }
                iterator& operator-= (difference_type n)
                {
                    this->iterator_pointer -= n;
                    return (*this);
                }
                pointer operator->() const
                {
                    return (iterator_pointer);
                }
                reference operator[] (difference_type n) const
                {
                    return *(iterator_pointer + n);
                }
                iterator &operator=(const iterator &rhs)
                {
                    this->iterator_pointer = rhs.iterator_pointer;
                    return (*this);
                }
                // RATIONAL OPERATORS ARE NON-MEMBER FUNCTIONS
                // bool operator==(const iterator &rhs) const
                // {
                //     return (this->iterator_pointer == rhs.iterator_pointer);
                // }
                friend  bool operator!= (const iterator<Iterator>& lhs, const iterator<Iterator>& rhs);
                // {
                //     return (this->iterator_pointer != rhs.iterator_pointer);
                // }
                // bool operator<(const iterator &rhs) const
                // {
                //     return (this->iterator_pointer < rhs.iterator_pointer);
                // }
                // bool operator<=(const iterator &rhs) const
                // {
                //     return (this->iterator_pointer <= rhs.iterator_pointer);
                // }
                // bool operator>=(const iterator &rhs) const
                // {
                //     return (this->iterator_pointer >= rhs.iterator_pointer);
                // }
                // bool operator>(const iterator &rhs) const
                // {
                //     return (this->iterator_pointer > rhs.iterator_pointer);
                // }
            ~iterator()
            {return;};
        };
        void resize (size_type n, value_type val = value_type())
        {
            pointer_type tmp = u.allocate(n);
            if (n < _size)
            {
                for (int i = 0; i < n; i++)
                {
                    tmp[i] = data[i];
                    u.destroy(data[i]); /*DEBATABLE*/
                }
                u.deallocate(data, _size);
                data = tmp;
            }
            if (n > _size)
            {
                for (int i = 0; i < _size; i++)
                {
                    tmp[i] = data[i];
                }
                for (int i = _size; i < n; i++)
                {
                    tmp[i] = val;
                }
                u.deallocate(data, _size);
                data = tmp;
            }
            // _size = n;
            _capacity = n;
        }
        void reserve (size_type n)
        {
            if (n > _capacity)
            {
                pointer_type tmp;
                tmp = u.allocate(n);
                for (int i = 0; i < _size; i++)
                {
                    tmp[i] = data[i];
                }
                u.deallocate(data, _capacity);
                data = tmp;
            }
        }
        iterator begin()
        {
            return iterator(data);
        }
        iterator end()
        {
            return (iterator(data + _size));
        }
        iterator rbegin()
        {
            return (iterator(data + (_size - 1)));
        }
        iterator rend()
        {
            return (iterator(data));
        }
        size_type size() const
        {
            return (_size);
        }
        size_type capacity() const
        {
            return (_capacity);
        }
        bool empty() const
        {
            return (_size > 0);
        }
        reference operator[] (size_type n)
        {
            return *(data[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return *(data[n]);
        }
        reference at (size_type n)
        {
            if (n < 0 || n >= _size)
                throw std::out_of_range("Out of range");
            return *(data[n]);
        }
        const_reference at (size_type n) const
        {
            if (n < 0 || n >= _size)
                throw std::out_of_range("Out of range");
            return *(data[n]);
        }
        reference front()
        {
            return *(data[0]);
        }
        const_reference front() const
        {
            return *(data[0]);
        }
        reference back()
        {
            return *(data[_size - 1]);
        }
        const_reference back() const
        {
            return *(data[_size - 1]);
        }
        //template <class InputIterator> void assign (InputIterator first, InputIterator last);
        void assign (size_type n, const value_type& val)
        {
            if (_size + n > _capacity)
            {
                resize(_size + n);
                _capacity = _size + n;
            }
            for (int i = _size; i < _size + n; i++)
            {
                data[i] = val;
            }
            _size = _size + n;
        }
        void push_back (const value_type& val)
        {
            if (_size + 1 == _capacity)
                resize(_size + 1);
            data[_size - 1] = val;
        }
        void pop_back()
        {
            u.destroy(data[_size - 1]);
            _size--;
        }
        //iterator insert (iterator position, const value_type& val);
        // void insert (iterator position, size_type n, const value_type& val)
        // {
        //     pointer_type tmp = u.allocate(s);
        //     if (_size + n >= _capacity)
        //     {
        //         resize(_size + n);
        //     }
        // }
        //template <class InputIterator>
        //void insert (iterator position, InputIterator first, InputIterator last);
        void swap (vector& x)
        {
            vector tmp(x);
            x = *this;
            this = *tmp;
        }
        void clear()
        {
            for (; _size >= 0; _size--)
            {
                u.destroy(data[_size]);
            }
        }
        allocator_type get_allocator() const
        {
            allocator_type object;
            return (object);
        }
        template <class something>
        bool operator!= (const iterator<something>& lhs, const iterator<something>& rhs)
        {
            return (lhs.iterator_pointer != rhs.iterator_pointer);
        }
        ~vector(){return;};
    };
}

#endif