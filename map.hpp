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
    template <class value_type, class key_type, class allocator_type, class comp>
    class my_tree
    {
        public:
            typedef node<value_type> _node;
            typedef typename allocator_type::template rebind<_node>::other node_allocator;
            typedef comp comparison_type;
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
            void    actual_copy_function(_node *nd, _node *x)
            {
                if (x)  //PREORDER TRAVERSAL//
                {
                    nd = new_node(x->_value);                       /*INSERT CURRENT NODE*/
                    actual_copy_function(nd->_left_child, x->_left_child); /*start with root and then traverses to the left node first then right*/
                    actual_copy_function(nd->_right_child, x->_right_child);
                }
                tree_node = nd;
            }
            void copy_tree(my_tree x)
            {
                actual_copy_function(tree_node, x.tree_node);
                // tree_node = nd;
                // return (x);
            }
            my_tree operator= (const my_tree& x)
            {
                // if (x.tree_node)
                // {
                //     tree_node = allocator.allocate(1);
                //     allocator.construct(tree_node, x.tree_node->_value);
                //     this->tree_node->balance_factor = x.tree_node->balance_factor;
                //     this->tree_node->_left_child = x.tree_node->_left_child;
                //     this->tree_node->_parent = x.tree_node->_parent;
                //     this->tree_node->_right_child = x.tree_node->_right_child;
                // }
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
            my_tree    swap(my_tree tree)
            {
                _node *nd = this->tree_node;
                _node *cp_root = this->root;
                this->tree_node = tree.tree_node;
                this->root = tree.root;
                tree.tree_node = nd;
                tree.root = cp_root;
                return (tree);
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
                    else if (pair.first > tmp->_value.first)        /////iterates in the tree till it finds pointer to where the node shoud be inserted////
                        tmp = tmp->_right_child;
                    else
                    {
                        return(nd);                 /////if there was already a node with the same key it should return the unchanged head//////
                    }
                }
                if (pair.first < parent->_value.first)
                    parent->_left_child = tmp = new_node(pair);         ////inserts the new node depending on it's valuecompared to the parent/////
                else if (pair.first > parent->_value.first)
                    parent->_right_child = tmp = new_node(pair);
                tmp->_parent = parent;              ///link new node to it's new parent///
                while (tmp && tmp != root)
                {
                    tmp->height = 1 + max(height(tmp->_left_child), height(tmp->_right_child));     //// update height of nodes throught the loop coz we need it to calcul balance///
                    int balance = get_balance(tmp);
                    tmp->balance_factor = balance;      ///update balance///
                    if (balance > 1 && pair.first < tmp->_left_child->_value.first)    //// nd  ////
                    {                                                                  ////  \   //// 
                        tmp = right_rotation(tmp, root);// left case////                ////  nd ////
                    }                                                                   ////   \ ////
                    else if (balance < -1 && pair.first > tmp->_right_child->_value.first)////  nd ////   ////   nd  ////
                    {                                                                                    ////   /   ////
                        tmp = left_rotation(tmp, root);// right case////                                ////   nd  ////
                    }                                                                                  ////   /   ////
                    else if (balance > 1 && pair.first > tmp->_left_child->_value.first)              ////  nd   ////
                    {                                                                                                 //  nd ///
                        // std::cout << "here\n";                                                                  //      /   ////
                        tmp->_left_child = left_rotation(tmp->_left_child, root);                                 ///   nd     ////
                        tmp = right_rotation(tmp, root);//left right case////                                     //      \   ///
                   }                                                                                               //       nd  //
                    else if (balance < -1 && pair.first < tmp->_right_child->_value.first)              //   nd   ///
                    {                                                                                  //      \  ///
                        tmp->_right_child = right_rotation(tmp->_right_child, root);                   ///      nd  //
                        // std::cout << "here2\n";                                                   ///        /  //
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
                    if (k < nd->_value.first && nd->_left_child)
                    {
                        nd = nd->_left_child;
                    }
                    else if (k > nd->_value.first && nd->_right_child)    /////iterates in the tree till it finds the node it needs to erase////
                    {
                        nd = nd->_right_child;                                                  
                    }
                    else
                    {
                        prev = prev_node(tmp, nd->_value.first, &side);
                        if (!nd->_right_child && !nd->_left_child)          //if it has no children we can point it's parent to null ///
                        {
                            if (side == 1)
                                nd->_parent->_right_child = nullptr;
                            else
                                nd->_parent->_left_child = nullptr;
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
                            if (nd == tmp)
                            {
                                tree_node = nd->_right_child;
                                return ;
                            }
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
                            {
                                tree_node = nd->_right_child;
                                return ;
                            }
                        }
                        else
                        {
                            _node *tr_min = tree_min();
                            _node *old_nd = nd;
                            _node *old_right = nd->_right_child;
                            _node *old_left = nd->_left_child;
                            _node *old_parent = nd->_parent;
                            _node *tr_min_old_parent = tr_min->_parent;

                            ///PARKOUR///
                            nd = tr_min;
                            nd->_parent = old_parent;
                            nd->_right_child = old_right;
                            nd->_left_child = old_left;
                            // old_right->_parent = nd;
                            // old_left->_parent = nd;
                            //////place tr_min in place of nd that we want to erase///////
                            if (old_nd->_parent)
                            {
                                prev_node(tmp, nd->_value.first, &side);////if nd is not root place tr_min on it's right or left depending on wich side nd was////
                                if (side == 1)
                                {
                                    nd->_parent->_right_child = tr_min;                                      /*VERY DEBATABLE SINCE I CHANGED THE PARENT OF ROOT TO END*/
                                    old_left->_parent = nd;
                                }
                                else if (side == 2)
                                {
                                    nd->_parent->_left_child = tr_min;
                                    old_right->_parent = nd;
                                }
                            }
                            side = 0;
                            ///REMOVE TR_MIN FROM ORIGINAL PLACE////
                            if (tr_min_old_parent == old_nd)    /////in case tr_min was  attached to the node we deleted
                                tr_min_old_parent = nd;
                            side = wich_parent_side(tr_min, tr_min_old_parent);
                            if (side == 1)
                            {
                                tr_min_old_parent->_right_child = NULL;
                            }
                            else if (side == 2)
                            {
                                tr_min_old_parent->_left_child = NULL;
                            }
                            if (old_nd == tmp)
                            {
                                tree_node = nd;
                                return ;
                            }
                            // nd->_parent = prev;
                        }
                        break ;
                    }
                }
                // while (nd && nd != root)
                // {
                //     nd->height = 1 + max(height(nd->_left_child), height(nd->_right_child));
                //     int balance = get_balance(nd);
                //     nd->balance_factor = balance;
                //     if (balance > 1 && k < nd->_left_child->_value.first)
                //     {
                //         nd = right_rotation(nd, root);// left case////
                //     }
                //     else if (balance < -1 && k > nd->_right_child->_value.first)
                //     {
                //         nd = left_rotation(nd, root);// right case////
                //     }
                //     else if (balance > 1 && k > nd->_left_child->_value.first)
                //     {
                //         // std::cout << "here\n";
                //         nd->_left_child = left_rotation(nd->_left_child, root);
                //         nd = right_rotation(nd, root);//left right case////
                //     }
                //     else if (balance < -1 && k < nd->_right_child->_value.first)
                //     {
                //         nd->_right_child = right_rotation(nd->_right_child, root);
                //         // std::cout << "here2\n";
                //         nd = left_rotation(nd, root);//right left case////
                //     }
                //     nd = nd->_parent;
                // }
                // if (root != tmp->_parent)
                //     tree_node = root->_left_child;
                tree_node = tmp;
            }
            ///////////////////////////////////////////////////
            //functions i added to make tree_node private//////
            ///////////////////////////////////////////////////
            _node   *find(key_type k)
            {
                _node *tmp = tree_node;
                while (tmp)
                {
                    if (tmp->_value.first < k)
                        tmp = tmp->_right_child;
                    else if (tmp->_value.first > k)
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
                    // std::cout << "here\n";
                    // _node *tmp_left = nd->_left_child;
                    // _node *tmp_right = nd->_right_child;

                    recursive_delete(nd->_left_child);/*TRAVESES to the left node first then right*/
                    recursive_delete(nd->_right_child);
                    destroy_node(nd);                  /*destroy CURRENT NODE*/
                }

            }
            void    clear_call()
            {

                recursive_delete(tree_node);
                // std::cout << root->_value.first <<std::endl;
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
                // int init_parent = 0;
                // if (!tree_node)
                //     init_parent = 1;
                tree_node = insert(tree_node, val, root);
                // if (init_parent)
                // {
                //     tree_node->_parent = new_node();
                //     tree_node->_parent->_left_child = tree_node;
                //     root = tree_node->_parent;
                // }
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
                if (tree_node && !tree_node->_parent)
                {
                    // std::cout << "here\n";
                    tree_node->_parent = root;

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
                    // else
                    //     std::cout << "Error in wich_parent func" << std::endl;
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
        while (nd && nd->_left_child)
        {
            nd = nd->_right_child;
        }
        return (nd);
    }
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
                if (!nd->_parent)
                    return (nd);
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
        public:
            template <class val_type, class node_ptr>
            friend bool operator== (const my_map_iterator<val_type, node_ptr>& lhs, const my_map_iterator<val_type, node_ptr>& rhs);
            template <class val_type, class node_ptr>
            friend bool operator!= (const my_map_iterator<val_type, node_ptr>& lhs, const my_map_iterator<val_type, node_ptr>& rhs);
            typedef value_type*        pointer;
            typedef value_type&        reference;
            typedef node_pointer       nodePtr;
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
            private:
                nodePtr _ptr;
    };
    template <class val_type, class node_ptr>
    bool operator== (const my_map_iterator<val_type, node_ptr>& lhs, const my_map_iterator<val_type, node_ptr>& rhs)
    {
        return (lhs._ptr == rhs._ptr);
    }
    template <class val_type, class node_ptr>
    bool operator!= (const my_map_iterator<val_type, node_ptr>& lhs, const my_map_iterator<val_type, node_ptr>& rhs)
    {
        return (lhs._ptr != rhs._ptr);
    }
    template <class T>
    class my_map_reverse_iterator
    { 
        public:
            typedef typename T::pointer        pointer;
            typedef typename T::reference       reference;
            // typedef node_pointer       nodePtr;
            typedef T                  iterator_type;
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
                return (*_iterator);
            }
            pointer operator->() const
            {
                return (&(*_iterator));
            }
            my_map_reverse_iterator &operator++()
            {
                // _iterator._ptr = find_predeccessor(_iterator._ptr);
                _iterator--;
                return (*this);
            }
            my_map_reverse_iterator operator++(int)       /*COULD BE WRONG*//*RETURNS DECREMENTED VALUE IN THE SAME LINE*/
            {
                my_map_reverse_iterator tmp = *this;
                // this->_iterator._ptr = find_predeccessor(_iterator._ptr);
                _iterator--;
                return (tmp);
            }
            my_map_reverse_iterator &operator--()
            {
                // this->_iterator._ptr = find_successor(_iterator._ptr);
                _iterator++;
                return (*this);
            }
            my_map_reverse_iterator operator--(int)       /*COULD BE WRONG*/
            {
                my_map_reverse_iterator tmp = *this;
                _iterator++;
                // this->_iterator._ptr= find_successor(_iterator._ptr);
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
                my_cmp_type(Compare c) : cmp(c){};/*DUNNO ABOUT THIS*/
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

            typedef my_cmp_type<value_type, key_type>                                         value_compare;

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
            typedef ptrdiff_t                                                   differende_type;
            typedef size_t                                                      size_type;
            typedef my_tree<value_type, key_type, allocator_type, value_compare>               tree;

            explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : u(alloc) , comp_obj(comp)
            {
                _size = 0;
                /*root = */_tree.insert_end();
            }
            template <class InputIterator>
            map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : u(alloc) , comp_obj(comp)
            {
                _size = 0;

                /*root = */_tree.insert_end();
                for (;first != last; first++)
                {
                    insert(ft::make_pair (first->first, first->second));
                    _size++;
                }
                _tree.link_to_root();
            }
            map (const map& x)
            {
                *this = x;
            }
            map& operator= (const map& x)
            {
                this->_size = x._size;
                // this->root = x.root;
                _tree.copy_tree(x._tree);       
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
                for (; tmp != last;/* first++*/)
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
                map tmp = *this;

                x._tree = this->_tree.swap(x._tree);
                this->_size = x._size;
                // this->root = x.root;
                // x._tree = tmp._tree;
                // x._tree.swap(tmp._tree);
                x._size = tmp._size;
                // x.root = tmp.root;
            }
            void clear()
            {
                _tree.clear_call();
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
                if (k > _tree.tree_max()->_value.first)
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
                if (k > _tree.tree_max()->_value.first)
                {
                    return(ft::make_pair<iterator, iterator> (this->end(), this->end()));
                }
                else
                    return (ft::make_pair<iterator, iterator> (lower_bound(k), upper_bound(k)));
            }
            ~map()
            {
                // _tree.prettyPrint();
            }
            private:
                tree        _tree;
                // _node *root;
                allocator_type u;
                value_compare comp_obj;
                size_type _size;
    };
}

#endif