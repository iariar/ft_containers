#ifndef _VECTOR_H__
#define _VECTOR_H__

#include <vector>
#include <iostream>
#include <iterator>
#include <map>
#include <algorithm>
#include "lexicographical_compare.hpp"
#include "pair.hpp"

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
    struct enable_if<true, T>
    {
        typedef T type;
    };

    template<typename _Iterator>
    struct iterator_traits
    {
      typedef typename _Iterator::iterator_category iterator_category;
      typedef typename _Iterator::value_type        value_type;
      typedef typename _Iterator::difference_type   difference_type;
      typedef typename _Iterator::pointer           pointer;
      typedef typename _Iterator::reference         reference;
    };

    template<typename _Tp>
    struct iterator_traits<_Tp*>
    {
      typedef std::random_access_iterator_tag   iterator_category;
      typedef _Tp                               value_type;
      typedef ptrdiff_t                         difference_type;
      typedef _Tp*                              pointer;
      typedef _Tp&                              reference;
    };

  /// Partial specialization for const pointer types.
  template<typename _Tp>
    struct iterator_traits<const _Tp*>
    {
      typedef std::random_access_iterator_tag   iterator_category;
      typedef _Tp                               value_type;
      typedef ptrdiff_t                         difference_type;
      typedef const _Tp*                        pointer;
      typedef const _Tp&                        reference;
    };
    
    //////////////////////////////
    ////////////iterator//////////
    //////////////////////////////
    template <class T>
    class my_iterator
    {
        public:
            typedef typename iterator_traits<T>::value_type         value_type;
            typedef typename iterator_traits<T>::pointer            pointer;
            typedef typename iterator_traits<T>::reference          reference;
            typedef typename iterator_traits<T>::difference_type    difference_type;
            typedef typename iterator_traits<T>::iterator_category  iterator_category;
            typedef size_t   size_type;
            my_iterator()
            {
                iterator_pointer = NULL;
            }
            explicit my_iterator(pointer ptr) : iterator_pointer(ptr){};
            template <class Iter>
            my_iterator (const my_iterator<Iter>& it)
            {
                this->iterator_pointer = it.base();
            }
            pointer base() const
            {
                return iterator_pointer;
            }
            reference operator*() const
            {
                return *(iterator_pointer);
            }
            my_iterator operator+ (difference_type n) const
            {
                return (my_iterator(iterator_pointer + n));
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
                return (my_iterator(iterator_pointer - n));
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
        ~my_iterator()
        {return;}
        private:
            pointer iterator_pointer;
    };
    /////////////////////////////////////
    ////rational operators for iterator//
    /////////////////////////////////////
    template <class Iterator1, class Iterator2>
    bool operator== (const my_iterator<Iterator1>& lhs, const my_iterator<Iterator2>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator!= (const my_iterator<Iterator1>& lhs, const my_iterator<Iterator2>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator<  (const my_iterator<Iterator1>& lhs, const my_iterator<Iterator2>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator<=  (const my_iterator<Iterator1>& lhs, const my_iterator<Iterator2>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator>  (const my_iterator<Iterator1>& lhs, const my_iterator<Iterator2>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator1, class Iterator2>
    bool operator>=  (const my_iterator<Iterator1>& lhs, const my_iterator<Iterator2>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    my_iterator<Iterator> operator+ (typename my_iterator<Iterator>::difference_type n, const my_iterator<Iterator>& it)
    {
        return *(it.base() + n);
    }
    template <class Iterator>
    typename my_iterator<Iterator>::difference_type operator- (const my_iterator<Iterator>& lhs, const my_iterator<Iterator>& rhs)
    {
        return lhs.base() - rhs.base();
    }
    template <class T>
    class my_reverse_iterator
    {
        public:
            typedef T                                               iterator_type;
            typedef typename iterator_traits<T>::value_type         value_type;
            typedef typename iterator_traits<T>::pointer            pointer;
            typedef typename iterator_traits<T>::reference          reference;
            typedef typename iterator_traits<T>::difference_type    difference_type;
            typedef typename iterator_traits<T>::iterator_category  iterator_category;

            my_reverse_iterator() : _iter() {};
            explicit my_reverse_iterator (iterator_type it)
            {
                _iter = it;
            }
            template <class Iter>
            my_reverse_iterator (const my_reverse_iterator<Iter>& it)
            {
                this->_iter = it._iter;
            }
            iterator_type base() const
            {
                return (_iter - 1);
            }
            reference operator*() const
            {
                return *(base());
            }
            my_reverse_iterator operator+ (difference_type n) const
            {
                return (my_reverse_iterator(_iter - n));
            } 

            my_reverse_iterator &operator++()
            {
                --_iter;
                return (*this);
            }
            my_reverse_iterator operator++(int)
            {
                my_reverse_iterator tmp = *this;
                ++(*this);
                return (tmp);
            }
            my_reverse_iterator& operator+=(difference_type n)
            {
                this->_iter -= n;
                return (*this);
            }
            my_reverse_iterator operator- (difference_type n) const
            {
                return (my_reverse_iterator(_iter + n));
            }
            my_reverse_iterator &operator--()
            {
                ++_iter;
                return (*this);
            }
            my_reverse_iterator operator--(int)
            {
                my_reverse_iterator tmp = this;
                --(*this);
                return (tmp);
            }
            my_reverse_iterator& operator-= (difference_type n)
            {
                this->_iter += n;
                return (*this);
            }
            pointer operator->() const
            {
                return (_iter);
            }
            reference operator[] (difference_type n) const
            {
                return *(_iter.base() - n - 1);
            }
        ~my_reverse_iterator()
        {return;}
        private:
            iterator_type _iter;
    };
    ///////////////////////////////////////////
    //rational operators for reverse_iterator//
    ///////////////////////////////////////////
    template <class Iterator, class Iterator2>
    bool operator== (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator, class Iterator2>
    bool operator!= (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator, class Iterator2>
    bool operator<  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator, class Iterator2>
    bool operator<=  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator, class Iterator2>
    bool operator>  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator, class Iterator2>
    bool operator>=  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator2>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    my_reverse_iterator<Iterator> operator+ (typename my_reverse_iterator<Iterator>::difference_type n, const my_reverse_iterator<Iterator>& rev_it)
    {
        return  my_reverse_iterator<Iterator>(rev_it.base() - n + 1);
    }
    template <class Iterator>
    typename my_reverse_iterator<Iterator>::difference_type operator- (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return  lhs.base() - rhs.base();
    }
    //////////////////////////////
    /////////vector///////////////
    //////////////////////////////
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                                   value_type;
            typedef Alloc                                               allocator_type;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;
            typedef typename ft::my_iterator<T*>                        iterator;
            typedef typename ft::my_iterator<const T*>                  const_iterator;
            typedef typename ft::my_reverse_iterator<iterator>          reverse_iterator;
            typedef typename ft::my_reverse_iterator<const iterator>    const_reverse_iterator;
            typedef ptrdiff_t                                           difference_type;
            typedef size_t                                              size_type;


        explicit vector(const allocator_type &alloc = allocator_type()) : u(alloc)
        {
            _size = 0;
            _capacity = 0;
            been_to_constructor = 2;
        };
        explicit vector(size_type n, const value_type &val = value_type(), const allocator_type &alloc = allocator_type()) : u(alloc)
        {
            _size = n;
            _capacity = n;
            data = u.allocate(n);
            for (size_t i = 0; i < _size; i++)
            {
                data[i] = val;
            }
            been_to_constructor = 2;
        };
        template <class iterator>
        vector (iterator first, iterator last, const allocator_type& alloc = allocator_type(), typename enable_if<!is_integral<iterator>::value, iterator>::type* = nullptr) : u(alloc)
        {
            int len = dis(first, last);

            data = u.allocate(len);
            _size = 0;
            _capacity = len;
            for (; first != last; first++)
            {
                data[_size] = *first;
                _size++;
            }
            been_to_constructor = 2;
        }
        vector (const vector& x)
        {
            if (*this != x)
                *this = x;
        }
        vector &operator=(vector const &rhs)
        {
            if (been_to_constructor == 2)
                this->~vector();
            if (rhs._capacity > 0)
                this->data = u.allocate(rhs._capacity);
            for (size_t i = 0; i < rhs._size; i++)
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
            return (const_iterator(data));
        }
        iterator end()
        {
            return (iterator(data + _size));
        }
        const_iterator end() const
        {
            return (const_iterator(data + _size));
        }
        reverse_iterator rbegin()
        {
            return (reverse_iterator(end()));
        }
        const_reverse_iterator rbegin() const
        {
            return (const_reverse_iterator(end()));
        }
        reverse_iterator rend()
        {
            return (reverse_iterator(begin()));
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(begin()));
        }
        size_type size() const
        {
            return (_size);
        }
        size_type max_size() const
        {
            if (sizeof(value_type) == 1)
                return (std::numeric_limits<difference_type>::max());
            return ((std::numeric_limits<difference_type>::max() / (sizeof(value_type) / 2)));
        }
        void resize (size_type n, value_type val = value_type())
        {
            if (n < _size)
            {
                for (size_t i = n; i < _size; i++)
                {
                    u.destroy(data + i);
                }  
            }
            else if (n > _size)
            {
                if (n > _capacity)
                {
                    pointer tmp = u.allocate(n);
                    for (size_t i = 0; i < _size; i++)
                    {
                        tmp[i] = data[i];
                    }
                    for (size_t i = _size ; i < n; i++)
                    {
                        tmp[i] = val;
                    }
                    if (_capacity)
                        u.deallocate(data, _capacity);
                    data = tmp;
                    _capacity = n;
                }
                else
                {
                    for (size_t i = _size; i < n; i++)
                    {
                        data[i] = val;
                    }
                }
            }
            _size = n;
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
            size_type cap = _capacity;
            if (n > cap)
            {
                pointer tmp = u.allocate(n);
                for (size_t i = 0; i < _size; i++)
                {
                    tmp[i] = data[i];
                }
                if (_capacity > 0)
                {
                    u.deallocate(data, _capacity);
                }
                data = tmp;
                // _size = n;
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
            size_type sz = _size;
            if (n < 0 || n >= sz)
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
        void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
        {
            size_t len = dis(first, last);
            for (size_t i = 0; i < _size; i++)
            {
                u.destroy(data + i);
            }
            resize(len);
            for (int i = 0; first != last; first++)
            {
                data[i] = *first;
                i++;
            }
        }
        void assign (size_type n, const value_type& val)
        {
            for (size_t i = 0; i < _size; i++)
            {
                u.destroy(data + i);
            }
            resize(n);
            for (size_type i = 0; i < n; i++)
            {
                data[i] = val;
            }
        }
        void push_back (const value_type& val)
        {
            if (_size + 1 > _capacity)
            {
                if (_capacity == 0)
                    reserve(1);
                else
                    reserve(_capacity * 2);
            }
            _size++;
            data[_size - 1] = val;
        }
        void pop_back()
        {
            if (_size)
            {
                u.destroy(data + (_size - 1));
                _size--;
            }
        }
        iterator insert (iterator position, const value_type& val)
        {
            iterator start = this->begin();
            iterator last = this->end();
            int len = _size;
            int number_elements_after = dis(position, this->end());
            if (_size + 1 > _capacity)
            {
                if (_capacity == 0)
                    reserve(1);
                else
                    reserve(_capacity * 2);
            }
            for (; number_elements_after; number_elements_after--)
            {
                data[len] = data[len - 1];
                len--;
            }
            data[len] = val;
            _size++;
            return (iterator(&data[len]));
        }
        void insert (iterator position, size_type n, const value_type& val)
        {
            int number_of_elements_after = dis(position, this->end());
            if (_size + n > _capacity)
                reserve(_size + n);
            _size = _size + n;
            int distance_vector = _size;
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
        void insert (iterator position, InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
        {
            int number_of_elements_after = dis(position, this->end());
            size_type small_vec_len = dis(first, last);
            if (_size + small_vec_len >= _capacity)
            {
                if (_capacity == 0)
                    reserve(small_vec_len);
                if (_capacity * 2 < small_vec_len)
                {
                    reserve(small_vec_len + _size);
                }
                else
                    reserve(_capacity * 2);
            }
            _size += small_vec_len;
            int distance_vector = _size;
            for (; number_of_elements_after >= 0; number_of_elements_after--)
            {
                data[distance_vector] = data[distance_vector - small_vec_len];
                distance_vector--;
            }
            last--;
            for (; last != first ; last--)
            {
                data[distance_vector] = *last;
                distance_vector--;
            }
            data[distance_vector] = *last;
        }
        iterator erase (iterator position)
        {
            iterator last = this->end();
            iterator ret = position; /*without the +1 coz ret is gonna be pointing at the new posotion after shifting*/
            for (; position != last; position++)
            {
                *position = *(position + 1);
            }
            _size--;
            return(ret);
        }
        iterator erase (iterator first, iterator last)
        {
            iterator ending = this->end();
            int len = dis(first, last);
            int numbers_after_erased = dis(last, ending);
            iterator ret = last;

            for (; numbers_after_erased && first != ending; numbers_after_erased--)
            {
                *first = *(first + len);
                first++;
            }
            _size -= len;
            if (!_size)
                return (this->end());
            return (ret);
        }
        void swap (vector& x)
        {
            pointer tmp_data = x.data;
            size_type tmp_size = x._size;
            size_type tmp_cap = x._capacity;
            allocator_type tmp_u = x.u;
            x.data = this->data;
            x._size = this->_size;
            x._capacity = this->_capacity;
            x.u = this->u;
            this->data = tmp_data;
            this->_size = tmp_size;
            this->_capacity = tmp_cap;
            this->u = tmp_u;
        }
        void clear()
        {
            if (_size && _size < max_size() && _size < u.max_size())
            {
                for (int i = _size; i >= 0; i--)
                {
                    u.destroy(data + i);
                }
            }
            if (_capacity && _capacity < max_size())
                u.deallocate(data, _capacity);
            _size = 0;
            _capacity = 0;
        }
        allocator_type get_allocator() const
        {
            allocator_type object;
            return (object);
        }
        ~vector()
        { 
            clear();
            been_to_constructor = 0;
        };
        private:
            int been_to_constructor;
            pointer data;
            allocator_type u;
            size_type _size;
            size_type _capacity;
            template <class it>
            int dis(it start, it last)
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
        x.swap(y);
    }
    template <class T, class Alloc>
    bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lhs.size() == rhs.size() && std::equal(lhs.begin(), lhs.end(), rhs.begin()));
    }
    template <class T, class Alloc>
    bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs == rhs);
    }
    template <class T, class Alloc>
    bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return (lexicographical_compare(lhs.begin(), lhs.end(),  rhs.begin() , rhs.end()));
    }
    template <class T, class Alloc>
    bool operator<=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(rhs < lhs);
    }
    template <class T, class Alloc>
    bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return rhs < lhs;
    }
    template <class T, class Alloc>
    bool operator>=  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs)
    {
        return !(lhs < rhs);
    } 
}

#endif