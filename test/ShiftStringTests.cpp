//!
//! @file 			ShiftStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-25
//! @last-modified 	2014-08-25
//! @brief 			Contains unit tests which makes sure that the shift ('<<') operator works correctly with strings.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/StringApi.hpp"

namespace StringTestsNs
{
	SUITE(ShiftStringTests)
	{

		TEST(BasicShiftStringTest)
		{
			MbeddedNinja::String myString("Hello");

			myString << ", world!";

			// Number should have 6 digits after the decimal point,
			// last one will be rounded up
			CHECK_EQUAL("Hello, world!", myString.cStr);
		}

		TEST(ComplexShiftStringTest)
		{
			MbeddedNinja::String myString("Hello");

			myString << ", world!" << " This is your" << " captain speaking.";

			// Number should have 6 digits after the decimal point,
			// last one will be rounded up
			CHECK_EQUAL("Hello, world! This is your captain speaking.", myString.cStr);
		}

		TEST(ShiftFromEmptyStringTest)
		{
			MbeddedNinja::String myString;

			myString << "Hello!";

			// Number should have 6 digits after the decimal point,
			// last one will be rounded up
			CHECK_EQUAL("Hello!", myString.cStr);
		}

	} // SUITE(ShiftStringTests)
} // namespace StringTestsNs
