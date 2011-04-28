/*********************************************************\
 *  File: ScriptManager.h                                *
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


#ifndef __PLSCRIPT_SCRIPTMANAGER_H__
#define __PLSCRIPT_SCRIPTMANAGER_H__
#pragma once


//[-------------------------------------------------------]
//[ Includes                                              ]
//[-------------------------------------------------------]
#include <PLGeneral/Base/Singleton.h>
#include <PLGeneral/Container/Array.h>
#include <PLGeneral/Container/HashMap.h>
#include <PLCore/Base/Event/EventHandler.h>
#include "PLScript/PLScript.h"


//[-------------------------------------------------------]
//[ Forward declarations                                  ]
//[-------------------------------------------------------]
namespace PLCore {
	class Class;
}
namespace PLScript {
	class Script;
	class ScriptManager;
}


//[-------------------------------------------------------]
//[ Template instance                                     ]
//[-------------------------------------------------------]
PLSCRIPT_TEMPLATE template class PLSCRIPT_API PLGeneral::Singleton<PLScript::ScriptManager>;


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
namespace PLScript {


//[-------------------------------------------------------]
//[ Classes                                               ]
//[-------------------------------------------------------]
/**
*  @brief
*    Script manager
*
*  @note
*    - [TODO] Script support is currently under construction
*/
class ScriptManager : public PLGeneral::Singleton<ScriptManager> {


	//[-------------------------------------------------------]
	//[ Friends                                               ]
	//[-------------------------------------------------------]
	friend class PLGeneral::Singleton<ScriptManager>;


	//[-------------------------------------------------------]
	//[ Public functions                                      ]
	//[-------------------------------------------------------]
	public:
		/**
		*  @brief
		*    Returns a list of supported script languages
		*
		*  @return
		*    List of supported script languages
		*/
		PLSCRIPT_API const PLGeneral::Array<PLGeneral::String> &GetScriptLanguages();

		/**
		*  @brief
		*    Checks whether or not a given script language is supported
		*
		*  @param[in] sScriptLanguage
		*    Script language to check
		*
		*  @return
		*    'true' if the given script language is supported, else 'false'
		*/
		PLSCRIPT_API bool IsSupported(const PLGeneral::String &sScriptLanguage);

		/**
		*  @brief
		*    Creates a script instance
		*
		*  @param[in] sScriptLanguage
		*    Script language to use
		*
		*  @return
		*    The created script instance, null pointer on error
		*/
		PLSCRIPT_API Script *Create(const PLGeneral::String &sScriptLanguage);


	//[-------------------------------------------------------]
	//[ Protected functions                                   ]
	//[-------------------------------------------------------]
	protected:
		/**
		*  @brief
		*    Constructor
		*/
		PLSCRIPT_API ScriptManager();

		/**
		*  @brief
		*    Destructor
		*/
		PLSCRIPT_API virtual ~ScriptManager();


	//[-------------------------------------------------------]
	//[ Private functions                                     ]
	//[-------------------------------------------------------]
	private:
		/**
		*  @brief
		*    Register a class
		*
		*  @param[in] pClass
		*    Class to register, must be valid!
		*
		*  @note
		*    - If the class is not derived from 'PLScript::Script' it is ignored
		*    - The given class must be a new one, so this function did not check whether the
		*      class is already registered
		*/
		void OnClassLoaded(const PLCore::Class *pClass);

		/**
		*  @brief
		*    Registers queued classes
		*/
		void RegisterClasses();


	//[-------------------------------------------------------]
	//[ Private slots                                         ]
	//[-------------------------------------------------------]
	private:
		PLCore::EventHandler<const PLCore::Class*> SlotClassLoaded;


	//[-------------------------------------------------------]
	//[ Private data                                          ]
	//[-------------------------------------------------------]
	private:
		PLGeneral::Array<const PLCore::Class*>						m_lstNewClasses;		/**< New classes to register as soon as required */
		PLGeneral::Array<PLGeneral::String>							m_lstScriptLanguages;	/**< List of script languages */
		PLGeneral::HashMap<PLGeneral::String, const PLCore::Class*> m_mapScriptLanguages;	/**< Map of script languages (key = class name) */


};


//[-------------------------------------------------------]
//[ Namespace                                             ]
//[-------------------------------------------------------]
} // PLScript


#endif // __PLSCRIPT_SCRIPTMANAGER_H__