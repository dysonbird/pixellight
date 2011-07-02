/*********************************************************\
 *  File: Ogg.h                                          *
 *
 *  Copyright (C) 2002-2011 The PixelLight Team (http://www.pixellight.org/)
 *
 *  This file is part of PixelLight.
 *
 *  PixelLight is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU Lesser General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  PixelLight is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 *  GNU Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with PixelLight. If not, see <http://www.gnu.org/licenses/>.
\*********************************************************/


#ifndef __PLSOUNDOPENAL_OGG_H__
#define __PLSOUNDOPENAL_OGG_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLSoundOpenAL/PLSoundOpenAL.h"


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace PLGeneral {
	class File;
	template <class AType> class Array;
}


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLSoundOpenAL {


//[-------------------------------------------------------]
//[ Global functions                                      ]
//[-------------------------------------------------------]
/**
*  @brief
*    This function loads a '.ogg' file into a memory buffer and returns
*    the format and frequency
*
*  @param[in]  pFile
*    Sound file, must be valid
*  @param[out] lstBuffer
*    Will recive the read buffer data
*  @param[out] nFormat
*    Will receive the format
*  @param[out] nFrequency
*    Will receive the frequency
*
*  @return
*    'true' if all went fine and the file object was also destroyed automatically, else 'false'
*/
extern bool LoadOGG(PLGeneral::File *pFile, PLGeneral::Array<PLGeneral::uint8> &lstBuffer, ALenum &nFormat, ALsizei &nFrequency);

/**
*  @brief
*    This function loads a '.ogg' file into a memory buffer and returns
*    the format and frequency
*
*  @param[in]  nData
*    Data to read
*  @param[in]  nSize
*    Data size in bytes
*  @param[out] lstBuffer
*    Will recive the read buffer data
*  @param[out] nFormat
*    Will receive the format
*  @param[out] nFrequency
*    Will receive the frequency
*
*  @return
*    'true' if all went fine, else 'false'
*/
extern bool LoadOGG(const PLGeneral::uint8 nData[], PLGeneral::uint32 nSize, PLGeneral::Array<PLGeneral::uint8> &lstBuffer, ALenum &nFormat, ALsizei &nFrequency);


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLSoundOpenAL


#endif // __PLSOUNDOPENAL_OGG_H__