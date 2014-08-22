//!
//! @file				String.cpp
//! @author				Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created			2014-08-12
//! @last-modified		2014-08-21
//! @brief				Contains the definitions for the String class.
//! @details
//!						See README.rst in repo root dir for more info.

#ifndef __cplusplus
	#error Please build with C++ compiler
#endif

//===============================================================================================//
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System libraries
#include <cstdint>		// int8_t, int32_t e.t.c
#include <cstring>		// strlen(), strncpy()
#include <cstdio>
//#include <iostream>		//!< @debug

// User libraries
// none

// User source
#include "../include/String.hpp"

//===============================================================================================//
//======================================== NAMESPACE ============================================//
//===============================================================================================//

namespace StringNs
{

	//============================================================================================//
	//======================= PUBLIC OPERATOR OVERLOAD DEFINITIONS ===============================//
	//============================================================================================//

	bool operator==(String & lhs, const char * rhs)
	{
		// Use strcmp function, returns 0 (false) if strings match, so note
		// the logic inversion that takes place here!
		if(strcmp(lhs.cStr, rhs))
			return false;
		else
			return true;
	}

	bool operator==(String & lhs, String & rhs)
	{
		// Call the overload with one string obj and one c-style string
		return (lhs == rhs.cStr);
	}

	bool operator!=(String & lhs, const char * rhs)
	{
		// Use the equality overload to perform the inequality overload
		if(lhs == rhs)
			return false;
		else
			return true;
	}

	bool operator!=(String & lhs, String & rhs)
	{
		// Call the inquality overload with one string object
		// and one C-style string
		return (lhs != rhs.cStr);
	}


	String operator+(String & lhs, const char * rhs)
	{
		// + operator overload between a strings object and a C-style string
		String result(lhs.cStr);
		result.Append(rhs);
		return result;

	}

	String operator+(String & lhs, String & rhs)
	{
		// + operator overload between two strings,
		// joins the two strings together
		String result(lhs.cStr);
		result.Append(rhs.cStr);
		return result;
	}



	//============================================================================================//
	//=============================== PUBLIC METHOD DEFINITIONS ==================================//
	//============================================================================================//

	String::String(const char * cString)
	{
		// Get length of cString
		this->length = strlen(cString);

		// Allocate memory to store this string, + 1 to store null char
		this->cStr = new char[this->length + 1];

		// Now copy string across
		strncpy(this->cStr, cString, this->length);

		// Make sure it is null terminated
		this->cStr[this->length] = '\0';
	}

	String::String() :
			String("") // Delegate to base constructor, passing in empty C-style string
	{
		// No code needed here
	}

	String::String(const String &obj) :
		String(obj.cStr)	// Delegate to base constructor, passing in the C-style string
	{
		// Copy constructor
		// Nothing here
	}

	String & String::operator= (const String & other)
	{
		//std::cerr << "Assignment operator overload called.\r\n";

		// Assignment operator
		if (this != &other) // protect against invalid self-assignment
		{
			// Make sure C-string ptr is valid
			if(!other.cStr)
				return *this;

			//std::cerr << "LHS.cStr = '" << this->cStringPtr << "'. Length = '" <<
			//		this->length << "'.\r\n" << std::endl;
			//std::cerr << "RHS.cStr = '" << other.cStringPtr << "'. Length = '" <<
			//					other.length << "'.\r\n" << std::endl;

			// Deallocate current memory
			delete[] this->cStr;

			// Copy length
			this->length = other.length;

			// allocate memory for our copy
			this->cStr = new char[this->length + 1];

			// Copy the parameter the newly allocated memory
			strncpy(this->cStr, other.cStr, this->length + 1);

			// Make sure a null is inserted at the end
			// This should never be required and strncpy should always insert it,
			// but better to be safe than sorry
			this->cStr[this->length] = '\0';

			//std::cerr << "New LHS.cStr = '" << this->cStringPtr << "'. New Length = '" <<
			//					this->length << "'.\r\n" << std::endl;

		}

		// Return *this for chaining
		return *this;
	}

