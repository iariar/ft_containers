#ifndef _VECTOR_H__
#define _VECTOR_H__

#include <iostream>
#include <vector>

namespace ft
{
    template <class T>
    class my_iterator
    {
        public:
            typedef T value_type;
            typedef size_t size_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ptrdiff_t difference_type;

            my_iterator(/* args */)
            {
                iterator_pointer = NULL;
            }
            explicit my_iterator(pointer ptr) : iterator_pointer(ptr){};
            // ex 
            template <class Iter>
            my_iterator (const my_iterator<Iter>& it)
            {
                *this = it;
            }
            // iterator_type base() const
            // {
            //     return *(iterator_pointer + n);
            // }
            reference operator*() const
            {
                return *(iterator_pointer);
            }
            my_iterator operator+ (difference_type n) const
            {
                return *(iterator_pointer + n);
            }

            my_iterator &operator++()
            {
                iterator_pointer++;
                return (*this);
            }
            my_iterator operator++(int)
            {
                my_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            my_iterator& operator+=(difference_type n)
            {
                this->iterator_pointer += n;
                return (*this);
            }
            my_iterator operator- (difference_type n) const
            {
                return *(iterator_pointer - n);
            }
            my_iterator &operator--()
            {
                iterator_pointer--;
                return (*this);
            }
            my_iterator operator--(int)
            {
                my_iterator tmp = this;
                --(*this);
                return (tmp);
            }
            my_iterator& operator-= (difference_type n)
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
            my_iterator &operator=(const my_iterator &rhs)
            {
                this->iterator_pointer = rhs.iterator_pointer;
                return (*this);
            }
            pointer get_my_iterator_pointer(void) const
            {
                return (iterator_pointer);
            }
        ~my_iterator()
        {return;}
        private:
            pointer iterator_pointer;
    };
    ///////////////////////////////////
    //rational operators for iterator//
    ///////////////////////////////////
    template <class Iterator>
    bool operator== (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() == rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    bool operator!= (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() != rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    bool operator<  (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() < rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    bool operator<=  (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() <= rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    bool operator>  (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() > rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    bool operator>=  (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() >= rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    my_iterator<Iterator> operator+ (typename my_iterator<Iterator>::difference_type n, const my_iterator<Iterator>& it)
    {
        return *(it + n);
    }
    template <class Iterator>
    typename my_iterator<Iterator>::difference_type operator- (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs);
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
            typedef typename ft::my_iterator<T> iterator;
            // typedef typename const ft::my_iterator<T> const_iterator;
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
        iterator begin()
        {
            return (iterator(data));
        }
        //const_iterator begin() const;
        iterator end()
        {
            return (iterator(data + _size));
        }
        //const_iterator end() const;
        iterator rbegin()
        {
            return (iterator(data + (_size - 1)));
        }
        //iterator rbegin() const;
        iterator rend()
        {
            return (iterator(data));
        }
        //iterator rend() const;
        size_type size() const
        {
            return (_size);
        }
        size_type max_size() const
        {
            //returns maximum potential size that the container can reach 
        }
        void resize (size_type n, value_type val = value_type())
        {
            pointer_type tmp = u.allocate(n);
            if (n < _size)
            {
                for (int i = 0; i < n; i++)
                {
                    tmp[i] = data[i];
                }
                for (int i = 0; i < _size; i++)
                {
                    u.destroy(data[i]); /*DEBATABLE*/
                }
                u.deallocate(data, _size);
                data = tmp;
                _size = n;
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
            _capacity = n;
        }
        size_type capacity() const
        {
            return (_capacity);
        }
        bool empty() const
        {
            return (_size == 0);
        }
        void reserve (size_type n)
        {
            // if (n > max_size())
            //     throw std::length_error("something");
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
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last)
        {
            int std::distance(first, last);
            for (size_t i = 0; i < _size; i++)
            {
                u.destroy(data[i]);
            }
            if (distance > size)
            {
                u.deallocate(data, _capacity);/*DEABATABLE*/
                _capacity = distance;
                u.allocate(distance);
            }
            _size = distance;
            for (int i = 0; first != last; first++)
            {
                data[i] = *first;
                i++;
            }
        }
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
                reserve(_size + 1); /*DEBATABLE*/
            data[_size - 1] = val;
        }
        void pop_back()
        {
            u.destroy(data[_size - 1]);
            _size--;
        }
        // iterator insert (iterator position, const value_type& val)
        // {

        // }
        // iterator insert (iterator position, const value_type& val);
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
        iterator erase (iterator position)
        {
            iterator last = this.end();
            for (int i = 0; position != last; position++)
            {
                position = position + 1;
            }
            _size--;
        }
        // iterator erase (iterator first, iterator last)
        // {
        //     int distance = std::distance(first, last);


        // }
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
        ~vector(){return;};
    };
    template <class T, class Alloc>
    void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
    {
        x.swap(y);/*DEBATABLE*/
    }
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.data == rhs.data);
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.data != rhs.data);
    }
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.data < rhs.data);
    }
    template <class T, class Alloc>
    bool operator<=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.data <= rhs.data);
    }
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.data > rhs.data);
    }
    template <class T, class Alloc>
    bool operator>=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.data >= rhs.data);
    }
}

#endif