#include "vector.hpp"
#include "map.hpp"
#include <map>
#include "stack.hpp"
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

// int main ()
// {
//     {
        ////////////////////////
        //testing constructors//
        ////////////////////////
        // {
        //     {
        //         std::vector<int> first;                                // empty vector of ints
        //         std::vector<int> second (4,100);                       // four ints with value 100
        //         std::vector<int> third (second.begin(),second.end());  // iterating through second
        //         std::vector<int> fourth (third);                       // a copy of third

        //         // the iterator constructor can also be used to construct from arrays:
        //         int myints[] = {16,2,77,29};
        //         std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        //         std::cout << "The contents of fifth are:";
        //         for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        //             std::cout << ' ' << *it;
        //         std::cout << '\n';
        //     }
        //     {
        //         ft::vector<int> first;                                // empty vector of ints
        //         ft::vector<int> second (4,100);                       // four ints with value 100
        //         ft::vector<int> third (second.begin(),second.end());  // iterating through second
        //         ft::vector<int> fourth (third);                       // a copy of third

        //         // the iterator constructor can also be used to construct from arrays:
        //         int myints[] = {16,2,77,29};
        //         ft::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

        //         std::cout << "The contents of fifth are:";
        //         for (ft::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
        //             std::cout << ' ' << *it;
        //         std::cout << '\n';
        //     }
        // }
        ////////////////////////
        //TESTING OPERATOR=/////
        ////////////////////////
        // {
        //     std::vector<int> foo (3,0);
        //     std::vector<int> bar (5,0);

        //     bar = foo;
        //     foo = std::vector<int>();

        //     std::cout << "Size of foo: " << int(foo.size()) << '\n';
        //     std::cout << "Size of bar: " << int(bar.size()) << '\n';
        // }
        // {
        //     ft::vector<int> foo (3,0);
        //     ft::vector<int> bar (5,0);

        //     bar = foo;
        //     foo = ft::vector<int>();

        //     std::cout << "Size of foo: " << int(foo.size()) << '\n';
        //     std::cout << "Size of bar: " << int(bar.size()) << '\n';
        // }
        ////////////////////
        //TESTING BEGIN()///
        ////////////////////
        // {  
        //     std::vector<int> myvector;
        //     for (int i=1; i<=5; i++) myvector.push_back(i);
        //         std::cout << "myvector contains:";
        //     for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        // {  
        //     ft::vector<int> myvector;
        //     for (int i=1; i<=5; i++) myvector.push_back(i);
        //         std::cout << "myvector contains:";
        //     for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        ////////////////////
        //TESTING END()/////
        ////////////////////
        // {
        //     std::vector<int> myvector;
        //     for (int i=1; i<=5; i++) myvector.push_back(i);

        //     std::cout << "myvector contains:";
        //     for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> myvector;
        //     for (int i=1; i<=5; i++) myvector.push_back(i);

        //     std::cout << "myvector contains:";
        //     for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        ////////////////////
        //TESTING RBEGIN()//
        ////////////////////
        // {
        //     std::vector<int> myvector (5);  // 5 default-constructed ints

        //     int i=0;

        //     std::vector<int>::reverse_iterator rit = myvector.rbegin();
        //     for (; rit!= myvector.rend(); ++rit)
        //         *rit = ++i;

        //     std::cout << "myvector contains:";
        //     for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> myvector (5);  // 5 default-constructed ints

        //     int i = 0;

        //     ft::vector<int>::reverse_iterator rit = myvector.rbegin();
        //     for (; rit!= myvector.rend(); ++rit)
        //         *rit = ++i;

        //     std::cout << "myvector contains:";
        //     for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        ////////////////////
        //TESTING REND()////
        ////////////////////
        // {
        //     std::vector<int> myvector (5);  // 5 default-constructed ints
        //     std::vector<int>::reverse_iterator rit = myvector.rbegin();

        //     int i=0;
        //     for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
        //         *rit = ++i;

        //     std::cout << "myvector contains:";
        //     for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> myvector (5);  // 5 default-constructed ints
        //     ft::vector<int>::reverse_iterator rit = myvector.rbegin();

        //     int i=0;
        //     for (rit = myvector.rbegin(); rit!= myvector.rend(); ++rit)
        //         *rit = ++i;

        //     std::cout << "myvector contains:";
        //     for (ft::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
        //         std::cout << ' ' << *it;
        //     std::cout << '\n';
        // }
        ////////////////////
        //TESTING SIZE()////
        ////////////////////
        // {
        //     std::vector<int> myints;
        //     std::cout << "0. size: " << myints.size() << '\n';

        //     for (int i=0; i<10; i++) myints.push_back(i);
        //     std::cout << "1. size: " << myints.size() << '\n';

        //     myints.insert (myints.end(),10,100);
        //     std::cout << "2. size: " << myints.size() << '\n';

        //     myints.pop_back();
        //     std::cout << "3. size: " << myints.size() << '\n';
        //     std::cout << "end of std::vector" << std::endl;
        // }
        // {
        //     ft::vector<int> myints;
        //     std::cout << "0. size: " << myints.size() << '\n';

        //     for (int i=0; i<10; i++) myints.push_back(i);
        //     std::cout << "1. size: " << myints.size() << '\n';

        //     myints.insert (myints.end(),10,100);
        //     std::cout << "2. size: " << myints.size() << '\n';

        //     myints.pop_back();
        //     std::cout << "3. size: " << myints.size() << '\n';
        // }
        ////////////////////////
        //TESTING MAX_SIZE()////
        ///////////////////////
        // {
        //     std::vector<int> myvector;

        //     // set some content in the vector:
        //     for (int i=0; i<100; i++)
        //     {
        //         myvector.push_back(i);
        //     }

        //     std::cout << "size: " << myvector.size() << "\n";
        //     std::cout << "capacity: " << myvector.capacity() << "\n";
        //     std::cout << "max_size: " << myvector.max_size() << "\n";
        // }
        // {
        //     ft::vector<int> myvector;

        //     // set some content in the vector:
        //     for (int i=0; i<100; i++) myvector.push_back(i);

        //     std::cout << "size: " << myvector.size() << "\n";
        //     std::cout <<  "capacity: " << myvector.capacity() << "\n";             ///////////FIXED//////////
        //     std::cout << "max_size: " << myvector.max_size() << "\n";
        // }
        ///////////////////////
        //TESTING RESIZE()/////
        ///////////////////////
        // {
        //     std::vector<int> myvector;

        //     // set some initial content:
        //     for (int i=1;i<10;i++) myvector.push_back(i);

        //     myvector.resize(5);
        //     myvector.resize(8,100);
        //     myvector.resize(12);

        //     std::cout << "myvector contains:";
        //     for (int i=0; i < myvector.size();i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> myvector;

        //     // set some initial content:
        //     for (int i=1;i<10;i++) myvector.push_back(i);

        //     myvector.resize(5);
        //     myvector.resize(8,100);
        //     myvector.resize(12);

        //     std::cout << "myvector contains:";
        //     for (int i=0;i<myvector.size();i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }
        ///////////////////////
        //TESTING CAPACITY()///
        ///////////////////////
        // {
        //     std::vector<int> myvector;

        //     // set some content in the vector:
        //     for (int i=0; i<100; i++) myvector.push_back(i);

        //     std::cout << "size: " << (int) myvector.size() << '\n';
        //     std::cout << "capacity: " << (int) myvector.capacity() << '\n';
        //     std::cout << "max_size: " << (int) myvector.max_size() << '\n';
        // }
        // {
        //     ft::vector<int> myvector;

        //     // set some content in the vector:
        //     for (int i=0; i<100; i++) myvector.push_back(i);

        //     std::cout << "size: " << (int) myvector.size() << '\n';
        //     std::cout << "capacity: " << (int) myvector.capacity() << '\n';//FIXED
        //     std::cout << "max_size: " << (int) myvector.max_size() << '\n';
        // }
        ///////////////////////
        //TESTING EMPTY()//////
        ///////////////////////
        // {
        //     std::vector<int> myvector;
        //     int sum (0);

        //     for (int i=1;i<=10;i++) myvector.push_back(i);

        //     while (!myvector.empty())
        //     {
        //         sum += myvector.back();
        //         myvector.pop_back();
        //     }

        //     std::cout << "total: " << sum << '\n';
        // }
        // {
        //     ft::vector<int> myvector;
        //     int sum (0);

        //     for (int i=1;i<=10;i++) myvector.push_back(i);

        //     while (!myvector.empty())
        //     {
        //         sum += myvector.back();
        //         myvector.pop_back();
        //     }

        //     std::cout << "total: " << sum << '\n';
        // }
        ///////////////////////
        //TESTING RESERVE()////
        ///////////////////////
        // {
        //     std::vector<int>::size_type sz;

        //     std::vector<int> foo;
        //     sz = foo.capacity();
        //     std::cout << "making foo grow:\n";
        //     for (int i=0; i<100; ++i) {
        //         foo.push_back(i);
        //         if (sz!=foo.capacity()) {
        //         sz = foo.capacity();
        //         std::cout << "capacity changed: " << sz << '\n';
        //         }
        //     }

        //     std::vector<int> bar;
        //     sz = bar.capacity();
        //     bar.reserve(100);   // this is the only difference with foo above
        //     std::cout << "making bar grow:\n";
        //     for (int i=0; i<100; ++i) {
        //         bar.push_back(i);
        //         if (sz!=bar.capacity()) {
        //         sz = bar.capacity();
        //         std::cout << "capacity changed: " << sz << '\n';
        //         }
        //     }
        // }
        // std::cout << "End of std vector <<<<<<<<<" << std::endl;
        // {
        //     ft::vector<int>::size_type sz;

        //     ft::vector<int> foo;
        //     sz = foo.capacity();
        //     std::cout << "making foo grow:\n";
        //     for (int i=0; i<100; ++i) {
        //         foo.push_back(i);
        //         if (sz!=foo.capacity()) {
        //         sz = foo.capacity();
        //         std::cout << "capacity changed: " << sz << '\n';
        //         }
        //     }

        //     ft::vector<int> bar;
        //     sz = bar.capacity();
        //     bar.reserve(100);   // this is the only difference with foo above
        //     std::cout << "making bar grow:\n";
        //     for (int i=0; i<100; ++i) {
        //         bar.push_back(i);
        //         if (sz!=bar.capacity()) {
        //         sz = bar.capacity();
        //         std::cout << "capacity changed: " << sz << '\n';
        //         }
        //     }
        // }
        ///////////////////////
        //TESTING OERATOR[]////
        ///////////////////////
        // {
        //     std::vector<int> myvector (10);   // 10 zero-initialized elements

        //     std::vector<int>::size_type sz = myvector.size();

        //     // assign some values:
        //     for (unsigned i=0; i<sz; i++) myvector[i]=i;

        //     // reverse vector using operator[]:
        //     for (unsigned i=0; i<sz/2; i++)
        //     {
        //         int temp;
        //         temp = myvector[sz-1-i];
        //         myvector[sz-1-i]=myvector[i];
        //         myvector[i]=temp;
        //     }

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<sz; i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';

        // }
        // {
        //     ft::vector<int> myvector (10);   // 10 zero-initialized elements

        //     ft::vector<int>::size_type sz = myvector.size();

        //     // assign some values:
        //     for (unsigned i=0; i<sz; i++) myvector[i]=i;

        //     // reverse vector using operator[]:
        //     for (unsigned i=0; i<sz/2; i++)
        //     {
        //         int temp;
        //         temp = myvector[sz-1-i];
        //         myvector[sz-1-i]=myvector[i];
        //         myvector[i]=temp;
        //     }

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<sz; i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';

        // }
        ///////////////////////
        //TESTING AT///////////
        ///////////////////////
        // {
        //     std::vector<int> myvector (10);   // 10 zero-initialized ints

        //     // assign some values:
        //     for (unsigned i=0; i<myvector.size(); i++)
        //         myvector.at(i)=i;

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); i++)
        //         std::cout << ' ' << myvector.at(i);
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> myvector (10);   // 10 zero-initialized ints

        //     // assign some values:
        //     for (unsigned i=0; i<myvector.size(); i++)
        //         myvector.at(i)=i;

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); i++)
        //         std::cout << ' ' << myvector.at(i);
        //     std::cout << '\n';
        // }
        ///////////////////////
        //TESTING FRONT////////
        ///////////////////////
        // {
        //     std::vector<int> myvector;

        //     myvector.push_back(78);
        //     myvector.push_back(16);

        //     // now front equals 78, and back 16

        //     myvector.front() -= myvector.back();

        //     std::cout << "myvector.front() is now " << myvector.front() << '\n';
        // }
        // {
        //     ft::vector<int> myvector;

        //     myvector.push_back(78);
        //     myvector.push_back(16);

        //     // now front equals 78, and back 16

        //     myvector.front() -= myvector.back();

        //     std::cout << "myvector.front() is now " << myvector.front() << '\n';
        // }
        ///////////////////////
        //TESTING  BACK////////
        ///////////////////////
        // {
        //     std::vector<int> myvector;

        //     myvector.push_back(10);

        //     while (myvector.back() != 0)
        //     {
        //         myvector.push_back ( myvector.back() -1 );
        //     }

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size() ; i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> myvector;

        //     myvector.push_back(10);

        //     while (myvector.back() != 0)
        //     {
        //         myvector.push_back ( myvector.back() -1 );
        //     }

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size() ; i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }
        ///////////////////////
        //TESTING  ASSIGN//////
        // ///////////////////////
        // {
        //     std::vector<int> first;
        //     std::vector<int> second;
        //     std::vector<int> third;

        //     first.assign (7,100);             // 7 ints with a value of 100

        //     std::vector<int>::iterator it;
        //     it=first.begin()+1;

        //     second.assign (it,first.end()-1); // the 5 central values of first

        //     int myints[] = {1776,7,4};
        //     third.assign (myints,myints+3);   // assigning from array.

        //     std::cout << "Size of first: " << int (first.size()) << '\n';
        //     std::cout << "Size of second: " << int (second.size()) << '\n';
        //     std::cout << "Size of third: " << int (third.size()) << '\n';
        // }
        // {
        //     ft::vector<int> first;
        //     ft::vector<int> second;
        //     ft::vector<int> third;

        //     first.assign (7,100);             // 7 ints with a value of 100

        //     ft::vector<int>::iterator it;
        //     it=first.begin()+1;

        //     second.assign (it,first.end()-1); // the 5 central values of first

        //     int myints[] = {1776,7,4};
        //     third.assign (myints,myints+3);   // assigning from array.

        //     std::cout << "Size of first: " << int (first.size()) << '\n';
        //     std::cout << "Size of second: " << int (second.size()) << '\n';
        //     std::cout << "Size of third: " << int (third.size()) << '\n';/////////////////////FIXEDDDDD/////////////////
        // }
        ///////////////////////
        //TESTING PUSH_BACK////
        ///////////////////////
        // {
        //     std::vector<int> myvector;
        //     int myint;

        //     std::cout << "Please enter some integers (enter 0 to end):\n";

        //     do {
        //         std::cin >> myint;
        //         myvector.push_back (myint);
        //     } while (myint);

        //     std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        // }
        // {
        //    ft::vector<int> myvector;
        //     int myint;

        //     std::cout << "Please enter some integers (enter 0 to end):\n";

        //     do {
        //         std::cin >> myint;
        //         myvector.push_back (myint);
        //     } while (myint);

        //     std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        // }
        ///////////////////////
        //TESTING POP_BACK/////
        ///////////////////////
        // {
        //     std::vector<int> myvector;
        //     int sum (0);
        //     myvector.push_back (100);
        //     myvector.push_back (200);
        //     myvector.push_back (300);

        //     while (!myvector.empty())
        //     {
        //         sum+=myvector.back();
        //         myvector.pop_back();
        //     }

        //     std::cout << "The elements of myvector add up to " << sum << '\n';
        // }
        // {
        //     ft::vector<int> myvector;
        //     int sum (0);
        //     myvector.push_back (100);
        //     myvector.push_back (200);
        //     myvector.push_back (300);

        //     while (!myvector.empty())
        //     {
        //         sum+=myvector.back();
        //         myvector.pop_back();
        //     }

        //     std::cout << "The elements of myvector add up to " << sum << '\n';
        // }
        ///////////////////////
        //TESTING INSERT///////
        ///////////////////////
            // {
            //     std::vector<int> myvector (3,100);
            //     std::vector<int>::iterator it;

            //     it = myvector.begin();
            //     it = myvector.insert ( it , 200 );

            //     std::cout << "std capacity = " << myvector.capacity() << std::endl;
            //     myvector.insert (it,10,300);

            //     // "it" no longer valid, get a new one:
            //     it = myvector.begin();

            //     std::vector<int> anothervector (2,400);
            //     std::cout << "std capacity = " << myvector.capacity() << std::endl;
            //     myvector.insert (it+1,anothervector.begin(),anothervector.end());
            //     std::cout << "std capacity = " << myvector.capacity() << std::endl;
            //     int myarray [] = { 501,502,503 };
            //     myvector.insert (myvector.begin(), myarray, myarray+3);

            //     std::cout << "std capacity = " << myvector.capacity() << std::endl;
            //     std::cout << "myvector contains:";
            //     for (it=myvector.begin(); it<myvector.end(); it++)
            //         std::cout << ' ' << *it;
            //     std::cout << '\n';
            // }
            // {
            //     ft::vector<int> myvector (3,100);
            //     ft::vector<int>::iterator it;

            //     it = myvector.begin();
            //     it = myvector.insert ( it , 200 );////////////WRONG CAPACITY/////////////

            //     std::cout << "my capacity = " << myvector.capacity() << std::endl;
            //     myvector.insert (it,10,300);

            //     // "it" no longer valid, get a new one:
            //     it = myvector.begin();

            //     ft::vector<int> anothervector (2,400);
                
            //     std::cout << "my capacity = " << myvector.capacity() << std::endl;
            //     myvector.insert (it+1,anothervector.begin(),anothervector.end());

            //     std::cout << "my capacity = " << myvector.capacity() << std::endl;
            //     int myarray [] = { 501,502,503 };
            //     myvector.insert (myvector.begin(), myarray, myarray+3);

            //     std::cout << "my capacity = " << myvector.capacity() << std::endl;
            //     std::cout << "myvector contains:";
            //     for (it=myvector.begin(); it < myvector.end(); it++)
            //         std::cout << ' ' << *it;
            //     std::cout << '\n';
            // }
        ///////////////////////
        //TESTING ERASE////////
        /////////////////////// 
        // {
        //     std::vector<int> myvector;

        //     // set some values (from 1 to 10)
        //     for (int i=1; i<=10; i++) myvector.push_back(i);

        //     // erase the 6th element
        //     myvector.erase (myvector.begin()+5);

        //     // erase the first 3 elements:
        //     myvector.erase (myvector.begin(),myvector.begin()+3);

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); ++i)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> myvector;

        //     // set some values (from 1 to 10)
        //     for (int i=1; i<=10; i++) myvector.push_back(i);

        //     // erase the 6th element
        //     myvector.erase (myvector.begin()+5);

        //     // erase the first 3 elements:
        //     myvector.erase (myvector.begin(),myvector.begin()+3);

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); ++i)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }
        ///////////////////////
        //TESTING SWAP/////////
        ///////////////////////
        // {
        //     std::vector<int> foo (3,100);   // three ints with a value of 100
        //     std::vector<int> bar (5,200);   // five ints with a value of 200

        //     foo.swap(bar);

        //     std::cout << "foo contains:";
        //     for (unsigned i=0; i<foo.size(); i++)
        //         std::cout << ' ' << foo[i];
        //     std::cout << '\n';

        //     std::cout << "bar contains:";
        //     for (unsigned i=0; i<bar.size(); i++)
        //         std::cout << ' ' << bar[i];
        //     std::cout << '\n';
        // }
        // {
        //     ft::vector<int> foo (3,100);   // three ints with a value of 100//////////////////fixed///////////////////
        //     ft::vector<int> bar (5,200);   // five ints with a value of 200

        //     foo.swap(bar);

        //     std::cout << "foo contains:";
        //     for (unsigned i=0; i<foo.size(); i++)
        //         std::cout << ' ' << foo[i];
        //     std::cout << '\n';

        //     std::cout << "bar contains:";
        //     for (unsigned i=0; i<bar.size(); i++)
        //         std::cout << ' ' << bar[i];
        //     std::cout << '\n';
        // }
        //////////////////////////
        //TESTING PCLEAR//////////
        // ///////////////////////
        // {
        //     std::vector<int> myvector;
        //     myvector.push_back (100);
        //     myvector.push_back (200);
        //     myvector.push_back (300);

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';

        //     myvector.clear();
        //     myvector.push_back (1101);
        //     myvector.push_back (2202);

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); i++)/////////////////fixed////////////////
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }
        // std::cout << "END OF STD::VECTOR" << std::endl;
        // {
        //     ft::vector<int> myvector;
        //     myvector.push_back (100);
        //     myvector.push_back (200);
        //     myvector.push_back (300);

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';

        //     myvector.clear();
        //     myvector.push_back (1101);
        //     myvector.push_back (2202);

        //     std::cout << "myvector contains:";
        //     for (unsigned i=0; i<myvector.size(); i++)
        //         std::cout << ' ' << myvector[i];
        //     std::cout << '\n';
        // }

