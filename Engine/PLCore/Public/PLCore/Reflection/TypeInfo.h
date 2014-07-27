/*********************************************************\
 *  File: Rtti.h                                         *
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


#ifndef __PLCORE_REFL_TYPEINFO_H__
#define __PLCORE_REFL_TYPEINFO_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLCore/String/String.h>
#include <PLCore/Typebase/TypeTraits.h>


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLRefl {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Reflection type representation
*/
class TypeInfo {


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*/
		PLCORE_API TypeInfo(const PLCore::String &sName);

		/**
		*  @brief
		*    Virtual destructor
		*/
		virtual ~TypeInfo() {}

	//[-------------------------------------------------------]
	//[ Protected data                                        ]
	//[-------------------------------------------------------]
	protected:
		PLCore::String	m_sName;			/**< Name of the type */
};

//TEST
template <bool IS_CONST>
class PointerTypeInfo : public TypeInfo {

	public:
		PointerTypeInfo(TypeInfo *pPointedType) : TypeInfo(IS_CONST ? "const*" : "*"), m_pPointedType(pPointedType) {}

		TypeInfo *GetPointedType()
		{
			return m_pPointedType;
		}

	private:
		TypeInfo *m_pPointedType;
};

template <bool IS_CONST>
class ReferenceTypeInfo : public TypeInfo {

public:
	ReferenceTypeInfo(TypeInfo *pPointedType) : TypeInfo(IS_CONST ? "const&" : "&"), m_pPointedType(pPointedType) {}

	TypeInfo *GetPointedType()
	{
		return m_pPointedType;
	}

private:
	TypeInfo *m_pPointedType;
};

/**
*  @brief
*    Helper to retrieve a TypeInfo from object type
*/
template <typename T>
struct StaticTypeInfo;

/**
*  @brief
*    Specialization of StaticTypeInfo for classes without defined reflection
*
*  @remarks
*    This will throw a compile time error if you try to retrieve reflection type Id
*    of a non-registered type
*/
template <typename T>
struct StaticTypeInfo {

	static TypeInfo *Get()
	{
		// This will create at least somehow verbose compile-time error
		return T::TYPE_NOT_REGISTERED_IN_REFLECTION();
	}

	enum { Defined = false, Copyable = true };
};

//TEST
template <typename T>
struct StaticTypeInfo<T*> {

	static TypeInfo *Get()
	{
		static PointerTypeInfo<false> info(StaticTypeInfo<T>::Get());
		return &info;
	}

	enum { Defined = true, Copyable = true };
};

template <typename T>
struct StaticTypeInfo<const T*> {

	static TypeInfo *Get()
	{
		static PointerTypeInfo<true> info(StaticTypeInfo<T>::Get());
		return &info;
	}

	enum { Defined = true, Copyable = true };
};

template <typename T>
struct StaticTypeInfo<T&> {

	static TypeInfo *Get()
	{
		static ReferenceTypeInfo<false> info(StaticTypeInfo<T>::Get());
		return &info;
	}

	enum { Defined = true, Copyable = false };
};

template <typename T>
struct StaticTypeInfo<const T&> {

	static TypeInfo *Get()
	{
		static ReferenceTypeInfo<true> info(StaticTypeInfo<T>::Get());
		return &info;
	}

	enum { Defined = true, Copyable = false };
};

/**
*  @brief
*    Check if the given type has been registered with reflection
*/
template <typename T>
struct HasStaticTypeInfo {

	enum Value
	{
		Value = StaticTypeInfo<PLCore::RawType<T>>::Defined;
	};
};

//[-------------------------------------------------------]
//[ Global functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    Retirieve the static type Id of the given type
*/
template <typename T>
TypeInfo *GetStaticTypeInfo()
{
	return StaticTypeInfo<typename PLCore::RawType<T>::Type>::Get();
}

/**
*  @brief
*    Retrieve the static type Id from the specified instance
*/
template <typename T>
TypeInfo *GetStaticTypeInfo(const T&)
{
	// [TODO] This won't work if for example a base class pointer is passed here but the object is of derived class type
	return StaticTypeInfo<typename PLCore::RawType<T>::Type>::Get();
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLRefl


#endif // __PLCORE_REFL_TYPEINFO_H__
