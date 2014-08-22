//!
//! @file 			CastingTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-22
//! @last-modified 	2014-08-22
//! @brief 			Makes sure the casting overloads for String work as expected.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(CastingTests)
	{

		TEST(CastTest)
		{
			StringNs::String myString1("Testing");

			// myString2 should not be affected by above change to myString1!
			CHECK_EQUAL("Testing", (const char *)myString1);
		}

		TEST(CastTest2)
		{
			StringNs::String myString1("Testing");

			const char * myCStr;

			myCStr = myString1;

			// myString2 should not be affected by above change to myString1!
			CHECK_EQUAL("Testing", myCStr);

		}



	} // SUITE(CastingTests)
} // namespace StringTestsNs
