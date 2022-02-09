#ifndef RDESTL_ALGORITHM_H
#define RDESTL_ALGORITHM_H

#include "int_to_type.h"
#include "iterator.h"
#include "type_traits.h"
#include "utility.h"

namespace rde
{

#ifndef RDE_COMPILER_MSVC_2010
//-----------------------------------------------------------------------------
// Modern C++ version that does constructor/copy constructor/move constructor in 1
template<typename T, typename... Args> RDE_FORCEINLINE
void construct_args(T* p, Args&&... args)
{
	::new (static_cast<void*>(p)) T(std::forward<Args>(args)...);
}
#else
// TODO Regression tests for VS2010
#pragma region VS2010_COMPATABILITY_TEMPLATES

template<typename T, class Arg1> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1));
}

template<typename T, class Arg1, class Arg2> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2));
}

template<typename T, class Arg1, class Arg2, class Arg3> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21, class Arg22> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21, Arg22&& arg22) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21), std::forward<Arg22>(arg22));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21, class Arg22, class Arg23> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21, Arg22&& arg22, Arg23&& arg23) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21), std::forward<Arg22>(arg22), std::forward<Arg23>(arg23));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21, class Arg22, class Arg23, class Arg24> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21, Arg22&& arg22, Arg23&& arg23, Arg24&& arg24) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21), std::forward<Arg22>(arg22), std::forward<Arg23>(arg23), std::forward<Arg24>(arg24));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21, class Arg22, class Arg23, class Arg24, class Arg25> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21, Arg22&& arg22, Arg23&& arg23, Arg24&& arg24, Arg25&& arg25) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21), std::forward<Arg22>(arg22), std::forward<Arg23>(arg23), std::forward<Arg24>(arg24), std::forward<Arg25>(arg25));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21, class Arg22, class Arg23, class Arg24, class Arg25, class Arg26> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21, Arg22&& arg22, Arg23&& arg23, Arg24&& arg24, Arg25&& arg25, Arg26&& arg26) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21), std::forward<Arg22>(arg22), std::forward<Arg23>(arg23), std::forward<Arg24>(arg24), std::forward<Arg25>(arg25), std::forward<Arg26>(arg26));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21, class Arg22, class Arg23, class Arg24, class Arg25, class Arg26, class Arg27> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21, Arg22&& arg22, Arg23&& arg23, Arg24&& arg24, Arg25&& arg25, Arg26&& arg26, Arg27&& arg27) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21), std::forward<Arg22>(arg22), std::forward<Arg23>(arg23), std::forward<Arg24>(arg24), std::forward<Arg25>(arg25), std::forward<Arg26>(arg26), std::forward<Arg27>(arg27));
}

template<typename T, class Arg1, class Arg2, class Arg3, class Arg4, class Arg5, class Arg6, class Arg7, class Arg8, class Arg9, class Arg10, class Arg11, class Arg12, class Arg13, class Arg14, class Arg15, class Arg16, class Arg17, class Arg18, class Arg19, class Arg20, class Arg21, class Arg22, class Arg23, class Arg24, class Arg25, class Arg26, class Arg27, class Arg28> RDE_FORCEINLINE
void construct_args(T* p, Arg1&& arg1, Arg2&& arg2, Arg3&& arg3, Arg4&& arg4, Arg5&& arg5, Arg6&& arg6, Arg7&& arg7, Arg8&& arg8, Arg9&& arg9, Arg10&& arg10, Arg11&& arg11, Arg12&& arg12, Arg13&& arg13, Arg14&& arg14, Arg15&& arg15, Arg16&& arg16, Arg17&& arg17, Arg18&& arg18, Arg19&& arg19, Arg20&& arg20, Arg21&& arg21, Arg22&& arg22, Arg23&& arg23, Arg24&& arg24, Arg25&& arg25, Arg26&& arg26, Arg27&& arg27, Arg28&& arg28) {
	::new (static_cast<void*>(p)) T(std::forward<Arg1>(arg1), std::forward<Arg2>(arg2), std::forward<Arg3>(arg3), std::forward<Arg4>(arg4), std::forward<Arg5>(arg5), std::forward<Arg6>(arg6), std::forward<Arg7>(arg7), std::forward<Arg8>(arg8), std::forward<Arg9>(arg9), std::forward<Arg10>(arg10), std::forward<Arg11>(arg11), std::forward<Arg12>(arg12), std::forward<Arg13>(arg13), std::forward<Arg14>(arg14), std::forward<Arg15>(arg15), std::forward<Arg16>(arg16), std::forward<Arg17>(arg17), std::forward<Arg18>(arg18), std::forward<Arg19>(arg19), std::forward<Arg20>(arg20), std::forward<Arg21>(arg21), std::forward<Arg22>(arg22), std::forward<Arg23>(arg23), std::forward<Arg24>(arg24), std::forward<Arg25>(arg25), std::forward<Arg26>(arg26), std::forward<Arg27>(arg27), std::forward<Arg28>(arg28));
}

