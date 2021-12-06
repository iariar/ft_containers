#include "Vector.hpp"
// #include "map.hpp"
#include <map>


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

int main()
{
    ft::vector<int> test;

    test.get_allocator();
}