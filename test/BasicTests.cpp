//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-12
//! @last-modified 	2014-08-21
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(BasicTests)
	{


		TEST(BasicCapacityTest)
		{
			StringNs::String myString("Testing");

			// Check capacity is calculated correctly
			CHECK_EQUAL("Testing", myString.cStr);
		}


	} // SUITE(BasicTests)
} // namespace StringTestsNs
