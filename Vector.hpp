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

    // template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T*, class Reference = T&>
    // class base_iterator
    // {
    //     typedef T         value_type;
    //     typedef Distance  difference_type;
    //     typedef Pointer   pointer;
    //     typedef Reference reference;
    //     typedef Category  iterator_category;
    // };

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
    class my_iterator/* : public base_iterator*/
    {
        public:
            typedef typename iterator_traits<T>::value_type         value_type;
            typedef typename iterator_traits<T>::pointer            pointer;
            typedef typename iterator_traits<T>::reference          reference;
            typedef typename iterator_traits<T>::difference_type    difference_type;
            typedef typename iterator_traits<T>::iterator_category  iterator_category;
            typedef size_t   size_type;
            my_iterator(/* args */)
            {
                iterator_pointer = NULL;
            }
            explicit my_iterator(pointer ptr) : iterator_pointer(ptr){};
            // ex 
            template <class Iter>
            my_iterator (const my_iterator<Iter>& it)
            {
                this->iterator_pointer = it.iterator_pointer;
            }
            value_type base() const
            {
                return *(iterator_pointer);
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
            pointer get_my_iterator_pointer(void) const
            {
                return (iterator_pointer);
            }
        ~my_iterator()
        {return;}
            pointer iterator_pointer;
        private:
    };
    /////////////////////////////////////
    ////rational operators for iterator//
    /////////////////////////////////////
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

            // explicit my_reverse_iterator(pointer ptr) : iterator_pointer(ptr){};
            my_reverse_iterator(){/*_iter = NULL;*/};
            explicit my_reverse_iterator (iterator_type it)
            {
                _iter = it;
            }
            // MISSING CONSTRUCTOR//maybe not
            template <class Iter>
            my_reverse_iterator (const my_reverse_iterator<Iter>& it)
            {
                this->_iter = it._iter;
            }
            iterator_type base() const
            {
                return (_iter);
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
                _iter--;
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
                this->_iter -= n;
                return (*this);
            }
            my_reverse_iterator operator- (difference_type n) const
            {
                return (my_reverse_iterator(_iter + n));
            }
            my_reverse_iterator &operator--()
            {
                _iter++;
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
                this->_iter += n;
                return (*this);
            }
            pointer operator->() const
            {
                return (_iter);
            }
            reference operator[] (difference_type n) const
            {
                return *(_iter - n - 1);
            }
        ~my_reverse_iterator()
        {return;}
        private:
            iterator_type _iter;
            // pointer iterator_pointer;
    };
    ///////////////////////////////////////////
    //rational operators for reverse_iterator//
    ///////////////////////////////////////////
    template <class Iterator>
    bool operator== (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() == rhs.base());
    }
    template <class Iterator>
    bool operator!= (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() != rhs.base());
    }
    template <class Iterator>
    bool operator<  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() < rhs.base());
    }
    template <class Iterator>
    bool operator<=  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() <= rhs.base());
    }
    template <class Iterator>
    bool operator>  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() > rhs.base());
    }
    template <class Iterator>
    bool operator>=  (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return (lhs.base() >= rhs.base());
    }
    template <class Iterator>
    my_reverse_iterator<Iterator> operator+ (typename my_reverse_iterator<Iterator>::difference_type n, const my_reverse_iterator<Iterator>& rev_it)
    {
        return  my_reverse_iterator<Iterator>(rev_it + n);
    }
    template <class Iterator>
    typename my_reverse_iterator<Iterator>::difference_type operator- (const my_reverse_iterator<Iterator>& lhs, const my_reverse_iterator<Iterator>& rhs)
    {
        return rhs.base() - lhs.base();
    }
    //////////////////////////////
    /////////vector///////////////
    //////////////////////////////
    template < class T, class Alloc = std::allocator<T> >
    class vector
    {
        public:
            typedef T                                                   value_type;
            typedef size_t                                              size_type;
            typedef T*                                                  pointer_type;
            typedef T&                                                  reference_type;
            typedef Alloc                                               allocator_type;
            typedef ptrdiff_t                                           difference_type;
            typedef typename ft::my_iterator<T*>                        iterator;
            typedef typename ft::my_iterator<const T*>                  const_iterator;
            typedef typename ft::my_reverse_iterator<iterator>          reverse_iterator;
            typedef typename ft::my_reverse_iterator<const iterator>    const_reverse_iterator;
            typedef typename allocator_type::reference                  reference;
            typedef typename allocator_type::const_reference            const_reference;
            typedef typename allocator_type::pointer                    pointer;
            typedef typename allocator_type::const_pointer              const_pointer;


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
        }
        vector (const vector& x)//NOT WORKING 
        {
            *this = x;
        }
        vector &operator=(vector const &rhs)
        {
            this->data = u.allocate(rhs._capacity);
            for (int i = 0; i < rhs._size; i++)
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
            return (reverse_iterator(begin()));/*VERY DEBATABLE*/
        }
        const_reverse_iterator rend() const
        {
            return (const_reverse_iterator(begin()));/*SAME*/
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
            if (n < _size)
            {
                for (; n < _size; n++)
                {
                    u.destroy(data + n);
                }  
            }
            if (n > _size)
            {
                pointer_type tmp = u.allocate(n);
                for (int i = 0; i < _size; i++)
                {
                    tmp[i] = data[i];
                }
                for (int i = _size ; i < n; i++)
                {
                    tmp[i] = val;
                }
                if (_capacity)
                    u.deallocate(data, _capacity);
                data = tmp;
                _capacity = n;
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
            if (n > _capacity)
            {
                pointer_type tmp = u.allocate(n);
                for (int i = 0; i < _size; i++)
                {
                    tmp[i] = data[i];
                }
                if (_capacity)
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
        void assign (InputIterator first, InputIterator last, typename enable_if<!is_integral<InputIterator>::value, InputIterator>::type* = nullptr)
        {
            int len = dis(first, last);
            for (size_t i = 0; i < _size; i++)
            {
                u.destroy(data + i);
            }
            if (_size != len)
                resize(len);
            for (int i = 0; first != last; first++)
            {
                data[i] = *first;
                i++;
            }
        }
        void assign (size_type n, const value_type& val)//WORKING
        {
            for (size_t i = 0; i < _size; i++)
            {
                u.destroy(data + i);
            }
            resize(n);
            for (int i = 0; i < n; i++)
            {
                data[i] = val;
            }
        }
        void push_back (const value_type& val)
        {
            if (_size + 1 > _capacity)
            {
                if (_capacity == 0)
                {
                    reserve(1);
                }
                else
                {
                    reserve(_capacity * 2);
                }
            }
            _size++;
            data[_size - 1] = val;
        }
        void pop_back()
        {
            u.destroy(data + (_size - 1));
            _size--;
        }
        iterator insert (iterator position, const value_type& val)//WORKING
        {
            iterator start = this->begin();
            iterator last = this->end();
            int len = dis(this->begin(), this->end());
            int number_elements_after = dis(position, this->end());
            _size++;
            if (_size + 1 >= _capacity)
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
            return (iterator(&data[len]));
        }
        void insert (iterator position, size_type n, const value_type& val)//WORKING
        {
            int number_of_elements_after = dis(position, this->end());
            if (_size + n > _capacity)
                reserve(_size + n);
            _size = _size + n;
            int distance_vector = dis(this->begin(), this->end());
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
            int small_vec_len = dis(first, last);
            if (_size + small_vec_len >= _capacity)
            {
                if (_capacity == 0)
                    reserve(small_vec_len);
                else
                    reserve(_capacity * 2);
            }
            _size += small_vec_len;
            int distance_vector = dis(this->begin(), this->end());
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
            for (; position != last; position++)
            {
                *position = *(position + 1);
            }
            _size--;
            return(position);
        }
        iterator erase (iterator first, iterator last)
        {
            iterator ending = this->end();
            int len = dis(first, last);
            int numbers_after_erased = dis(last, ending);

            for (; numbers_after_erased && first != ending; numbers_after_erased--)
            {
                *first = *(first + len);
                first++;
            }
            _size -= len;
            return (this->end());
        }
        void swap (vector& x)
        {
            vector tmp(x);
            x = *this;
            *this = tmp;
        }
        void clear()
        {
            for (; _size >= 0; _size--)
            {
                u.destroy(data + _size);
            }
            _size = 0;
        }
        allocator_type get_allocator() const
        {
            allocator_type object(this->u);
            return (object);
        }
        ~vector()
        { 
            // this->clear();
            // u.deallocate(data, _size);

        };
        private:
            pointer_type data;
            allocator_type u;
            int _size;
            int _capacity;
            // reference operator*() const
            // {
            //     return *(data);
            // }
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