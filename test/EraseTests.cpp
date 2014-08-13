//!
//! @file 			EraseTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014-08-13
//! @last-modified 	2014-08-13
//! @brief 			Makes sure the String::Erase() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/StringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(EraseTests)
	{

		TEST(BasicEraseTest)
		{
			StringNs::String myString("Hello, world!");

			// Erase everything after "Hello"
			myString.Erase(5);

			CHECK_EQUAL("Hello", myString.cStringPtr);
		}

		TEST(LengthCorrectCheckTest)
		{
			StringNs::String myString("Hello, world!");

			myString.Erase(5);

			// Make sure only 5 characters are left
			CHECK_EQUAL(5, myString.GetLength());
		}

		TEST(EraseMiddleSectionTest)
		{
			StringNs::String myString("Hello, world!");

			// Erase the comma and space
			myString.Erase(5, 2);

			CHECK_EQUAL("Helloworld!", myString.cStringPtr);
			CHECK_EQUAL(11, myString.GetLength());
		}

		TEST(EraseBeyondLengthTest)
		{
			StringNs::String myString("Hello, world!");

			// Atempt to erase characters beyond the length of the string, this
			// should do nothing
			myString.Erase(30);

			CHECK_EQUAL("Hello, world!", myString.cStringPtr);
			CHECK_EQUAL(13, myString.GetLength());
		}

		TEST(SpecifyTooManyCharsToEraseTest)
		{
			StringNs::String myString("Hello, world!");

			// Try and erase 30 chars starting from pos 5, should just erase what we can
			myString.Erase(5, 30);

			CHECK_EQUAL("Hello", myString.cStringPtr);
		}

		TEST(EraseAllTest)
		{
			StringNs::String myString("Hello, world!");

			// Erase all characters
			myString.Erase(0);

			CHECK_EQUAL("", myString.cStringPtr);
		}

	} // SUITE(EraseTests)
} // namespace StringTestsNs
