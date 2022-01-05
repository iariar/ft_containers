#ifndef _PAIR_H__
#define _PAIR_H__

namespace ft
{
	template <class T1, class T2>
	struct pair
	{
		public:
			typedef T1 first_type; 
			typedef T2 second_type;
			pair() : first() , second()
			{
				return; 
			}
			template <class U, class V>
			pair (const pair<U,V>& pr) : first(pr.first)
			{
				// this->first = pr.first;
				this->second = pr.second;
			}
			pair (const first_type& a, const second_type& b) : first(a)
			{
				// first = a;
				second = b;
			}
			pair& operator= (const pair& pr)
			{
				this->first = pr.first;
				this->second = pr.second;
				return (*this);
			}
			first_type first;
			second_type second;
	};
	template <class T1, class T2>
	bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first == rhs.first && lhs.second == rhs.second);
	}
	template <class T1, class T2>
	bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first != rhs.first && lhs.second != rhs.second);
	}
	template <class T1, class T2>
	bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{        
		return (lhs.first < rhs.first && lhs.second < rhs.second);
	}
	template <class T1, class T2>
	bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first <= rhs.first && lhs.second <= rhs.second);
	}
	template <class T1, class T2>
	bool operator> (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first > rhs.first && lhs.second > rhs.second);
	}
	template <class T1, class T2>
	bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
	{
		return (lhs.first >= rhs.first && lhs.second >= rhs.second);
	}
	template <class T1,class T2>
	pair<T1,T2> make_pair (T1 x, T2 y)
	{
		return ( pair<T1,T2>(x,y) );
	};
}

#endif
