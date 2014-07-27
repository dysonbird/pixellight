/*********************************************************\
 *  File: PLCore.h                                       *
 *
 *  Copyright (C) 2002-2013 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy of this software
 *  and associated documentation files (the "Software"), to deal in the Software without
 *  restriction, including without limitation the rights to use, copy, modify, merge, publish,
 *  distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the
 *  Software is furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in all copies or
 *  substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 *  BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND
 *  NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
 *  DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
\*********************************************************/


#ifndef __PLCORE_TYPETRAITS2_H__
#define __PLCORE_TYPETRAITS2_H__
#pragma once


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLCore {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Member function type decomposer
*/
template <typename T>
struct MemberFunctionDecomp;

template <class TClass, typename TRet, typename... TArgs>
struct MemberFunctionDecomp<TRet(TClass::*)(TArgs...)> {

	//[-------------------------------------------------------]
	//[ Public types                                          ]
	//[-------------------------------------------------------]
	typedef TClass _Class;
	typedef TRet _ReturnType;
};

/**
*  @brief
*    Remove reference from a type
*/
template <typename T>
struct RemoveReference {

	typedef T Type;
};

template <typename T>
struct RemoveReference<T&> {

	typedef T Type;
};

template <typename T>
struct RemoveReference<T&&> {

	typedef T Type;
};

/**
*  @brief
*    Remove const from a type
*/
template <typename T>
struct RemoveConst {

	typedef T Type;
};

template <typename T>
struct RemoveConst<const T> {

	typedef T Type;
};

/**
*  @brief
*    This template will remove all type qualifiers (const, pointers, references)
*/
template <typename T>
struct RawType
{
	// [TODO] use the above Remove* instead of specialization
	typedef T Type;
};

template <typename T>
struct RawType<const T>
{
	typedef typename RawType<T>::Type Type;
};

template <typename T>
struct RawType<T&>
{
	typedef typename RawType<T>::Type Type;
};

template <typename T>
struct RawType<T*>
{
	typedef typename RawType<T>::Type Type;
};

//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLCore


#endif // __PLCORE_TYPETRAITS2_H__
