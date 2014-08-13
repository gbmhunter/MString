//!
//! @file				String.cpp
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
//========================================= INCLUDES ============================================//
//===============================================================================================//

// System libraries
#include <cstdint>		// int8_t, int32_t e.t.c
#include <cstring>		// strlen(), strncpy()

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
	//=============================== PUBLIC METHOD DEFINITIONS ==================================//
	//============================================================================================//

	String::String(const char * cString)
	{
		// Get length of cString
		this->length = strlen(cString);

		// Allocate memory to store this string, + 1 to store null char
		this->cStringPtr = new char[this->length + 1];

		// Now copy string across
		strncpy(this->cStringPtr, cString, this->length);

		// Make sure it is null terminated
		this->cStringPtr[this->length] = '\0';
	}

	String::String() :
			String("") // Delegate to base constructor, passing in empty C-style string
	{
		// No code needed here
	}

	String::String(const String &obj) :
		String(obj.cStringPtr)	// Delegate to base constructor, passing in the C-style string
	{
		// Copy constructor
		// Nothing here
	}

	String & String::operator= (const String & other)
	{
		// Assignment operator
		if (this != &other) // protect against invalid self-assignment
		{
			// Deallocate current memory
			delete[] this->cStringPtr;

			// Copy length
			this->length = other.length;

			// Do a deep copy of the cStringPtr
			if(other.cStringPtr)
			{
				// allocate memory for our copy
				this->cStringPtr = new char[this->length + 1];

				// Copy the parameter the newly allocated memory
				strncpy(this->cStringPtr, other.cStringPtr, this->length);
			}
			else
				this->cStringPtr = nullptr;
		}

		// Return *this for chaining
		return *this;
	}


	String::~String()
	{
		// Delete memory that was allocated in the constructor.
		delete[] this->cStringPtr;
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
		char * ptrToFirstOccurance = strstr(this->cStringPtr + startPos, cStringToFind);

		if(ptrToFirstOccurance == nullptr)
			// stringToFind not found inside string, return -1.
			return -1;
		else
			// Return offset of pointer to matched string from start of searched-in string,
			// this will be the index
			return ptrToFirstOccurance - this->cStringPtr;
	}

	int32_t String::Find(const String & stringToFind, uint32_t startPos)
	{
		// Call base method, passing in C-style string
		return this->Find(stringToFind.cStringPtr, startPos);
	}

	void String::Append(const char * cStringToAppend)
	{
		// Get length of stringToAppend
		uint32_t appendStringLength = strlen(cStringToAppend);

		// Allocate memory for new string
		char * newCStringPtr = new char[this->length + appendStringLength + 1];

		// Copy across first section
		strncpy(newCStringPtr, this->cStringPtr, this->length);

		// Copy across second section
		strncpy(newCStringPtr + this->length, cStringToAppend, appendStringLength);

		// Make sure new string is null terminated
		newCStringPtr[this->length + appendStringLength] = '\0';

		// Free old memory
		delete[] this->cStringPtr;

		// Save new pointer
		this->cStringPtr = newCStringPtr;

		// Update length
		this->length += appendStringLength;

	}

	void String::Erase(uint32_t startPos, int32_t numOfChars)
	{
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

		// Calculate new string length
		uint32_t newStringLength = this->length - actualNumOfCharsToErase;

		// Allocate memory for new string, + 1 for null char
		char * newCStringPtr = new char[newStringLength + 1];

		// Copy first section into new string, note startPos could be zero,
		// in this case this call won't do anything
		strncpy(newCStringPtr, this->cStringPtr, startPos);

		// Copy second section (the bit after the erased section) into new string,
		// if second section exists
		if((numOfChars >= 0) || (startPos + numOfChars < this->length))
		{
			strncpy(
				newCStringPtr + startPos,
				this->cStringPtr + startPos + actualNumOfCharsToErase,
				this->length - actualNumOfCharsToErase);
		}

		// Make sure new string is null terminated
		newCStringPtr[newStringLength] = '\0';

		// Free old memory
		delete[] this->cStringPtr;

		// Save new pointer
		this->cStringPtr = newCStringPtr;

		// Update length
		this->length = newStringLength;

	}

	String operator+(String & lhs, String & rhs)
	{
		// + operator overload between two strings,
		// joins the two strings together
		String result(lhs.cStringPtr);
		result.Append(rhs.cStringPtr);
		return result;
	}

	//============================================================================================//
	//============================== PRIVATE METHOD DEFINITIONS ==================================//
	//============================================================================================//

	// none

} // namespace StringNs

// EOF
