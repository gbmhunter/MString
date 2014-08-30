//!
//! @file 			CopyTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-12
//! @last-modified 	2014-08-21
//! @brief 			Makes sure the copy constructors for String work as expected.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{
	SUITE(CopyTests)
	{

		TEST(DeepCopyTest)
		{
			MbeddedNinja::MString myString1("Testing");

			MbeddedNinja::MString myString2(myString1);

			// Change memory in myString1 to make sure deep copy worked
			myString1.cStr[0] = 'a';

			// myString2 should not be affected by above change to myString1!
			CHECK_EQUAL("Testing", myString2.cStr);
		}

		TEST(CopyAssignmentTest)
		{
			MbeddedNinja::MString myString1("Testing");

			// Do a copy-assignment
			MbeddedNinja::MString myString2 = myString1;

			// Change memory in myString1 to make sure deep copy worked
			myString1.cStr[0] = 'a';

			// myString2 should not be affected by above change to myString1!
			CHECK_EQUAL("Testing", myString2.cStr);
		}

	} // SUITE(CopyTests)
} // namespace StringTestsNs
