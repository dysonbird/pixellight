/*********************************************************\
 *  File: SNMPostProcessSepia2.h                         *
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


#ifndef __PLPOSTPROCESSEFFECTS_SEPIA2_H__
#define __PLPOSTPROCESSEFFECTS_SEPIA2_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLGraphics/Color/Color4.h>
#include <PLCompositing/SceneNodeModifiers/SNMPostProcess.h>


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLPostProcessEffects {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Sepia camera scene node post process modifier class
*
*  @remarks
*    Color manipulation.
*/
class SNMPostProcessSepia2 : public PLCompositing::SNMPostProcess {


	//[-------------------------------------------------------]
	//[ RTTI interface                                        ]
	//[-------------------------------------------------------]
	pl_class(pl_rtti_export, SNMPostProcessSepia2, "PLPostProcessEffects", PLCompositing::SNMPostProcess, "")
		// Attributes
		pl_attribute(TintColor0,	PLGraphics::Color4,	PLGraphics::Color4(0.299f, 0.587f, 0.184f,  0.31f),	ReadWrite,	DirectValue,	"Tint color 0 (red component)",			"")
		pl_attribute(TintColor1,	PLGraphics::Color4,	PLGraphics::Color4(0.299f, 0.587f, 0.184f,  0.17f),	ReadWrite,	DirectValue,	"Tint color 1 (green component)",		"")
		pl_attribute(TintColor2,	PLGraphics::Color4,	PLGraphics::Color4(0.299f, 0.587f, 0.184f, -0.09f),	ReadWrite,	DirectValue,	"Tint color 2 (blue component)",		"")
			// Overloaded SNMPostProcess attributes
		pl_attribute(Filename,		PLCore::String,		"Data/PostProcesses/Sepia2.pp",						ReadWrite,	ModifyAttr,		"Filename of the post process to use",	"Type='PostProcess'")
		// Constructors
		pl_constructor_1(ParameterConstructor,	PLScene::SceneNode&,	"Parameter constructor",	"")
	pl_class_end


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Constructor
		*
		*  @param[in] cSceneNode
		*    Owner scene node
		*/
		SNMPostProcessSepia2(PLScene::SceneNode &cSceneNode);

		/**
		*  @brief
		*    Destructor
		*/
		virtual ~SNMPostProcessSepia2();


	//[-------------------------------------------------------]
	//[ Class definition                                      ]
	//[-------------------------------------------------------]
	//[-------------------------------------------------------]
	//[ Public virtual PLCompositing::SNMPostProcess functions ]
	//[-------------------------------------------------------]
	public:
		virtual void SetParameters();


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLPostProcessEffects


#endif // __PLPOSTPROCESSEFFECTS_SEPIA2_H__