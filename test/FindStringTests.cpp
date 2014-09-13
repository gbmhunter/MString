//!
//! @file 			FindStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
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

	MTEST(CStringPresentFindTest)
	{
		MbeddedNinja::MString myString("Looking for the needle in the haystack.");

		// "needle" should be found, and Find() return 0-based index to first occurance
		CHECK_EQUAL(16, myString.Find("needle"));
	}

	MTEST(StringPresentFindTest)
	{
		MbeddedNinja::MString myString("Looking for the needle in the haystack.");

		MbeddedNinja::MString stringToFind("needle");

		// "needle" should be found, and Find() return 0-based index to first occurance
		CHECK_EQUAL(16, myString.Find(stringToFind));
	}

	MTEST(StringNotPresentFindTest)
	{
		MbeddedNinja::MString myString("Looking for the needle in the haystack.");

		MbeddedNinja::MString stringToFind("noneedle");

		// Char should not be found, and Find() should return -1
		CHECK_EQUAL(-1, myString.Find(stringToFind));
	}

	MTEST(StringPresentMultipleTimesFindTest)
	{
		MbeddedNinja::MString myString("Looking for the needle in the haystack full of needles.");

		MbeddedNinja::MString stringToFind("needle");

		// Find should return first occurrance of "needle"
		CHECK_EQUAL(16, myString.Find(stringToFind));

		// Now look for second occurrance of the word needle
		CHECK_EQUAL(47, myString.Find(stringToFind, 17));
	}

} // namespace StringTestsNs
