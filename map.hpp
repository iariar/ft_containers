#ifndef _MAP_H__
#define _MAP_H__


#include "iostream"
#include "vector.hpp"
#include <stack>
#include "lexicographical_compare.hpp"
#include "pair.hpp"

namespace ft
{
	/////////////////////
    //////MAP////////////
    /////////////////////
    template <class value_type>
    struct node
    {
        value_type  _value;
        int         balance_factor;      
        struct node *_left_child;
        struct node *_right_child;
        struct node *_parent;
        int         height;
        node(){};
        node(value_type pir) : _value(pir){};
    };
    template <class value_type, class key_type, class allocator_type>
    class my_tree
    {
        public:
            typedef node<value_type> _node;
            typedef typename allocator_type::template rebind<_node>::other node_allocator;
            // typename allocator_type::rebind<node<value_type> >::other;
            // template< class U > struct rebind
            // {
            //     typedef allocator_type<U> other;
            // };
            my_tree(/* args */)
            {
                // tree_node._value = nullptr;
                // tree_node.balance_factor = 0;
                // // tree_node._root = nullptr;
                // tree_node._left_child = nullptr;
                // tree_node._right_child = nullptr;
                tree_node = nullptr;
            }
            my_tree operator= (const my_tree& x)
            {
                if (x.tree_node)
                {
                    tree_node = allocator.allocate(1);
                    allocator.construct(tree_node, x.tree_node->_value);
                    this->tree_node->balance_factor = x.tree_node->balance_factor;
                    this->tree_node->_left_child = x.tree_node->_left_child;
                    this->tree_node->_parent = x.tree_node->_parent;
                    this->tree_node->_right_child = x.tree_node->_right_child;
                }
                return (*this);
            }
            int height(_node *nd)
            {
                if (nd == NULL)
                    return (0);
                return (nd->height);
            }
            int max(int a, int b)
            {
                return (a > b ? a : b);
            }
            _node *new_node(value_type pair)
            {
                _node *nd = allocator.allocate(1);
                allocator.construct(nd, pair);
                nd->balance_factor = 0;
                nd->_left_child = NULL;
                nd->_parent= NULL;
                nd->_right_child = NULL;
                nd->height = 1;/*probably a 0*/  
                return (nd);
            }
            _node *new_node(void)
            {
                _node *nd = allocator.allocate(1);
                nd->balance_factor = 0;
                nd->_left_child = NULL;
                nd->_parent= NULL;
                nd->_right_child = NULL;
                nd->height = 1;/*probably a 0*/  
                return (nd);
            }
            void printHelper(_node *root,std::string indent, bool last) 
            {
                if (root != nullptr)
                {
                    std::cout << indent;
                    if (last) 
                    {
                        std::cout<<"R >>> ";
                        indent += "     ";
                    } 
                    else 
                    {
                        std::cout<<"L >>> ";
                        indent += "|    ";
                    }
                    std::cout<<root->_value.first<<"( BF = " << root->height << ")"<<std::endl;
                    printHelper(root->_left_child, indent, false);
                    printHelper(root->_right_child, indent, true);
                }
            }
            void prettyPrint() {
                printHelper(this->tree_node, "", true);
            }
            _node *right_rotation(_node *nd, _node *root)
            {
                _node *old_left = nd->_left_child;

                nd->_left_child = old_left->_right_child;          //////connect left child's right child to nd////
                if (old_left->_right_child)
                    old_left->_right_child->_parent = nd;/**/

                old_left->_parent = nd->_parent;            /////////connect nd's left child to nd's parent//////
    
                if (nd->_parent == root)                    /////in case nd was connected to end update root/////
                    root->_left_child = old_left;
                else if (nd == nd->_parent->_left_child)    /////////connect nd's parent to nd's right child as a child//////
                    nd->_parent->_left_child = old_left;
                else
                    nd->_parent->_right_child = old_left;

                old_left->_right_child = nd;                /////connect nd and it's left child//////
                nd->_parent = old_left;

                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);
                old_left->height = max(height(old_left->_left_child), height(old_left->_right_child) + 1);
                old_left->balance_factor = get_balance(old_left);
                return (old_left);
            }
            _node *left_rotation(_node *nd, _node *root)
            {
                _node *old_right = nd->_right_child;

                nd->_right_child = old_right->_left_child;
                if (old_right->_left_child)                     //////connect right child's left child to nd////
                    old_right->_left_child->_parent = nd;

                old_right->_parent = nd->_parent;       /////////connect nd's right child to nd's parent//////

                if (nd->_parent == root)                /////in case nd was connected to end update root/////
                    root = old_right;
                else if (nd->_parent->_right_child == nd)
                    nd->_parent->_right_child = old_right;  /////////connect nd's parent to nd's right child as a child//////
                else
                    nd->_parent->_left_child = old_right;

                old_right->_left_child = nd; /////connect nd and it's right child//////
                nd->_parent = old_right;

                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);  ///update height by choosing the biggest height of the subtrees///
                old_right->height = max(height(old_right->_left_child), height(old_right->_right_child) + 1);
                old_right->balance_factor = get_balance(old_right); ////update balance///
                return (old_right);
            }
            int get_balance(_node *nd)
            {
                if (nd == NULL)
                {
                    return (0);
                }
                return (height(nd->_left_child) - height(nd->_right_child));
            }
            _node *prev_node(_node *nd, key_type k, int *side)
            {
                _node *prev = NULL;
                _node *tmp = nd;
                (*side) = 0;
                while (nd)
                {
                    if (k > nd->_value.first)
                    {
                        prev = nd;
                        (*side) = 1;
                        nd = nd->_right_child;
                    }
                    else if (k < nd->_value.first)
                    {
                        prev = nd;
                        (*side) = 2;
                        nd = nd->_left_child;
                    }
                    else
                    {
                        if (tmp == nd && (*side) == 0)/*in case root is getting checked zon it's on the left*/
                            (*side) = 2;
                        return(nd);
                    }
                }
                return (prev);
            }
            _node *copy_insert(_node *nd, _node *x)
            {
                if (x)  //PREORDER TRAVERSAL//
                {
                    nd = new_node(x->_value);                       /*INSERT CURRENT NODE*/
                    copy_insert(nd->_left_child, x->_left_child);/*TRAVESES to the left node first then right*/
                    copy_insert(nd->_right_child, x->_right_child);
                }
                return (x);
            }
            _node *insert(_node *nd, value_type pair, _node *root)
            {
                _node *tmp = nd;
                _node *parent = NULL;
                if (tmp == NULL)
                {  
                    return (new_node(pair));
                }
                while (tmp)
                {
                    parent  = tmp;
                    if (pair.first < tmp->_value.first)
                        tmp = tmp->_left_child;
                    else if (pair.first > tmp->_value.first)
                        tmp = tmp->_right_child;
                    else
                    {
                        return(nd);
                    }
                }
                int side = 0;
                // parent = prev_node(nd, pair.first, &side);
                if (pair.first < parent->_value.first)
                    parent->_left_child = tmp = new_node(pair);
                else if (pair.first > parent->_value.first)
                    parent->_right_child = tmp = new_node(pair);
                tmp->_parent = parent;
                while (tmp && tmp != nd->_parent)
                {
                    tmp->height = 1 + max(height(tmp->_left_child), height(tmp->_right_child));
                    int balance = get_balance(tmp);
                    tmp->balance_factor = balance;
                    if (balance > 1 && pair.first < tmp->_left_child->_value.first)
                    {
                        return (right_rotation(tmp, root));//left left case////
                    }
                    if (balance < -1 && pair.first > tmp->_right_child->_value.first)
                    {
                        return (left_rotation(tmp, root));//right right case////
                    }
                    if (balance > 1 && pair.first > tmp->_left_child->_value.first)
                    {
                        tmp->_left_child = left_rotation(tmp->_left_child, root);
                        return (right_rotation(tmp, root));//left right case////
                    }
                    if (balance < -1 && pair.first < tmp->_right_child->_value.first)
                    {
                        tmp->_right_child = left_rotation(tmp->_left_child, root);
                        return (left_rotation(tmp, root));//right left case////
                    }
                    tmp = tmp->_parent;
                }
                if (root != nd->_parent)
                    return (root)
                return (nd);
            }
            _node *erase(_node *nd, key_type k)
            {
                _node *tmp = nd;
                _node *prev = NULL;
                int side;

                if (nd == NULL)
                {
                    return (NULL);
                }
                while(nd)
                {
                    if (k < nd->_value.first && nd->_left_child)
                    {
                        nd = nd->_left_child;
                    }
                    else if (k > nd->_value.first && nd->_right_child)
                    {
                        nd = nd->_right_child;                                                  /*MAY NEED TO FIX HEIGHT / BALANCE*/
                    }
                    else
                    {
                        prev = prev_node(tmp, nd->_value.first, &side);
                        if (!nd->_right_child && !nd->_left_child)
                        {
                            if (side == 1)
                                nd->_parent->_right_child = nullptr;
                            else
                                nd->_parent->_left_child = nullptr;
                            if (nd == tmp)
                                return (NULL);
                        }
                        else if (nd->_right_child && !nd->_left_child)
                        {
                            if (side == 1)
                            {
                                nd->_parent->_right_child = nd->_right_child;
                            }
                            else if (side == 2)
                            {
                                nd->_parent->_left_child = nd->_right_child;
                            }
                            nd->_right_child->_parent = nd->_parent;/*debatable*//*NOT*/
                            if (nd == tmp)
                                return (nd->_right_child);
                        }
                        else if (nd->_left_child && !nd->_right_child)
                        {
                            if (side == 1)
                            {
                                nd->_parent->_right_child = nd->_left_child;
                            }
                            else if (side == 2)
                            {
                                nd->_parent->_left_child = nd->_left_child;
                            }
                            nd->_left_child->_parent = nd->_parent;
                            if (nd == tmp)
                                return (nd->_right_child);
                        }
                        else
                        {
                            _node *tr_min = tree_min(nd->_right_child);
                            _node *old_nd = nd;
                            _node *old_right = nd->_right_child;
                            _node *old_left = nd->_left_child;
                            _node *old_parent = nd->_parent;
                            //////place tr_min in place of nd that we want to erase///////
                            if (nd->_parent)
                            {
                                prev_node(tmp, nd->_value.first, &side);////if nd is not root place tr_min on it's right or left depending on wich side nd was////
                                if (side == 1)
                                {
                                    nd->_parent->_right_child = tr_min;                                      /*VERY DEBATABLE SINCE I CHANGED THE PARENT OF ROOT TO END*/
                                }
                                else if (side == 2)
                                    nd->_parent->_left_child = tr_min;
                            }
                            ///PARKOUR///
                            nd = tr_min;
                            nd->_parent = old_parent;
                            nd->_right_child = old_right;
                            nd->_left_child = old_left;
                            old_right->_parent = nd;
                            old_left->_parent = nd;
                            side = 0;
                            ///REMOVE TR_MIN FROM ORIGINAL PLACE////
                            /*prev = */prev_node(nd, tr_min->_value.first, &side);
                            if (side == 1)
                            {
                                tr_min->_parent->_right_child = NULL;
                            }
                            else if (side == 2)
                            {
                                tr_min->_parent->_left_child = NULL;
                            }
                            if (old_nd == tmp)
                                return (nd);
                            // nd->_parent = prev;
                        }
                        break ;
                    }
                }
                // nd->height = 1 + max(height(nd->_left_child), height(nd->_right_child));
                // int balance = get_balance(nd);
                // nd->balance_factor = balance;
                // // std::cout << "balance factor = " << balance << std::endl;
                // if (balance > 1 && k < nd->_left_child->_value.first)
                // {
                //     return (right_rotation(nd));//left left case////
                // }
                // if (balance < -1 && k > nd->_right_child->_value.first)
                // {
                //     return (left_rotation(nd));//right right case////
                // }
                // if (balance > 1 && k > nd->_left_child->_value.first)
                // {
                //     nd->_left_child = left_rotation(nd->_left_child);
                //     return (right_rotation(nd));//left right case////
                // }
                // if (balance < -1 && k < nd->_right_child->_value.first)
                // {
                //     nd->_right_child = left_rotation(nd->_left_child);
                //     return (left_rotation(nd));//right left case////
                // }
                // if(nd->_parent)//IN CASE OF ROOT TO BE REMOVED TMP HAS OLD ROOT
                //     return (nd);
                return (tmp);
            }
            void    destroy_node(_node *nd)
            {
                allocator.destroy(nd);
                allocator.deallocate(nd, 1);
            }
            ~my_tree(){};
            _node *tree_node;
        private:
            node_allocator allocator;
    };
    template <class node_>
    node_ *tree_min(node_ *nd)
    {
        while (nd && nd->_left_child)
        {
            nd = nd->_left_child;
        }
        return (nd);
    }
    template <class node_>
    node_ *tree_max(node_ *nd)
    {
        while (nd && nd->_right_child)
        {
            nd = nd->_right_child;
        }
        return (nd);
    }
    template <class node_>
    int wich_parent_side(node_ *nd, node_ *nd_parent)
    {
        if (nd && nd_parent)
        {
            if (nd == nd_parent->_right_child)
                return (1);
            else if (nd == nd_parent->_left_child)
                return (2);
            else
                return (0);
        }
        return (-1);
    }
    template <class node_>
    node_ *find_successor(node_ * nd)
    {
        if (nd)
        {
            if (nd->_right_child)
            {
                return (tree_min(nd->_right_child));
            }
            else
            {
                int side = 0;
                side = wich_parent_side(nd, nd->_parent);
                if (side == 2)
                {
                    return (nd->_parent);
                }
                else/* if(side == 1)*/
                {
                    while((side = wich_parent_side(nd, nd->_parent)) == 1)
                    {
                        nd = nd->_parent;
                    }
                    return (nd->_parent);
                }
            }
        }
        return (NULL);
    }
    template <class node_>
    node_ *find_predeccessor(node_ * nd)
    {
        if (nd->_left_child)
        {
            return (tree_max(nd->_left_child));
        }
        else
        {
            int side = 0;
            side = wich_parent_side(nd, nd->_parent);
            if (side == 1)
            {
                return (nd->_parent);
            }
            else/* if(side == 2)*/
            {
                while((side = wich_parent_side(nd, nd->_parent)) == 2)
                {
                    nd = nd->_parent;
                }
                return (nd->_parent);
            }
            // else
            //     std::cout << "Error in wich_parent func" << std::endl;
        }
        return (NULL);
    }
    template <class value_type, class node_pointer>
    class my_map_iterator
    {
        typedef value_type*        pointer;
        typedef value_type&        reference;
        typedef node_pointer       nodePtr;

        private:
        public:
            nodePtr _ptr;
            my_map_iterator():_ptr(){}
            my_map_iterator(nodePtr ptr):_ptr(ptr){}
            template <class iterator>
            my_map_iterator(const iterator &it)
            {
                this->_ptr = it._ptr;
            }
            my_map_iterator operator=(const my_map_iterator &it)
            {
                this->_ptr = it._ptr;
                return (*this);
            }
            reference operator*() const
            {
                return (_ptr->_value);
            }
            pointer operator->() const
            {
                return (&_ptr->_value);
            }
            my_map_iterator &operator++()
            {
                this->_ptr = find_successor(_ptr);
                return (*this);
            }
            my_map_iterator operator++(int)       /*COULD BE WRONG*/
            {
                my_map_iterator tmp = *this;
                this->_ptr = find_successor(_ptr);
                return (tmp);
            }
            my_map_iterator &operator--()
            {
                this->_ptr = find_predeccessor(_ptr);
                return (*this);
            }
            my_map_iterator operator--(int)       /*COULD BE WRONG*//*RETURNS DECREMENTED VALUE IN THE SAME LINE*/
            {
                my_map_iterator tmp = *this;
                this->_ptr = find_predeccessor(_ptr);
                return (tmp);
            }
            ~my_map_iterator(){};
    };
    template <class value_type, class node_pointer>
    bool operator== (const my_map_iterator<value_type, node_pointer>& lhs, const my_map_iterator<value_type, node_pointer>& rhs)
    {
        if (lhs._ptr->_value == rhs._ptr->_value && lhs._ptr->_left_child == rhs._ptr->_left_child && lhs._ptr->_right_child == rhs._ptr->_right_child && lhs._ptr->_parent == rhs._ptr->_parent)
            return (1);
        return (0);
    }
    template <class value_type, class node_pointer>
    bool operator!= (const my_map_iterator<value_type, node_pointer>& lhs, const my_map_iterator<value_type, node_pointer>& rhs)
    {
        if (lhs._ptr->_value != rhs._ptr->_value || lhs._ptr->_left_child != rhs._ptr->_left_child || lhs._ptr->_right_child != rhs._ptr->_right_child || lhs._ptr->_parent != rhs._ptr->_parent)
        {
            return (1);
        }
        return (0);
    }
    template <class T>
    class my_map_reverse_iterator
    {
        typedef typename T::pointer        pointer;
        typedef typename T::reference       reference;
        // typedef node_pointer       nodePtr;
        typedef T                  iterator_type;

        private:
            iterator_type _iterator;
        public:
            // nodePtr _ptr;
            my_map_reverse_iterator():_iterator(){};
            my_map_reverse_iterator(iterator_type it):_iterator(it){}
            my_map_reverse_iterator(const my_map_reverse_iterator  &it)
            {
                this->_iterator = it._iterator;
            }
            my_map_reverse_iterator operator=(const my_map_reverse_iterator &it)
            {
                this->_iterator = it._iterator;
                return (*this);
            }
            reference operator*() const
            {
                return (_iterator._ptr->value);
            }
            pointer operator->() const
            {
                return (&_iterator._ptr->_value);
            }
            my_map_reverse_iterator &operator++()
            {
                _iterator._ptr = find_predeccessor(_iterator._ptr);
                return (*this);
            }
            my_map_reverse_iterator operator++(int)       /*COULD BE WRONG*//*RETURNS DECREMENTED VALUE IN THE SAME LINE*/
            {
                my_map_reverse_iterator tmp = *this;
                this->_iterator._ptr = find_predeccessor(_iterator._ptr);
                return (tmp);
            }
            my_map_reverse_iterator &operator--()
            {
                this->_iterator._ptr = find_successor(_iterator._ptr);
                return (*this);
            }
            my_map_reverse_iterator operator--(int)       /*COULD BE WRONG*/
            {
                my_map_reverse_iterator tmp = *this;
                this->_iterator._ptr= find_successor(_iterator._ptr);
                return (tmp);
            }
            ~my_map_reverse_iterator(){};
    };
    template <class iterator>
    bool operator== (const my_map_reverse_iterator<iterator>& lhs, const my_map_reverse_iterator<iterator>& rhs)
    {
        if (lhs == rhs)
            return (1);
        return (0);
    }
    template <class iterator>
    bool operator!= (const my_map_reverse_iterator<iterator>& lhs, const my_map_reverse_iterator<iterator>& rhs)
    {
        if (lhs != rhs)
        {
            return (1);
        }
        return (0);
    }
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator<pair<const Key, T> > >
    class map
    {
        public:
            typedef Compare                                                     key_compare;
            typedef Key                                                         key_type;
            template <class value_type>
            class my_less
            {
                public:
                key_compare cmp;
                my_less(Compare c) : cmp(c){};/*DUNNO ABOUT THIS*/
                my_less(){};
                bool operator() (const value_type& x, const value_type& y) 
                {
                    return cmp(x.first , y.first);
                }
            };
            typedef T                                                           mapped_type;
            typedef pair<const key_type,mapped_type>                            value_type;

            typedef my_less<value_type>                                         value_compare;

            typedef node<value_type>                                            _node;
            typedef Allocator                                                   allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef my_map_iterator<value_type, _node *>                        iterator;
            typedef my_map_iterator<const value_type, _node *>                  const_iterator;
            typedef my_map_reverse_iterator<iterator>                           reverse_iterator;
            typedef my_map_reverse_iterator<const_iterator>                     const_reverse_iterator;
            typedef ptrdiff_t                                                   differende_type;
            typedef size_t                                                      size_type;
            typedef my_tree<value_type, key_type, allocator_type>               tree;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : u(alloc)
            {
                _size = 0;
                // _node *tmp;
                // _tree.tree_node = _tree.new_node();
                // tmp = _tree.tree_node;
                // _tree.tree_node->_left_child = _tree.new_node();
                // _tree.tree_node = _tree.tree_node->_left_child;
                // _tree.tree_node->_parent = tmp;
                // root = tmp;
                // _node *tmp =  _tree.tree_node;
                // _tree.tree_node = _tree.tree_node->_left_child;
                // std::cout << "!" << std::endl;
                // _tree.tree_node->_parent = tmp;
                // std::cout << "3" << std::endl;
            }
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : u(alloc)
            {
                _size = 0;
                if (first._ptr)
                {
                    _tree.tree_node = _tree.new_node();
                    // std::cout << _tree.tree_node->_value.first;
                    _node *tmp =  _tree.tree_node;
                    // root = _tree.tree_node;
                    _tree.tree_node = _tree.tree_node->_left_child;
                    for (; first != last; first++)
                    {
                        _tree.tree_node = _tree.insert(_tree.tree_node, first._ptr->_value, root);
                        _size++;
                    }
                    _tree.tree_node->_parent = tmp;
                }
            }
            map (const map& x)
            {
                *this = x;
            }
            map& operator= (const map& x)
            {
                _size = x._size;
                _tree.tree_node = _tree.copy_insert(_tree.tree_node, x._tree.tree_node);       
                return (*this);
            }
            bool empty() const
            {
                return (_size == 0);
            }
            size_type size() const
            {
                return (_size);
            }
            size_type max_size() const
            {
                return (u.max_size());
            }
            mapped_type& operator[] (const key_type& k)
            {
                tree tmp = _tree;
                while (tmp.tree_node)
                {
                    if (k == tmp.tree_node->_value.first)
                        return (tmp.tree_node->_value.second);
                    if (k > tmp.tree_node->_value.first)
                    {
                        tmp.tree_node = tmp.tree_node->_right_child;
                    }
                    else if (k < tmp.tree_node->_value.first)
                    {
                        tmp.tree_node = tmp.tree_node->_left_child;
                    }
                }
                if (tmp.tree_node)
                    return (tmp.tree_node->_value.second);
                else
                {
                    return insert(ft::make_pair (k, NULL)).first->second;//////////NEED TO FIX INSERT RETUTRN VALUE///////////
                }
            }
			pair<iterator, bool> insert (const value_type& val)
			{
                int init_parent = 0;
                if (!_tree.tree_node)
                    init_parent = 1;
                if (count(val.first))
                {
                    return ft::make_pair (find(val.first), 0);///////return pair who's first type is an iterator pointing to where it found it and 0 in case it was there /////
                }
                _tree.tree_node = _tree.insert(_tree.tree_node, val, root);
                if (init_parent)
                {
                    _tree.tree_node->_parent = _tree.new_node();
                    _tree.tree_node->_parent->_left_child = _tree.tree_node;
                    root = _tree.tree_node->_parent;
                }
                // if (_size == 0)
                //     _tree.tree_node->_parent = root;
                _size += 1;
                return (ft::make_pair (find(val.first), 1));
			}
            iterator insert (iterator position, const value_type& val)
            {
                int init_parent = 0;
                if (!_tree.tree_node)
                    init_parent = 1;
                position = insert(val).first;
                if (init_parent)
                {
                    _tree.tree_node->_parent = _tree.new_node();
                    _tree.tree_node->_parent->_left_child = _tree.tree_node;
                    root = _tree.tree_node->_parent;
                }
                return (position);
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                int init_parent = 0;
                if (!_tree.tree_node)
                    init_parent = 1;
                for (; first != last; first++)
                {
                    insert(first._ptr->_value);
                }
                if (init_parent)
                {
                    _tree.tree_node->_parent = _tree.new_node();
                    _tree.tree_node->_parent->_left_child = _tree.tree_node;
                    root = _tree.tree_node->_parent;
                }
            }
            void erase (iterator position)
            {
                erase(position->first);
            }
            size_type erase (const key_type& k)
            {
                _tree.tree_node = _tree.erase(_tree.tree_node, k);
                _size--;   
                return (1);           
            }
            void erase (iterator first, iterator last)
            {
                iterator tmp = first;
                for (; tmp != last;/* first++*/)
                {
                    first = tmp;
                    tmp++;
                    erase(first);
                }  
            }
            iterator begin()
            {
                return (iterator(tree_min(_tree.tree_node)));
            }
            const_iterator begin() const
            {
                return (const_iterator(tree_min(_tree.tree_node)));
            }
            iterator end()
            {
                // std::cout << find_successor(tree_max(_tree.tree_node))->_value.second<< " sk" << std::endl; 
                // iterator test = tree_max(_tree.tree_node);
                // test++;
                // std::cout << "here" << std::endl;
                // std::cout << test->first << std::endl;
                // std::cout << "here2" << std::endl; 
                return (++iterator(tree_max(_tree.tree_node)));
            }
            const_iterator end() const
            {
                return (const_iterator(_tree.tree_node->_parent));
            }
            // const_iterator cbegin()
            // {
            //     return (const_iterator(tree_min(_tree.tree_node)));
            // }
            // const_iterator cend()
            // {
            //     return (const_iterator(tree_max(_tree.tree_node))++);
            // }
            reverse_iterator rbegin()
            {
                return (++reverse_iterator(tree_max(_tree.tree_node)));
            }
            reverse_iterator rend()
            {
                return (reverse_iterator(tree_min(_tree.tree_node)));
            }
            iterator find (const key_type& k) 
            {
                // if (_size == 0)
                // {
                //     return (this->end());       //////TEMPORARY CONDITION TILL I FIX THIS->END()////////
                // }
                iterator it = this->begin();
                for (iterator it = this->begin(); it != this->end(); it++)
                {
                    if (k == it->first)
                        return (it);
                }
                return (this->end()); 
            }
            const_iterator find (const key_type& k) const
            {
                // if (_size == 0)
                // {
                //     return (this->end());       //////TEMPORARY CONDITION TILL I FIX THIS->END()////////
                // }
                iterator it = this->begin();
                for (iterator it = this->begin(); it != this->end(); it++)
                {
                    if (k == it->first)
                        return (it);
                }
                return (this->end()); 
            }
            size_type count (const key_type& k) const
            {
                // if (find(k) == this->end())
                //     return (0);
                // return(1);
                if (_size == 0)
                    return(0);
                return ( const_cast<map *>(this)->find(k) == const_cast<map *>(this)->end() ? 0 : 1);///////////calling a non-const func inside a const func/////////
            }
            void swap (map& x)
            {
                map tmp = *this;
                this->_tree = x._tree;
                this->_size = x._size;
                x._tree = tmp._tree;
                x._size = tmp._size;
            }
            void clear()
            {
                iterator it = this->begin();
                iterator finish = this->end();
                iterator tmp = it;
                for (; tmp != finish ;/* it++*/)
                {
                    it = tmp;
                    tmp++;
                    erase(it._ptr);
                    _tree.destroy_node(it._ptr);
                }
            }
            key_compare key_comp() const
            {
                key_compare ret;
                return (ret);
            }
            value_compare value_comp() const
            {
                value_compare ret(key_comp());
                return (ret);
            }
            iterator lower_bound (const key_type& k)
            {
                if (count(k))
                    return (find(k));
                else
                {
                    iterator it = this->begin();
                    while (it != this->end() && it->first < k)
                    {
                        it++;
                    }
                    if (it == this->end())
                        return (this->end());
                    else
                    {
                        return --it;
                    }
                }
                // return (this->end());
            }
            const_iterator lower_bound (const key_type& k) const
            {
                if (count(k))
                    return (find(k));
                else
                {
                    iterator it = this->begin();
                    while (it != this->end() && it->first < k)
                    {
                        it++;
                    }
                    if (it == this->end())
                        return (this->end());
                    else
                    {
                        return --it;
                    }
                }
            }
            iterator upper_bound (const key_type& k)
            {
                if (count(k))
                    return (++find(k));
                else
                {
                    iterator it = this->end();
                    while (it != this->begin() && it->first > k)
                    {
                        it--;
                    }
                    if (it == this->begin())
                        return (this->end());
                    else
                    {
                        return ++it;
                    }
                }
                // return (this->end());
            }
            const_iterator upper_bound (const key_type& k) const
            {
                if (count(k))
                    return (++find(k));
                else
                {
                    iterator it = this->end();
                    while (it != this->begin() && it->first > k)
                    {
                        it--;
                    }
                    if (it == this->begin())
                        return (this->end());
                    else
                    {
                        return ++it;
                    }
                }
            }
            pair<iterator,iterator> equal_range (const key_type& k)
            {
                if (count(k))
                    return (ft::make_pair<iterator, iterator> (find(k), ++find(k)));
                if (k > tree_max(_tree.tree_node)->_value.first)
                {
                    return(ft::make_pair<iterator, iterator> (this->end(), this->end()));
                }
                else
                    return (ft::make_pair<iterator, iterator> (lower_bound(k), upper_bound(k)));
            }
            pair<const_iterator,const_iterator> equal_range (const key_type& k) const
            {
                if (count(k))
                    return (ft::make_pair<iterator, iterator> (find(k), ++find(k)));
                if (k > tree_max(_tree.tree_node)->_value.first)
                {
                    return(ft::make_pair<iterator, iterator> (this->end(), this->end()));
                }
                else
                    return (ft::make_pair<iterator, iterator> (lower_bound(k), upper_bound(k)));
            }
            tree        _tree;
            private:
                _node *root;
                allocator_type u;
                size_type _size;
    };
}

#endif