#pragma endregion
#endif
//-----------------------------------------------------------------------------
template<typename T> RDE_FORCEINLINE
void copy_construct(T* mem, const T& orig)
{
	//new (mem) T(orig);
	internal::copy_construct(mem, orig, int_to_type<has_trivial_copy<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T> RDE_FORCEINLINE
void construct(T* mem)
{
	internal::construct(mem, int_to_type<has_trivial_constructor<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T> RDE_FORCEINLINE
void destruct(T* mem)
{
	internal::destruct(mem, int_to_type<has_trivial_destructor<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T>
void copy_n(const T* first, size_t n, T* result)
{
	internal::copy_n(first, n, result, int_to_type<has_trivial_copy<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T>
void copy(const T* first, const T* last, T* result)
{
	internal::copy(first, last, result, int_to_type<has_trivial_copy<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T>
void copy_construct_n(T* first, size_t n, T* result)
{
	internal::copy_construct_n(first, n, result, int_to_type<has_trivial_copy<T>::value>());
}

//-----------------------------------------------------------------------------
// Modern C++ version that does constructor / copy constructor / move constructor in 1
template <typename T>
void move_construct_n(T* first, size_t n, T* result)
{
	internal::move_construct_n(first, n, result, int_to_type<has_trivial_copy<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T>
void move_n(const T* from, size_t n, T* result)
{
	RDE_ASSERT(from != result || n == 0);
	// Overlap?
	if (result + n >= from && result < from + n)
	{
		internal::move_n(from, n, result, int_to_type<has_trivial_copy<T>::value>());
	}
	else
	{
		internal::copy_n(from, n, result, int_to_type<has_trivial_copy<T>::value>());
	}
}

//-----------------------------------------------------------------------------
template<typename T>
inline void move(const T* first, const T* last, T* result)
{
	RDE_ASSERT(first != result || first == last);
	const size_t n = reinterpret_cast<uintptr_t>(last) - reinterpret_cast<uintptr_t>(first);
	const unsigned char* resultEnd = reinterpret_cast<const unsigned char*>(result) + n;
	if (resultEnd >= reinterpret_cast<const unsigned char*>(first) && result < last)
	{
		internal::move(first, last, result, int_to_type<has_trivial_copy<T>::value>());
	}
	else
	{
		internal::copy(first, last, result, int_to_type<has_trivial_copy<T>::value>());
	}
}

//-----------------------------------------------------------------------------
template<typename T>
void construct_n(T* first, size_t n)
{
	internal::construct_n(first, n, int_to_type<has_trivial_constructor<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T>
void destruct_n(T* first, size_t n)
{
	internal::destruct_n(first, n, int_to_type<has_trivial_destructor<T>::value>());
}

//-----------------------------------------------------------------------------
template<typename T> RDE_FORCEINLINE
void fill_n(T* first, size_t n, const T& val)
{
	//for (size_t i = 0; i < n; ++i)
	//	first[i] = val;
	// Loop unrolling with Duff's Device.
	T* last = first + n;
	switch (n & 0x7)
	{
	case 0:
		while (first != last)
		{
			*first = val; ++first;
	case 7:	*first = val; ++first;
	case 6:	*first = val; ++first;
	case 5:	*first = val; ++first;
	case 4:	*first = val; ++first;
	case 3:	*first = val; ++first;
	case 2:	*first = val; ++first;
	case 1:	*first = val; ++first;
		}
	}
}

//-----------------------------------------------------------------------------
template<typename TIter, typename TDist> inline
void distance(TIter first, TIter last, TDist& dist)
{
	internal::distance(first, last, dist, typename iterator_traits<TIter>::iterator_category());
}

//-----------------------------------------------------------------------------
template<typename TIter, typename TDist> inline
void advance(TIter& iter, TDist off)
{
	internal::advance(iter, off, typename iterator_traits<TIter>::iterator_category());
}

//-----------------------------------------------------------------------------
template<class TIter, typename T, class TPred> inline
TIter lower_bound(TIter first, TIter last, const T& val, const TPred& pred)
{
	internal::test_ordering(first, last, pred);
	int dist(0);
	distance(first, last, dist);
	while (dist > 0)
	{
		const int halfDist = dist >> 1;
		TIter mid = first;
		rde::advance(mid, halfDist);
		if (internal::debug_pred(pred, *mid, val))
			first = ++mid, dist -= halfDist + 1;
		else
			dist = halfDist;
	}
	return first;
}

//-----------------------------------------------------------------------------
template<class TIter, typename T, class TPred> inline
TIter upper_bound(TIter first, TIter last, const T& val, const TPred& pred)
{
	internal::test_ordering(first, last, pred);
	int dist(0);
	distance(first, last, dist);
	while (dist > 0)
	{
		const int halfDist = dist >> 1;
		TIter mid = first;
		advance(mid, halfDist);
		if (!internal::debug_pred(pred, val, *mid))
			first = ++mid, dist -= halfDist + 1;
		else
			dist = halfDist;
	}
	return first;
}

//-----------------------------------------------------------------------------
template<class TIter, typename T>
TIter find(TIter first, TIter last, const T& val)
{
	while (first != last)
	{
		if ((*first) == val)
			return first;
		++first;
	}
	return last;
}

//-----------------------------------------------------------------------------
template<class TIter, typename T, class TPred>
TIter find_if(TIter first, TIter last, const T& val, const TPred& pred)
{
	while (first != last)
	{
		if (pred(*first, val))
			return first;
		++first;
	}
	return last;
}

//-----------------------------------------------------------------------------
template<class TIter, typename T>
void accumulate(TIter first, TIter last, T& result)
{
	while (first != last)
	{
		result += *first;
		++first;
	}
}

//-----------------------------------------------------------------------------
template<typename T>
T abs(const T& t)
{
	return t >= T(0) ? t : -t;
}
// No branches, Hacker's Delight way.
RDE_FORCEINLINE int abs(int x)
{
	const int y = x >> 31;
	return (x ^ y) - y;
}
RDE_FORCEINLINE short abs(short x)
{
	const short y = x >> 15;
	return (x ^ y) - y;
}

//-----------------------------------------------------------------------------
template<typename T> inline
T max(const T& x, const T& y)
{
	return x > y ? x : y;
}

//-----------------------------------------------------------------------------
template<typename T> inline
T min(const T& x, const T& y)
{
	return x < y ? x : y;
}
// @TODO: determine if it REALLY is quicker than version with branches.
/*RDE_FORCEINLINE float min(float x, float y)
{
	float result;
	__asm
	{
		fld		[x]
		fld		[y]
		fcomi	st(0), st(1)
		fcmovnb	st(0), st(1)
		fstp	[result]
		fcomp
	}
	return result;
}*/

//-----------------------------------------------------------------------------
template<typename TAssignable>
void swap(TAssignable& a, TAssignable& b)
{
	TAssignable tmp(a);
	a = b;
	b = tmp;
}

} // namespace rde

//-----------------------------------------------------------------------------
#endif // #ifndef RDESTL_ALGORITHM_H
