//!
//! @file 			BasicTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.cladlab.com)
//! @created		2014-08-12
//! @last-modified 	2014-08-12
//! @brief 			Contains basic tests.
//! @details
//!					See README.rst in root dir for more info.

#include <stdio.h>

#include "../api/StringApi.hpp"

#include "../lib/UnitTest++/src/UnitTest++.h"

namespace StringTestsNs
{
	SUITE(BasicTests)
	{


		TEST(BasicCapacityTest)
		{
			StringNs::String myString("Testing");

			// Check capacity is calculated correctly
			CHECK_EQUAL("Testing", myString.cStringPtr);
		}


	} // SUITE(BasicTests)
} // namespace StringTestsNs
