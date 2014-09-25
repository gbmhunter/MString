//!
//! @file 			ShiftDobleTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-25
//! @last-modified 	2014-09-13
//! @brief 			Contains unit tests which makes sure that the shift ('<<') operator works correctly with doubles.
//! @details
//!					See README.rst in root dir for more info.

//===== SYSTEM LIBRARIES =====//
#include <cstdint>	// uint32_t, e.t.c

//====== USER LIBRARIES =====//
#include "MUnitTest/api/MUnitTestApi.hpp"

//===== USER SOURCE =====//
#include "../api/MStringApi.hpp"

namespace StringTestsNs
{

	MTEST(ShiftLargeNumberOfDecimalPartsDoubleTest)
	{
		MbeddedNinja::MString myString("double = ");

		myString << (double)3.123456789;

		// Number should have 6 digits after the decimal point,
		// last one will be rounded up
		CHECK_EQUAL(myString, "double = 3.12346");
	}

	MTEST(ShiftRandomDoubleTest)
	{
		MbeddedNinja::MString myString("double = ");

		myString << (double)3.254;

		// Number should have 6 digits after the decimal point
		CHECK_EQUAL(myString, "double = 3.254");
	}

	MTEST(ShiftLargeNumberDoubleTest)
	{
		MbeddedNinja::MString myString("double = ");

		myString << (double)123456789123456789llu;

		// Number should have 6 digits after the decimal point,
		// last one will be rounded up
		CHECK_EQUAL(myString, "double = 1.23457e+17");
	}

} // namespace StringTestsNs
