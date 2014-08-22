//!
//! @file 			SubscriptOperatorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-22
//! @last-modified 	2014-08-22
//! @brief 			Makes sure the subscript operator overloads for String work as expected.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"


namespace StringTestsNs
{
	SUITE(SubscriptOperatorTests)
	{

		TEST(SubscriptOperatorReadTest)
		{
			mNinja::String myString1("Testing");

			CHECK_EQUAL('T', myString1[0]);
			CHECK_EQUAL('i', myString1[4]);

			// Make sure it's null-terminated
			// (we are allowed to access the terminating null)
			CHECK_EQUAL('\0', myString1[7]);
		}

		TEST(SubscriptOperatorWriteTest)
		{
			mNinja::String myString1("Testing");
			myString1[4] = 'z';

			// Check to make sure write was successful
			CHECK_EQUAL("Testzng", myString1.cStr);
		}

		TEST(OutOfBoundsTest)
		{
			mNinja::String myString1("Testing");

			// Lets try and write to something out-of-bounds
			myString1[287] = 'z';

			// Specified behaviour when out-of-bounds is to return the first char.
			CHECK_EQUAL("zesting", myString1.cStr);
		}

	} // SUITE(SubscriptOperatorTests)
} // namespace StringTestsNs

// EOF
