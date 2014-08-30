//!
//! @file 			FindCharTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-12
//! @last-modified 	2014-08-21
//! @brief 			Makes sure the String::Find() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{
	SUITE(FindCharTests)
	{


		TEST(CharPresentFindTest)
		{
			MbeddedNinja::MString myString("Testing");

			// Char should be found, and Find() return 0-based index to first occurance
			CHECK_EQUAL(2, myString.Find('s'));
		}

		TEST(CharNotPresentFindTest)
		{
			MbeddedNinja::MString myString("Testing");

			// Char should not be found, and Find() should return -1
			CHECK_EQUAL(-1, myString.Find('z'));
		}

		TEST(CharPresentMultipleTimesFindTest)
		{
			MbeddedNinja::MString myString("aaabbaaa");

			// Find should return first occurance of 'b'
			CHECK_EQUAL(3, myString.Find('b'));

			// Find should return second occurance of 'b'
			CHECK_EQUAL(4, myString.Find('b', 4));
		}

		TEST(LookForCharBeyondStringFindTest)
		{
			MbeddedNinja::MString myString("aaabbaaa");

			// A startPos of 30 exceeds string lengh, we should not find anything
			CHECK_EQUAL(-1, myString.Find('b', 30));
		}

		TEST(LookForNullFindTest)
		{
			MbeddedNinja::MString myString("Testing");

			// Null should not be found, and Find() should return -1
			CHECK_EQUAL(-1, myString.Find('\0'));
		}

	} // SUITE(FindTests)
} // namespace StringTestsNs
