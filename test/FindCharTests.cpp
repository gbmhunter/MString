//!
//! @file 			FindCharTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-12
//! @last-modified 	2014-09-13
//! @brief 			Makes sure the String::Find() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{

	MTEST(CharPresentFindTest)
	{
		MbeddedNinja::MString myString("Testing");

		// Char should be found, and Find() return 0-based index to first occurance
		CHECK_EQUAL(2, myString.Find('s'));
	}

	MTEST(CharNotPresentFindTest)
	{
		MbeddedNinja::MString myString("Testing");

		// Char should not be found, and Find() should return -1
		CHECK_EQUAL(-1, myString.Find('z'));
	}

	MTEST(CharPresentMultipleTimesFindTest)
	{
		MbeddedNinja::MString myString("aaabbaaa");

		// Find should return first occurance of 'b'
		CHECK_EQUAL(3, myString.Find('b'));

		// Find should return second occurance of 'b'
		CHECK_EQUAL(4, myString.Find('b', 4));
	}

	MTEST(LookForCharBeyondStringFindTest)
	{
		MbeddedNinja::MString myString("aaabbaaa");

		// A startPos of 30 exceeds string lengh, we should not find anything
		CHECK_EQUAL(-1, myString.Find('b', 30));
	}

	MTEST(LookForNullFindTest)
	{
		MbeddedNinja::MString myString("Testing");

		// Null should not be found, and Find() should return -1
		CHECK_EQUAL(-1, myString.Find('\0'));
	}

} // namespace StringTestsNs
