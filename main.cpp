#include "Vector.hpp"


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

int main ()
{
    {
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
    //     {  
    //         std::vector<int> myvector;
    //         for (int i=1; i<=5; i++) myvector.push_back(i);
    //             std::cout << "myvector contains:";
    //         for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << '\n';
    //     }
    //     {  
    //         ft::vector<int> myvector;
    //         for (int i=1; i<=5; i++) myvector.push_back(i);
    //             std::cout << "myvector contains:";
    //         for (ft::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
    //             std::cout << ' ' << *it;
    //         std::cout << '\n';
    //     }
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
        //     std::cout << "Size of third: " << int (third.size()) << '\n';/////////////////////NOT WORKING PROPERLY/////////////////
        // }
        // {
        //     ft::vector<int> first;
        //     ft::vector<int> second;
        //     ft::vector<int> third;

        //     first.assign (7,100);             // 7 ints with a value of 100

        //     std::vector<int>::iterator it;
        //     it = first.begin()+1;

        //     second.assign(it,first.end()-1); // the 5 central values of first

        //     int myints[] = {1776,7,4};
        //     third.assign (myints,myints+3);   // assigning from array.

        //     std::cout << "Size of first: " << int (first.size()) << '\n';
        //     std::cout << "Size of second: " << int (second.size()) << '\n';
        //     std::cout << "Size of third: " << int (third.size()) << '\n';
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
        {
            std::vector<int> myvector (3,100);
            std::vector<int>::iterator it;

            it = myvector.begin();
            it = myvector.insert ( it , 200 );

            myvector.insert (it,2,300);

            // "it" no longer valid, get a new one:
            // it = myvector.begin();

            // std::vector<int> anothervector (2,400);
            // myvector.insert (it+2,anothervector.begin(),anothervector.end());/////////////////NOT WORKING PROPERLY///////////////

            // int myarray [] = { 501,502,503 };
            // myvector.insert (myvector.begin(), myarray, myarray+3);

            std::cout << "myvector contains:";
            for (it=myvector.begin(); it<myvector.end(); it++)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
        {
            ft::vector<int> myvector (3,100);
            ft::vector<int>::iterator it;

            it = myvector.begin();
            it = myvector.insert ( it , 200 );


            myvector.insert (it,2,300);

            // // "it" no longer valid, get a new one:
            // it = myvector.begin();

            // ft::vector<int> anothervector (2,400);
            // myvector.insert (it+2,anothervector.begin(),anothervector.end());

            // int myarray [] = { 501,502,503 };
            // myvector.insert (myvector.begin(), myarray, myarray+3);

            std::cout << "myvector contains:";
            for (it=myvector.begin(); it<myvector.end(); it++)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
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

    }
}
