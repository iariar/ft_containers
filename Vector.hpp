#ifndef _VECTOR_H__
#define _VECTOR_H__

#include <vector>
#include <iostream>
#include <iterator>
#include <algorithm>

namespace ft
{
    //////////////////////////////
    ////////////is_integral///////
    //////////////////////////////
    template <class T>
    struct is_integral
    {
        const static bool value = false;
        T type;
    };
    template <>
    struct is_integral<bool>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<char>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<char16_t>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<char32_t>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<wchar_t>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<signed char>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<short int>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<int>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<long int>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<long long int>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<unsigned char>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<unsigned short int>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<unsigned int>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<unsigned long int>
    {
        const static bool value = true;
    };
    template <>
    struct is_integral<unsigned long long int>
    {
        const static bool value = true;
    };
    //////////////////////////////
    ////////////enable_if/////////
    //////////////////////////////
    template <bool B, typename T = void>
    struct enable_if{};

    template <class T>
    struct enable_if<true, T>{
        typedef T type;
    };
    //////////////////////////////
    ////////////iterator//////////
    //////////////////////////////
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
                return (iterator_pointer + n);
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
                my_iterator tmp = *this;
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
    // template <class Iterator>
    // typename my_iterator<Iterator>::difference_type operator- (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    // {
    //     return *(it - n);
    // }
    //////////////////////////////
    /////////reverse_iterator/////
    //////////////////////////////
    template <class T>
    class my_reverse_iterator
    {
        public:
            typedef T value_type;
            typedef size_t size_type;
            typedef T* pointer;
            typedef T& reference;
            typedef ptrdiff_t difference_type;

            my_reverse_iterator(/* args */)
            {
                iterator_pointer = NULL;
            }
            explicit my_reverse_iterator(pointer ptr) : iterator_pointer(ptr){};
            // MISSING CONSTRUCTOR
            template <class Iter>
            my_reverse_iterator (const my_reverse_iterator<Iter>& it)
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
            my_reverse_iterator operator+ (difference_type n) const
            {
                return *(iterator_pointer - n);
            }

