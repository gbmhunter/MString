//!
//! @file 			AssignmentOperatorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-12
//! @last-modified 	2014-08-21
//! @brief 			Makes sure the assignment operator overloads for String work as expected.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/MStringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(AssignmentOperatorTests)
	{

		TEST(AssignmentOperatorTest)
		{
			MbeddedNinja::MString myString1("Testing");

			MbeddedNinja::MString myString2("Other stuff");

			myString2 = myString1;

			// myString2 should now be equal to myString1
			CHECK_EQUAL("Testing", myString2.cStr);
		}

	} // SUITE(AssignmentOperatorTests)
} // namespace StringTestsNs
