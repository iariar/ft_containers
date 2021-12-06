#ifndef _MAP_H__
#define _MAP_H__


#include "iostream"
#include "vector.hpp"

namespace ft
{
	/////////////////////
    //////MAP////////////
    /////////////////////
    template <class value_type>
    struct node
    {
        value_type  _value;
        int         balace_factor;
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
                tree_node.value = 0;
                tree_node.balance_factor = 0;
                tree_node.root = nullptr;
                tree_node._left_child = nullptr;
                tree_node._righ_child = nullptr;
            }
            my_tree operator= (const my_tree& x)
            {
                tree_node.value = x.tree_node.value;
                tree_node.balance_factor = x.tree_node.balance_factor;
                tree_node.root = x.tree_node.root;
                tree_node._left_child = x.tree_node._left_child;
                tree_node._righ_child = x.tree_node._righ_child;
            }
            int height(tree_node nd)
            {
                if (nd == NULL)
                    return (0);
                return (__node->height);
            }
            int max(int a, int b)
            {
                return (a > b ? a : b);
            }
            tree_node *new_node(value_type pair)
            {
                tree_node nd = new tree_node;
                nd.value = pair;
                nd._left_child = nullptr;
                nd._right_child = nullptr;
                nd.height = 1;/*probably a 0*/
                return (nd);
            }
            tree_node *right_rotation(tree_node *nd)
            {
                tree_node *z = nd->_right_child;
                tree_node *x = nd->_left_child;
                nd->_right_child = nd;
                nd->_left_child = z;
                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);
                x->height = max(height(x->_left_child), height(x->_right_child) + 1);
                return (x);
            }
            tree_node *left_rotation(tree_node *nd)
            {
                tree_node *z = nd->_left_child;
                tree_node *x = nd->_right_child;
                nd->_left_child = nd;
                nd->_right_child = z;
                nd->height = max(height(nd->_left_child), height(nd->_right_child) + 1);
                x->height = max(height(x->_left_child), height(x->_right_child) + 1);
                return (x);
            }
            int get_balance(tree_node *nd)
            {
                if (nd == NULL)
                {
                    return (0);
                }
                return (height(nd->_left_child) - height(nd->_right_child));
            }
            tree_node *insert(tree_node *nd, valu_type pair)
            {
                if (nd == NULL)
                {
                    retrun (new_node(pair));
                }
                if (pair.first < nd._value.first)
                {
                    nd->_left_child = insert(node->_left_child, pair);
                }
                if (pair.first > nd._value.first)
                {
                    nd->_right_child = insert(node->_right_child, pair);
                }
                else
                    return (nd);
                nd->height = 1 + max(height(nd->_left_child), height(nd->_right_child));
                int balance = get_balance(nd);
                if (balance > 1 && )

            }

        private:
            node<value_type> tree_node;
            ~my_tree();
    };
}

#endif