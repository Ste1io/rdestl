#include <UnitTest++/src/UnitTest++.h>
#include "rdestl/algorithm.h"
#include "rdestl/functional.h"
#include "rdestl/list.h"

namespace
{
	TEST(LowerBound)
	{
		const int array [] = { 1, 4, 9, 16, 25, 36 }; 
		const int* it = rde::lower_bound(&array[0], &array[6], 11, rde::less<int>());
		CHECK_EQUAL(16, *it);
		const int* it2 = &array[0];
		rde::less<int> pred;
		while (it2 != it)
		{
			CHECK(pred(*it2, *it));
			++it2;
		}
	}
	TEST(LowerBoundInputIter)
	{
		const int array [] = { 1, 4, 9, 16, 25, 36 }; 
		rde::list<int> lst(&array[0], &array[6]);
		rde::list<int>::iterator it = rde::lower_bound(lst.begin(), lst.end(), 11, rde::less<int>());
		CHECK_EQUAL(16, *it);
		rde::list<int>::iterator it2 = lst.begin();
		rde::less<int> pred;
		while (it2 != it)
		{
			CHECK(pred(*it2, *it));
			++it2;
		}
	}
	TEST(UpperBound)
	{
		const int array[] = { 1, 2, 3, 3, 3, 5, 8 };
		const int N = sizeof(array) / sizeof(int);
		const int* it = rde::upper_bound(&array[0], &array[N], 5, rde::less<int>());
		CHECK_EQUAL(8, *it);
		it = rde::upper_bound(&array[0], &array[N], 6, rde::less<int>());
		CHECK_EQUAL(8, *it);
		it = rde::upper_bound(&array[0], &array[N], 2, rde::less<int>());
		const int* it2 = &array[0];
		rde::less<int> pred;
		while (it2 != it)
		{
			CHECK(!pred(2, *it2));
			++it2;
		}
	}
	TEST(Find)
	{
		const int array [] = { 1, 4, 9, 16, 25, 36 }; 
		const int* it = rde::find(&array[0], &array[6], 16);
		CHECK_EQUAL(it, &array[3]);
		CHECK_EQUAL(16, *it);
	}
	TEST(FindIf)
	{
		const int array [] = { 1, 4, 9, 16, 25, 36 }; 
		const int* it = rde::find(&array[0], &array[6], 16);
		CHECK_EQUAL(it, &array[3]);
		CHECK_EQUAL(16, *it);
	}
}