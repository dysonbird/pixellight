/*********************************************************\
 *  File: ShaderFunctionGradientNull.h                   *
 *
 *  Copyright (C) 2002-2012 The PixelLight Team (http://www.pixellight.org/)
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


#ifndef __PLVOLUMERENDERER_SHADERFUNCTION_GRADIENT_NULL_H__
#define __PLVOLUMERENDERER_SHADERFUNCTION_GRADIENT_NULL_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include "PLVolumeRenderer/Gradient/ShaderFunctionGradient.h"


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLVolumeRenderer {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Null shader function implementation class for gradient
*/
class ShaderFunctionGradientNull : public ShaderFunctionGradient {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(PLVOLUMERENDERER_RTTI_EXPORT, ShaderFunctionGradientNull, "PLVolumeRenderer", PLVolumeRenderer::ShaderFunctionGradient, "Null shader function implementation class for gradient")
		// Constructors
		pl_constructor_0(DefaultConstructor,	"Default constructor",	"")
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Default constructor
		*/
		PLVOLUMERENDERER_API ShaderFunctionGradientNull();

		/**
		*  @brief
		*    Destructor
		*/
		PLVOLUMERENDERER_API virtual ~ShaderFunctionGradientNull();


	//[-------------------------------------------------------]
	//[ Public virtual ShaderFunction functions               ]
	//[-------------------------------------------------------]
	public:
		PLVOLUMERENDERER_API virtual PLCore::String GetSourceCode(const PLCore::String &sShaderLanguage, ESourceCodeType nSourceCodeType) override;


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLVolumeRenderer


#endif // __PLVOLUMERENDERER_SHADERFUNCTION_GRADIENT_NULL_H__