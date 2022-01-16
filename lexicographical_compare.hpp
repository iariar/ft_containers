#ifndef _LEXICOGRAPHICAL_COMPARE__
#define _LEXICOGRAPHICAL_COMPARE__

namespace ft
{
	///////////////////////////////
	// lexicographical_compare()///
	///////////////////////////////
	template <class InputIterator1, class InputIterator2>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2)
	{
		while (first1 != last1)
		{
			if (*first1 < *first2)
				return (1);
			else if (first2 == last2 || *first1 > *first2)
				return(0);
			first1++;
			first2++;   
		}
		return(first1 != last1);
	}
	template <class InputIterator1, class InputIterator2, class Compare>
	bool lexicographical_compare (InputIterator1 first1, InputIterator1 last1, InputIterator2 first2, InputIterator2 last2, Compare comp)
	{
		while (first1 != last1)
		{
			if (comp(*first1, *first2))
				return (1);
			else if (first2 == last2 || !comp(*first1, *first2))
				return(0);
			first1++;
			first2++;   
		}
		return(first1 != last1);
	}
}

#endif