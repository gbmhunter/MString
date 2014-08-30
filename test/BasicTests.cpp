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
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{
	SUITE(BasicTests)
	{


		TEST(BasicCapacityTest)
		{
			MbeddedNinja::MString myString("Testing");

			// Check capacity is calculated correctly
			CHECK_EQUAL("Testing", myString.cStr);
		}


	} // SUITE(BasicTests)
} // namespace StringTestsNs
