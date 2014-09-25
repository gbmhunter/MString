//!
//! @file 			ConstructorTests.cpp
//! @author 		Geoffrey Hunter <gbmhunter@gmail.com> (www.mbedded.ninja)
//! @created		2014-08-13
//! @last-modified 	2014-09-13
//! @brief 			Contains unit tests that make sure the constructor is working correctly.
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

	MTEST(NoParamConstructorTest)
	{
		MbeddedNinja::MString myString;

		// Check constructor worked correctly
		CHECK_EQUAL(myString, "");
	}

	MTEST(EmptyStringConstructorTest)
	{
		MbeddedNinja::MString myString("");

		// Check constructor worked correctly
		CHECK_EQUAL(myString, "");
	}

} // namespace StringTestsNs
