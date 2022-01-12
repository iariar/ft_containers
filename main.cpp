#include "vector.hpp"
#include "map.hpp"
#include <map>
#include "stack.hpp"
#include "lexicographical_compare.hpp"
#include <stack>


// template <typename T>
// struct is_integral
// {
//     static bool value = false;
// };

// template <>
// struct is_integral<int>
// {
//     static bool value = true;
// };


// template <bool, typename T = void>
// struct enable_if{};

// template <>
// struct enable_if<true, T>{
//     typedef T type;
// };

struct t
    {
        int a;
    };
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

// int main()
// {
    //////////////////
    ///constructors///
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef std::vector<int>::iterator iter_type;
    //                                                             // ? 0 1 2 3 4 5 6 7 8 9 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     std::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until)
    //         std::cout << ' ' << *rev_from++;
    //     std::cout << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef ft::vector<int>::iterator iter_type;
    //                                                             // ? 0 1 2 3 4 5 6 7 8 9 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     std::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until)
    //         std::cout << ' ' << *rev_from++;
    //     std::cout << '\n';
    // }
    //////////////////
    ///BASE()/////////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_end (myvector.begin());
    //     std::reverse_iterator<iter_type> rev_begin (myvector.end());

    //     std::cout << "myvector:";
    //     for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
    //         std::cout << ' ' << *it;
    //     std::cout << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef ft::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_end (myvector.begin());
    //     std::reverse_iterator<iter_type> rev_begin (myvector.end());

    //     std::cout << "myvector:";
    //     for (iter_type it = rev_end.base(); it != rev_begin.base(); ++it)
    //         std::cout << ' ' << *it;
    //     std::cout << '\n';
    // }
    //////////////////
    ///OPERATOR*//////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef std::vector<int>::iterator iter_type;
    //                                                             // ? 9 8 7 6 5 4 3 2 1 0 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     std::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until)
    //         std::cout << ' ' << *rev_from++;
    //     std::cout << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef ft::vector<int>::iterator iter_type;
    //                                                             // ? 9 8 7 6 5 4 3 2 1 0 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     std::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until)
    //         std::cout << ' ' << *rev_from++;
    //     std::cout << '\n';
    // }
    //////////////////
    ///OPERATOR+//////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_it;

    //     rev_it = myvector.rbegin() +3;

    //     std::cout << "The fourth element from the end is: " << *rev_it << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef ft::vector<int>::iterator iter_type;

    //     ft::my_reverse_iterator<iter_type> rev_it;

    //     rev_it = myvector.rbegin() +3;

    //     std::cout << "The fourth element from the end is: " << *rev_it << '\n';
    // }
    //////////////////
    ///OPERATOR++/////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef std::vector<int>::iterator iter_type;
    //                                                             // ? 9 8 7 6 5 4 3 2 1 0 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     std::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until) {
    //         std::cout << ' ' << *rev_from;
    //         ++rev_from;
    //     }
    //     std::cout << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef ft::vector<int>::iterator iter_type;
    //                                                             // ? 9 8 7 6 5 4 3 2 1 0 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     std::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until) {
    //         std::cout << ' ' << *rev_from;
    //         ++rev_from;
    //     }
    //     std::cout << '\n';
    // }
    //////////////////
    ///OPERATOR+=/////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

    //     rev_iterator += 2;

    //     std::cout << "The third element from the end is: " << *rev_iterator << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef ft::vector<int>::iterator iter_type;

    //     ft::my_reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

    //     rev_iterator += 2;

    //     std::cout << "The third element from the end is: " << *rev_iterator << '\n';
    // }
    //////////////////
    ///OPERATOR-//////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_iterator;

    //     rev_iterator = myvector.rend() - 3;

    //     std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';/////////////NOT WORKING ////////////
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef ft::vector<int>::iterator iter_type;

    //     ft::my_reverse_iterator<iter_type> rev_iterator;

    //     rev_iterator = myvector.rend() - 3;

    //     std::cout << "myvector.rend()-3 points to: " << *rev_iterator << '\n';
    // }
    //////////////////
    ///OPERATOR--/////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_begin (myvector.end());
    //     std::reverse_iterator<iter_type> rev_end (myvector.begin());

    //     std::reverse_iterator<iter_type> rev_iterator = rev_begin;
    //     while ( rev_iterator != rev_end )
    //         std::cout << *rev_iterator++ << ' ';
    //     std::cout << '\n';

    //     while ( rev_iterator != rev_begin )
    //         std::cout << *(--rev_iterator) << ' ';
    //     std::cout << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);                      /////////////NOT WORKING ////////////

    //     typedef ft::vector<int>::iterator iter_type;

    //     ft::my_reverse_iterator<iter_type> rev_begin (myvector.end());
    //     ft::my_reverse_iterator<iter_type> rev_end (myvector.begin());

    //     ft::my_reverse_iterator<iter_type> rev_iterator = rev_begin;
    //     while ( rev_iterator != rev_end )
    //     {
    //         std::cout << *rev_iterator << ' ';
    //         ++rev_iterator;
    //     }
    //     std::cout << '\n';

    //     while ( rev_iterator != rev_begin )
    //         std::cout << *(--rev_iterator) << ' ';
    //     std::cout << '\n';
    // }
    //////////////////
    ///OPERATOR-=/////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_iterator = myvector.rend();

    //     rev_iterator -= 4;

    //     std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef ft::vector<int>::iterator iter_type;

    //     ft::my_reverse_iterator<iter_type> rev_iterator = myvector.rend();

    //     rev_iterator -= 4;

    //     std::cout << "rev_iterator now points to: " << *rev_iterator << '\n';
    // }
    //////////////////
    ///OPERATOR->/////
    //////////////////
    //bad example//
    //////////////////
    ///OPERATOR[]/////
    //////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

    //     std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);  // myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef ft::vector<int>::iterator iter_type;

    //     ft::my_reverse_iterator<iter_type> rev_iterator = myvector.rbegin();

    //     std::cout << "The fourth elementt from the end is: " << rev_iterator[3] << '\n';
    // }
    //////////////////////////
    ///RATIONAL OPERATORS/////
    //////////////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     typedef std::vector<int>::iterator iter_type;
    //                                                             // ? 9 8 7 6 5 4 3 2 1 0 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     std::reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     std::reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until)
    //         std::cout << ' ' << *rev_from++;
    //     std::cout << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i); 

    //     typedef ft::vector<int>::iterator iter_type;
    //                                                             // ? 9 8 7 6 5 4 3 2 1 0 ?
    //     iter_type from (myvector.begin());                     //   ^
    //                                                             //         ------>
    //     iter_type until (myvector.end());                      //                       ^
    //                                                             //
    //     ft::my_reverse_iterator<iter_type> rev_until (from);     // ^
    //                                                             //         <------
    //     ft::my_reverse_iterator<iter_type> rev_from (until);     //                     ^

    //     std::cout << "myvector:";
    //     while (rev_from != rev_until)
    //         std::cout << ' ' << *rev_from++;
    //     std::cout << '\n';
    // }
    //////////////////////////
    ///NON-MEMBER OPERATOR+///
    //////////////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef std::vector<int>::iterator iter_type;

    //     std::reverse_iterator<iter_type> rev_it;

    //     rev_it = 3 + myvector.rbegin();

    //     std::cout << "The fourth element from the end is: " << *rev_it << '\n';
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9

    //     typedef ft::vector<int>::iterator iter_type;

    //     ft::my_reverse_iterator<iter_type> rev_it;

    //     rev_it = 3 + myvector.rbegin();

    //     std::cout << "The fourth element from the end is: " << *rev_it << '\n';
    // }
    //////////////////////////
    ///NON-MEMBER OPERATOR-///
    //////////////////////////
    // {
    //     std::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     std::reverse_iterator<std::vector<int>::iterator> from,until;

    //     from = myvector.rbegin();
    //     until = myvector.rend();

    //     std::cout << "myvector has " << (until-from) << " elements.\n";
    // }
    // {
    //     ft::vector<int> myvector;
    //     for (int i=0; i<10; i++) myvector.push_back(i);

    //     ft::my_reverse_iterator<ft::vector<int>::iterator> from,until;

    //     from = myvector.rbegin();
    //     until = myvector.rend();

    //     std::cout << "myvector has " << (until-from) << " elements.\n";
    // }
    // ft::vector<int> my_vec;
    // ft::vector<int> another_vec(3, 6);

    // my_vec.assign(10, 5);
    // my_vec.assign(another_vec.begin(), another_vec.end());
    // my_vec.insert(my_vec.begin(), another_vec.begin(), another_vec.end());
    // for (ft::vector<int>::iterator it = my_vec.begin(); it < my_vec.end(); it++)
    // {
    //     std::cout << *it << std::endl;
    // }
    // std::vector<int> vec(10, 2);
   
    // std::vector<int>::reverse_iterator  it1 = vec.rbegin();
    // std::cout << *it1 << std::endl;
    // *it1 = 10;
    // std::cout << *it1 << std::endl;