            my_reverse_iterator &operator++()
            {
                iterator_pointer--;
                return (*this);
            }
            my_reverse_iterator operator++(int)
            {
                my_reverse_iterator tmp = *this;
                --(*this);
                return (tmp);
            }
            my_reverse_iterator& operator+=(difference_type n)
            {
                this->iterator_pointer -= n;
                return (*this);
            }
            my_reverse_iterator operator- (difference_type n) const
            {
                return *(iterator_pointer + n);
            }
            my_reverse_iterator &operator--()
            {
                iterator_pointer++;
                return (*this);
            }
            my_reverse_iterator operator--(int)
            {
                my_reverse_iterator tmp = this;
                ++(*this);
                return (tmp);
            }
            my_reverse_iterator& operator-= (difference_type n)
            {
                this->iterator_pointer += n;
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
            my_reverse_iterator &operator=(const my_reverse_iterator &rhs)
            {
                this->iterator_pointer = rhs.iterator_pointer;
                return (*this);
            }
            pointer get_my_iterator_pointer(void) const
            {
                return (iterator_pointer);
            }
        ~my_reverse_iterator()
        {return;}
        private:
            pointer iterator_pointer;
    };
    ///////////////////////////////////////////
    //rational operators for reverse_iterator//
    ///////////////////////////////////////////
    template <class Iterator>
    bool operator== (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() == rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    bool operator!= (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() != rhs.get_my_iterator_pointer());
    }
    template <class Iterator>
    bool operator<  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.get_my_iterator_pointer() < rhs.get_my_iterator_pointer());
    }
    // template <class Iterator>
    // bool operator<=  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    // {
     
    // template <class Iterator>
    // typename my_reverse_iterator<Iterator>::difference_type operator- (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    // {
    //     return *(it + n);
    // }
    //////////////////////////////
    /////////vector///////////////
    //////////////////////////////
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T value_type;
            typedef size_t size_type;
            typedef T* pointer_type;
            typedef T& reference_type;
            typedef Alloc allocator_type;
            typedef ptrdiff_t difference_type;
            typedef typename ft::my_iterator<T> iterator;
            typedef typename ft::my_iterator<const T> const_iterator;
            typedef typename ft::my_reverse_iterator<T> reverse_iterator;
            typedef typename ft::my_reverse_iterator<const T> const_reverse_iterator;
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
            int len = std::distance(first, last);
            data = u.allocate(len);
            _size = 0;
            _capacity = len;
            for (; first != last; first++)
            {
                data[_size] = *first;
                _size++;
            }
        }
        vector (const vector& x)//NOT WORKING 
        {
            *this = x;
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
        const_iterator begin() const
        {
            return (iterator(data));
        }
        iterator end()
        {
            return (iterator(data + _size));
        }
        const_iterator end() const
        {
            return (iterator(data + _size));
        }
        reverse_iterator rbegin()
        {
            return (reverse_iterator(data + (_size - 1)));
        }
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(data + (_size - 1)));
        }
        reverse_iterator rend()
        {
            return (reverse_iterator(data));
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(data));
        }
        size_type size() const
        {
            return (_size);
        }
        size_type max_size() const
        {
            //returns maximum potential size that the container can reach 
            return (u.max_size());
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
                    u.destroy(data + i); /*DEBATABLE*/
                }
                u.deallocate(data, _size);
                data = tmp;
            }
            if (n > _size)
            {
                for (int i = 0; i < _size; i++)
                {
                    tmp[i] = data[i];
                    // u.destroy(data[i]);
                }
                for (int i = _size - 1; i < n; i++)
                {
                    tmp[i] = val;
                }
                u.deallocate(data, _size);
                data = tmp;
                _size = n;
            }
            _size = n;
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
            if (n > max_size())
                throw std::length_error("something");
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
                _size = n;
                _capacity = n;
            }
        }
        reference operator[] (size_type n)
        {
            return (data[n]);
        }
        const_reference operator[] (size_type n) const
        {
            return (data[n]);
        }
        reference at (size_type n)
        {
            if (n < 0 || n >= _size)
                throw std::out_of_range("Out of range");
            return (data[n]);
        }
        const_reference at (size_type n) const
        {
            if (n < 0 || n >= _size)
                throw std::out_of_range("Out of range");
            return (data[n]);
        }
        reference front()
        {
            return (data[0]);
        }
        const_reference front() const
        {
            return (data[0]);
        }
        reference back()
        {
            return (data[_size - 1]);
        }
        const_reference back() const
        {
            return (data[_size - 1]);
        }
        template <class InputIterator>
        void assign (InputIterator first, InputIterator last, typename enable_if<is_integral<InputIterator>::value, InputIterator>::Type)
        {
            int len = std::distance(first, last);
            for (size_t i = 0; i < _size; i++)
            {
                u.destroy(data + i);
            }
            for (int i = 0; first != last; first++)
            {
                data[i] = first;
                i++;
            }
        }
        void assign (size_type n, const value_type& val)//WORKING
        {
            resize(n);
            for (int i = 0; i < _size + n; i++)
            {
                data[i] = val;
            }
        }
        void push_back (const value_type& val)
        {
            if (_size + 1 == _capacity)
                reserve(_size * 2); /*DEBATABLE*/
            _size++;
            _capacity++;
            data[_size - 1] = val;
        }
        void pop_back()
        {
            u.destroy(data + (_size - 1));
            _size--;
        }
        iterator insert (iterator position, const value_type& val)//WORKING
        {
            int distance_vector = dis(this->begin(), this->end());
            iterator last = this->end();
            if (_size == _capacity)
            {
                reserve(_capacity + 1);
            }
            for (; last != position ; last--)
            {
                data[distance_vector] = data[distance_vector - 1];
                distance_vector--;
            }
            data[distance_vector] = val;
            return (position);
        }
        void insert (iterator position, size_type n, const value_type& val)//WORKING
        {
            int number_of_elements_after = dis(position, this->end());
            if (_size + n >= _capacity)
                reserve(_size + n);
            int distance_vector = dis(this->begin(), this->end());
            // iterator last = this->end();
            // // printf("size is %d\n", _size);
            printf("distance_vector = %d\n", number_of_elements_after);
            for (; number_of_elements_after >= 0; number_of_elements_after--)
            {
                data[distance_vector] = data[distance_vector - n];
                distance_vector--;
            }
            int len = n;
            for (; len > 0 ; len--)
            {
                data[distance_vector] = val;
                distance_vector--;
            }
        }
        template <class InputIterator>
        void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<is_integral<InputIterator>::value, InputIterator>::Type)
        {
            int number_of_elements_after = dis(position, this->end());
            int small_vec_len = dis(first, last);
            if (_size + small_vec_len >= _capacity)
                reserve(_size + small_vec_len);
            int distance_vector = dis(this->begin(), this->end());
            for (; number_of_elements_after >= 0; number_of_elements_after--)
            {
                data[distance_vector] = data[distance_vector - small_vec_len];
                distance_vector--;
            }
            for (; last != first ; last--)
            {
                data[distance_vector] = *last;
                distance_vector--;
            }
        }
        iterator erase (iterator position)
        {
            iterator last = this->end();
            for (int i = 0; position != last; position++)
            {
                position = position + 1;
            }
            _size--;
        }
        iterator erase (iterator first, iterator last)
        {
            iterator ending = this->end();
            iterator start = this->begin();
            int len = dis(first, last);
            int dup;
            int numbers_after_erased = dis(last, ending);
            dup = numbers_after_erased;
            while (start != first)
                start++;
            for (; start != last && numbers_after_erased; start++)
            {
                data[numbers_after_erased] = data[numbers_after_erased + len];
                numbers_after_erased--;
            }
            _size -=len;
            return (this->end());
        }
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
        private:
            T *data;
            Alloc u;
            int _size;
            int _capacity;
            int dis(iterator start, iterator last)
            {
                int i = 0;
                for (; start != last; start++)
                {
                    i++;
                }
                return (i);
            }
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
    ///////////////////////////////
    // lexicographical_compare()///
    ///////////////////////////////
    template <class InputIterator1, class InputIterator2>/*DEBATABLE*/
    bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
    {
        for (first1; first1 != last1 && first2 != last2; first1++)
        {
            if (first1 != first2)
                return(1);
            first2++;
        }
        return(0);
    }

    template <class T1, class T2> struct pair
    {
        typedef T1 first_type; 
        typedef T2 second_type;
        pair() : first(NULL) , second(NULL){return;}
        template <class U, class V>
        pair (const pair<U,V>& pr)
        {
            *this = pr;
        }
        pair& operator= (const pair& pr)
        {
            this->first = pr.first;
            this->second = pr.second;
            return (*this);
        }
        pair (const first_type& a, const second_type& b)
        {
            first = a;
            second = b;
        }
        private:
            T1 first;
            T2 second;
    };
    template <class T1, class T2>
    bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first == rhs.first && lhs.second == rhs.second);
    }
    template <class T1, class T2>
    bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first != rhs.first && lhs.second != rhs.second);
    }
    template <class T1, class T2>
    bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {        
        return (lhs.first < rhs.first && lhs.second < rhs.second);
    }
    template <class T1, class T2>
    bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first <= rhs.first && lhs.second <= rhs.second);
    }
    template <class T1, class T2>
    bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first > rhs.first && lhs.second > rhs.second);
    }
    template <class T1, class T2>
    bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
    {
        return (lhs.first >= rhs.first && lhs.second >= rhs.second);
    }
    template <class T1,class T2>
    pair<T1,T2> make_pair (T1 x, T2 y)
    {
        return ( pair<T1,T2>(x,y) );
    };
}

#endif