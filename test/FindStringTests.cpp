//!
//! @file 			FindStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-09-24
//! @brief 			Makes sure the String::Find() method works as expected for strings.
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
		CHECK_EQUAL(myString.Find("needle"), 16);
	}

	MTEST(StringPresentFindTest)
	{
		MbeddedNinja::MString myString("Looking for the needle in the haystack.");

		MbeddedNinja::MString stringToFind("needle");

		// "needle" should be found, and Find() return 0-based index to first occurance
		CHECK_EQUAL(myString.Find(stringToFind), 16);
	}

	MTEST(StringNotPresentFindTest)
	{
		MbeddedNinja::MString myString("Looking for the needle in the haystack.");

		MbeddedNinja::MString stringToFind("noneedle");

		// Char should not be found, and Find() should return -1
		CHECK_EQUAL(myString.Find(stringToFind), -1);
	}

	MTEST(StringPresentMultipleTimesFindTest)
	{
		MbeddedNinja::MString myString("Looking for the needle in the haystack full of needles.");

		MbeddedNinja::MString stringToFind("needle");

		// Find should return first occurrance of "needle"
		CHECK_EQUAL(myString.Find(stringToFind), 16);

		// Now look for second occurrance of the word needle
		CHECK_EQUAL(myString.Find(stringToFind, 17), 47);
	}

	MTEST(FindSomethingInNothingTest1)
	{
		MbeddedNinja::MString myString;

		// Look for something in an empty string
		CHECK_EQUAL(myString.Find("something"), -1);
	}

	MTEST(FindSomethingInNothingTest2)
	{
		MbeddedNinja::MString myString;

		// Look for something in an empty string
		CHECK_EQUAL(myString.Find("OK\r\n"), -1);
	}

	MTEST(FindSomethingInNothingTest3)
	{
		MbeddedNinja::MString myString("something");

		// Erase everything
		myString.Erase(0);

		// Look for something in an empty string
		CHECK_EQUAL(myString.Find("OK\r\n"), -1);
	}

	MTEST(FindNothingInSomethingTest)
	{
		MbeddedNinja::MString myString("something");

		// Look for something in an empty string
		CHECK_EQUAL(myString.Find(""), -1);
	}

} // namespace StringTestsNs
