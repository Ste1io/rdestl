#ifndef RDESTL_UTILITY_H
#define RDESTL_UTILITY_H

#include <new>
#include <utility> //for std::move, std::forward
#include "rdestl_common.h"
#include "int_to_type.h"

namespace rde
{
namespace internal
{
	template<typename T>
	void copy_n(const T* first, size_t n, T* result, int_to_type<false>)
	{
		const T* last = first + n;
		//while (first != last)
		//	*result++ = *first++;
		switch (n & 0x3)
		{
		case 0:
			while (first != last)
			{
				*result++ = *first++;
		case 3:	*result++ = *first++;
		case 2: *result++ = *first++;
		case 1: *result++ = *first++;
			}
		}
	}
	template<typename T>
	void copy_n(const T* first, size_t n, T* result, int_to_type<true>)
	{
		RDE_ASSERT(result >= first + n || result < first);
		Sys::MemCpy(result, first, n * sizeof(T));
	}

	template<typename T>
	void copy(const T* first, const T* last, T* result, int_to_type<false>)
	{
		// Local variable helps MSVC keep stuff in registers
		T* localResult = result;
		while (first != last)
			*localResult++ = *first++;
	}
	template<typename T>
	void copy(const T* first, const T* last, T* result, int_to_type<true>)
	{
		const size_t n = reinterpret_cast<const char*>(last) - reinterpret_cast<const char*>(first);
		Sys::MemCpy(result, first, n);
	}

	template<typename T> RDE_FORCEINLINE
	void move_n(const T* from, size_t n, T* result, int_to_type<false>)
	{
		for (size_t i = n - 1; i != size_t(-1); --i)
			result[i] = from[i];
	}
	template<typename T> RDE_FORCEINLINE
	void move_n(const T* first, size_t n, T* result, int_to_type<true>)
	{
		Sys::MemMove(result, first, n * sizeof(T));
	}

	template<typename T> RDE_FORCEINLINE
	void move(const T* first, const T* last, T* result, int_to_type<false>)
	{
		result += (last - first);
		while (--last >= first)
			*(--result) = *last;
	}
	template<typename T> RDE_FORCEINLINE
	void move(const T* first, const T* last, T* result, int_to_type<true>)
	{
		// Meh, MSVC does pretty stupid things here.
		//memmove(result, first, (last - first) * sizeof(T));
		const size_t n = reinterpret_cast<uintptr_t>(last) - reinterpret_cast<uintptr_t>(first);
		//const size_t n = (last - first) * sizeof(T);
		Sys::MemMove(result, first, n);
	}

	template<typename T>
	void copy_construct_n(const T* first, size_t n, T* result, int_to_type<false>)
	{
		for (size_t i = 0; i < n; ++i)
			new (result + i) T(first[i]);
	}
	template<typename T>
	void copy_construct_n(const T* first, size_t n, T* result, int_to_type<true>)
	{
		RDE_ASSERT(result >= first + n || result < first);
		Sys::MemCpy(result, first, n * sizeof(T));
	}

	template<typename T>
	void move_construct_n(T* first, size_t n, T* result, int_to_type<false>)
	{
		for (size_t i = 0; i < n; ++i)
			new (result + i) T(std::move(first[i]));
	}

	template<typename T>
	void move_construct_n(T* first, size_t n, T* result, int_to_type<true>)
	{
		RDE_ASSERT(result >= first + n || result < first);
		Sys::MemCpy(result, first, n * sizeof(T));
	}

	template<typename T>
	void destruct_n(T* first, size_t n, int_to_type<false>)
	{
		// For unknown reason MSVC cant see reference to first here...
		(void)sizeof(first);
		(void)first;
		for (size_t i = 0; i < n; ++i)
			(first + i)->~T();
	}
	template<typename T> RDE_FORCEINLINE
	void destruct_n(T*, size_t, int_to_type<true>)
	{
		// Nothing to do, no destructor needed.
	}

	template<typename T>
	void destruct(T* mem, int_to_type<false>)
	{
		sizeof(mem);
		mem->~T();
	}
	template<typename T> RDE_FORCEINLINE
	void destruct(T*, int_to_type<true>)
	{
		// Nothing to do, no destructor needed.
	}

