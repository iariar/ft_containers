#include "stack.hpp"
#include "vector.hpp"
#include <iostream>
#include <deque>
#include <stack>

#ifndef NS
#define NS std
#endif

int main()
{
	{
		std::deque<int> mydeque (3,100);          // deque with 3 elements
		NS::vector<int> myvector (2,200);        // vector with 2 elements

		NS::stack<int> first;                    // empty stack
		NS::stack<int, std::deque<int> > second (mydeque);         // stack initialized to copy of deque

		NS::stack<int,NS::vector<int> > third;  // empty stack using vector
		NS::stack<int,NS::vector<int> > fourth (myvector);

		std::cout << "size of first: " << first.size() << '\n';
		std::cout << "size of second: " << second.size() << '\n';
		std::cout << "size of third: " << third.size() << '\n';
		std::cout << "size of fourth: " << fourth.size() << '\n';
	}
	//empty()
	{
		std::stack<int> mystack;
		int sum (0);

		for (int i=1;i<=10;i++) mystack.push(i);

		while (!mystack.empty())
		{
			sum += mystack.top();
			mystack.pop();
		}

		std::cout << "total: " << sum << '\n';
	}
	//size()
	{
		NS::stack<int> myints;
		std::cout << "0. size: " << myints.size() << '\n';

		for (int i=0; i<5; i++) myints.push(i);
		std::cout << "1. size: " << myints.size() << '\n';

		myints.pop();
		std::cout << "2. size: " << myints.size() << '\n';
	}
	//top()
	{
		NS::stack<int> mystack;

		mystack.push(10);
		mystack.push(20);

		mystack.top() -= 5;

		std::cout << "mystack.top() is now " << mystack.top() << '\n';
	}
	//push
	{
		NS::stack<int> mystack;

		for (int i=0; i<5; ++i) mystack.push(i);

		std::cout << "Popping out elements...";
		while (!mystack.empty())
		{
			std::cout << ' ' << mystack.top();
			mystack.pop();
		}
		std::cout << '\n';
	}
}