	char & String::operator[] (const uint32_t index)
	{

		// Check if index is > length (e.g. past null char)
		if(index > this->length)
		{
			//! @todo Add assert No bounds checking!

			// Index is out of bounds, the best we can do is return
			// something is in bounds, so let's return
			// the last char. This could cause unexpected behaviour,
			// so an assert() needs to be added!
			return this->cStr[0];
		}

	    return this->cStr[index];
	}


	String::~String()
	{
		// Delete memory that was allocated in the constructor.
		delete[] this->cStr;
	}

	uint32_t String::GetLength()
	{
		// Easy, just return the internal length variable
		return this->length;
	}

	int32_t String::Find(char charToFind, uint32_t startPos)
	{
		// Check if char to find is null, in that case, return -1 straight away
		if(charToFind == '\0')
			return -1;

		// Create temporary C-style string for charToFind,
		// because strstr() requires the string to find to be null-terminated
		char stringToFind[2] = {0};
		stringToFind[0] = charToFind;

		return this->Find(stringToFind, startPos);

		/*

		// Search for character using C std library call strstr()
		char * ptrToFirstOccurance = strstr(this->cStringPtr, stringToFind);

		if(ptrToFirstOccurance == nullptr)
			return -1;
		else
		{
			// Return offset of pointer to matched string from start of searched-in string,
			// this will be the index
			return ptrToFirstOccurance - this->cStringPtr;
		}*/

	}

	int32_t String::Find(const char * cStringToFind, uint32_t startPos)
	{
		// Look for stringToFind inside string, offsetting string by startPos
		char * ptrToFirstOccurance = strstr(this->cStr + startPos, cStringToFind);

		if(ptrToFirstOccurance == nullptr)
			// stringToFind not found inside string, return -1.
			return -1;
		else
			// Return offset of pointer to matched string from start of searched-in string,
			// this will be the index
			return ptrToFirstOccurance - this->cStr;
	}

	int32_t String::Find(const String & stringToFind, uint32_t startPos)
	{
		// Call base method, passing in C-style string
		return this->Find(stringToFind.cStr, startPos);
	}

	void String::Append(const char * cStringToAppend)
	{
		// Get length of stringToAppend
		uint32_t appendStringLength = strlen(cStringToAppend);

		// Allocate memory for new string
		char * newCStringPtr = new char[this->length + appendStringLength + 1];

		// Copy across first section
		strncpy(newCStringPtr, this->cStr, this->length);

		// Copy across second section
		strncpy(newCStringPtr + this->length, cStringToAppend, appendStringLength);

		// Make sure new string is null terminated
		newCStringPtr[this->length + appendStringLength] = '\0';

		// Free old memory
		delete[] this->cStr;

		// Save new pointer
		this->cStr = newCStringPtr;

		// Update length
		this->length += appendStringLength;

	}

	void String::Erase(uint32_t startPos, int32_t numOfChars)
	{
		//std::cerr << "String::Erase() called." << std::endl;
		//std::cerr << "this->cStr = '" << this->cStringPtr << "'." << std::endl;
		//std::cerr << "this->length = '" << this->length << "'." << std::endl;
		//std::cerr << "startPos = '" << startPos << "'." << std::endl;
		//std::cerr << "numOfChars = '" << numOfChars << "'." << std::endl;

		// Make sure start position is not > length,
		// if so, return
		if(startPos > this->length)
			return;

		// Calculate actual number of chars to remove
		// (assuming startPos + numOfChars could be > length)
		uint32_t actualNumOfCharsToErase;

		// See if we are erasing everything from startPos to the end of string,
		// or there will be a second section kept after the bit that is erased
		if((numOfChars < 0) || (startPos + numOfChars > this->length))
			// Want to erase everything from startPos to end of string
			actualNumOfCharsToErase = this->length - startPos;
		else
			actualNumOfCharsToErase = numOfChars;

		//std::cerr << "Actual num chars to erase = '" << actualNumOfCharsToErase << "'." << std::endl;

		// Calculate new string length
		uint32_t newStringLength = this->length - actualNumOfCharsToErase;

		//std::cerr << "New string length = '" << newStringLength << "'." << std::endl;

		// Allocate memory for new string, + 1 for null char
		char * newCStringPtr = new char[newStringLength + 1];

		//================= FIRST SECTION ===============//

		// Copy first section into new string, note startPos could be zero,
		// in this case this call won't do anything
		strncpy(newCStringPtr, this->cStr, startPos);

		//std::cerr << "New cPtr = '" << newCStringPtr << "'." << std::endl;

		// Copy second section (the bit after the erased section) into new string,
		// if second section exists
		//if((numOfChars >= 0) && (startPos + numOfChars < this->length))
		if(startPos + actualNumOfCharsToErase < this->length)
		{
			//std::cerr << "There is a second segment to copy (erase didn't go the the end)." << std::endl;
			//std::cerr << "To string start = '" << startPos <<
			//		"'. From str start ='" << startPos + actualNumOfCharsToErase <<
			//		". Num chars = '" << this->length - actualNumOfCharsToErase << "'." << std::endl;

			strncpy(
				newCStringPtr + startPos,
				this->cStr + startPos + actualNumOfCharsToErase,
				this->length - actualNumOfCharsToErase);
		}

		// Make sure new string is null terminated
		newCStringPtr[newStringLength] = '\0';

		//std::cerr << "Freeing old memory." << std::endl;

		// Free old memory
		delete[] this->cStr;

		//std::cerr << "Saving new pointer." << std::endl;

		// Save new pointer
		this->cStr = newCStringPtr;

		//std::cerr << "Final string = '" << this->cStringPtr << "'." << std::endl;
		//std::cerr << "Updating length." << std::endl;

		// Update length
		this->length = newStringLength;

	}