	template<typename T>
	void construct(T* mem, int_to_type<false>)
	{
		new (mem) T();
	}
	template<typename T> RDE_FORCEINLINE
	void construct(T*, int_to_type<true>)
	{
		// Nothing to do
	}

	template<typename T> RDE_FORCEINLINE
	void copy_construct(T* mem, const T& orig, int_to_type<false>)
	{
		new (mem) T(orig);
	}
	template<typename T> RDE_FORCEINLINE
	void copy_construct(T* mem, const T& orig, int_to_type<true>)
	{
		mem[0] = orig;
	}

	template<typename T>
	void construct_n(T* to, size_t count, int_to_type<false>)
	{
		sizeof(to);
		for (size_t i = 0; i < count; ++i)
			new (to + i) T();
	}
	template<typename T> inline
	void construct_n(T*, size_t, int_to_type<true>)
	{
		// trivial ctor, nothing to do.
	}

	// Tests if all elements in range are ordered according to pred.
	template<class TIter, class TPred>
	void test_ordering(TIter first, TIter last, const TPred& pred)
	{
	#if RDE_DEBUG
		if (first != last)
		{
			TIter next = first;
			if (++next != last)
			{
				RDE_ASSERT(pred(*first, *next));
				first = next;
			}
		}
	#else
		sizeof(first); sizeof(last); sizeof(pred);
	#endif
	}

	template<typename T1, typename T2, class TPred> inline
	bool debug_pred(const TPred& pred, const T1& a, const T2& b)
	{
	#if RDE_DEBUG
		if (pred(a, b))
		{
			RDE_ASSERT(!pred(b, a));
			return true;
		}
		else
		{
			return false;
		}
	#else
		return pred(a, b);
	#endif
	}

} // namespace internal

#if !RDE_HAS_CPP14
#if RDE_HAS_CPP11 || RDE_COMPILER_MSVC_2010

//
// exchange
//
// Replaces the value of obj with new_value and returns the old value of obj.
//
// C++11 compatable version of std::exchange (introduced in C++14).
// Requires either C++11, or MSVC100 (for move/forward).
//
// NOTE: In cases that template argument deduction cannot happen, resulting in a non-deduced context
// (such as when exchanging overloaded functions causing ambiguous deduction), implicit instantiation
// will fail due to U not being a default template argument. In this case, explicit instantiation is needed.
//
// Example usage:
//    int  i1 = 1;
//    int* p1 = &i1;
//    void f1() { puts("f1"); };
//    void f2() { puts("f2"); };
//    void (*fp1)() = &f1;
//
//    int i2 = exchange(i1, 0); // i2==1, i1==0
//    int* p2 = exchange(p1, nullptr); // p2==&i1, p1==nullptr
//
//    fp1(); // prints "f1"
//    void (*fp2)() = exchange(fp1, &f2);
//    fp1(); // prints "f2"
//    fp2(); // prints "f1"
//
// Example usage with a non-deduced context:
//    void     f(double);
//    void     f(int);
//    void (*fp)(int);
//    //exchange(fp, &f); // fails due to ambiguous overload resolution
//    exchange(fp, static_cast<void(*)(int)>(fp1)); // ok: explicitly cast second parameter
//    exchange<void(*)(int)>(fp, &fp1); // ok: explicit template instantiation
//    exchange<decltype(fp)>(fp, &fp1); // ok: same as both of the above, using decltype
//

template<typename T>
T exchange(T& obj, T&& new_value)
{
	T old_value = std::move(obj);
	obj = std::forward<T>(new_value);
	return old_value;
}

template<typename T, typename U>
T exchange(T& obj, U&& new_value)
{
	(void)(&new_value);
	T old_value = std::move(obj);
	obj = std::forward<U>(new_value);
	return old_value;
}

#endif // #if RDE_HAS_CPP11
#endif // #if !RDE_HAS_CPP14

} // namespace rde

//-----------------------------------------------------------------------------
#endif // #ifndef RDESTL_UTILITY_H
