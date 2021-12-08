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
        struct node *_root;
        struct node *_left_child;
        struct node *_right_child;
        int         height;
    };
    // template< class Key, class T, class Compare = std::less<Key>, class Allocator = std::allocator</*std::*/pair<const Key, T> > >
    // class map
    // {
    //     public:
    //         typedef Key                                         key_type;
    //         typedef T                                           mapped_type;
    //         typedef pair< key_type,mapped_type>                 value_type;
    //         typedef Compare                                     key_compare;
    //         typedef Allocator                                   allocator_type;
    //         typedef typename allocator_type::reference          reference;
    //         typedef typename allocator_type::const_reference    const_reference;
    //         typedef typename allocator_type::pointer            pointer;
    //         typedef typename allocator_type::const_pointer      const_pointer;
    //         typedef size_t                                      size_type;
    //         typedef node<value_type>                            _node;
    //         typedef my_tree<value_type>                         tree;
    //         explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) :u(alloc)
    //         {
    //             _size = 0;
    //         }
    //         map (const map& x)
    //         {
    //             *this = x;
    //         }
    //         map& operator= (const map& x)
    //         {
    //             _size = x._size;
    //             _tree.tree_node._tree = x._tree;
    //             return (*this);
    //         }
    //         bool empty() const
    //         {
    //             return (_size == 0);
    //         }
    //         size_type size() const
    //         {
    //             return (_size);
    //         }
    //         size_type max_size() const
    //         {
    //             return (u.max_size);
    //         }
	// 		// pair<iterator,bool> insert (const value_type& val)
	// 		// {
	// 		// 	if (!root)
	// 		// 	{
	// 		// 		root = val;
	// 		// 		return (root);
	// 		// 	}
	// 		// 	if ()
	// 		// }
    //         private:
    //             allocator_type u;
    //             // _node _my_node;
    //             tree        _tree;
    //             size_type _size;
    // };
    template <class value_type>
    class my_tree
    {
        public:
            my_tree(/* args */)
            {
                // tree_node._value = nullptr;
                tree_node.balance_factor = 0;
                tree_node._root = nullptr;
                tree_node._left_child = nullptr;
                tree_node._right_child = nullptr;
            }
            my_tree operator= (const my_tree& x)
            {
                tree_node._value = x.tree_node._value;
                tree_node.balance_factor = x.tree_node.balance_factor;
                tree_node._root = x.tree_node._root;
                tree_node._left_child = x.tree_node._left_child;
                tree_node._righ_child = x.tree_node._righ_child;
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
                node<value_type> *nd;;
                nd->_value = pair;
                nd->_left_child = nullptr;
                nd->_right_child = nullptr;
                nd->height = 1;/*probably a 0*/
                return (nd);
            }
            node<value_type> *right_rotation(node<value_type> *nd)
            {
                node<value_type> *z = nd->_right_child;
                node<value_type> *x = nd->_left_child;
                nd->_right_child = nd;
                nd->_left_child = z;
                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);
                x->height = max(height(x->_left_child), height(x->_right_child) + 1);
                return (x);
            }
            node<value_type> *left_rotation(node<value_type> *nd)
            {
                node<value_type> *z = nd->_left_child;
                node<value_type> *x = nd->_right_child;
                nd->_left_child = nd;
                nd->_right_child = z;
                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);
                x->height = max(height(x->_left_child), height(x->_right_child) + 1);
                return (x);
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
                if (pair.first > nd->_value.first)
                {
                    nd->_right_child = insert(nd->_right_child, pair);
                }
                else
                    return (nd);
                nd->height = 1 + max(height(nd->_left_child), height(nd->_right_child));
                int balance = get_balance(nd);
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
                    return (left_rotation(nd));//right right case////
                }
                return (nd);
            }
            ~my_tree(){};
        private:
            node<value_type> tree_node;
    };
}

#endif