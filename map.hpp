#ifndef _MAP_H__
#define _MAP_H__


#include "iostream"
#include "Vector.hpp"

namespace ft
{
	/////////////////////
    //////MAP////////////
    /////////////////////

//     template <class _NodePtr>
// _NodePtr  tree_min(_NodePtr __x) 
// {
//     while (__x->__left_ != nullptr)
//         __x = __x->__left_;
//     return __x;
// }


    template <class value_type>
    struct node
    {
        value_type  _value;
        int         balance_factor;
        // struct node *_root;       
        struct node *_left_child;
        struct node *_right_child;
        struct node *_parent;
        int         height;
        node(){};
        node(value_type pir) : _value(pir){};
    };
    // template <class value_type, class __node_pointer>
    // class __tree_iterator{
    //     typedef value_type *        pointer;

    //     typedef __node_pointer       nodePtr;

    //     private:
    //         nodePtr _ptr;
    //     public:
    //         __tree_iterator(nodePtr ptr):_ptr(ptr){}
    // };

    template <class value_type, class key_type, class allocator_type>
    class my_tree
    {
        public:
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
                    tree_node = new node<value_type>(x.tree_node->_value);
                    // tree_node->_value = new node<value_type>(x.tree_node->_value);
                    tree_node->balance_factor = x.tree_node->balance_factor;
                    tree_node->_left_child = x.tree_node->_left_child;
                    tree_node->_parent = x.tree_node->_parent;
                    tree_node->_right_child = x.tree_node->_right_child;
                }
                return (*this);
            }
            int height(node<value_type> *nd)
            {
                if (nd == NULL)
                    return (0);
                return (nd->height);
            }
            int max(int a, int b)
            {
                return (a > b ? a : b);
            }
            node<value_type> *new_node(value_type pair)
            {
                node<value_type> *nd = new node<value_type>(pair);
                // nd = test;
                // nd->_value = pair;
                nd->balance_factor = 0;
                nd->_left_child = NULL;
                nd->_parent= NULL;
                nd->_right_child = NULL;
                nd->height = 1;/*probably a 0*/
                return (nd);
            }
            node<value_type> *right_rotation(node<value_type> *nd)
            {
                node<value_type> *old_left = nd->_left_child;
                node<value_type> *old_left_right = old_left->_right_child;

                old_left->_right_child = nd;
                nd->_left_child = old_left_right;

                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);
                old_left->height = max(height(old_left->_left_child), height(old_left->_right_child) + 1);
                old_left->balance_factor = get_balance(old_left);
                return (old_left);
            }
            node<value_type> *left_rotation(node<value_type> *nd)
            {
                node<value_type> *old_right = nd->_right_child;
                node<value_type> *old_right_left = old_right->_left_child;

                old_right->_left_child = nd;
                nd->_right_child = old_right_left;

                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);
                old_right->height = max(height(old_right->_left_child), height(old_right->_right_child) + 1);
                old_right->balance_factor = get_balance(old_right);
                return (old_right);
            }
            int get_balance(node<value_type> *nd)
            {
                if (nd == NULL)
                {
                    return (0);
                }
                return (height(nd->_left_child) - height(nd->_right_child));
            }
            // node<value_type> *tree_min(){
            //     tree_min_helper(tree_node);
            // }
            node<value_type> *tree_min/*_helper*/(node<value_type> *nd)
            {
                while (nd && nd->_left_child)
                {
                    nd = nd->_left_child;
                }
                return (nd);
            }
            node<value_type> *tree_max(node<value_type> *nd)
            {
                while (nd && nd->_right_child)
                {
                    nd = nd->_right_child;
                }
                return (nd);
            }
            node<value_type> *prev_node(node<value_type> *nd, key_type k, int *side)
            {
                node<value_type> *prev = NULL;
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
                        return(prev);
                    }
                }
                return (prev);
            }
            node<value_type> *insert(node<value_type> *nd, value_type pair)
            {
                node<value_type> *tmp = nd;
                node<value_type> *parent = NULL;
                if (tmp == NULL)
                {
                    return (new_node(pair));
                }
                while (tmp)
                {
                    if (pair.first < tmp->_value.first)
                        tmp = tmp->_left_child;
                    else if (pair.first > tmp->_value.first)
                        tmp = tmp->_right_child;
                    else
                    {
                        return(tmp);
                    }
                }
                int side = 0;
                parent = prev_node(nd, pair.first, &side);
                if (pair.first < parent->_value.first)
                    parent->_left_child = tmp = new_node(pair);
                else if (pair.first > parent->_value.first)
                    parent->_right_child = tmp = new_node(pair);
                tmp->_parent = parent;
                // nd->height = 1 + max(height(nd->_left_child), height(nd->_right_child));
                // int balance = get_balance(nd);
                // nd->balance_factor = balance;
                // if (balance > 1 && pair.first < nd->_left_child->_value.first)
                // {
                //     return (right_rotation(nd));//left left case////
                // }
                // if (balance < -1 && pair.first > nd->_right_child->_value.first)
                // {
                //     return (left_rotation(nd));//right right case////
                // }
                // if (balance > 1 && pair.first > nd->_left_child->_value.first)
                // {
                //     return (right_rotation(nd));//left right case////
                // }
                // if (balance < -1 && pair.first < nd->_right_child->_value.first)
                // {
                //     return (left_rotation(nd));//right left case////
                // }
                return (nd);
            }
            node<value_type> *erase(node<value_type> *nd, key_type k)
            {
                node<value_type> *tmp = nd;
                node<value_type> *prev = NULL;
                int side;

                if (nd == NULL)
                {
                    return (NULL);
                }
                while(nd)
                {
                    if (k < nd->_value.first && nd->_left_child)
                    {
                        // prev = nd;
                        nd = nd->_left_child;
                        // continue;
                    }
                    else if (k > nd->_value.first && nd->_right_child)
                    {
                        // prev = nd;
                        nd = nd->_right_child;                                                  /*MAY NEED TO FIX HEIGHT / BALANCE*/
                        // continue;
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
                        }
                        else if (nd->_right_child && !nd->_left_child)
                        {
                            if (side == 1)
                            {
                                prev->_right_child = nd->_right_child;;
                            }
                            else if (side == 2)
                            {
                                prev->_left_child = nd->_right_child;;
                            }
                            nd->_parent = prev;/*debatable*/
                        }
                        else if (nd->_left_child && !nd->_right_child)
                        {
                            // prev = prev_node(tmp, nd->_value.first, &side);
                            if (side == 1)
                            {
                                prev->_right_child = nd->_left_child;
                            }
                            else if (side == 2)
                            {
                                prev->_left_child = nd->_left_child;
                            }
                            nd->_parent = prev;
                        }
                        else
                        {
                            node<value_type> *tr_min = tree_min(nd->_right_child);
                            node<value_type> *old_right = nd->_right_child;
                            node<value_type> *old_left = nd->_left_child;
                            node<value_type> *old_parent = nd->_parent;
                            //////place tr_min in place of nd that we want to erase///////
                            if (nd->_parent)
                            {
                                prev_node(tmp, nd->_value.first, &side);////if nd is not root place tr_min on it's right or left depending on wich side nd was////
                                if (side == 1)
                                {
                                    nd->_parent->_right_child = tr_min;
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
                //     return (right_rotation(nd));//left right case////
                // }
                // if (balance < -1 && k < nd->_right_child->_value.first)
                // {
                //     return (left_rotation(nd));//right left case////
                // }
                if(!nd->_parent)//IN CASE OF ROOT TO BE REMOVED TMP HAS OLD ROOT
                    return (nd);
                return (tmp);
            }
            ~my_tree(){};
            node<value_type> *tree_node;
        private:
            allocator_type alloc;
    };
    // template <typename map_type>
    // class my_map_iterator
    // {
    //     public:
    //     // typedef std::bidirectional_iterator_tag iterator_category;
    //         // typedef typename map_type::tree iterator_tree_type;
    //         // typedef typename map_type::key_type key_type;
    //         // typedef typename map_type::value_type value_type;
    //         // typedef typename map_type::_node iterator_node;
    //         key_type    first;
    //         value_type  second;
    //         iterator_tree_type iterator_tree; 
    //         // iterator_node
    //         // node        iterator_node;
    //         my_map_iterator()/* : first(0), second(0)*/
    //         {
                
    //         };
    //         my_map_iterator(my_map_iterator const &x)
    //         {
    //             this->first = x.first;
    //             this->second = x.second;
    //         };
    //         // my_map_iterator(node *nd)
    //         // {
    //         //     iterator_node = nd;
    //         //     first = nd->_value.first;
    //         // }
    //         my_map_iterator operator=(my_map_iterator const &x)
    //         {
    //             this->first = x.first;
    //             this->second = x.second;
    //             return (*this);
    //         };
    //         ~my_map_iterator();

    // };
    template <class value_type, class node_pointer>
    class my_map_iterator
    {
        typedef value_type*        pointer_to_value;
        typedef node_pointer       nodePtr;

        private:
            nodePtr _ptr;
        public:
            my_map_iterator(nodePtr ptr):_ptr(ptr){}

    };
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator</*std::*/pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair<const key_type,mapped_type>            value_type;
            typedef Compare                                     key_compare;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;
            typedef node<value_type>                            _node;
            typedef my_tree<value_type, key_type, allocator_type>               tree;
            // typedef my_map_iterator<map>       iterator;

            typedef my_map_iterator<value_type, _node *>    iterator;
            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :u(alloc)
            {
                _size = 0;
            }
            map (const map& x)
            {
                *this = x;
            }
            map& operator= (const map& x)
            {
                _size = x._size;
                _tree = x._tree;
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
                return (u.max_size);
            }
            mapped_type& operator[] (const key_type& k)
            {
                tree tmp = _tree;
                for (size_t i = 0; i < _size; i++)
                {
                    if (k == tmp.tree_node->_value.first)
                        return (tmp.tree_node->_value.second);
                    if (k > tmp.tree_node->_value.first)
                        tmp.tree_node = tmp.tree_node->_right_child;
                    else if (k < tmp.tree_node->_value.first)
                        tmp.tree_node = tmp.tree_node->_left_child;
                } 
                return (tmp.tree_node->_value.second);
            }
			void insert (const value_type& val)
			{
                _tree.tree_node = _tree.insert(_tree.tree_node, val);
                _size += 1;
			}
            size_type erase (const key_type& k)
            {
                _tree.tree_node = _tree.erase(_tree.tree_node, k);
                _size--;   
                return (1);           
            }
            iterator begin()
            {
                return (iterator(_tree.tree_min()));
            }
            iterator end()
            {
                return (iterator(_tree.tree_max()));
            }
            // const_iterator begin() const;
            tree        _tree;
            private:
                allocator_type u;
                // _node _my_node;
                size_type _size;
    };
}

#endif