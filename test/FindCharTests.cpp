//!
//! @file 			FindCharTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014-08-12
//! @last-modified 	2014-08-13
//! @brief 			Makes sure the String::Find() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/StringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(FindCharTests)
	{


		TEST(CharPresentFindTest)
		{
			StringNs::String myString("Testing");

			// Char should be found, and Find() return 0-based index to first occurance
			CHECK_EQUAL(2, myString.Find('s'));
		}

		TEST(CharNotPresentFindTest)
		{
			StringNs::String myString("Testing");

			// Char should not be found, and Find() should return -1
			CHECK_EQUAL(-1, myString.Find('z'));
		}

		TEST(CharPresentMultipleTimesFindTest)
		{
			StringNs::String myString("aaabbaaa");

			// Find should return first occurance of 'b'
			CHECK_EQUAL(3, myString.Find('b'));

			// Find should return second occurance of 'b'
			CHECK_EQUAL(4, myString.Find('b', 4));
		}

		TEST(LookForCharBeyondStringFindTest)
		{
			StringNs::String myString("aaabbaaa");

			// A startPos of 30 exceeds string lengh, we should not find anything
			CHECK_EQUAL(-1, myString.Find('b', 30));
		}

		TEST(LookForNullFindTest)
		{
			StringNs::String myString("Testing");

			// Null should not be found, and Find() should return -1
			CHECK_EQUAL(-1, myString.Find('\0'));
		}

	} // SUITE(FindTests)
} // namespace StringTestsNs
