//!
//! @file 			ShiftDobleTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-25
//! @last-modified 	2014-08-25
//! @brief 			Contains unit tests which makes sure that the shift ('<<') operator works correctly with doubles.
//! @details
//!					See README.rst in root dir for more info.

// User libraries
#include "../lib/UnitTest++/src/UnitTest++.h"

// User source
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{
	SUITE(ShiftDoubleTests)
	{

		TEST(ShiftLargeNumberOfDecimalPartsDoubleTest)
		{
			MbeddedNinja::MString myString("double = ");

			myString << (double)3.123456789;

			// Number should have 6 digits after the decimal point,
			// last one will be rounded up
			CHECK_EQUAL("double = 3.12346", myString.cStr);
		}

		TEST(ShiftRandomDoubleTest)
		{
			MbeddedNinja::MString myString("double = ");

			myString << (double)3.254;

			// Number should have 6 digits after the decimal point
			CHECK_EQUAL("double = 3.254", myString.cStr);
		}

		TEST(ShiftLargeNumberDoubleTest)
		{
			MbeddedNinja::MString myString("double = ");

			myString << (double)123456789123456789llu;

			// Number should have 6 digits after the decimal point,
			// last one will be rounded up
			CHECK_EQUAL("double = 1.23457e+17", myString.cStr);
		}


	} // SUITE(ShiftDoubleTests)
} // namespace StringTestsNs