//     }
    
// }

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
    //         std::cout << *rev_iterator++ << ' ';
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

    //     std::cout << "The fourth element from the end is: " << rev_iterator[3] << '\n';
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
    //     for (int i=0; i<10; i++) myvector.push_back(i);     //////////////SEGFAULT/////////////

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
    //     for (int i=0; i<10; i++) myvector.push_back(i);	// myvector: 0 1 2 3 4 5 6 7 8 9/////////EXAMPLE NOT WORKING////////

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

//  struct t
//     {
//         int a;
//     };
// bool mycomp (char c1, char c2)
// { return std::tolower(c1)<std::tolower(c2); }
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

int main ()
{
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

    //     std::cout << "Size of first: " << first.size() << '\n';
    //     std::cout << "Size of second: " << second.size() << '\n';
    // }
    // {
    //     ft::map<char,int> first;
    //     ft::map<char,int> second;

    //     first['x']=8;
    //     first['y']=16;
    //     first['z']=32;


    //     second=first;                // second now contains 3 ints
    //     first=ft::map<char,int>();  // and first is now empty

    //     std::cout << "Size of first: " << second.size() << '\n';
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
    //         std::cout << it->first << " => " << it->second << '\n';
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
    //     // show content:
    //     for (it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
    // }
    // {
    //     ft::map<char,int> mymap;
    //     ft::map<char,int>::iterator it;

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

    //     // show content:
    //     for (it=mymap.begin(); it!=mymap.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
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

    //     std::cout << "bar contains:\n";
    //     for (std::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
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

    //     std::cout << "bar contains:\n";
    //     for (ft::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
    //         std::cout << it->first << " => " << it->second << '\n';
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
        // mp.insert(ft::make_pair ( 4, 30 ));
        // mp.insert(ft::make_pair ( 1, 40 ));
        // mp.insert(ft::make_pair ( 6, 60 ));
    
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
    // }
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
    //         std::cout << it->first << " => " << it->second << '\n';
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
    //         std::cout << it->first << " => " << it->second << '\n';
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
        // ft::map<char,int> mymap;

        // mymap['x']=1001;
        // mymap['y']=2002;
        // mymap['z']=3003;

    //     std::cout << "mymap contains:\n";

    //     ft::pair<char,int> highest = *mymap.rbegin();          // last element

    //     ft::map<char,int>::iterator it = mymap.begin();
    //     do {
    //         std::cout << it->first << " => " << it->second << '\n';
    //     } while ( mymap.value_comp()(*it++, highest) );
    // }
    // {
        // map<char, int> m = {
        //     { 'a', 1 },
        //     { 'b', 2 },
        //     { 'c', 3 },
        //     { 'd', 4 },
        //     { 'e', 5 },
        // };
    
        // auto last = *m.rbegin();
        // auto i = m.begin();
    
        // cout << "Map contains "
        //     << "following elements"
        //     << endl;
    
        // do {
    
        //     cout << i->first
        //         << " = "
        //         << i->second
        //         << endl;
        // } while (m.value_comp()(*i++, last));
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
    ft::map<int, int> mp;
    mp[0] = 1;
    mp[1] = 1;
    mp[2] = 1;
    mp[3] = 1;
    ft::map<int, int> mp2;
    mp2.insert(mp.begin() , mp.end());
    for (ft::map<int, int>::iterator it = mp2.begin(); it != mp2.end(); it++)
    {
        std::cout << it->first <<std::endl;
    }
    
    // vec.pop_back();
    // vec.pop_back();
    // vec.pop_back();
    // vec.pop_back();
}