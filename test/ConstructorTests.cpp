//!
//! @file 			ConstructorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-08-21
//! @brief 			Contains unit tests that make sure the constructor is working correctly.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(ConstructorTests)
	{

		TEST(NoParamConstructorTest)
		{
			MbeddedNinja::String myString;

			// Check constructor worked correctly
			CHECK_EQUAL("", myString.cStr);
		}

		TEST(EmptyStringConstructorTest)
		{
			MbeddedNinja::String myString("");

			// Check constructor worked correctly
			CHECK_EQUAL("", myString.cStr);
		}

	} // SUITE(ConstructorTests)
} // namespace StringTestsNs