// }

// int main()
// {
    ///////////////
    ///TEST PAIR///
    ///////////////
    // {
    //     std::pair <std::string,double> product1;                     // default constructor
    //     std::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    //     std::pair <std::string,double> product3 (product2);          // copy constructor

    //     product1 = std::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

    //     product2.first = "shoes";                  // the type of first is string
    //     product2.second = 39.90;                   // the type of second is double

    //     std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    //     std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    //     std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    // }
    // std::cout << "END OF STD::PAIR" << std::endl;
    // {
    //     ft::pair <std::string,double> product1;                     // default constructor
    //     ft::pair <std::string,double> product2 ("tomatoes",2.30);   // value init
    //     ft::pair <std::string,double> product3 (product2);          // copy constructor

    //     product1 = ft::make_pair(std::string("lightbulbs"),0.99);   // using make_pair (move)

    //     product2.first = "shoes";                  // the type of first is string
    //     product2.second = 39.90;                   // the type of second is double

    //     std::cout << "The price of " << product1.first << " is $" << product1.second << '\n';
    //     std::cout << "The price of " << product2.first << " is $" << product2.second << '\n';
    //     std::cout << "The price of " << product3.first << " is $" << product3.second << '\n';
    // }
    ///////////////
    ///MAKE_PAIR///
    ///////////////
    // {
    //     std::pair <int,int> foo;
    //     std::pair <int,int> bar;

    //     foo = std::make_pair (10,20);
    //     bar = std::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

    //     std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    //     std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    // }
    // {
    //     ft::pair <int,int> foo;
    //     ft::pair <int,int> bar;
    //         foo = ft::make_pair (10,20);
    //     bar = ft::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

    //     std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    //     std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    // }
    ///////////////////////////
    //lexicographical compare//
    ///////////////////////////
    // {
    //     char foo[]="Apple";
    //     char bar[]="apartment";

    //     std::cout << std::boolalpha;

    //     std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

    //     std::cout << "Using default comparison (operator<): ";
    //     std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
    //     std::cout << '\n';

    //     std::cout << "Using mycomp as comparison object: ";
    //     std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
    //     std::cout << '\n';
    // }
    // {
    //     char foo[]="Apple";
    //     char bar[]="apartment";

    //     std::cout << std::boolalpha;

    //     std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

    //     std::cout << "Using default comparison (operator<): ";
    //     std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
    //     std::cout << '\n';

    //     std::cout << "Using mycomp as comparison object: ";
    //     std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
    //     std::cout << '\n';
    // }
// }

// int main()
// {
//     ///////////////
//     //test_map/////
//     ///////////////
// using namespace std;

// int main()
// {
  
//     std::map<int , int> test;

//     test.assign(7, 100);
//     std::map<int, int>::iterator test.begin();
//     return 0;
// }
// }

