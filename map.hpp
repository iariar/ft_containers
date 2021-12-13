#ifndef _MAP_H__
#define _MAP_H__


#include "iostream"
#include "Vector.hpp"

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
        // struct node *_root;       
        struct node *_left_child;
        struct node *_right_child;
        int         height;
    };
    template <class value_type, class key_type>
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
                tree_node = new node<value_type>;
                if (x.tree_node)
                {
                    tree_node->_value = x.tree_node->_value ;
                    tree_node->balance_factor = x.tree_node->balance_factor;
                    tree_node->_left_child = x.tree_node->_left_child;
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
                node<value_type> *nd = new node<value_type>;
                nd->_value = pair;
                nd->balance_factor = 0;
                nd->_left_child = NULL;
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
            node<value_type> *insert(node<value_type> *nd, value_type pair)
            {
                if (nd == NULL)
                {
                    return (new_node(pair));
                }
                if (pair.first < nd->_value.first)
                {
                    nd->_left_child = insert(nd->_left_child, pair);
                }
                else if (pair.first > nd->_value.first)
                {
                    nd->_right_child = insert(nd->_right_child, pair);
                }
                else
                {
                    return (nd);
                }
                nd->height = 1 + max(height(nd->_left_child), height(nd->_right_child));
                int balance = get_balance(nd);
                nd->balance_factor = balance;
                // printf("%d\n", balance);
                if (balance > 1 && pair.first < nd->_left_child->_value.first)
                {
                    return (right_rotation(nd));//left left case////
                }
                if (balance < -1 && pair.first > nd->_right_child->_value.first)
                {
                    return (left_rotation(nd));//right right case////
                }
                if (balance > 1 && pair.first > nd->_left_child->_value.first)
                {
                    return (right_rotation(nd));//left right case////
                }
                if (balance < -1 && pair.first < nd->_right_child->_value.first)
                {
                    return (left_rotation(nd));//right left case////
                }
                return (nd);
            }
            node<value_type> *erase(node<value_type> *nd, key_type k)
            {
                if (nd == NULL)
                {
                    return (nd);
                }
                if (k < nd->_value.first)
                {
                    nd->_left_child = erase(nd->_left_child, pair);
                }
                else if (k > nd->_value.first)
                {
                    nd->_right_child = erase(nd->_right_child, pair);
                }
                else
                {
                    return (nd);
                }
                if (nd->_right_child)
                {
                    node<value_type> old_nd = nd;
                    nd = 
                }
            }
            ~my_tree(){};
            node<value_type> *tree_node;
        private:
    };
    template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator</*std::*/pair<const Key, T> > >
    class map
    {
        public:
            typedef Key                                         key_type;
            typedef T                                           mapped_type;
            typedef pair< key_type,mapped_type>                 value_type;
            typedef Compare                                     key_compare;
            typedef Allocator                                   allocator_type;
            typedef typename allocator_type::reference          reference;
            typedef typename allocator_type::const_reference    const_reference;
            typedef typename allocator_type::pointer            pointer;
            typedef typename allocator_type::const_pointer      const_pointer;
            typedef size_t                                      size_type;
            typedef node<value_type>                            _node;
            typedef my_tree<value_type, key_type>                         tree;
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
				// _tree.tree_node.balance_factor = test->balance_factor;
				// _tree.tree_node.height = test->height;
				// _tree.tree_node._left_child = test->_left_child;
				// _tree.tree_node._right_child= test->_right_child;
				// _tree.tree_node.balance_factor = test->balance_factor;
				// _tree.tree_node->_value = test->_value;
                // printf("inside insert %d\n", test->_value.first);
                _size += 1;
                // return (NULL);
			}
            size_type erase (const key_type& k)
            {
                _tree.tree_node = _tree.erase(_tree.tree_node, k);
                // int found = 0;
                // for (int i = 0; i < _size; i++)
                // {
                //     if (k == tmp.tree_node->_value.first)
                //     {
                //         found = 1;
                //     }
                //     if (k > tmp.tree_node->_value.first)
                //         tmp.tree_node = tmp.tree_node->_right_child;
                //     else if (k < tmp.tree_node->_value.first)
                //         tmp.tree_node = tmp.tree_node->_left_child;
                // }
                // if (found)
                // {
                //     if (tmp.tree_node->_right_child)

                // }                
            }
            tree        _tree;
            private:
                allocator_type u;
                // _node _my_node;
                size_type _size;
    };
}

#endif