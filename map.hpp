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
    template <class node_>
    node_ *tree_min_out(node_ *nd)
    {
        while (nd && nd->_left_child)
        {
            nd = nd->_left_child;
        }
        return (nd);
    }
    template <class value_type, class key_type, class allocator_type, class comp>
    class my_tree
    {
        public:
            typedef node<value_type> _node;
            typedef typename allocator_type::template rebind<_node>::other node_allocator;
            typedef comp comparison_type;
            my_tree(void)
            {
                tree_node = nullptr;
            }
            void    actual_copy_function(_node **nd, _node *x, _node **prev_node)
            {
                if (x)  //PREORDER TRAVERSAL//
                {
                    (*nd) = new_node(x->_value);                       /*INSERT CURRENT NODE*/
                    (*nd)->height = x->height;
                    (*nd)->balance_factor = x->balance_factor;
                    (*nd)->_parent = *prev_node;
                    actual_copy_function(&((*nd)->_left_child), x->_left_child, &(*nd)); /*start with root and then traverses to the left node first then right*/
                    actual_copy_function(&((*nd)->_right_child), x->_right_child, &(*nd));
                }
            }
            void copy_tree(my_tree x)
            {
                actual_copy_function(&tree_node, x.tree_node, &root);
                if (tree_node && root)
                    root->_left_child = tree_node;
            }
            my_tree operator= (const my_tree& x)
            {
                // clear_call(1);
                insert_end();
                this->copy_tree(x);
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
            void    swap(my_tree *tree)
            {
                _node *nd = this->tree_node;
                _node *cp_root = this->root;
                this->tree_node = tree->tree_node;
                this->root = tree->root;
                tree->tree_node = nd;
                tree->root = cp_root;
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

                if (nd->_right_child)
                    nd->_right_child = old_right->_left_child;
                if (old_right->_left_child)                     //////connect right child's left child to nd////
                    old_right->_left_child->_parent = nd;

                old_right->_parent = nd->_parent;       /////////connect nd's right child to nd's parent//////

                if (nd->_parent == root)                /////in case nd was connected to end update root/////
                    root->_left_child = old_right;
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
                    else if (cmp(k, nd->_value.first))
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
                    if (cmp(pair.first, tmp->_value.first))
                        tmp = tmp->_left_child;
                    else if (!cmp(pair.first, tmp->_value.first) && pair.first != tmp->_value.first)        /////iterates in the tree till it finds pointer to where the node shoud be inserted////
                        tmp = tmp->_right_child;
                    else
                    {
                        return(nd);                 /////if there was already a node with the same key it should return the unchanged head//////
                    }
                }
                if (cmp(pair.first, parent->_value.first))
                    parent->_left_child = tmp = new_node(pair);         ////inserts the new node depending on it's valuecompared to the parent/////
                else if (!cmp(pair.first, parent->_value.first) && pair.first != parent->_value.first)
                    parent->_right_child = tmp = new_node(pair);
                tmp->_parent = parent;              ///link new node to it's new parent///
                while (tmp && tmp != root)
                {
                    tmp->height = 1 + max(height(tmp->_left_child), height(tmp->_right_child));     //// update height of nodes throught the loop coz we need it to calcul balance///
                    int balance = get_balance(tmp);
                    tmp->balance_factor = balance;      ///update balance///
                    if (balance > 1 && cmp(pair.first, tmp->_left_child->_value.first))                                                       //// nd  ////
                    {                                                                                                                         ////  \   //// 
                        tmp = right_rotation(tmp, root);// left case////                                                                       ////  nd ////
                    }                                                                                                                          ////   \ ////
                    else if (balance < -1 && !cmp(pair.first, tmp->_right_child->_value.first) && pair.first != tmp->_right_child->_value.first)////  nd ////    ////   nd  ////
                    {                                                                                                                                           ////   /   ////
                        tmp = left_rotation(tmp, root);// right case////                                                                                       ////   nd  ////
                    }                                                                                                                                         ////   /   ////
                    else if (balance > 1 && !cmp(pair.first, tmp->_left_child->_value.first) && pair.first != tmp->_left_child->_value.first)                ////  nd   ////
                    {                                                                                                 //  nd ///
                                                                                                                  //      /   ////
                        tmp->_left_child = left_rotation(tmp->_left_child, root);                                 ///   nd     ////
                        tmp = right_rotation(tmp, root);//left right case////                                     //      \   ///
                   }                                                                                               //       nd  //
                    else if (balance < -1 && cmp(pair.first, tmp->_right_child->_value.first))           //   nd   ///
                    {                                                                                   //      \  ///
                        tmp->_right_child = right_rotation(tmp->_right_child, root);                    ///      nd  //
                                                                                                      ///        /  //
                        tmp = left_rotation(tmp, root);//right left case////                          //       nd  //
                    }
                    tmp = tmp->_parent;
                }
                if (root != nd->_parent)                ///in case root was changed return new root(not end) ///
                    return (root->_left_child);
                return (nd);
            }
            void erase(key_type k)
            {
                _node *tmp = tree_node;
                _node *nd = tree_node;
                _node *prev = NULL;
                int side;

                if (nd == NULL)
                {
                    return ;
                }
                while(nd)
                {
                    if (cmp(k, nd->_value.first))
                    {
                        nd = nd->_left_child;
                    }
                    else if (!cmp(k, nd->_value.first) && k != nd->_value.first)    /////iterates in the tree till it finds the node it needs to erase////
                    {
                        nd = nd->_right_child;                                                  
                    }
                    else
                    {
                        if (!nd)
                            return ;
                        prev = prev_node(tmp, nd->_value.first, &side);
                        if (!nd->_right_child && !nd->_left_child)          //if it has no children we can point it's parent to null ///
                        {
                            if (side == 1)
                            {
                                allocator.deallocate(nd->_parent->_right_child , 1);
                                nd->_parent->_right_child = nullptr;
                            }
                            else
                            {
                                allocator.deallocate(nd->_parent->_left_child , 1);
                                nd->_parent->_left_child = nullptr;
                            }
                            if (nd == tmp)                                  ////in case nd was root ///
                                return ;
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
                            nd->_right_child->_parent = nd->_parent;
                            _node *old_nd = nd;
                            if (nd == tmp)
                            {
                                tree_node = nd->_right_child;
                                // return ;
                            }
                            allocator.deallocate(old_nd, 1);
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
                            _node *old_nd = nd;
                            if (nd == tmp)
                            {
                                nd = nd->_right_child;
                                tree_node = nd;
                                // return ;
                            }
                            allocator.deallocate(old_nd, 1);
                        }
                        else
                        {
                            _node *tr_min = tree_min_out(nd->_right_child);
                            _node *tr_min_old_parent = tr_min->_parent;
                            _node *old_nd = nd;
                            _node *old_right = nd->_right_child;
                            _node *old_left = nd->_left_child;      //saving old adressed attached to node we wanna delete///
                            _node *old_parent = nd->_parent;

                            side = wich_parent_side(old_nd, old_parent);
                            if (tr_min == nd->_right_child)             //in case tr_min was attached to nd /////
                            {
                                nd = tr_min;
                                if (side == 1)
                                    old_parent->_right_child = nd;
                                else if (side == 2)
                                    old_parent->_left_child = nd;
                                nd->_parent = old_parent;
                                nd->_left_child = old_left;
                                old_left->_parent = nd;
                                nd->_right_child = old_right->_right_child;
                                if (old_right->_right_child)
                                {
                                    old_right->_right_child->_parent = nd;
                                }
                            }
                            else
                            {
                                nd = tr_min;
                                if (side == 1)
                                    old_parent->_right_child = nd;
                                else if (side == 2)
                                    old_parent->_left_child = nd;
                                nd->_parent = old_parent;
                                nd->_right_child = old_right;
                                nd->_left_child = old_left;
                                old_left->_parent = nd;
                                old_right->_parent = nd;
                                tr_min_old_parent->_left_child = NULL;
                            }
                            allocator.deallocate(old_nd, 1);
                            if (tmp == old_nd)
                                tree_node = nd;
                        }
                        break ;
                    }
                }
                while (nd && nd != root)
                {
                    nd->height = 1 + max(height(nd->_left_child), height(nd->_right_child));
                    int balance = get_balance(nd);
                    nd->balance_factor = balance;
                    if (balance > 1 && !cmp(k, nd->_left_child->_value.first) && k != nd->_left_child->_value.first)
                    {
                        nd = right_rotation(nd, root);// left case////
                    }
                    else if (balance < -1 && cmp(k, nd->_right_child->_value.first))
                    {
                        nd = left_rotation(nd, root);// right case////
                    }
                    else if (balance > 1 && cmp(k, nd->_left_child->_value.first))
                    {
                        nd->_left_child = left_rotation(nd->_left_child, root);
                        nd = right_rotation(nd, root);//left right case////
                    }
                    else if (balance < -1 && !cmp(k, nd->_right_child->_value.first) && nd->_right_child->_value.first != k)
                    {
                        nd->_right_child = right_rotation(nd->_right_child, root);
                        nd = left_rotation(nd, root);//right left case////
                    }
                    nd = nd->_parent;
                }
                if (root->_left_child != nd)
                {
                    tree_node = root->_left_child;
                    return ;
                }
                // tree_node = tmp;
            }
            ///////////////////////////////////////////////////
            //functions i added to make tree_node private//////
            ///////////////////////////////////////////////////
            _node   *find(key_type k)
            {
                _node *tmp = tree_node;
                while (tmp)
                {
                    if (cmp(tmp->_value.first, k))
                        tmp = tmp->_right_child;
                    else if (!cmp(tmp->_value.first, k) && k != tmp->_value.first)
                        tmp = tmp->_left_child;
                    else
                        return (tmp);
                }
                return (nullptr); ; 
            }
            void    destroy_node(_node *nd)
            {
                // erase(nd->_value.first);
                // allocator.destroy(nd);
                allocator.deallocate(nd, 1);
            }
            void    recursive_delete(_node *nd)
            {
                if (nd)
                {
                    recursive_delete(nd->_left_child);/*TRAVESES to the left node first then right*/
                    recursive_delete(nd->_right_child);
                    destroy_node(nd);                  /*destroy CURRENT NODE*/
                    nd = nullptr;
                }
                nd = nullptr;
                root->_left_child = nullptr;
            }
            void    clear_call(int last)
            {
                if (root)
                    recursive_delete(root->_left_child);
                if (last)
                {
                    allocator.deallocate(root, 1);
                }
                tree_node = nullptr;
            }
            _node *tree_max()
            {
                _node *tmp = tree_node;
                // if (tmp)
                // {
                    while (tmp && tmp->_right_child)
                    {
                        tmp = tmp->_right_child;
                    }
                // }
                return (tmp);
            }
            _node *tree_min()
            {
                _node *tmp = tree_node;
                while (tmp && tmp->_left_child)
                {
                    tmp = tmp->_left_child;
                }
                return (tmp);
            }
            void    insert_with_value(value_type val)
            {
                tree_node = insert(tree_node, val, root);
            }
            _node *insert_end()
            {
                tree_node = new_node();
                root = tree_node;
                tree_node = tree_node->_left_child;

                return (root);
            }
            void    link_to_root()
            {
                if (tree_node && (!tree_node->_parent || !root->_left_child))
                {
                    tree_node->_parent = root;
                    root->_left_child = tree_node;
                }
            }
            _node *find_successor(_node * nd)
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
            _node *find_predeccessor(_node * nd)
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
                }
                return (NULL);
            }
            ~my_tree(){};
        private:
            comparison_type cmp;
            _node *tree_node;
            _node *root;
            node_allocator allocator;
    };
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
                return (tree_min_out(nd->_right_child));
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
            else
            {
                while((side = wich_parent_side(nd, nd->_parent)) == 2)
                {
                    nd = nd->_parent;
                }
                if (!nd->_parent)
                    return (nd);
                return (nd->_parent);
            }
        }
        return (NULL);
    }
    template <class value_type, class node_pointer>
    class my_map_iterator
    {
        public:
            typedef value_type*        pointer;
            typedef value_type&        reference;
            typedef node_pointer       nodePtr;
            my_map_iterator():_ptr(){}
            my_map_iterator(nodePtr ptr):_ptr(ptr){}
            template <class iterator>
            my_map_iterator(const iterator &it)
            {
                this->_ptr = it.base();
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
            nodePtr base() const
            {
                return (_ptr);
            }
            my_map_iterator &operator++()
            {
                this->_ptr = find_successor(_ptr);
                return (*this);
            }
            my_map_iterator operator++(int)
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
            my_map_iterator operator--(int)
            {
                my_map_iterator tmp = *this;
                this->_ptr = find_predeccessor(_ptr);
                return (tmp);
            }
            bool	operator==(my_map_iterator const &rhs){
			    return	( this->_ptr == rhs._ptr);
		    };
            bool	operator!=(my_map_iterator const &rhs){
			    return	( this->_ptr != rhs._ptr);
		    };
            ~my_map_iterator(){};
            private:
                nodePtr _ptr;
    };
    template <class T>
    class my_map_reverse_iterator
    { 
        public:
            typedef typename T::pointer        pointer;
            typedef typename T::reference       reference;
            typedef T                  iterator_type;
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
                return (*_iterator);
            }
            pointer operator->() const
            {
                return (&(*_iterator));
            }
            my_map_reverse_iterator &operator++()
            {
                --_iterator;
                return (*this);
            }
            my_map_reverse_iterator operator++(int)
            {
                my_map_reverse_iterator tmp = *this;
                --_iterator;
                return (tmp);
            }
            my_map_reverse_iterator &operator--()
            {
                _iterator++;
                return (*this);
            }
            my_map_reverse_iterator operator--(int) 
            {
                my_map_reverse_iterator tmp = *this;
                _iterator++;
                return (tmp);
            }
            ~my_map_reverse_iterator(){};
        private:
            iterator_type _iterator;
    };
    template <class iterator>
    bool operator== (const my_map_reverse_iterator<iterator>& lhs, const my_map_reverse_iterator<iterator>& rhs)
    {
        if (*lhs == *rhs)
            return (1);
        return (0);
    }
    template <class iterator>
    bool operator!= (const my_map_reverse_iterator<iterator>& lhs, const my_map_reverse_iterator<iterator>& rhs)
    {
        if (*lhs != *rhs)
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
            template <class value_type, class key_type>
            class my_cmp_type
            {
                public:
                key_compare cmp;
                my_cmp_type(Compare c) : cmp(c){};
                my_cmp_type(){};
                bool operator() (const value_type& x, const value_type& y) 
                {
                    return cmp(x.first , y.first);
                }
                bool operator() (const key_type& x, const value_type& y) 
                {
                    return cmp(x , y.first);
                }
                bool operator() (const value_type& x, const key_type& y) 
                {
                    return cmp(x.first , y);
                }
                bool operator() (const key_type& x, const key_type& y) 
                {
                    return cmp(x , y);
                }
            };
            typedef T                                                           mapped_type;
            typedef pair<const key_type,mapped_type>                            value_type;

            typedef my_cmp_type<value_type, key_type>                           value_compare;

            typedef node<value_type>                                            _node;
            typedef Allocator                                                   allocator_type;
            typedef typename allocator_type::reference                          reference;
            typedef typename allocator_type::const_reference                    const_reference;
            typedef typename allocator_type::pointer                            pointer;
            typedef typename allocator_type::const_pointer                      const_pointer;
            typedef my_map_iterator<value_type, _node *>                        iterator;
            typedef my_map_iterator<const value_type, _node *>                  const_iterator;
            typedef my_map_reverse_iterator<iterator>                           reverse_iterator;
            typedef my_map_reverse_iterator<const iterator>                     const_reverse_iterator;
            typedef ptrdiff_t                                                   difference_type;
            typedef size_t                                                      size_type;
            typedef my_tree<value_type, key_type, allocator_type, key_compare>     tree;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : u(alloc) , comp_obj(comp)
            {
                _size = 0;
                /*root = */_tree.insert_end();
                been_to_constructor = 1;
            }
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : u(alloc) , comp_obj(comp)
            {
                _size = 0;
                been_to_constructor = 1;
                /*root = */_tree.insert_end();
                for (;first != last; first++)
                {
                    insert(ft::make_pair (first->first, first->second));
                }
                _tree.link_to_root();
            }
            map (const map& x)
            {
                *this = x;
            }
            map& operator= (const map& x)
            {
                if (been_to_constructor == 1)
                   this->~map();
                this->_tree = x._tree;      
                this->_size = x._size;
                this->u = x.u;
                this->comp_obj = x.comp_obj;
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
                size_t num = sizeof(key_type) >= sizeof(mapped_type) ? sizeof(key_type) : sizeof(mapped_type);
                if (num == 1)
                    return (std::numeric_limits<difference_type>::max() / 16);

                return ((std::numeric_limits<difference_type>::max() / (num + 16)));
            }
            mapped_type& operator[] (const key_type& k)
            {
                _node *tmp = _tree.find(k);
                if (tmp)
                {
                    return (tmp->_value.second);
                }
                else
                {
                    return (insert(ft::make_pair (k, mapped_type())).first)->second;
                }
            }
			pair<iterator, bool> insert (const value_type& val)
			{
                if (count(val.first))
                {
                    return ft::make_pair (find(val.first), 0);///////return pair who's first type is an iterator pointing to where it found it and 0 in case it was there /////
                }
                _tree.insert_with_value(val);
                _tree.link_to_root();
                _size += 1;
                return (ft::make_pair (find(val.first), 1));
			}
            iterator insert (iterator position, const value_type& val)
            {
                position = insert(val).first;
                _tree.link_to_root();
                return (position);
            }
            template <class InputIterator>
            void insert (InputIterator first, InputIterator last)
            {
                for (; first != last; first++)
                {
                    insert(ft::make_pair (first->first, first->second));
                }
                _tree.link_to_root();
            }
            void erase (iterator position)
            {
                erase(position->first);
            }
            size_type erase (const key_type& k)
            {
                _tree.erase(k);
                _size--;   
                return (1);           
            }
            void erase (iterator first, iterator last)
            {
                iterator tmp = first;
                for (; tmp != last;)
                {
                    first = tmp;
                    tmp++;
                    erase(first);
                }  
            }
            iterator begin()
            {
                return (iterator(_tree.tree_min()));
            }
            const_iterator begin() const
            {
                return (const_iterator(_tree.tree_min()));
            }
            iterator end()
            {
                return (++iterator(_tree.tree_max()));
            }
            const_iterator end() const
            {
                return (++const_iterator(_tree.tree_max()));
            }
            reverse_iterator rbegin()
            {
                return (reverse_iterator(_tree.tree_max()));
            }
            const_reverse_iterator rbegin() const
            {
                return (const_reverse_iterator(_tree.tree_max()));
            }
            reverse_iterator rend()
            {
                return (++reverse_iterator(_tree.tree_min()));
            }
            const_reverse_iterator rend() const
            {
                return (++const_reverse_iterator(_tree.tree_min()));
            }
            iterator find (const key_type& k) 
            {
                _node *tmp;
                if ((tmp = _tree.find(k)))
                {
                    return(iterator(tmp));
                }
                return (this->end());
            }
            const_iterator find (const key_type& k) const
            {
                _node *tmp;
                
                if ((tmp = _tree.find(k)))
                {
                    return(tmp);
                }
                return (this->end());
            }
            size_type count (const key_type& k) const
            {
                if (_size == 0)
                    return(0);
                return ( const_cast<map *>(this)->find(k) == const_cast<map *>(this)->end() ? 0 : 1);///////////calling a non-const func inside a const func/////////
            }
            void swap (map& x)
            {
                int tmp_size = this->_size;
                allocator_type tmp_u = this->u;
                key_compare tmp_cmp_obj = this->comp_obj;

                _tree.swap(&x._tree);
                this->_size = x._size;
                this->u = x.u;
                this->comp_obj = x.comp_obj;
                x._size = tmp_size;
                x.u = tmp_u;
                x.comp_obj = tmp_cmp_obj;
            }
            void clear()
            {    
                _tree.clear_call(0);
                _size = 0;
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
                    while (it != this->end() && comp_obj(it->first, k))
                    {
                        it++;
                    }
                    return it;
                }
            }
            const_iterator lower_bound (const key_type& k) const
            {
                if (count(k))
                    return (find(k));
                else
                {
                    iterator it = this->begin();
                    while (it != this->end() && comp_obj(it->first, k))
                    {
                        it++;
                    }
                    return it;
                }
            }
            iterator upper_bound (const key_type& k)
            {
                if (count(k))
                    return (++find(k));
                else
                {
                    iterator it = this->begin();
                    while (it != this->end() && comp_obj(it->first, k))
                    {
                        it++;
                    }
                    if (it == this->end())
                        return (this->end());
                    else
                    {
                        return it;
                    }
                }
            }
            const_iterator upper_bound (const key_type& k) const
            {
                if (count(k))
                    return (++find(k));
                else
                {
                    iterator it = this->begin();
                    while (it != this->end() && comp_obj(it->first, k))
                    {
                        it++;
                    }
                    if (it == this->end())
                        return (this->end());
                    else
                    {
                        return it;
                    }
                }
            }
            pair<iterator,iterator> equal_range (const key_type& k)
            {
                if (count(k))
                    return (ft::make_pair<iterator, iterator> (find(k), ++find(k)));
                if (!comp_obj(k, _tree.tree_max()->_value.first))
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
                if (!comp_obj(k, _tree.tree_max()->_value.first))
                {
                    return(ft::make_pair<iterator, iterator> (this->end(), this->end()));
                }
                else
                    return (ft::make_pair<iterator, iterator> (lower_bound(k), upper_bound(k)));
            }
            allocator_type get_allocator() const
            {
                allocator_type obj;
                return (obj);
            }
            ~map()
            {
                _tree.clear_call(1);
            }
            private:
                int been_to_constructor;
                allocator_type  u;
                Compare   comp_obj;
                tree            _tree;
                size_type       _size;
    };
}

#endif