//!
//! @file 			CopyTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014-08-12
//! @last-modified 	2014-08-12
//! @brief 			Makes sure the copy constructors for String work as expected.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/StringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(CopyTests)
	{

		TEST(DeepCopyTest)
		{
			StringNs::String myString1("Testing");

			StringNs::String myString2(myString1);

			// Change memory in myString1 to make sure deep copy worked
			myString1.cStringPtr[0] = 'a';

			// myString2 should not be affected by above change to myString1!
			CHECK_EQUAL("Testing", myString2.cStringPtr);
		}

		TEST(CopyAssignmentTest)
		{
			StringNs::String myString1("Testing");

			// Do a copy-assignment
			StringNs::String myString2 = myString1;

			// Change memory in myString1 to make sure deep copy worked
			myString1.cStringPtr[0] = 'a';

			// myString2 should not be affected by above change to myString1!
			CHECK_EQUAL("Testing", myString2.cStringPtr);
		}

	} // SUITE(CopyTests)
} // namespace StringTestsNs
