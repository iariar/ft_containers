#ifndef _STACk_H__
#define _STACk_H__

#include "vector.hpp"

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
		public:
			typedef Container	container_type;
			typedef T			value_type;
			typedef size_t		size_type;
			template <class type, class Con>
  			friend bool operator== (const stack<type,Con>& lhs, const stack<type,Con>& rhs);
			template <class type, class Con>
  			friend bool operator!= (const stack<type,Con>& lhs, const stack<type,Con>& rhs);
			template <class type, class Con>
  			friend bool operator< (const stack<type,Con>& lhs, const stack<type,Con>& rhs);
			template <class type, class Con>
  			friend bool operator<= (const stack<type,Con>& lhs, const stack<type,Con>& rhs);
			template <class type, class Con>
  			friend bool operator> (const stack<type,Con>& lhs, const stack<type,Con>& rhs);
			template <class type, class Con>
  			friend bool operator>= (const stack<type,Con>& lhs, const stack<type,Con>& rhs);
			explicit stack (const container_type& ctnr = container_type()) : c(ctnr) {};
			bool empty() const
			{
				return (c.empty());
			}
			size_type size() const
			{
				return (c.size());
			}
			value_type& top()
			{
				return (c.back());
			}
			const value_type& top() const
			{
				return (c.back());
			}
			void push (const value_type& val)
			{
				c.push_back(val);
			}
			void pop()
			{
				c.pop_back();
			}
		protected:
			container_type c;
	};
	template <class T, class Container>
  	bool operator== (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c == rhs.c);
	}
	template <class T, class Container>
  	bool operator!= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c != rhs.c);
	}
	template <class T, class Container>
  	bool operator< (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c < rhs.c);
	}
	template <class T, class Container>
  	bool operator<= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c <= rhs.c);
	}
	template <class T, class Container>
  	bool operator> (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c > rhs.c);
	}
	template <class T, class Container>
  	bool operator>= (const stack<T,Container>& lhs, const stack<T,Container>& rhs)
	{
		return (lhs.c >= rhs.c);
	}
	
}

#endif