// int main()
// {
//     ft::my_tree< ft::pair<int, int> > test;
//     // ft::my_tree< ft::pair<int , int> > test2(test);
//     ft::pair<int , int> pp(1, 10);
//     ft::pair<int , int> pp2(0, 40);
//     ft::pair<int , int> pp3(-1, 50);
//     // std::cout << pp.first << "\n" << pp.second << std::endl;
//     // pp.first = 0;
//     // pp.second = 10;
//     // pp2.first = 50;
//     // pp2.second = 60;
//     // test.insert(test.new_node(pp) , pp);
//     ft::node<ft::pair<int, int> > *test_node = test.new_node(pp);
//     ft::node<ft::pair<int, int> > *test_node2 = test.insert(test_node, pp2);
//     test_node = test.insert(test_node, pp3);
//     printf("pp first = %d -- pp second = %d\n", test_node->_value.first ,test_node->_value.second);
//     // printf("out \n");
//     printf("pp2 first = %d -- pp2 second = %d\n", test_node->_right_child->_value.first ,test_node->_right_child->_value.second);
//     printf("pp3 first = %d -- pp3 second = %d\n", test_node->_left_child->_value.first ,test_node->_left_child->_value.second);
// }

// int main()
// {
//     ft::map<int, int> test;
//     ft::map<int, int> test2;
//     // printf("been there\n");
//     test.insert(ft::pair<int, int>(20, 20));
//     test.insert(ft::pair<int, int>(10, 10));
//     test.insert(ft::pair<int, int>(15, 30));
//     test.insert(ft::pair<int, int>(5, 40));
//     test.insert(ft::pair<int, int>(30, 50));
//     test.insert(ft::pair<int, int>(25, 60));
//     test.insert(ft::pair<int, int>(40, 70));
//     test.insert(ft::pair<int, int>(45, 80));
//     test.insert(ft::pair<int, int>(1, 90));
//     test.insert(ft::pair<int, int>(60, 660));
//     test.insert(ft::pair<int, int>(70, 770));
//     test.insert(ft::pair<int, int>(80, 880));
//     test.insert(ft::pair<int, int>(90, 990));
//     test2.insert(test.begin(), test.end());
//     test2.insert(ft::pair<int, int>(0, 0));

//     for (ft::map<int, int>::iterator it = test2.begin();it != test2.end() ; it++)
//     {
//         std::cout << it->first << std::endl;
//     }
    
//     // ft::map<int, int>::reverse_iterator it = test.begin();
//     // std::cout << test.count(30) << std::endl;
//     // test2.swap(test);
//     // std::cout << test.count(33) << std::endl;
//     // for (ft::map<int, int>::reverse_iterator it = test.rbegin(); it != test.rend(); it++)
//     // {
//     //    std::cout << it->first << std::endl;
//     // }
//     // std::cout << test._tree.tree_node->_left_child->_right_child->_right_child->_value.first << std::endl;
    
//     // test_iterator++;
//     // test_iterator--;
//     // printf("done that\n");
//     // test.insert(pp2);
//     // test.insert(pp3);
//     // test.insert(pp4);
//     // test.insert(pp5);          /////BALANCE FACTOR IS WRONG///////  
//     // test.insert(pp6);
//     // test.insert(pp7);
//     // ft::map<int, int> test2;
//     // test2 = test;
//     // std::cout << "pp first = " << test._tree.tree_node->_value.first << "\npp second = " << test._tree.tree_node->_value.second << std::endl;
//     // std::cout << "operator return val = " << test._tree.tree_node->balance_factor << std::endl;
//     // std::cout << "pp first = " << test._tree.tree_node->_left_child->_left_child->_value.first << "\npp second = " << test._tree.tree_node->_left_child->_left_child->_value.second << std::endl;
//     // std::cout << "operator return val = " << test._tree.tree_node->balance_factor << std::endl;

//     // std::cout << test[6] << std::endl;
//     // test.erase(20);
//     // test.erase(7);
//     // test.erase(4);
//     // std::cout << "pp first = " << test._tree.tree_node->_left_child->_value.first << "\npp second = " << test._tree.tree_node->_value.second << std::endl;
//     // std::cout << "operator return val = " << test._tree.tree_node->balance_factor << std::endl;
//     // std::cout << test_iterator->first << std::endl;
//     // std::cout << "pp first = " << test._tree.tree_node->_left_child->_left_child->_value.first << "\npp second = " << test._tree.tree_node->_left_child->_left_child->_value.second << std::endl;
//     // std::cout << "operator return val = " << test._tree.tree_node->balance_factor << std::endl;
//     // test.erase(0);
//     // test.erase(0);
//     // test.erase(0);
// }

bool fncomp (char lhs, char rhs) {return lhs<rhs;}

struct classcomp {
  bool operator() (const char& lhs, const char& rhs) const
  {return lhs<rhs;}
};

// bool mycomp (char c1, char c2)
// { return std::tolower(c1)<std::tolower(c2); }


