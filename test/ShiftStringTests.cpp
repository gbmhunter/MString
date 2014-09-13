//!
//! @file 			ShiftStringTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-25
//! @last-modified 	2014-09-13
//! @brief 			Contains unit tests which makes sure that the shift ('<<') operator works correctly with strings.
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

	MTEST(BasicShiftStringTest)
	{
		MbeddedNinja::MString myString("Hello");

		myString << ", world!";

		CHECK_EQUAL("Hello, world!", myString);
	}

	MTEST(ComplexShiftStringTest)
	{
		MbeddedNinja::MString myString("Hello");

		myString << ", world!" << " This is your" << " captain speaking.";

		CHECK_EQUAL("Hello, world! This is your captain speaking.", myString);
	}

	MTEST(ShiftFromEmptyStringTest)
	{
		MbeddedNinja::MString myString;

		myString << "Hello!";

		CHECK_EQUAL("Hello!", myString);
	}

} // namespace StringTestsNs