	void String::Trim(String charsToMatch, EndsToTrim endsToTrim)
	{
		uint32_t posInString;

		if((endsToTrim == EndsToTrim::LEFT) || (endsToTrim == EndsToTrim::BOTH))
		{
			//================== TRIM LEFT ===============//

			// Find out how many characters match pattern
			for(posInString = 0; posInString < this->length; posInString++)
			{
				//! @brief		Used to flag when a match has been found
				bool matchFound = false;
				for(uint32_t posInCharsToMatch = 0; posInCharsToMatch < charsToMatch.length; posInCharsToMatch++)
				{
					if((*this)[posInString] == charsToMatch[posInCharsToMatch])
					{
						// Char that doesn't match stuff to trim found, let's stop here!
						matchFound = true;
						// We don't need to keep looking, we have found a match!
						break;
					}
				}

				// If none of the chars in the charsToMatch string could be found at
				// this position, then break out of loop
				if(!matchFound)
					break;

			}

			// posInString should be the number of chars we want to erase from the start of the string

			// Erase number of chars found, starting at the beginning of the string
			this->Erase(0, posInString);
		} // if((endsToTrim == EndsToTrim::LEFT) || (endsToTrim == EndsToTrim::BOTH))

		if((endsToTrim == EndsToTrim::RIGHT) || (endsToTrim == EndsToTrim::BOTH))
		{

			//================= TRIM RIGHT ==============//

			// Find out how many characters match pattern, starting at the
			// end of the string and working backwards
			for(posInString = this->length - 1; posInString >= 0; posInString--)
			{
				//! @brief		Used to flag when a match has been found
				bool matchFound = false;
				for(uint32_t posInCharsToMatch = 0; posInCharsToMatch < charsToMatch.length; posInCharsToMatch++)
				{
					if((*this)[posInString] == charsToMatch[posInCharsToMatch])
					{
						// Char that doesn't match stuff to trim found, let's stop here!
						matchFound = true;
						// We don't need to keep looking, we have found a match!
						break;
					}
				}

				// If none of the chars in the charsToMatch string could be found at
				// this position, then break out of loop
				if(!matchFound)
				{
					// No match found, so non-trimable char found, lets
					// increment posInString by 1 so that it points to the last
					// trimable char
					posInString++;
					break;
				}

			}

			// Erase number of chars found, starting at posInString
			// and erasing till the end (no second argument provided to Erase()).
			this->Erase(posInString );

		} // if((endsToTrim == EndsToTrim::RIGHT) || (endsToTrim == EndsToTrim::BOTH))

	}

	void String::Trim(EndsToTrim endsToTrim)
	{
		this->Trim(defCharsToMatch , endsToTrim);
	}

	//============================================================================================//
	//============================== PRIVATE METHOD DEFINITIONS ==================================//
	//============================================================================================//

	// none

} // namespace StringNs

// EOF