int main ()
{
    // {
    //     std::map<std::string, int> mapOfWordCount;
    // // Insert Element in map
    //     mapOfWordCount.insert(std::pair<std::string, int>("first", 1));
    //     mapOfWordCount.insert(std::pair<std::string, int>("second", 2));
    //     mapOfWordCount.insert(std::pair<std::string, int>("third", 3));
    //     mapOfWordCount.insert(std::pair<std::string, int>("third", 4));
    //     mapOfWordCount.insert(std::pair<std::string, int>("third", 5));
    //     // Create a map iterator and point to beginning of map
    //     std::map<std::string, int>::iterator it = mapOfWordCount.begin();
    //     // Iterate over the map using Iterator till end.
    //     while (it != mapOfWordCount.end())
    //     {
    //         // Accessing KEY from element pointed by it.
    //         std::string word = it->first;
    //         // Accessing VALUE from element pointed by it.
    //         int count = it->second;
    //         std::cout << word << " :: " << count << std::endl;
    //         // Increment the Iterator to point to next entry
    //         it++;
    //     }
    // }
    // {
    //     ft::map<std::string, int> mapOfWordCount;
    // // Insert Element in map
    //     mapOfWordCount.insert(ft::pair<std::string, int>("first", 1));
    //     mapOfWordCount.insert(ft::pair<std::string, int>("second", 2));
    //     mapOfWordCount.insert(ft::pair<std::string, int>("third", 3));
    //     mapOfWordCount.insert(ft::pair<std::string, int>("third", 4));
    //     mapOfWordCount.insert(ft::pair<std::string, int>("third", 5));
    //     // Create a map iterator and point to beginning of map
    //     ft::map<std::string, int>::iterator it = mapOfWordCount.begin();
    //     // Iterate over the map using Iterator till end.
    //     while (it != mapOfWordCount.end())
    //     {
    //         // Accessing KEY from element pointed by it.
    //         std::string word = it->first;
    //         // Accessing VALUE from element pointed by it.
    //         int count = it->second;
    //         std::cout << word << " :: " << count << std::endl;
    //         // Increment the Iterator to point to next entry
    //         it++;
    //     }
    // }
    {
        std::map<int, int> gquiz1;
  
        // insert elements in random order
        gquiz1.insert(std::pair<int, int>(1, 40));
        gquiz1.insert(std::pair<int, int>(2, 30));
        gquiz1.insert(std::pair<int, int>(3, 60));
        gquiz1.insert(std::pair<int, int>(4, 20));
        gquiz1.insert(std::pair<int, int>(5, 50));
        gquiz1.insert(std::pair<int, int>(6, 50));
        gquiz1.insert(std::pair<int, int>(7, 10));
    
        // printing map gquiz1
        std::map<int, int>::iterator itr;
        std::cout << "\nThe map gquiz1 is : \n";
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
        std::cout << std::endl;
    
        // assigning the elements from gquiz1 to gquiz2
        std::map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
    
        // print all elements of the map gquiz2
        std::cout << "\nThe map gquiz2 after"
            << " assign from gquiz1 is : \n";
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
        std::cout << std::endl;
    
        // remove all elements up to
        // element with key=3 in gquiz2
        std::cout << "\ngquiz2 after removal of"
                " elements less than key=3 : \n";
        std::cout << "\tKEY\tELEMENT\n";
        gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
    
        // remove all elements with key = 4
        int num;
        num = gquiz2.erase(4);
        std::cout << "\ngquiz2.erase(4) : ";
        std::cout << num << " removed \n";
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
    
        std::cout << std::endl;
    
        // lower bound and upper bound for map gquiz1 key = 5
        std::cout << "gquiz1.lower_bound(5) : "
            << "\tKEY = ";
        std::cout << gquiz1.lower_bound(5)->first << '\t';
        std::cout << "\tELEMENT = "
            << gquiz1.lower_bound(5)->second << std::endl;
        std::cout << "gquiz1.upper_bound(5) : "
            << "\tKEY = ";
        std::cout << gquiz1.upper_bound(5)->first << '\t';
        std::cout << "\tELEMENT = "
            << gquiz1.upper_bound(5)->second << std::endl;
    }
    {
        ft::map<int, int> gquiz1;
  
        // insert elements in random order
        gquiz1.insert(ft::pair<int, int>(1, 40));
        gquiz1.insert(ft::pair<int, int>(2, 30));
        gquiz1.insert(ft::pair<int, int>(3, 60));
        gquiz1.insert(ft::pair<int, int>(4, 20));
        gquiz1.insert(ft::pair<int, int>(5, 50));
        gquiz1.insert(ft::pair<int, int>(6, 50));
        gquiz1.insert(ft::pair<int, int>(7, 10));
    
        // printing map gquiz1
        ft::map<int, int>::iterator itr;
        std::cout << "\nThe map gquiz1 is : \n";
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
        std::cout << std::endl;
    
        // assigning the elements from gquiz1 to gquiz2
        ft::map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
    
        // print all elements of the map gquiz2
        std::cout << "\nThe map gquiz2 after"
            << " assign from gquiz1 is : \n";
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
        std::cout << std::endl;
    
        // remove all elements up to
        // element with key=3 in gquiz2
        std::cout << "\ngquiz2 after removal of"
                " elements less than key=3 : \n";
        std::cout << "\tKEY\tELEMENT\n";
        gquiz2.erase(gquiz2.begin(), gquiz2.find(3));
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
    
        // remove all elements with key = 4
        int num;
        num = gquiz2.erase(4);
        std::cout << "\ngquiz2.erase(4) : ";
        std::cout << num << " removed \n";
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz2.begin(); itr != gquiz2.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
    
        std::cout << std::endl;
    
        // lower bound and upper bound for map gquiz1 key = 5
        std::cout << "gquiz1.lower_bound(5) : "
            << "\tKEY = ";
        std::cout << gquiz1.lower_bound(5)->first << '\t';
        std::cout << "\tELEMENT = "
            << gquiz1.lower_bound(5)->second << std::endl;
        std::cout << "gquiz1.upper_bound(5) : "
            << "\tKEY = ";
        std::cout << gquiz1.upper_bound(5)->first << '\t';
        std::cout << "\tELEMENT = "
            << gquiz1.upper_bound(5)->second << std::endl;
    }
    //////////////////////
    //CONSTRUCTORS////////
    //////////////////////
    // {
    //     std::map<char,int> first;

    //     first['a']=10;
    //     first['b']=30;
    //     first['c']=50;
    //     first['d']=70;

    //     std::map<char,int> second (first.begin(),first.end());

    //     std::map<char,int> third (second);

    //     std::map<char,int,classcomp> fourth;                 // class as Compare

    //     bool(*fn_pt)(char,char) = fncomp;
    //     std::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    // }
    // {
    //     ft::map<char,int> first;

    //     first['a']=10;
    //     first['b']=30;
    //     first['c']=50;
    //     first['d']=70;

    //     ft::map<char,int> second (first.begin(),first.end());

    //     ft::map<char,int> third (second);

    //     ft::map<char,int,classcomp> fourth;                 // class as Compare

    //     bool(*fn_pt)(char,char) = fncomp;
    //     ft::map<char,int,bool(*)(char,char)> fifth (fn_pt); // function pointer as Compare
    // }
    //////////////////////
    //OPERATOR=///////////
    //////////////////////
    // {
    //     std::map<char,int> first;
    //     std::map<char,int> second;

    //     first['x']=8;
    //     first['y']=16;
    //     first['z']=32;

    //     second=first;                // second now contains 3 ints
    //     first=std::map<char,int>();  // and first is now empty

    //     std::cout << second['x'] << std::endl;
    //     std::cout << second['y'] << std::endl;
    //     std::cout << second['z'] << std::endl;
    //     std::cout << "Size of first: " << first.size() << '\n';
    //     std::cout << "Size of second: " << second.size() << '\n';            ///sigfaults when u check on a nonexistant key////
    // }
    // {
    //     ft::map<char,int> first;
    //     ft::map<char,int> second;

    //     first['x']=8;
    //     first['y']=16;
    //     first['z']=32;

    //     second = first;                // second now contains 3 ints
    //     first=ft::map<char,int>();  // and first is now empty

    //     std::cout << second['x'] << std::endl;
    //     std::cout << second['y'] << std::endl;
    //     std::cout << second['z'] << std::endl;
    //     std::cout << "Size of first: " << first.size() << '\n';
    //     std::cout << "Size of second: " << second.size() << '\n';
    // }
    //////////////////////
    //BEGIN()/////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     mymap['b'] = 100;
    //     mymap['a'] = 200;
    //     mymap['c'] = 300;

    //     // show content:
    //     for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;
    //     mymap['b'] = 100;
    //     mymap['a'] = 200;
    //     mymap['c'] = 300;

    //     // show content:
    //     for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first<< " => " << it->second << '\n';
    // }
    //////////////////////
    ////END()/////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     mymap['b'] = 100;
    //     mymap['a'] = 200;
    //     mymap['c'] = 300;

    //     // show content:
    //     for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;

    //     mymap['b'] = 100;
    //     mymap['a'] = 200;
    //     mymap['c'] = 300;

    //     // show content:
    //     for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    //////////////////////
    //EMPTY()/////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     mymap['a']=10;
    //     mymap['b']=20;
    //     mymap['c']=30;

    //     while (!mymap.empty())
    //     {
    //         std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    //         mymap.erase(mymap.begin());
    //     }
    // }
    // {
    //     ft::map<char,int> mymap;

    //     mymap['a']=10;
    //     mymap['b']=20;
    //     mymap['c']=30;

    //     while (!mymap.empty())
    //     {
    //         std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
    //         mymap.erase(mymap.begin());
    //     }
    // }
    //////////////////////
    //SIZE()//////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;
    //     mymap['a']=101;
    //     mymap['b']=202;
    //     mymap['c']=302;

    //     std::cout << "mymap.size() is " << mymap.size() << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;
    //     mymap['a']=101;
    //     mymap['b']=202;
    //     mymap['c']=302;

    //     std::cout << "mymap.size() is " << mymap.size() << '\n';
    // }
    //////////////////////
    //max_size()//////////
    //////////////////////
    // {
    //     int i;
    //     std::map<int,int> mymap;

    //     if (mymap.max_size()>1000)
    //     {
    //         for (i=0; i<1000; i++) mymap[i]=0;
    //         std::cout << "The map contains 1000 elements.\n";
    //     }
    //     else std::cout << "The map could not hold 1000 elements.\n";
    // }
    // {
    //     int i;
    //     ft::map<int,int> mymap;

    //     if (mymap.max_size()>1000)
    //     {
    //         for (i=0; i<1000; i++) mymap[i]=0;
    //         std::cout << "The map contains 1000 elements.\n";
    //     }
    //     else std::cout << "The map could not hold 1000 elements.\n";
    // }
    //////////////////////
    //OPERATOR[]//////////
    //////////////////////
    // {
    //     std::map<char,std::string> mymap;

    //     mymap['a']="an element";
    //     mymap['b']="another element";
    //     mymap['c']=mymap['b'];

    //     std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    //     std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    //     std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    //     std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    //     std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    // }
    // {
    //     ft::map<char,std::string> mymap;

    //     mymap['a']="an element";
    //     mymap['b']="another element";
    //     mymap['c']=mymap['b'];

    //     std::cout << "mymap['a'] is " << mymap['a'] << '\n';
    //     std::cout << "mymap['b'] is " << mymap['b'] << '\n';
    //     std::cout << "mymap['c'] is " << mymap['c'] << '\n';
    //     std::cout << "mymap['d'] is " << mymap['d'] << '\n';

    //     std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    // }
    //////////////////////
    //INSERT()////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     // first insert function version (single parameter):
    //     mymap.insert ( std::pair<char,int>('a',100) );
    //     mymap.insert ( std::pair<char,int>('z',200) );

    //     std::pair<std::map<char,int>::iterator,bool> ret;
    //     ret = mymap.insert ( std::pair<char,int>('z',500) );
    //     if (ret.second==false) {
    //         std::cout << "element 'z' already existed";
    //         std::cout << " with a value of " << ret.first->second << '\n';
    //     }

    //     // second insert function version (with hint position):
    //     std::map<char,int>::iterator it = mymap.begin();
    //     mymap.insert (it, std::pair<char,int>('b',300));  // max efficiency inserting
    //     mymap.insert (it, std::pair<char,int>('c',400));  // no max efficiency inserting

    //     // third insert function version (range insertion):
    //     std::map<char,int> anothermap;
    //     anothermap.insert(mymap.begin(),mymap.find('c'));

    //     // showing contents:
    //     std::cout << "mymap contains:\n";
    //     for (it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';

    //     std::cout << "anothermap contains:\n";
    //     for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;

    //     // first insert function version (single parameter):
    //     mymap.insert ( ft::pair<char,int>('a',100) );
    //     mymap.insert ( ft::pair<char,int>('z',200) );

    //     ft::pair<ft::map<char,int>::iterator,bool> ret;
    //     ret = mymap.insert ( ft::pair<char,int>('z',500) );
    //     if (ret.second==false) {
    //         std::cout << "element 'z' already existed";
    //         std::cout << " with a value of " << ret.first->second << '\n';
    //     }

    //     // second insert function version (with hint position):
    //     ft::map<char,int>::iterator it = mymap.begin();
    //     mymap.insert (it, ft::pair<char,int>('b',300));  // max efficiency inserting
    //     mymap.insert (it, ft::pair<char,int>('c',400));  // no max efficiency inserting

    //     // third insert function version (range insertion):
    //     ft::map<char,int> anothermap;
    //     anothermap.insert(mymap.begin(),mymap.find('c'));

    //     // showing contents:
    //     std::cout << "mymap contains:\n";
    //     for (it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';

    //     std::cout << "anothermap contains:\n";
    //     for (it=anothermap.begin(); it!=anothermap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     std::map<int, int> mp;
    
    //     // insert elements in random order
    //     mp.insert(std::make_pair( 2, 30 ));
    //     mp.insert(std::make_pair( 1, 40 ));
    //     mp.insert(std::make_pair( 3, 60 ));
    
    //     // does not inserts key 2 with element 20
    //     mp.insert(std::make_pair( 2, 30 ));
    //     mp.insert(std::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "KEY\tELEMENT\n";
    //     for (std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    // {
    //     ft::map<int, int> mp;
    
    //     // insert elements in random order
    //     mp.insert(ft::make_pair( 2, 30 ));
    //     mp.insert(ft::make_pair( 1, 40 ));
    //     mp.insert(ft::make_pair( 3, 60 ));
    
    //     // does not inserts key 2 with element 20
    //     mp.insert(ft::make_pair( 2, 30 ));
    //     mp.insert(ft::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "KEY\tELEMENT\n";
    //     for (ft::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    //////////////////////
    //ERASE()/////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;
    //     std::map<char,int>::iterator it;

    //     mymap['a']=10;
    //     mymap['b']=20;
    //     mymap['c']=30;
    //     mymap['d']=40;
    //     mymap['e']=50;
    //     mymap['f']=60;

    //     it=mymap.find('b');
    //     mymap.erase (it);                   // erasing by iterator

    //     mymap.erase ('c');                  // erasing by key

    //     it=mymap.find ('e');
    //     mymap.erase ( it, mymap.end() );    // erasing by range
    //     // mymap['c']=30;
    //     // mymap['e']=50;
    //     // show content:
    //     for (it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;
    //     ft::map<char,int>::iterator it;

    //     mymap['a']=10;
    //     mymap['b']=20;                                              ////ERASE FUCKED UP///////
    //     mymap['c']=30;
    //     mymap['d']=40;
    //     mymap['e']=50;
    //     mymap['f']=60;

    //     it=mymap.find('b');
    //     mymap.erase (it);                   // erasing by iterator

    //     mymap.erase ('c');                  // erasing by key

    //     it=mymap.find ('e');
    //     mymap.erase ( it, mymap.end() );    // erasing by range
    //     // mymap['c']=30;
    //     // mymap['e']=50;
    //     // show content:
    //     for (it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     std::map<int, int> mp;
    
    //     // insert elements in random order
        // mp.insert(std::make_pair( 2, 30 ));
        // mp.insert(std::make_pair( 1, 40 ));
        // mp.insert(std::make_pair( 3, 60 ));
        // mp.insert(std::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "The map before using erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    
    //     // function to erase given keys
    //     mp.erase(1);
    //     mp.erase(2);
    
    //     // prints the elements
    //     std::cout << "\nThe map after applying erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    // {
    //     ft::map<int, int> mp;
    
    //     // insert elements in random order
    //     mp.insert(ft::make_pair( 2, 30 ));
    //     mp.insert(ft::make_pair( 1, 40 ));
    //     mp.insert(ft::make_pair( 3, 60 ));
    //     mp.insert(ft::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "The map before using erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (ft::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    
    //     // function to erase given keys
    //     mp.erase(1);
    //     mp.erase(2);
    
    //     // prints the elements
    //     std::cout << "\nThe map after applying erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (ft::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    // {
    //     std::map<int, int> mp;
    // // insert elements in random order
        // mp.insert(std::make_pair( 2, 30 ));
        // mp.insert(std::make_pair( 1, 40 ));
        // mp.insert(std::make_pair( 3, 60 ));
        // mp.insert(std::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "The map before using erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    
    //     // function to erase given position
    //     std::map<int, int>::iterator it = mp.find(2);
    //     mp.erase(it);
    
    //     std::map<int, int>::iterator it1 = mp.find(5);
    //     mp.erase(it1);
    
    //     // prints the elements
    //     std::cout << "\nThe map after applying erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    // {
    //     ft::map<int, int> mp;
    // // insert elements in random order
    //     mp.insert(ft::make_pair( 2, 30 ));
    //     mp.insert(ft::make_pair( 1, 40 ));
    //     mp.insert(ft::make_pair( 3, 60 ));
    //     mp.insert(ft::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "The map before using erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (ft::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    
    //     // function to erase given position
    //     ft::map<int, int>::iterator it = mp.find(2);
    //     mp.erase(it);
    
    //     ft::map<int, int>::iterator it1 = mp.find(5);
    //     mp.erase(it1);
    
    //     // prints the elements
    //     std::cout << "\nThe map after applying erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (ft::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    // {
    //     std::map<int, int> mp;
    //     // insert elements in random order
    //     mp.insert(std::make_pair( 2, 30 ));
    //     mp.insert(std::make_pair( 1, 40 ));
    //     mp.insert(std::make_pair( 3, 60 ));
    //     mp.insert(std::make_pair( 2, 20 ));
    //     mp.insert(std::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "The map before using erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    
    //     // function to erase in a given range
    //     // find() returns the iterator reference to
    //     // the position where the element is
    //     std::map<int, int>::iterator it1 = mp.find(2);
    //     std::map<int, int>::iterator it2 = mp.find(5);
    //     mp.erase(it1, it2);
    
    //     // prints the elements
    //     std::cout << "\nThe map after applying erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (std::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    // {
    //     ft::map<int, int> mp;
    //     // insert elements in random order
    //     mp.insert(ft::make_pair( 2, 30 ));
    //     mp.insert(ft::make_pair( 1, 40 ));
    //     mp.insert(ft::make_pair( 3, 60 ));
    //     mp.insert(ft::make_pair( 2, 20 ));
    //     mp.insert(ft::make_pair( 5, 50 ));
    
    //     // prints the elements
    //     std::cout << "The map before using erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (ft::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    
    //     // function to erase in a given range
    //     // find() returns the iterator reference to
    //     // the position where the element is
    //     ft::map<int, int>::iterator it1 = mp.find(2);
    //     ft::map<int, int>::iterator it2 = mp.find(5);
    //     mp.erase(it1, it2);
    
    //     // prints the elements
    //     std::cout << "\nThe map after applying erase() is : \n";
    //     std::cout << "KEY\tELEMENT\n";
    //     for (ft::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
    //         std::cout << itr->first
    //             << '\t' << itr->second << '\n';
    //     }
    // }
    //////////////////////
    //SWAP()//////////////
    //////////////////////
    // {
    //     std::map<char,int> foo,bar;

    //     foo['x']=100;
    //     foo['y']=200;

    //     bar['a']=11;
    //     bar['b']=22;
    //     bar['c']=33;

    //     foo.swap(bar);

    //     std::cout << "foo contains:\n";
    //     for (std::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    //     std::cout << "Foo size = " << foo.size() << std::endl;

    //     std::cout << "bar contains:\n";
    //     for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)                       /////SWAP LEAKS////
    //         std::cout << it->first << " => " << it->second << '\n';
    //     std::cout << "Bar size = " << bar.size() << std::endl;
    // }
    // {
    //     ft::map<char,int> foo,bar;

    //     foo['x']=100;
    //     foo['y']=200;

    //     bar['a']=11;
    //     bar['b']=22;
    //     bar['c']=33;

    //     foo.swap(bar);

    //     std::cout << "foo contains:\n";
    //     for (ft::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    //     std::cout << "Foo size = " << foo.size() << std::endl;

    //     std::cout << "bar contains:\n";
    //     for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    //     std::cout << "Bar size = " << bar.size() << std::endl;
    // }
    //////////////////////
    //CLEAR()/////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     mymap['x']=100;
    //     mymap['y']=200;
    //     mymap['z']=300;

    //     std::cout << "mymap contains:\n";
    //     for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';

    //     mymap.clear();
    //     mymap['a']=1101;
    //     mymap['b']=2202;

    //     std::cout << "mymap contains:\n";
    //     for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;

    //     mymap['x']=100;
    //     mymap['y']=200;
    //     mymap['z']=300;

    //     std::cout << "mymap contains:\n";
    //     for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';

    //     mymap.clear();
    //     mymap['a']=1101;                //SEGF WHEN U TRY THE LOOP WITHOUT ADDING ELEMENTS/////
    //     mymap['b']=2202;

    //     std::cout << "mymap contains:\n";
    //     for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    //////////////////////
    //LOWER_BOUND/////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;
    //     std::map<char,int>::iterator itlow,itup;

    //     mymap['a']=20;
    //     mymap['b']=40;
    //     mymap['c']=60;
    //     mymap['d']=80;
    //     mymap['e']=100;

    //     itlow=mymap.lower_bound ('b');  // itlow points to b
    //     itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    //     mymap.erase(itlow,itup);        // erases [itlow,itup)

    //     // print content:
    //     for (std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;
    //     ft::map<char,int>::iterator itlow,itup;

    //     mymap['a']=20;
    //     mymap['b']=40;
    //     mymap['c']=60;
    //     mymap['d']=80;
    //     mymap['e']=100;

    //     itlow=mymap.lower_bound ('b');  // itlow points to b
    //     itup=mymap.upper_bound ('d');   // itup points to e (not d!)

    //     mymap.erase(itlow,itup);        // erases [itlow,itup)

    //     // print content:
    //     for (ft::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    //////////////////////
    //EQUAL_RANGE/////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     mymap['a']=10;
    //     mymap['b']=20;
    //     mymap['c']=30;

    //     std::pair<std::map<char,int>::iterator,std::map<char,int>::iterator> ret;
    //     ret = mymap.equal_range('b');

    //     std::cout << "lower bound points to: ";
    //     std::cout << ret.first->first << " => " << ret.first->second << '\n';

    //     std::cout << "upper bound points to: ";
    //     std::cout << ret.second->first << " => " << ret.second->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;

    //     mymap['a']=10;
    //     mymap['b']=20;
    //     mymap['c']=30;

    //     ft::pair<ft::map<char,int>::iterator,ft::map<char,int>::iterator> ret;
    //     ret = mymap.equal_range('b');

    //     std::cout << "lower bound points to: ";
    //     std::cout << ret.first->first << " => " << ret.first->second << '\n';

    //     std::cout << "upper bound points to: ";
    //     std::cout << ret.second->first << " => " << ret.second->second << '\n';
    // }
    // {
    //     std::map<int, int> mp;
 
    //     // insert elements in random order
    //     mp.insert(std::make_pair ( 4, 30 ));
    //     mp.insert(std::make_pair ( 1, 40 ));
    //     mp.insert(std::make_pair ( 6, 60 ));
    
    //     std::pair<std::map<int, int>::iterator,
    //         std::map<int, int>::iterator>
    //         it;
    
    //     // iterator of pairs
    //     it = mp.equal_range(1);
    //     std::cout << "The lower bound is "
    //         << it.first->first
    //         << ":" << it.first->second;
    
    //     std::cout << "\nThe upper bound is "
    //         << it.second->first
    //         << ":" << it.second->second <<std::endl;
    // }
    // {
    //     ft::map<int, int> mp;
 
    //     // insert elements in random order
    //     mp.insert(ft::make_pair ( 4, 30 ));
    //     mp.insert(ft::make_pair ( 1, 40 ));
    //     mp.insert(ft::make_pair ( 6, 60 ));
    
    //     ft::pair<ft::map<int, int>::iterator,
    //         ft::map<int, int>::iterator>
    //         it;
    
    //     // iterator of pairs
    //     it = mp.equal_range(1);
    //     std::cout << "The lower bound is "
    //         << it.first->first
    //         << ":" << it.first->second;
    
    //     std::cout << "\nThe upper bound is "
    //         << it.second->first
    //         << ":" << it.second->second;
    //     std::cout << std::endl;
    // }
    ///still  testing equal range
    // {
    //     std::map<int, int> mp;
 
    //     // insert elements in random order
    //     mp.insert(std::make_pair ( 4, 30 ));
    //     mp.insert(std::make_pair ( 1, 40 ));
    //     mp.insert(std::make_pair ( 6, 60 ));
    
    //     std::pair<std::map<int, int>::iterator,
    //         std::map<int, int>::iterator>        /////something aint right here/////
    //         it;
    
    //     // iterator of pairs
    //     it = mp.equal_range(10);
    //     std::cout << "The lower bound is "
    //         << it.first->first << ":"
    //         << it.first->second;
    
    //     std::cout << "\nThe upper bound is "
    //         << it.second->first
    //         << ":" << it.second->second;
    // }
    // {
    //     ft::map<int, int> mp;
 
    //     // insert elements in random order
    //     mp.insert(ft::make_pair ( 4, 30 ));
    //     mp.insert(ft::make_pair ( 1, 40 ));
    //     mp.insert(ft::make_pair ( 6, 60 ));
    
    //     ft::pair<ft::map<int, int>::iterator,
    //         ft::map<int, int>::iterator>        /////something aint right here/////
    //         it;
    
    //     // iterator of pairs
    //     it = mp.equal_range(10);
    //     std::cout << "The lower bound is "
    //         << it.first->first << ":"
    //         << it.first->second;
    
    //     std::cout << "\nThe upper bound is "
    //         << it.second->first
    //         << ":" << it.second->second;
    // }
    //////////////////////
    //KEY_COMP////////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     std::map<char,int>::key_compare mycomp = mymap.key_comp();

    //     mymap['a']=100;
    //     mymap['b']=200;
    //     mymap['c']=300;

    //     std::cout << "mymap contains:\n";

    //     char highest = mymap.rbegin()->first;     // key value of last element

    //     std::map<char,int>::iterator it = mymap.begin();
    //     do {     
    //         std::cout << it->first << " => " << it->second << '\n';                                  ///////reverse_iterator still fucked up/////
    //     } while ( mycomp((*it++).first, highest) );

    //     std::cout << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;

    //     ft::map<char,int>::key_compare mycomp = mymap.key_comp();

    //     mymap['a']=100;
    //     mymap['b']=200;
    //     mymap['c']=300;

    //     std::cout << "mymap contains:\n";

    //     char highest = mymap.rbegin()->first;     // key value of last element

    //     ft::map<char,int>::iterator it = mymap.begin();
    //     do {     
    //         std::cout << it->first << " => " << it->second << '\n';                                  ///////reverse_iterator still fucked up/////
    //     } while ( mycomp((*it++).first, highest) );

    //     std::cout << '\n';
    // }
    //////////////////////
    //VALUE_COMP//////////
    //////////////////////
    // {
    //     std::map<char,int> mymap;

    //     mymap['x']=1001;
    //     mymap['y']=2002;
    //     mymap['z']=3003;

    //     std::cout << "mymap contains:\n";

    //     std::pair<char,int> highest = *mymap.rbegin();          // last element

    //     std::map<char,int>::iterator it = mymap.begin();
    //     do {
    //         std::cout << it->first << " => " << it->second << '\n';
    //     } while ( mymap.value_comp()(*it++, highest) );
    // }
    // {
    //     ft::map<char,int> mymap;

    //     mymap['x']=1001;
    //     mymap['y']=2002;
    //     mymap['z']=3003;

    //     std::cout << "mymap contains:\n";

    //     ft::pair<char,int> highest = *mymap.rbegin();          // last element

    //     ft::map<char,int>::iterator it = mymap.begin();
    //     do {
    //         std::cout << it->first << " => " << it->second << '\n';
    //     } while ( mymap.value_comp()(*it++, highest) );
    // }
    // {
    //     map<char, int> m = {
    //         { 'a', 1 },
    //         { 'b', 2 },
    //         { 'c', 3 },
    //         { 'd', 4 },
    //         { 'e', 5 },
    //     };
    
    //     auto last = *m.rbegin();
    //     auto i = m.begin();
    
    //     cout << "Map contains "
    //         << "following elements"
    //         << endl;
    
    //     do {
    
    //         cout << i->first
    //             << " = "
    //             << i->second
    //             << endl;
    //     } while (m.value_comp()(*i++, last));
    // }
//   return 0;
    // std::map<int , int> mymap;
    // mymap[10] = 20;
    // mymap[-1] = 20;
    // mymap[2] = 20;
    // mymap[40] = 20;
    // mymap[20] = 20;
    // mymap[25] = 20;
    // mymap[30] = 20;
    // mymap[27] = 20;
    // std::map<int , int> mysecmap(mymap);
    // for (std::map<int, int>::iterator it = mymap.begin(); it != mymap.end(); it++)
    // {
    //     std::cout << it->first << std::endl;
    // }
    // ft::stack<int> name;
    // name.push(10);
    // std::cout << name.empty() << std::endl;
    // mp.insert(mp2.begin(), mp2.end());
    // mp.equal_range(5);
    // // std::cout << mp[0] << std::endl;
    // // std::cout << mp[1] << std::endl;
    // // std::cout << mp[2] << std::endl;
    // // std::cout << mp[3] << std::endl;
    // // std::cout << mp.size() << std::endl;
    // // mp2.insert(mp.begin() , mp.end());
    // for (ft::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
    // {
    //     std::cout << it->first <<std::endl;
    // }
    // mp.clear();
    
    // vec.pop_back();
    // vec.pop_back();
    // vec.pop_back();
    // vec.pop_back();
    // {
    // ft::map<int, int> mp;
    // mp[41] = 0;
    // mp[20] = 10;
    // mp[65] = 20;
    // mp[29] = 30;
    // mp[11] = 30;
    // mp[50] = 30;
    // mp[91] = 30;
    // mp[32] = 30;
    // mp[72] = 30;
    // mp[99] = 30;
    // ft::map<int, int> mp2(mp);
    // // mp.erase(41);
    // mp.clear();
    // // mp[41] = 0;
    // // mp[73] = 0;
    // // mp[2] = 10;
    // // mp.erase(1);
    // for (ft::map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
    // {
    //     std::cout << it->first << " = " << it->second << std::endl;
    // }
    // }
    // {
    //     char foo[]="Apple";
    //     char bar[]="apartment";

    //     std::cout << std::boolalpha;

    //     std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

    //     std::cout << "Using default comparison (operator<): ";
    //     std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9);
    //     std::cout << '\n';

    //     std::cout << "Using mycomp as comparison object: ";
    //     std::cout << std::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
    //     std::cout << '\n';
    // }
    // {
    //     char foo[]="Apple";
    //     char bar[]="apartment";

    //     std::cout << std::boolalpha;

    //     std::cout << "Comparing foo and bar lexicographically (foo<bar):\n";

    //     std::cout << "Using default comparison (operator<): ";
    //     std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9);
    //     std::cout << '\n';

    //     std::cout << "Using mycomp as comparison object: ";
    //     std::cout << ft::lexicographical_compare(foo,foo+5,bar,bar+9,mycomp);
    //     std::cout << '\n';
    // }
    
}