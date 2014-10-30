//!
//! @file				MString.hpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-08-12
//! @last-modified		2014-10-31
//! @brief				Contains the declarations for the String class.
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//======================================== HEADER GUARD =========================================//
//===============================================================================================//

#ifndef MSTRING_MSTRING_H
#define MSTRING_MSTRING_H

//===============================================================================================//
//==================================== FORWARD DECLARATION ======================================//
//===============================================================================================//

namespace MbeddedNinja
{
	class MString;
}

//===============================================================================================//
//========================================== INCLUDES ===========================================//
//===============================================================================================//

//===== SYSTEM LIBRARIES =====//
#include <cstdint>		// uint8_t, uint32_t, e.t.c
#include <iostream>

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace MbeddedNinja
{

	//! @brief		The default characters to trim from a string if none are provided as
	//!				an argument to String::Trim().
	static const char * defCharsToMatch = " \r\n\t";

	//! @brief		String class designed for embedded applications.
	//! @details	Exceptions are not used.
	class MString
	{	
		
		public:

			//! @brief		Enumerates the possible ends to trim a string from when calling String::Trim().
			enum class EndsToTrim
			{
				LEFT,		//!< Trim from the left-side of the string only.
				RIGHT,		//!< Trim from the right-side of the string only.
				BOTH		//!< Trim from both sides of the string.
			};

			//======================================================================================//
			//==================================== PUBLIC METHODS ==================================//
			//======================================================================================//
					
			//! @brief		Constructor.
			//! @details	Allocates memory for the string and copies the provided cString into this memory.
			//! @param		cString		C-style string to populate string with.
			//! @note
			MString(const char * cString);

			//! @brief		Simplified constructor.
			//! @details	Creates string object that only contains one character, the null char.
			MString();

			//! @brief		Copy constructor.
			//! @details	Delegates to normal constructor.
			MString(const MString &obj);

			//! @brief		Destructor.
			//! @details	Deletes memory that was allocated for the string.
			~MString();

			//! @brief		Call to find how many characters are in the string (excluding the null character).
			//! @returns	The number of characters in the string, excluding the terminating-null character.
			uint32_t GetLength();
						
			//! @brief		Searches for a particular character in the string.
			//! @returns	If character is found in string, returns the 0-based index of the first occurrence. If character is not found in string, returns -1.
			int32_t Find(char charToFind, uint32_t startPos = 0);

			//! @brief		Looks for first occurrence of cStringToFind inside this string, starting at startPos.
			//! @param		cStringToFind	The string to search for.
			//!	@param		startPos		The 0-based index to start searching from.
			//! @returns	If cStringToFind is found in string, returns the 0-based index of the first occurrence. If stringToFind is not found in string, returns -1.
			int32_t Find(const char * cStringToFind, uint32_t startPos = 0);

			//! @brief		Looks for the MString stringToFind inside this string.
			//! @details	Calls int32_t Find(const char * cStringToFind, uint32_t startPos = 0), passing in the C style string of stringToFind.
			//! @param		stringToFind	The string to search for.
			//!	@param		startPos		The 0-based index to start searching from.
			//! @returns	If stringToFind is found in string, returns the 0-based index of the first occurrence. If stringToFind is not found in string, returns -1.
			int32_t Find(const MString & stringToFind, uint32_t startPos = 0);

			//! @brief		Append a single character onto the end of the current string.
			//! @param		charToAppend		A single character to append onto the end of the current string.
			void Append(char charToAppend);

			//! @brief		Append a C-style string onto the end of the current string.
			//! @param		cStringToAppend		A null-terminated C-style string to append onto the end of the current string.
			void Append(const char * cStringToAppend);

			//! @brief		Erases a specific number of characters from the string.
			//! @details	Similar to std::string::Erase(), except that it does not throw any exceptions.
			//! @param		startPos	The 0-indexed position to start erasing characters from. If startPos
			//!							> string length then no characters will be erased.
			//! @param		numOfChars	The number of characters to erase. If numOfChars > string length
			//!							then all characters will be erased.
			void Erase(uint32_t startPos, int32_t numOfChars = -1);

			//! @brief		Trims white-space (or specified chars) from either or both ends of the string.
			//! @details	Default characters are all those which are considered to be
			//!				 white space: ' ', '\r', '\n', '\t'.
			//!				Calls Erase().
			//! @param		charsToMatch	A string of all the characters that should be trimmed
			//!								from the string. Default is all characters considered to
			//!								be white space.
			void Trim(MString charsToMatch = defCharsToMatch, EndsToTrim endsToTrim = EndsToTrim::BOTH);

			//! @brief		Simplified overload of Trim().
			//! @details	Calls the base Trim() with charsToMatch = defaultCharsToMatch.
			//! @sa			Trim().
			void Trim(EndsToTrim endsToTrim);

			//======================================================================================//
			//============================ PUBLIC OPERATOR OVERLOAD DECLARATIONS ===================//
			//======================================================================================//

			//! @brief		Assignment operator overload. Allows you to make one string equal another.
			//! @details	Copies the contents of the RHS string into the LHS, so that they both have
			//!				the same contents (but do not point to the same memory!).
			MString & operator= (const MString & other);

			//! @brief		Subscript operator overload. Allows individual char access.
			//! @returns	Reference to char located at position 'index'. Performs bounds checking, only
			//!				allows chars and terminating null to be indexed, any other number is out
			//!				of bounds. If index is out-of-bounds, the first character in the array will be
			//!				returned. We shouldn't be allowed to write to the terminating null, but
			//!				we have to provide access for read operations.
			char & operator[] (const uint32_t index);

			//! @brief		Compound assignment operator overload.
			//! @details	Appends the RHS C-style string onto the LHS string object.
			//!				Used by the "+" operator overload.
			MString & operator+=(const char * rhs);

			//! @brief		Compound assignment operator overload.
			//! @details	Appends the RHS string onto the LHS string.
			//!				Used by the "+" operator overload.
			MString & operator+=(const MString &rhs);

			//! @brief		Equality operator overload. Allows you to compare one string object and
			//!				one C-style string for equality.
			//! @details	Used by the other equality operator overload and the inequality operator overload.
			friend bool operator==(const MString &lhs, const char * rhs);
			//friend bool operator==(MString &lhs, char * rhs);

			//friend bool operator==(const char * lhs, MString &rhs);
			//friend bool operator==(char * lhs, MString &rhs);

			//friend bool operator==(const char * const lhs, const MString &rhs);

			friend std::ostream& operator<< (std::ostream &lhs, const MString &rhs);

			//bool operator==(MString &rhs) const;
			//bool operator==(const char * rhs) const;
			//bool operator==(char * rhs) const;

			//! @brief		Equality operator overload. Allows you to compare two string objects for equality.
			//! @details	Calls the overload with one string object and one C-style string.
			//!				Also used by the inequality operator overload.
			friend bool operator==(const MString & lhs, const MString & rhs);

			//! @brief		Inequality operator overload. Allows you to compare one string and
			//!				one C-style string for inequality.
			//! @details	Internally calls the equality operator overload.
			friend bool operator!=(MString & lhs, const char * rhs);

			//! @brief		Inequality operator overload. Allows you to compare two strings for inequality.
			//! @details	Internally calls the equality operator overload.
			friend bool operator!=(MString & lhs, MString & rhs);

			//! @brief		Allows you to concatenate two strings together.
			//! @details	Calls the Append() method.
			friend MString operator+(MString lhs, const char * rhs);

			//! @brief		Allows you to concatenate a string object and a C-style string together.
			//! @details	Calls the += operaotr which in turn calls the Append() method.
			//!				Pass LHS by value to allow to better optimisation.
			friend MString operator+(MString lhs, MString & rhs);

			//! \defgroup{Shift Operators}
			//! @{

			//! @brief		Allows you to append the RHS C-style string onto the LHS
			//!				string object with LHS << RHS.
			MString & operator << (const char * rhs);

			//! @brief		Allows you to append the RHS string object onto the LHS
			//!				string object with LHS << RHS.
			MString & operator << (const MString & rhs);

			//! @brief		Operator overload for uint8_t. Appends unsigned integer onto the end of the string.
			MString & operator << (uint8_t myUint16);

			//! @brief		Operator overload for int8_t. Appends integer onto the end of the string.
			MString & operator << (int8_t myInt16);

			//! @brief		Operator overload for uint16_t. Appends unsigned integer onto the end of the string.
			MString & operator << (uint16_t myUint16);

			//! @brief		Operator overload for int16_t. Appends integer onto the end of the string.
			MString & operator << (int16_t myInt16);

			//! @brief		Operator overload for uint32_t. Appends unsigned integer onto the end of the string.
			MString & operator << (uint32_t myUint32);

			//! @brief		Operator overload for int32_t. Appends integer onto the end of the string.
			MString & operator << (int32_t myInt32);

			//! @brief		Operator overload for uint64_t. Appends unsigned integer onto the end of the string.
			MString & operator << (uint64_t myUint64);

			//! @brief		Operator overload for int64_t. Appends integer onto the end of the string.
			MString & operator << (int64_t myInt64);

			//! @brief		Operator overload for double. Appends double onto the end of the string.
			MString & operator << (double myDouble);

			//! @}

			//! \defgroup{Type Conversions}
			//! @{

			//! @brief		Type conversion for going from a string object to a const char * (C-style string).
			operator const char *();

			//! @}

			//======================================================================================//
			//================================= PUBLIC VARIABLES ===================================//
			//======================================================================================//
				
			//! @brief		Pointer to internal memory where C-style string is stored. Guaranteed
			//!				to be null-terminated.
			//! @details	Access this to pass in string when a C-style function is called.
			char * cStr;
				
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


} // namespace MbeddedNinja

#endif	// #ifndef STRING_CPP_STRING_H

// EOF
