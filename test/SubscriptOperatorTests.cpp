//!
//! @file 			SubscriptOperatorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-22
//! @last-modified 	2014-09-13
//! @brief 			Makes sure the subscript operator overloads for String work as expected.
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

	MTEST(SubscriptOperatorReadTest)
	{
		MbeddedNinja::MString myString1("Testing");

		CHECK_EQUAL(myString1[0], 'T');
		CHECK_EQUAL(myString1[4], 'i');

		// Make sure it's null-terminated
		// (we are allowed to access the terminating null)
		CHECK_EQUAL(myString1[7], '\0');
	}

	MTEST(SubscriptOperatorWriteTest)
	{
		MbeddedNinja::MString myString1("Testing");
		myString1[4] = 'z';

		// Check to make sure write was successful
		CHECK_EQUAL(myString1, "Testzng");
	}

	MTEST(OutOfBoundsTest)
	{
		MbeddedNinja::MString myString1("Testing");

		// Lets try and write to something out-of-bounds
		myString1[287] = 'z';

		// Specified behaviour when out-of-bounds is to return the first char.
		CHECK_EQUAL(myString1, "zesting");
	}

} // namespace StringTestsNs

// EOF
