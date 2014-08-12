//!
//! @file 			FindStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014-08-13
//! @last-modified 	2014-08-13
//! @brief 			Makes sure the String::Find() method works as expected.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/StringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(FindStringTests)
	{

		TEST(CStringPresentFindTest)
		{
			StringNs::String myString("Looking for the needle in the haystack.");

			// "needle" should be found, and Find() return 0-based index to first occurance
			CHECK_EQUAL(16, myString.Find("needle"));
		}

		TEST(StringPresentFindTest)
		{
			StringNs::String myString("Looking for the needle in the haystack.");

			StringNs::String stringToFind("needle");

			// "needle" should be found, and Find() return 0-based index to first occurance
			CHECK_EQUAL(16, myString.Find(stringToFind));
		}

		TEST(StringNotPresentFindTest)
		{
			StringNs::String myString("Looking for the needle in the haystack.");

			StringNs::String stringToFind("noneedle");

			// Char should not be found, and Find() should return -1
			CHECK_EQUAL(-1, myString.Find(stringToFind));
		}

		TEST(StringPresentMultipleTimesFindTest)
		{
			StringNs::String myString("Looking for the needle in the haystack full of needles.");

			StringNs::String stringToFind("needle");

			// Find should return first occurrance of "needle"
			CHECK_EQUAL(16, myString.Find(stringToFind));

			// Now look for second occurrance of the word needle
			CHECK_EQUAL(47, myString.Find(stringToFind, 17));
		}

	} // SUITE(FindStringTests)
} // namespace StringTestsNs
