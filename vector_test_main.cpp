#include "vector.hpp"
#include <iostream>
#include <vector>
#include <iterator>

// #if 0 //CREATE A REAL STL EXAMPLE
// 	#include <map>
// 	#include <stack>
// 	#include <vector>
// 	namespace ft = std;
// #else
// 	#include "map.hpp"
// 	#include "stack.hpp"
// 	#include "vector.hpp"
// #endif

#ifndef NS
#define NS ft
#endif

int main()
{

    // {
    //     NS::vector<int> vec;
    //     NS::vector<int>::iterator vec_it = vec.begin();
    //     NS::vector<int>::const_iterator vec_it2 = vec.begin();
    //     if (vec_it == vec_it2)
    //         std::cout << "ok" << std::endl;
    // }
    // {
    //     NS::pair <int,int> foo;
    //     NS::pair <int,int> bar;

    //     foo = NS::make_pair (10,20);
    //     bar = NS::make_pair (10.5,'A'); // ok: implicit conversion from pair<double,char>

    //     std::cout << "foo: " << foo.first << ", " << foo.second << '\n';
    //     std::cout << "bar: " << bar.first << ", " << bar.second << '\n';
    // }
	/////////////////////////
	// testing constructors//
	/////////////////////////
		{
			NS::vector<int> first;                                // empty vector of ints
			NS::vector<int> second (4,100);                       // four ints with value 100
			NS::vector<int> third (second.begin(),second.end());  // iterating through second
			NS::vector<int> fourth (third);                       // a copy of third

			// the iterator constructor can also be used to construct from arrays:
			int myints[] = {16,2,77,29};
			NS::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

			std::cout << "The contents of fifth are:";
			for (NS::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
			std::cout << "The contents of third are:";
			for (NS::vector<int>::iterator it = third.begin(); it != third.end(); ++it)
				std::cout << ' ' << *it;
			std::cout << '\n';
		}
    //     //////////////////////
    //     TESTING OPERATOR=/////
    //     //////////////////////
        {
            NS::vector<int> foo (3,0);
            NS::vector<int> bar (5,0);

            bar = foo;
            foo = NS::vector<int>();

            std::cout << "Size of foo: " << int(foo.size()) << '\n';
            std::cout << "Size of bar: " << int(bar.size()) << '\n';
        }
    //     //////////////////
    //     TESTING BEGIN()///
    //     //////////////////
        {  
            NS::vector<int> myvector;
            for (int i=1; i<=5; i++) myvector.push_back(i);
                std::cout << "myvector contains:";
            for (NS::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
    //     //////////////////
    //     TESTING END()/////
    //     //////////////////
        {
            NS::vector<int> myvector;
            for (int i=1; i<=5; i++) myvector.push_back(i);

            std::cout << "myvector contains:";
            for (NS::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
    //     //////////////////
    //     TESTING RBEGIN()//
    //     //////////////////
        {
            NS::vector<int> myvector (5);  // 5 default-constructed ints

            int i = 0;

            NS::vector<int>::reverse_iterator rit = myvector.rbegin();
            for (; rit!= myvector.rend(); ++rit)
                *rit = ++i;

            std::cout << "myvector contains:";
            for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
    //     //////////////////
    //     TESTING REND()////
    //     //////////////////
        {
            NS::vector<int> myvector (5);  // 5 default-constructed ints
            NS::vector<int>::reverse_iterator rit = myvector.rbegin();

            int i=0;
            for (rit = myvector.rbegin(); rit != myvector.rend(); ++rit)
                *rit = ++i;

            std::cout << "myvector contains:";
            for (NS::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
    //     //////////////////
    //     TESTING SIZE()////
    //     //////////////////
        {
            NS::vector<int> myints;
            std::cout << "0. size: " << myints.size() << '\n';

            for (int i=0; i<10; i++) myints.push_back(i);
            std::cout << "1. size: " << myints.size() << '\n';

            myints.insert (myints.end(),10,100);
            std::cout << "2. size: " << myints.size() << '\n';

            myints.pop_back();
            std::cout << "3. size: " << myints.size() << '\n';
        }
    //     //////////////////////
    //     TESTING MAX_SIZE()////
    //     /////////////////////
        {
            NS::vector<int> myvector;

            // set some content in the vector:
            for (int i=0; i<100; i++) myvector.push_back(i);

            std::cout << "size: " << myvector.size() << "\n";
            std::cout <<  "capacity: " << myvector.capacity() << "\n";             ///////////FIXED//////////
            std::cout << "max_size: " << myvector.max_size() << "\n";
        }
    //     /////////////////////
    //     TESTING RESIZE()/////
    //     /////////////////////
        {
            NS::vector<int> myvector;

            // set some initial content:
            for (int i=1;i<10;i++) myvector.push_back(i);

            myvector.resize(5);
            myvector.resize(8,100);
            myvector.resize(12);

            std::cout << "myvector contains:";
            for (size_t i=0; i < myvector.size();i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
    //     /////////////////////
    //     TESTING CAPACITY()///
    //     /////////////////////
        {
            NS::vector<int> myvector;

            // set some content in the vector:
            for (int i=0; i<100; i++) myvector.push_back(i);

            std::cout << "size: " << (int) myvector.size() << '\n';
            std::cout << "capacity: " << (int) myvector.capacity() << '\n';//FIXED
            std::cout << "max_size: " << myvector.max_size() << '\n';
        }
    //     /////////////////////
    //     TESTING EMPTY()//////
    //     /////////////////////
        {
            NS::vector<int> myvector;
            int sum (0);

            for (int i=1;i<=10;i++) myvector.push_back(i);

            while (!myvector.empty())
            {
                sum += myvector.back();
                myvector.pop_back();
            }

            std::cout << "total: " << sum << '\n';
        }
    //     /////////////////////
    //     TESTING RESERVE()////
    //     /////////////////////
        {
            NS::vector<int>::size_type sz;

            NS::vector<int> foo;
            sz = foo.capacity();
            std::cout << "making foo grow:\n";
            for (int i=0; i<100; ++i) {
                foo.push_back(i);
                if (sz!=foo.capacity()) {
                sz = foo.capacity();
                std::cout << "capacity changed: " << sz << '\n';
                }
            }

            NS::vector<int> bar;
            sz = bar.capacity();
            bar.reserve(100);   // this is the only difference with foo above
            std::cout << "making bar grow:\n";
            for (int i=0; i<100; ++i) {
                bar.push_back(i);
                if (sz!=bar.capacity()) {
                sz = bar.capacity();
                std::cout << "capacity changed: " << sz << '\n';
                }
            }
        }
    //     /////////////////////
    //     TESTING OERATOR[]////
    //     /////////////////////
        {
            NS::vector<int> myvector (10);   // 10 zero-initialized elements

            NS::vector<int>::size_type sz = myvector.size();

            // assign some values:
            for (size_t i = 0; i < sz; i++) myvector[i]=i;

            std::cout << "myvector contains:";
            for (size_t i = 0; i<sz; i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';

        }
    //     /////////////////////
    //     TESTING AT///////////
    //     /////////////////////
        {
            NS::vector<int> myvector (10);   // 10 zero-initialized ints

            // assign some values:
            for (size_t i=0; i<myvector.size(); i++)
                myvector.at(i)=i;

            std::cout << "myvector contains:";
            for (size_t i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector.at(i);
            std::cout << '\n';
        }
    //     /////////////////////
    //     TESTING FRONT////////
    //     /////////////////////
        {
            NS::vector<int> myvector;

            myvector.push_back(78);
            myvector.push_back(16);

            // now front equals 78, and back 16

            myvector.front() -= myvector.back();

            std::cout << "myvector.front() is now " << myvector.front() << '\n';
        }
    //     /////////////////////
    //     TESTING  BACK////////
    //     /////////////////////
        {
            NS::vector<int> myvector;

            myvector.push_back(10);

            while (myvector.back() != 0)
            {
                myvector.push_back ( myvector.back() -1 );
            }

            std::cout << "myvector contains:";
            for (size_t i=0; i<myvector.size() ; i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
    //     /////////////////////
    //     TESTING  ASSIGN//////
    //     ///////////////////////
        {
            NS::vector<int> first;
            NS::vector<int> second;
            NS::vector<int> third;

            first.assign (7,100);             // 7 ints with a value of 100

            NS::vector<int>::iterator it;
            it = first.begin() + 1;

            second.assign (it, first.end() - 1); // the 5 central values of first

            int myints[] = {1776,7,4};
            third.assign (myints,myints+3);   // assigning from array.

            std::cout << "Size of first: " << int (first.size()) << '\n';
            std::cout << "Size of second: " << int (second.size()) << '\n';
            std::cout << "Size of third: " << int (third.size()) << '\n';/////////////////////FIXEDDDDD/////////////////
        }
    //     /////////////////////
    //     TESTING PUSH_BACK////
    //     /////////////////////
        // {
        //    NS::vector<int> myvector;
        //     int myint;

        //     std::cout << "Please enter some integers (enter 0 to end):\n";

        //     do {
        //         std::cin >> myint;
        //         myvector.push_back (myint);
        //     } while (myint);

        //     std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";
        // }
    //     /////////////////////
    //     TESTING POP_BACK/////
    //     /////////////////////
        {
            NS::vector<int> myvector;
            int sum (0);
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            while (!myvector.empty())
            {
                sum+=myvector.back();
                myvector.pop_back();
            }

            std::cout << "The elements of myvector add up to " << sum << '\n';
        }
    //     /////////////////////
    //     TESTING INSERT///////
    //     /////////////////////
            {
                NS::vector<int> myvector (3,100);
                NS::vector<int>::iterator it;

                it = myvector.begin();
                it = myvector.insert ( it , 200 );

                std::cout << "my capacity = " << myvector.capacity() << std::endl;
                myvector.insert (it,10,300);

                // "it" no longer valid, get a new one:
                it = myvector.begin();

                NS::vector<int> anothervector (2,400);
                
                std::cout << "my capacity = " << myvector.capacity() << std::endl;
                myvector.insert (it+1,anothervector.begin(),anothervector.end());

                std::cout << "my capacity = " << myvector.capacity() << std::endl;
                int myarray [] = { 501,502,503 };
                myvector.insert (myvector.begin(), myarray, myarray+3);

                std::cout << "my capacity = " << myvector.capacity() << std::endl;
                std::cout << "myvector contains:";
                for (it=myvector.begin(); it < myvector.end(); it++)
                    std::cout << ' ' << *it;
                std::cout << '\n';
            }
        /////////////////////
        // TESTING ERASE////////
        ///////////////////// 
        {
            NS::vector<int> myvector;

            // set some values (from 1 to 10)
            for (int i=1; i<=10; i++) myvector.push_back(i);

            // erase the 6th element
            NS::vector<int>::iterator ite = myvector.begin()+5;
            myvector.erase (ite);

            // erase the first 3 elements:
            myvector.erase (myvector.begin(),myvector.begin()+3);

            std::cout << "myvector contains:";
            for (size_t i=0; i<myvector.size(); ++i)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        /////////////////////
        // TESTING SWAP/////////
        /////////////////////
        {
            NS::vector<int> foo (3,100);   // three ints with a value of 100//////////////////fixed///////////////////
            NS::vector<int> bar (5,200);   // five ints with a value of 200

            foo.swap(bar);

            std::cout << "foo contains:";
            for (size_t i=0; i<foo.size(); i++)
                std::cout << ' ' << foo[i];
            std::cout << '\n';

            std::cout << "bar contains:";
            for (size_t i=0; i<bar.size(); i++)
                std::cout << ' ' << bar[i];
            std::cout << '\n';
        }
        ////////////////////////
        // TESTING PCLEAR//////////
        ///////////////////////
        {
            NS::vector<int> myvector;
            myvector.push_back (100);
            myvector.push_back (200);
            myvector.push_back (300);

            std::cout << "myvector contains:";
            for (size_t i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';

            myvector.clear();
            myvector.push_back (1101);
            myvector.push_back (2202);

            std::cout << "myvector contains:";
            for (size_t i=0; i<myvector.size(); i++)
                std::cout << ' ' << myvector[i];
            std::cout << '\n';
        }
        ////////////////////////
        // TESTING GET_ALLOCATOR//////////
        ///////////////////////
        {
            std::vector<int> myvector;
            int * p;
            unsigned int i;

            // allocate an array with space for 5 elements using vector's allocator:
            p = myvector.get_allocator().allocate(5);

            // construct values in-place on the array:
            for (i=0; i<5; i++) myvector.get_allocator().construct(&p[i],i);

            std::cout << "The allocated array contains:";
            for (i=0; i<5; i++) std::cout << ' ' << p[i];
            std::cout << '\n';

            // destroy and deallocate:
            for (i=0; i<5; i++) myvector.get_allocator().destroy(&p[i]);
            myvector.get_allocator().deallocate(p,5);
        }
        //////////////////////////
        //RATIONAL_OPERATORS///////
        //////////////////////////
        {
            NS::vector<int> foo (3,100);   // three ints with a value of 100
            NS::vector<int> bar (2,200);   // two ints with a value of 200

            if (foo==bar) std::cout << "foo and bar are equal\n";
            if (foo!=bar) std::cout << "foo and bar are not equal\n";
            if (foo< bar) std::cout << "foo is less than bar\n";
            if (foo> bar) std::cout << "foo is greater than bar\n";
            if (foo<=bar) std::cout << "foo is less than or equal to bar\n";
            if (foo>=bar) std::cout << "foo is greater than or equal to bar\n";
        }
        //////////////
        ///SWAP///////
        //////////////
        {
            // unsigned int i;
            NS::vector<int> foo (3,100);   // three ints with a value of 100
            NS::vector<int> bar (5,200);   // five ints with a value of 200

            foo.swap(bar);

            std::cout << "foo contains:";
            for (NS::vector<int>::iterator it = foo.begin(); it!=foo.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';

            std::cout << "bar contains:";
            for (NS::vector<int>::iterator it = bar.begin(); it!=bar.end(); ++it)
                std::cout << ' ' << *it;
            std::cout << '\n';
        }
}

