//!
//! @file				String.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created			2014-08-12
//! @last-modified		2014-08-12
//! @brief
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef STRING_CPP_STRING_H
#define STRING_CPP_STRING_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace StringNs
{
	class TemplateClass;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

// System headers
#include <cstdint>		// int8_t, int32_t e.t.c

// User libraries
// none

// User headers
// none

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace StringNs
{
	
	//! @brief		String class.
	//! @details	Detailed description of class.
	class String
	{	
		
		public:
									
			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//
					
			//! @brief		Constructor.
			//! @details	Allocates memory for the string and copies the provided cString into this memory.
			//! @param		cString		C-style string to populate string with.
			//! @note
			String(const char * cString);

			//! @brief		Simplified constructor.
			//! @details	Creates string object that only contains one character, the null char.
			String();

			//! @brief		Copy constructor.
			//! @details	Delegates to normal constructor.
			String(const String &obj);

			//! @brief		Assignment operator overload.
			String & operator= (const String & other);

			//! @brief		Destructor.
			//! @details	Deletes memory that was allocated for the string.
			~String();

			//! @brief		Call to find how many characters are in the string (excluding the null character).
			//! @returns	The number of characters in the string, excluding the terminating-null character.
			uint32_t GetLength();
						
			//! @brief		Searches for a particular character in the string.
			//! @returns	If character is found in string, returns the 0-based index of the first
			//!				occurrence. If character is not found in string, returns -1.
			int32_t Find(char charToFind, uint32_t startPos = 0);

			//! @brief		Looks for first occurrence of cStringToFind inside this string, starting at startPos.
			//! @param		cStringToFind	The string to search for.
			//!	@param		startPos		The 0-based index to start searching from.
			//! @returns	If cStringToFind is found in string, returns the 0-based index of the first
			//!				occurrence. If stringToFind is not found in string, returns -1.
			int32_t Find(const char * cStringToFind, uint32_t startPos = 0);

			//! @brief		Looks for stringToFind inside this string.
			//! @details	Calls int32_t Find(const char * cStringToFind, uint32_t startPos = 0),
			//!				passing in the C style string of stringToFind.
			//! @param		stringToFind	The string to search for.
			//!	@param		startPos		The 0-based index to start searching from.
			//! @returns	If stringToFind is found in string, returns the 0-based index of the first
			//!				occurrence. If stringToFind is not found in string, returns -1.
			int32_t Find(const String & stringToFind, uint32_t startPos = 0);

			//! @brief		Append a C-style string onto the end of the current string.
			//! @param		cStringToAppend		A null-terminated C-style string to append onto the
			//!									end of the current string.
			void Append(const char * cStringToAppend);

			//! @brief		Erases a specific number of characters from the string.
			//! @details	Similar to std::string::Erase(), except that it does not throw any exceptions.
			//! @param		startPos	The 0-indexed position to start erasing characters from. If startPos
			//!							> string length then no characters will be erased.
			//! @param		numOfChars	The number of characters to erase. If numOfChars > string length
			//!							then all characters will be erased.
			void Erase(uint32_t startPos, int32_t numOfChars = -1);

			//! @brief		Allows you to concatenate two strings together.
			//! @details	Calls the Append() method.
			friend String operator+(String & lhs, String & rhs);

			//======================================================================================//
			//================================= PUBLIC VARIABLES ===================================//
			//======================================================================================//
				
			//! @brief		Pointer to internal memory where C-style string is stored. Guaranteed
			//!				to be null-terminated.
			//! @details	Access this to pass in string when a C-style function is called.
			char * cStringPtr;
				
		private:
						
			//======================================================================================//
			//=================================== PRIVATE METHODS ==================================//
			//======================================================================================//
			
			// none
			
			//======================================================================================//
			//================================== PRIVATE VARIABLES =================================//
			//======================================================================================//

			//! @brief		Remembers the length of the string.
			uint32_t length;

		protected:

			//======================================================================================//
			//=================================== PROTECTED METHODS ================================//
			//======================================================================================//
			
			// none
			
			//======================================================================================//
			//================================== PROTECTED VARIABLES ===============================//
			//======================================================================================//

			// none
		
	}; // class String


} // namespace StringNs

#endif	// #ifndef STRING_CPP_STRING_H

// EOF
