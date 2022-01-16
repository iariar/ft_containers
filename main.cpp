#include "vector.hpp"
#include "map.hpp"
#include <map>
#include "stack.hpp"
#include "lexicographical_compare.hpp"
#include <stack>

struct t
    {
        int a;
    };
bool mycomp (char c1, char c2)
{ return std::tolower(c1)<std::tolower(c2); }

// bool fncomp (char lhs, char rhs) {return lhs<rhs;}

// struct classcomp {
//   bool operator() (const char& lhs, const char& rhs) const
//   {return lhs<rhs;}
// };

// bool mycomp (char c1, char c2)
// { return std::tolower(c1)<std::tolower(c2); }


#ifndef NS
#define NS ft
#endif

int main ()
{
    {
        NS::map<int, int> mp;
        mp[1] = 10;
        mp[-1] = 70;
        mp[5] = 30;
        for (NS::map<int, int>::iterator it = mp.begin(); it != mp.end(); it++)
        {
            std::cout << it->first << std::endl;
        }
        
    }
    {
        NS::map<std::string, int> mapOfWordCount;
    // Insert Element in map
        mapOfWordCount.insert(NS::pair<std::string, int>("first", 1));
        mapOfWordCount.insert(NS::pair<std::string, int>("second", 2));
        mapOfWordCount.insert(NS::pair<std::string, int>("third", 3));
        mapOfWordCount.insert(NS::pair<std::string, int>("third", 4));
        mapOfWordCount.insert(NS::pair<std::string, int>("third", 5));
        // Create a map iterator and point to beginning of map
        NS::map<std::string, int>::iterator it = mapOfWordCount.begin();
        // Iterate over the map using Iterator till end.
        while (it != mapOfWordCount.end())
        {
            // Accessing KEY from element pointed by it.
            std::string word = it->first;
            // Accessing VALUE from element pointed by it.
            int count = it->second;
            std::cout << word << " :: " << count << std::endl;
            // Increment the Iterator to point to next entry
            it++;
        }
    }
    {
        NS::map<int, int> gquiz1;
  
        // insert elements in random order
        gquiz1.insert(NS::pair<int, int>(1, 40));
        gquiz1.insert(NS::pair<int, int>(2, 30));
        gquiz1.insert(NS::pair<int, int>(3, 60));
        gquiz1.insert(NS::pair<int, int>(4, 20));
        gquiz1.insert(NS::pair<int, int>(5, 50));
        gquiz1.insert(NS::pair<int, int>(6, 50));
        gquiz1.insert(NS::pair<int, int>(7, 10));
    
        // printing map gquiz1
        NS::map<int, int>::iterator itr;
        std::cout << "\nThe map gquiz1 is : \n";
        std::cout << "\tKEY\tELEMENT\n";
        for (itr = gquiz1.begin(); itr != gquiz1.end(); ++itr) {
            std::cout << '\t' << itr->first
                << '\t' << itr->second << '\n';
        }
        std::cout << std::endl;
    
        // assigning the elements from gquiz1 to gquiz2
        NS::map<int, int> gquiz2(gquiz1.begin(), gquiz1.end());
    
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
    {
        NS::map<char,int> first;

        first['a']=10;
        first['b']=30;
        first['c']=50;
        first['d']=70;

        NS::map<char,int> second (first.begin(),first.end());

        NS::map<char,int> third (second);
    }
    //////////////////////
    //OPERATOR=///////////
    //////////////////////
    {
        NS::map<char,int> first;
        NS::map<char,int> second;

        first['x']=8;
        first['y']=16;
        first['z']=32;

        second = first;                // second now contains 3 ints
        first = NS::map<char,int>();  // and first is now empty

        std::cout << second['x'] << std::endl;
        std::cout << second['y'] << std::endl;
        std::cout << second['z'] << std::endl;
        std::cout << "Size of first: " << first.size() << '\n';
        std::cout << "Size of second: " << second.size() << '\n';
    }
    //////////////////////
    //BEGIN()/////////////
    //////////////////////
    {
        NS::map<char,int> mymap;
        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        // show content:
        for (NS::map<char,int>::iterator it = mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first<< " => " << it->second << '\n';
    }
    //////////////////////
    ////END()/////////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        mymap['b'] = 100;
        mymap['a'] = 200;
        mymap['c'] = 300;

        // show content:
        for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    //////////////////////
    //RBEGIN()////////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        NS::map<char,int>::reverse_iterator rit;
        for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    //////////////////////
    //REND()//////////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        mymap['x'] = 100;
        mymap['y'] = 200;
        mymap['z'] = 300;

        // show content:
        NS::map<char,int>::reverse_iterator rit;
        for (rit=mymap.rbegin(); rit!=mymap.rend(); ++rit)
            std::cout << rit->first << " => " << rit->second << '\n';
    }
    //////////////////////
    //EMPTY()/////////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        while (!mymap.empty())
        {
            std::cout << mymap.begin()->first << " => " << mymap.begin()->second << '\n';
            mymap.erase(mymap.begin());
        }
    }
    //////////////////////
    //SIZE()//////////////
    //////////////////////
    {
        NS::map<char,int> mymap;
        mymap['a']=101;
        mymap['b']=202;
        mymap['c']=302;

        std::cout << "mymap.size() is " << mymap.size() << '\n';
    }
    //////////////////////
    //max_size()//////////
    //////////////////////
    {
        int i;
        NS::map<int,int> mymap;

        if (mymap.max_size()>1000)
        {
            for (i=0; i<1000; i++) mymap[i]=0;
            std::cout << "The map contains 1000 elements.\n";
            std::cout << mymap.max_size() << std::endl;
        }
        else std::cout << "The map could not hold 1000 elements.\n";
    }
    //////////////////////
    //OPERATOR[]//////////
    //////////////////////
    {
        NS::map<char,std::string> mymap;

        mymap['a']="an element";
        mymap['b']="another element";
        mymap['c']=mymap['b'];

        std::cout << "mymap['a'] is " << mymap['a'] << '\n';
        std::cout << "mymap['b'] is " << mymap['b'] << '\n';
        std::cout << "mymap['c'] is " << mymap['c'] << '\n';
        std::cout << "mymap['d'] is " << mymap['d'] << '\n';

        std::cout << "mymap now contains " << mymap.size() << " elements.\n";
    }
    //////////////////////
    //INSERT()////////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        // first insert function version (single parameter):
        mymap.insert ( NS::pair<char,int>('a',100) );
        mymap.insert ( NS::pair<char,int>('z',200) );

        NS::pair<NS::map<char,int>::iterator,bool> ret;
        ret = mymap.insert ( NS::pair<char,int>('z',500) );
        if (ret.second==false) {
            std::cout << "element 'z' already existed";
            std::cout << " with a value of " << ret.first->second << '\n';
        }

        // second insert function version (with hint position):
        NS::map<char,int>::iterator it = mymap.begin();
        mymap.insert (it, NS::pair<char,int>('b',300));  // max efficiency inserting
        mymap.insert (it, NS::pair<char,int>('c',400));  // no max efficiency inserting

        // third insert function version (range insertion):
        NS::map<char,int> anothermap;
        anothermap.insert(mymap.begin(),mymap.find('c'));

        // showing contents:
        std::cout << "mymap contains:\n";
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        std::cout << "anothermap contains:\n";
        for (it=anothermap.begin(); it!=anothermap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        NS::map<int, int> mp;
    
        // insert elements in random order
        mp.insert(NS::make_pair( 2, 30 ));
        mp.insert(NS::make_pair( 1, 40 ));
        mp.insert(NS::make_pair( 3, 60 ));
    
        // does not inserts key 2 with element 20
        mp.insert(NS::make_pair( 2, 30 ));
        mp.insert(NS::make_pair( 5, 50 ));
    
        // prints the elements
        std::cout << "KEY\tELEMENT\n";
        for (NS::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            std::cout << itr->first
                << '\t' << itr->second << '\n';
        }
    }
    //////////////////////
    //ERASE()/////////////
    //////////////////////
    {
        NS::map<char,int> mymap;
        NS::map<char,int>::iterator it;

        mymap['a']=10;
        mymap['b']=20;                                              ////ERASE FUCKED UP///////
        mymap['c']=30;
        mymap['d']=40;
        mymap['e']=50;
        mymap['f']=60;

        it = mymap.find('b');
        mymap.erase (it);                   // erasing by iterator

        mymap.erase ('c');                  // erasing by key

        it=mymap.find ('e');
        mymap.erase ( it, mymap.end() );    // erasing by range
        // mymap['c']=30;
        // mymap['e']=50;
        // show content:
        for (it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    {
        NS::map<int, int> mp;
    
        // insert elements in random order
        mp.insert(NS::make_pair( 2, 30 ));
        mp.insert(NS::make_pair( 1, 40 ));
        mp.insert(NS::make_pair( 3, 60 ));
        mp.insert(NS::make_pair( 5, 50 ));
    
        // prints the elements
        std::cout << "The map before using erase() is : \n";
        std::cout << "KEY\tELEMENT\n";
        for (NS::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            std::cout << itr->first
                << '\t' << itr->second << '\n';
        }
    
        // function to erase given keys
        mp.erase(1);
        mp.erase(2);
    
        // prints the elements
        std::cout << "\nThe map after applying erase() is : \n";
        std::cout << "KEY\tELEMENT\n";
        for (NS::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            std::cout << itr->first
                << '\t' << itr->second << '\n';
        }
    }
    {
        NS::map<int, int> mp;
    // insert elements in random order
        mp.insert(NS::make_pair( 2, 30 ));
        mp.insert(NS::make_pair( 1, 40 ));
        mp.insert(NS::make_pair( 3, 60 ));
        mp.insert(NS::make_pair( 5, 50 ));
    
        // prints the elements
        std::cout << "The map before using erase() is : \n";
        std::cout << "KEY\tELEMENT\n";
        for (NS::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            std::cout << itr->first
                << '\t' << itr->second << '\n';
        }
    
        // function to erase given position
        NS::map<int, int>::iterator it = mp.find(2);
        mp.erase(it);
    
        NS::map<int, int>::iterator it1 = mp.find(5);
        mp.erase(it1);
    
        // prints the elements
        std::cout << "\nThe map after applying erase() is : \n";
        std::cout << "KEY\tELEMENT\n";
        for (NS::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            std::cout << itr->first
                << '\t' << itr->second << '\n';
        }
    }
    {
        NS::map<int, int> mp;
        // insert elements in random order
        mp.insert(NS::make_pair( 2, 30 ));
        mp.insert(NS::make_pair( 1, 40 ));
        mp.insert(NS::make_pair( 3, 60 ));
        mp.insert(NS::make_pair( 2, 20 ));
        mp.insert(NS::make_pair( 5, 50 ));
    
        // prints the elements
        std::cout << "The map before using erase() is : \n";
        std::cout << "KEY\tELEMENT\n";
        for (NS::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            std::cout << itr->first
                << '\t' << itr->second << '\n';
        }
    
        // function to erase in a given range
        // find() returns the iterator reference to
        // the position where the element is
        NS::map<int, int>::iterator it1 = mp.find(2);
        NS::map<int, int>::iterator it2 = mp.find(5);
        mp.erase(it1, it2);
    
        // prints the elements
        std::cout << "\nThe map after applying erase() is : \n";
        std::cout << "KEY\tELEMENT\n";
        for (NS::map<int, int>::iterator itr = mp.begin(); itr != mp.end(); ++itr) {
            std::cout << itr->first
                << '\t' << itr->second << '\n';
        }
    }
    //////////////////////
    //SWAP()//////////////
    //////////////////////
    {
        NS::map<char,int> foo,bar;

        foo['x']=100;
        foo['y']=200;

        bar['a']=11;
        bar['b']=22;
        bar['c']=33;

        foo.swap(bar);

        std::cout << "foo contains:\n";
        for (NS::map<char,int>::iterator it=foo.begin(); it!=foo.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "Foo size = " << foo.size() << std::endl;

        std::cout << "bar contains:\n";
        for (NS::map<char,int>::iterator it=bar.begin(); it!=bar.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
        std::cout << "Bar size = " << bar.size() << std::endl;
    }
    //////////////////////
    //CLEAR()/////////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        mymap['x']=100;
        mymap['y']=200;
        mymap['z']=300;

        std::cout << "mymap contains:\n";
        for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';

        mymap.clear();
        mymap['a']=1101;                //SEGF WHEN U TRY THE LOOP WITHOUT ADDING ELEMENTS/////
        mymap['b']=2202;

        std::cout << "mymap contains:\n";
        for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    //////////////////////
    //key_comp////////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        NS::map<char,int>::key_compare mycomp = mymap.key_comp();

        mymap['a']=100;
        mymap['b']=200;
        mymap['c']=300;

        std::cout << "mymap contains:\n";

        char highest = mymap.rbegin()->first;     // key value of last element

        NS::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mycomp((*it++).first, highest) );

        std::cout << '\n';
    }
    //////////////////////
    //VALUE_COMPARE///////
    //////////////////////
    {
        NS::map<char,int> mymap;

        mymap['x']=1001;
        mymap['y']=2002;
        mymap['z']=3003;

        std::cout << "mymap contains:\n";

        NS::pair<char,int> highest = *mymap.rbegin();          // last element

        NS::map<char,int>::iterator it = mymap.begin();
        do {
            std::cout << it->first << " => " << it->second << '\n';
        } while ( mymap.value_comp()(*it++, highest) );
    }
    //////////////////////
    //FIND////////////////
    //////////////////////
    {
        NS::map<char,int> mymap;
        NS::map<char,int>::iterator it;

        mymap['a']=50;
        mymap['b']=100;
        mymap['c']=150;
        mymap['d']=200;

        it = mymap.find('b');
        if (it != mymap.end())
            mymap.erase (it);

        // print content:
        std::cout << "elements in mymap:" << '\n';
        std::cout << "a => " << mymap.find('a')->second << '\n';
        std::cout << "c => " << mymap.find('c')->second << '\n';
        std::cout << "d => " << mymap.find('d')->second << '\n';
    }
    //////////////////////
    //COUNT///////////////
    //////////////////////
    {
        NS::map<char,int> mymap;
        char c;

        mymap ['a']=101;
        mymap ['c']=202;
        mymap ['f']=303;

        for (c='a'; c<'h'; c++)
        {
            std::cout << c;
            if (mymap.count(c)>0)
            std::cout << " is an element of mymap.\n";
            else 
            std::cout << " is not an element of mymap.\n";
        }
    }
    //////////////////////
    //LOWER_BOUND/////////
    //////////////////////
    {
        NS::map<char,int> mymap;
        NS::map<char,int>::iterator itlow,itup;

        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;

        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        mymap.erase(itlow,itup);        // erases [itlow,itup)

        // print content:
        for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    //////////////////////
    //UPPER_BOUND/////////
    //////////////////////
    {
        NS::map<char,int> mymap;
        NS::map<char,int>::iterator itlow,itup;

        mymap['a']=20;
        mymap['b']=40;
        mymap['c']=60;
        mymap['d']=80;
        mymap['e']=100;

        itlow=mymap.lower_bound ('b');  // itlow points to b
        itup=mymap.upper_bound ('d');   // itup points to e (not d!)

        mymap.erase(itlow,itup);        // erases [itlow,itup)

        // print content:
        for (NS::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
            std::cout << it->first << " => " << it->second << '\n';
    }
    //////////////////////
    //EQUAL_RANGE/////////
    //////////////////////
    {
        NS::map<char,int> mymap;

        mymap['a']=10;
        mymap['b']=20;
        mymap['c']=30;

        NS::pair<NS::map<char,int>::iterator,NS::map<char,int>::iterator> ret;
        ret = mymap.equal_range('b');

        std::cout << "lower bound points to: ";
        std::cout << ret.first->first << " => " << ret.first->second << '\n';

        std::cout << "upper bound points to: ";
        std::cout << ret.second->first << " => " << ret.second->second << '\n';
    } 
    {
        NS::map<int, int> mp;
 
        // insert elements in random order
        mp.insert(NS::make_pair ( 4, 30 ));
        mp.insert(NS::make_pair ( 1, 40 ));
        mp.insert(NS::make_pair ( 6, 60 ));
    
        NS::pair<NS::map<int, int>::iterator, NS::map<int, int>::iterator> it;
    
        // iterator of pairs
        it = mp.equal_range(1);
        std::cout << "The lower bound is " << it.first->first << " => " << it.first->second;
    
        std::cout << "\nThe upper bound is " << it.second->first << " => " << it.second->second; std::cout << std::endl;
    } 
}